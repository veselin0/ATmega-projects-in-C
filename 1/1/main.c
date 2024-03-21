/*
 * main.c
 *
 * Created: 3/17/2024 5:48:56 PM
 *  Author: Vesko
 */ 

#include <xc.h>

int main(void)
{
	
	DDRC = 0b0000001;
	
    while(1)
    {
        PORTC = 0b0000001;
    }
}