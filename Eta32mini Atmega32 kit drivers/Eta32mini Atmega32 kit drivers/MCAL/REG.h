/***********************************************************************************/
/* File Name : REG.h											                   */
/* File Info : Contains Registers addresses			                               */
/* Version   : V1.0                                                                */
/* Date      : 06 Mar. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Gaurd*********************************/
/***********************************************************************************/
#ifndef REG_H_
#define REG_H_


/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "STD_TYPES.h"


/***********************************************************************************/
/****************************Macro Constant Definition******************************/
/***********************************************************************************/

/*****************************PORTA I/O Registers***********************************/
#define  PORTA		(*((volatile u8*)0x3B))
#define  DDRA		(*((volatile u8*)0x3A))
#define  PINA		(*((volatile u8*)0x39))

/*****************************PORTB I/O Registers***********************************/
#define  PORTB		(*((volatile u8*)0x38))
#define  DDRB		(*((volatile u8*)0x37))
#define  PINB		(*((volatile u8*)0x36))

/*****************************PORTC I/O Registers***********************************/
#define  PORTC		(*((volatile u8*)0x35))
#define  DDRC		(*((volatile u8*)0x34))
#define  PINC		(*((volatile u8*)0x33))

/*****************************PORTS I/O Registers***********************************/
#define  PORTD		(*((volatile u8*)0x32))
#define  DDRD		(*((volatile u8*)0x31))
#define  PIND		(*((volatile u8*)0x30))

/*****************************STATUS REGISTER(SREG)*********************************/
#define SREG		(*((volatile u8*)0x5F))

/*****************************TIMER_0_REGISTERS*************************************/
#define TCCR0		(*((volatile u8*)0x53))
#define OCR0		(*((volatile u8*)0x5C))
#define TCNT0		(*((volatile u8*)0x52))
#define TIMSK		(*((volatile u8*)0x59))

/*****************************STACK REGISTER***************************************/
#define SPL		(*((volatile u8*)0x5D))
#define SPH		(*((volatile u8*)0x5E))
#define SP		(*((volatile u16*)0x5D))


/**************************EEPROM REGISTERS******************************************/
/*EEPROM Control Register*/
#define EECR		(*((volatile u8*)0x3C))
/*EEPROM Data Register*/
#define EEDR		(*((volatile u8*)0x3D))
/*EEPROM Address Register*/
#define EEARL		(*((volatile u8*)0x3E))
#define EEARH		(*((volatile u8*)0x3F))
/**can be handled as 16 bit register but last 6 bits are reserved **/
/**Only needs 10 bits to access 1024 EEPROM*/
#define EEAR		(*((volatile u16*)0x3E))


/*****************************TIMER_1_REGISTERS*************************************/
#define TCCR1A		(*((volatile u8*)0x4F))
#define TCCR1B		(*((volatile u8*)0x4E))

#define TCNT1H		(*((volatile u8*)0x4D))
#define TCNT1L		(*((volatile u8*)0x4C))
/*To access TCNT1 as one 16-bit register*/
#define TCNT1		(*((volatile u16*)0x4C))

#define OCR1AH		(*((volatile u8*)0x4B))
#define OCR1AL		(*((volatile u8*)0x4A))
/*To access OCR1A as one 16-bit register*/
#define OCR1A		(*((volatile u16*)0x4A))

#define OCR1BH		(*((volatile u8*)0x49))
#define OCR1BL		(*((volatile u8*)0x48))
/*To access OCR1B as one 16-bit register*/
#define OCR1B		(*((volatile u16*)0x48))

#define ICR1H		(*((volatile u8*)0x47))
#define ICR1L		(*((volatile u8*)0x46))
/*To access ICR1 as one 16-bit register*/
#define ICR1		(*((volatile u16*)0x46))
/*note :
To do a 16-bit write, the high byte must be written before the low byte. For a 16-bit read,
the low byte must be read before the high byte.*/

#endif /* REG_H_ */