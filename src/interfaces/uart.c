#include <avr/interrupt.h>
#include <avr/io.h>
#include "uart.h"
#include "ring_buffer.h"

#ifdef ATMEGA8
void uart_init(uint16_t speed)
{
    uint32_t speedReg = F_CPU/16/speed - 1;
    UBRRH = (uint8_t)((speedReg >> 8) & 0x000000ff);
    UBRRL = (uint8_t)(speedReg & 0x000000ff);
    
    UCSRB = (1 << RXEN) | (1 << TXEN);
    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}

void uart_send(uint8_t data)
{
    while(!(UCSRA & (1 << UDRE)));
    UDR = data;
}

void uart_send_string(char * str)
{
    char * pStr = str;
    while(*pStr)
    {
        uart_send(*pStr);
        pStr++;
    }
}

#endif

#ifdef ATMEGA328

volatile TRingBuffer uart_rx_ring_buffer;
volatile TRingBuffer uart_tx_ring_buffer;

ISR(USART_RX_vect)
{
   uint8_t data = UDR0;
   ringBuffer_pushBack(&uart_rx_ring_buffer, data);
}

ISR(USART_TX_vect)
{
    uint8_t data;
    if(uart_tx_ring_buffer.count)
    {
        ringBuffer_popFront(&uart_tx_ring_buffer, &data);
        UDR0 = data;
    }
}

void uart_init(uint16_t speed)
{
    uint32_t speedReg = F_CPU/16/speed - 1;
    UBRR0H = (uint8_t)((speedReg >> 8) & 0x000000ff);
    UBRR0L = (uint8_t)(speedReg & 0x000000ff);
    
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
    
    //extend settings
    sei(); //global interrupt enable
    UCSR0B |= (1 << RXCIE0) | (1 << TXCIE0); //enable interrupts
    ringBuffer_init(&uart_rx_ring_buffer);
    ringBuffer_init(&uart_tx_ring_buffer);
}

void uart_rb_send_bytes(uint8_t * buffer, uint8_t len)
{
    uint8_t data;
    for(uint8_t i = 0; i < len; i++)
    {
        ringBuffer_pushBack(&uart_tx_ring_buffer, buffer[i]);
    }
    ringBuffer_popFront(&uart_tx_ring_buffer, &data);
    uart_send(data);
}

void uart_rb_receive_bytes(uint8_t * buffer, uint8_t * len)
{
    * len = 0;
    while(uart_rx_ring_buffer.count)
    {
        ringBuffer_popFront(&uart_rx_ring_buffer, buffer);
        buffer++;
        (* len)++;
    }
}

void uart_send(uint8_t data)
{
    while(!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
}

void uart_send_string(char * str)
{
    char * pStr = str;
    while(*pStr)
    {
        uart_send(*pStr);
        pStr++;
    }
}

void uart_send_bytes(uint8_t * buffer, uint8_t len)
{
    for(uint8_t i = 0; i < len; i++)
    {
        uart_send(buffer[i]);
    }
}

uint8_t uart_receive(void)
{
    while (!(UCSR0A & (1<<RXC0)));
    return UDR0;
}

uint8_t uart_is_empty(void)
{
    return (UCSR0A & (1 << UDRE0));
}
#endif