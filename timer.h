/*
 * timer.h
 *
 *  Created on: Sep 11, 2017
 *      Author: Brandon, Sam, Charles
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "gpio1.h"

void timerA0_config();
void timerA0_set(uint8_t i, uint32_t count, intHandler fn);
void timerA0_enable();
void timerA0_disable();


#endif /* TIMER_H_ */
