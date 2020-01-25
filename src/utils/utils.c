#include <util/delay.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "buttons.h"
#include "timer.h"
#include "display.h"
#include "clock.h"
#include "settings.h"
 
static uint32_t hardwareState = 0;

void setHardwareState(HwBit hwBit)
{
    hardwareState |= (uint32_t)(1 << hwBit);
}

void clearHardwareState(HwBit hwBit)
{
    hardwareState &= ~((uint32_t)(1 << hwBit));
}

bool getHardwareState(HwBit hwBit)
{
    return (hardwareState &((uint32_t)(1 << hwBit)));
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
    timer_stop(&buttonsTimeout);
    while(buttons_getPress(BUTTON_ENTER)){};

	if(timer_check(&buttonsTimeout)) 
	{
        return ENTER_TIME_BUTTONS_TIMEOUT_ERR;
    }
    
    return 0;
}

/*
  Name  : CRC-8
  Poly  : 0x31    x^8 + x^5 + x^4 + 1
  Init  : 0xFF
  Revert: false
  XorOut: 0x00
  Check : 0xF7 ("123456789")
  MaxLen: 15 байт(127 бит) - обнаружение
    одинарных, двойных, тройных и всех нечетных ошибок
*/
uint8_t crc8(uint8_t *pcBlock, uint16_t len)
{
    uint8_t crc = 0xFF;
    uint16_t i;

    while (len--)
    {
        crc ^= *pcBlock++;

        for (i = 0; i < 8; i++)
            crc = crc & 0x80 ? (crc << 1) ^ 0x31 : crc << 1;
    }

    return crc;
}


void showTimeout(uint8_t timeout, char unit)
{
    char displayData[5];
    display_clear();
    itoa(timeout, displayData, 10);
    strcat((char *)displayData, unit);
    display_setText(displayData, 0);
    display_show();
}

int enterSensorsTimeout(uint8_t * timeout, uint8_t timeoutMin, uint8_t timeoutMax, char unit)
{
    TTimer buttonsTimeout;
    bool enterPressFlag = true;
    uint8_t pressedButton;
    uint8_t prevPressedButton = 0;
    uint8_t sensorsTimeout = * timeout;

    timer_start(&buttonsTimeout, ENTER_TIME_BUTTONS_TIMEOUT);
    showTimeout(sensorsTimeout, unit);

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
                    if(sensorsTimeout > timeoutMin)
                        sensorsTimeout--;
                break;
                case BUTTON_RIGHT:
                    timer_restart(&buttonsTimeout);
                    if(sensorsTimeout < timeoutMax)
                        sensorsTimeout++;
                break;
                case BUTTON_UP:
                    timer_restart(&buttonsTimeout);
                    timer_restart(&buttonsTimeout);
                    if(sensorsTimeout < timeoutMax - 10)
                        sensorsTimeout += 10;
                break;
                case BUTTON_DOWN:
                    timer_restart(&buttonsTimeout);
                    if(sensorsTimeout > timeoutMin + 10)
                        sensorsTimeout -= 10;
                break;
            }
            showTimeout(sensorsTimeout, unit);
            _delay_ms(50);
        }

        if(!buttons_getPress(BUTTON_ENTER) && enterPressFlag)
        {
            enterPressFlag = false;
        }
    }
    timer_stop(&buttonsTimeout);
    while(buttons_getPress(BUTTON_ENTER)){};

    if(timer_check(&buttonsTimeout)) 
    {
        return ENTER_TIME_BUTTONS_TIMEOUT_ERR;
    }
    
    * timeout = sensorsTimeout;
    return 0;
}

void showSensorSelectState(char sensor, bool state)
{
    char displayData[5];
    display_clear();
    displayData[0] = sensor;
    displayData[1] = ':';
    if(state)
    {
        displayData[2] = 'O';
        displayData[3] = 'K';
    }
    else
    {
        displayData[2] = 'N';
        displayData[3] = 'O';
    }
    displayData[4] = 0;
    display_setText(displayData, 0);
    display_show();
}