#include <avr/io.h>
void Delay(void);
int main(void)
{
	DDRB = 0b0000001; // set bit 0 of DDR register which makes PB0 an output
	while(1)
	{
		PORTB = 0b0000001; // switch LED on
		Delay();
		PORTB = 0b0000000; // switch LED off
		Delay();
	}
}
void Delay(void)
{
	volatile unsigned long count = 100000;
	while (count--);
}
