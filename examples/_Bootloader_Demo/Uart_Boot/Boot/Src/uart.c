#include  <hic.h>
#include  "typedef.h"
#include "rw_flash.h"

isp_data_t g_isp_data;   //通信数据与通信状态机寄存器
extern u32  g_boot_timer;
extern u32  g_frame_timer;

/***************************************************************
函数名：start_tx
描  述: 启动UART发送
输入值：发送的字节数
输出值：无
返回值：无 
***************************************************************/
void start_tx(u8 len)
{	
	g_isp_data.tx_cnt = 0;
 	g_isp_data.tx_len = len; 
	TX0B = g_isp_data.tx_buf[0];
	while(1)
	{
		g_isp_data.tx_cnt++;
		if(g_isp_data.tx_cnt > g_isp_data.tx_len)    //发送完成，触发下一步工作
		{
			while(!TX0IF);
			g_isp_data.triger = 1;      //触发状态机进入下一步
			g_isp_data.rx_cnt=0;
			break;
		}
		else
		{
			while(!TX0IF);
			TX0B = g_isp_data.tx_buf[g_isp_data.tx_cnt];
		}
	}
}
/***************************************************************
函数名：UartReceive
描  述: UART接收数据
输入值：无
输出值：无
返回值：无 
***************************************************************/
void UartReceive(void)
{
	volatile u8   buf8;
	while(1)				//如果没有接收到数据直接退出
	{	
		if(RX0IF)
		{
			buf8 = RX0B;
			g_boot_timer = Boot_OVERTIME_2;
			if(g_isp_data.syn)  //如果同步成功
			{
				if((buf8 == SYN) &&(g_isp_data.step == WAIT_REV_INS))
				{
					g_isp_data.tx_buf[0] = ACK;
					start_tx(0);
					g_isp_data.triger=0;
					break;			
				}
				else
				{					
				
					if(g_isp_data.step == WAIT_REV_INS)
					{
						g_isp_data.rx_len = 1;
						g_isp_data.rx_cnt = 0;
						g_isp_data.step = IN_REV_INS;  //正在接收指令码		
					}
					g_isp_data.rx_buf[g_isp_data.rx_cnt] = buf8;
					g_isp_data.rx_cnt++;
					if(g_isp_data.rx_cnt == 2 && g_isp_data.step == WAIT_REV_PARA1 && g_isp_data.cmd == EX_ERASE)
					{
						g_isp_data.rx_len = (g_isp_data.rx_buf[1]+2) * 2;
					}
					if(g_isp_data.rx_cnt == 1 && g_isp_data.step == WAIT_REV_PARA2 && g_isp_data.cmd == WRITE_M)
					{
						g_isp_data.rx_len = g_isp_data.rx_buf[0] + 2;
					}
					if(g_isp_data.rx_cnt > g_isp_data.rx_len)    //接收完成，触发下一步工作
					{
							
						g_isp_data.triger = 1;  //触发状态机进入下一步
						break;
					}
					
				}
			}
			else if(buf8 == SYN)  //如果接收到启动码则同步成功
			{
				g_isp_data.tx_buf[0] = ACK;
				g_isp_data.syn = 1;  //同步完成			
				g_isp_data.step = WAIT_REV_INS;
				g_isp_data.triger=0;
				start_tx(0);
				break;	
			}
		}
		else
		{
			break;
		}
	}
}