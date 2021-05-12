/*****************************************************************
*Copyright (C), 2017, Shanghai Eastsoft Microelectronics Co., Ltd
*文件名:  iap_flash.h
*作  者:  AE Team 
*日  期:  2020/07/23
*描  述:  测试例程头文件，适用于ES7P0693
*备  注:  本软件仅供测试使用，对用户直接引用代码所带来的风险或后果不承担任何法律责任。
******************************************************************/

#ifndef _ES7P0693_IAP_
#define _ES7P0693_IAP_

#include "ES7P0693.h"
#include <hic.h>

/* 数据类型定义 */
typedef unsigned char  uchar;		//无符号8位整型变量
typedef unsigned int   uint;		//无符号16位整型变量 
typedef unsigned long  ulong;       //无符号32位整型变量

typedef unsigned char  u8;          //无符号8位整型变量
typedef unsigned int   u16;         //无符号16位整型变量 
typedef unsigned long  u32;       	//无符号32位整型变量

typedef unsigned char  INT8U;       //无符号8位整型变量
typedef signed   char  INT8S;       //有符号8位整型变量
typedef unsigned int   INT16U;      //无符号16位整型变量 
typedef signed   int   INT16S;      //有符号16位整型变量
typedef unsigned long  INT32U;      //无符号32位整型变量
typedef signed   long  INT32S;		//有符号32位整型变量

typedef float          FP32;		//单精度浮点型变量[floating-point type:浮点型]
typedef double         FP64;		//双精度浮点型变量

/* 联合体定义 */
typedef union 
{
	unsigned char byte;
	struct P8Bit
	{
	   unsigned char bit0:1;	// 1 
	   unsigned char bit1:1;	// 2 
	   unsigned char bit2:1;	// 3 
	   unsigned char bit3:1;	// 4 
	   unsigned char bit4:1;	// 5 
	   unsigned char bit5:1;	// 6 
	   unsigned char bit6:1;	// 7 
	   unsigned char bit7:1;	// 8 
	}bitn;
}BitAccess; 	

/* 汇编指令宏定义 */
#define nop()		{__Asm NOP;}	//空
#define clr_wdt()	{__Asm CWDT;}	//清狗
#define IDLE()		{__Asm IDLE;}	//低功耗模式
//#define TBR()		{__Asm TBR;}	//查表读
#define TBR          __Asm TBR	  //汇编查表读指令

/* 标志位宏定义 */
#define FALSE		0
#define TRUE		1
#define WRONG		0
#define SUCCESS		1


//FRAH-PAGE选择
#define CODEADDRH	0x3F        //CODE区操作页高地址
//#define CODEADDRH	0x08

#define CODEADDRL	0x00

//FRAH-区域选择
#define CODE	0x00

#define WRDATA0H   0x55        //ROMD0待写入高字节数据(85)
#define WRDATA0L   0xAA        //ROMD0待写入低字节数据(170)
#define WRDATA1H   0x55        //ROMD1待写入高字节数据(85)
#define WRDATA1L   0xAA        //ROMD1待写入低字节数据(170)

#define ERASEDATA 0xFF		  //擦除完成后数据(256)

#endif