//***************************************************************************
//
//  Author(s)...: ����� ������  http://ChipEnable.Ru   
//
//  Target(s)...: mega16
//
//  Compiler....: GCC
//
//  Description.: ������� �������� TWI ����������. 
//                ��� ������� �� Atmel`������ ����� - AVR315.
//
//  Data........: 13.11.13
//
//***************************************************************************
#include "twi.h"
#include "timer.h"

#define TWSR_MASK     0xfc  

volatile static uint8_t twiBuf[TWI_BUFFER_SIZE];
volatile static uint8_t twiState = TWI_NO_STATE;      
volatile static uint8_t twiMsgSize;       

/*������������ ��� ��������� �������� ������ twi ������*/
uint8_t pre[4] = {2, 8, 32, 128};

/****************************************************************************
 ������������� � ��������� ������� SCL �������
****************************************************************************/
uint8_t TWI_MasterInit(uint16_t fr)
{
  uint8_t i;
  uint16_t twbrValue;
  
  for(i = 0; i<4; i++){
    twbrValue = ((((F_CPU)/1000UL)/fr)-16)/pre[i];
    if ((twbrValue > 0)&& (twbrValue < 256)){
       TWBR = (uint8_t)twbrValue;
       TWSR = i;
       TWDR = 0xFF;
       TWCR = (1<<TWEN);
       return TWI_SUCCESS;
    }
  }
  return 0;  
}    

/****************************************************************************
 �������� - �� ����� �� TWI ������. ������������ ������ ������
****************************************************************************/
static uint8_t TWI_TransceiverBusy(void)
{
  return (TWCR & (1<<TWIE));                 
}

/****************************************************************************
 ����� ������ TWI ������
****************************************************************************/
uint8_t TWI_GetState(void)
{
  TTimer timer;
  timer_start(&timer, TWI_TIMEOUT);
  while (TWI_TransceiverBusy() && !timer_check(&timer));

  if(timer_check(&timer))  
  {
    twiState = TWI_TIMEOUT_EXCEEDED;
  }           
  return twiState;                        
}

/****************************************************************************
 �������� ��������� msg �� msgSize ������ �� TWI ����
****************************************************************************/
void TWI_SendData(uint8_t *msg, uint8_t msgSize)
{
  uint8_t i;
  TTimer timer;
  timer_start(&timer, TWI_TIMEOUT);
  while(TWI_TransceiverBusy() && !timer_check(&timer));   //����, ����� TWI ������ �����������             
  if(timer_check(&timer))  
  {
    twiState = TWI_TIMEOUT_EXCEEDED;
    return twiState;
  }  

  twiMsgSize = msgSize;           //��������� ���. ���� ��� ��������             
  twiBuf[0]  = msg[0];            //� ������ ���� ��������� 
  
  if (!(msg[0] & (TRUE<<TWI_READ_BIT))){   //���� ������ ���� ���� SLA+W
    for (i = 1; i < msgSize; i++){         //�� ��������� ��������� ����� ���������
      twiBuf[i] = msg[i];
    }
  }
                       
  twiState = TWI_NO_STATE ;
  TWCR = (1<<TWEN)|(1<<TWIE)|(1<<TWINT)|(1<<TWSTA); //��������� ���������� � ��������� ��������� �����                            
}

/****************************************************************************
 ���������� ���������� ������ � ����� msg � ���������� msgSize ����. 
****************************************************************************/
uint8_t TWI_GetData(uint8_t *msg, uint8_t msgSize)
{
  uint8_t i;
  TTimer timer;
  timer_start(&timer, TWI_TIMEOUT);
  while(TWI_TransceiverBusy() && !timer_check(&timer));    //����, ����� TWI ������ ����������� 
  if(timer_check(&timer))  
  {
    twiState = TWI_TIMEOUT_EXCEEDED;
    return twiState;
  } 
  
  if(twiState == TWI_SUCCESS){     //���� ��������� ������� �������,                         
    for(i = 0; i < msgSize; i++){  //�� ������������ ��� �� ����������� ������ � ����������
      msg[i] = twiBuf[i];
    }
  }
  
  return twiState;                                   
}

/****************************************************************************
 ���������� ���������� TWI ������
****************************************************************************/
ISR(TWI_vect)
{
  static uint8_t ptr;
  uint8_t stat = TWSR & TWSR_MASK;
  
  switch (stat){
    
    case TWI_START:                   // ��������� START ������������ 
    case TWI_REP_START:               // ��������� ��������� START ������������        
       ptr = 0;      

    case TWI_MTX_ADR_ACK:             // ��� ������� ����� SLA+W � �������� �������������
    case TWI_MTX_DATA_ACK:            // ��� ������� ���� ������ � �������� �������������  
       if (ptr < twiMsgSize){
          TWDR = twiBuf[ptr];                    //��������� � ������� ������ ��������� ����
          TWCR = (1<<TWEN)|(1<<TWIE)|(1<<TWINT); //���������� ���� TWINT    
          ptr++;
       }
       else{
          twiState = TWI_SUCCESS;  
          TWCR = (1<<TWEN)|(1<<TWINT)|(1<<TWSTO)|(0<<TWIE); //��������� ��������� ����, ���������� ����, ��������� ����������
       }
       break;
     
    case TWI_MRX_DATA_ACK:          //���� ������ ������ � �������� �������������  
       twiBuf[ptr] = TWDR;
       ptr++;
    
    case TWI_MRX_ADR_ACK:           //��� ������� ����� SLA+R � �������� ������������  
      if (ptr < (twiMsgSize-1)){
        TWCR = (1<<TWEN)|(1<<TWIE)|(1<<TWINT)|(1<<TWEA);  //���� ��� �� ������������� �������� ����, ��������� �������������                             
      }
      else {
        TWCR = (1<<TWEN)|(1<<TWIE)|(1<<TWINT);            //���� ������� ������������� ����, ������������� �� ���������
      }    
      break; 
      
    case TWI_MRX_DATA_NACK:       //��� ������ ���� ������ ��� �������������      
      twiBuf[ptr] = TWDR;
      twiState = TWI_SUCCESS;  
      TWCR = (1<<TWEN)|(1<<TWINT)|(1<<TWSTO); //��������� ��������� ����
      break; 
     
    case TWI_ARB_LOST:          //��� ������� ��������� 
      TWCR = (1<<TWEN)|(1<<TWIE)|(1<<TWINT)|(1<<TWSTA); // ���������� ���� TWINT, ��������� ��������� �����
      break;
      
    case TWI_MTX_ADR_NACK:      // ��� ������� ���� SLA+W � �� �������� �������������
    case TWI_MRX_ADR_NACK:      // ��� ������� ����� SLA+R � �� �������� �������������    
    case TWI_MTX_DATA_NACK:     // ��� ������� ���� ������ � �� �������� �������������
    case TWI_BUS_ERROR:         // ������ �� ���� ��-�� ����������� ��������� ����� ��� ����
    default:     
      twiState = stat;                                                                                    
      TWCR = (1<<TWEN)|(0<<TWIE)|(0<<TWINT)|(0<<TWEA)|(0<<TWSTA)|(0<<TWSTO)|(0<<TWWC); //��������� ����������                              
  }
}
