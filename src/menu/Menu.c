/*
	           MICRO-MENU

	     (C) Dean Camera, 2007
	    www.fourwalledcubicle.com
	dean_camera@fourwalledcubicle.com
	
	    Royalty-free for all uses.
	                                  */

#include "Menu.h"
#include "resource.h"

const char string_0[] PROGMEM = EMPTY_STR;
const char string_1[] PROGMEM = MENU_STR_ENTER_TIME;
const char string_2[] PROGMEM = MENU_STR_SHOW_TIMEOUT;
const char string_3[] PROGMEM = MENU_STR_SHOW_DELAY;
const char string_4[] PROGMEM = MENU_STR_SENSORS_SELECT;
const char string_5[] PROGMEM = MENU_STR_SENSORS_SELECT_TEMP;
const char string_6[] PROGMEM = MENU_STR_SENSORS_SELECT_HUM;
const char string_7[] PROGMEM = MENU_STR_SENSORS_SELECT_PRESS;
const char string_8[] PROGMEM = MENU_STR_SENSORS_SELECT_CO2;

PGM_P const menu_string_table[] PROGMEM = 
{
	string_0,
    string_1,
    string_2,
    string_3,
    string_4,
    string_5,
    string_6,
    string_7,
    string_8,
};

Menu_Item        Null_Menu = {(void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, 0x00};
Menu_Item*       CurrMenuItem;
WriteFuncPtr*    WriteFunc;

void MenuChange(Menu_Item* NewMenu)
{
	if ((void*)NewMenu == (void*)&NULL_ENTRY)
	  return;

	CurrMenuItem = NewMenu;
	
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
		((WriteFuncPtr)WriteFunc)((const char*)Buffer);
    #else
		((WriteFuncPtr)WriteFunc)((const char*)CurrMenuItem->Text);	
	#endif

	GO_MENU_FUNC(ENTERFUNC);
}

void MenuFunc(FuncPtr* Function)
{
	if ((void*)Function == (void*)NULL_FUNC)
	  return;

	((FuncPtr)Function)();
}
