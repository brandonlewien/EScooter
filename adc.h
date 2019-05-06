
#include "msp.h"
#include <stdint.h>

#ifndef ADC_H_
#define ADC_H_

void        ADC_init();
void        ADC_addChannel(uint8_t channel, uint8_t map, uint8_t vref);
uint16_t    ADC_getN(uint8_t channel);
double      ADC_getMV(uint8_t channel);
void        ADC_EOS(uint8_t channel);
void        ADC_start();


#endif /* ADC_H_ */
