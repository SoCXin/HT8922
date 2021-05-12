/*******************************************************
*Copyright(C),2020,Shanghai Eastsoft Microelectronics Co.,Ltd.
*文件名：vector.c
*作  者：AE Team
*版  本：v1.0，编译于iDesigner(v4.2.3.166) + 工具链HRCC(v1.2.0.106)
*日  期：2020/07/10
*描  述：使用向量中断模式前，需在配置字界面选择->向量中断模式，且需右键工程->属性->编译->Support interrupt vectors->True        
        设置完成后切记保存设置；依据INTV<1:0>和INTP寄存器配置，优先响应高优先级中断。高优先级中断可以嵌套响应低优先级中断，
        同属高(或低)优先级中断之间不能嵌套响应
*备  注：本软件仅供学习和演示使用，对用户直接引用代码所带来的风险或后果不承担任何法律责任。
*******************************************************/
#include <hic.h>

#define SLAVE_ADDR  0x2D            //宏定义IIC从机地址
#define I2C_RLENGTH 64
#define CLRWDT()   {__Asm CWDT;}        //宏定义清狗指令

unsigned char t8nisr;        //T8N中断计次标志
unsigned char i2c_sta,i2c_rxd[I2C_RLENGTH],i2c_temp;      //I2C启动/重启动状态
unsigned char uart_rxd;

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
函数名：void isrx(void) interrupt
描  述：向量中断服务程序，isrx对应IGx
输入值：无
输出值：无
返回值：无
*******************************************************/
void isr0(void) interrupt_low 0x24        //IG0(T8N)1s定时中断
{
    T8N = 6;          //赋计数器初值
    t8nisr++;
    if (t8nisr >= 250)      //1s计时
    {
        t8nisr = 0;
        PA4 = ~PA4;
    }   
    T8NIF = 0;        //清标志位 
}

void isr3(void) interrupt_high 0x18        //IG3(UART)中断
{
    if (RX0IE==1 && RX0IF==1)     //UART接收中断，接收数据返回
    {
        uart_rxd = RX0B;
        TX0B = uart_rxd;
    }
    if (TX0IE==1 && TX0IF==1)     //UART发送中断，自行处理
    {
        TX0B = 0x5A;     //示例
        TX0IE = 0;       //示例
    }
}

void isr6(void) interrupt_high 0x0C        //IG6(I2C)中断
{
    if (I2CRBIE==1 && I2CRBIF==1)          //I2C接收中断
    {
        i2c_rxd[i2c_temp] = I2CRB;        //I2C接收数据返回
        I2CTB = i2c_rxd[i2c_temp];
        i2c_temp++;
        if (i2c_temp > I2C_RLENGTH)
            i2c_temp = 0;
    }
    if (I2CSRIE==1 && I2CSRIF==1)       //I2C接收“起始位+从机地址匹配+发送应答位”中断
    {
        i2c_sta = 1;        //I2C启动/重启动状态
        I2CSRIF = 0;
    }
    I2CIF = 0;      //清I2C总标志位
}

void isr7(void) interrupt_low 0x08         //IG7(T21)1s定时中断
{
    if (T21VIE==1 && T21VIF==1)         //定时器溢出中断
    {
        PA6 = ~PA6;
        T21VIF = 0;        //清溢出标志位
    }
}

/*******************************************************
函数名：void main(void)
描  述：主函数，默认中断向量表，IG6、IG3配置为高优先级中断，IG0、IG7配置为低优先级中断
        配置优先级顺序：IG6(高)>IG3(高)>IG0(低)>IG7(低)，高优先级可以嵌套响应低优先级
输入值：无
输出值：无
返回值：无
*******************************************************/
void main(void)
{
    RAMclear();
    GPIOInit();
    i2c_temp = 0;
    INTG = 0x07;        //向量中断模式，中断向量表INTV<1:0>=11
    IGP6 = 1;           //I2C中断高优先级
    IGP3 = 1;           //UART中断高优先级

/**********************T8N初始化************************/
    T8NC = 0x0E;         //定时器模式，预分频1:(Fosc/2)/128
    T8N = 6;             //赋计数器初值，计数器4ms溢出
    T8NIF = 0;           //清溢出标志位
    T8NIE = 1;           //打开定时器溢出中断

/**********************T21初始化************************/
    T21CL = 0x00;        //定时器模式
    T21CM = 0x0F;        //预分频1:16
    T21CH = 0x0F;        //后分频次数16
    T21PH = 0xF4;        //周期值高8位
    T21PL = 0x24;
    T21VIF = 0;          //清溢出标志位
    T21VIE = 1;          //打开T21溢出中断

/**********************IIC初始化************************/
    PBT0 = 1;           //I2C_SDA输入
    PBT1 = 1;           //I2C_SCL输入
    I2CC = 0xE0;        //I2C端口使能，使能上拉，开漏方式，发送ACK
    I2CSA = SLAVE_ADDR<<1;      //从机地址       
    I2CIFC = 0x00;      //清除标志位    
    I2CRBIE = 1;        //使能I2C接收中断
    I2CIF = 0;          //清I2C总标志位
    I2CIE = 1;          //使能I2C总中断

/**********************UART初始化***********************/
    PAT1 = 0;       //TX输出
    PAT2 = 1;       //RX输入
    RX0LEN = 0;     //8位数据接收格式
    TX0LEN = 0;     //8位数据发送格式
    BRGH0 = 0;      //波特率高速模式：波特率=Fosc/(64*(BRR<7:0>+1))
    BR0R = 25;      //波特率=16MHz/(64*26)≈9600bps
    TX0IE = 1;      //发送空中断
    RX0IE = 1;      //接收满中断
    
/*****************打开全局中断，使能模块*****************/   
    GIEL = 1;           //开低优先级中断
    GIE = 1;            //开全局中断
    T8NEN = 1;          //使能T8N
    T21EN = 1;          //使能T21
    I2CEN = 1;          //使能I2C
    RX0EN = 1;          //使能UART接收
    TX0EN = 1;          //使能UART发送
    while (1)
    {
        CLRWDT();
    }
}