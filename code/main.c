#include "header/stc12.h"
#include <intrins.h>
#include "uart.h"
 
 
 
// Define the EEPROM base address
#define EEPROM_BASE_ADDRESS 0x0000

// Function to write a byte to EEPROM
void EEPROM_writeByte(unsigned int address, unsigned char byteToWrite) {
    EA = 0; // Disable interrupts during write operation
    IAP_CONTR = 0x82; // Enable IAP and set programming time

    IAP_DATA = byteToWrite; // Load data to be written
    IAP_ADDRH = (address >> 8) & 0xFF; // Load high byte of address
    IAP_ADDRL = address & 0xFF; // Load low byte of address

    IAP_CMD = 0x02; // Command to erase and write one byte
    IAP_TRIG = 0x5A; // Trigger IAP
   _nop_();// Wait for IAP to complete

    EA = 1; // Re-enable interrupts
}

// Function to read a byte from EEPROM
unsigned char EEPROM_readByte(unsigned int address) {
    unsigned char readData;

    EA = 0; // Disable interrupts during read operation
    IAP_CONTR = 0x80; // Enable IAP

    IAP_ADDRH = (address >> 8) & 0xFF; // Load high byte of address
    IAP_ADDRL = address & 0xFF; // Load low byte of address

    IAP_CMD = 0x01; // Command to read one byte
    IAP_TRIG = 0x5A; // Trigger IAP

     
        _nop_();// Wait for IAP to complete
     

    readData = IAP_DATA; // Read the data from EEPROM

    EA = 1; // Re-enable interrupts

    return readData;
}




 

void main() {
	 

    unsigned char byteToWrite = 0xAA;
    
    UART_init(9600);
    
    UART_printStr("Hello, this is working with one byte ... \r"); 
    // Write a byte to EEPROM
    EEPROM_writeByte(0, 0xAA); 
    // Read the byte from EEPROM 
    UART_printHex(EEPROM_readByte(0),1);// Print readed

 


	
	    UART_printStr("\r... but not with 2 \r"); 
    // Write a byte to EEPROM
    EEPROM_writeByte(1, 0xBB); 
		_nop_(); // no matter how long I wait here 
    EEPROM_writeByte(2, 0xCC); 
    // Read the byte from EEPROM 
    UART_printHex(EEPROM_readByte(1),1);// Print readed
		_nop_(); // no matter how long I wait here
    UART_printHex(EEPROM_readByte(2),1);// Print readed
	

    while(1) {
        // Main loop, do nothing
    }
}



 