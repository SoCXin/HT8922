	LIST
;   Standard Header File, Ver 1.0
;   Copyright(C) Shanghai Eastsoft Microelectronics Co., Ltd.
;   Rev Date : 2020-7-7
 	NLIST


;-----------[Register Map]----------------
IAD                     EQU     H'FF80'
IAAL                    EQU     H'FF81'
IAAH                    EQU     H'FF82'
BKSR                    EQU     H'FF83'
PSW                     EQU     H'FF84'
AREG                    EQU     H'FF85'
PCRL                    EQU     H'FF86'
PCRH                    EQU     H'FF87'
MULA                    EQU     H'FF88'
MULL                    EQU     H'FF88'
MULB                    EQU     H'FF89'
MULH                    EQU     H'FF89'
TMRADC                  EQU     H'FF8A'
BEEPC                   EQU     H'FF8B'
LVDC                    EQU     H'FF8C'
ANSH                    EQU     H'FF8D'
FRALN                   EQU     H'FF8E'
FRAHN                   EQU     H'FF8F'
FRAL                    EQU     H'FF90'
FRAH                    EQU     H'FF91'
ROMDL                   EQU     H'FF92'
ROMDH                   EQU     H'FF93'
ROMCL                   EQU     H'FF94'
ROMCH                   EQU     H'FF95'
INTG                    EQU     H'FF96'
INTP                    EQU     H'FF97'
INTC0                   EQU     H'FF98'
INTE0                   EQU     H'FF99'
INTF0                   EQU     H'FF9A'
INTE1                   EQU     H'FF9B'
INTF1                   EQU     H'FF9C'
INTE2                   EQU     H'FF9D'
INTF2                   EQU     H'FF9E'
INTE3                   EQU     H'FF9F'
INTF3                   EQU     H'FFA0'
ROMD1L                  EQU     H'FFA1'
ROMD1H                  EQU     H'FFA2'
KMSK                    EQU     H'FFA3'
WDTC                    EQU     H'FFA4'
WDTP                    EQU     H'FFA5'
WKDC                    EQU     H'FFA6'
PWEN                    EQU     H'FFA7'
PA                      EQU     H'FFA8'
PB                      EQU     H'FFA9'
PC                      EQU     H'FFAA'
PAFLT                   EQU     H'FFAB'
PBFLT                   EQU     H'FFAC'
PAT                     EQU     H'FFAD'
PBT                     EQU     H'FFAE'
PCT                     EQU     H'FFAF'
PAPD                    EQU     H'FFB0'
PBPD                    EQU     H'FFB1'
PAPU                    EQU     H'FFB2'
PBPU                    EQU     H'FFB3'
PCPU                    EQU     H'FFB4'
PCFLT                   EQU     H'FFB5'
PWRC                    EQU     H'FFB6'
PACTR                   EQU     H'FFB7'
PBCTR                   EQU     H'FFB8'
PCCTR                   EQU     H'FFB9'
ADCCFL                  EQU     H'FFBA'
PORTCTR                 EQU     H'FFBB'
ANSL                    EQU     H'FFBC'
T8N                     EQU     H'FFBD'
T8NC                    EQU     H'FFBE'
T31CHBK                 EQU     H'FFBF'
T31DLYT                 EQU     H'FFC0'
T31C0L                  EQU     H'FFC1'
T31C0H                  EQU     H'FFC2'
T31C1L                  EQU     H'FFC3'
T31C1H                  EQU     H'FFC4'
T31C2L                  EQU     H'FFC5'
T31C2H                  EQU     H'FFC6'
T31IEL                  EQU     H'FFC7'
T31IEH                  EQU     H'FFC8'
T31IDL                  EQU     H'FFC9'
T31IDH                  EQU     H'FFCA'
T31IVSL                 EQU     H'FFCB'
T31IVSH                 EQU     H'FFCC'
T31IFL                  EQU     H'FFCD'
T31IFH                  EQU     H'FFCE'
T31IFML                 EQU     H'FFCF'
T31IFMH                 EQU     H'FFD0'
T31ICRL                 EQU     H'FFD1'
T31ICRH                 EQU     H'FFD2'
T31EVG                  EQU     H'FFD3'
T31CH1C                 EQU     H'FFD4'
;T31CH1C                 EQU     H'FFD4'
T31CH2C                 EQU     H'FFD5'
;T31CH2C                 EQU     H'FFD5'
T31CH3C                 EQU     H'FFD6'
;T31CH3C                 EQU     H'FFD6'
T31CH4C                 EQU     H'FFD7'
;T31CH4C                 EQU     H'FFD7'
T31PINCL                EQU     H'FFD8'
T31PINCH                EQU     H'FFD9'
T31CNTL                 EQU     H'FFDA'
T31CNTH                 EQU     H'FFDB'
T31PRSL                 EQU     H'FFDC'
T31PRSH                 EQU     H'FFDD'
T31CNTLDL               EQU     H'FFDE'
T31CNTLDH               EQU     H'FFDF'
T31POS                  EQU     H'FFE0'
T31CH1RL                EQU     H'FFE1'
T31CH1RH                EQU     H'FFE2'
T31CH2RL                EQU     H'FFE3'
T31CH2RH                EQU     H'FFE4'
T31CH3RL                EQU     H'FFE5'
T31CH3RH                EQU     H'FFE6'
T31CH4RL                EQU     H'FFE7'
T31CH4RH                EQU     H'FFE8'
T21OC                   EQU     H'FFE9'
T21L                    EQU     H'FFEA'
T21H                    EQU     H'FFEB'
T21PL                   EQU     H'FFEC'
T21PH                   EQU     H'FFED'
T21R0L                  EQU     H'FFEE'
T21R0H                  EQU     H'FFEF'
T21CL                   EQU     H'FFF0'
T21CM                   EQU     H'FFF1'
T21CH                   EQU     H'FFF2'
T21R1L                  EQU     H'FFF3'
T21R1H                  EQU     H'FFF4'
T21R2L                  EQU     H'FFF5'
T21R2H                  EQU     H'FFF6'
ADCCM                   EQU     H'FFF7'
ADCRL                   EQU     H'FFF8'
ADCRH                   EQU     H'FFF9'
ADCCL                   EQU     H'FFFA'
ADCCH                   EQU     H'FFFB'
ADCLTRL                 EQU     H'FFFC'
ADCLTRH                 EQU     H'FFFD'
ADCHTRL                 EQU     H'FFFE'
ADCHTRH                 EQU     H'FFFF'
;IAD                     EQU     H'FF80'
;IAAL                    EQU     H'FF81'
;IAAH                    EQU     H'FF82'
;BKSR                    EQU     H'FF83'
;PSW                     EQU     H'FF84'
;AREG                    EQU     H'FF85'
;PCRL                    EQU     H'FF86'
;PCRH                    EQU     H'FF87'
;MULA                    EQU     H'FF88'
;MULL                    EQU     H'FF88'
;MULB                    EQU     H'FF89'
;MULH                    EQU     H'FF89'
;TMRADC                  EQU     H'FF8A'
;BEEPC                   EQU     H'FF8B'
;LVDC                    EQU     H'FF8C'
;ANSH                    EQU     H'FF8D'
;FRALN                   EQU     H'FF8E'
;FRAHN                   EQU     H'FF8F'
;FRAL                    EQU     H'FF90'
;FRAH                    EQU     H'FF91'
;ROMDL                   EQU     H'FF92'
;ROMDH                   EQU     H'FF93'
;ROMCL                   EQU     H'FF94'
;ROMCH                   EQU     H'FF95'
;INTG                    EQU     H'FF96'
;INTP                    EQU     H'FF97'
;INTC0                   EQU     H'FF98'
;INTE0                   EQU     H'FF99'
;INTF0                   EQU     H'FF9A'
;INTE1                   EQU     H'FF9B'
;INTF1                   EQU     H'FF9C'
;INTE2                   EQU     H'FF9D'
;INTF2                   EQU     H'FF9E'
;INTE3                   EQU     H'FF9F'
;INTF3                   EQU     H'FFA0'
;ROMD1L                  EQU     H'FFA1'
;ROMD1H                  EQU     H'FFA2'
;KMSK                    EQU     H'FFA3'
;WDTC                    EQU     H'FFA4'
;WDTP                    EQU     H'FFA5'
;WKDC                    EQU     H'FFA6'
;PWEN                    EQU     H'FFA7'
;PA                      EQU     H'FFA8'
;PB                      EQU     H'FFA9'
;PC                      EQU     H'FFAA'
;PAFLT                   EQU     H'FFAB'
;PBFLT                   EQU     H'FFAC'
;PAT                     EQU     H'FFAD'
;PBT                     EQU     H'FFAE'
;PCT                     EQU     H'FFAF'
;PAPD                    EQU     H'FFB0'
;PBPD                    EQU     H'FFB1'
;PAPU                    EQU     H'FFB2'
;PBPU                    EQU     H'FFB3'
;PCPU                    EQU     H'FFB4'
;PCFLT                   EQU     H'FFB5'
;PWRC                    EQU     H'FFB6'
;PACTR                   EQU     H'FFB7'
;PBCTR                   EQU     H'FFB8'
;PCCTR                   EQU     H'FFB9'
;ADCCFL                  EQU     H'FFBA'
;PORTCTR                 EQU     H'FFBB'
;ANSL                    EQU     H'FFBC'
;T8N                     EQU     H'FFBD'
;T8NC                    EQU     H'FFBE'
;T31CHBK                 EQU     H'FFBF'
SPICON0                 EQU     H'FFC0'
SPICON1                 EQU     H'FFC1'
SPIIE                   EQU     H'FFC2'
SPIIF                   EQU     H'FFC3'
SPIRBR                  EQU     H'FFC4'
SPITBW                  EQU     H'FFC5'
T11L                    EQU     H'FFC6'
T11H                    EQU     H'FFC7'
T11PL                   EQU     H'FFC8'
T11PH                   EQU     H'FFC9'
T11CL                   EQU     H'FFCA'
T11CM                   EQU     H'FFCB'
T11CH                   EQU     H'FFCC'
BR0FRA                  EQU     H'FFCD'
BR1FRA                  EQU     H'FFCE'
RX0B                    EQU     H'FFCF'
RX0C                    EQU     H'FFD0'
TX0B                    EQU     H'FFD1'
TX0C                    EQU     H'FFD2'
BR0R                    EQU     H'FFD3'
RX1B                    EQU     H'FFD4'
RX1C                    EQU     H'FFD5'
TX1B                    EQU     H'FFD6'
TX1C                    EQU     H'FFD7'
BR1R                    EQU     H'FFD8'
I2CX16                  EQU     H'FFD9'
I2CC                    EQU     H'FFDA'
I2CSA                   EQU     H'FFDB'
I2CTB                   EQU     H'FFDC'
I2CRB                   EQU     H'FFDD'
I2CIEC                  EQU     H'FFDE'
I2CIFC                  EQU     H'FFDF'
CALPROT                 EQU     H'FFE0'
;                       EQU     H'FFE1'
;                       EQU     H'FFE2'
;                       EQU     H'FFE3'
;                       EQU     H'FFE4'
;                        EQU     H'FFE5'
;                        EQU     H'FFE6'
;                        EQU     H'FFE7'
;                        EQU     H'FFE8'
;                        EQU     H'FFE9'
;                        EQU     H'FFEA'
;                        EQU     H'FFEB'
;                        EQU     H'FFEC'
;                        EQU     H'FFED'
;                        EQU     H'FFEE'
VRTEST                  EQU     H'FFEF'
;                        EQU     H'FFF0'
;                        EQU     H'FFF1'
;                        EQU     H'FFF2'
;                        EQU     H'FFF3'
;                        EQU     H'FFF4'
;                        EQU     H'FFF5'
;                        EQU     H'FFF6'
;                        EQU     H'FFF7'
;                        EQU     H'FFF8'
;                        EQU     H'FFF9'
;                       EQU     H'FFFA'
;                       EQU     H'FFFB'
;                       EQU     H'FFFC'
;                       EQU     H'FFFD'
;                       EQU     H'FFFE'
;                       EQU     H'FFFF'


;-----------[IAD]----------------
IAD0                   EQU     H'0000'
IAD1                   EQU     H'0001'
IAD2                   EQU     H'0002'
IAD3                   EQU     H'0003'
IAD4                   EQU     H'0004'
IAD5                   EQU     H'0005'
IAD6                   EQU     H'0006'
IAD7                   EQU     H'0007'


;-----------[IAAL]----------------
IAAL0                  EQU     H'0000'
IAAL1                  EQU     H'0001'
IAAL2                  EQU     H'0002'
IAAL3                  EQU     H'0003'
IAAL4                  EQU     H'0004'
IAAL5                  EQU     H'0005'
IAAL6                  EQU     H'0006'
IAAL7                  EQU     H'0007'


;-----------[IAAH]----------------
IAAH0                  EQU     H'0000'
IAAH1                  EQU     H'0001'
IAAH2                  EQU     H'0002'
IAAH3                  EQU     H'0003'
IAAH4                  EQU     H'0004'
IAAH5                  EQU     H'0005'
IAAH6                  EQU     H'0006'
IAAH7                  EQU     H'0007'


;-----------[BKSR]----------------
DBKSR0                 EQU     H'0000'
DBKSR1                 EQU     H'0001'
DBKSR2                 EQU     H'0002'
;                      EQU     H'0003'
SBKSR                  EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[PSW]----------------
C                      EQU     H'0000'
DC                     EQU     H'0001'
Z                      EQU     H'0002'
OV                     EQU     H'0003'
N                      EQU     H'0004'
OF                     EQU     H'0005'
UF                     EQU     H'0006'
;                      EQU     H'0007'


;-----------[AREG]----------------
AREG0                  EQU     H'0000'
AREG1                  EQU     H'0001'
AREG2                  EQU     H'0002'
AREG3                  EQU     H'0003'
AREG4                  EQU     H'0004'
AREG5                  EQU     H'0005'
AREG6                  EQU     H'0006'
AREG7                  EQU     H'0007'


;-----------[PCRL]----------------
PCRL0                  EQU     H'0000'
PCRL1                  EQU     H'0001'
PCRL2                  EQU     H'0002'
PCRL3                  EQU     H'0003'
PCRL4                  EQU     H'0004'
PCRL5                  EQU     H'0005'
PCRL6                  EQU     H'0006'
PCRL7                  EQU     H'0007'


;-----------[PCRH]----------------
PCRH0                  EQU     H'0000'
PCRH1                  EQU     H'0001'
PCRH2                  EQU     H'0002'
PCRH3                  EQU     H'0003'
PCRH4                  EQU     H'0004'
PCRH5                  EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[MULA]----------------
MULA0                  EQU     H'0000'
MULA1                  EQU     H'0001'
MULA2                  EQU     H'0002'
MULA3                  EQU     H'0003'
MULA4                  EQU     H'0004'
MULA5                  EQU     H'0005'
MULA6                  EQU     H'0006'
MULA7                  EQU     H'0007'


;-----------[MULL]----------------
MULL0                  EQU     H'0000'
MULL1                  EQU     H'0001'
MULL2                  EQU     H'0002'
MULL3                  EQU     H'0003'
MULL4                  EQU     H'0004'
MULL5                  EQU     H'0005'
MULL6                  EQU     H'0006'
MULL7                  EQU     H'0007'


;-----------[MULB]----------------
MULB0                  EQU     H'0000'
MULB1                  EQU     H'0001'
MULB2                  EQU     H'0002'
MULB3                  EQU     H'0003'
MULB4                  EQU     H'0004'
MULB5                  EQU     H'0005'
MULB6                  EQU     H'0006'
MULB7                  EQU     H'0007'


;-----------[MULH]----------------
MULH0                  EQU     H'0000'
MULH1                  EQU     H'0001'
MULH2                  EQU     H'0002'
MULH3                  EQU     H'0003'
MULH4                  EQU     H'0004'
MULH5                  EQU     H'0005'
MULH6                  EQU     H'0006'
MULH7                  EQU     H'0007'


;-----------[TMRADC]----------------
TMRADC0                EQU     H'0000'
TMRADC1                EQU     H'0001'
TMRADC2                EQU     H'0002'
TMRADC3                EQU     H'0003'
TMRADC4                EQU     H'0004'
TMRADC5                EQU     H'0005'
TMRADC6                EQU     H'0006'
TMRADC7                EQU     H'0007'


;-----------[BEEPC]----------------
BEEPEN                 EQU     H'0000'
;                      EQU     H'0001'
BEEP_OUTSEL0             EQU     H'0002'
BEEP_OUTSEL1             EQU     H'0003'
BEEPPRE0               EQU     H'0004'
BEEPPRE1               EQU     H'0005'
BEEPIOS0               EQU     H'0006'
BEEPIOS1               EQU     H'0007'


;-----------[LVDC]----------------
LVDV0                  EQU     H'0000'
LVDV1                  EQU     H'0001'
LVDV2                  EQU     H'0002'
;                      EQU     H'0003'
LVDEN                  EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
LVDLS                  EQU     H'0007'


;-----------[ANSH]----------------
;                      EQU     H'0000'
ANSH1                  EQU     H'0001'
ANSH2                  EQU     H'0002'
ANSH3                  EQU     H'0003'
ANSH4                  EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[FRALN]----------------
FRALN0                 EQU     H'0000'
FRALN1                 EQU     H'0001'
FRALN2                 EQU     H'0002'
FRALN3                 EQU     H'0003'
FRALN4                 EQU     H'0004'
FRALN5                 EQU     H'0005'
FRALN6                 EQU     H'0006'
FRALN7                 EQU     H'0007'


;-----------[FRAHN]----------------
FRAHN0                 EQU     H'0000'
FRAHN1                 EQU     H'0001'
FRAHN2                 EQU     H'0002'
FRAHN3                 EQU     H'0003'
FRAHN4                 EQU     H'0004'
FRAHN5                 EQU     H'0005'
FRAHN6                 EQU     H'0006'
FRAHN7                 EQU     H'0007'


;-----------[FRAL]----------------
FRAL0                  EQU     H'0000'
FRAL1                  EQU     H'0001'
FRAL2                  EQU     H'0002'
FRAL3                  EQU     H'0003'
FRAL4                  EQU     H'0004'
FRAL5                  EQU     H'0005'
FRAL6                  EQU     H'0006'
FRAL7                  EQU     H'0007'


;-----------[FRAH]----------------
FRAH0                  EQU     H'0000'
FRAH1                  EQU     H'0001'
FRAH2                  EQU     H'0002'
FRAH3                  EQU     H'0003'
FRAH4                  EQU     H'0004'
FRAH5                  EQU     H'0005'
FRAH6                  EQU     H'0006'
FRAH7                  EQU     H'0007'


;-----------[ROMDL]----------------
ROMDL0                 EQU     H'0000'
ROMDL1                 EQU     H'0001'
ROMDL2                 EQU     H'0002'
ROMDL3                 EQU     H'0003'
ROMDL4                 EQU     H'0004'
ROMDL5                 EQU     H'0005'
ROMDL6                 EQU     H'0006'
ROMDL7                 EQU     H'0007'


;-----------[ROMDH]----------------
ROMDH0                 EQU     H'0000'
ROMDH1                 EQU     H'0001'
ROMDH2                 EQU     H'0002'
ROMDH3                 EQU     H'0003'
ROMDH4                 EQU     H'0004'
ROMDH5                 EQU     H'0005'
ROMDH6                 EQU     H'0006'
ROMDH7                 EQU     H'0007'


;-----------[ROMCL]----------------
DATARDTRG              EQU     H'0000'
WR                     EQU     H'0001'
WREN                   EQU     H'0002'
FPEE                   EQU     H'0003'
;                      EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
DATARDEN               EQU     H'0007'


;-----------[ROMCH]----------------
ROMCH0                 EQU     H'0000'
ROMCH1                 EQU     H'0001'
ROMCH2                 EQU     H'0002'
ROMCH3                 EQU     H'0003'
ROMCH4                 EQU     H'0004'
ROMCH5                 EQU     H'0005'
ROMCH6                 EQU     H'0006'
ROMCH7                 EQU     H'0007'


;-----------[INTG]----------------
INTV0                  EQU     H'0000'
INTV1                  EQU     H'0001'
INTVEN0                EQU     H'0002'
SOFTIF                 EQU     H'0003'
;                      EQU     H'0004'
;                      EQU     H'0005'
GIEL                   EQU     H'0006'
GIE                    EQU     H'0007'


;-----------[INTP]----------------
IGP0                   EQU     H'0000'
IGP1                   EQU     H'0001'
IGP2                   EQU     H'0002'
IGP3                   EQU     H'0003'
IGP4                   EQU     H'0004'
IGP5                   EQU     H'0005'
IGP6                   EQU     H'0006'
IGP7                   EQU     H'0007'


;-----------[INTC0]----------------
PEG00                  EQU     H'0000'
PEG01                  EQU     H'0001'
PEG10                  EQU     H'0002'
PEG11                  EQU     H'0003'
PEG20                  EQU     H'0004'
PEG21                  EQU     H'0005'
PEG30                  EQU     H'0006'
PEG31                  EQU     H'0007'


;-----------[INTE0]----------------
ADIE                   EQU     H'0000'
T8NIE                  EQU     H'0001'
T31IE                  EQU     H'0002'
PIE8                   EQU     H'0003'
KIE                    EQU     H'0004'
ADLTRIE                EQU     H'0005'
ADHTRIE                EQU     H'0006'
SPI_GIEIE              EQU     H'0007'


;-----------[INTF0]----------------
ADIF                   EQU     H'0000'
T8NIF                  EQU     H'0001'
T31IF                  EQU     H'0002'
PIF8                   EQU     H'0003'
KIF                    EQU     H'0004'
ADLTRIF                EQU     H'0005'
ADHTRIF                EQU     H'0006'
SPI_GIEIF              EQU     H'0007'


;-----------[INTE1]----------------
PIE0                   EQU     H'0000'
PIE1                   EQU     H'0001'
PIE2                   EQU     H'0002'
PIE3                   EQU     H'0003'
PIE4                   EQU     H'0004'
PIE5                   EQU     H'0005'
PIE6                   EQU     H'0006'
PIE7                   EQU     H'0007'


;-----------[INTF1]----------------
PIF0                   EQU     H'0000'
PIF1                   EQU     H'0001'
PIF2                   EQU     H'0002'
PIF3                   EQU     H'0003'
PIF4                   EQU     H'0004'
PIF5                   EQU     H'0005'
PIF6                   EQU     H'0006'
PIF7                   EQU     H'0007'


;-----------[INTE2]----------------
TX0IE                  EQU     H'0000'
RX0IE                  EQU     H'0001'
T21VIE                 EQU     H'0002'
T21PIE                 EQU     H'0003'
T21MIE0                EQU     H'0004'
T21MIE1                EQU     H'0005'
I2CIE                  EQU     H'0006'
T21MIE2                EQU     H'0007'


;-----------[INTF2]----------------
TX0IF                  EQU     H'0000'
RX0IF                  EQU     H'0001'
T21VIF                 EQU     H'0002'
T21PIF                 EQU     H'0003'
T21MIF0                EQU     H'0004'
T21MIF1                EQU     H'0005'
I2CIF                  EQU     H'0006'
T21MIF2                EQU     H'0007'


;-----------[INTE3]----------------
TX1IE                  EQU     H'0000'
RX1IE                  EQU     H'0001'
T11VIE                 EQU     H'0002'
T11PIE                 EQU     H'0003'
;                      EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
LVDIE                  EQU     H'0007'


;-----------[INTF3]----------------
TX1IF                  EQU     H'0000'
RX1IF                  EQU     H'0001'
T11VIF                 EQU     H'0002'
T11PIF                 EQU     H'0003'
;                      EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
LVDIF                  EQU     H'0007'


;-----------[ROMD1L]----------------
ROMD1L0                EQU     H'0000'
ROMD1L1                EQU     H'0001'
ROMD1L2                EQU     H'0002'
ROMD1L3                EQU     H'0003'
ROMD1L4                EQU     H'0004'
ROMD1L5                EQU     H'0005'
ROMD1L6                EQU     H'0006'
ROMD1L7                EQU     H'0007'


;-----------[ROMD1H]----------------
ROMD1H0                EQU     H'0000'
ROMD1H1                EQU     H'0001'
ROMD1H2                EQU     H'0002'
ROMD1H3                EQU     H'0003'
ROMD1H4                EQU     H'0004'
ROMD1H5                EQU     H'0005'
ROMD1H6                EQU     H'0006'
ROMD1H7                EQU     H'0007'


;-----------[KMSK]----------------
KMSK0                  EQU     H'0000'
KMSK1                  EQU     H'0001'
KMSK2                  EQU     H'0002'
KMSK3                  EQU     H'0003'
KMSK4                  EQU     H'0004'
KMSK5                  EQU     H'0005'
KMSK6                  EQU     H'0006'
KMSK7                  EQU     H'0007'


;-----------[WDTC]----------------
WDTPRS0                EQU     H'0000'
WDTPRS1                EQU     H'0001'
WDTPRS2                EQU     H'0002'
;                      EQU     H'0003'
WDTPRE                 EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[WDTP]----------------
WDTP0                  EQU     H'0000'
WDTP1                  EQU     H'0001'
WDTP2                  EQU     H'0002'
WDTP3                  EQU     H'0003'
WDTP4                  EQU     H'0004'
WDTP5                  EQU     H'0005'
WDTP6                  EQU     H'0006'
WDTP7                  EQU     H'0007'


;-----------[WKDC]----------------
WKDC0                  EQU     H'0000'
WKDC1                  EQU     H'0001'
WKDC2                  EQU     H'0002'
WKDC3                  EQU     H'0003'
WKDC4                  EQU     H'0004'
WKDC5                  EQU     H'0005'
WKDC6                  EQU     H'0006'
WKDC7                  EQU     H'0007'


;-----------[PWEN]----------------
HALT_PWM               EQU     H'0000'
;                      EQU     H'0001'
BORFLT0                EQU     H'0002'
BORFLT1                EQU     H'0003'
PORLOST                EQU     H'0004'
MRSTF                  EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[PA]----------------
PA0                    EQU     H'0000'
PA1                    EQU     H'0001'
PA2                    EQU     H'0002'
PA3                    EQU     H'0003'
PA4                    EQU     H'0004'
PA5                    EQU     H'0005'
PA6                    EQU     H'0006'
PA7                    EQU     H'0007'


;-----------[PB]----------------
PB0                    EQU     H'0000'
PB1                    EQU     H'0001'
PB2                    EQU     H'0002'
PB3                    EQU     H'0003'
PB4                    EQU     H'0004'
PB5                    EQU     H'0005'
PB6                    EQU     H'0006'
PB7                    EQU     H'0007'


;-----------[PC]----------------
PC0                    EQU     H'0000'
PC1                    EQU     H'0001'
;                      EQU     H'0002'
;                      EQU     H'0003'
;                      EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[PAFLT]----------------
PAFLT0                 EQU     H'0000'
PAFLT1                 EQU     H'0001'
PAFLT2                 EQU     H'0002'
PAFLT3                 EQU     H'0003'
PAFLT4                 EQU     H'0004'
PAFLT5                 EQU     H'0005'
PAFLT6                 EQU     H'0006'
PAFLT7                 EQU     H'0007'


;-----------[PBFLT]----------------
PBFLT0                 EQU     H'0000'
PBFLT1                 EQU     H'0001'
PBFLT2                 EQU     H'0002'
PBFLT3                 EQU     H'0003'
PBFLT4                 EQU     H'0004'
PBFLT5                 EQU     H'0005'
PBFLT6                 EQU     H'0006'
PBFLT7                 EQU     H'0007'


;-----------[PAT]----------------
PAT0                   EQU     H'0000'
PAT1                   EQU     H'0001'
PAT2                   EQU     H'0002'
PAT3                   EQU     H'0003'
PAT4                   EQU     H'0004'
PAT5                   EQU     H'0005'
PAT6                   EQU     H'0006'
PAT7                   EQU     H'0007'


;-----------[PBT]----------------
PBT0                   EQU     H'0000'
PBT1                   EQU     H'0001'
PBT2                   EQU     H'0002'
PBT3                   EQU     H'0003'
PBT4                   EQU     H'0004'
PBT5                   EQU     H'0005'
PBT6                   EQU     H'0006'
PBT7                   EQU     H'0007'


;-----------[PCT]----------------
PCT0                   EQU     H'0000'
PCT1                   EQU     H'0001'
;                      EQU     H'0002'
;                      EQU     H'0003'
;                      EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[PAPD]----------------
PAPD0                  EQU     H'0000'
PAPD1                  EQU     H'0001'
PAPD2                  EQU     H'0002'
PAPD3                  EQU     H'0003'
PAPD4                  EQU     H'0004'
PAPD5                  EQU     H'0005'
PAPD6                  EQU     H'0006'
PAPD7                  EQU     H'0007'


;-----------[PBPD]----------------
PBPD0                  EQU     H'0000'
PBPD1                  EQU     H'0001'
PBPD2                  EQU     H'0002'
PBPD3                  EQU     H'0003'
PBPD4                  EQU     H'0004'
PBPD5                  EQU     H'0005'
PBPD6                  EQU     H'0006'
PBPD7                  EQU     H'0007'


;-----------[PAPU]----------------
PAPU0                  EQU     H'0000'
PAPU1                  EQU     H'0001'
PAPU2                  EQU     H'0002'
PAPU3                  EQU     H'0003'
PAPU4                  EQU     H'0004'
PAPU5                  EQU     H'0005'
PAPU6                  EQU     H'0006'
PAPU7                  EQU     H'0007'


;-----------[PBPU]----------------
PBPU0                  EQU     H'0000'
PBPU1                  EQU     H'0001'
PBPU2                  EQU     H'0002'
PBPU3                  EQU     H'0003'
PBPU4                  EQU     H'0004'
PBPU5                  EQU     H'0005'
PBPU6                  EQU     H'0006'
PBPU7                  EQU     H'0007'


;-----------[PCPU]----------------
PCPU0                  EQU     H'0000'
PCPU1                  EQU     H'0001'
;                      EQU     H'0002'
;                      EQU     H'0003'
;                      EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[PCFLT]----------------
PCFLT0                 EQU     H'0000'
PCFLT1                 EQU     H'0001'
;                      EQU     H'0002'
;                      EQU     H'0003'
;                      EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[PWRC]----------------
N_BOR                  EQU     H'0000'
N_POR                  EQU     H'0001'
N_PD                   EQU     H'0002'
N_TO                   EQU     H'0003'
VRST0                  EQU     H'0004'
VRST1                  EQU     H'0005'
LPM0                   EQU     H'0006'
LPM1                   EQU     H'0007'


;-----------[PACTR]----------------
PA0DS                  EQU     H'0000'
PA1DS                  EQU     H'0001'
PA2DS                  EQU     H'0002'
PA3DS                  EQU     H'0003'
PA4DS                  EQU     H'0004'
PA5DS                  EQU     H'0005'
PA5OD                  EQU     H'0006'
PASMTS                 EQU     H'0007'


;-----------[PBCTR]----------------
PB0DS                  EQU     H'0000'
PB1DS                  EQU     H'0001'
PB2DS                  EQU     H'0002'
PB3DS                  EQU     H'0003'
;                      EQU     H'0004'
PB1OD                  EQU     H'0005'
PB0OD                  EQU     H'0006'
PBSMTS                 EQU     H'0007'


;-----------[PCCTR]----------------
PC0DS                  EQU     H'0000'
PC1DS                  EQU     H'0001'
;                      EQU     H'0002'
;                      EQU     H'0003'
;                      EQU     H'0004'
I2C_SEL                EQU     H'0005'
PC1OD                  EQU     H'0006'
PCSMTS                 EQU     H'0007'


;-----------[ADCCFL]----------------
;                      EQU     H'0000'
;                      EQU     H'0001'
;                      EQU     H'0002'
;                      EQU     H'0003'
T21ADEN                EQU     H'0004'
ADC_LP_EN              EQU     H'0005'
T21ADS                 EQU     H'0006'
ADCVTTEN               EQU     H'0007'


;-----------[PORTCTR]----------------
T21CH0NSEL             EQU     H'0000'
T21CH2NSEL             EQU     H'0001'
ADC_ETR0EN             EQU     H'0002'
AD_ETR1EN              EQU     H'0003'
T31CH3SEL              EQU     H'0004'
T31CH4SEL              EQU     H'0005'
T31CH3NSEL             EQU     H'0006'
UART1SEL               EQU     H'0007'


;-----------[ANSL]----------------
ANSL0                  EQU     H'0000'
ANSL1                  EQU     H'0001'
ANSL2                  EQU     H'0002'
ANSL3                  EQU     H'0003'
ANSL4                  EQU     H'0004'
ANSL5                  EQU     H'0005'
ANSL6                  EQU     H'0006'
ANSL7                  EQU     H'0007'


;-----------[T8N]----------------
T8N0                   EQU     H'0000'
T8N1                   EQU     H'0001'
T8N2                   EQU     H'0002'
T8N3                   EQU     H'0003'
T8N4                   EQU     H'0004'
T8N5                   EQU     H'0005'
T8N6                   EQU     H'0006'
T8N7                   EQU     H'0007'


;-----------[T8NC]----------------
T8NPRS0                EQU     H'0000'
T8NPRS1                EQU     H'0001'
T8NPRS2                EQU     H'0002'
T8NPRE                 EQU     H'0003'
T8NEG                  EQU     H'0004'
T8NM                   EQU     H'0005'
T8NCLK                 EQU     H'0006'
T8NEN                  EQU     H'0007'


;-----------[T31CHBK]----------------
PROTS0                 EQU     H'0000'
PROTS1                 EQU     H'0001'
NOFFS                  EQU     H'0002'
ROFFS                  EQU     H'0003'
BKE                    EQU     H'0004'
BKPS                   EQU     H'0005'
AROE                   EQU     H'0006'
CHOE                   EQU     H'0007'


;-----------[T31DLYT]----------------
DLYT0                  EQU     H'0000'
DLYT1                  EQU     H'0001'
DLYT2                  EQU     H'0002'
DLYT3                  EQU     H'0003'
DLYT4                  EQU     H'0004'
DLYT5                  EQU     H'0005'
DLYT6                  EQU     H'0006'
DLYT7                  EQU     H'0007'


;-----------[T31C0L]----------------
T31EN                  EQU     H'0000'
UED                    EQU     H'0001'
UES                    EQU     H'0002'
SPME                   EQU     H'0003'
DIRS                   EQU     H'0004'
CMC0                   EQU     H'0005'
CMC1                   EQU     H'0006'
RLBE                   EQU     H'0007'


;-----------[T31C0H]----------------
DFCKS0                 EQU     H'0000'
DFCKS1                 EQU     H'0001'
;                      EQU     H'0002'
;                      EQU     H'0003'
;                      EQU     H'0004'
;                      EQU     H'0005'
HTOEOFF                EQU     H'0006'
T31PWMCKS              EQU     H'0007'


;-----------[T31C1L]----------------
CHCBE                  EQU     H'0000'
;                      EQU     H'0001'
CHCUS                  EQU     H'0002'
;                      EQU     H'0003'
ADTRGS0                EQU     H'0004'
ADTRGS1                EQU     H'0005'
ADTRGS2                EQU     H'0006'
;                      EQU     H'0007'


;-----------[T31C1H]----------------
ONS1                   EQU     H'0000'
ONS1N                  EQU     H'0001'
ONS2                   EQU     H'0002'
ONS2N                  EQU     H'0003'
ONS3                   EQU     H'0004'
ONS3N                  EQU     H'0005'
ONS4                   EQU     H'0006'
;                      EQU     H'0007'


;-----------[T31C2L]----------------
T31SM0                 EQU     H'0000'
T31SM1                 EQU     H'0001'
T31SM2                 EQU     H'0002'
COCE                   EQU     H'0003'
TRGS0                  EQU     H'0004'
TRGS1                  EQU     H'0005'
TRGS2                  EQU     H'0006'
;                      EQU     H'0007'


;-----------[T31C2H]----------------
ETFS0                  EQU     H'0000'
ETFS1                  EQU     H'0001'
ETFS2                  EQU     H'0002'
ETFS3                  EQU     H'0003'
ETPRS0                 EQU     H'0004'
ETPRS1                 EQU     H'0005'
ECM2E                  EQU     H'0006'
ETEG                   EQU     H'0007'


;-----------[T31IEL]----------------
UPIE                   EQU     H'0000'
MIE1                   EQU     H'0001'
MIE2                   EQU     H'0002'
MIE3                   EQU     H'0003'
MIE4                   EQU     H'0004'
CHUIE                  EQU     H'0005'
TRGIE                  EQU     H'0006'
BKIE                   EQU     H'0007'


;-----------[T31IEH]----------------
;                      EQU     H'0000'
OVIE1                  EQU     H'0001'
OVIE2                  EQU     H'0002'
OVIE3                  EQU     H'0003'
OVIE4                  EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[T31IDL]----------------
UPID                   EQU     H'0000'
MID1                   EQU     H'0001'
MID2                   EQU     H'0002'
MID3                   EQU     H'0003'
MID4                   EQU     H'0004'
CHUID                  EQU     H'0005'
TRGID                  EQU     H'0006'
BKID                   EQU     H'0007'


;-----------[T31IDH]----------------
;                      EQU     H'0000'
OVID1                  EQU     H'0001'
OVID2                  EQU     H'0002'
OVID3                  EQU     H'0003'
OVID4                  EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[T31IVSL]----------------
UPIS                   EQU     H'0000'
MIS1                   EQU     H'0001'
MIS2                   EQU     H'0002'
MIS3                   EQU     H'0003'
MIS4                   EQU     H'0004'
CHUIS                  EQU     H'0005'
TRGIS                  EQU     H'0006'
BKIS                   EQU     H'0007'


;-----------[T31IVSH]----------------
;                      EQU     H'0000'
OVIS1                  EQU     H'0001'
OVIS2                  EQU     H'0002'
OVIS3                  EQU     H'0003'
OVIS4                  EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[T31IFL]----------------
UPIF                   EQU     H'0000'
MIF1                   EQU     H'0001'
MIF2                   EQU     H'0002'
MIF3                   EQU     H'0003'
MIF4                   EQU     H'0004'
CHUIF                  EQU     H'0005'
TRGIF                  EQU     H'0006'
BKIF                   EQU     H'0007'


;-----------[T31IFH]----------------
;                      EQU     H'0000'
OVIF1                  EQU     H'0001'
OVIF2                  EQU     H'0002'
OVIF3                  EQU     H'0003'
OVIF4                  EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[T31IFML]----------------
UPIM                   EQU     H'0000'
MIM1                   EQU     H'0001'
MIM2                   EQU     H'0002'
MIM3                   EQU     H'0003'
MIM4                   EQU     H'0004'
CHUIM                  EQU     H'0005'
TRGIM                  EQU     H'0006'
BKIM                   EQU     H'0007'


;-----------[T31IFMH]----------------
;                      EQU     H'0000'
OVIM1                  EQU     H'0001'
OVIM2                  EQU     H'0002'
OVIM3                  EQU     H'0003'
OVIM4                  EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[T31ICRL]----------------
UPIC                   EQU     H'0000'
MIC1                   EQU     H'0001'
MIC2                   EQU     H'0002'
MIC3                   EQU     H'0003'
MIC4                   EQU     H'0004'
CHUIC                  EQU     H'0005'
TRGIC                  EQU     H'0006'
BKIC                   EQU     H'0007'


;-----------[T31ICRH]----------------
;                      EQU     H'0000'
OVIC1                  EQU     H'0001'
OVIC2                  EQU     H'0002'
OVIC3                  EQU     H'0003'
OVIC4                  EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[T31EVG]----------------
UPT                    EQU     H'0000'
CH1T                   EQU     H'0001'
CH2T                   EQU     H'0002'
CH3T                   EQU     H'0003'
CH4T                   EQU     H'0004'
CHUT                   EQU     H'0005'
TRGT                   EQU     H'0006'
BKT                    EQU     H'0007'


;-----------[T31CH1C]----------------
CH1IOS0                EQU     H'0000'
CH1IOS1                EQU     H'0001'
CH1OFE                 EQU     H'0002'
CH1OBE                 EQU     H'0003'
CH1OM0                 EQU     H'0004'
CH1OM1                 EQU     H'0005'
CH1OM2                 EQU     H'0006'
CH1COCE                EQU     H'0007'


;-----------[T31CH1C]----------------
;CH1IOS0                EQU     H'0000'
;CH1IOS1                EQU     H'0001'
CH1IM0                 EQU     H'0002'
CH1IM1                 EQU     H'0003'
CH1IFS0                EQU     H'0004'
CH1IFS1                EQU     H'0005'
CH1IFS2                EQU     H'0006'
CH1IFS3                EQU     H'0007'


;-----------[T31CH2C]----------------
CH2IOS0                EQU     H'0000'
CH2IOS1                EQU     H'0001'
CH2OFE                 EQU     H'0002'
CH2OBE                 EQU     H'0003'
CH2OM0                 EQU     H'0004'
CH2OM1                 EQU     H'0005'
CH2OM2                 EQU     H'0006'
CH2COCE                EQU     H'0007'


;-----------[T31CH2C]----------------
;CH2IOS0                EQU     H'0000'
;CH2IOS1                EQU     H'0001'
CH2IM0                 EQU     H'0002'
CH2IM1                 EQU     H'0003'
CH2IFS0                EQU     H'0004'
CH2IFS1                EQU     H'0005'
CH2IFS2                EQU     H'0006'
CH2IFS3                EQU     H'0007'


;-----------[T31CH3C]----------------
CH3IOS0                EQU     H'0000'
CH3IOS1                EQU     H'0001'
CH3OFE                 EQU     H'0002'
CH3OBE                 EQU     H'0003'
CH3OM0                 EQU     H'0004'
CH3OM1                 EQU     H'0005'
CH3OM2                 EQU     H'0006'
CH3COCE                EQU     H'0007'


;-----------[T31CH3C]----------------
;CH3IOS0                EQU     H'0000'
;CH3IOS1                EQU     H'0001'
CH3IM0                 EQU     H'0002'
CH3IM1                 EQU     H'0003'
CH3IFS0                EQU     H'0004'
CH3IFS1                EQU     H'0005'
CH3IFS2                EQU     H'0006'
CH3IFS3                EQU     H'0007'


;-----------[T31CH4C]----------------
CH4IOS0                EQU     H'0000'
CH4IOS1                EQU     H'0001'
CH4OFE                 EQU     H'0002'
CH4OBE                 EQU     H'0003'
CH4OM0                 EQU     H'0004'
CH4OM1                 EQU     H'0005'
CH4OM2                 EQU     H'0006'
CH4COCE                EQU     H'0007'


;-----------[T31CH4C]----------------
;CH4IOS0                EQU     H'0000'
;CH4IOS1                EQU     H'0001'
CH4IM0                 EQU     H'0002'
CH4IM1                 EQU     H'0003'
CH4IFS0                EQU     H'0004'
CH4IFS1                EQU     H'0005'
CH4IFS2                EQU     H'0006'
CH4IFS3                EQU     H'0007'


;-----------[T31PINCL]----------------
CH1E                   EQU     H'0000'
CH1P                   EQU     H'0001'
CH1NE                  EQU     H'0002'
CH1NP                  EQU     H'0003'
CH2E                   EQU     H'0004'
CH2P                   EQU     H'0005'
CH2NE                  EQU     H'0006'
CH2NP                  EQU     H'0007'


;-----------[T31PINCH]----------------
CH3E                   EQU     H'0000'
CH3P                   EQU     H'0001'
CH3NE                  EQU     H'0002'
CH3NP                  EQU     H'0003'
CH4E                   EQU     H'0004'
CH4P                   EQU     H'0005'
;                      EQU     H'0006'
CH4NP                  EQU     H'0007'


;-----------[T31CNTL]----------------
CNT0                   EQU     H'0000'
CNT1                   EQU     H'0001'
CNT2                   EQU     H'0002'
CNT3                   EQU     H'0003'
CNT4                   EQU     H'0004'
CNT5                   EQU     H'0005'
CNT6                   EQU     H'0006'
CNT7                   EQU     H'0007'


;-----------[T31CNTH]----------------
CNT8                   EQU     H'0000'
CNT9                   EQU     H'0001'
CNT10                  EQU     H'0002'
CNT11                  EQU     H'0003'
CNT12                  EQU     H'0004'
CNT13                  EQU     H'0005'
CNT14                  EQU     H'0006'
CNT15                  EQU     H'0007'


;-----------[T31PRSL]----------------
PRS0                   EQU     H'0000'
PRS1                   EQU     H'0001'
PRS2                   EQU     H'0002'
PRS3                   EQU     H'0003'
PRS4                   EQU     H'0004'
PRS5                   EQU     H'0005'
PRS6                   EQU     H'0006'
PRS7                   EQU     H'0007'


;-----------[T31PRSH]----------------
PRS8                   EQU     H'0000'
PRS9                   EQU     H'0001'
PRS10                  EQU     H'0002'
PRS11                  EQU     H'0003'
PRS12                  EQU     H'0004'
PRS13                  EQU     H'0005'
PRS14                  EQU     H'0006'
PRS15                  EQU     H'0007'


;-----------[T31CNTLDL]----------------
CNTLD0                 EQU     H'0000'
CNTLD1                 EQU     H'0001'
CNTLD2                 EQU     H'0002'
CNTLD3                 EQU     H'0003'
CNTLD4                 EQU     H'0004'
CNTLD5                 EQU     H'0005'
CNTLD6                 EQU     H'0006'
CNTLD7                 EQU     H'0007'


;-----------[T31CNTLDH]----------------
CNTLD8                 EQU     H'0000'
CNTLD9                 EQU     H'0001'
CNTLD10                EQU     H'0002'
CNTLD11                EQU     H'0003'
CNTLD12                EQU     H'0004'
CNTLD13                EQU     H'0005'
CNTLD14                EQU     H'0006'
CNTLD15                EQU     H'0007'


;-----------[T31POS]----------------
POS0                   EQU     H'0000'
POS1                   EQU     H'0001'
POS2                   EQU     H'0002'
POS3                   EQU     H'0003'
POS4                   EQU     H'0004'
POS5                   EQU     H'0005'
POS6                   EQU     H'0006'
POS7                   EQU     H'0007'


;-----------[T31CH1RL]----------------
CH1R0                  EQU     H'0000'
CH1R1                  EQU     H'0001'
CH1R2                  EQU     H'0002'
CH1R3                  EQU     H'0003'
CH1R4                  EQU     H'0004'
CH1R5                  EQU     H'0005'
CH1R6                  EQU     H'0006'
CH1R7                  EQU     H'0007'


;-----------[T31CH1RH]----------------
CH1R8                  EQU     H'0000'
CH1R9                  EQU     H'0001'
CH1R10                 EQU     H'0002'
CH1R11                 EQU     H'0003'
CH1R12                 EQU     H'0004'
CH1R13                 EQU     H'0005'
CH1R14                 EQU     H'0006'
CH1R15                 EQU     H'0007'


;-----------[T31CH2RL]----------------
CH2R0                  EQU     H'0000'
CH2R1                  EQU     H'0001'
CH2R2                  EQU     H'0002'
CH2R3                  EQU     H'0003'
CH2R4                  EQU     H'0004'
CH2R5                  EQU     H'0005'
CH2R6                  EQU     H'0006'
CH2R7                  EQU     H'0007'


;-----------[T31CH2RH]----------------
CH2R8                  EQU     H'0000'
CH2R9                  EQU     H'0001'
CH2R10                 EQU     H'0002'
CH2R11                 EQU     H'0003'
CH2R12                 EQU     H'0004'
CH2R13                 EQU     H'0005'
CH2R14                 EQU     H'0006'
CH2R15                 EQU     H'0007'


;-----------[T31CH3RL]----------------
CH3R0                  EQU     H'0000'
CH3R1                  EQU     H'0001'
CH3R2                  EQU     H'0002'
CH3R3                  EQU     H'0003'
CH3R4                  EQU     H'0004'
CH3R5                  EQU     H'0005'
CH3R6                  EQU     H'0006'
CH3R7                  EQU     H'0007'


;-----------[T31CH3RH]----------------
CH3R8                  EQU     H'0000'
CH3R9                  EQU     H'0001'
CH3R10                 EQU     H'0002'
CH3R11                 EQU     H'0003'
CH3R12                 EQU     H'0004'
CH3R13                 EQU     H'0005'
CH3R14                 EQU     H'0006'
CH3R15                 EQU     H'0007'


;-----------[T31CH4RL]----------------
CH4R0                  EQU     H'0000'
CH4R1                  EQU     H'0001'
CH4R2                  EQU     H'0002'
CH4R3                  EQU     H'0003'
CH4R4                  EQU     H'0004'
CH4R5                  EQU     H'0005'
CH4R6                  EQU     H'0006'
CH4R7                  EQU     H'0007'


;-----------[T31CH4RH]----------------
CH4R8                  EQU     H'0000'
CH4R9                  EQU     H'0001'
CH4R10                 EQU     H'0002'
CH4R11                 EQU     H'0003'
CH4R12                 EQU     H'0004'
CH4R13                 EQU     H'0005'
CH4R14                 EQU     H'0006'
CH4R15                 EQU     H'0007'


;-----------[T21OC]----------------
PT0EN0                 EQU     H'0000'
PT0EN1                 EQU     H'0001'
PT1EN                  EQU     H'0002'
T21OM22                EQU     H'0003'
PT2EN0                 EQU     H'0004'
PT2EN1                 EQU     H'0005'
PLLCKS                 EQU     H'0006'
T21TR                  EQU     H'0007'


;-----------[T21L]----------------
T210                   EQU     H'0000'
T211                   EQU     H'0001'
T212                   EQU     H'0002'
T213                   EQU     H'0003'
T214                   EQU     H'0004'
T215                   EQU     H'0005'
T216                   EQU     H'0006'
T217                   EQU     H'0007'


;-----------[T21H]----------------
T218                   EQU     H'0000'
T219                   EQU     H'0001'
T2110                  EQU     H'0002'
T2111                  EQU     H'0003'
T2112                  EQU     H'0004'
T2113                  EQU     H'0005'
T2114                  EQU     H'0006'
T2115                  EQU     H'0007'


;-----------[T21PL]----------------
T21P0                  EQU     H'0000'
T21P1                  EQU     H'0001'
T21P2                  EQU     H'0002'
T21P3                  EQU     H'0003'
T21P4                  EQU     H'0004'
T21P5                  EQU     H'0005'
T21P6                  EQU     H'0006'
T21P7                  EQU     H'0007'


;-----------[T21PH]----------------
T21P8                  EQU     H'0000'
T21P9                  EQU     H'0001'
T21P10                 EQU     H'0002'
T21P11                 EQU     H'0003'
T21P12                 EQU     H'0004'
T21P13                 EQU     H'0005'
T21P14                 EQU     H'0006'
T21P15                 EQU     H'0007'


;-----------[T21R0L]----------------
T21R00                 EQU     H'0000'
T21R01                 EQU     H'0001'
T21R02                 EQU     H'0002'
T21R03                 EQU     H'0003'
T21R04                 EQU     H'0004'
T21R05                 EQU     H'0005'
T21R06                 EQU     H'0006'
T21R07                 EQU     H'0007'


;-----------[T21R0H]----------------
T21R08                 EQU     H'0000'
T21R09                 EQU     H'0001'
T21R010                EQU     H'0002'
T21R011                EQU     H'0003'
T21R012                EQU     H'0004'
T21R013                EQU     H'0005'
T21R014                EQU     H'0006'
T21R015                EQU     H'0007'


;-----------[T21CL]----------------
CAP0S0                 EQU     H'0000'
CAP0S1                 EQU     H'0001'
CAP1S0                 EQU     H'0002'
CAP1S1                 EQU     H'0003'
T21M0                  EQU     H'0004'
T21M1                  EQU     H'0005'
T21M2                  EQU     H'0006'
T21M3                  EQU     H'0007'


;-----------[T21CM]----------------
T21PRS0                EQU     H'0000'
T21PRS1                EQU     H'0001'
T21PRS2                EQU     H'0002'
T21PRS3                EQU     H'0003'
T21OM21                EQU     H'0004'
T21OM20                EQU     H'0005'
CAP2S0                 EQU     H'0006'
CAP2S1                 EQU     H'0007'


;-----------[T21CH]----------------
T21POS0                EQU     H'0000'
T21POS1                EQU     H'0001'
T21POS2                EQU     H'0002'
T21POS3                EQU     H'0003'
T21POS4                EQU     H'0004'
T21POS5                EQU     H'0005'
T21POS6                EQU     H'0006'
T21EN                  EQU     H'0007'


;-----------[T21R1L]----------------
T21R10                 EQU     H'0000'
T21R11                 EQU     H'0001'
T21R12                 EQU     H'0002'
T21R13                 EQU     H'0003'
T21R14                 EQU     H'0004'
T21R15                 EQU     H'0005'
T21R16                 EQU     H'0006'
T21R17                 EQU     H'0007'


;-----------[T21R1H]----------------
T21R18                 EQU     H'0000'
T21R19                 EQU     H'0001'
T21R110                EQU     H'0002'
T21R111                EQU     H'0003'
T21R112                EQU     H'0004'
T21R113                EQU     H'0005'
T21R114                EQU     H'0006'
T21R115                EQU     H'0007'


;-----------[T21R2L]----------------
T21R20                 EQU     H'0000'
T21R21                 EQU     H'0001'
T21R22                 EQU     H'0002'
T21R23                 EQU     H'0003'
T21R24                 EQU     H'0004'
T21R25                 EQU     H'0005'
T21R26                 EQU     H'0006'
T21R27                 EQU     H'0007'


;-----------[T21R2H]----------------
T21R28                 EQU     H'0000'
T21R29                 EQU     H'0001'
T21R210                EQU     H'0002'
T21R211                EQU     H'0003'
T21R212                EQU     H'0004'
T21R213                EQU     H'0005'
T21R214                EQU     H'0006'
T21R215                EQU     H'0007'


;-----------[ADCCM]----------------
ADBITSEL0              EQU     H'0000'
ADBITSEL1              EQU     H'0001'
ADSMPS0                EQU     H'0002'
ADSMPS1                EQU     H'0003'
ADVREFPS0              EQU     H'0004'
ADVREFPS1              EQU     H'0005'
ADVREFNS               EQU     H'0006'
VREFSEL                EQU     H'0007'


;-----------[ADCRL]----------------
ADCRL0                 EQU     H'0000'
ADCRL1                 EQU     H'0001'
ADCRL2                 EQU     H'0002'
ADCRL3                 EQU     H'0003'
ADCRL4                 EQU     H'0004'
ADCRL5                 EQU     H'0005'
ADCRL6                 EQU     H'0006'
ADCRL7                 EQU     H'0007'


;-----------[ADCRH]----------------
ADCRH0                 EQU     H'0000'
ADCRH1                 EQU     H'0001'
ADCRH2                 EQU     H'0002'
ADCRH3                 EQU     H'0003'
ADCRH4                 EQU     H'0004'
ADCRH5                 EQU     H'0005'
ADCRH6                 EQU     H'0006'
ADCRH7                 EQU     H'0007'


;-----------[ADCCL]----------------
ADEN                   EQU     H'0000'
ADTRG                  EQU     H'0001'
SMPS                   EQU     H'0002'
SMPON                  EQU     H'0003'
ADCHS0                 EQU     H'0004'
ADCHS1                 EQU     H'0005'
ADCHS2                 EQU     H'0006'
ADCHS3                 EQU     H'0007'


;-----------[ADCCH]----------------
VREFEN                 EQU     H'0000'
VREF_CHOPEN             EQU     H'0001'
ADST0                  EQU     H'0002'
ADST1                  EQU     H'0003'
ADCKS0                 EQU     H'0004'
ADCKS1                 EQU     H'0005'
ADCKS2                 EQU     H'0006'
ADFM                   EQU     H'0007'


;-----------[ADCLTRL]----------------
ADCLTRL0               EQU     H'0000'
ADCLTRL1               EQU     H'0001'
ADCLTRL2               EQU     H'0002'
ADCLTRL3               EQU     H'0003'
ADCLTRL4               EQU     H'0004'
ADCLTRL5               EQU     H'0005'
ADCLTRL6               EQU     H'0006'
ADCLTRL7               EQU     H'0007'


;-----------[ADCLTRH]----------------
ADCLTRH0               EQU     H'0000'
ADCLTRH1               EQU     H'0001'
ADCLTRH2               EQU     H'0002'
ADCLTRH3               EQU     H'0003'
ADCLTRH4               EQU     H'0004'
ADCLTRH5               EQU     H'0005'
ADCLTRH6               EQU     H'0006'
ADCLTRH7               EQU     H'0007'


;-----------[ADCHTRL]----------------
ADCHTRL0               EQU     H'0000'
ADCHTRL1               EQU     H'0001'
ADCHTRL2               EQU     H'0002'
ADCHTRL3               EQU     H'0003'
ADCHTRL4               EQU     H'0004'
ADCHTRL5               EQU     H'0005'
ADCHTRL6               EQU     H'0006'
ADCHTRL7               EQU     H'0007'


;-----------[ADCHTRH]----------------
ADCHTRH0               EQU     H'0000'
ADCHTRH1               EQU     H'0001'
ADCHTRH2               EQU     H'0002'
ADCHTRH3               EQU     H'0003'
ADCHTRH4               EQU     H'0004'
ADCHTRH5               EQU     H'0005'
ADCHTRH6               EQU     H'0006'
ADCHTRH7               EQU     H'0007'


;-----------[IAD]----------------
;IAD0                   EQU     H'0000'
;IAD1                   EQU     H'0001'
;IAD2                   EQU     H'0002'
;IAD3                   EQU     H'0003'
;IAD4                   EQU     H'0004'
;IAD5                   EQU     H'0005'
;IAD6                   EQU     H'0006'
;IAD7                   EQU     H'0007'


;-----------[IAAL]----------------
;IAAL0                  EQU     H'0000'
;IAAL1                  EQU     H'0001'
;IAAL2                  EQU     H'0002'
;IAAL3                  EQU     H'0003'
;IAAL4                  EQU     H'0004'
;IAAL5                  EQU     H'0005'
;IAAL6                  EQU     H'0006'
;IAAL7                  EQU     H'0007'


;-----------[IAAH]----------------
;IAAH0                  EQU     H'0000'
;IAAH1                  EQU     H'0001'
;IAAH2                  EQU     H'0002'
;IAAH3                  EQU     H'0003'
;IAAH4                  EQU     H'0004'
;IAAH5                  EQU     H'0005'
;IAAH6                  EQU     H'0006'
;IAAH7                  EQU     H'0007'


;-----------[BKSR]----------------
;DBKSR0                 EQU     H'0000'
;DBKSR1                 EQU     H'0001'
;DBKSR2                 EQU     H'0002'
;                      EQU     H'0003'
;SBKSR                  EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[PSW]----------------
;C                      EQU     H'0000'
;DC                     EQU     H'0001'
;Z                      EQU     H'0002'
;OV                     EQU     H'0003'
;N                      EQU     H'0004'
;OF                     EQU     H'0005'
;UF                     EQU     H'0006'
;                      EQU     H'0007'


;-----------[AREG]----------------
;AREG0                  EQU     H'0000'
;AREG1                  EQU     H'0001'
;AREG2                  EQU     H'0002'
;AREG3                  EQU     H'0003'
;AREG4                  EQU     H'0004'
;AREG5                  EQU     H'0005'
;AREG6                  EQU     H'0006'
;AREG7                  EQU     H'0007'


;-----------[PCRL]----------------
;PCRL0                  EQU     H'0000'
;PCRL1                  EQU     H'0001'
;PCRL2                  EQU     H'0002'
;PCRL3                  EQU     H'0003'
;PCRL4                  EQU     H'0004'
;PCRL5                  EQU     H'0005'
;PCRL6                  EQU     H'0006'
;PCRL7                  EQU     H'0007'


;-----------[PCRH]----------------
;PCRH0                  EQU     H'0000'
;PCRH1                  EQU     H'0001'
;PCRH2                  EQU     H'0002'
;PCRH3                  EQU     H'0003'
;PCRH4                  EQU     H'0004'
;PCRH5                  EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[MULA]----------------
;MULA0                  EQU     H'0000'
;MULA1                  EQU     H'0001'
;MULA2                  EQU     H'0002'
;MULA3                  EQU     H'0003'
;MULA4                  EQU     H'0004'
;MULA5                  EQU     H'0005'
;MULA6                  EQU     H'0006'
;MULA7                  EQU     H'0007'


;-----------[MULL]----------------
;MULL0                  EQU     H'0000'
;MULL1                  EQU     H'0001'
;MULL2                  EQU     H'0002'
;MULL3                  EQU     H'0003'
;MULL4                  EQU     H'0004'
;MULL5                  EQU     H'0005'
;MULL6                  EQU     H'0006'
;MULL7                  EQU     H'0007'


;-----------[MULB]----------------
;MULB0                  EQU     H'0000'
;MULB1                  EQU     H'0001'
;MULB2                  EQU     H'0002'
;MULB3                  EQU     H'0003'
;MULB4                  EQU     H'0004'
;MULB5                  EQU     H'0005'
;MULB6                  EQU     H'0006'
;MULB7                  EQU     H'0007'


;-----------[MULH]----------------
;MULH0                  EQU     H'0000'
;MULH1                  EQU     H'0001'
;MULH2                  EQU     H'0002'
;MULH3                  EQU     H'0003'
;MULH4                  EQU     H'0004'
;MULH5                  EQU     H'0005'
;MULH6                  EQU     H'0006'
;MULH7                  EQU     H'0007'


;-----------[TMRADC]----------------
;TMRADC0                EQU     H'0000'
;TMRADC1                EQU     H'0001'
;TMRADC2                EQU     H'0002'
;TMRADC3                EQU     H'0003'
;TMRADC4                EQU     H'0004'
;TMRADC5                EQU     H'0005'
;TMRADC6                EQU     H'0006'
;TMRADC7                EQU     H'0007'


;-----------[BEEPC]----------------
;BEEPEN                 EQU     H'0000'
;                      EQU     H'0001'
;BEEP_OUTSEL0             EQU     H'0002'
;BEEP_OUTSEL1             EQU     H'0003'
;BEEPPRE0               EQU     H'0004'
;BEEPPRE1               EQU     H'0005'
;BEEPIOS0               EQU     H'0006'
;BEEPIOS1               EQU     H'0007'


;-----------[LVDC]----------------
;LVDV0                  EQU     H'0000'
;LVDV1                  EQU     H'0001'
;LVDV2                  EQU     H'0002'
;                      EQU     H'0003'
;LVDEN                  EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;LVDLS                  EQU     H'0007'


;-----------[ANSH]----------------
;                      EQU     H'0000'
;ANSH1                  EQU     H'0001'
;ANSH2                  EQU     H'0002'
;ANSH3                  EQU     H'0003'
;ANSH4                  EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[FRALN]----------------
;FRALN0                 EQU     H'0000'
;FRALN1                 EQU     H'0001'
;FRALN2                 EQU     H'0002'
;FRALN3                 EQU     H'0003'
;FRALN4                 EQU     H'0004'
;FRALN5                 EQU     H'0005'
;FRALN6                 EQU     H'0006'
;FRALN7                 EQU     H'0007'


;-----------[FRAHN]----------------
;FRAHN0                 EQU     H'0000'
;FRAHN1                 EQU     H'0001'
;FRAHN2                 EQU     H'0002'
;FRAHN3                 EQU     H'0003'
;FRAHN4                 EQU     H'0004'
;FRAHN5                 EQU     H'0005'
;FRAHN6                 EQU     H'0006'
;FRAHN7                 EQU     H'0007'


;-----------[FRAL]----------------
;FRAL0                  EQU     H'0000'
;FRAL1                  EQU     H'0001'
;FRAL2                  EQU     H'0002'
;FRAL3                  EQU     H'0003'
;FRAL4                  EQU     H'0004'
;FRAL5                  EQU     H'0005'
;FRAL6                  EQU     H'0006'
;FRAL7                  EQU     H'0007'


;-----------[FRAH]----------------
;FRAH0                  EQU     H'0000'
;FRAH1                  EQU     H'0001'
;FRAH2                  EQU     H'0002'
;FRAH3                  EQU     H'0003'
;FRAH4                  EQU     H'0004'
;FRAH5                  EQU     H'0005'
;FRAH6                  EQU     H'0006'
;FRAH7                  EQU     H'0007'


;-----------[ROMDL]----------------
;ROMDL0                 EQU     H'0000'
;ROMDL1                 EQU     H'0001'
;ROMDL2                 EQU     H'0002'
;ROMDL3                 EQU     H'0003'
;ROMDL4                 EQU     H'0004'
;ROMDL5                 EQU     H'0005'
;ROMDL6                 EQU     H'0006'
;ROMDL7                 EQU     H'0007'


;-----------[ROMDH]----------------
;ROMDH0                 EQU     H'0000'
;ROMDH1                 EQU     H'0001'
;ROMDH2                 EQU     H'0002'
;ROMDH3                 EQU     H'0003'
;ROMDH4                 EQU     H'0004'
;ROMDH5                 EQU     H'0005'
;ROMDH6                 EQU     H'0006'
;ROMDH7                 EQU     H'0007'


;-----------[ROMCL]----------------
;DATARDTRG              EQU     H'0000'
;WR                     EQU     H'0001'
;WREN                   EQU     H'0002'
;FPEE                   EQU     H'0003'
;                      EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;DATARDEN               EQU     H'0007'


;-----------[ROMCH]----------------
;ROMCH0                 EQU     H'0000'
;ROMCH1                 EQU     H'0001'
;ROMCH2                 EQU     H'0002'
;ROMCH3                 EQU     H'0003'
;ROMCH4                 EQU     H'0004'
;ROMCH5                 EQU     H'0005'
;ROMCH6                 EQU     H'0006'
;ROMCH7                 EQU     H'0007'


;-----------[INTG]----------------
;INTV0                  EQU     H'0000'
;INTV1                  EQU     H'0001'
;INTVEN0                EQU     H'0002'
;SOFTIF                 EQU     H'0003'
;                      EQU     H'0004'
;                      EQU     H'0005'
;GIEL                   EQU     H'0006'
;GIE                    EQU     H'0007'


;-----------[INTP]----------------
;IGP0                   EQU     H'0000'
;IGP1                   EQU     H'0001'
;IGP2                   EQU     H'0002'
;IGP3                   EQU     H'0003'
;IGP4                   EQU     H'0004'
;IGP5                   EQU     H'0005'
;IGP6                   EQU     H'0006'
;IGP7                   EQU     H'0007'


;-----------[INTC0]----------------
;PEG00                  EQU     H'0000'
;PEG01                  EQU     H'0001'
;PEG10                  EQU     H'0002'
;PEG11                  EQU     H'0003'
;PEG20                  EQU     H'0004'
;PEG21                  EQU     H'0005'
;PEG30                  EQU     H'0006'
;PEG31                  EQU     H'0007'


;-----------[INTE0]----------------
;ADIE                   EQU     H'0000'
;T8NIE                  EQU     H'0001'
;T31IE                  EQU     H'0002'
;PIE8                   EQU     H'0003'
;KIE                    EQU     H'0004'
;ADLTRIE                EQU     H'0005'
;ADHTRIE                EQU     H'0006'
;SPI_GIEIE              EQU     H'0007'


;-----------[INTF0]----------------
;ADIF                   EQU     H'0000'
;T8NIF                  EQU     H'0001'
;T31IF                  EQU     H'0002'
;PIF8                   EQU     H'0003'
;KIF                    EQU     H'0004'
;ADLTRIF                EQU     H'0005'
;ADHTRIF                EQU     H'0006'
;SPI_GIEIF              EQU     H'0007'


;-----------[INTE1]----------------
;PIE0                   EQU     H'0000'
;PIE1                   EQU     H'0001'
;PIE2                   EQU     H'0002'
;PIE3                   EQU     H'0003'
;PIE4                   EQU     H'0004'
;PIE5                   EQU     H'0005'
;PIE6                   EQU     H'0006'
;PIE7                   EQU     H'0007'


;-----------[INTF1]----------------
;PIF0                   EQU     H'0000'
;PIF1                   EQU     H'0001'
;PIF2                   EQU     H'0002'
;PIF3                   EQU     H'0003'
;PIF4                   EQU     H'0004'
;PIF5                   EQU     H'0005'
;PIF6                   EQU     H'0006'
;PIF7                   EQU     H'0007'


;-----------[INTE2]----------------
;TX0IE                  EQU     H'0000'
;RX0IE                  EQU     H'0001'
;T21VIE                 EQU     H'0002'
;T21PIE                 EQU     H'0003'
;T21MIE0                EQU     H'0004'
;T21MIE1                EQU     H'0005'
;I2CIE                  EQU     H'0006'
;T21MIE2                EQU     H'0007'


;-----------[INTF2]----------------
;TX0IF                  EQU     H'0000'
;RX0IF                  EQU     H'0001'
;T21VIF                 EQU     H'0002'
;T21PIF                 EQU     H'0003'
;T21MIF0                EQU     H'0004'
;T21MIF1                EQU     H'0005'
;I2CIF                  EQU     H'0006'
;T21MIF2                EQU     H'0007'


;-----------[INTE3]----------------
;TX1IE                  EQU     H'0000'
;RX1IE                  EQU     H'0001'
;T11VIE                 EQU     H'0002'
;T11PIE                 EQU     H'0003'
;                      EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;LVDIE                  EQU     H'0007'


;-----------[INTF3]----------------
;TX1IF                  EQU     H'0000'
;RX1IF                  EQU     H'0001'
;T11VIF                 EQU     H'0002'
;T11PIF                 EQU     H'0003'
;                      EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;LVDIF                  EQU     H'0007'


;-----------[ROMD1L]----------------
;ROMD1L0                EQU     H'0000'
;ROMD1L1                EQU     H'0001'
;ROMD1L2                EQU     H'0002'
;ROMD1L3                EQU     H'0003'
;ROMD1L4                EQU     H'0004'
;ROMD1L5                EQU     H'0005'
;ROMD1L6                EQU     H'0006'
;ROMD1L7                EQU     H'0007'


;-----------[ROMD1H]----------------
;ROMD1H0                EQU     H'0000'
;ROMD1H1                EQU     H'0001'
;ROMD1H2                EQU     H'0002'
;ROMD1H3                EQU     H'0003'
;ROMD1H4                EQU     H'0004'
;ROMD1H5                EQU     H'0005'
;ROMD1H6                EQU     H'0006'
;ROMD1H7                EQU     H'0007'


;-----------[KMSK]----------------
;KMSK0                  EQU     H'0000'
;KMSK1                  EQU     H'0001'
;KMSK2                  EQU     H'0002'
;KMSK3                  EQU     H'0003'
;KMSK4                  EQU     H'0004'
;KMSK5                  EQU     H'0005'
;KMSK6                  EQU     H'0006'
;KMSK7                  EQU     H'0007'


;-----------[WDTC]----------------
;WDTPRS0                EQU     H'0000'
;WDTPRS1                EQU     H'0001'
;WDTPRS2                EQU     H'0002'
;                      EQU     H'0003'
;WDTPRE                 EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[WDTP]----------------
;WDTP0                  EQU     H'0000'
;WDTP1                  EQU     H'0001'
;WDTP2                  EQU     H'0002'
;WDTP3                  EQU     H'0003'
;WDTP4                  EQU     H'0004'
;WDTP5                  EQU     H'0005'
;WDTP6                  EQU     H'0006'
;WDTP7                  EQU     H'0007'


;-----------[WKDC]----------------
;WKDC0                  EQU     H'0000'
;WKDC1                  EQU     H'0001'
;WKDC2                  EQU     H'0002'
;WKDC3                  EQU     H'0003'
;WKDC4                  EQU     H'0004'
;WKDC5                  EQU     H'0005'
;WKDC6                  EQU     H'0006'
;WKDC7                  EQU     H'0007'


;-----------[PWEN]----------------
;HALT_PWM               EQU     H'0000'
;                      EQU     H'0001'
;BORFLT0                EQU     H'0002'
;BORFLT1                EQU     H'0003'
;PORLOST                EQU     H'0004'
;MRSTF                  EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[PA]----------------
;PA0                    EQU     H'0000'
;PA1                    EQU     H'0001'
;PA2                    EQU     H'0002'
;PA3                    EQU     H'0003'
;PA4                    EQU     H'0004'
;PA5                    EQU     H'0005'
;PA6                    EQU     H'0006'
;PA7                    EQU     H'0007'


;-----------[PB]----------------
;PB0                    EQU     H'0000'
;PB1                    EQU     H'0001'
;PB2                    EQU     H'0002'
;PB3                    EQU     H'0003'
;PB4                    EQU     H'0004'
;PB5                    EQU     H'0005'
;PB6                    EQU     H'0006'
;PB7                    EQU     H'0007'


;-----------[PC]----------------
;PC0                    EQU     H'0000'
;PC1                    EQU     H'0001'
;                      EQU     H'0002'
;                      EQU     H'0003'
;                      EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[PAFLT]----------------
;PAFLT0                 EQU     H'0000'
;PAFLT1                 EQU     H'0001'
;PAFLT2                 EQU     H'0002'
;PAFLT3                 EQU     H'0003'
;PAFLT4                 EQU     H'0004'
;PAFLT5                 EQU     H'0005'
;PAFLT6                 EQU     H'0006'
;PAFLT7                 EQU     H'0007'


;-----------[PBFLT]----------------
;PBFLT0                 EQU     H'0000'
;PBFLT1                 EQU     H'0001'
;PBFLT2                 EQU     H'0002'
;PBFLT3                 EQU     H'0003'
;PBFLT4                 EQU     H'0004'
;PBFLT5                 EQU     H'0005'
;PBFLT6                 EQU     H'0006'
;PBFLT7                 EQU     H'0007'


;-----------[PAT]----------------
;PAT0                   EQU     H'0000'
;PAT1                   EQU     H'0001'
;PAT2                   EQU     H'0002'
;PAT3                   EQU     H'0003'
;PAT4                   EQU     H'0004'
;PAT5                   EQU     H'0005'
;PAT6                   EQU     H'0006'
;PAT7                   EQU     H'0007'


;-----------[PBT]----------------
;PBT0                   EQU     H'0000'
;PBT1                   EQU     H'0001'
;PBT2                   EQU     H'0002'
;PBT3                   EQU     H'0003'
;PBT4                   EQU     H'0004'
;PBT5                   EQU     H'0005'
;PBT6                   EQU     H'0006'
;PBT7                   EQU     H'0007'


;-----------[PCT]----------------
;PCT0                   EQU     H'0000'
;PCT1                   EQU     H'0001'
;                      EQU     H'0002'
;                      EQU     H'0003'
;                      EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[PAPD]----------------
;PAPD0                  EQU     H'0000'
;PAPD1                  EQU     H'0001'
;PAPD2                  EQU     H'0002'
;PAPD3                  EQU     H'0003'
;PAPD4                  EQU     H'0004'
;PAPD5                  EQU     H'0005'
;PAPD6                  EQU     H'0006'
;PAPD7                  EQU     H'0007'


;-----------[PBPD]----------------
;PBPD0                  EQU     H'0000'
;PBPD1                  EQU     H'0001'
;PBPD2                  EQU     H'0002'
;PBPD3                  EQU     H'0003'
;PBPD4                  EQU     H'0004'
;PBPD5                  EQU     H'0005'
;PBPD6                  EQU     H'0006'
;PBPD7                  EQU     H'0007'


;-----------[PAPU]----------------
;PAPU0                  EQU     H'0000'
;PAPU1                  EQU     H'0001'
;PAPU2                  EQU     H'0002'
;PAPU3                  EQU     H'0003'
;PAPU4                  EQU     H'0004'
;PAPU5                  EQU     H'0005'
;PAPU6                  EQU     H'0006'
;PAPU7                  EQU     H'0007'


;-----------[PBPU]----------------
;PBPU0                  EQU     H'0000'
;PBPU1                  EQU     H'0001'
;PBPU2                  EQU     H'0002'
;PBPU3                  EQU     H'0003'
;PBPU4                  EQU     H'0004'
;PBPU5                  EQU     H'0005'
;PBPU6                  EQU     H'0006'
;PBPU7                  EQU     H'0007'


;-----------[PCPU]----------------
;PCPU0                  EQU     H'0000'
;PCPU1                  EQU     H'0001'
;                      EQU     H'0002'
;                      EQU     H'0003'
;                      EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[PCFLT]----------------
;PCFLT0                 EQU     H'0000'
;PCFLT1                 EQU     H'0001'
;                      EQU     H'0002'
;                      EQU     H'0003'
;                      EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[PWRC]----------------
;N_BOR                  EQU     H'0000'
;N_POR                  EQU     H'0001'
;N_PD                   EQU     H'0002'
;N_TO                   EQU     H'0003'
;VRST0                  EQU     H'0004'
;VRST1                  EQU     H'0005'
;LPM0                   EQU     H'0006'
;LPM1                   EQU     H'0007'


;-----------[PACTR]----------------
;PA0DS                  EQU     H'0000'
;PA1DS                  EQU     H'0001'
;PA2DS                  EQU     H'0002'
;PA3DS                  EQU     H'0003'
;PA4DS                  EQU     H'0004'
;PA5DS                  EQU     H'0005'
;PA5OD                  EQU     H'0006'
;PASMTS                 EQU     H'0007'


;-----------[PBCTR]----------------
;PB0DS                  EQU     H'0000'
;PB1DS                  EQU     H'0001'
;PB2DS                  EQU     H'0002'
;PB3DS                  EQU     H'0003'
;                      EQU     H'0004'
;PB1OD                  EQU     H'0005'
;PB0OD                  EQU     H'0006'
;PBSMTS                 EQU     H'0007'


;-----------[PCCTR]----------------
;PC0DS                  EQU     H'0000'
;PC1DS                  EQU     H'0001'
;                      EQU     H'0002'
;                      EQU     H'0003'
;                      EQU     H'0004'
;I2C_SEL                EQU     H'0005'
;PC1OD                  EQU     H'0006'
;PCSMTS                 EQU     H'0007'


;-----------[ADCCFL]----------------
;                      EQU     H'0000'
;                      EQU     H'0001'
;                      EQU     H'0002'
;                      EQU     H'0003'
;T21ADEN                EQU     H'0004'
;ADC_LP_EN              EQU     H'0005'
;T21ADS                 EQU     H'0006'
;ADCVTTEN               EQU     H'0007'


;-----------[PORTCTR]----------------
;T21CH0NSEL             EQU     H'0000'
;T21CH2NSEL             EQU     H'0001'
;ADC_ETR0EN             EQU     H'0002'
;AD_ETR1EN              EQU     H'0003'
;T31CH3SEL              EQU     H'0004'
;T31CH4SEL              EQU     H'0005'
;T31CH3NSEL             EQU     H'0006'
;UART1SEL               EQU     H'0007'


;-----------[ANSL]----------------
;ANSL0                  EQU     H'0000'
;ANSL1                  EQU     H'0001'
;ANSL2                  EQU     H'0002'
;ANSL3                  EQU     H'0003'
;ANSL4                  EQU     H'0004'
;ANSL5                  EQU     H'0005'
;ANSL6                  EQU     H'0006'
;ANSL7                  EQU     H'0007'


;-----------[T8N]----------------
;T8N0                   EQU     H'0000'
;T8N1                   EQU     H'0001'
;T8N2                   EQU     H'0002'
;T8N3                   EQU     H'0003'
;T8N4                   EQU     H'0004'
;T8N5                   EQU     H'0005'
;T8N6                   EQU     H'0006'
;T8N7                   EQU     H'0007'


;-----------[T8NC]----------------
;T8NPRS0                EQU     H'0000'
;T8NPRS1                EQU     H'0001'
;T8NPRS2                EQU     H'0002'
;T8NPRE                 EQU     H'0003'
;T8NEG                  EQU     H'0004'
;T8NM                   EQU     H'0005'
;T8NCLK                 EQU     H'0006'
;T8NEN                  EQU     H'0007'


;-----------[T31CHBK]----------------
;PROTS0                 EQU     H'0000'
;PROTS1                 EQU     H'0001'
;NOFFS                  EQU     H'0002'
;ROFFS                  EQU     H'0003'
;BKE                    EQU     H'0004'
;BKPS                   EQU     H'0005'
;AROE                   EQU     H'0006'
;CHOE                   EQU     H'0007'


;-----------[SPICON0]----------------
TBIM0                  EQU     H'0000'
TBIM1                  EQU     H'0001'
RBIM0                  EQU     H'0002'
RBIM1                  EQU     H'0003'
CKS0                   EQU     H'0004'
CKS1                   EQU     H'0005'
TXCLR                  EQU     H'0006'
RXCLR                  EQU     H'0007'


;-----------[SPICON1]----------------
SPIEN                  EQU     H'0000'
SPIRST                 EQU     H'0001'
MS                     EQU     H'0002'
REN                    EQU     H'0003'
;                      EQU     H'0004'
DRE                    EQU     H'0005'
DFS0                   EQU     H'0006'
DFS1                   EQU     H'0007'


;-----------[SPIIE]----------------
TBIE                   EQU     H'0000'
RBIE                   EQU     H'0001'
TEIE                   EQU     H'0002'
ROIE                   EQU     H'0003'
IDIE                   EQU     H'0004'
NSSIE                  EQU     H'0005'
TBWEIE                 EQU     H'0006'
;                      EQU     H'0007'


;-----------[SPIIF]----------------
TBIF                   EQU     H'0000'
RBIF                   EQU     H'0001'
TEIF                   EQU     H'0002'
ROIF                   EQU     H'0003'
IDIF                   EQU     H'0004'
NSSIF                  EQU     H'0005'
TBWEIF                 EQU     H'0006'
;                      EQU     H'0007'


;-----------[SPIRBR]----------------
RBR0                   EQU     H'0000'
RBR1                   EQU     H'0001'
RBR2                   EQU     H'0002'
RBR3                   EQU     H'0003'
RBR4                   EQU     H'0004'
RBR5                   EQU     H'0005'
RBR6                   EQU     H'0006'
RBR7                   EQU     H'0007'


;-----------[SPITBW]----------------
TBW0                   EQU     H'0000'
TBW1                   EQU     H'0001'
TBW2                   EQU     H'0002'
TBW3                   EQU     H'0003'
TBW4                   EQU     H'0004'
TBW5                   EQU     H'0005'
TBW6                   EQU     H'0006'
TBW7                   EQU     H'0007'


;-----------[T11L]----------------
T110                   EQU     H'0000'
T111                   EQU     H'0001'
T112                   EQU     H'0002'
T113                   EQU     H'0003'
T114                   EQU     H'0004'
T115                   EQU     H'0005'
T116                   EQU     H'0006'
T117                   EQU     H'0007'


;-----------[T11H]----------------
T118                   EQU     H'0000'
T119                   EQU     H'0001'
T1110                  EQU     H'0002'
T1111                  EQU     H'0003'
T1112                  EQU     H'0004'
T1113                  EQU     H'0005'
T1114                  EQU     H'0006'
T1115                  EQU     H'0007'


;-----------[T11PL]----------------
T11P0                  EQU     H'0000'
T11P1                  EQU     H'0001'
T11P2                  EQU     H'0002'
T11P3                  EQU     H'0003'
T11P4                  EQU     H'0004'
T11P5                  EQU     H'0005'
T11P6                  EQU     H'0006'
T11P7                  EQU     H'0007'


;-----------[T11PH]----------------
T11P8                  EQU     H'0000'
T11P9                  EQU     H'0001'
T11P10                 EQU     H'0002'
T11P11                 EQU     H'0003'
T11P12                 EQU     H'0004'
T11P13                 EQU     H'0005'
T11P14                 EQU     H'0006'
T11P15                 EQU     H'0007'


;-----------[T11CL]----------------
;                      EQU     H'0000'
;                      EQU     H'0001'
;                      EQU     H'0002'
;                      EQU     H'0003'
T11M0                  EQU     H'0004'
T11M1                  EQU     H'0005'
T11M2                  EQU     H'0006'
T11M3                  EQU     H'0007'


;-----------[T11CM]----------------
T11PRS0                EQU     H'0000'
T11PRS1                EQU     H'0001'
T11PRS2                EQU     H'0002'
T11PRS3                EQU     H'0003'
;                      EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[T11CH]----------------
T11POS0                EQU     H'0000'
T11POS1                EQU     H'0001'
T11POS2                EQU     H'0002'
T11POS3                EQU     H'0003'
T11POS4                EQU     H'0004'
T11POS5                EQU     H'0005'
T11POS6                EQU     H'0006'
T11EN                  EQU     H'0007'


;-----------[BR0FRA]----------------
BR0FRA0                EQU     H'0000'
BR0FRA1                EQU     H'0001'
BR0FRA2                EQU     H'0002'
BR0FRA3                EQU     H'0003'
BR0FRA4                EQU     H'0004'
BR0FRA5                EQU     H'0005'
BR0FRA6                EQU     H'0006'
BR0FRA7                EQU     H'0007'


;-----------[BR1FRA]----------------
BR1FRA0                EQU     H'0000'
BR1FRA1                EQU     H'0001'
BR1FRA2                EQU     H'0002'
BR1FRA3                EQU     H'0003'
BR1FRA4                EQU     H'0004'
BR1FRA5                EQU     H'0005'
BR1FRA6                EQU     H'0006'
BR1FRA7                EQU     H'0007'


;-----------[RX0B]----------------
RX0B0                  EQU     H'0000'
RX0B1                  EQU     H'0001'
RX0B2                  EQU     H'0002'
RX0B3                  EQU     H'0003'
RX0B4                  EQU     H'0004'
RX0B5                  EQU     H'0005'
RX0B6                  EQU     H'0006'
RX0B7                  EQU     H'0007'


;-----------[RX0C]----------------
RX0R8                  EQU     H'0000'
FERR0                  EQU     H'0001'
OERR0                  EQU     H'0002'
RX0IOS                 EQU     H'0003'
RX2TXEN                EQU     H'0004'
BJTEN                  EQU     H'0005'
RX0LEN                 EQU     H'0006'
RX0EN                  EQU     H'0007'


;-----------[TX0B]----------------
TX0B0                  EQU     H'0000'
TX0B1                  EQU     H'0001'
TX0B2                  EQU     H'0002'
TX0B3                  EQU     H'0003'
TX0B4                  EQU     H'0004'
TX0B5                  EQU     H'0005'
TX0B6                  EQU     H'0006'
TX0B7                  EQU     H'0007'


;-----------[TX0C]----------------
TX0R8                  EQU     H'0000'
TRMT0                  EQU     H'0001'
;                      EQU     H'0002'
;                      EQU     H'0003'
;                      EQU     H'0004'
BRGH0                  EQU     H'0005'
TX0LEN                 EQU     H'0006'
TX0EN                  EQU     H'0007'


;-----------[BR0R]----------------
BR0R0                  EQU     H'0000'
BR0R1                  EQU     H'0001'
BR0R2                  EQU     H'0002'
BR0R3                  EQU     H'0003'
BR0R4                  EQU     H'0004'
BR0R5                  EQU     H'0005'
BR0R6                  EQU     H'0006'
BR0R7                  EQU     H'0007'


;-----------[RX1B]----------------
RX1B0                  EQU     H'0000'
RX1B1                  EQU     H'0001'
RX1B2                  EQU     H'0002'
RX1B3                  EQU     H'0003'
RX1B4                  EQU     H'0004'
RX1B5                  EQU     H'0005'
RX1B6                  EQU     H'0006'
RX1B7                  EQU     H'0007'


;-----------[RX1C]----------------
RX1R8                  EQU     H'0000'
FERR1                  EQU     H'0001'
OERR1                  EQU     H'0002'
RX1IOS                 EQU     H'0003'
;RX2TXEN                EQU     H'0004'
;BJTEN                  EQU     H'0005'
RX1LEN                 EQU     H'0006'
RX1EN                  EQU     H'0007'


;-----------[TX1B]----------------
TX1B0                  EQU     H'0000'
TX1B1                  EQU     H'0001'
TX1B2                  EQU     H'0002'
TX1B3                  EQU     H'0003'
TX1B4                  EQU     H'0004'
TX1B5                  EQU     H'0005'
TX1B6                  EQU     H'0006'
TX1B7                  EQU     H'0007'


;-----------[TX1C]----------------
TX1R8                  EQU     H'0000'
TRMT1                  EQU     H'0001'
;                      EQU     H'0002'
;                      EQU     H'0003'
;                      EQU     H'0004'
BRGH1                  EQU     H'0005'
TX1LEN                 EQU     H'0006'
TX1EN                  EQU     H'0007'


;-----------[BR1R]----------------
BR1R0                  EQU     H'0000'
BR1R1                  EQU     H'0001'
BR1R2                  EQU     H'0002'
BR1R3                  EQU     H'0003'
BR1R4                  EQU     H'0004'
BR1R5                  EQU     H'0005'
BR1R6                  EQU     H'0006'
BR1R7                  EQU     H'0007'


;-----------[I2CX16]----------------
I2CX160                EQU     H'0000'
I2CX161                EQU     H'0001'
I2CX162                EQU     H'0002'
I2CX163                EQU     H'0003'
I2CX164                EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[I2CC]----------------
I2CEN                  EQU     H'0000'
I2CRST                 EQU     H'0001'
I2CCSE                 EQU     H'0002'
I2CANAE                EQU     H'0003'
I2CTAS                 EQU     H'0004'
I2COD                  EQU     H'0005'
I2CPU                  EQU     H'0006'
I2CTE                  EQU     H'0007'


;-----------[I2CSA]----------------
I2CRW                  EQU     H'0000'
I2CSADR0               EQU     H'0001'
I2CSADR1               EQU     H'0002'
I2CSADR2               EQU     H'0003'
I2CSADR3               EQU     H'0004'
I2CSADR4               EQU     H'0005'
I2CSADR5               EQU     H'0006'
I2CSADR6               EQU     H'0007'


;-----------[I2CTB]----------------
I2CTB0                 EQU     H'0000'
I2CTB1                 EQU     H'0001'
I2CTB2                 EQU     H'0002'
I2CTB3                 EQU     H'0003'
I2CTB4                 EQU     H'0004'
I2CTB5                 EQU     H'0005'
I2CTB6                 EQU     H'0006'
I2CTB7                 EQU     H'0007'


;-----------[I2CRB]----------------
I2CRB0                 EQU     H'0000'
I2CRB1                 EQU     H'0001'
I2CRB2                 EQU     H'0002'
I2CRB3                 EQU     H'0003'
I2CRB4                 EQU     H'0004'
I2CRB5                 EQU     H'0005'
I2CRB6                 EQU     H'0006'
I2CRB7                 EQU     H'0007'


;-----------[I2CIEC]----------------
I2CSRIE                EQU     H'0000'
I2CSPIE                EQU     H'0001'
I2CTBIE                EQU     H'0002'
I2CRBIE                EQU     H'0003'
I2CTEIE                EQU     H'0004'
I2CROIE                EQU     H'0005'
I2CNAIE                EQU     H'0006'
;                      EQU     H'0007'


;-----------[I2CIFC]----------------
I2CSRIF                EQU     H'0000'
I2CSPIF                EQU     H'0001'
I2CTBIF                EQU     H'0002'
I2CRBIF                EQU     H'0003'
I2CTEIF                EQU     H'0004'
I2CROIF                EQU     H'0005'
I2CNAIF                EQU     H'0006'
;                      EQU     H'0007'


;-----------[CALPROT]----------------
;CALPROT                EQU     H'0000'
;                      EQU     H'0001'
;                      EQU     H'0002'
;                      EQU     H'0003'
;                      EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'


;-----------[VRTEST]----------------
;                      EQU     H'0000'
;                      EQU     H'0001'
SOFT_LP0               EQU     H'0002'
SOFT_LP1               EQU     H'0003'
SOFT_LP2               EQU     H'0004'
;                      EQU     H'0005'
;                      EQU     H'0006'
;                      EQU     H'0007'



