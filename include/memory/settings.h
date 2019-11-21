/* 
 * File:   settings.h
 * Author: muaddib
 *
 * Created on November 18, 2019, 10:31 PM
 */

#ifndef SETTINGS_H
#define	SETTINGS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <avr/pgmspace.h>

#define MAX_SETTING_SIZE 3
    
typedef struct __attribute__ ((packed))
{
	uint16_t	offset;				
	uint8_t     len;			
} T_TableAttr;


#ifdef	__cplusplus
}
#endif

#endif	/* SETTINGS_H */

