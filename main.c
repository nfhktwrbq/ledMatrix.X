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
#include "twi.h"
#include "bme.h"

#ifdef DEBUG
#include "debug.h"
#endif

static double PRECISION = 0.00000000000001;
//static int MAX_NUMBER_STRING_SIZE = 32;

char * dtoa(double n, char *s);

/*
 * 
 */
int main(void) {

    char dest[20];
//    TTime time;
	strcpy_P(dest, PSTR(TEST_STRING));
    
    DDRB |= 0b00000010;
    DDRC|= 0b00100000;
    
    TWI_MasterInit(100);
    display_init();
    clock_init();
    mhz19b_init();
    timer0_init();
    bme_init();
    
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
    
    //clock_getTime(&time);
    //display_clear();
    //display_setTimeText(time.hours, time.minutes);
    //display_show();
    //_delay_ms(2000);
    //co2 test begin
    
    _delay_ms(2000);
    
    
    int8_t bme_proc_status = 0;
    while(1)
    {
        bme_proc_status = bme_proc();
        uint32_t temp = bme_getPressure32()/10000;
        
//        uint16_t concentration = mhz19b_getCO2Concentration();
//        mhz19b_proc();
        
        memset(dest, 0, sizeof(dest));
        itoa(temp, dest, 10);
        display_setText(dest, 0);
        display_show();
        _delay_ms(2000);
        if(bme_proc_status)
        {
            itoa(bme_proc_status, dest, 10);
            display_setText(dest, 0);
            display_show();
            _delay_ms(10000);
        }
    }
    //co2 test end{
        display_clear();
     
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

char * dtoa(double n, char *s) {
    // handle special cases
    if (isnan(n)) {
        strcpy(s, "nan");
    } else if (isinf(n)) {
        strcpy(s, "inf");
    } else if (n == 0.0) {
        strcpy(s, "0");
    } else {
        int digit, m, m1;
        char *c = s;
        int neg = (n < 0);
        if (neg)
            n = -n;
        // calculate magnitude
        m = log10(n);
        int useExp = (m >= 14 || (neg && m >= 9) || m <= -9);
        if (neg)
            *(c++) = '-';
        // set up for scientific notation
        if (useExp) {
            if (m < 0)
               m -= 1.0;
            n = n / pow(10.0, m);
            m1 = m;
            m = 0;
        }
        if (m < 1.0) {
            m = 0;
        }
        // convert the number
        while (n > PRECISION || m >= 0) {
            double weight = pow(10.0, m);
            if (weight > 0 && !isinf(weight)) {
                digit = floor(n / weight);
                n -= (digit * weight);
                *(c++) = '0' + digit;
            }
            if (m == 0 && n > 0)
                *(c++) = '.';
            m--;
        }
        if (useExp) {
            // convert the exponent
            int i, j;
            *(c++) = 'e';
            if (m1 > 0) {
                *(c++) = '+';
            } else {
                *(c++) = '-';
                m1 = -m1;
            }
            m = 0;
            while (m1 > 0) {
                *(c++) = '0' + m1 % 10;
                m1 /= 10;
                m++;
            }
            c -= m;
            for (i = 0, j = m-1; i<j; i++, j--) {
                // swap without temporary
                c[i] ^= c[j];
                c[j] ^= c[i];
                c[i] ^= c[j];
            }
            c += m;
        }
        *(c) = '\0';
    }
    return s;
}