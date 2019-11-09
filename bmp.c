#include <string.h>
#include <util/delay.h>
#include "stdio.h"
#include "bmp280.h"
#include "bmp.h"
#include "twi.h"


int8_t i2c_reg_write(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length);
int8_t i2c_reg_read(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length);
void delay_ms(uint32_t period_ms);



static struct bmp280_dev bmp;

int8_t bmp_init()
{
    int8_t rslt;
    
    struct bmp280_config conf;
    
    bmp.delay_ms = delay_ms;

    /* Assign device I2C address based on the status of SDO pin (GND for PRIMARY(0x76) & VDD for SECONDARY(0x77)) */
    bmp.dev_id = BMP280_I2C_ADDR_PRIM;

    /* Select the interface mode as I2C */
    bmp.intf = BMP280_I2C_INTF;

    /* Map the I2C read & write function pointer with the functions responsible for I2C bus transfer */
    bmp.read = i2c_reg_read;
    bmp.write = i2c_reg_write;
    
    rslt = bmp280_init(&bmp);
    
    if(rslt != BMP280_OK) 
        return rslt;
    
    /* Always read the current settings before writing, especially when
     * all the configuration is not modified
     */
            
    rslt = bmp280_get_config(&conf, &bmp);
    
    if(rslt != BMP280_OK) 
        return rslt;

    /* configuring the temperature oversampling, filter coefficient and output data rate */
    /* Overwrite the desired settings */
    conf.filter = BMP280_FILTER_COEFF_2;
    
    /* Temperature oversampling set at 4x */
    conf.os_temp = BMP280_OS_1X;
    
    /* Pressure oversampling set at 4x */
    conf.os_pres = BMP280_OS_1X;

    /* Setting the output data rate as 1HZ(1000ms) */
    conf.odr = BMP280_ODR_1000_MS;
    rslt = bmp280_set_config(&conf, &bmp);
    
    if(rslt != BMP280_OK) 
        return rslt;

    /* Always set the power mode after setting the configuration */
    rslt = bmp280_set_power_mode(BMP280_FORCED_MODE, &bmp);
     
    return rslt;
}

int8_t bmp_getTemperature(int32_t * temp32)
{
    int8_t rslt;
    struct bmp280_uncomp_data ucomp_data;
    /* Reading the raw data from sensor */
    rslt = bmp280_get_uncomp_data(&ucomp_data, &bmp);
    if(rslt != BMP280_OK) 
        return rslt;
    
    /* Getting the 32 bit compensated temperature */
    rslt = bmp280_get_comp_temp_32bit(temp32, ucomp_data.uncomp_temp, &bmp);
    return rslt;
}

int8_t bmp_getPressure(uint32_t * pres32)
{
    int8_t rslt;
    struct bmp280_uncomp_data ucomp_data;
    /* Reading the raw data from sensor */
    rslt = bmp280_get_uncomp_data(&ucomp_data, &bmp);
    if(rslt != BMP280_OK) 
        return rslt;
    
    /* Getting the compensated pressure using 32 bit precision */
    rslt = bmp280_get_comp_pres_32bit(pres32, ucomp_data.uncomp_press, &bmp);
    return rslt;
}


int8_t i2c_reg_write(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length)
{
    uint8_t buffer[BMP_BUFFER_SIZE + 2];
    
    if(length > BMP_BUFFER_SIZE)
        return 1; //error
    
    buffer[0] = i2c_addr;
    buffer[1] = reg_addr << 1;
    
    memcpy(&buffer[2], reg_data, length);
    
    TWI_SendData(buffer, length + 2);    
    
    return 0;
}

int8_t i2c_reg_read(uint8_t i2c_addr, uint8_t reg_addr, uint8_t *reg_data, uint16_t length)
{
    uint8_t buffer[2];
    
    buffer[0] = i2c_addr;
    buffer[1] = reg_addr << 1;
    
    TWI_SendData(buffer, 2);
    
    buffer[1] = (reg_addr << 1) | 1;
    TWI_SendData(buffer, length + 2);
    
    TWI_GetData(reg_data, length);
    
    return 0;
}

void delay_ms(uint32_t period_ms)
{
    for(uint32_t i = 0; i < period_ms; i++)
    {
        _delay_ms(1);
    }
}
