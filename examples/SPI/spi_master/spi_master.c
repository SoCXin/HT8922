/*********************************************************
*Copyright (C), 2020, Shanghai Eastsoft Microelectronics Co., Ltd
*文件名:  spi_master.c
*作  者:  AE Team
*版  本:  v1.0，编译于iDesigner(v4.2.3.166) + 工具链HRCC(v1.2.0.106)
*日  期:  2020/07/08
*描  述:  SPI主机模式演示
          PA6：NSS
          PB4：SCK
          PB5：MOSI
          PB6：MISO
*备  注:  本软件仅供学习和演示使用，对用户直接引用代码所带来的风险或后果不承担任何法律责任。
**********************************************************/
#include <hic.h>

#define IT_RECEIVE      //将这句注释掉采用查询接收，否则采用中断接收
#define RXBUF_SIZE 8       //定义接收缓冲区长度
#define CLRWDT()   {__Asm CWDT;}        //宏定义清狗指令

typedef unsigned char uchar;
typedef unsigned int uint;

uchar txbuf[8] = {0,1,2,3,4,5,6,7};
uchar rxbuf[RXBUF_SIZE] = {0};
uint rxcnt;

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
    ANSL = 0xFF;        //选择对应端口为数字IO功能
	ANSH = 0xFF;
    PAT = 0x00;         //所有IO设为输出低电平
    PBT = 0x00;
    PCT = 0x00;
    PA = 0x00;
    PB = 0x00;
    PC = 0x00;
    PBT6 = 1;       //主机MISO设为输入
}

/**********************************************
函数名：void Init_spi(void)
描  述：SPI初始化程序
输入值：无
输出值：无
返回值：无
**********************************************/
void Init_spi(void)
{
    SPIRST = 1;     //复位SPI
    while(SPIRST)
        ;
    SPICON0 = 0xF0;       //CKS = Fosc/16，清空发送器、接收器
    SPICON1 |= 0<<6;      //0:上升沿发送（先），下降沿接收（后）；
    MS = 0;               //0：主机模式，1：从机模式
#ifdef IT_RECEIVE
    RBIE = 1;       //打开接收中断
#else
    RBIE = 0;       //关闭接收中断
#endif
    REN = 1;        //打开接收
    SPIEN = 1;      //SPI使能
}
/**********************************************
函数名：void SPIWriteData(uchar *wbuf,uint n)
描  述：SPI数据发送程序
输入值：发送数据起始地址和发送的数据个数
输出值：无
返回值：无
**********************************************/
void SPIWriteData(uchar *wbuf,uint n)
{
    uchar i;
    PA6 = 0;    //片选拉低
    for (i=0; i<255; i++)     //延时等待从机准备
        ;
    for (i=0 ;i<n; i++)
    {
        SPITBW = *(wbuf+i);
        while(!IDIF);
        CLRWDT();
    }
    PA6 = 1;
}

/**********************************************
函数名：void SPIReadData(uchar *rbuf,uint n)
描  述：SPI数据接收程序
输入值：接收起始地址和发送的数据个数
输出值：接收到的数据
返回值：无
**********************************************/
void SPIReadData(uchar *rbuf,uint n)
{
    uint i;
    PA6 = 0;        //片选拉低
    for (i = 0;i<1000;i++)    //延时等待从机准备
        ;

    rxcnt = 0;      //接收计数复位
    REN = 1;        //读数据时打开接收

    for (i=0; i<n; i++)
    {
		SPITBW = 0xFF;  //写数据
        while(!IDIF);      //等待发送完成

        if (RBIE == 0)
        {
            while (!RBIF);          //等待接收完成
            *(rbuf+i) = SPIRBR;     //读数据
        }
        CLRWDT();
    }
    PA6 = 1;
    REN = 0;  
}

/**********************************************
函数名：void isr(void) interrupt 
描  述：接收中断服务程序
输入值：无
输出值：无
返回值：无
**********************************************/
void isr(void) interrupt
{
    if (RBIE==1 && RBIF==1)     //SPI接收中断
    {
        rxbuf[rxcnt++] = SPIRBR;
        if (rxcnt > RXBUF_SIZE - 1)
            rxcnt = 0;
    }

    SPI_GIEIF = 0;//清中断标志
}

/**********************************************
函数名：void main(void) 
描  述：主函数
输入值：无
输出值：无
返回值：无
**********************************************/
void main(void) 
{
    uint i;
    GPIOInit();
    Init_spi();
    SPI_GIEIE = 1;  //打开SPI中断
    GIE = 1;    //打开总中断

    while(1)
    {
		SPIReadData(rxbuf,8);
		for(i = 0;i<10000;i++);

		SPIWriteData(txbuf,8);
		for(i = 0;i<10000;i++);

		CLRWDT();
    }
}
