// Write code in C for ATmega328P: When a button is pressed an LED  is lighted


#define F_CPU 16000000UL // Crystal oscillator frequency (16 MHz)
#include <avr/io.h>
#include <util/delay.h>

#define BUTTON_PIN PD2  // Define button pin (replace with actual pin)
#define LED_PIN PB0     // Define LED pin (replace with actual pin)

int main(void) {
	// Set button pin as input
	DDRD &= ~(1 << BUTTON_PIN);  // Clear PD2 bit in Data Direction Register D

	// (Optional) Enable internal pull-up resistor for button 
	 PORTD |= (1 << BUTTON_PIN);

	// Set LED pin as output
	DDRB |= (1 << LED_PIN);      // Set PB0 bit in Data Direction Register B

	while (1) {
		// Read button state (active-low logic)
		uint8_t button_pressed = !(PIND & (1 << BUTTON_PIN));

		if (button_pressed) {
			// Turn on LED
			PORTB |= (1 << LED_PIN);  // Set PB0 bit in Port B

			// (Optional) Debounce (add a short delay to avoid flickering)
			_delay_ms(10);  // Delay for 10 milliseconds

			// Turn off LED (optional for a toggle behavior)
			 //PORTB &= ~(1 << LED_PIN);
			} else {
			// Turn off LED (optional for a toggle behavior)
			 PORTB &= ~(1 << LED_PIN);
		}
	}

	return 0; // Not strictly necessary for microcontrollers
}


