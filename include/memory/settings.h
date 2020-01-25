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

#define MAX_SETTING_SIZE 4
    
#define SETTING_DEF(type, name,...)		SETTING_##name,
#define SETTING_DEF3(type, name,...)		SETTING_##name,

typedef enum
{
	//__setting_00,
    #include "settings_table.h"
}	TSetting;

#undef SETTING_DEF
#undef SETTING_DEF3    
    
    
typedef struct __attribute__ ((packed))
{
	uint16_t	offset;				
	uint8_t     len;			
} T_TableAttr;

void setting_getAttribute(TSetting setting, T_TableAttr * attr);
void setting_getMin(TSetting setting, uint8_t * data);
void setting_getMax(TSetting setting, uint8_t * data);
void setting_getDef(TSetting setting, uint8_t * data);
void setting_get(TSetting setting, uint8_t * data);
void setting_set(TSetting setting, uint8_t * data);
uint8_t setting_init(void);

#ifdef	__cplusplus
}
#endif

#endif	/* SETTINGS_H */

