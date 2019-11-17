#include <util//delay.h>



#include "settings_menu.h"
#include "Menu.h"
#include "display.h"

void printText(char * str);


//        Name,             Next,       Previous,       Parent,     Sibling,        SelectFunc,         EnterFunc,              Text
MAKE_MENU(Level1Item1    , Level1Item2, Level1Item3, NULL_ENTRY , NULL_ENTRY     , NULL_FUNC           , NULL_FUNC           , 1);
MAKE_MENU(Level1Item2    , Level1Item3, Level1Item1, NULL_ENTRY , NULL_ENTRY     , NULL_FUNC           , NULL_FUNC           , 2);
MAKE_MENU(Level1Item3    , Level1Item1, Level1Item2, NULL_ENTRY , NULL_ENTRY     , NULL_FUNC           , NULL_FUNC           , 3);

//MAKE_MENU(Level1Item1Sub1, NULL_ENTRY , NULL_ENTRY , Level1Item1, NULL_ENTRY     , Level1Item1Sub1_Func, Level1Item1Sub1_Text, NULL_TEXT);

void printText(char * str)
{
    display_setText(str, 0);
    display_show();
}

void menu_init(void)
{
   SET_MENU_WRITE_FUNC(printText);
   printText("1");
   _delay_ms(2000);
   SET_MENU(Level1Item1); 
   _delay_ms(2000);
   printText("0");
   _delay_ms(2000);
   SET_MENU(NEXT);
   _delay_ms(2000);
   printText("0");
   _delay_ms(2000);
   SET_MENU(NEXT);
   while(1){};
}

