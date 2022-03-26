/***********************************************************************************/
/* File Name : PUSH_BTN.c                                                          */
/* File Info : Contains functions implementation					               */
/* Version   : V1.0                                                                */
/* Date      : 24 Mar 2021                                                         */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/

#include "PUSH_BTN.h"



/***********************************************************************************/
/* Function Name  : HPUSH_BTN_vInitWithInterrupt		                           */
/* Function Info  : Inits push button								               */
/* Function Input : Pointer to button configuration							       */
/* Function Return: None													       */
/***********************************************************************************/
void HPUSH_BTN_vInitWithInterrupt(BTN_INT_t* Ptr_tBtn){
		MEXT_INT_vInit(&Ptr_tBtn->BtnInt);
}