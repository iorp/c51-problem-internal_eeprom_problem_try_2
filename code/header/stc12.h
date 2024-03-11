/*--------------------------------------------------------------------------
REG51.H

Header file for generic 80C51 and 80C31 microcontroller.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __STC12_H__
#define __STC12_H__

//------------------------------------------------ --------------------------------
//New generation 1T 8051 series microcontroller core special function register C51 Core SFRs
// 7 6 5 4 3 2 1 0 Reset Value
sfr ACC = 0xE0; //Accumulator 0000,0000
sfr B = 0xF0; //B Register 0000,0000
sfr PSW = 0xD0; //Program Status Word CY AC F0 RS1 RS0 OV F1 P 0000,0000
//----------------------------------
sbit CY = PSW^7;
sbit AC = PSW^6;
sbit F0 = PSW^5;
sbit RS1 = PSW^4;
sbit RS0 = PSW^3;
sbit OV = PSW^2;
sbit P = PSW^0;
//----------------------------------
sfr SP = 0x81; //Stack Pointer 0000,0111
sfr DPL = 0x82; //Data Pointer Low Byte 0000,0000
sfr DPH = 0x83; //Data Pointer High Byte 0000,0000
//------------------------------------------------ --------------------------------
//New generation 1T 8051 series microcontroller system management special function register
// 7 6 5 4 3 2 1 0 Reset Value
sfr PCON = 0x87; //Power Control SMOD SMOD0 LVDF POF GF1 GF0 PD IDL 0001,0000
// 7 6 5 4 3 2 1 0 Reset Value
sfr AUXR = 0x8E; //Auxiliary Register T0x12 T1x12 UART_M0x6 BRTR S2SMOD BRTx12 EXTRAM S1BRS 0000,0000
//----------------------------------
sfr AUXR1 = 0xA2; //Auxiliary Register 1 - PCA_P4 SPI_P4 S2_P4 GF2 ADRJ - DPS 0000,0000
/*
PCA_P4:
     0, the default PCA is on the P1 port
     1. PCA/PWM switches from P1 port to P4 port: ECI switches from P1.2 to P4.1 port,
                                    PCA0/PWM0 switches from P1.3 to P4.2 port
                                    PCA1/PWM1 switches from P1.4 to P4.3 port
SPI_P4:
     0, the default SPI is on the P1 port
     1. SPI switches from P1 port to P4 port: SPICLK switches from P1.7 to P4.3 port
                                MISO switches from P1.6 to P4.2 port
                                MOSI switches from P1.5 to P4.1 port
                                SS switches from P1.4 to P4.0 port
S2_P4:
     0, the default UART2 is on the P1 port
     1. UART2 switches from P1 port to P4 port: TxD2 switches from P1.3 to P4.3 port
                                  RxD2 switches from P1.2 to P4.2 port
GF2: General flag bit

ADRJ:
     0, the upper 8 bits of the 10-bit A/D conversion result are placed in the ADC_RES register, and the lower 2 bits are placed in the ADC_RESL register
     1. The upper 2 bits of the 10-bit A/D conversion result are placed in the lower 2 bits of the ADC_RES register, and the lower 8 bits are placed in the ADC_RESL register.

DPS: 0, use default data pointer DPTR0
      1. Use another data pointer DPTR1
*/
//----------------------------------
sfr WAKE_CLKO = 0x8F; //Additional SFR WAK1_CLKO
/*
       7 6 5 4 3 2 1 0 Reset Value
    PCAWAKEUP RXD_PIN_IE T1_PIN_IE T0_PIN_IE LVD_WAKE _ T1CLKO T0CLKO 0000,0000B

b7 - PCAWAKEUP: PCA interrupt can wake up powerdown.
b6 - RXD_PIN_IE: When the falling edge of P3.0(RXD) sets RI, it can wake up powerdown (the corresponding interrupt must be turned on).
b5 - T1_PIN_IE: When the falling edge of T1 pin sets the T1 interrupt flag, it can wake up powerdown (the corresponding interrupt must be turned on).
b4 - T0_PIN_IE: When the falling edge of the T0 pin sets the T0 interrupt flag, it can wake up powerdown (the corresponding interrupt must be turned on).
b3 - LVD_WAKE: When the CMPIN pin low level sets the LVD interrupt flag, it can wake up powerdown (the corresponding interrupt must be turned on).
b2-
b1 - T1CLKO: Allow T1CKO (P3.5) pin to output T1 overflow pulse, Fck1 = 1/2 T1 overflow rate
b0 - T0CLKO: Allow T0CKO(P3.4) pin to output T0 overflow pulse, Fck0 = 1/2 T1 overflow rate
*/
//----------------------------------
sfr CLK_DIV = 0x97; //Clock Divder - - - - - CLKS2 CLKS1 CLKS0 xxxx,x000
//----------------------------------
sfr BUS_SPEED = 0xA1; //Stretch register - - ALES1 ALES0 - RWS2 RWS1 RWS0 xx10,x011
/*
ALES1 and ALES0:
00 : The P0 address setup time and hold time to ALE negative edge is one clock cycle
01 : The P0 address setup time and hold time to ALE negative edge are two clock cycles.
10: The P0 address setup time and hold time to ALE negative edge is three clock cycles. (default)
11: The P0 address setup time and hold time to ALE negative edge is four clock cycles.

RWS2,RWS1,RWS0:
   000 : The MOVX read/write pulse is 1 clock cycle.
   001 : The MOVX read/write pulse is 2 clock cycles.
   010 : The MOVX read/write pulse is 3 clock cycles.
   011 : The MOVX read/write pulse is 4 clock cycles. (default)
   100: The MOVX read/write pulse is 5 clock cycles.
   101 : The MOVX read/write pulse is 6 clock cycles.
   110 : The MOVX read/write pulse is 7 clock cycles.
   111 : The MOVX read/write pulse is 8 clock cycles.
*/
//------------------------------------------------ --------------------------------
//New generation 1T 8051 series microcontroller interrupt special function register
//Some interrupt control and interrupt flag bits are scattered in other special function registers. These bits are defined in the bit address
//Some of the bits do not have bit addressability, please refer to the new generation 1T 8051 series microcontroller Chinese guide
// 7 6 5 4 3 2 1 0 Reset Value
sfr IE = 0xA8; //Interrupt control register EA ELVD EADC ES ET1 EX1 ET0 EX0 0x00,0000
//----------------------
sbit EA = IE^7;
sbit ELVD = IE^6; //Low voltage monitoring interrupt enable bit
sbit EADC = IE^5; //ADC interrupt enable bit
sbit ES = IE^4;
sbit ET1 = IE^3;
sbit EX1 = IE^2;
sbit ET0 = IE^1;
sbit EX0 = IE^0;
//----------------------
sfr IE2 = 0xAF; //Auxiliary Interrupt - - - - - - ESPI ES2 0000,0000B
//----------------------
// 7 6 5 4 3 2 1 0 Reset Value
sfr IP = 0xB8; //Interrupt priority low bit PPCA PLVD PADC PS PT1 PX1 PT0 PX0 0000,0000
//--------
sbit PPCA = IP^7; //PCA module interrupt priority
sbit PLVD = IP^6; //Low voltage monitoring interrupt priority
sbit PADC = IP^5; //ADC interrupt priority
sbit PS = IP^4;
sbit PT1 = IP^3;
sbit PX1 = IP^2;
sbit PT0 = IP^1;
sbit PX0 = IP^0;
//----------------------
// 7 6 5 4 3 2 1 0 Reset Value
sfr IPH = 0xB7; //Interrupt priority high bit PPCAH PLVDH PADCH PSH PT1H PX1H PT0H PX0H 0000,0000
sfr IP2 = 0xB5; // - - - - - - PSPI PS2 xxxx,xx00
sfr IPH2 = 0xB6; // - - - - - - PSPIH PS2H xxxx,xx00
//----------------------
//New generation 1T 8051 series microcontroller I/O port special function register
// 7 6 5 4 3 2 1 0 Reset Value
sfr P0 = 0x80; //8 bitPort0 P0.7 P0.6 P0.5 P0.4 P0.3 P0.2 P0.1 P0.0 1111,1111
sfr P0M0 = 0x94; // 0000,0000
sfr P0M1 = 0x93; // 0000,0000
sfr P1 = 0x90; //8 bitPort1 P1.7 P1.6 P1.5 P1.4 P1.3 P1.2 P1.1 P1.0 1111,1111
sfr P1M0 = 0x92; // 0000,0000
sfr P1M1 = 0x91; // 0000,0000
sfr P1ASF = 0x9D; //P1 analog special function
sfr P2 = 0xA0; //8 bitPort2 P2.7 P2.6 P2.5 P2.4 P2.3 P2.2 P2.1 P2.0 1111,1111
sfr P2M0 = 0x96; // 0000,0000
sfr P2M1 = 0x95; // 0000,0000
sfr P3 = 0xB0; //8 bitPort3 P3.7 P3.6 P3.5 P3.4 P3.3 P3.2 P3.1 P3.0 1111,1111
sfr P3M0 = 0xB2; // 0000,0000
sfr P3M1 = 0xB1; // 0000,0000
sfr P4 = 0xC0; //8 bitPort4 P4.7 P4.6 P4.5 P4.4 P4.3 P4.2 P4.1 P4.0 1111,1111
sfr P4M0 = 0xB4; // 0000,0000
sfr P4M1 = 0xB3; // 0000,0000
// 7 6 5 4 3 2 1 0 Reset Value
sfr P4SW = 0xBB; //Port-4 switch - LVD_P4.6 ALE_P4.5 NA_P4.4 - - - - x000,xxxx

sfr P5 = 0xC8; //8 bitPort5 - - - - P5.3 P5.2 P5.1 P5.0 xxxx,1111
sfr P5M0 = 0xCA; // 0000,0000
sfr P5M1 = 0xC9; // 0000,0000
//------------------------------------------------ --------------------------------
//New generation 1T 8051 series microcontroller timer special function register
// 7 6 5 4 3 2 1 0 Reset Value
sfr TCON = 0x88; //T0/T1 Control TF1 TR1 TF0 TR0 IE1 IT1 IE0 IT0 0000,0000
//----------------------------------
sbit TF1 = TCON^7;
sbit TR1 = TCON^6;
sbit TF0 = TCON^5;
sbit TR0 = TCON^4;
sbit IE1 = TCON^3;
sbit IT1 = TCON^2;
sbit IE0 = TCON^1;
sbit IT0 = TCON^0;
//----------------------------------
sfr TMOD = 0x89; //T0/T1 Modes GATE1 C/T1 M1_1 M1_0 GATE0 C/T0 M0_1 M0_0 0000,0000
sfr TL0 = 0x8A; //T0 Low Byte 0000,0000
sfr TH0 = 0x8C; //T0 High Byte 0000,0000
sfr TL1 = 0x8B; //T1 Low Byte 0000,0000
sfr TH1 = 0x8D; //T1 High Byte 0000,0000
//------------------------------------------------ --------------------------------
//New generation 1T 8051 series microcontroller serial port special function register
// 7 6 5 4 3 2 1 0 Reset Value
sfr SCON = 0x98; //Serial Control SM0/FE SM1 SM2 REN TB8 RB8 TI RI 0000,0000
//----------------------------------
sbit SM0 = SCON^7; //SM0/FE
sbit SM1 = SCON^6;
sbit SM2 = SCON^5;
sbit REN = SCON^4;
sbit TB8 = SCON^3;
sbit RB8 = SCON^2;
sbit TI = SCON^1;
sbit RI = SCON^0;
//----------------------------------
sfr SBUF = 0x99; //Serial Data Buffer xxxx,xxxx
sfr SADEN = 0xB9; //Slave Address Mask 0000,0000
sfr SADDR = 0xA9; //Slave Address 0000,0000
//----------------------------------
// 7 6 5 4 3 2 1 0 Reset Value
sfr S2CON = 0x9A; //S2 Control S2SM0 S2SM1 S2SM2 S2REN S2TB8 S2RB8 S2TI S2RI 00000000B
sfr S2BUF = 0x9B; //S2 Serial Buffer xxxx,xxxx
sfr BRT = 0x9C; //S2 Baud-Rate Timer 0000,0000
//------------------------------------------------ --------------------------------
//New generation 1T 8051 series microcontroller watchdog timer special function register
sfr WDT_CONTR = 0xC1; //Watch-Dog-Timer Control register
// 7 6 5 4 3 2 1 0 Reset Value
// WDT_FLAG - EN_WDT CLR_WDT IDLE_WDT PS2 PS1 PS0 xx00,0000
//----------------------

//------------------------------------------------ --------------------------------
//New generation 1T 8051 series microcontroller PCA/PWM special function register
// 7 6 5 4 3 2 1 0 Reset Value
sfr CCON = 0xD8; //PCA control register. CF CR - - - - CCF1 CCF0 00xx,xx00
//----------------------
sbit CF = CCON^7; //PCA counter overflow flag, set by hardware or software, must be cleared by software.
sbit CR = CCON^6; //1: Allow PCA counter to count, must be cleared to 0 by software.
//-
//-
sbit CCF1 = CCON^1; //PCA module 1 interrupt flag, set by hardware, must be cleared by software.
sbit CCF0 = CCON^0; //PCA module 0 interrupt flag, set by hardware, must be cleared by software.
//----------------------
sfr CMOD = 0xD9; //PCA working mode register. CIDL - - - CPS2 CPS1 CPS0 ECF 0xxx,x000
/*
CIDL: Whether the PCA counter continues counting in idle state, 0: continue counting, 1: stop counting.

CPS2: PCA counter pulse source selection bit 2.
CPS1: PCA counter pulse source selection bit 1.
CPS0: PCA counter pulse source selection bit 0.
    CPS2 CPS1 CPS0
     0 0 0 System clock frequency fosc/12.
     0 0 1 System clock frequency fosc/2.
     0 1 0 Timer0 overflow.
     0 1 1 External clock input from ECI/P3.4 pin, maximum fosc/2.
     1 0 0 System clock frequency, Fosc/1
     1 0 1 System clock frequency/4, Fosc/4
     1 1 0 System clock frequency/6, Fosc/6
     1 1 1 System clock frequency/8, Fosc/8

ECF: PCA counter overflow interrupt enable bit, 1--allows CF(CCON.7) to generate an interrupt.
*/
//----------------------
sfr CL = 0xE9; //PCA counter low bit 0000,0000
sfr CH = 0xF9; //PCA counter high bit 0000,0000
//----------------------
// 7 6 5 4 3 2 1 0 Reset Value
sfr CCAPM0 = 0xDA; //PCA module 0 PWM register - ECOM0 CAPP0 CAPN0 MAT0 TOG0 PWM0 ECCF0 x000,0000
sfr CCAPM1 = 0xDB; //PCA module 1 PWM register - ECOM1 CAPP1 CAPN1 MAT1 TOG1 PWM1 ECCF1 x000,0000

//ECOMn = 1: Allow comparison function.
//CAPPn = 1: Allow rising edge trigger capture function.
//CAPNn = 1: Allow falling edge trigger capture function.
//MATn = 1: Allow CCFn in CCON to be set when a match occurs.
//TOGn = 1: When a match occurs, CEXn will flip.
//PWMn = 1: Set CEXn as PWM output.
//ECCFn = 1: Allow CCFn in CCON to trigger interrupts.

//ECOMn CAPPn CAPNn MATn TOGn PWMn ECCFn
// 0 0 0 0 0 0 0 0x00 No functionality is enabled.
// x 1 0 0 0 0 x 0x21 16-bit CEXn rising edge trigger capture function.
// x 0 1 0 0 0 x 0x11 16-bit CEXn falling edge trigger capture function.
// x 1 1 0 0 0 x 0x31 16-bit CEXn edge (upper and lower edge) trigger capture function.
// 1 0 0 1 0 0 x 0x49 16-bit software timer.
// 1 0 0 1 1 0 x 0x4d 16-bit high-speed pulse output.
// 1 0 0 0 0 1 0 0x42 8-bit PWM.

//ECOMn CAPPn CAPNn MATn TOGn PWMn ECCFn
// 0 0 0 0 0 0 0 0x00 No such operation
// 1 0 0 0 0 1 0 0x42 Normal 8-bit PWM, no interrupt
// 1 1 0 0 0 1 1 0x63 The PWM output changes from low to high to generate an interrupt.
// 1 0 1 0 0 1 1 0x53 PWM output changes from high to low to generate an interrupt
// 1 1 1 0 0 1 1 0x73 An interrupt can be generated when the PWM output changes from low to high or from high to low.

//----------------------
sfr CCAP0L = 0xEA; //The lower 8 bits of the capture/compare register of PCA module 0. 0000,0000
sfr CCAP0H = 0xFA; //The upper 8 bits of the capture/compare register of PCA module 0. 0000,0000
sfr CCAP1L = 0xEB; //The lower 8 bits of the capture/compare register of PCA module 1. 0000,0000
sfr CCAP1H = 0xFB; //The upper 8 bits of the capture/compare register of PCA module 1. 0000,0000
//----------------------
// 7 6 5 4 3 2 1 0 Reset Value
sfr PCA_PWM0 = 0xF2; //PCA module 0 PWM register. - - - - - - EPC0H EPC0L xxxx,xx00
sfr PCA_PWM1 = 0xF3; //PCA module 1 PWM register. - - - - - - EPC1H EPC1L xxxx,xx00
//PCA_PWMn: 7 6 5 4 3 2 1 0
// - - - - - - EPCnH EPCnL
//B7-B2: reserved
//B1(EPCnH): In PWM mode, combined with CCAPnH to form a 9-digit number.
//B0(EPCnL): In PWM mode, combined with CCAPnL to form a 9-digit number.
//------------------------------------------------ --------------------------------
//New generation 1T 8051 series microcontroller ADC special function register
// 7 6 5 4 3 2 1 0 Reset Value
sfr ADC_CONTR = 0xBC; //A/D conversion control register ADC_POWER SPEED1 SPEED0 ADC_FLAG ADC_START CHS2 CHS1 CHS0 0000,0000
sfr ADC_RES = 0xBD; //High 8 bits of A/D conversion result ADCV.9 ADCV.8 ADCV.7 ADCV.6 ADCV.5 ADCV.4 ADCV.3 ADCV.2 0000,0000
sfr ADC_RESL = 0xBE; //Lower 2 bits of A/D conversion result ADCV.1 ADCV.0 0000,0000
//------------------------------------------------ --------------------------------
//New generation 1T 8051 series microcontroller SPI special function register
// 7 6 5 4 3 2 1 0 Reset Value
sfr SPCTL = 0xCE; //SPI Control Register SSIG SPEN DORD MSTR CPOL CPHA SPR1 SPR0 0000,0100
sfr SPSTAT = 0xCD; //SPI Status Register SPIF WCOL - - - - - - 00xx,xxxx
sfr SPDAT = 0xCF; //SPI Data Register 0000,0000
//------------------------------------------------ --------------------------------
//New generation 1T 8051 series microcontroller IAP/ISP special function register
sfr IAP_DATA = 0xC2; //Flash data register
sfr IAP_ADDRH = 0xC3; //Flash address HIGH
sfr IAP_ADDRL = 0xC4; //Flash address LOW
sfr IAP_CMD = 0xC5; //Flash command register
sfr IAP_TRIG = 0xC6; //Flash command trigger
sfr IAP_CONTR = 0xC7; //Flash control register
//------------------------------------------------ --------------------------------



#endif