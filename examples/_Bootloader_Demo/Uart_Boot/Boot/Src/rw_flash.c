#include  <hic.h>
#include  <string.h>
#include  "typedef.h"
#include  "macrodef.h"
#include  "rw_flash.h"

/**********************************************
函数名：check_empty
描  述：查询Flash是否为空
输入值：word_addr:Flash起始地址;num:查空的字节数
输出值：无
返回值：SUCCESS，FAILED
**********************************************/
u8 check_empty(u16  word_addr, u8 *buf_Addr, u16 num)
{
	u16  i,buf16;
    for(i = 0; i < (num / 2); i++)
    {
		if(i % 2 == 1){

			__Asm  TBR;

			buf16 = (((u16)ROMD1H << 8) + ROMD1L);
			++word_addr;
			buf_Addr += 2;
		}
		if(i % 2 == 0){
			FRAL = word_addr;
			FRAH = word_addr >> 8;
			FRAHN = ~FRAH;
			FRALN = ~FRAL;
			__Asm  TBR;
			buf16 = (((u16)ROMDH << 8) + ROMDL);
			++word_addr;
			buf_Addr += 2;
		}

        if(buf16 != 0xFFFF)
		{
			return  FAILED;
		}
    }
    return  SUCCESS;
}
/**********************************************
函数名：Read_Cont
描  述：连续读Flash
输入值：word_addr:Flash地址; *buf_Addr:数据保存地址; num:连续读的字节数
输出值：Flash中的数据
返回值：SUCCESS，FAILED
**********************************************/
u8 Read_Cont(u16  word_addr, u8 *buf_Addr, u16 num)
{
    u16  i;
    for(i = 0; i < (num / 2); i++)
    {
		if(i % 2 == 1){
			__Asm  TBR;
			*(u16 *)buf_Addr = (((u16)ROMD1H << 8) + ROMD1L);
			word_addr++;
			buf_Addr += 2;
		}
		if(i % 2 == 0){
			FRAL = word_addr;
			FRAH = word_addr >> 8;
			FRAHN = ~FRAH;
			FRALN = ~FRAL;
			__Asm  TBR;
			*(u16 *)buf_Addr = (((u16)ROMDH << 8) + ROMDL);
			word_addr++;
			buf_Addr += 2;
		}
    }
	ROMCL=0x00;
    return  SUCCESS;
}
/**********************************************
函数名：StartIAP
描  述：IAP固定操作
输入值：无
输出值：无
返回值：无
**********************************************/
void StartIAP(void)	//IAP固定格式
{
	__asm
	{
			  MOVI 0x55
			  MOVA ROMCH
			  MOVI 0x02        //等待8个指令周期
			  SSUBI 1          //(A)-1->(A)
			  JBS PSW,Z
			  goto $-2
			  MOVI 0xAA
			  MOVA ROMCH
			  MOVI 0x02        //等待8个->(指令周期
			  SSUBI 1          //(A)-1A)
			  JBS PSW,Z
			  goto $-2
     		  BSS ROMCL,WR     //Flash存储器页擦除/自编程触发位
			  JBC ROMCL,WR
			  goto $-1         //等待操作结束
	}
}
/**********************************************
函数名：Erase_Page
描  述：擦除一页Flash
输入值：page_addr：擦除页所在的地址
输出值：无
返回值：SUCCESS，FAILED
**********************************************/
u8 Erase_Page(u16  page_addr)
{
	GIE = 0 ;
	DATARDEN = 1;
	FPEE=1;
    FRAH = page_addr >> 8;	//地址高字节
	FRAL = page_addr;		//地址低字节
	FRAHN = ~FRAH;
	FRALN = ~FRAL;
	WREN=1;
	StartIAP();
	//while(WR);	//等待擦除结束
	ROMCL=0x00;
	return SUCCESS;	
}
/**********************************************
函数名：Write_SingleWord
描  述：向Flash中连续写数据
输入值：word_addr：Flash起始地址;buf_Addr:要写入数据的起始地址 num:数据个数
输出值：无
返回值：SUCCESS，FAILED
**********************************************/
u8 Write_Cont(u16  word_addr, u8 *buf_Addr, u16 num)
{
    u16  i;

	GIE = 0;
	ROMCL=0x80;			
	DATARDEN = 1;
	FPEE=0;

    for(i = 0; i < (num / 2); i++)

    {
		if(i % 2 == 0){
		    FRAH = word_addr >> 8;	//地址高字节
			FRAL = word_addr;		//地址低字节
			FRAHN = ~FRAH;
			FRALN = ~FRAL;
			ROMDH = (*((u16 *)buf_Addr)) >> 8; //
			ROMDL = (*((u16 *)buf_Addr));	 //写入Flash的字节数据
			word_addr++;
			buf_Addr += 2;
		}

		if(i % 2 == 1){
			ROMD1H = (*((u16 *)buf_Addr)) >> 8; //
			ROMD1L = (*((u16 *)buf_Addr));	 //写入Flash的字节数据
			WREN=1;
			StartIAP();
			word_addr++;
			buf_Addr += 2;
		}
    }
	ROMCL=0x00;
    return  SUCCESS;
}


