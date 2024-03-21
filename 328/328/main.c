/*
 * 328.c
 *
 * Created: 18/3/2024 9:14:02 p. m.
 * Author : Vesko
 */ 

#define F_CPU 6000000UL
#include <avr/io.h>
#include <util/delay.h>
#define BLINC 1000
#define LED PORTC


int main(void)
{
    DDRC = 0b0000011;
    while (1) 
    {
		
		LED = 0b0000001;
		_delay_ms(BLINC);
		LED = 0b0000000;
		_delay_ms(BLINC);
		LED= 0b0000010;
		_delay_ms(BLINC);
		LED = 0b0000000;
		_delay_ms(BLINC);
    }
}

