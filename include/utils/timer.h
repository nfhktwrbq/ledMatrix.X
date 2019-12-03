/* 
 * File:   timer.h
 * Author: muaddib
 *
 * Created on November 4, 2019, 8:39 PM
 */

#ifndef TIMER_H
#define	TIMER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <inttypes.h>
#include <stdbool.h>
    
typedef struct __attribute__ ((packed))
{
    uint32_t start;
    uint32_t timeout;
    bool isActive;
} TTimer;

void timer0_init(void);
void timer1_init(void);
void timer_start(TTimer * timer, uint32_t timeout);
bool timer_check(TTimer * timer);
void timer_stop(TTimer * timer);
void timer_restart(TTimer * timer);

#ifdef	__cplusplus
}
#endif

#endif	/* TIMER_H */

