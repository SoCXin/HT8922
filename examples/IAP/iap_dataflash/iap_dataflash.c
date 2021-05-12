/*******************************************************
*Copyright(C),2020,Shanghai Eastsoft Microelectronics Co.,Ltd.
*文件名：iap_dataflash.c
*作  者：AE Team
*版  本：v1.1，编译于iDesigner(v4.2.3.166) + 工具链HRCC(v1.2.0.106)
*日  期：2020/12/18
*描  述：数据区IAP操作，数据区地址：0xC000~0xC1FF
        IAP擦除以页(256个地址单元)为单位，对一个地址执行擦除动作即是擦除这个地址所在的一整页。
        IAP写入以一个地址单元为单位(一个地址单元对应一个Word)。每页擦除时间至少2ms，单个地址编程时间至少25us。
		增加IAP擦除编程软件锁，防止程序跑飞误擦程序。
        注意：建议IAP操作前关闭WDT(配置字选择WDTEN为Disable)，若使能WDT，请设置合理的WDT溢出时间，并合理清狗。
*备  注：本软件仅供学习和演示使用，对用户直接引用代码所带来的风险或后果不承担任何法律责任。
*******************************************************/
#include <hic.h>

#define CLRWDT()   {__Asm CWDT;}        //宏定义清狗指令

#define STARTADDR    0xC000     //宏定义数据区IAP操作起始地址
#define ENDADDR      0xC07F     //宏定义数据区IAP操作结束地址
#define WRDATA       0x87654321     //宏定义待写入数据

unsigned char dataerr = 0;      //0：写入与读出相等，1：写入与读出不等

unsigned char CallFlashEn,FlashEwEn;//软件锁变量

/******************************************************
函数名：void RAMclear(void)
描  述：RAM区数据清零，RAM区地址0x0000~0x03FF
输入值：无
输出值：无
返回值：无
*******************************************************/
void RAMclear(void)
{
    for (IAAH=0; IAAH<=0x03; IAAH++)
    {
        for (IAAL=0; IAAL<0xFF; IAAL++)
            IAD = 0x00;
        IAD = 0x00;
    }
}

/******************************************************
函数名：void GPIOInit(void)
描  述：首先初始化所有未用到的IO口为输出低电平
输入值：无
输出值：无
返回值：无
*******************************************************/
void GPIOInit(void)
{
	ANSH = 0xFF;        //选择对应端口为数字IO功能
    ANSL = 0xFF;        //选择对应端口为数字IO功能
    PAT = 0x00;         //所有IO设为输出低电平
    PBT = 0x00;
    PCT = 0x00;
    PA = 0x00;
    PB = 0x00;
    PC = 0x00;
}

/******************************************************
函数名：void StartIAP(void)
描  述：开始IAP操作。注意：IAP固定操作格式，使用时不可改变
输入值：无
输出值：无
返回值：无
*******************************************************/
void StartIAP(void)
{
    __asm{
          MOVI 0x55
          MOVA ROMCH
          MOVI 0xFF     //8个NOP代替语句开始
          SECSEL &FlashEwEn& % 0x80//选择变量所在的section
          XOR &FlashEwEn& % 0x80,0//0xFF xor 0xAA = 0x55
          SECSEL &CallFlashEn& % 0x80//选择变量所在的section
          XOR &CallFlashEn& % 0x80,0//若CallFlashEn在调用函数前为0x55，0x55 xor 0x55 = 0x00
          JBS PSW,Z//如果运算结果为0x00，则执行正确，跳至下一个NOP
          GOTO $+3
          NOP//8个NOP代替语句结束
          MOVI 0xAA
          MOVA ROMCH
          MOVI 0xFF     //8个NOP代替语句开始
          SECSEL &FlashEwEn& % 0x80//选择变量所在的section
          XOR &FlashEwEn& % 0x80,0//0xFF xor 0xAA = 0x55
          SECSEL &CallFlashEn& % 0x80//选择变量所在的section
          XOR &CallFlashEn& % 0x80,0//若CallFlashEn在调用函数前为0x55，0x55 xor 0x55 = 0x00
          JBS PSW,Z//如果运算结果为0x00，则执行正确，跳至下一个NOP
          GOTO $+3
          NOP//8个NOP代替语句结束
          BSS ROMCL,WR     //触发编程操作
          JBC ROMCL,WR
          goto $-1         //等待操作结束
        }
}

/*******************************************************
函数名：void DataFlashErsPage(void)
描  述：擦除DataFlash整页(256 word)，地址范围：0xC000~0xC1FF
输入值：无
输出值：无
返回值：无
*******************************************************/
void DataFlashErsPage(void)
{
	unsigned char gie_bk = GIE;		//备份GIE
    CLRWDT();
	while(GIE == 1)GIE = 0;            //启动IAP前关闭全局中断   
    FPEE = 1;           //存储器擦除模式
    FRAH = 0xC0;
    FRAL = 0x00;
    FRAHN = ~FRAH;      //IAP擦除/编程必须满足地址取反逻辑
    FRALN = ~FRAL;     
	FlashEwEn = 0xAA;//设置软件锁变量
    WREN = 1;           //使能擦除/编程功能
    StartIAP();         //开始IAP操作
	CallFlashEn = 0;//清零软件锁变量
	FlashEwEn = 0;
    ROMCL = 0x00;       //退出IAP
	GIE = gie_bk;       //恢复全局中断
}

/*******************************************************
函数名：unsigned long DataFlashRdData(unsigned int addr)
描  述：读Flash指定地址的数据
输入值：DataFlash地址addr，地址范围：0xC000~0xC1FF
输出值：无
返回值：DataFlash指定地址的数据
*******************************************************/
unsigned long DataFlashRdData(unsigned int addr)
{
	unsigned long data;
	unsigned char gie_bk = GIE;	  //备份GIE
    CLRWDT();
	while(GIE == 1)GIE = 0;
	DATARDEN=1;
    FRAH = addr>>8;
    FRAL = addr;
	DATARDTRG=1;
	while(DATARDTRG);
    __Asm TBR;          //查表读指令
    data = ((unsigned long)ROMD1H<<24) | ((unsigned long)ROMD1L<<16) | ((unsigned long)ROMDH<<8) | ROMDL;
    GIE = gie_bk;       //恢复全局中断
	return data;
}

/*******************************************************
函数名：void DataFlashWrData(unsigned int addr, unsigned long word)
描  述：写DataFlash指定地址的数据，地址范围：0xC000~0xC1FF
输入值：DataFlash地址addr，待写的数据word
输出值：无
返回值：0:写入失败，1:写入成功
*******************************************************/
unsigned char DataFlashWrData(unsigned int addr, unsigned long word)
{
    unsigned char rmdh,rmdl,rmd1h,rmd1l;      //临时存放ROMDH、ROMDL值
	unsigned char gie_bk = GIE;	  //备份GIE
    CLRWDT();
	while(GIE == 1)GIE = 0;            //启动IAP前关闭全局中断
    FPEE = 0;           //存储器编程模式
    ROMD1H = word>>24;    //写Word
    ROMD1L = word>>16;
    ROMDH = word>>8;
    ROMDL = word;
    FRAH = addr>>8;     //IAP编程地址
    FRAL = addr;
    FRAHN = ~FRAH;      //IAP擦除/编程必须满足地址取反逻辑
    FRALN = ~FRAL;       
	FlashEwEn = 0xAA;//设置软件锁变量
    WREN = 1;           //使能编程
    StartIAP();         //开始IAP操作
	CallFlashEn = 0;//清零软件锁变量
	FlashEwEn = 0;
    rmdh = ROMDH++;
    rmdl = ROMDL++;
    rmd1h = ROMD1H++;
    rmd1l = ROMD1L++;
	DATARDEN=1;      //DATA区读出使能
    FRAH = addr>>8;
    FRAL = addr;
	DATARDTRG=1;     //DATA区读出触发
	while(DATARDTRG);
    __Asm TBR;          //查表读指令
    if (ROMDH!=rmdh || ROMDL!=rmdl || ROMD1H!=rmd1h || ROMD1L!=rmd1l)
	{
        ROMCL = 0x00;       //退出IAP
		return 0;
	}
	FRAH = 0xFF;//指到不用的地址空间
	FRAL = 0xFF;//指到不用的地址空间
	ROMDH = 0xFF;//数据初始化为0xFF
	ROMDL = 0xFF;//数据初始化为0xFF
	ROMD1H = 0xFF;//数据初始化为0xFF
	ROMD1L = 0xFF;//数据初始化为0xFF
    ROMCL = 0x00;       //退出IAP
	GIE = gie_bk;       //恢复全局中断
    return 1;
}

/*******************************************************
函数名：void main(void)
描  述：主函数，数据区IAP操作，数据区地址：0xC000~0xC1FF
输入值：无
输出值：无
返回值：无
*******************************************************/
void main(void)
{
    unsigned char i;
    unsigned long j;
    unsigned int dtflashaddr;       //地址变量，用于DataFlash擦除、读写操作

    RAMclear();
    GPIOInit();

/************IAP擦除操作，擦除Flash数据区(256Word)****/
	CallFlashEn = 0x55;			//CallFlashEn赋值0x55才能正常执行擦除编程操作
    DataFlashErsPage();
    CLRWDT();

/******************IAP写入并读出校验******************/
    for (dtflashaddr=STARTADDR; dtflashaddr<=ENDADDR; dtflashaddr++)
    {
		CallFlashEn = 0x55;		//CallFlashEn赋值0x55才能正常执行擦除编程操作
        i = DataFlashWrData(dtflashaddr,WRDATA);
        if (i != 1)
            dataerr = 1;        //数据校验出错
    }
    ROMCL = 0x00;       //退出IAP
    CLRWDT();

/******************IAP读出校验(示例)******************/
    for (dtflashaddr=STARTADDR; dtflashaddr<=ENDADDR; dtflashaddr++)
    {
        j = DataFlashRdData(dtflashaddr);
        if (j != WRDATA)
            dataerr = 1;        //数据校验出错
    }
    ROMCL = 0x00;       //退出IAP
    CLRWDT();

    while (1)
    {
        CLRWDT();
    }
}