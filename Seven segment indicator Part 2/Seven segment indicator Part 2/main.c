/*
 * Seven segment indicator Part 2.c
 *
 * Created: 24/3/2024 5:04:27 p. m.
 * Author : Vesko
 */ 

#include <avr/io.h>


int main(void)
{
    
	DDRD = 0b11111111;
	
    while (1) 
    {
		
		PORTD = 00000110;
    }
}

