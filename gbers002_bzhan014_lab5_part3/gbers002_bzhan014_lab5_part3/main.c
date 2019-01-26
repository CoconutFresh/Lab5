

#include <avr/io.h>
enum States{start,set, hold}state;
unsigned char button = 0x00;
unsigned char led = 0x15;
unsigned char temp = 0x00;

void tick() {
	switch(state) { //transition
		case start:
			state = set;
			break;
		case set:
			if (button == 0x01) {
				state = hold;
			}
			break;
		case hold:
			if (button == 0x01) {
				state = hold;
			}
			else {
				temp = 0x01;
				state = set;
			}
			break;
	}
	switch (state) { //state action
		case set:
			if (button == 0x00 && temp == 0x01) {
				led = ~led;
				temp = 0x00;
			}
			PORTB = led;
			break;
	}
}
int main(void)
{
    DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
    while (1) 
    {
		button = (~PINA & 0x01);
		tick();
    }
}

