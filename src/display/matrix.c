#include "spi.h"
#include "matrix.h"
#include <string.h>

void matrix_writeCommand(uint8_t adr, uint8_t cmd)
{
	uint8_t buffer[2];
	buffer[0] = adr;
	buffer[1] = cmd;
	spi_transmit_sync(buffer, 2);
}

void matrix_writeDigit(uint8_t pos, uint8_t value)
{
	if(pos > 8)
		return;
	matrix_writeCommand(pos, value);
}


