/*
 * encoder.c
 *
 *  Created on: Oct 30, 2017
 *      Author: Brandon, Charles, Sam
 */

#include <gpio1.h>
#include "encoder.h"
#include "timer.h"

#define ENCODER_H_DIST (0.02236071428)

void _distance_int();
void _velocity_int();
volatile int _spokes1=0;
volatile int _spokes2=0;
volatile double _velocity=0;

void encoder_config() {
    P5->SEL0&=~BIT1;
    P5->SEL1&=~BIT1;
    P5->DIR&=~BIT1;
    P5->REN&=~BIT1;
    P5->IES|=BIT1;
    P5->IE|=BIT1;
    gpio_registerInterrupt(5,1,(intHandler)&_distance_int);
    timerA0_set(1,753,(intHandler)&_velocity_int);
}

double encoder_distance() {
    return _spokes1*ENCODER_H_DIST;
}
double encoder_velocity() {
    return _velocity;
}

void _distance_int() {
    _spokes1++;
    _spokes2++;
    P1->OUT^=BIT0;
}

volatile int counter1=0;
void _velocity_int() {
    counter1++;
    if(counter1>200) {
        _velocity = ((double)_spokes2 * (ENCODER_H_DIST))/.10;
        _spokes2=0;
        counter1=0;
        //P1->OUT^=BIT0;
    }
}
