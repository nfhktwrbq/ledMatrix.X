#include <inttypes.h>
#include <string.h>

#include "twi.h"
#include "at24c32.h"
#if USE_ATMEGA_INTERNAL_EEPROM
#include <avr/eeprom.h>
#endif

void at24c32_writeByte(uint8_t id, uint16_t mem_addr, uint8_t data)
{
    uint8_t addr = mem_addr;
#if USE_ATMEGA_INTERNAL_EEPROM
    eeprom_write_byte (&addr, data);
#else
	uint8_t buf[4];

	buf[0] = (id << 1);
	buf[1] = (uint8_t)(mem_addr >> 8);
	buf[2] = (uint8_t)(mem_addr & 0x00ff);
	buf[3] = data;

	TWI_SendData(buf, sizeof(buf));
#endif
}

void at24c32_writeBytes(uint8_t id, uint16_t mem_addr, uint8_t * data, uint8_t len)
{
    
#if USE_ATMEGA_INTERNAL_EEPROM
    eeprom_write_block ((const void *)data, (void *)mem_addr, len);
#else
	uint8_t buf[AT24C32_BUFFER_SIZE + 3];

	buf[0] = (id << 1);
	buf[1] = (uint8_t)(mem_addr >> 8);
	buf[2] = (uint8_t)(mem_addr & 0x00ff);
	
	memcpy(&buf[3], data, len >= AT24C32_BUFFER_SIZE ? AT24C32_BUFFER_SIZE : len);

	TWI_SendData(buf, sizeof(buf));
#endif
}

uint16_t at24c32_readCurrentAddress(uint8_t id)
{
#if USE_ATMEGA_INTERNAL_EEPROM
    return 0;
#else
	uint8_t buf[3];
	buf[0] = (id << 1) | 1;
	TWI_SendData(buf, sizeof(buf));

	TWI_GetData(buf, sizeof(buf));

	return ((buf[1] << 8) + buf[2]);
#endif    
}

void at24c32_readBytes(uint8_t id, uint16_t mem_addr, uint8_t * data, uint8_t len)
{
#if USE_ATMEGA_INTERNAL_EEPROM
    eeprom_read_block ((void *)data, (const void *)mem_addr, len);
#else            
	uint8_t buf[AT24C32_BUFFER_SIZE + 3];

	buf[0] = (id << 1);
	buf[1] = (uint8_t)(mem_addr >> 8);
	buf[2] = (uint8_t)(mem_addr & 0x00ff);
    
    TWI_SendData(buf, 3);
    
    buf[0] = (id << 1) | 1;
    TWI_SendData(buf, len + 1);
    
    TWI_GetData(buf, len + 1);
    memcpy(data, &buf[1], len); 
#endif
}

uint8_t at24c32_getState(void)
{
    return TWI_GetState();
}