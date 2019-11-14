#include <string.h>
#include <util/delay.h>
#include "bme280.h"
#include "bme.h"
#include "twi.h"
#include "timer.h"

#define BME_BUFFER_SIZE             TWI_BUFFER_SIZE

int8_t user_i2c_read(uint8_t id, uint8_t reg_addr, uint8_t *data, uint16_t len);
void user_delay_ms(uint32_t period);
int8_t user_i2c_write(uint8_t id, uint8_t reg_addr, uint8_t *data, uint16_t len);

static struct bme280_dev dev;
static TTimer bme_measure_timer;
static struct bme280_data comp_data;

int8_t bme_init(void)
{
    int8_t rslt;
    uint8_t settings_sel;
    
    dev.dev_id = BME280_I2C_ADDR_PRIM;    
    dev.intf = BME280_I2C_INTF;
    dev.read = user_i2c_read;
    dev.write = user_i2c_write;
    dev.delay_ms = user_delay_ms;
    
    rslt = bme280_init(&dev);    
    if (rslt != BME280_OK)
        return rslt;
    
    dev.settings.osr_h = BME280_OVERSAMPLING_1X;
    dev.settings.osr_p = BME280_OVERSAMPLING_16X;
    dev.settings.osr_t = BME280_OVERSAMPLING_2X;
    dev.settings.filter = BME280_FILTER_COEFF_16;
    
    settings_sel = BME280_OSR_PRESS_SEL | BME280_OSR_TEMP_SEL | BME280_OSR_HUM_SEL | BME280_FILTER_SEL;

    rslt = bme280_set_sensor_settings(settings_sel, &dev);
    timer_stop(&bme_measure_timer);
	if(rslt == BME280_OK)
    {
        timer_start(&bme_measure_timer, BME_MEASURE_TIMEOUT);
    }
    
    return rslt;    
}

int8_t bme_proc(void)
{
    static TTimer bme_conversion_timer;
    static uint8_t bme_state = 0;
    int8_t rslt;
    
    switch(bme_state)
    {
        case 0:
            if(timer_check(&bme_measure_timer))
            {
                rslt = bme280_set_sensor_mode(BME280_FORCED_MODE, &dev);
                if (rslt != BME280_OK)
                    return rslt;
                
                timer_start(&bme_conversion_timer, BME_CONVERSION_TIMEOUT);
                bme_state = 1;
            }
            break;
        case 1:
            if(timer_check(&bme_conversion_timer))
            {
                bme_state = 0;
                rslt = bme280_get_sensor_data(BME280_ALL, &comp_data, &dev);
                if (rslt != BME280_OK)
                    return rslt;
            }
            break;
        default:
            bme_state = 0;
    }
    return BME280_OK;
}

float  bme_getPressure(void)
{
    return 0.0001f * comp_data.pressure;
}

float  bme_getTemperature(void)
{
    return 0.01f * comp_data.temperature;
}

float bme_getHumidity(void)
{
    return 1.0f / 1024.0f * comp_data.humidity;
}

uint32_t  bme_getPressure32(void)
{
    return comp_data.pressure;
}

int32_t  bme_getTemperature32(void)
{
    return comp_data.temperature;
}

uint32_t bme_getHumidity32(void)
{
    return comp_data.humidity;
}

int8_t user_i2c_read(uint8_t id, uint8_t reg_addr, uint8_t *data, uint16_t len)
{
    uint8_t buffer[BME_BUFFER_SIZE + 2];
    
    buffer[0] = id << 1;
    buffer[1] = reg_addr;
    
    TWI_SendData(buffer, 2);
    
    buffer[0] = (id << 1) | 1;
    TWI_SendData(buffer, len + 1);
    
    TWI_GetData(buffer, len + 1);
    memcpy(data, &buffer[1], len);    
    
    return BME280_OK;
}

void user_delay_ms(uint32_t period)
{
    for(uint32_t i = 0; i < period; i++)
    {
        _delay_ms(1);
    }
}

int8_t user_i2c_write(uint8_t id, uint8_t reg_addr, uint8_t *data, uint16_t len)
{
    uint8_t buffer[BME_BUFFER_SIZE + 2];
    
    if(len > BME_BUFFER_SIZE)
        return 1; //error
    
    buffer[0] = id << 1;
    buffer[1] = reg_addr;
    
    memcpy(&buffer[2], data, len);
    
    TWI_SendData(buffer, len + 2);    
    
	return BME280_OK;
}
