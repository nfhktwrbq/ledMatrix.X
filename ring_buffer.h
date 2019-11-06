/* 
 * File:   ring_buffer.h
 * Author: muaddib
 *
 * Created on November 4, 2019, 6:46 PM
 */

#ifndef RING_BUFFER_H
#define	RING_BUFFER_H

#ifdef	__cplusplus
extern "C" {
#endif
  
#include <inttypes.h>
    
#define RING_BUFFER_SIZE 32

typedef struct __attribute__ ((packed))
{
    uint8_t buffer[RING_BUFFER_SIZE];     // data buffer
    uint8_t count;     // number of items in the buffer
    uint8_t head;       // pointer to head
    uint8_t tail;       // pointer to tail
} TRingBuffer;

void ringBuffer_init(volatile TRingBuffer * rb);
void ringBuffer_pushBack(volatile TRingBuffer * rb, const uint8_t byte);
void ringBuffer_popFront(volatile TRingBuffer * rb, uint8_t * byte);

#ifdef	__cplusplus
}
#endif

#endif	/* RING_BUFFER_H */

