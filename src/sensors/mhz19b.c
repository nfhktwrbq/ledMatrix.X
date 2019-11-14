#include <string.h>
#include "mhz19b.h"
#include "uart.h"
#include "timer.h"
#include "ring_buffer.h"

static uint16_t co2concentration;

typedef enum{
    NONE,
    START_MEASURE,
    WAIT_FOR_ANSWER,
    MAKE_ZERO_CALIBRATION,
    MAKE_SPAN_CALIBRATION,
    SET_AUTOCALIBRATION,        
} TMHZ19B_State;

char getCheckSum(char * packet)
{
    uint8_t i;
    char checksum = 0;
    for( i = 1; i < 8; i++)
    {
        checksum += packet[i];
    }
    checksum = 0xff - checksum;
    checksum += 1;
    return checksum;
}

void mhz19b_init()
{
    uart_init(9600);
    mhz19b_sendCommand(DETECTION_RANGE, 5000);
    mhz19b_sendCommand(AUTO_CALIBRATION, AUTO_CALIBRATION_OFF);
}

void mhz19b_sendCommand(uint8_t cmd, uint16_t parameter)
{
    TMHA19BPacket pkt;
    
    memset(&pkt, 0, sizeof(pkt));
    pkt.startByte = START_BYTE;
    pkt.sensor = SENSOR;
    pkt.content[0] = cmd;
    switch(cmd)
    {
        case DETECTION_RANGE:       
            if(parameter != 2000 || parameter != 5000)
                return;
            
            pkt.content[4] = (uint8_t)(parameter >> 8);
            pkt.content[5] = (uint8_t)(parameter & 0x00ff);           
            break;
        case AUTO_CALIBRATION:
            pkt.content[1] = (uint8_t)(parameter & 0x00ff);
        case CALIBRATE_ZERO_POINT:
        case READ_CO2_CONCENTRATION:
            break;
        case CALIBRATE_SPAN_POINT:
            if(parameter != 2000 || parameter != 5000)
                return;
            pkt.content[1] = (uint8_t)(parameter >> 8);
            pkt.content[2] = (uint8_t)(parameter & 0x00ff);
            break;
        default:
            return;
    }
    
    pkt.crc = getCheckSum((char *) &pkt);
    uart_rb_send_bytes((uint8_t *)&pkt, sizeof(pkt));
}

void mhz19b_proc(void)
{
    static TMHZ19B_State state = NONE;
    static TTimer mhz19b_timer;
    
    switch(state){
        case NONE:
            state = START_MEASURE;
            break;
        case START_MEASURE:
            timer_start(&mhz19b_timer, MEASURE_TIMEOUT);
            mhz19b_sendCommand(READ_CO2_CONCENTRATION, 0);
            state = WAIT_FOR_ANSWER;
            break;
        case WAIT_FOR_ANSWER:
            if(timer_check(&mhz19b_timer))
            {
                uint8_t answ[RING_BUFFER_SIZE + 1];
                uint8_t len;
                uart_rb_receive_bytes(answ, &len);
                if(len)
                {
                    uint8_t concentrationSubstring[3] = {0xff, 0x86, 0x00};
                    answ[len] = 0x00;                    
                    char * pch = strstr((const char *)answ, (const char *)concentrationSubstring);
                    if(pch)
                    {
                        pch += 2;
                        co2concentration = pch[0] * 256 + pch[1];
                    }
                }
                state = START_MEASURE;
            }            
            break;
        default:
            state = START_MEASURE;
    }
}

uint16_t mhz19b_getCO2Concentration(void)
{  
    return co2concentration;
}