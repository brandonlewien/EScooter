/*
 * gpio.c
 *
 *  Created on: Oct 25, 2017
 * @author Brandon Lewien, Charles Van De Mark, Sam Zimmer
 */


#include <button1.h>
#include <gpio1.h>
#include <stdlib.h>

intHandler interruptHandlers[7][8];

void gpio_config() {
    NVIC_EnableIRQ(PORT1_IRQn);
    NVIC_EnableIRQ(PORT2_IRQn);
    NVIC_EnableIRQ(PORT3_IRQn);
    NVIC_EnableIRQ(PORT4_IRQn);
    NVIC_EnableIRQ(PORT5_IRQn);
    NVIC_SetPriority(PORT5_IRQn,1);
}

void gpio_LEDconfig() {
    P2->SEL0&=~BIT6&~BIT4;
    P2->SEL1&=~BIT6&~BIT4;
    P2->DIR|=BIT6|BIT4;
    P2->OUT&=~BIT6&~BIT4;

    P5->SEL0&=~BIT6;
    P5->SEL1&=~BIT6;
    P5->DIR|=BIT6;
    P5->OUT&=~BIT6;
}
void gpio_LEDout(uint8_t R, uint8_t G, uint8_t B) {
    if(R) P2->OUT|=BIT6;
    else P2->OUT&=~BIT6;

    if(G) P2->OUT|=BIT4;
    else P2->OUT&=~BIT4;

    if(B) P5->OUT|=BIT6;
    else P5->OUT&=~BIT6;
}

void gpio_registerInterrupt(uint8_t portNumber, uint8_t pin, intHandler function) {
    interruptHandlers[portNumber][pin]=function;
}

void PORT1_IRQHandler() {
    int i;
    for(i=0;i<8;i++) {
        if(P1->IFG&(1<<i)) {
            P1->IFG&=~(1<<i);
            if(interruptHandlers[1][i]!=0) interruptHandlers[1][i]();
        }
    }
}

void PORT2_IRQHandler() {
    int i;
    for(i=0;i<8;i++) {
        if(P2->IFG&(1<<i)) {
            P2->IFG&=~(1<<i);
            if(interruptHandlers[2][i]!=0) interruptHandlers[2][i]();
        }
    }
}

void PORT3_IRQHandler() {
    int i;
    for(i=0;i<8;i++) {
        if(P3->IFG&(1<<i)) {
            P3->IFG&=~(1<<i);
            if(interruptHandlers[3][i]!=0) interruptHandlers[3][i]();
        }
    }
}

void PORT4_IRQHandler() {
    int i;
    for(i=0;i<8;i++) {
        if(P4->IFG&(1<<i)) {
            P4->IFG&=~(1<<i);
            if(interruptHandlers[4][i]!=0) interruptHandlers[4][i]();
        }
    }
}

void PORT5_IRQHandler() {
    int i;
    for(i=0;i<8;i++) {
        if(P5->IFG&(1<<i)) {
            P5->IFG&=~(1<<i);
            if(interruptHandlers[5][i]!=0) interruptHandlers[5][i]();
        }
    }
}
