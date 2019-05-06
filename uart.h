/*
 * uart.h
 *
 *  Created on: Sep 25, 2017
 *      Author: Brandon, Sam, Charles
 */
#include "msp.h"

#ifndef UART_H_
#define UART_H_

void uart_config(uint16_t buad);
void uart_write_byte(uint8_t data);
void uart_write_n(uint8_t * data, uint8_t size);

void uart_send(uint8_t byte);
void uart_print(uint8_t * bytes);
void uart_println(uint8_t * bytes);


/***BUFFER***/

typedef struct {
    volatile uint32_t num_items;
    volatile uint32_t capacity;
    volatile uint32_t head;
    volatile uint32_t tail;
    uint8_t * buffer;
} buffer;

buffer * buffer_initialize(uint32_t len);
int8_t buffer_clear(buffer * buf);
int8_t buffer_delete(buffer * buf);
int8_t buffer_isfull(buffer * buf);
int8_t buffer_isempty(buffer * buf);
int8_t buffer_length(buffer *buf);
int8_t buffer_add(buffer * buf, uint8_t item);
uint8_t buffer_get(buffer * buf);
uint32_t inc(uint32_t var, uint32_t cap);



#endif /* UART_H_ */
