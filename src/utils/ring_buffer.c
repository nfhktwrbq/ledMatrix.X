#include "ring_buffer.h"

void ringBuffer_init(volatile TRingBuffer * rb)
{
    rb->count = 0;
    rb->head = 0;
    rb->tail = 0;
}

void ringBuffer_pushBack(volatile TRingBuffer * rb, const uint8_t byte)
{
    if(rb->count == RING_BUFFER_SIZE)
        return; //overflow
    
    rb->buffer[rb->head] = byte;
    rb->head++;
    if(rb->head == RING_BUFFER_SIZE)
        rb->head = 0;
    rb->count++;
}

void ringBuffer_popFront(volatile TRingBuffer * rb, uint8_t * byte)
{
    if(rb->count == 0)
        return; //empty buffer
    
    * byte = rb->buffer[rb->tail];
    rb->tail++;
    if(rb->tail == RING_BUFFER_SIZE)
        rb->tail = 0;
    rb->count--;
}