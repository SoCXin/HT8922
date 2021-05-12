#include  <hic.h>
#include  "typedef.h"
extern isp_data_t g_isp_data;
u32  g_boot_timer;   //超时引导程序计时器
u32  g_frame_timer;  //帧间隔超时计时器
u8   g_boot;  //引导程序标识

/**********************************************
函数名：Timer_Proc
描  述：定时器处理函数
输入值：无
输出值：无
返回值：无
**********************************************/
void  Timer_Proc(void)
{
    static u16 t1s_tmp = 0 ;
    if(T8NIF == 1)   //每4ms产生一次
    {
        T8NIF = 0;
        T8N = 130;
        if(PA0 == 0)  //BootPIN拉低
		{
			if(g_boot_timer != 0)
			{
				g_boot_timer--;
				if(g_boot_timer == 0)
				{
					g_boot = 1;  //引导程序
				}
			}
		}
		if(g_frame_timer != 0) //帧字节间隔时间超时复位，并使命令重新进入等待命令码的状态
		{
			g_frame_timer--;
			if(g_frame_timer == 0)
			{
				g_isp_data.step = WAIT_REV_INS;
				//g_isp_data.syn = 0;
				//Init_Uart();
			}
		}
    }
}