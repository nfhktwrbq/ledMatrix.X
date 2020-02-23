/* 
 * File:   font.h
 * Author: muaddib
 *
 * Created on October 27, 2019, 2:09 PM
 */

#ifndef FONT_H
#define	FONT_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define FONT_HEIGHT     8    
#define FONT_WIDTH      6
#define MAX_CHAR_NUM    63
    
uint8_t font_getCharLine(uint16_t character, uint8_t lineNum, uint8_t flag); 
 
#ifdef	__cplusplus
}
#endif

#endif	/* FONT_H */