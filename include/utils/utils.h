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

#include "clock.h"  
    
#define ENTER_TIME_BUTTONS_TIMEOUT	15000
#define ENTER_TIME_BLINK_TIMEOUT	400

#define ENTER_TIME_BUTTONS_TIMEOUT_ERR  (-1)   
    
int enterTime(TTime * time, uint8_t timeFormat);    
    
#ifdef	__cplusplus
}
#endif

#endif	/* UTILS_H */

