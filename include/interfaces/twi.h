//***************************************************************************
//
//  Author(s)...: Ïàâåë Áîáêîâ  http://ChipEnable.Ru   
//
//  Target(s)...: mega16
//
//  Compiler....: GCC
//
//  Description.: Äðàéâåð âåäóùåãî TWI óñòðîéñòâà. 
//                Êîä îñíîâàí íà Atmel`îâñêèõ äîêàõ - AVR315.
//
//  Data........: 13.11.13
//
//***************************************************************************
#ifndef TWIM_H
#define TWIM_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

/****************************************************************************
  Íàñòðîéêè ìîäóëÿ
****************************************************************************/

/*åñëè íå îïðåäåëåíà òàêòîâàÿ 
÷àñòîòà, îïðåäåëÿåì åå çäåñü*/
#ifndef F_CPU
   #define F_CPU  16000000UL
#endif

/*ðàçìåð áóôåðà TWI ìîäóëÿ*/
#define TWI_BUFFER_SIZE  32      

/****************************************************************************
  Ñòàòóñíûå êîäû TWI ìîäóëÿ 
****************************************************************************/

/*Îáùèå ñòàòóñíûå êîäû */                    
#define TWI_START                  0x08  // ñîñòîÿíèå START ñôîðìèðîâàíî 
#define TWI_REP_START              0x10  // ñîñòîÿíèå ïîâòîðíûé START ñôîðìèðîâàíî 
#define TWI_ARB_LOST               0x38  // áûë ïîòåðÿí ïðèîðèòåò 

/*Ñòàòóñíûå êîäû âåäóùåãî ïåðåäàò÷èêà*/                
#define TWI_MTX_ADR_ACK            0x18  // áûë ïåðåäàí ïàêåò SLA+W è ïîëó÷åíî ïîäòâåðæäåíèå
#define TWI_MTX_ADR_NACK           0x20  // áûë ïåðåäàí ïàåò SLA+W è íå ïîëó÷åíî ïîäòâåðæäåíèå
#define TWI_MTX_DATA_ACK           0x28  // áûë ïåðåäàí áàéò äàííûõ è ïîëó÷åíî ïîäòâåðæäåíèå  
#define TWI_MTX_DATA_NACK          0x30  // áûë ïåðåäàí áàéò äàííûõ è íå ïîëó÷åíî ïîäòâåðæäåíèå

/*Ñòàòóñíûå êîäû âåäóùåãî ïðèåìíèêà*/ 
#define TWI_MRX_ADR_ACK            0x40  // áûë ïåðåäàí ïàêåò SLA+R è ïîëó÷åíî ïîäòâåæäåíèå 
#define TWI_MRX_ADR_NACK           0x48  // áûë ïåðåäàí ïàêåò SLA+R è íå ïîëó÷åíî ïîäòâåðæäåíèå 
#define TWI_MRX_DATA_ACK           0x50  // áàéò äàííûõ ïðèíÿò è ïåðåäàíî ïîäòâåðæäåíèå  
#define TWI_MRX_DATA_NACK          0x58  // áûë ïðèíÿò áàéò äàííûõ áåç ïîäòâåðæäåíèÿ  

/*Äðóãèå ñòàòóñíûå êîäû*/
#define TWI_NO_STATE               0xF8  // íåîïðåäåëåííîå ñîñòîÿíèå; TWINT = “0”
#define TWI_BUS_ERROR              0x00  // îøèáêà íà øèíå èç-çà íåêîðåêòíûõ ñîñòîÿíèé ÑÒÀÐÒ èëè ÑÒÎÏ

/*Ïîëüçîâàòåëüñêèå êîäû*/
#define TWI_SUCCESS                0xff

/****************************************************************************
  Îïðåäåëåíèÿ êîíñòàíò
****************************************************************************/

#define TWI_READ_BIT     0       // ïîçèöèÿ R/W áèòà â àäðåñíîì ïàêåòå
#define TWI_ADR_BITS     1       // ïîçèöèÿ àäðåñà â àäðåñíîì ïàêåòå
#ifndef TRUE
#define TRUE             1
#endif
#ifndef FALSE
#define FALSE            0
#endif

/****************************************************************************
  Ïîëüçîâàòåëüñêèå ôóíêöèè
****************************************************************************/

/*Èíèöèàëèçàöèÿ è óñòàíîâêà ÷àñòîòû SCL ñèãíàëà*/
uint8_t TWI_MasterInit(uint16_t fr);

/*Ïåðåäàòü äàííûå*/
void TWI_SendData(uint8_t *msg, uint8_t msgSize);

/*Ïîëó÷èòü ïðèíÿòûå äàííûå*/
uint8_t TWI_GetData(uint8_t *msg, uint8_t msgSize);

/*Âçÿòü ñòàòóñ TWI ìîäóëÿ*/
uint8_t TWI_GetState(void);

#endif //TWIM_H