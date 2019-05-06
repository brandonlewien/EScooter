#include <button1.h>
#include <gpio1.h>
#include <stdio.h>
#include "msp.h"
#include "clock.h"
#include "uart.h"
#include "encoder.h"
#include "adc.h"
#include "accel.h"
#include "timer.h"
#include "lcdconfig.h"

#define MS 753
volatile uint32_t counter=0;
volatile double dist=0;
volatile double velocity=0;
volatile char dir;
volatile int trigger=0;
void timer();

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	P1->DIR|=BIT0;
	clock_config();
	uart_config(19200);
	gpio_config();
	button_config();
	encoder_config();
	ADC_init();
	accel_init(1,2,3);
	ADC_EOS(3);
	ADC_start();
	timerA0_config();
	timerA0_set(0,MS,(intHandler)&timer);
	timerA0_enable();
    lcdconfig();
    getwordsback("eSCOOTER",64,5);
    getwordsback("Charles, Sam, Brandon",64,122);
    trigger=0;
	__enable_interrupt();

	while(1) {
	    if(trigger) {


	        uint8_t text[128];

	        dist=encoder_distance();
	        velocity=encoder_velocity();
	        dir=(70*(accel_velocity()>0))+(66*(accel_velocity()<0));

	        sprintf(text,"    Dir: %c    ",dir);
	        getwordsback(text,64,54);

	        sprintf(text,"   Spd: %2.5g   ",velocity);
	        getwordsback(text,64,64);

	        sprintf(text,"   Dist: %2.5g   ",dist);
	        getwordsback(text,64,74);

	        sprintf(text,"Distance: %2.3g m    Velocity: %2.5g m/s         ",dist,velocity);
	        uart_println(0x03);


	        trigger=0;
	    }
	}

}



void timer() {
    counter++;
    // EVERY 1 MS
    // EVERY 100 MS
    if(counter>99)
    {
        trigger=1;

        counter=0;
    }
}
