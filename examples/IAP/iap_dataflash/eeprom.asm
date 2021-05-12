;编译器支持用户向芯片的DataFlash区指定地址填写初始化值，编译后的初始化值会包含在Hex文件中。
;当用户将该Hex文件烧录到芯片中时，初始化值将自动写入到DataFlash区的指定地址。
;命令格式：
;       eeprom 0x1F00
;       name DW 0x1234,0x5678
;       END
;示例如下：
tmp eeprom 0x1F00   ;指定起始地址
    DW 0x1234,0x5678,0x9ABC,0xDEF0,0x1234,0x5678,0x9ABC,0xDEF0;
    DW 0x1234,0x5678,0x9ABC,0xDEF0,0x1234,0x5678,0x9ABC,0xDEF0;
    DW 0x1234,0x5678,0x9ABC,0xDEF0,0x1234,0x5678,0x9ABC,0xDEF0;
    DW 0x1234,0x5678,0x9ABC,0xDEF0,0x1234,0x5678,0x9ABC,0xDEF0;
    DW 0x1234,0x5678,0x9ABC,0xDEF0,0x1234,0x5678,0x9ABC,0xDEF0;
    DW 0x1234,0x5678,0x9ABC,0xDEF0,0x1234,0x5678,0x9ABC,0xDEF0;
END