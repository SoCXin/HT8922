/*********************************************************
*Copyright (C), 2020, Shanghai Eastsoft Microelectronics Co., Ltd
*文件名:  spi_slave.c
*作  者:  AE Team
*版  本:  v1.0，编译于iDesigner(v4.2.3.166) + 工具链HRCC(v1.2.0.106)
*日  期:  2020/12/28
*描  述:  SPI从机模式演示
          PA6：NSS
          PB4：SCK
          PB5：MOSI
          PB6：MISO
          从机中断方式读写数据，向主机写数组txbuf中的数据，读主机的数据存在数组rxbuf中。
*备  注:  本软件仅供学习和演示使用，对用户直接引用代码所带来的风险或后果不承担任何法律责任。
**********************************************************/
#include <hic.h>

#define CLRWDT()   {__Asm CWDT;}        //宏定义清狗指令
#define RXBUF_SIZE 8       //宏定义接收缓冲区长度
#define TXBUF_SIZE 8       //宏定义发送缓冲区长度

typedef unsigned char uchar;
typedef unsigned int uint;

uchar rxbuf[RXBUF_SIZE];
uint rxcnt = 0;

uchar txbuf[TXBUF_SIZE] = {0x01, 0x12, 0x23, 0x34, 0x45, 0x56, 0x67, 0x78};
uint txcnt = 0;

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
    PAT6 = 1;       //主机NSS设为输入
    PBT4 = 1;       //主机SCK设为输入
    PBT5 = 1;       //主机MOSI设为输入
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
    while(SPIRST);
    SPICON0 = 0xF0;     //CKS = Fosc/16，清空发送器、接收器
    SPICON1 &= ~(3<<6);
    SPICON1 |= 0<<6;      //0:上升沿发送（先），下降沿接收（后）；
    MS = 1;     //0：主机模式，1：从机模式
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
    if (RBIE == 1 && RBIF == 1)     //SPI接收中断
    {
		RBIF = 0;                   //清接收中断标志

        rxbuf[rxcnt++] = SPIRBR;

        if (rxcnt > RXBUF_SIZE - 1)
            rxcnt = 0;

        CLRWDT();
    }

	if(TBIE == 1 && TBIF == 1)      //SPI发送中断
	{
		TBIF = 0;                   //清发送中断标志

	    SPITBW = txbuf[txcnt++];

        if (txcnt > TXBUF_SIZE - 1)
            txcnt = 0;

        CLRWDT();
	}

    SPI_GIEIF = 0;  //清中断标志
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
//    RAMclear();
    GPIOInit();
    Init_spi();
    RBIE = 1;       //打开接收中断
    TBIE = 1;       //打开发送中断
    SPI_GIEIE = 1;  //打开SPI中断
    SPI_GIEIF = 0;  //清中断标志
    GIE = 1;        //打开总中断
    REN = 1;        //打开接收
    SPIEN = 1;      //SPI使能
    while(1)
    {
        CLRWDT();
    }
}
