/***********************************************************************************/
/* File Name : PUSH_BTN.h	                                                       */
/* File Info : Contains Macros, user-defined data types and functions prototypes   */
/*			   for the push button				                                   */
/* Version   : V1.0                                                                */
/* Date      : 25 Mar 2022                                                         */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Gaurd*********************************/
/***********************************************************************************/
#ifndef PUSH_BTN_H_
#define PUSH_BTN_H_
#include "EX_INT.h"
//
//typedef enum{
	//BTN_INT		=	0,
	//BTN_POLLING
//}BTN_INTERACT_t;


typedef enum{
	BTN_FAIL	=	0,	
	BTN_SUCCESS
}BTN_STATUS_t;

typedef struct{
	EXT_INT_t BtnInt;
}BTN_INT_t;


/***********************************************************************************/
/*******************************Functions prototypes********************************/
/***********************************************************************************/

/***********************************************************************************/
/* Function Name  : HPUSH_BTN_vInitWithInterrupt		                           */
/* Function Info  : Inits push button								               */
/* Function Input : Pointer to button configuration							       */
/* Function Return: None													       */
/***********************************************************************************/
void HPUSH_BTN_vInitWithInterrupt(BTN_INT_t* Ptr_tBtn);

#endif /* PUSH_BTN_H_ */