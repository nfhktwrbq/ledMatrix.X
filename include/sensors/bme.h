/* 
 * File:   bme.h
 * Author: muaddib
 *
 * Created on November 10, 2019, 1:32 PM
 */

#ifndef BME_H
#define	BME_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define BME_MEASURE_TIMEOUT         10000
#define BME_CONVERSION_TIMEOUT      50
    
int8_t bme_init(void);
int8_t bme_proc(void);
float  bme_getPressure(void);
float  bme_getTemperature(void);
float bme_getHumidity(void);
uint32_t bme_getPressure32(void);
int32_t  bme_getTemperature32(void);
uint32_t bme_getHumidity32(void);

#ifdef	__cplusplus
}
#endif

#endif	/* BME_H */

