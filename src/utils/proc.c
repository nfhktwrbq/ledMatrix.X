#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include <string.h>
#include <stdbool.h>

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

#if DEBUG
uint8_t debug_disp[5];
#endif

#define PROC_ROLL_FRAME_SPEED   (100)
#define PROC_HALF_OF_SECOND (1000/PROC_ROLL_FRAME_SPEED/2) 


static ProcState proc_state = PROC_NONE;
static TTime currentTime;
static TTimer secondTimer;
static uint8_t count100ms;
static bool flChangeMinutes = false;
static uint8_t frameCounter = 0;

void proc_init(void)
{
    int err = 0;
    display_init();
#if DEBUG
    
    display_clear();
    debug_disp[0] = 'C';
    debug_disp[1] = 0;
    display_setText("CT", 0);
    display_show();
    _delay_ms(1000);
#endif
    TWI_MasterInit(100);
    
    mhz19b_init();    
    timer0_init();
    timer1_init();
    err = clock_init();
    if(!err)
    {
        setHardwareState(HW_CLOCK_OK);
    }
    if(!bme_init())
    {
        setHardwareState(HW_BME_OK);
    }
    buttons_init();
    adc_init();
    if(!setting_init())
    {
        setHardwareState(HW_EEPROM_OK);
    }    
    menu_init(); 
#if DEBUG
    itoa(err, &debug_disp[1], 10);
    debug_disp[0] = 'A';   
    display_setText(debug_disp, 0);
    display_show();
   _delay_ms(1000);
#endif
}

void hw_process(void)
{    
    switch(proc_state)
    {
        case PROC_NONE:
            if(getHardwareState(HW_CLOCK_OK))
            {
                proc_state = PROC_SHOW_TIME_PREPARE;
            }
            break;
        case PROC_SHOW_TIME_PREPARE:
            clock_getTime(&currentTime);
            display_clear();
            display_setTimeText(currentTime.hours, currentTime.minutes);
            display_show();
            timer_start(&secondTimer, PROC_ROLL_FRAME_SPEED);
            proc_state = PROC_SHOW_TIME_GO;
            break;
        case PROC_SHOW_TIME_GO:
            if(timer_check(&secondTimer))
            {
                TTime newTime;
                count100ms++;                 
                //uint8_t err = clock_getTime(&newTime);              
                clock_getTime(&newTime);              
                if(count100ms == PROC_HALF_OF_SECOND)
                {
                    display_clockColonSwitch(false);
                }
                if(count100ms == PROC_HALF_OF_SECOND * 2)
                {
                    display_clockColonSwitch(true);
                    count100ms = 0;
                }
                if(flChangeMinutes)
                {
                    if(display_rollTimeText2(currentTime.hours, currentTime.minutes, frameCounter))
                    {
                        frameCounter++;
                    }
                    else
                    {
                        flChangeMinutes = false;
                        frameCounter = 0;
                    }
                }
                else
                {                  
                    if(memcmp(&currentTime, &newTime, sizeof(currentTime)))
                    {
                        flChangeMinutes = true;
                        memcpy(&currentTime, &newTime, sizeof(currentTime));
                    }
                }                
                display_show();
                timer_restart(&secondTimer);
            }
            break;
        default:
            break;
    }
}