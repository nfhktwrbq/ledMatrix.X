/* 
 * File:   proc.h
 * Author: muaddib
 *
 * Created on January 19, 2020, 3:13 PM
 */

#ifndef PROC_H
#define	PROC_H

#ifdef	__cplusplus
extern "C" {
#endif
typedef enum
{
    PROC_NONE = 0,
    PROC_SHOW_TIME_START,
    PROC_SHOW_TIME_PREPARE,
    PROC_SHOW_TIME_GO,
    PROC_SETTINGS_START,
    PROC_SETTINGS_GO,
            
} ProcState;

void proc_init(void);
void hw_process(void);

#ifdef	__cplusplus
}
#endif

#endif	/* PROC_H */

