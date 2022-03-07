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
#include "DIO.h"
#include "TIMER0.h"
DIO_t led={C,PIN0,OUTPUT_MODE,NOT_SET};
void LED_TOGGLE(){
	
	MDIO_vTogglePin(&led);
}
int main(void)
{
	MDIO_vInitPin(&led);
	TIMER_0_INIT();
	TIMER_0_SET_CALLBACK(LED_TOGGLE);
	TIMER_0_SET_TIME(1000);
	TIMER_0_START();
    while(1)
    {
    }
}