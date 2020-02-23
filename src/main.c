/* 
 * File:   main.c
 * Author: muaddib
 *
 * Created on October 27, 2019, 12:23 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

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
#include "buttons.h"
#include "settings_menu.h"
#include "Menu.h"
#include "at24c32.h"
#include "settings.h"
#include "utils.h"
#include "adc.h"
#include "proc.h"

#ifdef DEBUG
#include "debug.h"
#endif
/*
 * 
 */
int main(void) {

    proc_init();
    
    while (1) 
    {
		hw_process();
    }
}
/*
void settings_test(void)
{
    TTime time;
    uint8_t disp[5];
    char buf[20];
    TTime timeMin;
    TTime timeMax;
    TTime timeDef;
    //at24c32_readBytes(AT24C32_ADDR, 0, (uint8_t *)&time, sizeof(time));
    
    time.hours = 0x6;
    time.minutes = 0x6;
    time.seconds = 0x6;
    
    T_TableAttr attr;
    //attr.len = (sizeof(((TTime *)0)->hours));
    //attr.offset = ((size_t)&(((TTime *)0)->hours));
    setting_getAttribute(SETTING_ALARM_TIME, &attr);
      
    at24c32_writeBytes(AT24C32_ADDR, attr.offset, (uint8_t *)&time, attr.len); 
       
    time.hours = 0x5;
    time.minutes = 0x4;
    time.seconds = 0x5;    
    disp[0] = time.hours + 0x30;
    disp[1] = time.minutes+ 0x30;
    disp[2] = time.seconds+ 0x30;
    disp[3] = 0;
    
    display_setText((char *)disp, 0);
    display_show();
    _delay_ms(2000);
    
    //
    //at24c32_writeBytes(AT24C32_ADDR, attr.offset, (uint8_t *)&time, attr.len); 
    //at24c32_writeBytes(AT24C32_ADDR, 0, (uint8_t *)"teck", 4);
    //at24c32_writeBytes(AT24C32_ADDR, 20, (uint8_t *)"teck", 4);
    setting_set(SETTING_ALARM_TIME, (uint8_t *)&time);
    
    memset(&time, 0, sizeof(time));
    memset(buf, 0x31, sizeof(buf)); 
    _delay_ms(10);
    
    buf[0] = 'c';
    itoa(attr.len, &buf[1], 10);   
    display_setText(buf, 0);
    display_show();
    _delay_ms(1000);
    
    buf[0] = 'o';
    itoa(attr.offset, &buf[1], 10); 
    display_setText(buf, 0);
    display_show();
    _delay_ms(1000);
    
    //at24c32_readBytes(AT24C32_ADDR, 1, &time, sizeof(time));
    //at24c32_readBytes(AT24C32_ADDR, attr.offset, &time, attr.len);
    setting_get(SETTING_ALARM_TIME, (uint8_t *)&time);
    
    buf[0] = 'p';
    buf[1] = time.hours + 0x30;
    buf[2] = time.minutes+ 0x30;
    buf[3] = time.seconds+ 0x30;
    display_setText(buf, 0);
    display_show();
    _delay_ms(2000);
    
    
    setting_getMin(SETTING_ALARM_TIME, (uint8_t *) &timeMin);
    disp[0] = 'a';
    disp[1] = timeMin.hours + 0x30;
    disp[2] = timeMin.minutes+ 0x30;
    disp[3] = timeMin.seconds+ 0x30;
    disp[4] = 0;
    display_setText((char *)disp, 0);
    display_show();
    _delay_ms(2000);
    
    setting_getMax(SETTING_ALARM_TIME, (uint8_t *) &timeMax);
    disp[0] = 'b';
    disp[1] = timeMax.hours + 0x30;
    disp[2] = timeMax.minutes+ 0x30;
    disp[3] = timeMax.seconds+ 0x30;
    disp[4] = 0;
    display_setText((char *)disp, 0);
    display_show();
    _delay_ms(2000);
    
    setting_getDef(SETTING_ALARM_TIME, (uint8_t *) &timeDef);
    disp[0] = 'c';
    disp[1] = timeDef.hours + 0x30;
    disp[2] = timeDef.minutes+ 0x30;
    disp[3] = timeDef.seconds+ 0x30;
    disp[4] = 0;
    display_setText((char *)disp, 0);
    display_show();
    _delay_ms(2000);
    
    for(uint8_t i = 1; i <= attr.len; i++)
    {         
        if(((uint8_t *)&time)[i] < ((uint8_t *)&timeMin)[i] || ((uint8_t *)&time)[i] > ((uint8_t *)&timeMax)[i])
        {
            ((uint8_t *)&time)[i] = ((uint8_t *)&timeDef)[i];
        }
    }
    
    buf[0] = 'h';
    buf[1] = time.hours + 0x30;
    buf[2] = time.minutes+ 0x30;
    buf[3] = time.seconds+ 0x30;
    display_setText(buf, 0);
    display_show();
    _delay_ms(2000);
    
    //setting_get(SETTING_ALARM_TIME, (uint8_t *)&time);
    //at24c32_readBytes(AT24C32_ADDR, 1, (uint8_t *)&time, sizeof(time));
    //at24c32_readBytes(AT24C32_ADDR, 0, (uint8_t *)disp, 4);        
    //at24c32_readBytes(AT24C32_ADDR, 20, (uint8_t *)buf, 4);
     
    display_setText("", 0);
    display_show();
    _delay_ms(1000);
    
}
*/
void eeprom_test(void)
{
    char buf[20];
    //at24c32_readBytes(AT24C32_ADDR, 0, (uint8_t *)buf, 6);
    at24c32_writeBytes(AT24C32_ADDR, 20, (uint8_t *)"teck", 4);
    //at24c32_readBytes(AT24C32_ADDR, 0, (uint8_t *)buf, 6);
   // at24c32_writeBytes(AT24C32_ADDR, 10, (uint8_t *)"teck", 4);
    display_setText("tect", 0);
    display_show();
    _delay_ms(2000);
    
    memset(buf, 0x31, sizeof(buf));
    
    at24c32_readBytes(AT24C32_ADDR, 21, (uint8_t *)buf, 6);
    display_setText("", 0);
    display_show();
    _delay_ms(2000);
    display_setText(buf, 0);
    display_show();
    _delay_ms(2000);
}

void buttonTestNumber(void)
{
    uint8_t bn = buttons_getPressNumber();
    if(bn)
    {
        char buf[4];
        itoa(bn, buf, 10);
        display_setText(buf, 0);
        display_show();
    }
}

void menuTest(void)
{
    if(buttons_getPress(BUTTON_ENTER))
    {
        GO_MENU_FUNC(SELECTFUNC);
    }
    if(buttons_getPress(BUTTON_UP))
    {
        SET_MENU(PREVIOUS);
    }
    if(buttons_getPress(BUTTON_DOWN))
    {
        SET_MENU(NEXT);
    }
    if(buttons_getPress(BUTTON_LEFT))
    {
        SET_MENU(PARENT);
    }
    if(buttons_getPress(BUTTON_RIGHT))
    {
        SET_MENU(SIBLING);
    }
}


void buttonsTestLong(void)
{
    uint8_t lb = 0;
    buttons_proc();
    
    
    lb = buttons_getLongPressNumber();
    if(lb)
    {
        buttons_getClickButtonNumber();
        if(lb == 1)
        {
            display_setText("BEE", 0);
            display_show();
        }
        if(lb == (BUTTON_UP))
        {
            display_setText("BAE", 0);
            display_show();
        }
        if(lb == (BUTTON_DOWN))
        {
            display_setText("BBE", 0);
            display_show();
        }
        if(lb == (BUTTON_LEFT))
        {
            display_setText("BHE", 0);
            display_show();
        }
        if(lb == (BUTTON_RIGHT))
        {
            display_setText("BME", 0);
            display_show();
        }
    }
}


void buttonsTest(void)
{
    if(buttons_getPress(BUTTON_ENTER))
    {
        display_setText("BE", 0);
        display_show();
    }
    if(buttons_getPress(BUTTON_UP))
    {
        display_setText("BA", 0);
        display_show();
    }
    if(buttons_getPress(BUTTON_DOWN))
    {
        display_setText("BB", 0);
        display_show();
    }
    if(buttons_getPress(BUTTON_LEFT))
    {
        display_setText("BH", 0);
        display_show();
    }
    if(buttons_getPress(BUTTON_RIGHT))
    {
        display_setText("BM", 0);
        display_show();
    }
}




