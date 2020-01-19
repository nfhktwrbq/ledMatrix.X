/* 
 * File:   at24c32.h
 * Author: muaddib
 *
 * Created on October 27, 2019, 2:09 PM
 */

#ifndef AT24C32_H
#define	AT24C32_H

#ifdef	__cplusplus
extern "C" {
#endif

#define AT24C32_ADDR	0x50
#define AT24C32_BUFFER_SIZE TWI_BUFFER_SIZE

void at24c32_writeByte(uint8_t id, uint16_t mem_addr, uint8_t data);
void at24c32_writeBytes(uint8_t id, uint16_t mem_addr, uint8_t * data, uint8_t len);
uint16_t at24c32_readCurrentAddress(uint8_t id);
void at24c32_readBytes(uint8_t id, uint16_t mem_addr, uint8_t * data, uint8_t len);
uint8_t at24c32_getState(void);

#ifdef	__cplusplus
}
#endif

#endif	/* AT24C32_H */
