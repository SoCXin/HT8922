/*********************************************************
*Copyright (C), 2020, Shanghai Eastsoft Microelectronics Co., Ltd
*文件名:  adc_offset.c
*作  者:  AE Team
*版  本:  v1.0，编译于iDesigner(v4.2.3.166) + 工具链HRCC(v1.2.0.106)
*日  期:  2020/12/25
*描  述:  ADC通信演示
          PA7：模拟输入端口
          PB5：TX
          PB6：RX
          程序将转换完的AD值通过串口发送到上位机，波特率9600bps。宏定义VDDVREF选择VDD作为参考电压正端，
          否则选择内部2.048V作为参考电压正端。
		  转换值减去offset进行ADC软件补偿，offset为802FH（内部2.048V作参考）和8030H（VDD作参考）低8位数据，
		  IAP读16位数据后需先判断是否满足高低8位取反。
		  注意：由于offset的存在，为防止溢出，转换值小于offset时，ADC结果直接归0；并且ADC最大只能测到(0xFFF-offset)。
*备  注:  本软件仅供学习和演示使用，对用户直接引用代码所带来的风险或后果不承担任何法律责任。
**********************************************************/
#include <hic.h>

#define VDDVREF        //宏定义选择VDD作为参考电压，注释本句则选择内部2.048V作为参考电压正端
#define CLRWDT()   {__Asm CWDT;}        //宏定义清狗指令

typedef unsigned char uchar;
typedef unsigned int uint;

uint adc_value;
uint offset_value = 0;  //保存ADC校准值
uchar str[] = "通道 的转换值为:    \r\n\0";

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

/**********************************************
函数名：UART_send(uchar *str,uchar ch,uint value)
描  述：UART发送函数
输入值：字符串指针，通道数，ADC转换值
输出值：无
返回值：无
**********************************************/
void UART_send(uchar *str,uchar ch,uint value)
{
    *(str+4) = ch+'0';
    *(str+16) = value/1000+'0';
    *(str+17) = value%1000/100+'0';
    *(str+18) = value%100/10+'0';
    *(str+19) = value%10+'0';

    while(*str)
    {
        while(!TRMT1);
        TX1B = *str++;
    }
}

/**********************************************
函数名：ADC_convert(uchar ch)
描  述：ADC转换函数
输入值：转换通道ch
输出值：无
返回值：转换的12位结果
**********************************************/
uint ADC_convert(void)
{
    ADTRG = 1;      //启动AD转换
    while(ADTRG);
    ADIF = 0;

    return (uint)ADCRH<<8 | ADCRL;
}

/*******************************************************
函数名：uint GetOffset2048(void)
描  述：获取参考电压为内部2.048V时offset值
输入值：无
输出值：无
返回值：offset值
*******************************************************/
uint GetOffset2048(void)
{
	uint value_tmp = 0;
	unsigned char gie_bk = GIE;		//备份GIE

    CLRWDT();

	while(GIE) GIE = 0;
	DATARDEN = 1;

	FRAH = 0x802F >> 8;
	FRAL = 0x802F;
	DATARDTRG = 1;
	while(DATARDTRG) ;	     //等待读完成
	__Asm TBR;		         //查表读指令
	value_tmp = (ROMDH<<8) | ROMDL;

    ROMCL = 0x00;            //退出IAP
	GIE = gie_bk;            //恢复全局中断

	return value_tmp;
}

/*******************************************************
函数名：uint GetOffsetVDD(void)
描  述：获取参考电压为VDD时offset值
输入值：无
输出值：无
返回值：offset值
*******************************************************/
uint GetOffsetVDD(void)
{
	uint value_tmp = 0;
	unsigned char gie_bk = GIE;		//备份GIE

    CLRWDT();

	while(GIE) GIE = 0;
	DATARDEN = 1;

	FRAH = 0x8030 >> 8;
	FRAL = 0x8030;
	DATARDTRG = 1;
	while(DATARDTRG) ;	     //等待读完成
	__Asm TBR;		         //查表读指令
	value_tmp = (ROMDH<<8) | ROMDL;

    ROMCL = 0x00;            //退出IAP
	GIE = gie_bk;            //恢复全局中断

    return value_tmp;
}

/**********************************************
函数名：main()
描  述：主函数,选择AIN7通道，测量值经UART传送到上位机
输入值：无
输出值：无
返回值：无
**********************************************/
void main(void) 
{
    uint i = 800;         //延时变量
    uint j = 3000;        //延时变量
	uchar cnt = 3;

//    RAMclear();
    CLRWDT();
	GPIOInit();

/****************初始化UART*******************/
    PBT5 = 0;       //TX输出
    PBT6 = 1;       //RX输入
    TX1LEN = 0;     //8位数据发送格式
    BRGH1 = 0;      //波特率低速模式：波特率=Fosc/(64*(BRR<7:0>+1))
    BR1R = 25;      //波特率=16MHz/(64*26)≈9600bps
     
/****************初始化ADC********************/
#ifdef VDDVREF
	while(cnt != 0)
	{
        offset_value = GetOffsetVDD();  //获取offset值
		if((offset_value>>8) == ((~offset_value) & 0x00FF)) //是否满足高低八位取反，是则取低8位作为offset
		{
			offset_value =  offset_value & 0x00FF;

			break;
		}
		else
		{
		    cnt--;

			if(cnt == 0)
			    offset_value = 0;  //读IAP超过3次后仍不满足高低8位取反则offset固定为0
		}
	}
    ANSL7 = 0;          //选择AIN7为模拟口
    ADCCL |= 0xF0;      //ADCCL<7:4>选择通道
    ADCCL &= 0x7F;      //选择通道7
	ADCCM = 0x4B;       //参考源VDD,负参考固定选择VSS，转换位数固定选择12位，AD调整offset固定选择档位1
    ADCCH = 0xC8;       //低位对齐;时钟周期FOSC/16
#else
	while(cnt != 0)
	{
        offset_value = GetOffset2048();  //获取offset值
		if((offset_value>>8) == ((~offset_value) & 0x00FF)) //是否满足高低八位取反，是则取低8位作为offset
		{
			offset_value =  offset_value & 0x00FF;

			break;
		}
		else
		{
		    cnt--;

			if(cnt == 0)
			    offset_value = 0;    //读IAP超过3次后仍不满足高低8位取反则offset固定为0
		}
	}
    ANSL7 = 0;          //选择AIN7为模拟口
    ADCCL |= 0xF0;      //ADCCL<7:4>选择通道
    ADCCL &= 0x7F;      //选择通道7
	ADCCM = 0x6B;       //参考源内部固定选择2.048V,负参考固定选择VSS，转换位数固定选择12位，AD调整offset固定选择档位1
    ADCCH = 0xC8;       //低位对齐;时钟周期FOSC/16
    VREFEN = 1;         //参考电压模块使能
	while(j--);         //等待300us
	VREF_CHOPEN = 1;    //内部参考必须使能电压斩波器
#endif

	ADC_LP_EN = 1;      //ADC低功耗必须固定使能
    PAT7 = 1;
    SMPS = 1;           //硬件控制采样，ADTRG=1时启动AD采样转换
    ADEN = 1;           //使能ADC模块
    while(i--);         //使能AD，建议在第一次转换之前延时80us以上

    ADC_convert();      //首次转换值不准确，丢弃

    while(1)
    {
		adc_value = ADC_convert();

		if(adc_value > offset_value)   //AD转换值大于offset值则减去offset，否则ADC结果归0
		    adc_value -= offset_value;
		else
		    adc_value = 0;

		TX1EN = 1;      //打开发送
        UART_send(str,7,adc_value);
        for(i = 0;i<50000;i++);        //延时
        for(i = 0;i<50000;i++);
        for(i = 0;i<50000;i++);
        for(i = 0;i<50000;i++);
        for(i = 0;i<50000;i++);
        for(i = 0;i<50000;i++);
        TX1EN = 0;      //关闭发送

        CLRWDT();
    }
}