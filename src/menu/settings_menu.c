#include <util//delay.h>
#include <string.h>

#include "settings_menu.h"
#include "Menu.h"
#include "display.h"
#include "utils.h"
#include "clock.h"
#include "settings.h"
#include "timer.h"
#include "font.h"
#include "matrix.h"

//        Name,            				 Next,       					Previous,       				Parent,   				 Sibling,        SelectFunc,         					EnterFunc,     					      Text
MAKE_MENU(Level1ItemEnterTime    		, Level1ItemSensorsShowTimeout, Level1ItemBrightnessSize, 	  NULL_ENTRY ,				NULL_ENTRY     , menu_enterTime      					, NULL_FUNC    					       , 1);
MAKE_MENU(Level1ItemSensorsShowTimeout  , Level1ItemSensorsShowDelay  , Level1ItemEnterTime	   , 	  NULL_ENTRY ,				NULL_ENTRY     , menu_enterSensorsTimeout   			, NULL_FUNC    					       , 2);
MAKE_MENU(Level1ItemSensorsShowDelay    , Level1ItemSensorsSelect	  , Level1ItemSensorsShowTimeout, NULL_ENTRY ,				NULL_ENTRY     , menu_enterSensorsDelay	    			, NULL_FUNC    					       , 3);
MAKE_MENU(Level1ItemSensorsSelect    	, Level1ItemCalibrationCO2	  , Level1ItemSensorsShowDelay,	  NULL_ENTRY ,		Level2ItemTemperature  , NULL_FUNC								, NULL_FUNC    					       , 4);
MAKE_MENU(Level1ItemCalibrationCO2    	, Level1ItemBrightnessStart	  , Level1ItemSensorsSelect,	  NULL_ENTRY ,    Level2ItemCalibrationCO2 , NULL_FUNC              				, NULL_FUNC    					       , 11);
MAKE_MENU(Level1ItemBrightnessStart    	, Level1ItemBrightnessSize	  , Level1ItemCalibrationCO2,	  NULL_ENTRY ,              NULL_ENTRY     , menu_enterBrightnessStart				, NULL_FUNC    					       , 13);
MAKE_MENU(Level1ItemBrightnessSize    	, Level1ItemEnterTime		  , Level1ItemBrightnessStart,	  NULL_ENTRY ,              NULL_ENTRY     , menu_enterBrightnessSize  				, NULL_FUNC    					       , 14);



MAKE_MENU(Level2ItemTemperature    		, Level2ItemHumidity		  , Level2ItemCO2,				  Level1ItemSensorsSelect , NULL_ENTRY     , menu_changeSensorsSelectTemperature	, NULL_FUNC                            , 5);
MAKE_MENU(Level2ItemHumidity    		, Level2ItemPressure		  , Level2ItemTemperature, 		  Level1ItemSensorsSelect , NULL_ENTRY     , menu_changeSensorsSelectHumidity   	, NULL_FUNC                            , 6);
MAKE_MENU(Level2ItemPressure    		, Level2ItemCO2				  , Level2ItemHumidity,			  Level1ItemSensorsSelect , NULL_ENTRY     , menu_changeSensorsSelectPressure       , NULL_FUNC                            , 7);
MAKE_MENU(Level2ItemCO2		    		, Level2ItemCalibrationCO2	  , Level2ItemPressure, 		  Level1ItemSensorsSelect , NULL_ENTRY     , menu_changeSensorsSelectCO2        	, NULL_FUNC                            , 8);
MAKE_MENU(Level2ItemCalibrationCO2		, NULL_ENTRY        		  , NULL_ENTRY,                   Level1ItemCalibrationCO2, NULL_ENTRY     , menu_startCalibrationCO2           	, NULL_FUNC                            , 12);


MAKE_MENU(Level3ItemTemperatureOk  		, Level3ItemTemperatureNo	  , Level3ItemTemperatureNo,	  Level2ItemTemperature ,   NULL_ENTRY     , menu_SensorsTemperatureSet         	, NULL_FUNC                            , 9);
MAKE_MENU(Level3ItemHumidityOk    		, Level3ItemHumidityNo		  , Level3ItemHumidityNo, 		  Level2ItemHumidity ,      NULL_ENTRY     , menu_SensorsHumiditySet                , NULL_FUNC                            , 9);
MAKE_MENU(Level3ItemPressureOk    		, Level3ItemPressureNo		  , Level3ItemPressureNo, 		  Level2ItemPressure ,      NULL_ENTRY     , menu_SensorsPressureSet                , NULL_FUNC                            , 9);
MAKE_MENU(Level3ItemCO2Ok		    	, Level3ItemCO2No             , Level3ItemCO2No,              Level2ItemCO2 ,           NULL_ENTRY     , menu_SensorsCO2Set                     , NULL_FUNC                            , 9);
MAKE_MENU(Level3ItemTemperatureNo  		, Level3ItemTemperatureOk	  , Level3ItemTemperatureOk,	  Level2ItemTemperature ,   NULL_ENTRY     , menu_SensorsTemperatureClear           , NULL_FUNC                            , 10);
MAKE_MENU(Level3ItemHumidityNo    		, Level3ItemHumidityOk		  , Level3ItemHumidityOk, 		  Level2ItemHumidity ,      NULL_ENTRY     , menu_SensorsHumidityClear              , NULL_FUNC                            , 10);
MAKE_MENU(Level3ItemPressureNo    		, Level3ItemPressureOk		  , Level3ItemPressureOk,		  Level2ItemPressure ,      NULL_ENTRY     , menu_SensorsPressureClear              , NULL_FUNC                            , 10);
MAKE_MENU(Level3ItemCO2No		    	, Level3ItemCO2Ok             , Level3ItemCO2Ok,              Level2ItemCO2 ,           NULL_ENTRY     , menu_SensorsCO2Clear                   , NULL_FUNC                            , 10);

//MAKE_MENU(Level1Item1Sub1, NULL_ENTRY , NULL_ENTRY , Level1Item1, NULL_ENTRY     , Level1Item1Sub1_Func, Level1Item1Sub1_Text, NULL_TEXT);

static int16_t displayText_offset = 0;
static TTimer offsetTimer;

void printText(char * str)
{
    display_setText(str, displayText_offset);
    display_show();
}

void menu_printTexProcess(void)
{
	if(timer_check(&offsetTimer))
	{
		timer_restart(&offsetTimer);
		displayText_offset--;
		#if defined(MENU_USE_SRAM_BUFFER)
			#if (MENU_USE_SRAM_BUFFER < 1)
			  #error Menu SRAM Buffer Size not Defined!
			#endif
			
			char Buffer[MENU_USE_SRAM_BUFFER];
			strcpy_P(Buffer, CurrMenuItem->Text);

			((WriteFuncPtr)WriteFunc)((const char*)Buffer);
	    #elif MENU_USE_STRING_ARRAY
	        char Buffer[STRING_ARRAY_BUFFER_SIZE];
			strcpy_P(Buffer, (PGM_P)pgm_read_word(&(menu_string_table[CurrMenuItem->stringNum])));
			uint8_t len = strlen((const char*)Buffer);
			((WriteFuncPtr)WriteFunc)((const char*)Buffer);
			if((-displayText_offset) > len * (LETTER_SPACE + FONT_WIDTH))
			{
				displayText_offset = MATRIX_WIDTH * MATRIX_NUM;
			}
	    #else
			((WriteFuncPtr)WriteFunc)((const char*)CurrMenuItem->Text);	
		#endif
	}
}

void menu_init(void)
{
   SET_MENU_WRITE_FUNC(printText);
   timer_start(&offsetTimer, MENU_PRINT_TEXT_OFFSET_TIMEOUT);
}

void menu_set(Menu_Item * menu)
{
	MenuChange(menu);
	displayText_offset = MATRIX_WIDTH;//MATRIX_WIDTH * MATRIX_NUM;
}

void menu_enterTime(void)
{
	TTime time;
	if(clock_getTime(&time))
	{
		return;
	}
	if(!enterTime(&time, TIME_FORMAT_24))
	{
		clock_setTime(&time);
	}
	//SET_MENU(CurrMenuItem); 
}

void menu_enterSensorsTimeout(void)
{
    enterUint8Setting(SETTING_SHOW_SENSORS_TIME, 'm');
	//SET_MENU(CurrMenuItem); 
}

void menu_enterSensorsDelay(void)
{
    enterUint8Setting(SETTING_SHOW_SENSORS_DELAY, 'c');
	//SET_MENU(CurrMenuItem); 
}

void menu_enterSensorsSelectTemperature(void)
{
	uint8_t sensorsSelect;
	setting_get(SETTING_SHOW_SENSORS, &sensorsSelect);
	showSensorSelectState('T', (bool)(sensorsSelect & (1 << TEMPERATURE)));
}

void menu_enterSensorsSelectHumidity(void)
{
	uint8_t sensorsSelect;
	setting_get(SETTING_SHOW_SENSORS, &sensorsSelect);
	showSensorSelectState('H', (bool)(sensorsSelect & (1 << HUMIDITY)));
}

void menu_enterSensorsSelectPressure(void)
{
	uint8_t sensorsSelect;
	setting_get(SETTING_SHOW_SENSORS, &sensorsSelect);
	showSensorSelectState('P', (bool)(sensorsSelect & (1 << PRESSURE)));
}

void menu_enterSensorsSelectCO2(void)
{
	uint8_t sensorsSelect;
	setting_get(SETTING_SHOW_SENSORS, &sensorsSelect);
	showSensorSelectState('C', (bool)(sensorsSelect & (1 << CO2)));
}

void menu_changeSensorsSelectTemperature(void)
{
	uint8_t sensorsSelect;
	setting_get(SETTING_SHOW_SENSORS, &sensorsSelect);
	if(sensorsSelect & (1 << TEMPERATURE))
	{
		menu_set(&Level3ItemTemperatureOk);
	}
	else
	{
		menu_set(&Level3ItemTemperatureNo);
	}
}

void menu_changeSensorsSelectHumidity(void)
{
	uint8_t sensorsSelect;
	setting_get(SETTING_SHOW_SENSORS, &sensorsSelect);
	if(sensorsSelect & (1 << HUMIDITY))
	{
		menu_set(&Level3ItemHumidityOk);
	}
	else
	{
		menu_set(&Level3ItemHumidityNo);
	}
	//SET_MENU(CurrMenuItem);	
}

void menu_changeSensorsSelectPressure(void)
{
	uint8_t sensorsSelect;
	setting_get(SETTING_SHOW_SENSORS, &sensorsSelect);
	if(sensorsSelect & (1 << PRESSURE))
	{
		menu_set(&Level3ItemPressureOk);
	}
	else
	{
		menu_set(&Level3ItemPressureNo);
	}
	//SET_MENU(CurrMenuItem);
}

void menu_changeSensorsSelectCO2(void)
{
	uint8_t sensorsSelect;
	setting_get(SETTING_SHOW_SENSORS, &sensorsSelect);
	if(sensorsSelect & (1 << CO2))
	{
		menu_set(&Level3ItemCO2Ok);
	}
	else
	{
		menu_set(&Level3ItemCO2No);
	}
	//SET_MENU(CurrMenuItem);
}

void menu_SensorsTemperatureSet(void)
{
    uint8_t sensorsSelect;
	setting_get(SETTING_SHOW_SENSORS, &sensorsSelect);
    if(!(sensorsSelect & (1 << TEMPERATURE)))
    {
        sensorsSelect |= (1 << TEMPERATURE);
        setting_set(SETTING_SHOW_SENSORS, &sensorsSelect);
    }
    menu_set(&Level2ItemTemperature);
}

void menu_SensorsHumiditySet(void)
{
    uint8_t sensorsSelect;
	setting_get(SETTING_SHOW_SENSORS, &sensorsSelect);
    if(!(sensorsSelect & (1 << HUMIDITY)))
    {
        sensorsSelect |= (1 << HUMIDITY);
        setting_set(SETTING_SHOW_SENSORS, &sensorsSelect);
    }
    menu_set(&Level2ItemHumidity);
}

void menu_SensorsPressureSet(void)
{
    uint8_t sensorsSelect;
	setting_get(SETTING_SHOW_SENSORS, &sensorsSelect);
    if(!(sensorsSelect & (1 << PRESSURE)))
    {
        sensorsSelect |= (1 << PRESSURE);
        setting_set(SETTING_SHOW_SENSORS, &sensorsSelect);
    }
    menu_set(&Level2ItemPressure);
}

void menu_SensorsCO2Set(void)
{
    uint8_t sensorsSelect;
	setting_get(SETTING_SHOW_SENSORS, &sensorsSelect);
    if(!(sensorsSelect & (1 << CO2)))
    {
        sensorsSelect |= (1 << CO2);
        setting_set(SETTING_SHOW_SENSORS, &sensorsSelect);
    }
    menu_set(&Level2ItemCO2);
}

void menu_SensorsTemperatureClear(void)
{
    uint8_t sensorsSelect;
	setting_get(SETTING_SHOW_SENSORS, &sensorsSelect);
    if(sensorsSelect & (1 << TEMPERATURE))
    {
        sensorsSelect &= ~(1 << TEMPERATURE);
        setting_set(SETTING_SHOW_SENSORS, &sensorsSelect);
    }
    menu_set(&Level2ItemTemperature);
}

void menu_SensorsHumidityClear(void)
{
    uint8_t sensorsSelect;
	setting_get(SETTING_SHOW_SENSORS, &sensorsSelect);
    if(sensorsSelect & (1 << HUMIDITY))
    {
        sensorsSelect &= ~(1 << HUMIDITY);
        setting_set(SETTING_SHOW_SENSORS, &sensorsSelect);
    }
    menu_set(&Level2ItemHumidity);
}

void menu_SensorsPressureClear(void)
{
    uint8_t sensorsSelect;
	setting_get(SETTING_SHOW_SENSORS, &sensorsSelect);
    if(sensorsSelect & (1 << PRESSURE))
    {
        sensorsSelect &= ~(1 << PRESSURE);
        setting_set(SETTING_SHOW_SENSORS, &sensorsSelect);
    }
    menu_set(&Level2ItemPressure);
}

void menu_SensorsCO2Clear(void)
{
    uint8_t sensorsSelect;
	setting_get(SETTING_SHOW_SENSORS, &sensorsSelect);
    if(sensorsSelect & (1 << CO2))
    {
        sensorsSelect &= ~(1 << CO2);
        setting_set(SETTING_SHOW_SENSORS, &sensorsSelect);
    }
    menu_set(&Level2ItemCO2);
}

void menu_startCalibrationCO2(void)
{
    if(startCalibrationCO2() == CO2_CALIBRATION_OK)
    {
        calibrationCO2Proc();
        hardReset();
        while(1);
    }
    menu_set(&Level1ItemCalibrationCO2);
}

void menu_enterBrightnessStart(void)
{
    enterUint8Setting(SETTING_BRIGTHNESS_START, '\0');
}

void menu_enterBrightnessSize(void)
{
    enterUint8Setting(SETTING_BRIGTHNESS_SIZE, '\0');
}