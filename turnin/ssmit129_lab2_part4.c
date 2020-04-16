/*	Author: Samuel
 *  Partner(s) Name: ** 
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
	DDRA = 0x00; PORTA = 0xFF; 
	DDRB = 0x00; PORTA = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
	unsigned char sum = 0;
	unsigned char dif = 0;
	unsigned char x = 0;
	unsigned char y = 0;
while(1) {
	sum = PINA;
	sum = sum + PINB;
	sum = sum + PINC;
	if(sum > 140) { y = 0x01; }
	dif = PINA;
	dif = dif - PINC;
	if(dif > 80 || dif < -80) { y = y + 0x02; }
	x = sum << 2;
	x = x & 0xFC;
	x = x + y;
	PORTD = x;
	}
	return 0;
}
