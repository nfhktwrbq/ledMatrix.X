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
#include "settings.h"
    
#define ENTER_TIME_BUTTONS_TIMEOUT	15000
#define ENTER_TIME_BLINK_TIMEOUT	400
#define CODE_ENTER_TIMEOUT          5000
#define SETTINGS_UPDATE_TIMEOUT     10000
#define SENSORS_DATA_OFFSET_TIMEOUT 50
#define ENTER_TIME_BUTTONS_TIMEOUT_ERR  (-1)   

#define CO2_CALIBRATION_FAIL        1
#define CO2_CALIBRATION_OK          0
#define CALIBRATION_CO2_TIME        20//min
    
#define ABS(x)      (x >= 0 ? x : -x)
    
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

int enterTime(TTime * time, TIME_FORMAT timeFormat); 
int enterClocklCalibration(int8_t * calibration);
uint8_t crc8(uint8_t *pcBlock, uint16_t len);
int enterSensorsTimeout(uint8_t * timeout, uint8_t timeoutMin, uint8_t timeoutMax, char unit);
void showSensorSelectState(char sensor, bool state);
uint8_t startCalibrationCO2(void);
void hardReset(void);
void calibrationCO2Proc(void);
void enterUint8Setting(TSetting settingName, char unit);
void brightnessAdjust(void);
void settingUpdateInit(void);
void sensorProc(void);
void sensorsShow(void);
uint8_t getSensorsTime(void);

#ifdef	__cplusplus
}
#endif

#endif	/* UTILS_H */

