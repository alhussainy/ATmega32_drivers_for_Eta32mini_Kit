/***********************************************************************************/
/* File Name : LCD.h															   */
/* File Info : Contains functions prototypes for DIO	                           */
/* Version   : V1.0                                                                */
/* Date      : 07 MAr. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Gaurd*********************************/
/***********************************************************************************/
#ifndef LCD_H_
#define LCD_H_

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "LCD_CFG.h"


/***********************************************************************************/
/*******************************Functions prototypes********************************/
/***********************************************************************************/


/***********************************************************************************/
/* Function Name  : HLCD_vInit						                               */
/* Function Info  : Inits a LCD										               */
/* Function Input : None													       */
/* Function Return: None													       */
/***********************************************************************************/
void HLCD_vInit(void);

/***********************************************************************************/
/* Function Name  : HLCD_vWriteCharacter                                           */
/* Function Info  : Displays a character on LCD						               */
/* Function Input : - Data to be displayed									       */
/* Function Return: None													       */
/***********************************************************************************/
void HLCD_vWriteCharacter(u8 Copy_tData);


/***********************************************************************************/
/* Function Name  : HLCD_vWriteCommand			                                   */
/* Function Info  : Sends a command on LCD							               */
/* Function Input : - Command to be send									       */
/* Function Return: None													       */
/***********************************************************************************/
void HLCD_vWriteCommand(u8 Copy_tCommand);


/***********************************************************************************/
/* Function Name  : HLCD_vDisplayString                                            */
/* Function Info  : Sends a string to LCD 		    			                   */
/* Function Input : String														   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vDisplayString(const u8 *str);

/***********************************************************************************/
/* Function Name  : HLCD_vCLR		                                               */
/* Function Info  : Clears LCD Display   		    			                   */
/* Function Input : None												   		   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vCLR(void);


/***********************************************************************************/
/* Function Name  : HLCD_vWriteInt	                                               */
/* Function Info  : Sends a integer to LCD 		    			                   */
/* Function Input : integer 													   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vWriteInt(u32 num);

/***********************************************************************************/
/* Function Name  : HLCD_GoTo		                                               */
/* Function Info  : Sets LCD location	 		    			                   */
/* Function Input : position in row and column 									   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vGoTo(u8 row,u8 col);

#endif /* LCD_H_ */