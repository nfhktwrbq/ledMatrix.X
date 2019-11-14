
#include <avr/io.h>
#include <avr/interrupt.h>
#include "spi.h"


void spi_init()
// Initialize pins for spi communication
{
	DDR_SPI &= ~((1<<DD_MOSI)|(1<<DD_MISO)|(1<<DD_SS)|(1<<DD_SCK));
	// Define the following pins as output
	DDR_SPI |= ((1<<DD_MOSI)|(1<<DD_SS)|(1<<DD_SCK));

	
	SPCR = ((1<<SPE)|               // SPI Enable
	(0<<SPIE)|              // SPI Interupt Enable
	(0<<DORD)|              // Data Order (0:MSB first / 1:LSB first)
	(1<<MSTR)|              // Master/Slave select
	(0<<SPR1)|(0<<SPR0)|    // SPI Clock Rate
	(0<<CPOL)|              // Clock Polarity (0:SCK low / 1:SCK hi when idle)
	(0<<CPHA));             // Clock Phase (0:leading / 1:trailing edge sampling)

	SPSR = (1<<SPI2X);              // Double Clock Rate
	CSN_HIGH();
	
}

void spi_transfer_sync (unsigned char * dataout, unsigned char * datain, unsigned char len)
// Shift full array through target device
{
    //CSN_LOW();
	unsigned char i;
	for (i = 0; i < len; i++) {
		SPDR = dataout[i];
		while((SPSR & (1<<SPIF))==0);
		datain[i] = SPDR;
	}
    //CSN_HIGH();
}

void spi_transmit_sync (unsigned char * dataout, unsigned char len)
// Shift full array to target device without receiving any byte
{
	unsigned char i;
    //CSN_LOW();
	for (i = 0; i < len; i++) {
		SPDR = dataout[i];
		while((SPSR & (1<<SPIF))==0);
	}
    //CSN_HIGH();
}

unsigned char spi_fast_shift (unsigned char data)
// Clocks only one byte to target device and returns the received one
{
    //CSN_LOW();
	SPDR = data;
	while((SPSR & (1<<SPIF))==0);
    //CSN_HIGH();
	return SPDR;
}



