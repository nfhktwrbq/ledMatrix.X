/* 
 * File:   display.h
 * Author: muaddib
 *
 * Created on October 28, 2019, 10:33 PM
 */

#ifndef DISPLAY_H
#define	DISPLAY_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <inttypes.h>
#include "spi.h"
#include "matrix.h"


#define MATRIX_NUM      4
#define LETTER_SPACE    1
#define LETTER_SPACE_V    1

void display_init(void);
void display_setIntensity(uint8_t intensity);
void display_show(void);
uint32_t * display_getBuffer(void);
void display_setText(char * str, int16_t startBit);
void display_addCharToPosition(char c, int8_t pos, uint8_t flag);
void display_setTimeText(uint8_t hoursBCD, uint8_t minutesBCD);
void display_clear(void);
void display_rollTimeText1(uint8_t hoursBCD, uint8_t minutesBCD, uint8_t frame);
bool display_rollTimeText2(uint8_t hoursBCD, uint8_t minutesBCD, uint8_t frame);
void test_rool(void);
void display_clearTimeDigit(uint8_t digit);
void display_partiallyClear(uint32_t part);
void display_clockColonSwitch(bool isOn);

#ifdef	__cplusplus
}
#endif

#endif	/* DISPLAY_H */

