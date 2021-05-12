/*********************************************************
*Copyright (C), 2020, Shanghai Eastsoft Microelectronics Co., Ltd
*文件名:  app_demo.c
*作  者:  AE Team
*版  本:  V1.00，编译于iDesigner(v4.2.3.174) + 工具链HRCC(v1.2.0.111)
*日  期:  2020/07/23
*描  述:  Bootloader示例程序
		  PA0：模拟BootPIN
          PA1：TX
		  PA2：RX
		  PB6：电平翻转管脚，LED闪烁
		  演示方法请参考应用笔记《AN112_UserManual_ES-UART-BOOT》
*备  注:  本软件仅供学习和演示使用，对用户直接引用代码所带来的风险或后果不承担任何法律责任。
**********************************************************/
#include <hic.h>

float test(void);
volatile float value;

/**********************************************
函数名： main
描  述：主函数
输入值：无
输出值：无
返回值：无
**********************************************/
void main()
{
	ANSL=0xFF;
	ANSH=0xFF;
	PBT6=0;

	T8NC=0x0E;	//预分频系数1:128
	T8N=0;		
	T8NIE=1;	//不使能中断
	T8NEN=1;
	GIE=1;
	value = test();
	while(1)
	{
		value += 1;
	}
}
/**********************************************
函数名：isr
描  述：中断处理函数
输入值：无
输出值：无
返回值：无
**********************************************/
void isr(void) interrupt
{
	if(T8NIE && T8NIF)
	{
		static unsigned int i;
		i++;
		if(i>100)
		{
			i=0;
			PB6=~PB6;
		}
		T8NIF=0;
	}
}
/**********************************************
函数名：test
描  述：增加代码量
输入值：无
输出值：无
返回值：无
**********************************************/
float test()
{
	volatile float a,b,c;
	a = 1031.34;
	b = 425;
	a *= 3;
	b /= 5;
	c = a / b;
	return c;
}

