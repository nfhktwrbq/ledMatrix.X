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

#define SECOND_UNITS_MAX    9
#define SECOND_TENS_MAX     5
#define MINUTE_UNITS_MAX    9
#define MINUTE_TENS_MAX    5
#define HOUR_UNITS_MAX    9
#define HOUR_TENS_MAX_24    2
#define HOUR_TENS_MAX_12    1
    
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

typedef enum
{
    SECOND_UNITS,
    SECOND_TENS,
    MINUTE_UNITS,
    MINUTE_TENS,
    HOUR_UNITS,
    HOUR_TENS,
} TIME_POS;

typedef enum
{
    TIME_FORMAT_12,
    TIME_FORMAT_24,
} TIME_FORMAT;

uint8_t clock_init(void);
void clock_setTime(TTime * time);
void clock_getTime(TTime * time);
void clock_changeTime(TTime * time, int8_t diff, TIME_FORMAT timeFormat, TIME_POS pos);

#ifdef	__cplusplus
}
#endif

#endif	/* CLOCK_H */

