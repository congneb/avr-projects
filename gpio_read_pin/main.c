#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // Configure PB5 (Arduino pin 13, onboard LED) as output
    DDRB |= (1 << DDB5);

    // Configure PD2 (Arduino pin 2) as input with pull-up
    DDRD &= ~(1 << DDD2);   // input
    PORTD |= (1 << PORTD2); // enable pull-up

    while (1) {
        // Read button state
        if (PIND & (1 << PIND2)) {
            // Button not pressed (input HIGH due to pull-up)
            PORTB &= ~(1 << PORTB5); // LED OFF
        } else {
            // Button pressed (input LOW)
            PORTB |= (1 << PORTB5);  // LED ON
        }

        _delay_ms(50); // debounce delay
    }

    return 0;
}
