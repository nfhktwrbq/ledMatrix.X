/*
	           MICRO-MENU

	     (C) Dean Camera, 2007
	    www.fourwalledcubicle.com
	dean_camera@fourwalledcubicle.com
	
	    Royalty-free for all uses.
	                                  */

#ifndef MENU_H
#define MENU_H

#include <avr/pgmspace.h>

#define MENU_USE_STRING_ARRAY (1 && !MENU_USE_SRAM_BUFFER)

#if MENU_USE_STRING_ARRAY
#define STRING_ARRAY_BUFFER_SIZE 100
#endif

extern PGM_P  const menu_string_table[];

// Typedefs:
typedef void (*FuncPtr)(void);
typedef void (*WriteFuncPtr)(const char*);

typedef struct {
	void       *Next;
	void       *Previous;
	void       *Parent;
	void       *Sibling;
	FuncPtr     SelectFunc;
	FuncPtr     EnterFunc;
#if MENU_USE_STRING_ARRAY
	uint8_t     stringNum;
#else
    const char  Text[];
#endif
} Menu_Item;

// Externs:
extern WriteFuncPtr*    WriteFunc;
extern Menu_Item        Null_Menu;
extern Menu_Item*       CurrMenuItem;

// Defines and Macros:
#define NULL_ENTRY Null_Menu
#define NULL_FUNC  (void*)0
#define NULL_TEXT  0x00

#define PREVIOUS   *((Menu_Item*)(CurrMenuItem->Previous))
#define NEXT       *((Menu_Item*)(CurrMenuItem->Next))
#define PARENT     *((Menu_Item*)(CurrMenuItem->Parent))
#define SIBLING    *((Menu_Item*)(CurrMenuItem->Sibling))
#define ENTERFUNC  *((FuncPtr*)(CurrMenuItem->EnterFunc))
#define SELECTFUNC *((FuncPtr*)(CurrMenuItem->SelectFunc))

#if MENU_USE_STRING_ARRAY
#define MAKE_MENU(Name, Next, Previous, Parent, Sibling, SelectFunc, EnterFunc, StringNum) \
    extern Menu_Item Next;     \
	extern Menu_Item Previous; \
	extern Menu_Item Parent;   \
	extern Menu_Item Sibling;  \
	Menu_Item Name = {(void*)&Next, (void*)&Previous, (void*)&Parent, (void*)&Sibling, (FuncPtr)SelectFunc, (FuncPtr)EnterFunc, StringNum}
#else
#define MAKE_MENU(Name, Next, Previous, Parent, Sibling, SelectFunc, EnterFunc, Text) \
    extern Menu_Item Next;     \
	extern Menu_Item Previous; \
	extern Menu_Item Parent;   \
	extern Menu_Item Sibling;  \
	Menu_Item Name = {(void*)&Next, (void*)&Previous, (void*)&Parent, (void*)&Sibling, (FuncPtr)SelectFunc, (FuncPtr)EnterFunc, { Text }}
#endif

#define SET_MENU_WRITE_FUNC(x) \
	WriteFunc = (WriteFuncPtr*)&x;

#define SET_MENU(x) \
	MenuChange((Menu_Item*)&x);
	
#define GO_MENU_FUNC(x)  \
	MenuFunc((FuncPtr*)&x)
	
#define EXTERN_MENU(Name) \
    extern Menu_Item Name;

// Prototypes:
void MenuChange(Menu_Item* NewMenu);
void MenuFunc(FuncPtr* Function);

EXTERN_MENU(Level1ItemEnterTime)
#endif
