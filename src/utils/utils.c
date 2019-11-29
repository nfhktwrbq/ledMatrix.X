#include "buttons.h"
#include "timer.h"
#include "display.h"
#include "clock.h"
 

int enterTime(TTime * time, uint8_t timeFormat)
{
	TTimer buttonsTimeout;
	TTimer blinkTimer;
	TTime timeTmp;
	uint8_t pressedButton;
	uint8_t enterPos = 0;
	uint8_t blinkFlag = 0;

	while(buttons_getPress(BUTTON_ENTER)){} 

	timer_start(&buttonsTimeout, ENTER_TIME_BUTTONS_TIMEOUT);
	timer_start(&blinkTimer, ENTER_TIME_BLINK_TIMEOUT);
	display_clockColonSwitch(true);

	//memcpy(&timeTmp, time, )

	while(!buttons_getPress(BUTTON_ENTER) && !timer_check(buttonsTimeout))
	{
		switch(buttons_getPressNumber())
		{
			case BUTTON_LEFT:
				timer_restart(buttonsTimeout);
				if(enterPos > 0)
					enterPos--;
			break;
			case BUTTON_RIGHT:
				timer_restart(buttonsTimeout);
				if(enterPos < 3)
					enterPos++;
			break;
			case BUTTON_UP:
			case BUTTON_DOWN:
				timer_restart(buttonsTimeout);
			break
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
    	

	}

	if(timer_check(buttonsTimeout)) 
	{}
}
