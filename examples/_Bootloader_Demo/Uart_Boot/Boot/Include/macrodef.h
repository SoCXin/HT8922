/*********************************************************
*Copyright (C), 2020, Shanghai Eastsoft Microelectronics Co., Ltd.
*文件名:	macrodef.h
*作  者:	AE Team
*版  本:	V1.01
*日  期:	2020/07/23
*描  述:	Bootloader demo 程序
*备  注:    本软件仅供学习和演示使用，对用户直接引用代码所带来的风险或后果不承担任何法律责任。
**********************************************************/
#ifndef   __MACRODEF__H
#define   __MACRODEF__H


// 相关函数或者计算
#define  ASM_GOTO(X)   __Asm  AJMP  X

/*****函数执行结果******/
#define  SUCCESS   0X01        //成功
#define  FAILED	   0X00        //失败

// 定义用户程序入口
#define  BOOT_APP_ADDR	(	0x0000	)
#define  USR_APP_ADDR	(	0x0900	)
#define  USR_APP_ENTER	(	0x0800	)

/*********** 定义硬件相关的函数/实现************/
// LED 指示灯
#define LED_INUSED
#define KEY_INUSED

#ifdef LED_INUSED
#define LED_PIN			(PA2)
#define LED_PIN_xS		(PAS2)
#define LED_PIN_xT     (PAT2)
#define LED_ON			(LED_PIN = 0)
#define LED_OFF			(LED_PIN = 1)
#define LED_BLINK		(LED_PIN ^= 1)
#else
#define LED_PIN
#define LED_PIN_xS
#define LED_PIN_xT
#define LED_ON
#define LED_OFF
#define LED_BLINK
#endif

#ifdef KEY_INUSED
#define KEY_PIN			(PC3)
#define KEY_PIN_xS      (PCS3)
#define KEY_PIN_xT		(PCT3 )
#define KEY_PIN_PxPU	(PCPU3 )

#else
#define KEY_PIN
#define KEY_PIN_xS
#define KEY_PIN_xT
#endif

// 定义bootloader使用的uart外设
#define UARTx_INUSED 1

#if UARTx_INUSED == 1
// 中断使能
#define RXxIE	RX1IE
#define TXxIE	TX1IE
// 中断标志
#define	RXxIF	RX1IF
#define	TXxIF	TX1IF
//
#define	TRMTx	TRMT1
// 错误标志
#define	FERRx	FERR1
#define	OERRx	OERR1
// 设备使能
#define	RXxEN	RX1EN
#define	TXxEN	TX1EN
// 发送寄存器/第9位
#define	TXxB	TX1B
#define	TXxR8	TX1R8
// 接受寄存器/第9位
#define	RXxB	RX1B
#define	RXxR8	RX1R8
#elif UARTx_INUSED == 3
// 中断使能
#define RXxIE	RX3IE
#define TXxIE	TX3IE
// 中断标志
#define	RXxIF	RX3IF
#define	TXxIF	TX3IF
//
#define	TRMTx	TRMT3
// 错误标志
#define	FERRx	FERR3
#define	OERRx	OERR3
// 设备使能
#define	RXxEN	RX3EN
#define	TXxEN	TX3EN
// 发送寄存器/第9位
#define	TXxB	TX3B
#define	TXxR8	TX3R8
// 接受寄存器/第9位
#define	RXxB	RX3B
#define	RXxR8	RX3R8
#endif

#define  ACK  0x79
#define  NACK 0x1F
#define  GO        0xA1
#define  SYN       0X3F
#define  READ_M    0x91
#define  WRITE_M   0xB1
#define  EX_ERASE  0xC4
#define  CHECK_EMPTY 0xD1

#define  FRAME_INTERVAL  80 //一帧数据相邻byte间隔时间最大80ms
#define  Boot_OVERTIME_1  20  //复位后如果BootPIN为低，超过20ms没有同步成功则开始引导程序
#define  Boot_OVERTIME_2  300

#endif
