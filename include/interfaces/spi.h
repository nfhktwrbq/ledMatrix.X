/* 
 * File:   spi.h
 * Author: muaddib
 *
 * Created on October 27, 2019, 2:09 PM
 */

#ifndef SPI_H
#define	SPI_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <avr/io.h>


#define PORT_SPI    PORTB
#define DDR_SPI     DDRB
#define DD_MISO     DDB4

#define DD_MOSI     DDB3
#define DD_SS       DDB2
#define DD_SCK      DDB5
    
#define CSN_HIGH() (PORT_SPI |= (1 << DD_SS))
#define CSN_LOW() (PORT_SPI &= ~(1 << DD_SS))

void spi_init();
void spi_transfer_sync (unsigned char* dataout, unsigned char * datain, unsigned char len);
void spi_transmit_sync (unsigned char * dataout, unsigned char len);
unsigned char spi_fast_shift (unsigned char data);


  
#ifdef	__cplusplus
}
#endif

#endif	/* SPI_H */

