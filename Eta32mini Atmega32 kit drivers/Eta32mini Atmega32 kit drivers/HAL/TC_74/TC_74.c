/***********************************************************************************/
/* File Name : TC_74.c	                                                           */
/* File Info : Contains functions implementation					               */
/* Version   : V1.0                                                                */
/* Date      : 25 Mar 2021                                                         */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "TC_74.h"


/***********************************************************************************/
/* Function Name  : HTC74_vInit						                               */
/* Function Info  : Inits TC74										               */
/* Function Input : None													       */
/* Function Return: None													       */
/***********************************************************************************/
void HTC74_vInit(){
	MI2C_vInit();
}



/***********************************************************************************/
/* Function Name  : HTC74_u8ReadTemp_Blocking		                               */
/* Function Info  : Raeds data from TC74							               */
/* Function Input : None													       */
/* Function Return: Temperature												       */
/***********************************************************************************/
u8 HTC74_u8ReadTemp_Blocking(){
	u8 Loc_u8Data=0;
	MI2C_vStartCondition_Block();
	MI2C_vCallSlaveToWrite_Block(TC74_ADDRESS);
	MI2C_vSendByte_Block(TC74_TEMP_REG);
	MI2C_vRepeatedStart_Block();
	MI2C_vCallSlaveToRead_Block(TC74_ADDRESS);
	Loc_u8Data = MI2C_u8ReceiveByte_Block();
	MI2C_vStopCondition_Block();
	return Loc_u8Data;
}