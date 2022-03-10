/***********************************************************************************/
/* File Name : TIMER0_CFG.h														   */
/* File Info : Contains configuration options for TIMER1                           */
/* Version   : V1.0                                                                */
/* Date      : 09 MAr. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Gaurd*********************************/
/***********************************************************************************/

#ifndef TIMER1_CFG_H_
#define TIMER1_CFG_H_

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
	PAHSE_CORRECT_PWM_8BIT		,
	PAHSE_CORRECT_PWM_9BIT		,
	PAHSE_CORRECT_PWM_10BIT		,
	CTC_MODE_OCR1A				,
	FAST_PWM_8BIT				,
	FAST_PWM_9BIT				,
	FAST_PWM_10BIT				,
	PHASE_FREQ_ICR1_PWM			,
	PHASE_FREQ_OCR1A_PWM		,
	PHASE_CORRECT_ICR1_PWM		,
	PHASE_CORRECT_OCR1A_PWM		,
	CTC_MODE_ICR1				,
	FAST_PWM_ICR1				,
	FAST_PWM_OCR1A
}TIMER1_MODE_t;

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
	TIMER1_MODE_t Mode;
	CLK_SRC_PRE_t	Prescaler;
	COM_OUTPUT_MODE_t COM_OUT_A;
	COM_OUTPUT_MODE_t COM_OUT_B;
}TIMER1_t;




#endif /* TIMER1_CFG_H_ */