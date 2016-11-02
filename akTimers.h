					// INCLUDES and DEFINES
#ifndef akTimers_h
#define akTimers_h

					// NEW DATA TYPES

					// FUNCTION PROTOTYPES
void atMega2560T3(int prescalar, int outCompareRegister);
	// To set the prescalar of the timer enter one of the following values.
	// If you enter a number not included, the function defaults to one.
	// Optional prescalars: 1, 8, 64, 256, 1024
	// The outCompareRegister is the number that the timer will count to 
	// before the ISR is run
	// For timer 3, using the following line of code to attach the ISR
	// ISR(TIMER3_COMPA_vect){ // put interrupt code here }

void atMega2560T3(int prescalar, int outCompareRegister);
	// To set the prescalar of the timer enter one of the following values.
	// If you enter a number not included, the function defaults to one.
	// Optional prescalars: 1, 8, 64, 256, 1024
	// The outCompareRegister is the number that the timer will count to 
	// before the ISR is run
	// For timer 4, using the following line of code to attach the ISR
	// ISR(TIMER4_COMPA_vect){ // put interrupt code here }

#endif