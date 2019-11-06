#ifndef TWI_H_
#define TWI_H_

void twi_init(void);
void twi_write(unsigned char adrWord, unsigned char data, unsigned char adres);
void twi_writeBytes(unsigned char adres, unsigned char adrWord, unsigned char * buf, unsigned char len);
unsigned char twi_read(unsigned char wordAdr, unsigned char adres);
void twi_readBytes(unsigned char adres, unsigned char wordAdr, unsigned char * buf, unsigned char len);

#endif /* TWI_H_ */