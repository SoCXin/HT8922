/*********************************************************
*Copyright (C), 2021, Shanghai Eastsoft Microelectronics Co., Ltd.
*文件名:    siic.c
*作  者:    AE Team
*版  本:    v1.0，编译于iDesigner(v4.2.3.177) + 工具链HRCC(v1.2.0.119)
*日  期:    2021/3/18
*描  述:    I2C从机高速传输例程
            1.本例程使用编译器优化的方法来实现I2C的高速传输，例程中主机写一个数据给
			从机，再读回两个数据，从机将接收到的数据以原码和反码的形式发回给主机。
			2.使用这种方法实现I2C传输时需要做到：
				A.使用向量中断，尽可能将I2C的中断优先级放在最高位；
				B.编译之前需要设置编译器，在“项目”菜单->“编译”->“IIC slave high speed mode”选择“true”，
										  在“项目”菜单->“编译”->“Support interrupt vectors”选择“true”；
				C.用户在处理完数据，写数据到I2CTB寄存器里面后需要软件释放SCL，即“I2CTE = 1”，主机才能读数据；
				D.当用户传输速度大于400KHz时，建议除能I2C滤波功能，且系统时钟不低于32MHz。
*备  注:   本软件仅供学习和演示使用，对用户直接引用代码所带来的风险或后果不承担任何法律责任。
**********************************************************/
#include <HIC.h>

sbit  I2C_Restart;
unsigned char I2CRB_REG;
unsigned char I2CTB_REG;

/*********************************************************
函数名: void clear_ram(void)
描  述: RAM中数据全部清零
输入值: 无
输出值: 无
返回值: 无 
**********************************************************/  
void clear_ram(void) 
{
    __asm 
    { 
         CLR   IAAL;
         CLR   IAAH;
         CLR   IAD;
         INC   IAAL,1;
         JBS   PSW,C
         GOTO  $-3;
         INC   IAAH,1;
         JBS   IAAH,2
         GOTO  $-6;
    } 
}

/*********************************************************
函数名: void delay(void)
描  述: 简单延时函数delay
输入值: 无
输出值: 无
返回值: 无 
**********************************************************/
void delay(void)
{
	unsigned char i = 50;
	while(i--);
}

/*********************************************************
函数名: void Init_i2c(void)
描  述:  I2CS模块初始化
输入值: 无
输出值: 无
返回值: 无 
**********************************************************/
void Init_i2c(void)        
{
	{
		ANSL = 0xFF;        //选择对应端口为数字IO功能
		ANSH = 0xFF;
		PAT = 0x00;         //所有IO设为输出低电平
		PBT = 0x00;
		PCT = 0x00;
		PA = 0x00;
		PB = 0x00;
		PC = 0x00;

		PBT0 = 1;					//I2C_SDA,输入
		PBT1 = 0;					//I2C_SCL,输出
	}

	I2C_Restart = 0;		//发送源码或反码标志
	I2CRST = 1;				//复位I2C
	while(I2CRST);
	I2CX16 = 0x0;				//采样滤波，当传输速度大于400KHz时，建议关闭采样滤波
	I2CSA = 0x2D<<1;			//从机地址0x2D
	I2CC = 0xE1;		//使能I2C端口，开漏，内部弱上拉
	I2CIEC = 0x0B;	//使能“起始位+从地址匹配+发送应答”中断使能，结束位中断使能
	I2CIE = 1;				//开启I2C总中断
}


/*********************************************************
函数名: void main()
描  述: 主函数
输入值: 无
输出值: 无 
返回值: 无  
**********************************************************/
void main(void)
{
	clear_ram();
    Init_i2c();
	INTG = 0b11000111;    //使能全局中断，设置向量中断
	INTP = 0b01000000;	  //中断优先级设置,IG6最高
	
    while(1)
    {
        ;
    }
}

/*********************************************************
函数名: void IG6_INT(void) interrupt_high  0x000C
描  述: IIC中断服务程序
输入值: 无
输出值: 无
返回值: 无 
**********************************************************/ 
void IG6_INT(void) interrupt_high  0x000C
{
	if(I2CIF && I2CIE) 
    {
        if(I2CSRIE && I2CSRIF)/*收到起始位+地址匹配+发送应答位中断*/
        {
            I2CSRIF = 0;               //清I2C起始位+地址匹配+发送应答位标志位            
            if(I2CRW) /*主机读*/
            {		
                //I2CRBIE = 0;           //I2C接收中断禁止
                I2CTBIE = 1;           //I2C发送中断使能
                I2C_Restart = 1;
            }
            else /*主机写*/
            {	
                //I2CRBIE = 1;           //I2C接收中断使能
                I2CTBIE = 0;           //I2C发送中断禁止     
            }     
        }
		
        else if(I2CRBIE && I2CRBIF)/*I2C接收缓冲器有接收数据*/
        {
            I2CRB_REG = I2CRB;        //读接收缓冲器，硬件清接收中断标志     
        }
		
        else if(I2CTBIE && I2CTBIF)/*I2C发送缓冲器未满中断*/
        {
			I2CTBIF = 0;
            if(I2C_Restart)
            {	                       
                I2CTB = I2CRB_REG;   //写原码至发送缓冲器
				I2CTE = 1; 
                I2C_Restart = 0;
            }
            else
            {	
                I2CTB_REG = ~I2CRB_REG;
                I2CTB = I2CTB_REG;   //写反码至发送缓冲器 
				I2CTE = 1; 
            } 
        }
		
		else if((I2CNAIE && I2CNAIF)||(I2CSPIE && I2CSPIF))/*接收NACK和停止位中断*/
        {
			PCT1 = 0;
			PC1 = 0;
			
			I2C_Restart = 0;	    //发送原码或反码标志
            I2CRST = 1;				//I2C模块复位使能
            while(I2CRST);          //I2C模块复位完成
            I2CX16 = 0x0;				//采样滤波，速度大于400KHz时建议关闭
			I2CSA = 0x2D<<1;			//重置从机地址
			I2CC = 0xE1;      //使能I2C端口，开漏，内部弱上拉
			I2CIEC = 0x0B;    //使能“起始位+从地址匹配+发送应答”中断使能，结束位中断使能
			I2CIE = 1;              //开启I2C总中断
        }
	}
     I2CIF = 0;
 }
