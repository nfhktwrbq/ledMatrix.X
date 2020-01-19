#include <string.h>
#include "display.h"
#include "font.h"
#include <util/delay.h>

#include "debug.h"

static uint32_t displayBuffer[8];
static uint8_t curHours;
static uint8_t curMinutes;

uint32_t * display_getBuffer(void)
{
    return displayBuffer;
}

void display_init(void)
{
    spi_init();
    CSN_LOW();
    matrix_writeCommand(DECODE_MODE_REG, DECODE_MODE_NO_DECODE);
    CSN_HIGH();
    CSN_LOW();
    matrix_writeCommand(INTENSITY_REG, 1);
    CSN_HIGH();
    CSN_LOW();
    matrix_writeCommand(SCAN_LIMIT_REG, 7);
    CSN_HIGH();
    CSN_LOW();
    matrix_writeCommand(SHUTDOWN_REG, 1);
    CSN_HIGH();
    CSN_LOW();
    matrix_writeCommand(TEST_REG, 0);
    CSN_HIGH();
    CSN_LOW();
    matrix_writeCommand(TEST_REG, 0);
    CSN_HIGH();
    CSN_LOW();
    matrix_writeCommand(TEST_REG, 0);
    CSN_HIGH();
    CSN_LOW();
    matrix_writeCommand(TEST_REG, 0);
    CSN_HIGH();
}

void display_setIntensity(uint8_t intensity)
{
    if(intensity > 16)
    {
        intensity = 16;
    }
    for(uint8_t i = 0; i < MATRIX_NUM; i++)
    {        
        CSN_LOW();
        matrix_writeCommand(INTENSITY_REG, intensity);
        CSN_HIGH();
    }
    display_show();
}
  
void display_show(void)
{
   for(uint8_t i = 0; i < MATRIX_HEIGHT; i++)
    {
        CSN_LOW();
        for(int8_t j = 3; j >= 0; j--)
        {
            matrix_writeDigit(i + 1,(uint8_t)((displayBuffer[i] >> 8 * j) & 0x000000ffUL));
        }
        CSN_HIGH();
    } 
}
  
void display_clear(void)
{
    memset(displayBuffer, 0, sizeof(displayBuffer));
}

void display_addCharToPosition(char c, int8_t pos, uint8_t flag)
{
    uint8_t line;
    int8_t offset;
    
    if(pos > MATRIX_NUM * MATRIX_WIDTH || pos < -FONT_WIDTH)
        return;
    
    offset = (MATRIX_NUM * MATRIX_WIDTH - 6 - pos);
    for(uint8_t i = 0; i < FONT_HEIGHT; i++)
    {
        line = font_getCharLine(c, i, flag);
        if(offset > 0)
        {
            displayBuffer[i] |= (((uint32_t)line) << offset);
        }
        else
        {
            displayBuffer[i] |= (line >> (-offset));
        }
    }
}

void display_setText(char * str, int16_t startBit)
{
    display_clear();
    uint8_t startCharIndex = 0;
    if(startBit <= 0 )
    {
        startCharIndex = -startBit / (FONT_WIDTH + LETTER_SPACE);
    }
    
    for(uint8_t i = startCharIndex; str[i] != 0 && (FONT_WIDTH + LETTER_SPACE) * i + startBit < MATRIX_NUM * MATRIX_WIDTH; i++)
    {
        display_addCharToPosition(str[i], (FONT_WIDTH + LETTER_SPACE) * i + startBit, 0);
    }
}
/*
void display_setText(char * str, uint8_t startBit)
{
    uint8_t line;
    uint8_t startCharIndex = startBit / (FONT_WIDTH + LETTER_SPACE);
    int8_t offset;
    uint8_t stringLen = strlen(str);
 
    for(uint8_t i = 0; i < FONT_HEIGHT; i++)
    {
        displayBuffer[i] = 0;
        
        for(uint8_t j = 0; j <= (MATRIX_NUM * MATRIX_WIDTH / (FONT_WIDTH + LETTER_SPACE)) + 1; j++)
        {
            if(startCharIndex + j >= stringLen)
            {
                break;
            }
            line = font_getCharLine(str[startCharIndex + j], i, 0);
            offset = (startBit % (FONT_WIDTH + LETTER_SPACE)) + (MATRIX_NUM * MATRIX_WIDTH - (FONT_WIDTH + LETTER_SPACE) * (j + 1));
            if(offset > 0)
            {
                displayBuffer[i] |= (((uint32_t)line) << offset);
            }
            else
            {
                offset = -offset;
                displayBuffer[i] |= (line >> offset);
            }
        }        
    }    
}
*/

void display_clockColonSwitch(bool isOn)
{
    if(isOn)
    {
        displayBuffer[1] |= 0x00018000;
        displayBuffer[2] |= 0x00018000;
        displayBuffer[5] |= 0x00018000;
        displayBuffer[6] |= 0x00018000;
    }
    else
    {
        displayBuffer[1] &= ~0x00018000;
        displayBuffer[2] &= ~0x00018000;
        displayBuffer[5] &= ~0x00018000;
        displayBuffer[6] &= ~0x00018000;
    }
}

void display_partiallyClear(uint32_t part)
{
    for(uint8_t i = 0; i < 8; i++)
    {
        displayBuffer[i] &= ~part;
    }
}

void display_clearTimeDigit(uint8_t digit)
{
    switch(digit)
    {
        case 0:
            display_partiallyClear(0x000000ff);
        break;
        case 1:
            display_partiallyClear(0x00007f00);
        break;
        case 2:
            display_partiallyClear(0x00fe0000);
        break;
        case 3:
            display_partiallyClear(0xff000000);
        break;
    }
}

void display_setTimeText(uint8_t hoursBCD, uint8_t minutesBCD)
{
    curHours = hoursBCD;
    curMinutes = minutesBCD;
    display_partiallyClear(0xfffe7fff);
    display_addCharToPosition((hoursBCD >> 4) + 0x30, 1, 1);
    display_addCharToPosition((hoursBCD & 0x0f) + 0x30, FONT_WIDTH + 2, 1);
    //display_addCharToPosition(':', FONT_WIDTH * 2 + 1, 0);
    display_addCharToPosition((minutesBCD >> 4) + 0x30, FONT_WIDTH * 3, 1);
    display_addCharToPosition((minutesBCD & 0x0f) + 0x30, FONT_WIDTH * 4 + 1, 1);
}
 
void display_rollTimeText1(uint8_t hoursBCD, uint8_t minutesBCD, uint8_t frame)
{
    uint8_t hours, minutes;
    uint8_t line;
    if(curHours == hoursBCD && curMinutes == minutesBCD)
        return;
    
    for(uint8_t i = 0; i < 8; i++)
    {
        displayBuffer[i] &= 0x00018000;
    }
    
    for(uint8_t i = 0; i < 8; i++)
    {
        if(i <= frame)
        {
            minutes = minutesBCD;
            hours = hoursBCD;
        }
        else
        {
            minutes = curMinutes;
            hours = curHours;
        }
        
        line = font_getCharLine((hours >> 4) + 0x30, i, 1);        
        displayBuffer[i] |= (((uint32_t)line) << (int8_t)(MATRIX_NUM * MATRIX_WIDTH - 7));
        line = font_getCharLine((hours & 0x0f) + 0x30, i, 1);        
        displayBuffer[i] |= (((uint32_t)line) << (int8_t)(MATRIX_NUM * MATRIX_WIDTH - 8 - FONT_WIDTH));
        line = font_getCharLine((minutes >> 4) + 0x30, i, 1);        
        displayBuffer[i] |= (((uint32_t)line) << (int8_t)(MATRIX_NUM * MATRIX_WIDTH - 6 - FONT_WIDTH * 3));
        line = font_getCharLine((minutes & 0x0f) + 0x30, i, 1);        
        displayBuffer[i] |= (((uint32_t)line) << (int8_t)(MATRIX_NUM * MATRIX_WIDTH - 7 - FONT_WIDTH * 4));
    }
    
    if(frame == MATRIX_HEIGHT - 1)
    {
        curHours = hoursBCD;
        curMinutes = minutesBCD;
    }
}

bool display_rollTimeText2(uint8_t hoursBCD, uint8_t minutesBCD, uint8_t frame)
{
 
    uint8_t line;
    if((curHours == hoursBCD && curMinutes == minutesBCD) || frame > LETTER_SPACE_V + FONT_HEIGHT - 1 )
        return false;
    
    for(uint8_t i = 7; i != 0; i--)
    {
        if((curHours >> 4) != (hoursBCD >> 4))
        {
            displayBuffer[i] = (displayBuffer[i] & 0x00ffffff) | (displayBuffer[i - 1] & 0xff000000);
        }
        if((curHours & 0x0f) != (hoursBCD & 0x0f))
        {
            displayBuffer[i] = (displayBuffer[i] & 0xff01ffff) | (displayBuffer[i - 1] & 0x00fe0000);
        }
        if((curMinutes >> 4) != (minutesBCD >> 4))
        {
            displayBuffer[i] = (displayBuffer[i] & 0xffff80ff) | (displayBuffer[i - 1] & 0x00007f00);
        }
        if((curMinutes & 0x0f) != (minutesBCD & 0x0f))
        {
            displayBuffer[i] = (displayBuffer[i] & 0xffffff00) | (displayBuffer[i - 1] & 0x000000ff);
        }
    }
    
    if(frame >= LETTER_SPACE_V)
    {
        if((curHours >> 4) != (hoursBCD >> 4))
        {
            line = font_getCharLine((hoursBCD >> 4) + 0x30, FONT_HEIGHT - 1 - (frame - LETTER_SPACE_V), 1);
            displayBuffer[0] = (displayBuffer[0] & 0x00ffffff) | (((uint32_t)line) << 25);
        }
        if((curHours & 0x0f) != (hoursBCD & 0x0f))
        {
            line = font_getCharLine((hoursBCD & 0x0f) + 0x30, FONT_HEIGHT - 1 - (frame - LETTER_SPACE_V), 1);
            displayBuffer[0] = (displayBuffer[0] & 0xff01ffff) | (((uint32_t)line) << 18);
        }
        if((curMinutes >> 4) != (minutesBCD >> 4))
        {
            line = font_getCharLine((minutesBCD >> 4) + 0x30, FONT_HEIGHT - 1 - (frame - LETTER_SPACE_V), 1);
            displayBuffer[0] = (displayBuffer[0] & 0xffff80ff) | (((uint32_t)line) << 8);
        }
        if((curMinutes & 0x0f) != (minutesBCD & 0x0f))
        {
            line = font_getCharLine((minutesBCD & 0x0f) + 0x30, FONT_HEIGHT - 1 - (frame - LETTER_SPACE_V), 1);
            displayBuffer[0] = (displayBuffer[0] & 0xffffff00) | (((uint32_t)line) << 1);
        }
    }
    else
    {
        if((curHours >> 4) != (hoursBCD >> 4))
        {
            displayBuffer[0] = 0x00ffffff & displayBuffer[0];
        }
        if((curHours & 0x0f) != (hoursBCD & 0x0f))
        {
            displayBuffer[0] = displayBuffer[0] & 0xff01ffff;
        }
        if((curMinutes >> 4) != (minutesBCD >> 4))
        {
            displayBuffer[0] = displayBuffer[0] & 0xffff80ff;
        }
        if((curMinutes & 0x0f) != (minutesBCD & 0x0f))
        {
            displayBuffer[0] = displayBuffer[0] & 0xffffff00;
        }
    }
        
    if(frame == LETTER_SPACE_V + FONT_HEIGHT - 1)
    {
        curHours = hoursBCD;
        curMinutes = minutesBCD;
    }
    return true;
}

void test_rool(void)
{
    display_setTimeText(0x12, 0x33);
    display_show();
    _delay_ms(3000);
    for(uint8_t i = 0; i < 9; i++)
    {
        display_rollTimeText2(0x12, 0x35, i);
        display_show();
        _delay_ms(500);
    }
    for(uint8_t i = 0; i < 9; i++)
    {
        display_rollTimeText2(0x23, 0x14, i);
        display_show();
        _delay_ms(500);
    }
}

