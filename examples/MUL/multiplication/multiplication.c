/*********************************************************
*Copyright (C), 2020, Shanghai Eastsoft Microelectronics Co., Ltd
*文件名:  multiplication.c
*作  者:  AE Team
*版  本:  v1.0，编译于iDesigner(v4.2.3.166) + 工具链HRCC(v1.2.0.118)
*日  期:  2020/12/28
*描  述:  硬件乘法器例程
          宏定义MULA_DATA：乘数A
          宏定义MULB_DATA：乘数B
		  变量product：乘积
          注意：中断服务程序可能会改变乘数寄存器MULA和MULB，最终导致乘积错误，有二种方式来规避这种风险。
          方式一：使用硬件乘法器之前，禁止全局中断使能（GIE=0，操作前先判断当前GIE状态）；
		          乘法运算完成后，将乘积读出，再恢复全局中断使能（GIE=1）。
          方式二：先将乘数和被乘数备份在特定的变量中。这样，编译器会在中断服务程序中自动备份和恢复乘数寄存器。
		  本例程展示方式二，为方便使用，请使用v1.2.0.113及以上版本的工具链，其头文件包含必要的变量声明和宏定义。
*备  注:  本软件仅供学习和演示使用，对用户直接引用代码所带来的风险或后果不承担任何法律责任。
**********************************************************/
#include <hic.h>

#define CLRWDT()   {__Asm CWDT;}        //宏定义清狗指令

#define uchar unsigned char
#define uint unsigned int

#define MULA_DATA 0xFE  //乘数A
#define MULB_DATA 0xDC  //乘数B

uint product;     //乘积变量

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
}

/**********************************************
函数名：void main(void)
描  述：主函数，SET_MULA、SET_MULB设置乘数A、乘数B的值，头文件已包含宏定义和声明，product存储乘积值。
输入值：无
输出值：无
返回值：无
**********************************************/
void main(void) 
{
    RAMclear();
    GPIOInit();

	SET_MULA(MULA_DATA);
	SET_MULB(MULB_DATA);

    product = (MULH << 8) | MULL;

    while(1);
}
