/*********************************************************
*Copyright (C), 2020, Shanghai Eastsoft Microelectronics Co., Ltd.
*文件名:	sysinit.h
*作  者:	AE Team
*版  本:	V1.01
*日  期:	2020/07/23
*描  述:	Bootloader demo 程序
*备  注:    本软件仅供学习和演示使用，对用户直接引用代码所带来的风险或后果不承担任何法律责任。
**********************************************************/
#ifndef   __SYSINIT__H
#define   __SYSINIT__H

void	Init_RAM(void);
void	Init_Uart(void) ;
void	Init_Ports(void);
void	Init_Timer(void) ;
void	Init_MCU(void) ;
#endif
