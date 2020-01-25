/* 
 * File:   settings_menu.h
 * Author: muaddib
 *
 * Created on November 16, 2019, 8:02 PM
 */

#ifndef SETTINGS_MENU_H
#define	SETTINGS_MENU_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Menu.h"

#define MENU_PRINT_TEXT_OFFSET_TIMEOUT 80

typedef enum 
{
	TEMPERATURE = 0,
	HUMIDITY,
	PRESSURE,
	CO2,
} SENSORS;

void menu_init(void);
void menu_set(Menu_Item * menu);
void menu_printTexProcess(void);

void printText(char * str);
void menu_enterTime(void);
void menu_enterSensorsTimeout(void);
void menu_enterSensorsDelay(void);

void menu_changeSensorsSelectTemperature(void);	
void menu_enterSensorsSelectTemperature(void);
void menu_changeSensorsSelectHumidity(void);
void menu_enterSensorsSelectHumidity(void);
void menu_changeSensorsSelectPressure(void);
void menu_enterSensorsSelectPressure(void);
void menu_changeSensorsSelectCO2(void);
void menu_enterSensorsSelectCO2(void);



#ifdef	__cplusplus
}
#endif

#endif	/* SETTINGS_MENU_H */

