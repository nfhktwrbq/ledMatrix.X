#include <string.h>

#include "clock.h"
#include "twi.h"
#include "debug.h"



static void getDataReg(TClock * clk)
{
    twi_readBytes(DS1307_ADDR, 0, (uint8_t *)clk, sizeof(TClock));
//    uart_send(clk->time.seconds);
//    uart_send(clk->time.minutes);
//    uart_send(clk->time.hours);
//    uart_send(clk->date.dayOfWeek);
//    uart_send(clk->date.day);
//    uart_send(clk->date.month);
//    uart_send(clk->date.year);
//    uart_send(clk->controlRegister);
}


void clock_init(void)
{
    twi_init();
}

void clock_getTime(TTime * time)
{
    TClock clk;
    getDataReg(&clk);
    memcpy(time, &clk.time, sizeof(clk));
}