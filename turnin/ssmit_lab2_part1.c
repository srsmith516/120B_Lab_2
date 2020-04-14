/*	Author: Samuel
 *  Partner(s) Name: Robert
 *	Lab Section:	027
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif	

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	//In this Exercise B0 represents a LED
	unsigned char tmpA0 = 0x00; // Temporary variable to hold the value of A0
	//In this Exercise A0 represents the door sensor of a garage door opener
	unsigned char tmpA1 = 0x00; //Temporary variable to hold the value of A1
	//In this Exercise A1 represents a light sensor
while(1) {
		// 1) Read input
		tmpA0 = PINA & 0x01;
		tmpA1 = PINA & 0x02;
		// 2) Perform computation - Garage door sensor
		if (tmpA0 == 0x01 && tmpA1 == 0x00  ) { // LED lights only if no light and
							// door open.
			tmpB = (tmpB & 0xFC) | 0x01; // Sets tmpB to bbbbbb01
						 // (clear rightmost 2 bits, then set to 01)
		}
		else {				// Otherwise the LED is not lit, tmpB = 0
			tmpB = (tmpB & 0xFC) | 0x00; // Sets tmpB to bbbbbb00
						 // (clear rightmost 2 bits, then set to 00)
		}	
	// 3) Write output
PORTB = tmpB;	
	}
	return 0;
}
