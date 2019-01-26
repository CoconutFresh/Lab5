/*	Glenn Bersabe Email: Gbers002@ucr.edu
 *  Bohan Zhang Email: Bzhan014@ucr.edu
 *	Lab Section: 023
 *	Assignment: Lab 3  Exercise 2
 *	Exercise Description: 
 *	
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */

#include <avr/io.h>

unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	unsigned char button = 0x00;
	unsigned char led = 0x00;
    while (1) 
    {
		led = 0x00;
		button = (~PINA & 0x0F);
			if (button >= 13) {
				led = (led | 0x3F);
			}
			if (button >= 10) {
				led = (led | 0x0E);
			}
			if (button >= 7) {
				led = (led | 0x3C);
			}
			if (button >= 5) {
				led = (led | 0x38);
			}
			if (button < 4) {
				led = (led | 0x40);
			}
			if (button <= 4 && button >= 3) {
				led = (led | 0x70);
			}
			if (button <= 2 && button >= 1) {
				led = (led | 0x60);
			}
			
			PORTB = led;
	}
}

//#include <avr/io.h>
//
//int main(void)
//{
	//DDRA = 0x00; PORTA = 0xFF; // Configure PORTA as input, initialize to 1s
	//DDRB = 0xFF; PORTB = 0x00; // Configure PORTB as outputs, initialize to 0s
	//unsigned char led = 0x00;
	//unsigned char button = 0x00;
	//while(1)
	//{
		//// if PA0 is 1, set PB1PB0=01, else =10
		//// 1) Read inputs
		//button = ~PINA & 0x01; // button is connected to A0
		//// 2) Perform Computation
		//if (button) { // True if button is pressed
			//led = (led & 0xFC) | 0x01; // Sets B to bbbbbb01
			//// (clear rightmost 2 bits, then set to 01)
		//}
		//else {
			//led = (led & 0xFC) | 0x02; // Sets B to bbbbbb10
			//// (clear rightmost 2 bits, then set to 10)
		//}
		//// 3) Write output
		//PORTB = led;
	//}
//}
