/* 
 * File:   clock.h
 * Author: muaddib
 *
 * Created on November 3, 2019, 2:19 PM
 */

#ifndef CLOCK_H
#define	CLOCK_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <inttypes.h>
    
#define DS1307_ADDR 0x68
    
typedef struct __attribute__ ((packed))
{
    uint8_t seconds;
    uint8_t minutes;
    uint8_t hours;
} TTime;

typedef struct __attribute__ ((packed))
{
    uint8_t dayOfWeek;
    uint8_t day;
    uint8_t month;
    uint8_t year;
} TDate;

typedef struct __attribute__ ((packed))
{
    TTime time;
    TDate date;
    uint8_t controlRegister;
} TClock;

typedef struct __attribute__ ((packed))
{
    uint8_t addr;
    TClock data;
} TClockTWICont;

void clock_init(void);
void clock_getTime(TTime * time);

#ifdef	__cplusplus
}
#endif

#endif	/* CLOCK_H */

