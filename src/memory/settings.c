#include <string.h>

#include <avr/pgmspace.h>
#include <util/delay.h>

#include "settings.h"
#include "clock.h"
#include "at24c32.h"
#include "utils.h"

#define offsetof(st, m) ((size_t)&(((st *)0)->m))
#define sizein(st, m) (sizeof(((st *)0)->m))
#define	ADDR(x)					(&(x))
#define MAX_SETTING_LEN   3

#define SETTING_DEF(type, name,...)		type		name;
#define SETTING_DEF3(type, name,...)		type		name;

typedef struct __attribute__ ((packed))
{
#include "settings_table.h"
}	T_Table;

#undef SETTING_DEF
#undef SETTING_DEF3

typedef struct __attribute__ ((packed))
{
    uint8_t crc;
    T_Table S;
}	T_TableCont;

#define SETTING_DEF(type, name, def,...)						            def,
#define SETTING_DEF3(type, name,def1, def2, def3, ...)		{def1, def2, def3},
const T_TableCont	tableDef PROGMEM =
{
    0xFF, 
    {
        #include "settings_table.h"
    }
};

#undef SETTING_DEF
#undef SETTING_DEF3

#define SETTING_DEF(type, name,...) {offsetof(T_Table,name), sizein(T_Table,name)},
#define SETTING_DEF3(type, name,...) {offsetof(T_Table,name), sizein(T_Table,name)},

const T_TableAttr tableAttr[] PROGMEM =
{
       #include "settings_table.h"
};

#undef SETTING_DEF
#undef SETTING_DEF3

#define SETTING_DEF(type, name, def, min, ...)			min,
#define SETTING_DEF3(type, name, def1, def2, def3, min1, min2, min3, ...)			{min1, min2, min3},

const T_Table tableMin PROGMEM =
{
#include "settings_table.h"
};

#undef SETTING_DEF
#undef SETTING_DEF3

#define SETTING_DEF(type, name, def, min, max)		max,
#define SETTING_DEF3(type, name, def1, def2, def3, min1, min2, min3, max1, max2, max3)		{max1, max2, max3},

const T_Table tableMax PROGMEM =
{
#include "settings_table.h"
};

#undef SETTING_DEF
#undef SETTING_DEF3

#define	TABLE_DEF(field)		((uint8_t *) (ADDR(tableDef.S)  + tableAttr[field].offset))
#define	TABLE_MIN(field)		((uint8_t *) (ADDR(tableMin) + tableAttr[field].offset))
#define	TABLE_MAX(field)		((uint8_t *) (ADDR(tableMax) + tableAttr[field].offset))

void setting_getAttribute(TSetting setting, T_TableAttr * attr)
{    
    memcpy_P(attr, &tableAttr[setting], sizeof(T_TableAttr));
}

void setting_getMin(TSetting setting, uint8_t * data)
{
    T_TableAttr attr;
    setting_getAttribute(setting, &attr);
    memcpy_P(data, ((uint8_t *)(&tableMin) + attr.offset), attr.len);
}

void setting_getMax(TSetting setting, uint8_t * data)
{
    T_TableAttr attr;
    setting_getAttribute(setting, &attr);
    memcpy_P(data, ((uint8_t *)(&tableMax) + attr.offset), attr.len);
}

void setting_getDef(TSetting setting, uint8_t * data)
{
    T_TableAttr attr;
    setting_getAttribute(setting, &attr);
    memcpy_P(data, ((uint8_t *)(&tableDef) + attr.offset + sizein(T_TableCont, crc)), attr.len);
}

void setting_get(TSetting setting, uint8_t * data)
{
    T_TableAttr attr;
    uint8_t settingMin[MAX_SETTING_LEN];
    uint8_t settingMax[MAX_SETTING_LEN];
    uint8_t settingDef[MAX_SETTING_LEN];
    
    setting_getAttribute(setting, &attr);     
    setting_getMin(setting, settingMin);
    setting_getMax(setting, settingMax);
    setting_getDef(setting, settingDef);
    
    at24c32_readBytes(AT24C32_ADDR, attr.offset, data, attr.len);
    for(uint8_t i = 0; i < attr.len; i++)
    {         
        if(data[i] < settingMin[i] || data[i] > settingMax[i])
        {
            data[i] = settingDef[i];
        }
    }
}

void setting_set(TSetting setting, uint8_t * data)
{
    T_TableAttr attr;
    uint8_t settingMin[MAX_SETTING_LEN];
    uint8_t settingMax[MAX_SETTING_LEN];
    uint8_t settingDef[MAX_SETTING_LEN];
    
    setting_getAttribute(setting, &attr);     
    setting_getMin(setting, settingMin);
    setting_getMax(setting, settingMax);
    setting_getDef(setting, settingDef);
    
    for(uint8_t i = 0; i < attr.len; i++)
    {         
        if(data[i] < settingMin[i] || data[i] > settingMax[i])
        {
            data[i] = settingDef[i];
        }
    }
    
    setting_get(setting, settingDef);
    if(memcmp(settingDef, data, attr.len))
    {
        at24c32_writeBytes(AT24C32_ADDR, attr.offset, data, attr.len);
    }
}

uint8_t setting_init(void)
{
    uint8_t calcCrc;
    T_TableCont defsTableCont;
    memcpy_P(&defsTableCont, (uint8_t *)(&tableDef), sizeof(T_TableCont));

    calcCrc = crc8((uint8_t *)&defsTableCont.S, sizeof(T_Table));

    if(calcCrc != defsTableCont.crc)
    {
        defsTableCont.crc = calcCrc;
        at24c32_writeBytes(AT24C32_ADDR, 0, (uint8_t *)&defsTableCont, sizeof(T_TableCont));
    }
    return at24c32_getState();
}

