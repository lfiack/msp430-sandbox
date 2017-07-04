#include <msp430g2553.h>

int main(void) {
	WDTCTL = WDTPW + WDTHOLD;		// Stop watchdog timer

	DCOCTL = 

	CCTL0 = CCIE;					// CCR0 interrupt enabled
	TACTL = TASSEL_2 + MC_1 + ID_3;	// SMCLK/8, upmode
	CCR0 = 10000;					// 12.5 Hz

	P1DIR |= 0x01;					// Set P1.0 to output direction
	P1DIR |= 0x40;					// Set P1.6 to output direction

	P1OUT = 0x00;					// Clear P1

	_BIS_SR(CPUOFF + GIE);			// Enter LPM0 w/ interrupt 

	while (1) {
	}

	return 0;
}

// Timer A0 interrupt service routine 
#pragma vector=TIMER0_A0_VECTOR 
__interrupt void Timer_A (void) 
{   
	P1OUT ^= BIT0;					// Toggle P1.0 
} 
