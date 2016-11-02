/* 
This file is to help the LED_Clock arduino file to control my 
LED display I jacked from that sony clock
*/

#ifndef akTimers_cpp
#define akTimers_cpp

// INCLUDES
	#include "Arduino.h"
	
// Functions
void atMega2560T3( int prescalar, int outCompareRegister){
		// Set the type of timer
		TCCR3A = 0x00; // Want bits 1:0 to be 00, they're WGM3 1:0, and everything else too
		// Set the prescalar
		int clkSelBit;
		switch (prescalar){ // get the prescalar values from the table 17-6 on p 157
			case 8:
				clkSelBit = 0b010;
			case 64:
				clkSelBit = 0b011;
			case 256:
				clkSelBit = 0b100;
			case 1024:
				clkSelBit = 0b101;
			default: // if the user didn't enter 8, 64, 256, 1024, set default of 1
				clkSelBit = 0b001;
			}// switch
		// set prescalar and other settings
		TCCR3B = 0x08 + clkSelBit; // Bits 7:6 have to do with input capture, 5 is reserved, 4:3 are waveform generation
		// Bits 4:3 are WGM3 3:2, so we want them to be 0b01, b/c WGMn3:0 = 0b0100, table 17-2 page 145,
		//   because this is CTC mode which clears the counter once it gets to OCR3A
		// Bits 2:0 are the prescalar, coming from clkSelBit
		OCR3A = 0x0271; // Want the output compare register to be 625 to get 100Hz
		// 16 MHz, 16e6/256 = 62500
		TIMSK3 = 0b0010; // bits 3:1 enable the output compare C:A respectively match interrupt, 0 is overflow
}// atMega2560T3
void atMega2560T4( int prescalar, int outCompareRegister){
		// Set the type of timer
		TCCR4A = 0x00; // Want bits 1:0 to be 00, they're WGM3 1:0, and everything else too
		// Set the prescalar
		int clkSelBit;
		switch (prescalar){ // get the prescalar values from the table 17-6 on p 157
			case 8:
				clkSelBit = 0b010;
			case 64:
				clkSelBit = 0b011;
			case 256:
				clkSelBit = 0b100;
			case 1024:
				clkSelBit = 0b101;
			default: // if the user didn't enter 8, 64, 256, 1024, set default of 1
				clkSelBit = 0b001;
			}// switch
		// set prescalar and other settings
		TCCR4B = 0x08 + clkSelBit; // Bits 7:6 have to do with input capture, 5 is reserved, 4:3 are waveform generation
		// Bits 4:3 are WGM3 3:2, so we want them to be 0b01, b/c WGMn3:0 = 0b0100, table 17-2 page 145,
		//   because this is CTC mode which clears the counter once it gets to OCR3A
		// Bits 2:0 are the prescalar, coming from clkSelBit
		OCR4A = 0x0271; // Want the output compare register to be 625 to get 100Hz
		// 16 MHz, 16e6/256 = 62500
		TIMSK4 = 0b0010; // bits 3:1 enable the output compare C:A respectively match interrupt, 0 is overflow
}// atMega2560T4
#endif
