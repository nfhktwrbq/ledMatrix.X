#include <util/delay.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "buttons.h"
#include "timer.h"
#include "display.h"
#include "clock.h"
#include "settings.h"
#include "settings_menu.h"
#include "resource.h"
#include "mhz19b.h"
#include "adc.h"
#include "Menu.h"
#include "font.h"
#include "bme.h"

static TTimer settingShowTimer;
static uint8_t sensorsSelect;
static uint8_t sensorsTime;

const char util_string_0[] PROGMEM = EMPTY_STR;

PGM_P const util_string_table[] PROGMEM = 
{
    util_string_0,
};

static uint32_t hardwareState = 0;

static void showTimeout(uint8_t timeout, char unit)
{
    char displayData[5];
    char unitStr[2];
    unitStr[0] = unit;
    unitStr[1] = '\0';
    display_clear();
    itoa(timeout, displayData, 10);
    strcat((char *)displayData, unitStr);
    display_setText(displayData, 0);
    display_show();
}

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

int enterClocklCalibration(int8_t * calibration)
{
    TTimer buttonsTimeout;
    bool enterPressFlag = true;
    uint8_t pressedButton;
    uint8_t prevPressedButton = 0;

    int8_t cal = clock_calibration_get();
    char unit = (cal >= 0) ? '+' : '-';  
    
    timer_start(&buttonsTimeout, ENTER_TIME_BUTTONS_TIMEOUT);
    showTimeout(ABS(cal), unit);

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
                    if(ABS(cal) < CLOCK_MAX_ABS_CAL_VAL || cal > 0)
                    {
                        cal--;
                    }
                break;
                case BUTTON_RIGHT:
                    timer_restart(&buttonsTimeout);
                    if(ABS(cal) < CLOCK_MAX_ABS_CAL_VAL || cal < 0)
                    {
                        cal++;
                    }
                break;
            }
            showTimeout(ABS(cal), cal >= 0 ? '+' : '-');
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
    
    *calibration = cal;
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

uint8_t startCalibrationCO2(void)
{
    static TTimer timer_button;
    char buffer[6];
    uint8_t butonsSequence[] = {BUTTON_LEFT, BUTTON_RIGHT, BUTTON_DOWN, BUTTON_UP};
    uint8_t button = BUTTON_NONE;
    
    strcpy(buffer, "----");
    timer_start(&timer_button, CODE_ENTER_TIMEOUT);
    for(int i = 0; i < sizeof(butonsSequence); i++)
    {
        button = BUTTON_NONE;
        display_setText(buffer, 0);
        display_show();

        buttons_clearClickButton();
        timer_restart(&timer_button);
        while(button == BUTTON_NONE && !timer_check(&timer_button))
        {
            buttons_proc();
            button = buttons_getClickButtonNumber();
        }
        if(timer_check(&timer_button) || button != butonsSequence[i])
            return CO2_CALIBRATION_FAIL;
        buffer[i] = 0x30 + i;
    }
    display_setText(buffer, 0);
    display_show();
        
    _delay_ms(200);   
    mhz19b_startCalibrating();
    
    return CO2_CALIBRATION_OK; 
}

void hardReset(void)
{
    WDTCSR=0x18;
    WDTCSR=0x08;
    while(1);
}

void calibrationCO2Proc(void)
{
    char buffer[6];
    uint8_t calTime = CALIBRATION_CO2_TIME;
    while(calTime)
    {
        itoa(calTime, buffer, 10);
        display_setText(buffer, 1);
        display_show();
        _delay_ms(60000);        
        calTime--;
    }
    itoa(calTime, buffer, 10);
    display_setText(buffer, 1);
    display_show();
    _delay_ms(100); 
}

void enterUint8Setting(TSetting settingName, char unit)
{
    uint8_t setting;
	uint8_t settingMin;
	uint8_t settingMax;

	setting_getMin(settingName, &settingMin);
	setting_getMax(settingName, &settingMax);
	setting_get(settingName, &setting);
	if(!enterSensorsTimeout(&setting, settingMin, settingMax, unit))
	{
		setting_set(settingName, &setting);
	}
}

void brightnessAdjust(void)
{
    uint8_t brightnessStart;
    uint8_t brightnessSize;
    uint8_t adcValue;
    uint8_t brightness;
    
    setting_get(SETTING_BRIGTHNESS_START, &brightnessStart);
    setting_get(SETTING_BRIGTHNESS_SIZE, &brightnessSize);
    
    adcValue = adc_get();
    brightness = adcValue * (brightnessSize + 1) / ADC_MAX + brightnessStart;
     
    display_setIntensity(brightness);
    display_show();
}

void settingUpdateInit(void)
{
    timer_start(&settingShowTimer, SETTINGS_UPDATE_TIMEOUT);
    setting_get(SETTING_SHOW_SENSORS, &sensorsSelect);
    setting_get(SETTING_SHOW_SENSORS_TIME, &sensorsTime);    
}

void sensorProc(void)
{    
    //mhz19b_getState(void) == 
    if(timer_check(&settingShowTimer))
    {
        timer_restart(&settingShowTimer);
        setting_get(SETTING_SHOW_SENSORS, &sensorsSelect);
        setting_get(SETTING_SHOW_SENSORS_TIME, &sensorsTime); 
    }
    
    if(sensorsSelect & (1 << TEMPERATURE) || sensorsSelect & (1 << HUMIDITY) || sensorsSelect & (1 << PRESSURE))
    {
        bme_proc();
    }
    
    if(sensorsSelect & (1 << CO2))
    {
        mhz19b_proc();
    }	
}

uint8_t getSensorsTime(void)
{
    return sensorsTime;
}

void showSensorData(char * sensorNameStr, char * sensorDataStr, char * unitString, uint8_t delay )
{
    char buffer[40];
    int8_t dataOffset = 0;
    TTimer offsetTimer;
    TTimer delayTimer;
    uint8_t len;
 
    strcpy(buffer, sensorNameStr);
    strcat(buffer, sensorDataStr);
    strcat(buffer, unitString);
    
    len = strlen(buffer);
    
    timer_start(&offsetTimer, SENSORS_DATA_OFFSET_TIMEOUT);
    if((len * (FONT_WIDTH + LETTER_SPACE)) > MATRIX_NUM * MATRIX_WIDTH)
    {
        while(buttons_getClickButtonNumber() != BUTTON_LEFT && ((len * (FONT_WIDTH + LETTER_SPACE)) - MATRIX_NUM * MATRIX_WIDTH) + dataOffset > 0)
        {
            display_setText(buffer, dataOffset);
            display_show();
            if(timer_check(&offsetTimer))
            {
                timer_restart(&offsetTimer);
                dataOffset--;
            } 
            buttons_proc();
        }    
    }
    else
    {
        display_setText(buffer, 0);
        display_show();
    }
    
    timer_start(&delayTimer, delay*1000);    
    while(buttons_getClickButtonNumber() != BUTTON_LEFT && !timer_check(&delayTimer))
    {
        buttons_proc();
    }
}

void sensorsShow(void)
{
    uint8_t sensorsDelay;
    char sensorNameStr[20];
    char sensorDataStr[10];
    char sensorUnitStr[10];
     
	setting_get(SETTING_SHOW_SENSORS_DELAY, &sensorsDelay);
    if(sensorsSelect & (1 << TEMPERATURE))
    {
        uint8_t len;
        int32_t temp;
        strcpy_P(sensorNameStr, (PGM_P)pgm_read_word(&(menu_string_table[5])));
        len = strlen(sensorNameStr);
        sensorNameStr[len - 1] = '\0';
        strcat(sensorNameStr, ": ");
        temp = bme_getTemperature32();
        itoa(temp, sensorDataStr, 10);
        len = strlen(sensorDataStr);
        sensorDataStr[len - 1] = sensorDataStr[len - 2];
        sensorDataStr[len - 2] = '.';
        strcpy(sensorUnitStr, "");
        showSensorData(sensorNameStr, sensorDataStr, sensorUnitStr, sensorsDelay);
    }
    if(sensorsSelect & (1 << HUMIDITY))
    {
        uint8_t len;
        uint32_t humidity;
        strcpy_P(sensorNameStr, (PGM_P)pgm_read_word(&(menu_string_table[6])));
        len = strlen(sensorNameStr);
        sensorNameStr[len - 1] = '\0';
        strcat(sensorNameStr, ": ");
        humidity = bme_getHumidity32() / 1024;
        itoa(humidity, sensorDataStr, 10);
        strcpy(sensorUnitStr, "% ");
        showSensorData(sensorNameStr, sensorDataStr, sensorUnitStr, sensorsDelay);
    }
    if(sensorsSelect & (1 << PRESSURE))
    {
        uint8_t len;
        uint32_t pressure;
        strcpy_P(sensorNameStr, (PGM_P)pgm_read_word(&(menu_string_table[7])));
        len = strlen(sensorNameStr);
        sensorNameStr[len - 1] = '\0';
        strcat(sensorNameStr, ": ");
        pressure = bme_getPressure32()/10000;
        itoa(pressure, sensorDataStr, 10);
        strcpy(sensorUnitStr, "");
        showSensorData(sensorNameStr, sensorDataStr, sensorUnitStr, sensorsDelay);
    }
    if(sensorsSelect & (1 << CO2))
    {
        uint8_t len;
        uint16_t co2;
        strcpy_P(sensorNameStr, (PGM_P)pgm_read_word(&(menu_string_table[8])));
        len = strlen(sensorNameStr);
        sensorNameStr[len - 1] = '\0';
        strcat(sensorNameStr, ": ");
        co2 = mhz19b_getCO2Concentration();
        itoa(co2, sensorDataStr, 10);
        strcpy(sensorUnitStr, "");
        showSensorData(sensorNameStr, sensorDataStr, sensorUnitStr, sensorsDelay);
    }    
}