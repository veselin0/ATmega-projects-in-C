/*
 * TestSevenFor.c
 *
 * Created: 27/3/2024 5:07:03 p. m.
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



int main(void)
{
    
    while (1) 
    {
		DDRD = 0b11111111;
		for (z = 0; z <= 9; z++)
		{
			_delay_ms(DLY);
			PORTD = count2 [z];
		}
		
		for (z = 9; z >= 0; z--)
		{
			_delay_ms(DLY);
			PORTD = count2 [z];
		}
		
    }
}

