/***********************************************************************************/
/* File Name : EEPROM_24C64.                                                       */
/* File Info : Contains functions implementation					               */
/* Version   : V1.0                                                                */
/* Date      : 24 Mar 2021                                                         */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "EEPROM_24C64.h"




/***********************************************************************************/
/* Function Name  : HEEPROM_24C64_vInit				                               */
/* Function Info  : Inits I2C										               */
/* Function Input : None													       */
/* Function Return: None													       */
/***********************************************************************************/
void HEEPROM_24C64_vInit(){
	MI2C_vInit();
}
/***********************************************************************************/
/* Function Name  : HEEPROM_24C64_vCallToRead		                               */
/* Function Info  : Call EEPROM to read								               */
/* Function Input : None													       */
/* Function Return: None													       */
/***********************************************************************************/
void HEEPROM_24C64_vCallToRead(){
	MI2C_vStartCondition_Block();
	MI2C_vCallSlaveToRead_Block(EEPROM_24C64_SLAVE_ADD);
}



/***********************************************************************************/
/* Function Name  : HEEPROM_24C64_vCallToWrite		                               */
/* Function Info  : Call EEPROM to write							               */
/* Function Input : None													       */
/* Function Return: None													       */
/***********************************************************************************/
void HEEPROM_24C64_vCallToWrite(){
	MI2C_vStartCondition_Block();
	MI2C_vCallSlaveToWrite_Block(EEPROM_24C64_SLAVE_ADD);
}




/***********************************************************************************/
/* Function Name  : HEEPROM_24C64_vWriteOneByte		                               */
/* Function Info  : Send data to EEPROM								               */
/* Function Input : Data to send											       */
/* Function Return: None													       */
/***********************************************************************************/
void HEEPROM_24C64_vWriteOneByte(u8 Copy_u8Page,u8 Copy_u8Byte,u8 Copy_u8Data){
	if(Copy_u8Byte<32 && Copy_u8Page<256){
		MI2C_vStartCondition_Block();
		MI2C_vCallSlaveToWrite_Block(EEPROM_24C64_SLAVE_ADD);
		MI2C_vSendByte_Block(Copy_u8Page>>3);
		MI2C_vSendByte_Block((Copy_u8Page<<3)|(Copy_u8Byte));
		//MI2C_vRepeatedStart_Block();
		MI2C_vSendByte_Block(Copy_u8Data);
		MI2C_vStopCondition_Block();
		/*HEEPROM_24C64_vCallToWrite();
		MI2C_vSendByte_Block((Copy_u8Page>>3));
		MI2C_vSendByte_Block((Copy_u8Page<<3)|(Copy_u8Byte));
		MI2C_vSendByte_Block(Copy_u8Data);
		MI2C_vStopCondition_Block();*/
		
	}
	
}


/***********************************************************************************/
/* Function Name  : HEEPROM_24C64_u8ReadOneByte		                               */
/* Function Info  : Read byte from EEPROM							               */
/* Function Input : None													       */
/* Function Return: Data received											       */
/***********************************************************************************/
u8 HEEPROM_24C64_u8ReadOneByte(u8 Copy_u8Page,u8 Copy_u8Byte){
	u8 Loc_u8Data=0;
	if(Copy_u8Byte<32 && Copy_u8Page<256){
		/*HEEPROM_24C64_vCallToWrite();
		MI2C_vSendByte_Block((Copy_u8Page>>3));
		MI2C_vSendByte_Block((Copy_u8Page<<3)|(Copy_u8Byte));
		MI2C_vRepeatedStart_Block();
		HEEPROM_24C64_vCallToRead();
		Loc_u8Data=MI2C_u8ReceiveByte_Block();
		MI2C_vStopCondition_Block();*/
		MI2C_vStartCondition_Block();
		MI2C_vCallSlaveToWrite_Block(EEPROM_24C64_SLAVE_ADD);
		MI2C_vSendByte_Block(Copy_u8Page>>3);
		MI2C_vSendByte_Block((Copy_u8Page<<3)|(Copy_u8Byte));
		MI2C_vRepeatedStart_Block();
		MI2C_vCallSlaveToRead_Block(EEPROM_24C64_SLAVE_ADD);
		Loc_u8Data = MI2C_u8ReceiveByte_Block();
		MI2C_vStopCondition_Block();
	}
	return Loc_u8Data;
}