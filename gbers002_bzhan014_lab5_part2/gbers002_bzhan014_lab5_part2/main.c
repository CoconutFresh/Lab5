
#include <avr/io.h>
enum States {Start, Init, Inc, Dec, Hold, Reset}state;
unsigned char led = 0x00;
unsigned char button = 0x00;
void tick(){
	button = (~PINA & 0x03);
	//Transitions
	switch(state){
		case Start:
		{
			state = Init;
			break;
		}
		
		case Init:
		if(button == 0x01)
		{
			state = Inc;
			break;
		}
		else if(button == 0x02)
		{
			state = Dec;
			break;
		}
		else if(button == 0x03)
		{
			state = Reset;
			break;
		}
		else
		{
			state = Init;
			break;
		}
		
		case Inc:
		state = Hold;
		break;
		
		case Dec:
		state = Hold;
		break;
		
		case Hold:
		if((button == 0x01) || (button == 0x02))
		{
			state = Hold;
			break;
		}
		else if(button == 0x03)
		{
			state = Reset;
			break;
		}
		else
		{
			state = Init;
			break;
		}
		
		case Reset:
		if((button == 0x01) || (button == 0x02))
		{
			state = Reset;
			break;
		}
		else
		{
			state = Init;
			break;
		}
		
		default:
		break;
	}
	switch(state){ //State actions
		case Start:
		led = 0x00;
		PORTB = led;
		break;
		
		case Init:
		break;
		
		case Inc:
		if(led < 0x09)
		{
			led += 0x01;
			PORTB = led;
			break;
		}
		break;
		
		case Dec:
		if(led > 0x00)
		{
			led -= 0x01;
			PORTB = led;
			break;
		}
		break;
		
		case Hold:
		break;
		
		case Reset:
		led = 0x00;
		PORTB = led;
		break;
		default:
		break;
	}
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	state = Start;
	while(1)
	{
		tick();
	}
}
