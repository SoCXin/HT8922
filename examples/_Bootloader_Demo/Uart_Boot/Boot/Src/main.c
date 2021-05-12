/*********************************************************
*Copyright (C), 2020, Shanghai Eastsoft Microelectronics Co., Ltd
*文件名:  main.c
*作  者:  AE Team
*版  本:  V1.00， 编译于iDesigner(v4.2.3.166) + 工具链HRCC(v1.2.0.106)
*日  期:  2020/07/23
*描  述:  Bootloader示例程序
		  PA0：模拟BootPIN
          PA1：TX
		  PA2：RX
		  串口配置 波特率：9600  数据位：8位  停止位：1位  校验：无校验
		  演示方法请参考应用笔记《AN112_UserManual_ES-UART-BOOT》
*备  注:  本软件仅供学习和演示使用，对用户直接引用代码所带来的风险或后果不承担任何法律责任。
**********************************************************/
#include "typedef.h"
#include "rw_flash.h"
#include "string.h"
#include "uart.h"
#include  "sysinit.h"
#include "systick.h"
#include <hic.h>

extern isp_data_t g_isp_data;
extern u32  g_boot_timer;
extern u8   g_boot;
void uart_proc_fsm(void);
void fsm_init(void);
void UartReceive(void);

/**********************************************
函数名：RAM_clear
描  述：RAM区清0
输入值：无
输出值：无
返回值：无
**********************************************/
void RAM_clear(void)
{
	for(IAAH=0; IAAH<=0x03; IAAH++)
	{
		for(IAAL=0;IAAL<0xFF;IAAL++)IAD=0;
		IAD=0;
	}
}
/**********************************************
函数名： main
描  述：主函数
输入值：无
输出值：无
返回值：无
**********************************************/
void main()
{
    Init_MCU();
	fsm_init();
    while(1)
    {
        Timer_Proc();     //4ms节拍处理
		UartReceive();
        while(g_isp_data.triger == 1)
		{
			uart_proc_fsm();  //isp命令状态机处理
		}
		if(g_boot == 1)  //需要引导程序到flash
		{
			Reg_reset();
			RAM_clear();
			PCRH=0x08;
			PCRL=0x00;
			//ASM_GOTO(USR_APP_ENTER);			//判断是跳到App程序还是进行Bootloader
		}
    }
}
