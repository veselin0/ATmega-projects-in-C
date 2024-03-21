/*
 * 328_2.c
 *
 * Created: 19/3/2024 7:55:34 p. m.
 * Author : Vesko
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/io.h>
#include <util/delay.h>

#define DLY 300
#define BUTTON_PIN PD2 // Define button pin (replace with actual pin)
#define LED_PIN PB0     // Define LED pin (replace with actual pin)

int main(void)
{
    // Set button pin as input
	DDRD &= ~(1 << BUTTON_PIN);  // Clear PD2 bit in Data Direction Register D
	// Enable internal pull-up resistor for button
	PORTD |= (1 << BUTTON_PIN);

	// Set LED pin as output
	DDRB |= (1 << LED_PIN);      // Set PB0 bit in Data Direction Register B

	
	
    while (1) 
    {
		// Read button state (active-low logic)
		uint8_t button_pressed = !(PIND & (1 << BUTTON_PIN));
		
		if (button_pressed)
		{
			// Turn on LED
			PORTB = 0b1111111;
			_delay_ms(DLY);
			// Turn off LED
			PORTB = 0b0000000;
			_delay_ms(DLY);
		} 
		else
		{
			//Turn off LED
			PORTB = 0b0000000;
		}
    }
}

