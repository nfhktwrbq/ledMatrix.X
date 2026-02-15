#include <string.h>

#include "clock.h"
#include "twi.h"
#include "debug.h"

#ifndef CLOCK_IC
#define CLOCK_IC DS1307
#endif

#define DS1307_HOURS_12_24_MSK        (1 << 6)
#define DS1307_HOURS_24_MSK           (0x3f) 

#define M41T81_CB_MSK                   (1 << 6)
#define M41T81_CEB_MSK                  (1 << 7)
#define M41T81_S_MSK                    (1 << 5)
#define M41T81_CAL_REG_ADDR             (8)

#if CLOCK_IC==M41T81
#define SECONDS_REG_ADDR    (1)
#else
#define SECONDS_REG_ADDR    (0)
#endif


static void getDataReg(TClock * clk)
{
    TClockTWICont clockCont;
    clockCont.data.time.seconds = SECONDS_REG_ADDR;
    clockCont.addr = (CLOCK_ADDR << 1) | 0; 
    
    TWI_SendData((uint8_t *)&clockCont, 2);
    
    clockCont.addr = (CLOCK_ADDR << 1) | 1;
    TWI_SendData((uint8_t *)&clockCont, sizeof(clockCont));
    
    TWI_GetData((uint8_t *)&clockCont, sizeof(clockCont));
    
    memcpy(clk, &(clockCont.data), sizeof(TClock));
}

static void setDataReg(TClock * clk)
{
    TClockTWIWriteCont clockCont;
    clockCont.slaveAddr = (CLOCK_ADDR << 1) | 0; 
    clockCont.wordAddr = SECONDS_REG_ADDR; //reset pointer
    memcpy(&clockCont.data, clk, sizeof(TClock)); 
    TWI_SendData((uint8_t *)&clockCont, sizeof(TClockTWIWriteCont));
}

static uint8_t readReg(uint8_t reg_addr)
{    
    uint8_t msg_w[] = {        
        (CLOCK_ADDR << 1) | 0,
        reg_addr,
    };
    
    TWI_SendData(msg_w, sizeof(msg_w));
    
    uint8_t msg_r[] = {
        (CLOCK_ADDR << 1) | 1,
        0,
    };
    
    TWI_SendData(msg_r, sizeof(msg_r));    
    TWI_GetData(msg_r, sizeof(msg_r));    
    return msg_r[1];
}

static void writeReg(uint8_t reg_addr, uint8_t reg)
{
    uint8_t msg_w[] = {        
        (CLOCK_ADDR << 1) | 0,
        reg_addr,
        reg,
    };
    
    TWI_SendData(msg_w, sizeof(msg_w));
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
#if CLOCK_IC==M41T81
    if(clk.time.hours & (M41T81_CEB_MSK | M41T81_CB_MSK))
    {
        clk.time.hours &= ~(M41T81_CEB_MSK | M41T81_CB_MSK);
        setDataReg(&clk);
    }
    uint8_t ht_reg = readReg(0x0c);
    if (0x40 & ht_reg)
    {
        ht_reg &= ~0x40;
        writeReg(0x0c, ht_reg);
    }
//    for (uint8_t i = 0; i < 0x14; i++)
//    {
//        (void)readReg(i);
//    }
#else
    if(clk.time.hours & DS1307_HOURS_12_24_MSK)
    {
        clk.time.hours &= ~DS1307_HOURS_12_24_MSK;
        setDataReg(&clk);
    }
#endif
    return TWI_GetState();
}

uint8_t clock_getTime(TTime * time)
{
    TClock clk;
    getDataReg(&clk);
    clk.time.hours &= DS1307_HOURS_24_MSK;
    memcpy(time, &clk.time, sizeof(TTime));
    return TWI_GetState();
}

uint8_t clock_setTime(TTime * time)
{
    uint8_t err;
    TClock clk;
    getDataReg(&clk);
    err = TWI_GetState();
    if(err)
    {
        return err;
    }
    memcpy(&(clk.time), time, sizeof(TTime));
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
                time->hours = (time->hours & 0x0f) + (digitChange(time->hours >> 4, diff, HOUR_TENS_MAX_24 ) << 4);
                if((time->hours >> 4) == 2 && (time->hours & 0x0f) > 4)
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

void clock_calibration_set(int8_t val)
{
#if CLOCK_IC==M41T81 
    uint8_t cal = readReg(M41T81_CAL_REG_ADDR);
    cal &= ~((1 << 6) | (M41T81_CAL_MSK)); //rest FT and current cal
    if (val > 0)
    {
        cal |= M41T81_S_MSK;
    }
    else
    {
        cal &= ~M41T81_S_MSK;
        val *= -1;
    }
    if (val > M41T81_CAL_MSK)
    {
        val = M41T81_CAL_MSK;
    }    
    
    cal |= val & M41T81_CAL_MSK;
    
    writeReg(M41T81_CAL_REG_ADDR, cal);
#endif
}

int8_t clock_calibration_get(void)
{
#if CLOCK_IC==M41T81  
    uint8_t cal = readReg(M41T81_CAL_REG_ADDR);
    
    bool neg = true;
    if (cal & M41T81_S_MSK)
    {
        neg = false;
    }
    
    int8_t res = (cal & M41T81_CAL_MSK) * (neg ? (-1) : 1);
    
    return res;    
#endif
}
