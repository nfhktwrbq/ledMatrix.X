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


void clock_init(void)
{
    
}

void clock_getTime(TTime * time)
{
    TClock clk;
    getDataReg(&clk);
    memcpy(time, &clk.time, sizeof(clk));
}