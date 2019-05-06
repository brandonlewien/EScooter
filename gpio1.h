/*
 * gpio.h
 *
 *  Created on: Oct 25, 2017
 *      Author: Brandon, Sam, Charles
 */

#ifndef GPIO1_H_
#define GPIO1_H_

#include <stdint.h>
#include "msp.h"


typedef void (*intHandler)(void);

void gpio_config();

void gpio_registerInterrupt(uint8_t portNumber, uint8_t pin, intHandler function);

void gpio_LEDconfig();
void gpio_LEDout(uint8_t R, uint8_t G, uint8_t B);

#endif /* GPIO1_H_ */
