/*******************************************************
*Copyright(C),2020,Shanghai Eastsoft Microelectronics Co.,Ltd.
*文件名：timer.c
*作  者：AE Team
*版  本：v1.0，编译于iDesigner(v4.2.3.166) + 工具链HRCC(v1.2.0.106)
*日  期：2020/07/09
*描  述：T21定时器定时模式，计数器溢出翻转PA1，溢出周期0.5s。预分频器决定计数器时钟频率，后分频器决定溢出总长度。
        单纯的一次计数器溢出并不会置起溢出标志，只有当计数器溢出次数与后分频器+1相等时才置起溢出标志。
*备  注：本软件仅供学习和演示使用，对用户直接引用代码所带来的风险或后果不承担任何法律责任。
*******************************************************/
#include <hic.h>

#define CLRWDT()   {__Asm CWDT;}        //宏定义清狗指令

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

/*******************************************************
函数名：void isr(void) interrupt
描  述：中断服务程序
输入值：无
输出值：无
返回值：无
*******************************************************/
void isr(void) interrupt
{
    if (T21VIE==1 && T21VIF==1)        //定时器溢出中断
    {
        T21VIF = 0;        //清标志位
        PA1 = ~PA1;
    }
}

/*******************************************************
函数名：void main(void)
描  述：主函数
输入值：无
输出值：无
返回值：无
*******************************************************/
void main(void)
{
    RAMclear();
    GPIOInit();
    T21CL = 0x00;        //定时器模式
    T21CM = 0x0F;        //预分频1:16
    T21CH = 0x79;        //后分频次数121
    T21PH = 0x0F;        //周期值高4位
    T21PL = 0xFF;        //周期值低8位
    T21VIE = 1;          //打开T21溢出中断
    T21VIF = 0;          //清标志位
    GIE = 1;             //开全局中断
    T21EN = 1;           //使能T21
    while (1)
    {
        CLRWDT();
    }
}