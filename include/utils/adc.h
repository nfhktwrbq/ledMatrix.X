/* 
 * File:   adc.h
 * Author: muaddib
 *
 * Created on December 2, 2019, 10:42 PM
 */

#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus
extern "C" {
#endif

#define AVERAGE_SIZE    3
#define ADC_MAX         255
    
    
void adc_init(void);
uint8_t adc_get(void);

#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

