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
	DDRB = 0xFF; PORTC = 0x00; // Configure prot C's 8 pins as outputs, initialize to 0s
	unsigned char cntavail;	   // Hold the number of spaces available -> PORTC
	unsigned char temp;	   // Hold a pin from PINA[3:0]
	//In this Exercise A1 represents a light sensor
while(1) {
		// 1) & 2) - Read & Compute
		cntavail = 0x00; 		//Initialize counter to zero
			//For each space PINA[3:0]
			//	1) Set temp with & mask
			//	2) Check if temp is zero - space is empty 
		temp = PINA & 0x01;
		if(temp == 0x00) {cntavail = cntavail + 1;}
		temp = PINA & 0x02;
		if(temp == 0x00) {cntavail = cntavail + 1;}
		temp = PINA & 0x04;
		if(temp == 0x00) {cntavail = cntavail + 1;}
		temp = PINA & 0x08;
		if(temp == 0x00) {cntavail = cntavail + 1;}
	// 3) Write output
PORTC = cntavail;	
	}
	return 0;
}
