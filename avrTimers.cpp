/*
This file is to help the LED_Clock arduino file to control my
LED display I jacked from that sony clock
*/

#ifndef avrTimers_cpp
#define avrTimers_cpp

// INCLUDES
	#include "Arduino.h"

// Functions
void atMega2560_T3( int prescalar, int outCompareRegister){
		// Set the type of timer
		TCCR3A = 0x00; // Want bits 1:0 to be 00, they're WGM3 1:0, and everything else too
		// Set the prescalar
		// int clkSelBit;
		// switch (prescalar){ // get the prescalar values from the table 17-6 on p 157
		// 	case 8:
		// 		clkSelBit = 0b010;
		// 	case 64:
		// 		clkSelBit = 0b011;
		// 	case 256:
		// 		clkSelBit = 0b100;
		// 	case 1024:
		// 		clkSelBit = 0b101;
		// 	default: // if the user didn't enter 8, 64, 256, 1024, set default of 1
		// 		clkSelBit = 0b001;
		// 	}// switch
		// set prescalar and other settings
		TCCR3B = 0b1000 + (prescalar&0b111); // Bits 7:6 have to do with input capture, 5 is reserved, 4:3 are waveform generation
		// Bits 4:3 are WGM3 3:2, so we want them to be 0b01, b/c WGMn3:0 = 0b0100, table 17-2 page 145,
		//   because this is CTC mode which clears the counter once it gets to OCR3A
		// Bits 2:0 are the prescalar, coming from clkSelBit
		OCR3A = outCompareRegister; // Set the output compare register
		TIMSK3 = 0b0010; // bits 3:1 enable the output compare C:A respectively match interrupt, 0 is overflow
	}// atMega2560_T3

void atMega2560_T4( int prescalar, int outCompareRegister){
		// Set the type of timer
		TCCR4A = 0x00; // Want bits 1:0 to be 00, they're WGM3 1:0, and everything else too
		// Set the prescalar
		// int clkSelBit;
		// switch (prescalar){ // get the prescalar values from the table 17-6 on p 157
		// 	case 8:
		// 		clkSelBit = 0b010;
		// 	case 64:
		// 		clkSelBit = 0b011;
		// 	case 256:
		// 		clkSelBit = 0b100;
		// 	case 1024:
		// 		clkSelBit = 0b101;
		// 	default: // if the user didn't enter 8, 64, 256, 1024, set default of 1
		// 		clkSelBit = 0b001;
		// 	}// switch
		// set prescalar and other settings
		TCCR4B = 0b1000 + (prescalar&0b111); // Bits 7:6 have to do with input capture, 5 is reserved, 4:3 are waveform generation
		// Bits 4:3 are WGM3 3:2, so we want them to be 0b01, b/c WGMn3:0 = 0b0100, table 17-2 page 145,
		//   because this is CTC mode which clears the counter once it gets to OCR3A
		// Bits 2:0 are the prescalar, coming from clkSelBit
		OCR4A = outCompareRegister; // Set the output compare register
		TIMSK4 = 0b0010; // bits 3:1 enable the output compare C:A respectively match interrupt, 0 is overflow
	}// atMega2560_T4

void atMega328P_T1(int prescalar, int outCompareRegister){
		// Set the type of timer
		TCCR1A = 0x00; // Want bits 1:0 to be 00, they're WGM3 1:0, and everything else too
		// Set the prescalar
		// int clkSelBit;
		// switch (prescalar){ // get the prescalar values from the table 17-6 on p 157
		// 	case 8:
		// 		clkSelBit = 0b010;
		// 	case 64:
		// 		clkSelBit = 0b011;
		// 	case 256:
		// 		clkSelBit = 0b100;
		// 	case 1024:
		// 		clkSelBit = 0b101;
		// 	default: // if the user didn't enter 8, 64, 256, 1024, set default of 1
		// 		clkSelBit = 0b001;
		// 	}// switch
		// set prescalar and other settings
		TCCR1B = 0b1000 + (prescalar&0b111); // Bits 7:6 have to do with input capture, 5 is reserved, 4:3 are waveform generation
		// Bits 4:3 are WGM3 3:2, so we want them to be 0b01, b/c WGMn3:0 = 0b0100, table 20-6 page 171,
		//   because this is CTC mode which clears the counter once it gets to OCR3A
		// Bits 2:0 are the prescalar, coming from clkSelBit
		OCR1A = outCompareRegister; // set the output compare register
		TIMSK1 = 0b0010; // bits 3:1 enable the output compare C:A respectively match interrupt, 0 is overflow
	} // atMega328P_T1

#endif
