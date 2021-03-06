/***********************************************************************************/
/* File Name : TC_74.h															   */
/* File Info : Contains functions prototypes for TC74	                           */
/* Version   : V1.0                                                                */
/* Date      : 25 MAr. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Gaurd*********************************/
/***********************************************************************************/
#ifndef TC_74_H_
#define TC_74_H_

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "TC_74_CFG.h"
#include "STD_TYPES.h"

/***********************************************************************************/
/* Function Name  : HTC74_vInit						                               */
/* Function Info  : Inits TC74										               */
/* Function Input : None													       */
/* Function Return: None													       */
/***********************************************************************************/
void HTC74_vInit();



/***********************************************************************************/
/* Function Name  : HTC74_u8ReadTemp_Blocking		                               */
/* Function Info  : Raeds data from TC74							               */
/* Function Input : None													       */
/* Function Return: Temperature												       */
/***********************************************************************************/
u8 HTC74_u8ReadTemp_Blocking();

#endif /* TC_74_H_ */