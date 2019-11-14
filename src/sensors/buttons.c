#include <avr/io.h>
#include <stdbool.h>

#include "buttons.h"
#include "timer.h"

#define BUTTON_ENTER_BIT        0x02
#define BUTTON_UP_BIT           0x40
#define BUTTON_DOWN_BIT         0x20
#define BUTTON_LEFT_BIT         0x01
#define BUTTON_RIGHT_BIT        0x80

static uint8_t longPressButtons = 0;

void buttons_init(void)
{
    DDR_BUTTON_ENTER &= ~BUTTON_ENTER_BIT;
    DDR_BUTTON_UP &= ~BUTTON_UP_BIT;   
    DDR_BUTTON_DOWN &= ~BUTTON_DOWN_BIT;
    DDR_BUTTON_LEFT &= ~BUTTON_LEFT_BIT;
    DDR_BUTTON_RIGHT &= ~BUTTON_RIGHT_BIT;
}

bool buttons_getPress(TButton button)
{
    switch(button)
    {
        case BUTTON_ENTER:
            return (bool)(PIN_BUTTON_ENTER & BUTTON_ENTER_BIT);
        case BUTTON_UP:
            return (bool)(PIN_BUTTON_UP & BUTTON_UP_BIT);
        case BUTTON_DOWN:
            return (bool)(PIN_BUTTON_DOWN & BUTTON_DOWN_BIT);
        case BUTTON_LEFT:
            return (bool)(PIN_BUTTON_LEFT & BUTTON_LEFT_BIT);
        case BUTTON_RIGHT:
            return (bool)(PIN_BUTTON_RIGHT & BUTTON_RIGHT_BIT);
        default:
            return false;
    }
}

uint8_t buttons_getPressNumber(void)
{    
    if(PIN_BUTTON_ENTER & BUTTON_ENTER_BIT)
        return  BUTTON_ENTER;
    if(PIN_BUTTON_UP & BUTTON_UP_BIT)
        return  BUTTON_UP;
    if(PIN_BUTTON_DOWN & BUTTON_DOWN_BIT)
        return  BUTTON_DOWN;
    if(PIN_BUTTON_LEFT & BUTTON_LEFT_BIT)
        return  BUTTON_LEFT;
    if(PIN_BUTTON_RIGHT & BUTTON_RIGHT_BIT)
        return  BUTTON_RIGHT;
    return 0;
}

void buttons_proc(void)
{
    static TTimer timer_button;
    static uint8_t curButtonNum = 0;
    static uint8_t prevButtonNum = 0;
    static bool pressFlag = false;
    
    curButtonNum = buttons_getPressNumber();
    if(prevButtonNum == curButtonNum && curButtonNum != 0)
    {
        if(pressFlag == false)
        {
           timer_start(&timer_button, LONG_PRESS_TIMEOUT);
           pressFlag = true; 
        }
        if(timer_check(&timer_button))
        {
           timer_stop(&timer_button); 
           longPressButtons = curButtonNum;
        }
    }
    else
    {
        pressFlag = false;
    }
    prevButtonNum = curButtonNum;   
}

uint8_t buttons_getLongPressNumber(void)
{
    return longPressButtons;
}

void clear_longPressBuffer(void)
{
    longPressButtons = 0;
}
