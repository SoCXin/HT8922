#ifndef   __RW_FLASH__H
#define   __RW_FLASH__H

u8 check_empty(u16  word_addr, u8 *buf_Addr, u16 num);
u8 Read_Cont(u16  word_addr, u8 *buf_Addr, u16 num);

u8 Erase_Page(u16  page_addr);
u8 Write_Cont(u16  word_addr, u8 *buf_Addr, u16 num);


#endif
