/*
 * button.c
 *
 *  Created on: Oct 30, 2017
 *      Author: Brandon, Charles, Sam
 */

#include <button1.h>
#include <gpio1.h>


void button_config() {
    // RGB LED
    gpio_LEDconfig();
/*
    // Top Button
    P5->SEL0&=~BIT1;
    P5->SEL1&=~BIT1;
    P5->DIR&=~BIT1;
    P5->REN|=BIT1;
    P5->OUT|=BIT1;
    P5->IES|=BIT1;
    P5->IE|=BIT1;
    gpio_registerInterrupt(5,1,(intHandler)&button_topPress);
*/
    // Bottom Button
    P3->SEL0&=~BIT5;
    P3->SEL1&=~BIT5;
    P3->DIR&=~BIT5;
    P3->REN|=BIT5;
    P3->OUT|=BIT5;
    P3->IES|=BIT5;
    P3->IE|=BIT5;
    gpio_registerInterrupt(3,5,(intHandler)&button_bottomPress);

}

void button_topPress() {
    gpio_LEDout(0,0,0);
}
void button_bottomPress() {
    gpio_LEDout(1,1,1);
}
