#include <avr/io.h>
#include <avr/interrupt.h>

#include "adc.h"


volatile static uint8_t avg[AVERAGE_SIZE];

ISR(ADC_vect)
{    
    static uint8_t index = 0;
    avg[index] = ADCH;
    index++;
    if(index >= AVERAGE_SIZE)
    {
        index = 0;
    }
}

void adc_init(void)
{
    ADMUX = (1 << REFS0) | (1 << ADLAR);
    ADCSRA = (1 << ADEN) | (1 << ADATE) | (1 << ADIE);
    ADCSRB = (1 << ADTS2) | (1 << ADTS1); //timer1 ovfl
}

uint8_t adc_get(void)
{
    uint16_t average = 0;
    for(int i = 0; i < AVERAGE_SIZE; i++)
    {
        average += avg[i]; 
    }
    return (uint8_t)(average / 3);
}

