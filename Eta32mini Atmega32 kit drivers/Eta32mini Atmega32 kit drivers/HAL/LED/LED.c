/***********************************************************************************/
/* File Name : LED.c	                                                           */
/* File Info : Contains functions implementation					               */
/* Version   : V1.0                                                                */
/* Date      : 09 Mar 2021                                                         */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "LED.h"



/***********************************************************************************/
/* Function Name  : HLED_vInit						                               */
/* Function Info  : Inits a led										               */
/* Function Input : - Pointer to led obj									       */
/* Function Return: None													       */
/***********************************************************************************/
void HLED_vInit(LED_t* Ptr_tLed){
	DIO_t led = {Ptr_tLed->Port,Ptr_tLed->Pin,OUTPUT_MODE,NOT_SET};
	MDIO_vInitPin(&led);
}

/***********************************************************************************/
/* Function Name  : HLED_vOn			                                           */
/* Function Info  : Turns led on									               */
/* Function Input : - Pointer to led obj									       */
/* Function Return: None													       */
/***********************************************************************************/
void HLED_vOn(LED_t * Ptr_tLed){
	DIO_t led = {Ptr_tLed->Port,Ptr_tLed->Pin,OUTPUT_MODE,NOT_SET};
	MDIO_vWritePin(&led,OUT_HIGH);
}


/***********************************************************************************/
/* Function Name  : HLED_vOff			                                           */
/* Function Info  : Turns led off									               */
/* Function Input : - Pointer to led obj									       */
/* Function Return: None													       */
/***********************************************************************************/
void HLED_vOff(LED_t * Ptr_tLed){
	DIO_t led = {Ptr_tLed->Port,Ptr_tLed->Pin,OUTPUT_MODE,NOT_SET};
	MDIO_vWritePin(&led,OUT_LOW);
}


/***********************************************************************************/
/* Function Name  : HLED_vToggle		                                           */
/* Function Info  : Toggles a led									               */
/* Function Input : - Pointer to led obj									       */
/* Function Return: None													       */
/***********************************************************************************/
void HLED_vToggle(LED_t *Ptr_tLed){
		DIO_t led = {Ptr_tLed->Port,Ptr_tLed->Pin,OUTPUT_MODE,NOT_SET};
		MDIO_vTogglePin(&led);
}