/*********************************************************
*Copyright (C), 2020, Shanghai Eastsoft Microelectronics Co., Ltd
*文件名:  iic_slave.c
*作  者:  AE Team
*版  本:  v1.0，编译于iDesigner(v4.2.3.166) + 工具链HRCC(v1.2.0.106)
*日  期:  2020/07/09
*描  述:  I2C从机模式演示
          PB1：SCL
          PB0：SDA
          I2C从机通信，数据收发，发送数据存在数组send_data，接收数据存在数组rece_data。
*备  注:  本软件仅供学习和演示使用，对用户直接引用代码所带来的风险或后果不承担任何法律责任。
**********************************************************/
#include <hic.h>

#define CLRWDT()   {__Asm CWDT;}        //宏定义清狗指令
#define SLAVE_ADDR 0x2D

typedef unsigned char uchar;
typedef unsigned int uint;

uchar send_data[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
uchar rece_data[8] = {0};
uchar send_i = 0;
uchar rece_i = 0;
uchar counter = 0;

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
    PBT0 = 1;       //SDA端口设为输入
    PBT1 = 1;       //SCL端口设为输入
}

/**********************************************
函数名：void isr(void) interrupt 
描  述：中断函数
输入值：无
输出值：无
返回值：无
**********************************************/
void isr(void) interrupt
{
    if(I2CIE==1 && I2CIF==1)
    {
        if(I2CRBIE==1 && I2CRBIF==1)      //接收中断
        {
			I2CRBIF = 0;
            rece_data[rece_i] = I2CRB;    //读取数据
			rece_i++;
			if(rece_i >= 8)
			    rece_i = 0;
        }
		
		if(I2CTBIE==1 && I2CTBIF==1)
		{
			I2CTBIF = 0;
			I2CTB = send_data[send_i];     //将数据放到发送缓冲区
			send_i++;
			if(send_i >= 8)
			    send_i = 0;
		}
        
        if(I2CSRIE==1 && I2CSRIF==1)    //收到起始位+地址匹配+发送应答位
        {
            I2CSRIF = 0;                //清除起始位+地址匹配+发送应答位中断
        }

        if(I2CSPIE==1 && I2CSPIF==1)    //停止位中断
        {
            I2CSPIF = 0;
            I2CRST = 1;         //复位I2C
            while(I2CRST);      //等待复位完成

			//reset param
			I2CSA = SLAVE_ADDR<<1;      //重置从机地址
            I2CC = 0xE1;	    //I2C上拉，开漏输入输出，ACK，I2C使能;
            I2CIEC = 0x4F;		//使能地址匹配中断，NACK中断，停止位中断，接收空/发送非空中断
			I2CIE = 1;          //使能I2C总中断
		    I2CIFC = 0x00;      //清除标志位

			send_i = 0;
			counter = 0;

        }
        if(I2CNAIE==1 && I2CNAIF==1)    //NACK中断
        {
            I2CNAIF = 0;
        }
    }
    I2CIF = 0;
}

/**********************************************
函数名：main() 
描  述：主函数
输入值：无
输出值：无
返回值：无
**********************************************/
void main() 
{
    uint i;
    GPIOInit();
    I2CRST = 1;         //复位I2C
    while(I2CRST);      //等待复位完成
    I2CC = 0xE0;        //I2C上拉，开漏输入输出，ACK;
    I2CSA = SLAVE_ADDR<<1;      //从机地址
    I2CEN = 1;          //使能I2C
    I2CIEC = 0x4F;      //使能地址匹配中断，NACK中断，停止位中断，接收空/发送非空中断
    I2CIE = 1;          //使能I2C总中断
    I2CIFC = 0x00;      //清除标志位
    GIE = 1;            //打开总中断

    while(1)
    {
        CLRWDT();
    }
}
