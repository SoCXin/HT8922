/*********************************************************
*Copyright (C), 2020, Shanghai Eastsoft Microelectronics Co., Ltd.
*文件名:	typedef.h
*作  者:	AE Team
*版  本:	V1.01
*日  期:	2020/07/23
*描  述:	Bootloader demo 程序
*备  注:    本软件仅供学习和演示使用，对用户直接引用代码所带来的风险或后果不承担任何法律责任。
**********************************************************/
#ifndef   __TYPEDEF__H
#define   __TYPEDEF__H
#include  "macrodef.h"

/**********************************************************/
//  add new datatypes by linford
/**********************************************************/
typedef   unsigned  char   u8;
typedef   unsigned  int    u16;
typedef   unsigned  long   u32;

/**********************************************************/
union u_b32b08_t{
	u32 b32;
	u8 b08[4];
};

typedef enum {
	            WAIT_REV_INS = 0,   
	            IN_REV_INS,   
	            END_IN_INS,  
	            WAIT_REV_PARA1,   
	            END_REV_PARA1,    
	            WAIT_REV_PARA2,      
	            IN_EXE_INS,       
	            IN_SEND_OVER,      
	            OTHER    
} isp_step_t; 

typedef struct isp_data_t{
    isp_step_t  step;	//指令时序步骤
    u8 syn;      //是否完成同步
	u8 cmd;      //指令码
	u8 triger;    //上一步动作完成，触发下一步动作
	u8 rx_len;   //接收长度
	u8 tx_len;   //发送长度
	u8 rx_cnt;   //接收计数
	u8 tx_cnt;   //发送计数
    union u_b32b08_t para1;  //参数1
    union u_b32b08_t para2;  //参数2
    u8 rx_buf[132];	//接收缓存
    u8 tx_buf[132];  //发送缓存
} isp_data_t;
#endif
