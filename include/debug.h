/* 
 * File:   debug.h
 * Author: muaddib
 *
 * Created on October 31, 2019, 11:17 PM
 */

#ifndef DEBUG_H
#define	DEBUG_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <avr/io.h>
#include <inttypes.h>

void debug_init(uint16_t speed);    
void debug_send(uint8_t data);
void debug_send_string(char * str);    
    
#ifdef	__cplusplus
}
#endif

#endif	/* DEBUG_H */

