#include <inttypes.h>

#include "twi.h"
#include "at24c32.h"


void at24c32_writeByte(uint16_t mem_addr, uint8_t data)
{
	uint8_t buf[4];

	buf[0] = (AT24C32_ADDR << 1);
	buf[1] = (uint8_t)(mem_addr >> 8);
	buf[2] = (uint8_t)(mem_addr & 0x00ff);
	buf[3] = data;

	TWI_SendData(buffer, sizeof(buf));
}

void at24c32_writeBytes(uint16_t mem_addr, uint8_t * data, uint8_t len)
{
	uint8_t buf[AT24C32_BUFFER_SIZE + 3];

	buf[0] = (AT24C32_ADDR << 1);
	buf[1] = (uint8_t)(mem_addr >> 8);
	buf[2] = (uint8_t)(mem_addr & 0x00ff);
	
	memcpy(&buf[3], data, len >= AT24C32_BUFFER_SIZE ? AT24C32_BUFFER_SIZE : len);

	TWI_SendData(buffer, sizeof(buf));
}

uint16_t at24c32_readCurrentAddress(void)
{
	uint8_t buf[3];
	buf[0] = (AT24C32_ADDR << 1) | 1;
	TWI_SendData(&addr, sizeof(buf));

	TWI_GetData(buffer, sizeof(buf));

	return ((buf[1] << 8) + buf[2]);
}

void at24c32_readBytes(uint16_t mem_addr, uint8_t * data, uint8_t len)
{
	uint8_t buf[AT24C32_BUFFER_SIZE + 3];

	buf[0] = (AT24C32_ADDR << 1);
	buf[1] = (uint8_t)(mem_addr >> 8);
	buf[2] = (uint8_t)(mem_addr & 0x00ff);
    
    TWI_SendData(buffer, 3);
    
    buffer[0] = (AT24C32_ADDR << 1) | 1;
    TWI_SendData(buffer, len + 1);
    
    TWI_GetData(buffer, len + 1);
    memcpy(data, &buffer[1], len);    
}