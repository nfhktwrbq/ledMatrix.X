#include <util//delay.h>



#include "settings_menu.h"
#include "Menu.h"
#include "display.h"
#include "utils.h"
#include "clock.h"

//        Name,            				 Next,       					Previous,       				Parent,   				 Sibling,        SelectFunc,         					EnterFunc,     					      Text
MAKE_MENU(Level1ItemEnterTime    		, Level1ItemSensorsShowTimeout, Level1ItemSensorsSelect, 	  NULL_ENTRY ,				NULL_ENTRY     , menu_enterTime      					, NULL_FUNC    					       , 1);
MAKE_MENU(Level1ItemSensorsShowTimeout  , Level1ItemSensorsShowDelay  , Level1ItemEnterTime	   , 	  NULL_ENTRY ,				NULL_ENTRY     , menu_enterSensorsTimeout   			, NULL_FUNC    					       , 2);
MAKE_MENU(Level1ItemSensorsShowDelay    , Level1ItemSensorsSelect	  , Level1ItemEnterTime	   , 	  NULL_ENTRY ,				NULL_ENTRY     , menu_enterSensorsDelay	    			, NULL_FUNC    					       , 3);
MAKE_MENU(Level1ItemSensorsSelect    	, Level1ItemEnterTime		  , Level1ItemSensorsShowDelay,	  NULL_ENTRY ,				NULL_ENTRY     , NULL_FUNC								, NULL_FUNC    					       , 4);

MAKE_MENU(Level2ItemTemperature    		, Level2ItemHumidity		  , Level2ItemCO2,				  Level1ItemSensorsSelect , NULL_ENTRY     , menu_changeSensorsSelectTemperature	, menu_enterSensorsSelectTemperature   , 5);
MAKE_MENU(Level2ItemHumidity    		, Level2ItemPressure		  , Level2ItemTemperature, 		  Level1ItemSensorsSelect , NULL_ENTRY     , menu_changeSensorsSelectHumidity   	, menu_enterSensorsSelectHumidity      , 6);
MAKE_MENU(Level2ItemPressure    		, Level2ItemCO2				  , Level2ItemHumidity,			  Level1ItemSensorsSelect , NULL_ENTRY     , menu_changeSensorsSelectPrerssure  	, menu_enterSensorsSelectPrerssure     , 7);
MAKE_MENU(Level2ItemCO2		    		, Level2ItemTemperature		  , Level2ItemPressure, 		  Level1ItemSensorsSelect , NULL_ENTRY     , menu_changeSensorsSelectCO2        	, menu_enterSensorsSelectCO2           , 8);

//MAKE_MENU(Level1Item1Sub1, NULL_ENTRY , NULL_ENTRY , Level1Item1, NULL_ENTRY     , Level1Item1Sub1_Func, Level1Item1Sub1_Text, NULL_TEXT);

void printText(char * str)
{
    display_setText(str, 0);
    display_show();
}

void menu_init(void)
{
   SET_MENU_WRITE_FUNC(printText);
}

void menu_enterTime(void)
{
	TTime time;
	if(!enterTime(&time, TIME_FORMAT_24))
	{
		clock_setTime(&time);
	}
	SET_MENU(CurrMenuItem); 
}

void menu_enterSensorsTimeout(void)
{
	uint8_t sensorsTime;
	uint8_t sensorsTimeMin;
	uint8_t sensorsTimeMax;

	setting_getMin(SHOW_SENSORS_TIME, &sensorsTimeMin);
	setting_getMax(SHOW_SENSORS_TIME, &sensorsTimeMax);
	setting_get(SHOW_SENSORS_TIME, &sensorsTime);
	if(!enterSensorsTimeout(&sensorsTime, sensorsTimeMin, sensorsTimeMax, 'm'))
	{
		setting_set(SHOW_SENSORS_TIME, uint8_t * data);
	}
	SET_MENU(CurrMenuItem); 
}

void menu_enterSensorsDelay(void)
{
	uint8_t sensorsTime;
	uint8_t sensorsTimeMin;
	uint8_t sensorsTimeMax;

	setting_getMin(SHOW_SENSORS_DELAY, &sensorsTimeMin);
	setting_getMax(SHOW_SENSORS_DELAY, &sensorsTimeMax);
	setting_get(SHOW_SENSORS_DELAY, &sensorsTime);
	if(!enterSensorsTimeout(&sensorsTime, sensorsTimeMin, sensorsTimeMax, 'c'))
	{
		setting_set(SHOW_SENSORS_DELAY, uint8_t * data);
	}
	SET_MENU(CurrMenuItem); 
}

void menu_enterSensorsSelectTemperature(void)
{
	uint8_t sensorsSelect;
	setting_get(SHOW_SENSORS, &sensorsSelect);
	showSensorSelectState('T', (bool)(sensorsSelect & (1 << TEMPERATURE)));
}

void menu_enterSensorsSelectHumidity(void)
{
	uint8_t sensorsSelect;
	setting_get(SHOW_SENSORS, &sensorsSelect);
	showSensorSelectState('H', (bool)(sensorsSelect & (1 << HUMIDITY)));
}

void menu_enterSensorsSelectPressure(void)
{
	uint8_t sensorsSelect;
	setting_get(SHOW_SENSORS, &sensorsSelect);
	showSensorSelectState('P', (bool)(sensorsSelect & (1 << PRESSURE)));
}

void menu_enterSensorsSelectCO2(void)
{
	uint8_t sensorsSelect;
	setting_get(SHOW_SENSORS, &sensorsSelect);
	showSensorSelectState('C', (bool)(sensorsSelect & (1 << CO2)));
}

void menu_changeSensorsSelectTemperature(void)
{
	uint8_t sensorsSelect;
	setting_get(SHOW_SENSORS, &sensorsSelect);
	if(sensorsSelect & (1 << TEMPERATURE))
	{
		showSensorSelectState('T', false);
		sensorsSelect &= ~(1 << TEMPERATURE);
	}
	else
	{
		showSensorSelectState('T', true);
		sensorsSelect |= (1 << TEMPERATURE);
	}
	setting_set(SHOW_SENSORS, &sensorsSelect);	
	SET_MENU(CurrMenuItem);
}

void menu_changeSensorsSelectHumidity(void)
{
	uint8_t sensorsSelect;
	setting_get(SHOW_SENSORS, &sensorsSelect);
	if(sensorsSelect & (1 << HUMIDITY))
	{
		showSensorSelectState('H', false);
		sensorsSelect &= ~(1 << HUMIDITY);
	}
	else
	{
		showSensorSelectState('H', true);
		sensorsSelect |= (1 << HUMIDITY);
	}
	setting_set(SHOW_SENSORS, &sensorsSelect);
	SET_MENU(CurrMenuItem);	
}

void menu_changeSensorsSelectPressure(void)
{
	uint8_t sensorsSelect;
	setting_get(SHOW_SENSORS, &sensorsSelect);
	if(sensorsSelect & (1 << PRESSURE))
	{
		showSensorSelectState('P', false);
		sensorsSelect &= ~(1 << PRESSURE);
	}
	else
	{
		showSensorSelectState('P', true);
		sensorsSelect |= (1 << PRESSURE);
	}
	setting_set(SHOW_SENSORS, &sensorsSelect);	
	SET_MENU(CurrMenuItem);
}

void menu_changeSensorsSelectCO2(void)
{
	uint8_t sensorsSelect;
	setting_get(SHOW_SENSORS, &sensorsSelect);
	if(sensorsSelect & (1 << CO2))
	{
		showSensorSelectState('C', false);
		sensorsSelect &= ~(1 << CO2);
	}
	else
	{
		showSensorSelectState('C', true);
		sensorsSelect |= (1 << CO2);
	}
	setting_set(SHOW_SENSORS, &sensorsSelect);	
	SET_MENU(CurrMenuItem);
}