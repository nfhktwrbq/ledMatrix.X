/* 
 * File:   bmp.h
 * Author: muaddib
 *
 * Created on November 9, 2019, 7:38 PM
 */

#ifndef BMP_H
#define	BMP_H

#ifdef	__cplusplus
extern "C" {
#endif    
    

int8_t bmp_init(void);
int8_t bmp_getTemperature(int32_t * temp32);
int8_t bmp_getPressure(uint32_t * pres32);
    
#ifdef	__cplusplus
}
#endif

#endif	/* BMP_H */

