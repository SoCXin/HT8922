/*********************************************************
*Copyright (C), 2020, Shanghai Eastsoft Microelectronics Co., Ltd
*文件名:  uart.c
*作  者:  AE Team
*版  本:  v1.0，编译于iDesigner(v4.2.3.166) + 工具链HRCC(v1.2.0.106)
*日  期:  2020/07/07
*描  述:  UART通信演示
          PB5：TX
          PB6：RX
          与上位机通信，波特率9600，复位发送一次"www.essemi.com"，然后循环将接收的数据原样返回。
          可通过宏定义的方式选择采用查询法发送接收或选择中断方式发送接收。
*备  注:  本软件仅供学习和演示使用，对用户直接引用代码所带来的风险或后果不承担任何法律责任。
**********************************************************/
#include <hic.h>

#define IT_SR       //中断发送接收，注释此宏定义则使用查询方式发送接收
#define CLRWDT()   {__Asm CWDT;}        //宏定义清狗指令

unsigned char rxbuf;
unsigned char str[] = "www.essemi.com\0";

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
	ANSH = 0xFF;        //选择对应端口为数字IO功能
    PAT = 0x00;         //所有IO设为输出低电平
    PBT = 0x00;
    PCT = 0x00;
    PA = 0x00;
    PB = 0x00;
    PC = 0x00;
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
    unsigned char *ptr = str;
//    RAMclear();
    GPIOInit();
    PBT5 = 0;       //TX输出
    PBT6 = 1;       //RX输入
    RX1LEN = 0;     //8位数据接收格式
    TX1LEN = 0;     //8位数据发送格式
    BRGH1 = 0;      //波特率低速模式：波特率=Fosc/(64*(BRR<7:0>+1))
    BR1R = 0x19;    //波特率=16MHz/(64*(25+1))≈9600bps

#ifdef IT_SR 
    RX1IE = 1;       //接收中断
    GIE = 1;        //打开总中断
#endif
    RX1EN = 1;       //打开接收
    TX1EN = 1;       //打开发送
    while (*ptr)        //发送："www.essemi.com"
    {
        while (!TRMT1);
        TX1B = *(ptr++);
        CLRWDT();
    }
    while (1)
    {
#ifndef IT_SR           //查询方式发送接收
        if (RXIF==1)
        {
            rxbuf = RX1B;
            while(!TRMT1);
            TX1B = rxbuf;
        }
#endif
        CLRWDT();
    }
}

/**********************************************
函数名：void isr(void) interrupt
描  述：中断服务程序
输入值：无
输出值：无
返回值：无
**********************************************/
#ifdef IT_SR 
void isr(void) interrupt
{
    if(RX1IE==1 && RX1IF==1)
    {
        rxbuf = RX1B;
        while(!TRMT1);
        TX1B = rxbuf;
    }
}
#endif