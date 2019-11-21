/* 
 * File:   settings_table.h
 * Author: muaddib
 *
 * Created on November 18, 2019, 10:32 PM
 */
                //type       name                 def      min      max
SETTING_DEF(    uint8_t,     SHOW_SENSORS,        0x0f,    0x00,    0x0f    )
SETTING_DEF3(    TTime,       ALARM_TIME,          0x00, 0x00, 0x00,  0x00, 0x00, 0x00,  0x23, 0x59, 0x59 )  
