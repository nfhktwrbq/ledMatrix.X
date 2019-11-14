/* 
 * File:   uart.h
 * Author: muaddib
 *
 * Created on November 4, 2019, 3:52 PM
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <avr/io.h>
#include <inttypes.h>   
    
void uart_init(uint16_t speed);    
void uart_send(uint8_t data);
void uart_send_string(char * str);   
void uart_send_bytes(uint8_t * buffer, uint8_t len);
uint8_t uart_receive(void);
uint8_t uart_is_empty(void);
void uart_rb_receive_bytes(uint8_t * buffer, uint8_t * len);
void uart_rb_send_bytes(uint8_t * buffer, uint8_t len);

#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

