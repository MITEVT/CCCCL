#include <avr/io.h>

#define OUTPUT PB4 //Pin 3

//100kHz
uint8_t overflow = 159;
uint8_t pwm = 0;

void initIO(void) {
	//Set output pin
	DDRB |= (1 << OUTPUT);
}

void initTimer(void) {
	//Set Compare mode to clear on match, set on $00
	TCCR1 |= (1 << COM1A1) | (1 << CTC1) | (1 << PWM1A);
	//Set to PCK/4 Prescaling
	TCCR1 |= (1 << CS11) | (1 << CS10);
	//PLL Control and status
	PLLCSR |= (1 << PCKE) | (1 << PLLE);
	//When to "overflow"
	OCR1C = overflow;
	//When to clear
	OCR1B = pwm;

}

void init(void) {
	initIO();
	initTimer();
}

void run(void) {
	while(1) {

	}
}

//Give a value from 0 to 100
void setPulseWidth(uint8_t i) {
	pwm = (uint8_t)(overflow * i/100);
}

int main (void){
	init();

	//Set PulseWidth here:
	setPulseWidth(50);

	run();

	return 0;
}


