/* 
 * File:   buttons.h
 * Author: muaddib
 *
 * Created on November 13, 2019, 10:47 PM
 */

#ifndef BUTTONS_H
#define	BUTTONS_H

#ifdef	__cplusplus
extern "C" {
#endif

#define DDR_BUTTON_ENTER    DDRB
#define DDR_BUTTON_UP       DDRD
#define DDR_BUTTON_DOWN     DDRD
#define DDR_BUTTON_LEFT     DDRB
#define DDR_BUTTON_RIGHT    DDRD

    
#define PORT_BUTTON_ENTER    PORTB
#define PORT_BUTTON_UP       PORTD
#define PORT_BUTTON_DOWN     PORTD
#define PORT_BUTTON_LEFT     PORTB
#define PORT_BUTTON_RIGHT    PORTD

    
#define PIN_BUTTON_ENTER    PINB
#define PIN_BUTTON_UP       PIND
#define PIN_BUTTON_DOWN     PIND
#define PIN_BUTTON_LEFT     PINB
#define PIN_BUTTON_RIGHT    PIND

#define LONG_PRESS_TIMEOUT  2000
    
typedef enum 
{
 BUTTON_ENTER  = 1,
 BUTTON_UP,
 BUTTON_DOWN,
 BUTTON_LEFT,
 BUTTON_RIGHT,
} TButton;

 void buttons_init(void);
 bool buttons_getPress(TButton button);
 uint8_t buttons_getPressNumber(void);
 void buttons_proc(void);
 uint8_t buttons_getLongPressNumber(void);
 void clear_longPressBuffer(void);

#ifdef	__cplusplus
}
#endif

#endif	/* BUTTONS_H */

