/*********************************************************
*Copyright (C), 2020, Shanghai Eastsoft Microelectronics Co., Ltd
*文件名:  exit.c
*作  者:  AE Team
*版  本:  v1.0，编译于iDesigner(v4.2.3.166) + 工具链HRCC(v1.2.0.106)
*日  期:  2020/07/07
*描  述:  按键中断演示
          PA1：管脚翻转输出
          PA3：外部中断管脚
          注意：PA3与外部复位(MRSETN)复用，需要在配置字界面选择MRSTEN为数字IO功能。
*备  注:  本软件仅供学习和演示使用，对用户直接引用代码所带来的风险或后果不承担任何法律责任。
**********************************************************/
#include <hic.h>

#define CLRWDT()   {__Asm CWDT;}        //宏定义清狗指令

sbit key_change_flag;
sbit PA3_volt;

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
    PAT3 = 1;           //PINT1设为输入
    PAPU3 = 1;          //打开上拉
}

/**********************************************
函数名：isr(void) interrupt
描  述：中断服务程序
输入值：无
输出值：无
返回值：无
**********************************************/
void isr(void) interrupt
{
    if(PIE1==1 && PIF1==1)
    {
        PA3_volt = PA3;     //读取当前按键状态
        key_change_flag = 1;
        PIF1 = 0;       //清除外部中断
    }
}

/**********************************************
函数名：void main(void)
描  述：主函数，PA3与外部复位(MRETN)复用，需要在配置字界面选择MRSTEN为数字IO功能。
输入值：无
输出值：无
返回值：无
**********************************************/
void main(void) 
{
    unsigned int i;     //延时变量
    RAMclear();
    GPIOInit();
    INTC0 &= 0xFC;      //PINT1下降沿中断
    PIE1 = 1;           //打开管脚中断
    PIF1 = 0;           //清除外部中断标志
    GIE = 1;            //打开总中断     
    while(1)
    {
        if(key_change_flag == 1)
        {
            for(i = 0;i<10000;i++);     //延时消抖
            if(PA3_volt == PA3)         //判断按键是否抬起
                PA1 = ~PA1;             //管脚取反
            key_change_flag = 0;
        }
        CLRWDT();
    }
}
