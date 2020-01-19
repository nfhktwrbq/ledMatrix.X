/* 
 * File:   mhz19b.h
 * Author: muaddib
 *
 * Created on November 4, 2019, 3:58 PM
 */

#ifndef MHZ19B_H
#define	MHZ19B_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <inttypes.h>
    
#define DETECTION_RANGE             0x99
#define AUTO_CALIBRATION            0x79
#define CALIBRATE_SPAN_POINT        0x88    //2000 or 5000 ppm
#define CALIBRATE_ZERO_POINT        0x87    //400ppm
#define READ_CO2_CONCENTRATION      0x86
    
#define START_BYTE                  0xff
#define SENSOR                      0x01
#define AUTO_CALIBRATION_OFF        0x00
#define AUTO_CALIBRATION_ON         0xA0
    
#define MEASURE_TIMEOUT             2000

#define MHZ19B_OK                   0
#define MHZ19B_NOT_ANSWER           1  
    
typedef struct __attribute__ ((packed))
{
    uint8_t startByte;
    uint8_t sensor;
    uint8_t content[6];
    uint8_t crc;
} TMHA19BPacket;    
    
void mhz19b_init();    
void mhz19b_sendCommand(uint8_t cmd, uint16_t parameter);
uint16_t mhz19b_getCO2Concentration(void);
void mhz19b_proc(void);
uint8_t mhz19b_getState(void);

#ifdef	__cplusplus
}
#endif

#endif	/* MHZ19B_H */

