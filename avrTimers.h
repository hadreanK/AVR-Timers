					// INCLUDES and DEFINES
#ifndef avrTimers_h
#define avrTimers_h

					// NEW DATA TYPES

					// FUNCTION PROTOTYPES
void atMega2560_T3(int prescalar, int outCompareRegister);
	// To set the prescalar of the timer enter one of the following values.
	// If you enter a number not included, the function defaults to one.
	// Optional prescalars: 1, 8, 64, 256, 1024
	// The outCompareRegister is the number that the timer will count to 
	// before the ISR is run. T3 is a 16 bit timer.
	// For timer 3, using the following line of code to attach the ISR
	// ISR(TIMER3_COMPA_vect){ // put interrupt code here }

void atMega2560_T3(int prescalar, int outCompareRegister);
	// To set the prescalar of the timer enter one of the following values.
	// If you enter a number not included, the function defaults to one.
	// Optional prescalars: 1, 8, 64, 256, 1024
	// The outCompareRegister is the number that the timer will count to 
	// before the ISR is run. T4 is a 16 bit timer.
	// For timer 4, using the following line of code to attach the ISR
	// ISR(TIMER4_COMPA_vect){ // put interrupt code here }

void atMega328P_T1(int prescalar, int outCompareRegister);
	// NOTE: This timer can be run at 16 MHz or 8 Mhz, look at your hardware!
	// To set the prescalar of the timer enter one of the following values.
	// If you enter a number not included, the function defaults to one.
	// Optional prescalars: 1, 8, 64, 256, 1024
	// The outCompareRegister is the number that the timer will count to 
	// before the ISR is run. T1 is a 16 bit timer.
	// For timer 1, using the following line of code to attach the ISR
	// ISR(TIMER1_COMPA_vect){ // put interrupt code here }

#endif