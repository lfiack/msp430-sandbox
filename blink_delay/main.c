#include <msp430g2553.h>

#define DELAY 10000

int main(void) {
	volatile unsigned long i;

	WDTCTL = WDTPW + WDTHOLD;	// Stop watchdog timer

	P1DIR |= 0x01;				// Set P1.0 to output direction
	P1DIR |= 0x40;				// Set P1.6 to output direction

	P1OUT = 0x01;				// Assert P1.0

	while (1) {
		P1OUT ^= 0x41;			// Toggle P1.0 and P1.6 using exclusive-OR

		for (i = 0 ; i < DELAY ; i++);
	}

	return 0;
}
