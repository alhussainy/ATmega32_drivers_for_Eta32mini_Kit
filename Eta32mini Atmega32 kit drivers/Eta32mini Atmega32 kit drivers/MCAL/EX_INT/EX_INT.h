/***********************************************************************************/
/* File Name : EXT_INT.h	                                                       */
/* File Info : Contains Macros, user-defined data types and functions prototypes   */
/*			   for the external interrupt		                                   */
/* Version   : V1.0                                                                */
/* Date      : 25 Mar 2022                                                         */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Gaurd*********************************/
/***********************************************************************************/
#ifndef EX_INT_H_
#define EX_INT_H_

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "REG.h"
#include "BITS.h"
#include "BIT_MATH.h"
#include "HELPER.h"


/***********************************************************************************/
/****************************User-defined datatypes*********************************/
/***********************************************************************************/
typedef enum{
	EXT_INT0	=	0,
	EXT_INT1		 ,
	EXT_INT2
}EXT_INT_NUM_t;

typedef enum{
	SEN_LOW		=	0,
	SEN_CHANGE		 ,
	SEN_FALLING		 ,
	SEN_RAISING
}EXT_INT_TRIGGER_t;
typedef struct{
	EXT_INT_NUM_t	EXT_INTNUM;
	EXT_INT_TRIGGER_t	Trigger;
	void (*EXT_INT_FUN)(void);
}EXT_INT_t;


static volatile void (* EXT_INT_0_CALLBACK)(void);
static volatile void (* EXT_INT_1_CALLBACK)(void);
static volatile void (* EXT_INT_2_CALLBACK)(void);

/***********************************************************************************/
/****************************Functions Declaration**********************************/
/***********************************************************************************/

/***********************************************************************************/
/* Function Name  : MEXT_INT_vInit								                   */
/* Function Info  : Inits external interrupt configurations					       */
/* Function Input : Pointer to external interrupt congiuration			           */
/* Function Return: None						                                   */
/***********************************************************************************/
void MEXT_INT_vInit(EXT_INT_t * Ptr_tExtInterrupt);


/***********************************************************************************/
/* Function Info  : ISR to handle of External interrupt	0						   */
/***********************************************************************************/
void __vector_1(void)     __attribute__((signal));

/***********************************************************************************/
/* Function Info  : ISR to handle of External interrupt	1						   */
/***********************************************************************************/
void __vector_2(void)     __attribute__((signal));

/***********************************************************************************/
/* Function Info  : ISR to handle of External interrupt	2						   */
/***********************************************************************************/
void __vector_3(void)     __attribute__((signal));

#endif /* EX_INT_H_ */