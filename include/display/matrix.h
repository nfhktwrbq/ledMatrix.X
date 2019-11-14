#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdbool.h>
#include <inttypes.h>

//max7219

#define MATRIX_HEIGHT   8
#define MATRIX_WIDTH    8

#define DECODE_MODE_REG 0x09
#define INTENSITY_REG   0x0A
#define SCAN_LIMIT_REG  0x0B
#define SHUTDOWN_REG    0x0C
#define TEST_REG        0x0F

#define DECODE_MODE_NO_DECODE       0x00
#define DECODE_MODE_CODE_B_FOR_0    0x01
#define DECODE_MODE_CODE_B_FOR_3_0  0x0f
#define DECODE_MODE_CODE_B_FOR_7_0  0xff


void matrix_writeDigit(uint8_t pos, uint8_t value);
void matrix_writeCommand(uint8_t adr, uint8_t cmd);

#endif
