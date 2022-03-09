/***********************************************************************************/
/* File Name : INT_EEPROM.h                                                        */
/* File Info : Contains  functions implementation for the internal EEPROM		   */
/* Version   : V1.0                                                                */
/* Date      : 08 Mar 2022                                                         */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "INT_EEPROM.h"

/***********************************************************************************/
/***************************Functions Implementation********************************/
/***********************************************************************************/

/***********************************************************************************/
/* Function Name  : MEEPROM_vWriteData                                             */
/* Function Info  : Writes one byte of Data to internal EEPROM				       */
/* Function Input : Address of the byte within EEPROM and one byte of data         */
/* Function Return: None						                                   */
/***********************************************************************************/
void MEEPROM_vWriteData(u16 Copy_u16ByteAddress,u8 Copy_u8ByteData){
	/*Must wait until EECR_EEWE is zero to make sure EEPROM is Ready*/
	while(GET_BIT(EECR,EECR_EEWE)!=0);

	/*set the accessed byte address*/
	EEAR = Copy_u16ByteAddress;
	/*write data to  EEDR register*/
	EEDR = Copy_u8ByteData;
	
	
	
	//TODO: if the software contains a Boot Loader allowing the CPU to program the Flash
	/*Must wait until SPMEN in SPMCR becomes zero.*/

	/*EEPROM write operation must not be interrupted*/
	DISABLE_GLOBAL_INT();
	/*Set EECR_EEMWE to one to cause EEPROM is written when EEWE is set*/
	/*it is cleared automatically by hardware after 4 clock cycles*/
	SET_BIT(EECR,EECR_EEMWE);
	/*Set EECR_EEWE to write data to EEPROM*/
	SET_BIT(EECR,EECR_EEWE);
}

/***********************************************************************************/
/* Function Name  : MEEPROM_vReadData                                              */
/* Function Info  : Reads one byte of Data from internal EEPROM				       */
/* Function Input : Address of the byte within EEPROM to be read			       */
/* Function Return: None						                                   */
/***********************************************************************************/
u8 MEEPROM_u8ReadData(u16 Copy_u16ByteAddress){
	/*Must wait until EECR_EEWE is zero to make sure EEPROM is Ready*/
	while(GET_BIT(EECR,EECR_EEWE)!=0);

	/*set the accessed byte address*/
	EEAR = Copy_u16ByteAddress;
	/*Set EECR_EERE to read data from EEPROM */
	/* read data access takes one instruction and the requested data is available immediately*/
	SET_BIT(EECR,EECR_EERE);
	/*Gets data from EEDR*/
	return EEDR;
}