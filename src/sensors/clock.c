#include <string.h>

#include "clock.h"
#include "twi.h"
#include "debug.h"


static void getDataReg(TClock * clk)
{
    TClockTWICont clockCont;
    clockCont.data.time.seconds = 0;
    clockCont.addr = (DS1307_ADDR << 1) | 0; 
    
    TWI_SendData((uint8_t *)&clockCont, 2);
    
    clockCont.addr = (DS1307_ADDR << 1) | 1;
    TWI_SendData((uint8_t *)&clockCont, sizeof(clockCont));
    
    TWI_GetData((uint8_t *)&clockCont, sizeof(clockCont));
    
    memcpy(clk, &(clockCont.data), sizeof(TClock));
}

static void setDataReg(TClock * clk)
{
    TClockTWICont clockCont;
    clockCont.addr = (DS1307_ADDR << 1) | 0; 
    clockCont.data.time.seconds = 0; //reset pointer
    TWI_SendData((uint8_t *)&clockCont, 2);
    
    memcpy(&clockCont.data, clk, sizeof(TClock));    
    TWI_SendData((uint8_t *)&clockCont, sizeof(TClockTWICont));
}

uint8_t clock_init(void)
{
   TClock clk;
    getDataReg(&clk);
    if(clk.time.seconds & 0x80)
    {
        clk.time.seconds &= ~0x80;
        setDataReg(&clk);
    }
    return TWI_GetState();
}

uint8_t clock_getTime(TTime * time)
{
    TClock clk;
    getDataReg(&clk);
    memcpy(time, &clk.time, sizeof(TTime));
    return TWI_GetState();
}

uint8_t clock_setTime(TTime * time)
{
    TClock clk;
    getDataReg(&clk);
    memcpy(&clk.time, time, sizeof(TTime));
    setDataReg(&clk);
    return TWI_GetState();
}

static uint8_t digitChange(uint8_t digit, int8_t diff, uint8_t digitMax)
{
    int8_t tmp;
    tmp = (digit + diff) % (digitMax + 1);
    if(tmp < 0)
        tmp = (digitMax + 1) + tmp;
    return (uint8_t) tmp;
}

void clock_changeTime(TTime * time, int8_t diff, TIME_FORMAT timeFormat, TIME_POS pos)
{
    switch(pos)
    {
        case SECOND_UNITS:
            time->seconds = (time->seconds & 0xf0) + digitChange(time->seconds & 0x0f, diff, SECOND_UNITS_MAX);
        break;
        case SECOND_TENS:
            time->seconds = (time->seconds & 0x0f) + (digitChange(time->seconds >> 4, diff, SECOND_TENS_MAX) << 4);
        break;
        case MINUTE_UNITS:
            time->minutes = (time->minutes & 0xf0) + digitChange(time->minutes & 0x0f, diff, MINUTE_UNITS_MAX);
        break;
        case MINUTE_TENS:
            time->minutes = (time->minutes & 0x0f) + (digitChange(time->minutes >> 4, diff, MINUTE_TENS_MAX ) << 4);
        break;
        case HOUR_UNITS:
            time->hours = (time->hours & 0xf0) + digitChange(time->hours & 0x0f, diff, HOUR_UNITS_MAX);
            if(timeFormat == TIME_FORMAT_24)
            {
                if((time->hours & 0x0f) > 4 && (time->hours >> 4) == 2)
                {
                    time->hours &= 0x0f;      
                }
            }
            if(timeFormat == TIME_FORMAT_12)
            {
                if((time->hours & 0x0f) > 2 && (time->hours >> 4) == 1)
                {
                    time->hours &= 0x0f;      
                }
            }
        break;
        case HOUR_TENS:
            if(timeFormat == TIME_FORMAT_24)
            {
                time->hours = (time->hours & 0x0f) + (digitChange(time->hours >> 4, diff, HOUR_TENS_MAX_24 ) << 4);if((time->hours >> 4) == 2 && (time->hours & 0x0f) > 4)
                {
                    time->hours &= 0xf0;  
                }
            }
            if(timeFormat == TIME_FORMAT_12)
            {
                time->hours = (time->hours & 0x0f) + (digitChange(time->hours >> 4, diff, HOUR_TENS_MAX_12 ) << 4);
                if((time->hours >> 4) == 1 && (time->hours & 0x0f) > 2)
                {
                    time->hours &= 0xf0;  
                }
            }
        break;
    }
}

