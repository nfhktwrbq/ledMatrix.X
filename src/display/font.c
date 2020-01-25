#include <avr/pgmspace.h>
#include "font.h"

//byte = pgm_read_byte(&(hexFont[i][j]));

const uint8_t hexFont[MAX_CHAR_NUM][FONT_HEIGHT] PROGMEM = {
	{ 0x00, 0x1C, 0x22, 0x22, 0x3E, 0x22, 0x22, 0x00, },	//1
	{ 0x00, 0x3E, 0x20, 0x3C, 0x22, 0x22, 0x3C, 0x00, },	//2
	{ 0x00, 0x3C, 0x22, 0x3C, 0x22, 0x22, 0x3C, 0x00, },	//3
	{ 0x00, 0x3E, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, },	//4
	{ 0x00, 0x0C, 0x14, 0x14, 0x14, 0x3E, 0x22, 0x00, },	//5
	{ 0x00, 0x3E, 0x20, 0x3C, 0x20, 0x20, 0x3E, 0x00, },	//6
	{ 0x14, 0x00, 0x3E, 0x20, 0x3C, 0x20, 0x3E, 0x00, },	//7
	{ 0x00, 0x2A, 0x2A, 0x1C, 0x2A, 0x2A, 0x2A, 0x00, },	//8
	{ 0x00, 0x3C, 0x02, 0x1C, 0x02, 0x02, 0x3C, 0x00, },	//9
	{ 0x00, 0x22, 0x22, 0x26, 0x2A, 0x32, 0x22, 0x00, },	//10
	{ 0x1C, 0x00, 0x22, 0x26, 0x2A, 0x32, 0x22, 0x00, },	//11
	{ 0x00, 0x22, 0x22, 0x24, 0x38, 0x24, 0x22, 0x00, },	//12
	{ 0x00, 0x06, 0x0A, 0x12, 0x12, 0x12, 0x22, 0x00, },	//13
	{ 0x00, 0x22, 0x36, 0x2A, 0x2A, 0x22, 0x22, 0x00, },	//14
	{ 0x00, 0x22, 0x22, 0x3E, 0x22, 0x22, 0x22, 0x00, },	//15
	{ 0x00, 0x1C, 0x22, 0x22, 0x22, 0x22, 0x1C, 0x00, },	//16
	{ 0x00, 0x3E, 0x22, 0x22, 0x22, 0x22, 0x22, 0x00, },	//17
	{ 0x00, 0x3C, 0x22, 0x22, 0x3C, 0x20, 0x20, 0x00, },	//18
	{ 0x00, 0x1C, 0x22, 0x20, 0x20, 0x22, 0x1C, 0x00, },	//19
	{ 0x00, 0x3E, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00, },	//20
	{ 0x00, 0x22, 0x22, 0x22, 0x1E, 0x02, 0x1C, 0x00, },	//21
	{ 0x08, 0x1C, 0x2A, 0x2A, 0x2A, 0x1C, 0x08, 0x00, },	//22
	{ 0x00, 0x22, 0x14, 0x08, 0x14, 0x22, 0x22, 0x00, },	//23
	{ 0x00, 0x22, 0x22, 0x22, 0x22, 0x22, 0x3F, 0x01, },	//24
	{ 0x00, 0x22, 0x22, 0x22, 0x1E, 0x02, 0x02, 0x00, },	//25
	{ 0x00, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x3E, 0x00, },	//26
	{ 0x00, 0x2A, 0x2A, 0x2A, 0x2A, 0x2A, 0x3F, 0x01, },	//27
	{ 0x00, 0x30, 0x10, 0x1C, 0x12, 0x12, 0x1C, 0x00, },	//28
	{ 0x00, 0x21, 0x21, 0x39, 0x25, 0x25, 0x39, 0x00, },	//29
	{ 0x00, 0x20, 0x20, 0x3C, 0x22, 0x22, 0x3C, 0x00, },	//30
	{ 0x00, 0x38, 0x04, 0x02, 0x1E, 0x04, 0x38, 0x00, },	//31
	{ 0x00, 0x24, 0x2A, 0x2A, 0x3A, 0x2A, 0x24, 0x00, },	//32
	{ 0x00, 0x1E, 0x22, 0x22, 0x1E, 0x0A, 0x12, 0x00, },	//33
	{ 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x0C, 0x0C, 0x00, },	//34
	{ 0x00, 0x08, 0x08, 0x08, 0x08, 0x00, 0x08, 0x00, },	//35
	{ 0x00, 0x1C, 0x26, 0x2A, 0x2A, 0x32, 0x1C, 0x00, },	//36
	{ 0x00, 0x08, 0x18, 0x08, 0x08, 0x08, 0x1C, 0x00, },	//37
	{ 0x00, 0x18, 0x24, 0x04, 0x08, 0x10, 0x3C, 0x00, },	//38
	{ 0x00, 0x38, 0x04, 0x18, 0x04, 0x04, 0x38, 0x00, },	//39
	{ 0x00, 0x04, 0x0C, 0x14, 0x24, 0x3E, 0x04, 0x00, },	//40
	{ 0x00, 0x3C, 0x20, 0x38, 0x04, 0x04, 0x38, 0x00, },	//41
	{ 0x00, 0x1C, 0x20, 0x38, 0x24, 0x24, 0x18, 0x00, },	//42
	{ 0x00, 0x3C, 0x04, 0x04, 0x08, 0x10, 0x10, 0x00, },	//43
	{ 0x00, 0x18, 0x24, 0x18, 0x24, 0x24, 0x18, 0x00, },	//44
	{ 0x00, 0x18, 0x24, 0x24, 0x1C, 0x04, 0x38, 0x00, },	//45
	{ 0x0C, 0x1E, 0x33, 0x33, 0x33, 0x33, 0x1E, 0x0C, },	//46
	{ 0x0C, 0x1C, 0x3C, 0x0C, 0x0C, 0x0C, 0x3F, 0x3F, },	//47
	{ 0x1E, 0x3F, 0x33, 0x07, 0x0E, 0x1C, 0x3F, 0x3F, },	//48
	{ 0x3F, 0x3F, 0x06, 0x0C, 0x06, 0x33, 0x3F, 0x1E, },	//49
	{ 0x33, 0x33, 0x33, 0x3F, 0x3F, 0x03, 0x03, 0x03, },	//50
	{ 0x3F, 0x3F, 0x30, 0x3E, 0x1F, 0x03, 0x3F, 0x1E, },	//51
	{ 0x1E, 0x3F, 0x30, 0x3E, 0x3F, 0x33, 0x3F, 0x1E, },	//52
	{ 0x3F, 0x3F, 0x03, 0x07, 0x0E, 0x0C, 0x0C, 0x0C, },	//53
	{ 0x1E, 0x33, 0x33, 0x1E, 0x3F, 0x33, 0x33, 0x1E, },	//54
	{ 0x1E, 0x3F, 0x33, 0x3F, 0x1F, 0x03, 0x3F, 0x1E, },	//55
	{ 0x18, 0x24, 0x24, 0x18, 0x00, 0x00, 0x00, 0x00, },	//56
	{ 0x30, 0x32, 0x04, 0x08, 0x10, 0x26, 0x06, 0x00, },	//57
	{ 0x20, 0x10, 0x08, 0x04, 0x08, 0x10, 0x20, 0x00, },	//58
};

static uint8_t default_char[FONT_HEIGHT] = 
{
    0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0xaa,
};

uint8_t font_getCharLine(uint16_t character, uint8_t lineNum, uint8_t flag)
{
    if(lineNum >= FONT_HEIGHT)
        return 0;
    
    switch(character)
    {
        case '�':
        case 'A':    
        case '�':
        case 'a':
            return pgm_read_byte(&(hexFont[0][lineNum]));
        case '�':
        case '�':
            return pgm_read_byte(&(hexFont[1][lineNum]));
        case 'B':
        case 'b':
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[2][lineNum]));
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[3][lineNum]));
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[4][lineNum]));
        case 'E':
        case 'e':
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[5][lineNum]));
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[6][lineNum]));
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[7][lineNum]));
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[8][lineNum]));
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[9][lineNum]));
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[10][lineNum]));
        case 'K':
        case 'k':
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[11][lineNum]));
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[12][lineNum]));
        case 'M':
        case 'm':
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[13][lineNum]));
        case 'H':
        case 'h':
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[14][lineNum]));
        case 'O':
        case 'o':
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[15][lineNum]));
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[16][lineNum]));
        case 'P':
        case 'p':
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[17][lineNum]));
        case 'C':
        case 'c':
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[18][lineNum]));
        case 'T':
        case 't':
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[19][lineNum]));
        case 'Y':
        case 'y':
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[20][lineNum]));
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[21][lineNum]));
        case 'X':
        case 'x':
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[22][lineNum]));
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[23][lineNum]));
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[24][lineNum]));
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[25][lineNum]));
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[26][lineNum]));
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[27][lineNum]));
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[28][lineNum]));
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[29][lineNum]));
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[30][lineNum]));
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[31][lineNum]));
        case '�':
        case '�':
        	return pgm_read_byte(&(hexFont[32][lineNum]));
        case ':':
        	return pgm_read_byte(&(hexFont[33][lineNum]));
        case '!':
        	return pgm_read_byte(&(hexFont[34][lineNum]));
        case '0':
        	if(flag == 1)
        		return pgm_read_byte(&(hexFont[45][lineNum]));
        	else
        		return pgm_read_byte(&(hexFont[35][lineNum]));
        case '1':
        	if(flag == 1)
        		return pgm_read_byte(&(hexFont[46][lineNum]));
        	else
        		return pgm_read_byte(&(hexFont[36][lineNum]));
        case '2':
        	if(flag == 1)
        		return pgm_read_byte(&(hexFont[47][lineNum]));
        	else
        		return pgm_read_byte(&(hexFont[37][lineNum]));
        case '3':
        	if(flag == 1)
        		return pgm_read_byte(&(hexFont[48][lineNum]));
        	else
        		return pgm_read_byte(&(hexFont[38][lineNum]));
        case '4':
        	if(flag == 1)
        		return pgm_read_byte(&(hexFont[49][lineNum]));
        	else
        		return pgm_read_byte(&(hexFont[39][lineNum]));
        case '5':
        	if(flag == 1)
        		return pgm_read_byte(&(hexFont[50][lineNum]));
        	else
        		return pgm_read_byte(&(hexFont[40][lineNum]));
        case '6':
        	if(flag == 1)
        		return pgm_read_byte(&(hexFont[51][lineNum]));
        	else
        		return pgm_read_byte(&(hexFont[41][lineNum]));
        case '7':
        	if(flag == 1)
        		return pgm_read_byte(&(hexFont[52][lineNum]));
        	else
        		return pgm_read_byte(&(hexFont[42][lineNum]));
        case '8':
        	if(flag == 1)
        		return pgm_read_byte(&(hexFont[53][lineNum]));
        	else
        		return pgm_read_byte(&(hexFont[43][lineNum]));
        case '9':
        	if(flag == 1)
        		return pgm_read_byte(&(hexFont[54][lineNum]));
        	else
        		return pgm_read_byte(&(hexFont[44][lineNum]));
        case '*':
        	return pgm_read_byte(&(hexFont[55][lineNum]));
        case '%':
        	return pgm_read_byte(&(hexFont[56][lineNum]));
        case ' ':
        	return 0x00;
        case '>':
            return pgm_read_byte(&(hexFont[57][lineNum]));
        default:
            return default_char[lineNum];       
    }
}