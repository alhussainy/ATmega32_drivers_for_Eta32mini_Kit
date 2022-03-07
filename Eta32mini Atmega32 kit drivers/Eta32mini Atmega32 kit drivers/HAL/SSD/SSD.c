/***********************************************************************************/
/* File Name : DIO.c	                                                           */
/* File Info : Contains functions implementation					               */
/* Version   : V1.0                                                                */
/* Date      : 06 Mar 2021                                                         */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "SSD.h"


/***********************************************************************************/
/*******************************Functions prototypes********************************/
/***********************************************************************************/
/***********************************************************************************/
/* Function Name  : HSSD_vInit                                                     */
/* Function Info  : Inits Seven segments display				                   */
/* Function Input : None														   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HSSD_vInit(void){
		#if SSD_MODE == ONE_DIGIT_MODE && SSD_DECODER_MODE == WITHOUT_DECODER
			MDIO_vInitPin(&SSD_PINA);
			MDIO_vInitPin(&SSD_PINB);
			MDIO_vInitPin(&SSD_PINC);
			MDIO_vInitPin(&SSD_PIND);
			MDIO_vInitPin(&SSD_PINE);
			MDIO_vInitPin(&SSD_PINF);
			MDIO_vInitPin(&SSD_PING);
			MDIO_vInitPin(&SSD1_En);
		#elif SSD_MODE == TWO_DIGITS_MODE && SSD_DECODER_MODE == WITHOUT_DECODER
			MDIO_vInitPin(&SSD_PINA);
			MDIO_vInitPin(&SSD_PINB);
			MDIO_vInitPin(&SSD_PINC);
			MDIO_vInitPin(&SSD_PIND);
			MDIO_vInitPin(&SSD_PINE);
			MDIO_vInitPin(&SSD_PINF);
			MDIO_vInitPin(&SSD_PING);
			MDIO_vInitPin(&SSD1_En);
			MDIO_vInitPin(&SSD2_En);
		#elif SSD_MODE == ONE_DIGIT_MODE && SSD_DECODER_MODE == WITH_DECODER
			MDIO_vInitPin(&SSD_DECODER_PINA);
			MDIO_vInitPin(&SSD_DECODER_PINB);
			MDIO_vInitPin(&SSD_DECODER_PINC);
			MDIO_vInitPin(&SSD_DECODER_PIND);
		#endif
}


/***********************************************************************************/
/* Function Name  : HSSD_vDisplayNum                                               */
/* Function Info  : Displays Copy_u8Nums(00:99)        				               */
/* Function Input : Copy_u8Num to be displayed									   */
/* Function Return: None						                                   */
/***********************************************************************************/
void HSSD_vDisplayNum(u8 Copy_u8Num){
	#if SSD_MODE == TWO_DIGITS_MODE && SSD_DECODER_MODE == WITHOUT_DECODER
	u8 i = 0;
	for (i=0;i<LOOP_MAX;i++)
	{
		u8 right_Copy_u8Num = Copy_u8Num % 10;
		u8 left_Copy_u8Num  = Copy_u8Num / 10;
		MDIO_vWritePin(&SSD1_En,OUT_HIGH);
		MDIO_vWritePin(&SSD2_En,OUT_LOW);
		switch(right_Copy_u8Num)
		{
			case 0:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINE,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINF,OUT_HIGH);
			MDIO_vWritePin(&SSD_PING,OUT_LOW);
			break;
			case 1:
			MDIO_vWritePin(&SSD_PINA,OUT_LOW);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_LOW);
			MDIO_vWritePin(&SSD_PINE,OUT_LOW);
			MDIO_vWritePin(&SSD_PINF,OUT_LOW);
			MDIO_vWritePin(&SSD_PING,OUT_LOW);
			break;
			case 2:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_LOW);
			MDIO_vWritePin(&SSD_PIND,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINE,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINF,OUT_LOW);
			MDIO_vWritePin(&SSD_PING,OUT_HIGH);
			break;
			case 3:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINE,OUT_LOW);
			MDIO_vWritePin(&SSD_PINF,OUT_LOW);
			MDIO_vWritePin(&SSD_PING,OUT_HIGH);
			break;
			case 4:
			MDIO_vWritePin(&SSD_PINA,OUT_LOW);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_LOW);
			MDIO_vWritePin(&SSD_PINE,OUT_LOW);
			MDIO_vWritePin(&SSD_PINF,OUT_HIGH);
			MDIO_vWritePin(&SSD_PING,OUT_HIGH);
			break;
			case 5:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_LOW);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINE,OUT_LOW);
			MDIO_vWritePin(&SSD_PINF,OUT_HIGH);
			MDIO_vWritePin(&SSD_PING,OUT_HIGH);
			break;
			case 6:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_LOW);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINE,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINF,OUT_HIGH);
			MDIO_vWritePin(&SSD_PING,OUT_HIGH);
			break;
			case 7:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_LOW);
			MDIO_vWritePin(&SSD_PINE,OUT_LOW);
			MDIO_vWritePin(&SSD_PINF,OUT_LOW);
			MDIO_vWritePin(&SSD_PING,OUT_LOW);
			break;
			case 8:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINE,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINF,OUT_HIGH);
			MDIO_vWritePin(&SSD_PING,OUT_HIGH);
			break;
			case 9:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINE,OUT_LOW);
			MDIO_vWritePin(&SSD_PINF,OUT_HIGH);
			MDIO_vWritePin(&SSD_PING,OUT_HIGH);
			break;
			default:
			break;
		}
		_delay_ms(SSD_DISPLAY_DELAY);
		MDIO_vWritePin(&SSD1_En,OUT_LOW);
		MDIO_vWritePin(&SSD2_En,OUT_HIGH);
		switch(left_Copy_u8Num)
		{
			case 0:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINE,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINF,OUT_HIGH);
			MDIO_vWritePin(&SSD_PING,OUT_LOW);
			break;
			case 1:
			MDIO_vWritePin(&SSD_PINA,OUT_LOW);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_LOW);
			MDIO_vWritePin(&SSD_PINE,OUT_LOW);
			MDIO_vWritePin(&SSD_PINF,OUT_LOW);
			MDIO_vWritePin(&SSD_PING,OUT_LOW);
			break;
			case 2:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_LOW);
			MDIO_vWritePin(&SSD_PIND,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINE,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINF,OUT_LOW);
			MDIO_vWritePin(&SSD_PING,OUT_HIGH);
			break;
			case 3:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINE,OUT_LOW);
			MDIO_vWritePin(&SSD_PINF,OUT_LOW);
			MDIO_vWritePin(&SSD_PING,OUT_HIGH);
			break;
			case 4:
			MDIO_vWritePin(&SSD_PINA,OUT_LOW);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_LOW);
			MDIO_vWritePin(&SSD_PINE,OUT_LOW);
			MDIO_vWritePin(&SSD_PINF,OUT_HIGH);
			MDIO_vWritePin(&SSD_PING,OUT_HIGH);
			break;
			case 5:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_LOW);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINE,OUT_LOW);
			MDIO_vWritePin(&SSD_PINF,OUT_HIGH);
			MDIO_vWritePin(&SSD_PING,OUT_HIGH);
			break;
			case 6:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_LOW);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINE,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINF,OUT_HIGH);
			MDIO_vWritePin(&SSD_PING,OUT_HIGH);
			break;
			case 7:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_LOW);
			MDIO_vWritePin(&SSD_PINE,OUT_LOW);
			MDIO_vWritePin(&SSD_PINF,OUT_LOW);
			MDIO_vWritePin(&SSD_PING,OUT_LOW);
			break;
			case 8:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINE,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINF,OUT_HIGH);
			MDIO_vWritePin(&SSD_PING,OUT_HIGH);
			break;
			case 9:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINE,OUT_LOW);
			MDIO_vWritePin(&SSD_PINF,OUT_HIGH);
			MDIO_vWritePin(&SSD_PING,OUT_HIGH);
			break;
			default:
			break;
		}
		_delay_ms(SSD_DISPLAY_DELAY);
		MDIO_vWritePin(&SSD1_En,OUT_LOW);
		MDIO_vWritePin(&SSD2_En,OUT_LOW);
	}

	#elif SSD_MODE == ONE_DIGIT_MODE && SSD_DECODER_MODE == WITHOUT_DECODER
	u8 i = 0;
	MDIO_vWritePin(&SSD1_En,OUT_HIGH);
	for (i=0;i<LOOP_MAX;i++)
	{
		switch(Copy_u8Num)
		{
			case 0:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINE,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINF,OUT_HIGH);
			MDIO_vWritePin(&SSD_PING,OUT_LOW);
			break;
			case 1:
			MDIO_vWritePin(&SSD_PINA,OUT_LOW);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_LOW);
			MDIO_vWritePin(&SSD_PINE,OUT_LOW);
			MDIO_vWritePin(&SSD_PINF,OUT_LOW);
			MDIO_vWritePin(&SSD_PING,OUT_LOW);
			break;
			case 2:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_LOW);
			MDIO_vWritePin(&SSD_PIND,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINE,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINF,OUT_LOW);
			MDIO_vWritePin(&SSD_PING,OUT_HIGH);
			break;
			case 3:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINE,OUT_LOW);
			MDIO_vWritePin(&SSD_PINF,OUT_LOW);
			MDIO_vWritePin(&SSD_PING,OUT_HIGH);
			break;
			case 4:
			MDIO_vWritePin(&SSD_PINA,OUT_LOW);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_LOW);
			MDIO_vWritePin(&SSD_PINE,OUT_LOW);
			MDIO_vWritePin(&SSD_PINF,OUT_HIGH);
			MDIO_vWritePin(&SSD_PING,OUT_HIGH);
			break;
			case 5:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_LOW);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINE,OUT_LOW);
			MDIO_vWritePin(&SSD_PINF,OUT_HIGH);
			MDIO_vWritePin(&SSD_PING,OUT_HIGH);
			break;
			case 6:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_LOW);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINE,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINF,OUT_HIGH);
			MDIO_vWritePin(&SSD_PING,OUT_HIGH);
			break;
			case 7:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_LOW);
			MDIO_vWritePin(&SSD_PINE,OUT_LOW);
			MDIO_vWritePin(&SSD_PINF,OUT_LOW);
			MDIO_vWritePin(&SSD_PING,OUT_LOW);
			break;
			case 8:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINE,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINF,OUT_HIGH);
			MDIO_vWritePin(&SSD_PING,OUT_HIGH);
			break;
			case 9:
			MDIO_vWritePin(&SSD_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_PIND,OUT_HIGH);
			MDIO_vWritePin(&SSD_PINE,OUT_LOW);
			MDIO_vWritePin(&SSD_PINF,OUT_HIGH);
			MDIO_vWritePin(&SSD_PING,OUT_HIGH);
			break;
			default:
			break;
		}
		_delay_ms(SSD_DISPLAY_DELAY);
		
		
	}
	#elif SSD_MODE == ONE_DIGIT_MODE && SSD_DECODER_MODE == WITH_DECODER
	u8 i = 0;
	
	for (i=0;i<LOOP_MAX;i++)
	{
		switch(Copy_u8Num)
		{
			case 0:
			MDIO_vWritePin(&SSD_DECODER_PINA,OUT_LOW);
			MDIO_vWritePin(&SSD_DECODER_PINB,OUT_LOW);
			MDIO_vWritePin(&SSD_DECODER_PINC,OUT_LOW);
			MDIO_vWritePin(&SSD_DECODER_PIND,OUT_LOW);
			
			break;
			case 1:
			MDIO_vWritePin(&SSD_DECODER_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_DECODER_PINB,OUT_LOW);
			MDIO_vWritePin(&SSD_DECODER_PINC,OUT_LOW);
			MDIO_vWritePin(&SSD_DECODER_PIND,OUT_LOW);
			break;
			case 2:
			MDIO_vWritePin(&SSD_DECODER_PINA,OUT_LOW);
			MDIO_vWritePin(&SSD_DECODER_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_DECODER_PINC,OUT_LOW);
			MDIO_vWritePin(&SSD_DECODER_PIND,OUT_LOW);
			break;
			case 3:
			MDIO_vWritePin(&SSD_DECODER_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_DECODER_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_DECODER_PINC,OUT_LOW);
			MDIO_vWritePin(&SSD_DECODER_PIND,OUT_LOW);
			break;
			case 4:
			MDIO_vWritePin(&SSD_DECODER_PINA,OUT_LOW);
			MDIO_vWritePin(&SSD_DECODER_PINB,OUT_LOW);
			MDIO_vWritePin(&SSD_DECODER_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_DECODER_PIND,OUT_LOW);
			break;
			case 5:
			MDIO_vWritePin(&SSD_DECODER_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_DECODER_PINB,OUT_LOW);
			MDIO_vWritePin(&SSD_DECODER_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_DECODER_PIND,OUT_LOW);
			break;
			case 6:
			MDIO_vWritePin(&SSD_DECODER_PINA,OUT_LOW);
			MDIO_vWritePin(&SSD_DECODER_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_DECODER_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_DECODER_PIND,OUT_LOW);
			break;
			case 7:
			MDIO_vWritePin(&SSD_DECODER_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_DECODER_PINB,OUT_HIGH);
			MDIO_vWritePin(&SSD_DECODER_PINC,OUT_HIGH);
			MDIO_vWritePin(&SSD_DECODER_PIND,OUT_LOW);
			break;
			case 8:
			MDIO_vWritePin(&SSD_DECODER_PINA,OUT_LOW);
			MDIO_vWritePin(&SSD_DECODER_PINB,OUT_LOW);
			MDIO_vWritePin(&SSD_DECODER_PINC,OUT_LOW);
			MDIO_vWritePin(&SSD_DECODER_PIND,OUT_HIGH);
			break;
			case 9:
			MDIO_vWritePin(&SSD_DECODER_PINA,OUT_HIGH);
			MDIO_vWritePin(&SSD_DECODER_PINB,OUT_LOW);
			MDIO_vWritePin(&SSD_DECODER_PINC,OUT_LOW);
			MDIO_vWritePin(&SSD_DECODER_PIND,OUT_HIGH);
			break;
			default:
			break;
		}
		_delay_ms(SSD_DISPLAY_DELAY);
		
		
	}
	#endif
}