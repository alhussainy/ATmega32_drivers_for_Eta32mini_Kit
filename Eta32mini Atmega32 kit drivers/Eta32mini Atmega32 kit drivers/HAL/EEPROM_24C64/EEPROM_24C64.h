/***********************************************************************************/
/* File Name : EEPROM_24C64.h													   */
/* File Info : Contains functions prototypes for EEPROM 24C64	                   */
/* Version   : V1.0                                                                */
/* Date      : 24 MAr. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Gaurd*********************************/
/***********************************************************************************/
#ifndef EEPROM_24C64_H_
#define EEPROM_24C64_H_

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "EEPROM_24C64_CFG.h"
#include "I2C.h"
#include "STD_TYPES.h"



/***********************************************************************************/
/* Function Name  : HEEPROM_24C64_vInit				                               */
/* Function Info  : Inits I2C										               */
/* Function Input : None													       */
/* Function Return: None													       */
/***********************************************************************************/
void HEEPROM_24C64_vInit();


/***********************************************************************************/
/* Function Name  : HEEPROM_24C64_vCallToRead		                               */
/* Function Info  : Call EEPROM to read								               */
/* Function Input : None													       */
/* Function Return: None													       */
/***********************************************************************************/
void HEEPROM_24C64_vCallToRead();



/***********************************************************************************/
/* Function Name  : HEEPROM_24C64_vCallToWrite		                               */
/* Function Info  : Call EEPROM to write							               */
/* Function Input : None													       */
/* Function Return: None													       */
/***********************************************************************************/
void HEEPROM_24C64_vCallToWrite();




/***********************************************************************************/
/* Function Name  : HEEPROM_24C64_vWriteData		                               */
/* Function Info  : Send data to EEPROM								               */
/* Function Input : Data to send											       */
/* Function Return: None													       */
/***********************************************************************************/
void HEEPROM_24C64_vWriteOneByte(u8 Copy_u8Page,u8 Copy_u8Byte,u8 Copy_u8Data);


/***********************************************************************************/
/* Function Name  : HEEPROM_24C64_u8ReadOneByte		                               */
/* Function Info  : Read byte from EEPROM							               */
/* Function Input : None													       */
/* Function Return: Data received											       */
/***********************************************************************************/
u8 HEEPROM_24C64_u8ReadOneByte(u8 Copy_u8Page,u8 Copy_u8Byte);

#endif /* EEPROM_24C64_H_ */