/***********************************************************************************/
/* File Name : TIMER0_CFG.h														   */
/* File Info : Contains configuration options for TIMER0                           */
/* Version   : V1.0                                                                */
/* Date      : 07 MAr. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Gaurd*********************************/
/***********************************************************************************/
#ifndef TIMER0_CFG_H_
#define TIMER0_CFG_H_

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "REG.h"
#include "BITS.h"
#include "DIO.h"

/***********************************************************************************/
/***********************User-defined data types and Macros**************************/
/***********************************************************************************/

typedef enum {
	NORMAL_MODE			=	0	,
	CTC_MODE					,
	FAST_PWM					,
	PAHSE_CORRECT_PWM		
}TIMER_MODE_t;

typedef enum{
	_01_PRESCALER		=	1	,
	_08_PRESCALER		=	8	,
	_64_PRESCALER		=	64	,
	_256_PRESCALER		=	256	,
	_1024_PRESCALER		=	1024,
	EXT_FALING_EDGE				,
	EXT_RAISING_EDGE
}CLK_SRC_PRE_t;

#define CLK_FREQUENCY	8				/*in MHz*/

typedef enum{
	DISCONNECTED		=	0	,
	TOGGLE_CMP_NON_PWM			,
	Clear_CMP_NON_PWM			,
	SET_CMP_NON_PWM				,
	NON_INVERTING_PWM			,
	INVERTING_PWM				
}COM_OUTPUT_MODE_t;


typedef struct {
	TIMER_MODE_t Mode;
	CLK_SRC_PRE_t	Prescaler;
	COM_OUTPUT_MODE_t COM_OUT;
}TIMER0_t;

/*
#if COM_OUTPUT_MODE !=	DISCONNECTED
static DIO_t PWM_OUTPUT={B,PIN3,OUTPUT_MODE,NOT_SET};
#endif
*/
#endif /* TIMER0_CFG_H_ */