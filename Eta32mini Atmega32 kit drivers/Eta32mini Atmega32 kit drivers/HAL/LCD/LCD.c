/***********************************************************************************/
/* File Name : LCD.c	                                                           */
/* File Info : Contains functions implementation					               */
/* Version   : V1.0                                                                */
/* Date      : 07 Mar 2021                                                         */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "LCD.h"





/***********************************************************************************/
/* Function Name  : HLCD_vInit						                               */
/* Function Info  : Inits a LCD										               */
/* Function Input : None													       */
/* Function Return: None													       */
/***********************************************************************************/
void HLCD_vInit(void){
		MDIO_vSetPortMode(&LCD);
		MDIO_vInitPin(&LCD_EN);
		MDIO_vInitPin(&LCD_RS);
		#if LCD_MODE     ==  _4_BIT_MODE
			/***_THIS_COMMAND_TO_ACTIVE_4_BIT_MODE_***/
			HLCD_vWriteCommand(0x33);
			HLCD_vWriteCommand(0x32);
			HLCD_vWriteCommand(0x28);
		#elif
			/***_THIS_COMMAND_TO_ACTIVE_8_BIT_MODE_***/
			HLCD_vWriteCommand(0x38);
		#endif
		HLCD_vWriteCommand(0x0C);   /***_THIS_COMMAND_TO_TURN_ON_DISPLAY_AND_TURN_OFF_CURSOR_***/
		HLCD_vWriteCommand(0x01);   /***_THIS_COMMAND_TO_CLEAR_LCD_*****************************/
		HLCD_vWriteCommand(0x06);   /***_THIS_COMMAND_TO_MOVE_CURSOR_FROM_LEFT_TO_RIGHT_********/
		HLCD_vWriteCommand(0x02);   /***_THIS_COMMAND_TO_RETURN_HOME_***************************/
}


/***********************************************************************************/
/* Function Name  : HLCD_vWriteCharacter                                           */
/* Function Info  : Displays a character on LCD						               */
/* Function Input : - Data to be displayed									       */
/* Function Return: None													       */
/***********************************************************************************/
void HLCD_vWriteCharacter(u8 Copy_tData){
		MDIO_vWritePin(&LCD_RS,OUT_HIGH);
		#if LCD_MODE     ==  _4_BIT_MODE
			MDIO_vWritePort(&LCD,((Copy_tData>>4)&0x0F),LCD_DATA_PIN_4,_4_BIT_DATA);
			MDIO_vWritePin(&LCD_EN,OUT_HIGH);
			_delay_ms(1);
			MDIO_vWritePin(&LCD_EN,OUT_LOW);
			_delay_ms(5);
			MDIO_vWritePort(&LCD,(Copy_tData&0x0F),LCD_DATA_PIN_4,_4_BIT_DATA);
			MDIO_vWritePin(&LCD_EN,OUT_HIGH);
			_delay_ms(1);
			MDIO_vWritePin(&LCD_EN,OUT_LOW);
			_delay_ms(5);
		#elif
		#endif
}



/***********************************************************************************/
/* Function Name  : HLCD_vWriteCommand			                                   */
/* Function Info  : Sends a command on LCD							               */
/* Function Input : - Command to be send									       */
/* Function Return: None													       */
/***********************************************************************************/
void HLCD_vWriteCommand(u8 Copy_tCommand){
		MDIO_vWritePin(&LCD_RS,OUT_LOW);
		#if LCD_MODE     ==  _4_BIT_MODE
			MDIO_vWritePort(&LCD,((Copy_tCommand>>4)&0x0F),LCD_DATA_PIN_4,_4_BIT_DATA);
			MDIO_vWritePin(&LCD_EN,OUT_HIGH);
			_delay_ms(1);
			MDIO_vWritePin(&LCD_EN,OUT_LOW);
			_delay_ms(5);
			MDIO_vWritePort(&LCD,(Copy_tCommand&0x0F),LCD_DATA_PIN_4,_4_BIT_DATA);
			MDIO_vWritePin(&LCD_EN,OUT_HIGH);
			_delay_ms(1);
			MDIO_vWritePin(&LCD_EN,OUT_LOW);
			_delay_ms(5);
		#elif
		#endif
}


/***********************************************************************************/
/* Function Name  : HLCD_vDisplayString                                            */
/* Function Info  : Sends a string to LCD 		    			                   */
/* Function Input : String														   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vDisplayString(const u8 *str)
{
	u8 i = 0;
	while(str[i] != '\0')
	{
		HLCD_vWriteCharacter(str[i]);
		i++;
	}
}

/***********************************************************************************/
/* Function Name  : HLCD_vCLR		                                               */
/* Function Info  : Clears LCD Display   		    			                   */
/* Function Input : None												   		   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vCLR(void)
{
	HLCD_vWriteCommand(0x01);
}


/***********************************************************************************/
/* Function Name  : HLCD_vWriteInt	                                               */
/* Function Info  : Sends a integer to LCD 		    			                   */
/* Function Input : integer 													   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vWriteInt(u32 num)
{
	u32 rem = 0;
	u8 arr [16];
	s8 i = 0;
	while(num != 0)
	{
		rem = num % 10;
		arr[i] = rem + 48;
		i++;
		num = num / 10;
	}
	i--;
	while(i > -1)
	{
		HLCD_vWriteCharacter(arr[i]);
		i--;
	}
}

/***********************************************************************************/
/* Function Name  : HLCD_GoTo		                                               */
/* Function Info  : Sets LCD location	 		    			                   */
/* Function Input : position in row and column 									   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HLCD_vGoTo(u8 row,u8 col)
{
	u8 Loc[2] = {0x80 , 0xC0};
	HLCD_vWriteCommand(Loc[row]+col);
}
