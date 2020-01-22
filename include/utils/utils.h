/* 
 * File:   utils.h
 * Author: muaddib
 *
 * Created on November 28, 2019, 10:42 PM
 */

#ifndef UTILS_H
#define	UTILS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
    
#include "clock.h"  
    
#define ENTER_TIME_BUTTONS_TIMEOUT	15000
#define ENTER_TIME_BLINK_TIMEOUT	400

#define ENTER_TIME_BUTTONS_TIMEOUT_ERR  (-1)   
  
typedef enum HwBit
{
	HW_CLOCK_OK = 0,
	HW_EEPROM_OK,
	HW_BME_OK,
	HW_MHZ19B_OK,
} HwBit;

void setHardwareState(HwBit hwBit);
void clearHardwareState(HwBit hwBit);
bool getHardwareState(HwBit hwBit);

int enterTime(TTime * time, uint8_t timeFormat);    
uint8_t crc8(uint8_t *pcBlock, uint16_t len);
int enterSensorsTimeout(uint8_t * timeout, uint8_t timeoutMin, uint8_t timeoutMax);

#ifdef	__cplusplus
}
#endif

#endif	/* UTILS_H */

