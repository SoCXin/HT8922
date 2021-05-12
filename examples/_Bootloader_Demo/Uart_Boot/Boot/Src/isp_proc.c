#include "typedef.h"
#include "rw_flash.h"
#include "string.h"
#include "uart.h"
#include <hic.h>
extern isp_data_t g_isp_data;
extern u32  g_boot_timer;
extern u32  g_frame_timer;
extern u8   g_boot;

/***************************************************************
函数名：next_ans_ins
描  述: 响应指令码后确定下一步
输入值：指令码
输出值：无
返回值：无 
***************************************************************/
void next_ans_ins(u8 ins)
{
	switch(ins)
	{
		case  READ_M:
		case  CHECK_EMPTY:
		case  WRITE_M:
		case  EX_ERASE:
		case  GO:
			g_isp_data.step = WAIT_REV_PARA1;
			g_isp_data.rx_len = 4;
			break;
		default:
			g_isp_data.step = WAIT_REV_INS;
			break;
	}
	
}
/***************************************************************
函数名：wait_rev_para1
描  述: 参数1处理
输入值：指令码
输出值：无
返回值：无 
***************************************************************/
void wait_rev_para1(u8 ins)
{
	u8 buf8,i;
	switch(ins)
	{
		case  READ_M:
		case  WRITE_M:
			buf8 = g_isp_data.rx_buf[0] ^ g_isp_data.rx_buf[1];
			buf8 = buf8 ^ g_isp_data.rx_buf[2];
			buf8 = buf8 ^ g_isp_data.rx_buf[3];

			if(g_isp_data.rx_buf[4] == buf8)
			//if(1)
			{
				g_isp_data.tx_buf[0] = ACK;
				g_isp_data.para1.b08[0] = g_isp_data.rx_buf[3]; 
				g_isp_data.para1.b08[1] = g_isp_data.rx_buf[2]; 
				g_isp_data.para1.b08[2] = g_isp_data.rx_buf[1]; 
				g_isp_data.para1.b08[3] = g_isp_data.rx_buf[0]; 
				g_isp_data.step = END_REV_PARA1;
				start_tx(0);				
			}
			else
			{
				g_isp_data.tx_buf[0] = NACK;
				g_isp_data.step = IN_SEND_OVER;
			}
			break;
		case  EX_ERASE:
			if(g_isp_data.rx_buf[0] == 0xFF)
			{
				g_isp_data.tx_buf[0] = NACK;
				g_isp_data.step = IN_SEND_OVER;	
			}
			else
			{
				g_isp_data.para1.b32 = 0;
				g_isp_data.para1.b08[0] = g_isp_data.rx_buf[2];
				g_isp_data.para1.b08[1] = g_isp_data.rx_buf[1]; 							
			}
			buf8 = g_isp_data.rx_buf[0] ^ g_isp_data.rx_buf[1];
			for(i=2; i<g_isp_data.rx_len; i++)
			{
				buf8 = buf8 ^ g_isp_data.rx_buf[i];
			}
			if(buf8 == g_isp_data.rx_buf[g_isp_data.rx_len])
			{
				g_isp_data.step = IN_EXE_INS;
			}
			else
			{
				g_isp_data.tx_buf[0] = NACK;
				g_isp_data.step = IN_SEND_OVER;		
			}
			break;
		case  CHECK_EMPTY:
			buf8 = g_isp_data.rx_buf[0] ^ g_isp_data.rx_buf[1];
			buf8 = buf8 ^ g_isp_data.rx_buf[2];
			buf8 = buf8 ^ g_isp_data.rx_buf[3];
			if(g_isp_data.rx_buf[4] == buf8)
			{
				g_isp_data.para1.b08[0] = g_isp_data.rx_buf[3]; 
				g_isp_data.para1.b08[1] = g_isp_data.rx_buf[2];
				g_isp_data.para1.b08[2] = g_isp_data.rx_buf[1]; 
				g_isp_data.para1.b08[3] = g_isp_data.rx_buf[0];
				g_isp_data.para1.b32=g_isp_data.para1.b32>>1;
				if((g_isp_data.para1.b32 % 4) == 0)
				{
					g_isp_data.tx_buf[0] = ACK;
					g_isp_data.step = END_REV_PARA1;
					start_tx(0);				
				}
				else
				{
					g_isp_data.tx_buf[0] = NACK;
					g_isp_data.step = IN_SEND_OVER;			
				}
			}
			else
			{
				g_isp_data.tx_buf[0] = NACK;
				g_isp_data.step = IN_SEND_OVER;
			}
		  break;
		  case  GO:
			buf8 = g_isp_data.rx_buf[0] ^ g_isp_data.rx_buf[1];
			buf8 = buf8 ^ g_isp_data.rx_buf[2];
			buf8 = buf8 ^ g_isp_data.rx_buf[3];
			if(g_isp_data.rx_buf[4] == buf8)
			{
				g_isp_data.para1.b08[0] = g_isp_data.rx_buf[3]; 
				g_isp_data.para1.b08[1] = g_isp_data.rx_buf[2]; 
				g_isp_data.para1.b08[2] = g_isp_data.rx_buf[1]; 
				g_isp_data.para1.b08[3] = g_isp_data.rx_buf[0]; 
				g_isp_data.step = WAIT_REV_PARA2;
				g_isp_data.tx_buf[0] = ACK;
				start_tx(0);
			}
			else
			{
				g_isp_data.tx_buf[0] = NACK;
				g_isp_data.step = IN_SEND_OVER;
			}
			break;
		default:
			g_isp_data.step = WAIT_REV_INS;
			break;
	}
	
}
/***************************************************************
函数名：next_rev_para1
描  述: 参数1处理后的下一步确定
输入值：指令码
输出值：无
返回值：无 
***************************************************************/
void next_rev_para1(u8 ins)
{
	switch(ins)
	{
		case  READ_M:
		case  WRITE_M:
			g_isp_data.rx_len = 1;
			g_isp_data.step = WAIT_REV_PARA2;
			break;
		case  CHECK_EMPTY:
			g_isp_data.rx_len = 4;
			g_isp_data.step = WAIT_REV_PARA2;
			break;
		default:
			g_isp_data.step = WAIT_REV_INS;
			break;
	}
}
/***************************************************************
函数名：wait_rev_para2
描  述: 参数2处理
输入值：指令码
输出值：无
返回值：无 
***************************************************************/
void wait_rev_para2(u8 ins)
{
	u8 i,buf8;
	switch(ins)
	{
		case  READ_M:
			if(g_isp_data.rx_buf[0] == (u8)(~g_isp_data.rx_buf[1]))
			{
				g_isp_data.para2.b08[0] = g_isp_data.rx_buf[0]; 
				g_isp_data.step = IN_EXE_INS;
				g_isp_data.tx_buf[0] = ACK;
				start_tx(0);
			}
			else
			{
				g_isp_data.tx_buf[0] = NACK;
				g_isp_data.step = IN_SEND_OVER;
			}
			break;
		case  WRITE_M:
			g_isp_data.para2.b32 = g_isp_data.rx_buf[0]; 
			g_isp_data.step = IN_EXE_INS;
			break;
		case  CHECK_EMPTY:
			buf8 = g_isp_data.rx_buf[0] ^ g_isp_data.rx_buf[1];
			buf8 = buf8 ^ g_isp_data.rx_buf[2];
			buf8 = buf8 ^ g_isp_data.rx_buf[3];
			if(buf8 == g_isp_data.rx_buf[4])
			{
				g_isp_data.para2.b08[0] = g_isp_data.rx_buf[3]; 
				g_isp_data.para2.b08[1] = g_isp_data.rx_buf[2]; 
				g_isp_data.para2.b08[2] = g_isp_data.rx_buf[1]; 
				g_isp_data.para2.b08[3] = g_isp_data.rx_buf[0]; 
				if((g_isp_data.para2.b32+1) % 4 == 0)
				{
					g_isp_data.tx_buf[0] = ACK;
					g_isp_data.step = IN_EXE_INS;
					start_tx(0);
				}
				else
				{
					g_isp_data.tx_buf[0] = NACK;
					g_isp_data.step = IN_SEND_OVER;				
				}
			}
			else
			{
				g_isp_data.tx_buf[0] = NACK;
				g_isp_data.step = IN_SEND_OVER;
			}
			break;
		case  GO:
			g_isp_data.step = IN_EXE_INS;
			g_isp_data.tx_buf[0] = ACK;
			start_tx(0);
			break;
		default:
			g_isp_data.step = WAIT_REV_INS;
			break;
	}
}

/***************************************************************
函数名：in_exe_ins
描  述: 执行各指令码
输入值：指令码
输出值：无
返回值：无 
***************************************************************/
u16 test;
void in_exe_ins(u8 ins)
{
	g_boot_timer = Boot_OVERTIME_2;
	volatile u8  buf8,wr_buf8[130],result,i;
	volatile u16 page;
	u32 buf32,iap_addr;
	switch(ins)
	{
		case  READ_M:
			Read_Cont(g_isp_data.para1.b32>>1,g_isp_data.tx_buf,g_isp_data.para2.b08[0]+1);
			g_isp_data.step = WAIT_REV_INS;
			start_tx(g_isp_data.para2.b08[0]);
			break;
		case  WRITE_M:
			g_isp_data.step = IN_SEND_OVER;
			buf8 = g_isp_data.rx_buf[0] ^ g_isp_data.rx_buf[1];
			for(i=2; i<(g_isp_data.para2.b32+2); i++)
			{
				buf8 = buf8 ^ g_isp_data.rx_buf[i];
			}
			if(buf8 ==  g_isp_data.rx_buf[i])  //下发的数据校验正确
			{
				memcpy(wr_buf8, g_isp_data.rx_buf+1, g_isp_data.para2.b32+1);
				result = Write_Cont(g_isp_data.para1.b32>>1,wr_buf8,g_isp_data.para2.b32+1);


				//if(g_isp_data.para1.b32 >= 0x3FFF)
				//{
					//test = 0;
				//}
				if(result == FAILED) //失败
				{
					g_isp_data.tx_buf[0] = NACK;
				}
				else
				{
					Read_Cont(g_isp_data.para1.b32>>1, g_isp_data.rx_buf+1, g_isp_data.para2.b32+1);
					buf8 = g_isp_data.rx_buf[0] ^ g_isp_data.rx_buf[1];
					for(i=2; i<(g_isp_data.para2.b32+2); i++)
					{
						buf8 = buf8 ^ g_isp_data.rx_buf[i];
					}
					if(buf8 ==  g_isp_data.rx_buf[i])  //写入的数据校验是否正确
					{
						g_isp_data.tx_buf[0] = ACK;						
					}
					else
					{
						g_isp_data.tx_buf[0] = NACK;
					}
				}
			}
			else
			{
				g_isp_data.tx_buf[0] = NACK;
			}
			break;
		case  EX_ERASE:
			for(i=0; i<g_isp_data.para1.b08[0]+1; i++)
			{
				page=(((u16)g_isp_data.rx_buf[3+i*2]+((u16)g_isp_data.rx_buf[2+i*2]<<8))<<8);	//0x1000
				if(Erase_Page(page)!= SUCCESS)
					break;					
			}
			if(i != g_isp_data.para1.b08[0]+1)  //擦除有误
			{
				g_isp_data.tx_buf[0] = NACK;
			}
			else
			{
				g_isp_data.tx_buf[0] = ACK;				
			}
			g_isp_data.step = IN_SEND_OVER;
			break;
		case  CHECK_EMPTY:
			result=check_empty(g_isp_data.para1.b32,wr_buf8,g_isp_data.para2.b32+1);
			if(result)
			{
				g_isp_data.tx_buf[0] = ACK;
			}
			else
			{
				g_isp_data.tx_buf[0] = NACK;
			}
			g_isp_data.step = IN_SEND_OVER;
			break;
		case  GO:
			PCRH=g_isp_data.para1.b32>>8;
			PCRL=g_isp_data.para1.b32;
			break;
		default:
			g_isp_data.step = WAIT_REV_INS;
			break;
	}
}

/***************************************************************
函数名：fsm_init
描  述: 状态机初始化
输入值：无
输出值：无
返回值：无 
***************************************************************/
void fsm_init(void)
{
	g_isp_data.syn = 0;
	g_isp_data.step = WAIT_REV_INS;
	g_isp_data.cmd = 0;  //指令码
	g_isp_data.rx_len = 1;    //接收长度
	g_isp_data.tx_len = 0;    //发送长度
	g_isp_data.rx_cnt = 0;    //接收计数
	g_isp_data.tx_cnt = 0;    //发送计数
	g_isp_data.triger = 0;    //上一步动作完成，触发下一步动作
	g_boot_timer = Boot_OVERTIME_1;
	g_boot=0;
}


/***************************************************************
函数名：uart_proc_fsm
描  述: UART命令帧处理状态机
输入值：无
输出值：无
返回值：无 
***************************************************************/
void uart_proc_fsm(void)
{
	g_isp_data.triger = 0;
	switch(g_isp_data.step)
	{
		case  IN_REV_INS:  //0:接收指令码
			if(g_isp_data.rx_buf[0] == (u8)(~g_isp_data.rx_buf[1])) //如果同步码校验正确
			{
				g_isp_data.tx_buf[0] = ACK;
				g_isp_data.step = END_IN_INS;
				g_isp_data.cmd = g_isp_data.rx_buf[0];
			}
			else
			{
				g_isp_data.tx_buf[0] = NACK;
				g_isp_data.step = IN_SEND_OVER;
			}
			start_tx(0);
			break;
		case  END_IN_INS:  //完成接收指令码
			next_ans_ins(g_isp_data.cmd);
			break;
		case  WAIT_REV_PARA1://等待接收参数1
			wait_rev_para1(g_isp_data.cmd);
			g_isp_data.triger = 1;
			break;
		case  END_REV_PARA1: //接收参数1完成
			next_rev_para1(g_isp_data.cmd);
			break;
		case  WAIT_REV_PARA2://等待接收参数2
			wait_rev_para2(g_isp_data.cmd);
			g_isp_data.triger = 1;
			break;
		case  IN_EXE_INS:  //执行指令
			in_exe_ins(g_isp_data.cmd);
			g_isp_data.triger = 1;
			break;
		case  IN_SEND_OVER:  //发送结束ACK
			start_tx(0);
			g_isp_data.step = WAIT_REV_INS;
			g_isp_data.rx_len = 1;    //接收长度
			g_isp_data.triger = 0;
			break;
		default:             //其他状态回归等待同步码状态
			g_isp_data.step = WAIT_REV_INS;  //等待指令码
			g_isp_data.rx_len = 1;    //接收长度
			g_isp_data.triger = 0;
			break;
	}
}
