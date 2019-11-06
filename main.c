/* 
 * File:   main.c
 * Author: muaddib
 *
 * Created on October 27, 2019, 12:23 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>


#include "display.h"
#include "resource.h"
#include "clock.h"
#include "mhz19b.h"
#include "timer.h"

#ifdef DEBUG
#include "debug.h"
#endif

/*
 * 
 */
int main(void) {

    char dest[20];
    TTime time;
	strcpy_P(dest, PSTR(TEST_STRING));
    
    DDRB |= 0b00000010;
    DDRC|= 0b00100000;
    

    display_init();
    clock_init();
    mhz19b_init();
    timer0_init();
    
    uint32_t * buf = display_getBuffer();
    buf[0] = 0x01;
    buf[1] = 0x02;
    buf[2] = 0x03;
    buf[3] = 0x04;
    buf[4] = 0x05;
    buf[5] = 0x06;
    buf[6] = 0x07;
    buf[7] = 0x08;
    display_show();
    _delay_ms(1000);
    display_setIntensity(2);
    /*for(int i = 0; i < 5; i++)
    {
        display_setText(dest, i);

        display_show();
        _delay_ms(500);
        clock_getTime(&time);
    }
    for(int i = 5; i != 0; i--)
    {
        display_setText(dest, i);

        display_show();
        _delay_ms(500);
        clock_getTime(&time);
    }*/
    
    clock_getTime(&time);
    display_clear();
    display_setTimeText(time.hours, time.minutes);
    display_show();
    _delay_ms(2000);
    //co2 test begin
    while(1)
    {
        uint16_t concentration = mhz19b_getCO2Concentration();
        mhz19b_proc();
        memset(dest, 0, sizeof(dest));
        itoa(concentration, dest, 10);
        display_setText(dest, 0);
        display_show();
        _delay_ms(2000);
    }
    //co2 test end
     
    // test_rool();
   /* for(int i = 0; i != 40; i++)
    {
        display_clear();
        display_addCharToPosition('1', i, 0);
    display_show();

        
        _delay_ms(200);
        clock_getTime(&time);
    }*/
    
    while (1) 
    {
		//spi_fast_shift ('f');
		_delay_ms(1000);
        PORTB |= 0b00000010;
        PORTC |= 0b00100000;
        _delay_ms(1000);
        PORTB &= ~0b00000010;
        PORTC &= ~0b00100000;
    }
}

