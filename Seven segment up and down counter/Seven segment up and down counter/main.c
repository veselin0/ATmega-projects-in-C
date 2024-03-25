/*
 * Seven segment up and down counter.c
 *
 * Created: 25/3/2024 3:58:34 p. m.
 * Author : Vesko
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include "util/delay.h"
#define DLY 300

int z = 0;

int count2 [10] = {
	0b00111111, //0
	0b00000110, //1
	0b01011011, //2
	0b01001111, //3
	0b01100110, //4
	0b01101101, //5
	0b01111101, //6
	0b00000111, //7
	0b01111111, //8
	0b01101111, //9
};

int count16 [10] = {
	0x3F, //0
	0x6, //1
	0x5B, //2
	0x4F, //3
	0x66, //4
	0x6D, //5
	0x7D, //6
	0x7, //7
	0x7F, //8
	0x6F, //9
};


int main(void)
{
	
	
    DDRD = 0b00000000;
	PORTD = 0b00000011;
	
	DDRC = 0b1111111;
	
	
	    while (1) 
    {
		
		//PORTC = count2 [z];
		if (PIND == 0b00000010)
		{
			PORTC = count2 [z];
			z++;
			_delay_ms(DLY);
			if(z > 9 ) z = 0;
		}
		
		//if (PINB == 0b00000010)
		//{
			//z--;
			//if (z < 0) z = 9;
		//}
		
    }
}

/*
PORTD = 0b00111111; //0
_delay_ms(DLY);
PORTD = 0b00000110; //1
_delay_ms(DLY);
PORTD = 0b01011011; //2
_delay_ms(DLY);
PORTD = 0b01001111; //3
_delay_ms(DLY);
PORTD = 0b01100110; //4
_delay_ms(DLY);
PORTD = 0b01101101; //5
_delay_ms(DLY);
PORTD = 0b01111101; //6
_delay_ms(DLY);
PORTD = 0b00000111; //7
_delay_ms(DLY);
PORTD = 0b01111111; //8
_delay_ms(DLY);
PORTD = 0b01101111; //9
_delay_ms(DLY);
PORTD = 0b10000000; //.
_delay_ms(DLY);
*/