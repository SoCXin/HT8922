#include "ES7P169C.inc"


EXTERN	_main
EXTERN ?_TMP

APP_ENTRY EQU 0x0800		;用户程序入口地址

_STARTUP	CSEG 0X00
	CALL	_main	;jump to the entry of main function
	GOTO	0x00		
	NOP
	NOP
	PUSH
	AJMP	APP_ENTRY+4		;jump to the entry of interrupt function
END
