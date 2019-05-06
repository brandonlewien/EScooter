/******************************************************************************
 * @Title: accel.c
 *
 * @author Brandon Lewien, Charles Van De Mark, Sam Zimmer
 * @date October 24, 2017
 * @version 1.0
 *
 * Compiled using CCSv7
 *
 *
 * Description:
 * This file contains functions that use the ADC library to read analog values
 * from the accelerometer and calculate the acceleration in m/s^2.
 * ***************************************************************************/

#include <gpio.h>
#include "accel.h"
#include "adc.h"
#include "msp.h"
#include "timer.h"
#include "encoder.h"

//x=6.1=A14
//y=4.0=A13
//z=4.2=A11

uint8_t _xchan,_ychan,_zchan;
volatile double _accel_velocity=0;

void _accel_int();


void accel_init(uint8_t xchan, uint8_t ychan, uint8_t zchan) {
    P6->SEL0|=BIT1;
    P6->SEL1|=BIT1;
    P4->SEL0|=BIT0|BIT4;
    P4->SEL1|=BIT0|BIT4;
    ADC_addChannel(xchan,14,0);
    ADC_addChannel(ychan,13,0);
    ADC_addChannel(zchan,11,0);
    _xchan=xchan;
    _ychan=ychan;
    _zchan=zchan;
    timerA0_set(2,753,(intHandler)&_accel_int);
}


double accel_x() {
    return 9.81*(ADC_getMV(_xchan)-1650)/660;
}


double accel_y() {
    return 9.81*(ADC_getMV(_ychan)-1650)/660;
}


double accel_z() {
    return 9.81*(ADC_getMV(_zchan)-1650)/660;
}

double accel_velocity() {
    return _accel_velocity;
}

double offset=.12;


void _accel_int() {
    _accel_velocity+=(-(accel_y()+offset)/1000);
    if(encoder_velocity()==0) _accel_velocity=0;
    if(_accel_velocity>0) {
        gpio_LEDout(0,1,0);
    }
    else {
        gpio_LEDout(0,0,1);
    }
}


