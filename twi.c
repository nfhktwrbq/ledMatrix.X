#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

void twi_init(void)
{
    SREG |= 0b10000000;
    TWBR = 0x10;//bit rate (then less then faster scl)		
    TWCR |= 0b11000100;//TWINT cleared, TWEN - set to one (enable twi), TWIE - enable interrupts
    TWSR &= 0b11111100;//prescaller = 1;
    //TWSR |= 0b00000011;//prescaller = 4;
		
}

void twi_write(unsigned char adrWord, unsigned char data, unsigned char adres )
{
    adres <<= 1;
	TWCR |= 0b10100100; // send START cond (TWINT, TWSTA, TWEN ==1)
	TWCR &= 0b11101111;//STo=0	
	while(!(TWCR & 0b10000000));//waiting to set (to low) TWINT;

	TWDR = adres;//adr ds1307 is 1101000 and w-0
	TWCR &= 0b11001111;
	TWCR |= 0b10000100;//clear TWINT
	while(!(TWCR & 0b10000000));//waiting to set (to low) TWINT;
	
	TWDR = adrWord;//load word adr secs	
	TWCR |= 0b10000100;//clear TWINT
	while(!(TWCR & 0b10000000));//waiting to set (to low) TWINT;

	TWDR = data;//load word adr secs	
	TWCR |= 0b10000100;//clear TWINT
	while(!(TWCR & 0b10000000));//waiting to set (to low) TWINT;

	TWCR |= 0b10010100;//clear TWINT, TWSto
}


void twi_writeBytes(unsigned char adres, unsigned char adrWord, unsigned char * buf, unsigned char len)
{
	unsigned char i=0;
    adres <<= 1;
	TWCR |= 0b10100100; // send START cond (TWINT, TWSTA, TWEN ==1)
	TWCR &= 0b11101111;//STo=0
	while(!(TWCR & 0b10000000));//waiting to set (to low) TWINT;

	TWDR = adres;//adr ds1307 is 1101000 and w-0
	TWCR &= 0b11001111;
	TWCR |= 0b10000100;//clear TWINT
	while(!(TWCR & 0b10000000));//waiting to set (to low) TWINT;
	
	TWDR = adrWord;//load word adr secs
	TWCR |= 0b10000100;//clear TWINT
	while(!(TWCR & 0b10000000));//waiting to set (to low) TWINT;
    
	for(i = 0; i < len; i++)
	{
        TWDR = buf[i];//load word adr secs
        TWCR |= 0b10000100;//clear TWINT
        while(!(TWCR & 0b10000000));//waiting to set (to low) TWINT;
	}

	TWCR |= 0b10010100;//clear TWINT, TWSto
}



unsigned char twi_read(unsigned char wordAdr, unsigned char adres)
{
	
	unsigned char tbufer=0;
    adres <<= 1;
    adres++;
	TWCR =0;
	TWCR |= 0b10100100; // send START cond (TWINT, TWSTA, TWEN ==1)
	TWCR &= 0b11101111;//STo=0	
	while(!(TWCR & 0b10000000));//waiting to set (to low) TWINT;

	TWDR = adres;//adr ds1307 is 1101000 and w-0
	TWCR &= 0b11001111;//sta=0
	//TWCR =0;
	TWCR |= 0b10000100;//clear TWINT
	while(!(TWCR & 0b10000000));//waiting to set (to low) TWINT;

	TWDR = wordAdr;//load word adr secs
	TWCR |= 0b10000100;//clear TWINT	
	while(!(TWCR & 0b10000000));//waiting to set (to low) TWINT;
			
	TWCR |= 0b10100100; // send START cond (TWINT, TWSTA, TWEN ==1)		
	while(!(TWCR & 0b10000000));//waiting to set (to low) TWINT;

	TWDR = adres+1;//adr ds1307 is 1101000 and r-1
	TWCR &= 0b11001111;//sta=0
	//TWCR = 0;
	TWCR |= 0b10000100;//clear TWINT
	while(!(TWCR & 0b10000000));//waiting to set (to low) TWINT;
	
	TWCR &= 0b10111111;
	TWCR |= 0b10000100;
	while(!(TWCR & 0b10000000));//waiting to set (to low) TWINT;
	tbufer=TWDR;
	TWCR |= 0b10010100;//clear TWINT, TWSto	
	return tbufer;
}

void twi_readBytes(unsigned char adres, unsigned char wordAdr, unsigned char * buf, unsigned char len)
{
    unsigned char i = 0;
    //TWCR =0;	
    adres <<= 1;
    TWCR |= 0b10100100; // send START cond (TWINT, TWSTA, TWEN ==1)
    TWCR &= 0b11101111;//STo=0
    while(!(TWCR & 0b10000000));//waiting to set (to low) TWINT;

    TWDR = adres;//adr ds1307 is 1101000 and w-0
    TWCR &= 0b11001111;//sta=0		
    TWCR |= 0b10000100;//clear TWINT
    while(!(TWCR & 0b10000000));//waiting to set (to low) TWINT;

    TWDR = wordAdr;//load word adr 
    TWCR |= 0b10000100;//clear TWINT
    while(!(TWCR & 0b10000000));//waiting to set (to low) TWINT;

    TWCR |= 0b10100100; // send START cond (TWINT, TWSTA, TWEN ==1)
    while(!(TWCR & 0b10000000));//waiting to set (to low) TWINT;

    TWDR = adres + 1;//adr ds1307 is 1101000 and r-1
    TWCR &= 0b11001111;//sta=0		
    TWCR |= 0b10000100;//clear TWINT
    while(!(TWCR & 0b10000000));//waiting to set (to low) TWINT;
    
    for(i = 0; i < len - 1; i++)
    {
        TWCR |= 0b11000100;
        while(!(TWCR & 0b10000000));//waiting to set (to low) TWINT;
        buf[i] = TWDR;
    }
    TWCR &= 0b10111111;
    TWCR |= 0b10000100;
    while(!(TWCR & 0b10000000));//waiting to set (to low) TWINT;
    buf[len - 1] = TWDR;		
    TWCR |= 0b10010100;//clear TWINT, TWSto		
}