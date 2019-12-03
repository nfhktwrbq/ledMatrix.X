#include <util/delay.h>

#include "utils.h"
#include "buttons.h"
#include "timer.h"
#include "display.h"
#include "clock.h"
 
static uint32_t hwOperFlags = 0;

void setOperFlag(uint32_t flag)
{
    hwOperFlags |= flag;
}

bool getOperFlag(uint32_t flag)
{
    return hwOperFlags & flag;
}

void clearOperFlag(uint32_t flag)
{
    hwOperFlags &= ~flag;
}

int enterTime(TTime * time, TIME_FORMAT timeFormat)
{
	TTimer buttonsTimeout;
	TTimer blinkTimer;
	uint8_t enterPos = 0;
	uint8_t blinkFlag = 0;
    bool enterPressFlag = true;
    uint8_t pressedButton;
    uint8_t prevPressedButton = 0;

	timer_start(&buttonsTimeout, ENTER_TIME_BUTTONS_TIMEOUT);
	timer_start(&blinkTimer, ENTER_TIME_BLINK_TIMEOUT);
	display_clockColonSwitch(true);

	//memcpy(&timeTmp, time, )

	while((!buttons_getPress(BUTTON_ENTER) && !timer_check(&buttonsTimeout)) || enterPressFlag)
	{
        pressedButton = buttons_getPressNumber();
        if(prevPressedButton != pressedButton)
        {
            prevPressedButton = pressedButton;
            switch(pressedButton)
            {
                case BUTTON_LEFT:
                    timer_restart(&buttonsTimeout);
                    if(enterPos > 0)
                        enterPos--;
                break;
                case BUTTON_RIGHT:
                    timer_restart(&buttonsTimeout);
                    if(enterPos < 3)
                        enterPos++;
                break;
                case BUTTON_UP:
                    timer_restart(&buttonsTimeout);
                    clock_changeTime(time, 1, timeFormat, (TIME_POS)(enterPos + 2));
                break;
                case BUTTON_DOWN:
                    timer_restart(&buttonsTimeout);
                    clock_changeTime(time, -1, timeFormat, (TIME_POS)(enterPos + 2));
                break;
            }
            _delay_ms(50);
        }

		if(timer_check(&blinkTimer))
		{
			if(blinkFlag % 2)
			{
    			display_clearTimeDigit(enterPos);
    		}
    		else
    		{
    			display_setTimeText(time->hours, time->minutes);
    		}
    		display_show();
    		blinkFlag++;
    		timer_restart(&blinkTimer);
		}
        
        if(!buttons_getPress(BUTTON_ENTER) && enterPressFlag)
        {
            enterPressFlag = false;
        }
	}
    
	if(timer_check(&buttonsTimeout)) 
	{
        return ENTER_TIME_BUTTONS_TIMEOUT_ERR;
    }
    
    return 0;
}
