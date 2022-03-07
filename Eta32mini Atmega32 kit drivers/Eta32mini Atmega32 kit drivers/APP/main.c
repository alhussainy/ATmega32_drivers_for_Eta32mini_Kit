/***********************************************************************************/
/* File Name : main.c	                                                           */
/* File Info : Contains main application							               */
/* Version   : V1.0                                                                */
/* Date      : 06 Mar 2021                                                         */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "LCD.h"
#include "INT_EEPROM.h"
int main(void)
{
	HLCD_vInit();
	HLCD_vCLR();
	//MEEPROM_vWriteData(0x200,'A');
	u8 data=MEEPROM_u8ReadData(0x200);
	HLCD_vWriteCharacter(data);
	HLCD_vWriteCharacter('p');
    while(1)
    {
	
    }
}