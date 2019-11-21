#include <string.h>

#include "settings.h"
#include "clock.h"
#include "at24c32.h"

#define offsetof(st, m) ((size_t)&(((st *)0)->m))
#define sizein(st, m) (sizeof(((st *)0)->m))
#define	ADDR(x)					(&(x))

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

#define SETTING_DEF(type, name,...)		SETTING_##name,
#define SETTING_DEF3(type, name,...)		SETTING_##name,

typedef enum
{
	//__setting_00,
    #include "settings_table.h"
}	TSetting;

#undef SETTING_DEF
#undef SETTING_DEF3

#define	TABLE_DEF(field)		((uint8_t *) (ADDR(tableDef.S)  + tableAttr[field].offset))
#define	TABLE_MIN(field)		((uint8_t *) (ADDR(tableMin) + tableAttr[field].offset))
#define	TABLE_MAX(field)		((uint8_t *) (ADDR(tableMax) + tableAttr[field].offset))

void settings_get(TSetting setting, uint8_t * data)
{
    T_TableAttr attr = tableAttr[setting];
    at24c32_readBytes(AT24C32_ADDR, attr.offset, data, attr.len);
    for(uint8_t i = 0; i < attr.len; i++)
    {         
        if(data[i] < TABLE_MIN(setting)[i] || data[i] > TABLE_MAX(setting)[i])
        {
            data[i] = TABLE_DEF(setting)[i];
        }
    }
}

void setting_set(TSetting setting, uint8_t * data)
{
    T_TableAttr attr = tableAttr[setting];
    uint8_t buf[MAX_SETTING_SIZE];
    for(uint8_t i = 0; i < attr.len; i++)
    {         
        if(data[i] < TABLE_MIN(setting)[i] || data[i] > TABLE_MAX(setting)[i])
        {
            data[i] = TABLE_DEF(setting)[i];
        }
    }
    settings_get(setting, buf);
    if(!memcmp(buf, data, attr.len))
    {
        at24c32_writeBytes(AT24C32_ADDR, attr.offset, data, attr.len);
    }
}