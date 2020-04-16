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
	DDRC = 0xFF; PORTC = 0x00; // Configure prot C's 8 pins as outputs, initialize to 0s
	unsigned char cntavail;	   // Hold the number of spaces available -> PORTC
	unsigned char tempA0;
	unsigned char tempA1;
	unsigned char tempA2;
	unsigned char tempA3;
while(1) {
		cntavail = 0x00;
		tempA0 = PINA;
		tempA1 = PINA;
		tempA2 = PINA;
		tempA3 = PINA;
		tempA0 = tempA0 & 0x01;
		tempA1 = tempA1 & 0x02;
		tempA2 = tempA2 & 0x04;
		tempA3 = tempA3 & 0x08;		 
		if(tempA0 == 0) {cntavail = cntavail + 1;}
		if(tempA1 == 0) {cntavail = cntavail + 1;}
		if(tempA2 == 0) {cntavail = cntavail + 1;}
		if(tempA3 == 0) {cntavail = cntavail + 1;}
		if(cntavail == 0x04){cntavail = 0x84;}
PORTC = cntavail;	
	}
	return 0;
}
