/*
 * LED garland on microcontroller.c
 *
 * Created: 23/3/2024 3:45:39 p. m.
 * Author : Vesko
 */ 

#define F_CPU 16000000UL // Crystal oscillator frequency (16 MHz)
#include <avr/io.h>
#include <util/delay.h>

#define BUTTON PORTD  
#define LED  PORTC   
#define DELAY 300

int main(void) {
	
	DDRD = 0b00000000;
	DDRC = 0b1111111;
	
	LED = 0b0000000;
	BUTTON = 0b11111111;
	
	while (1) 
	{
		if (PIND == 0b11111110)
		{
			LED = 0b11111111;
			_delay_ms(DELAY);
			LED = 0b00000000;
			_delay_ms(DELAY);
		}
		else 
		{
			LED = 0b00000000;
		}
		
		if (PIND == 0b11111101)
		{
			LED = 0b00000001;
			_delay_ms(DELAY);
			LED = 0b00000011;
			_delay_ms(DELAY);
			LED = 0b00000111;
			_delay_ms(DELAY);
			LED = 0b00001111;
			_delay_ms(DELAY);
			LED = 0b00011111;
			_delay_ms(DELAY);
			LED = 0b00000000;
			_delay_ms(DELAY);
		} 
		else
		{
			LED = 0b00000000;
		}
		
		
	}

	return 0; // Not strictly necessary for microcontrollers
}

