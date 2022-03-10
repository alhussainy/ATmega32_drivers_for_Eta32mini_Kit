/***********************************************************************************/
/* File Name : TIMER0.h															   */
/* File Info : Contains functions prototypes for Timer1	                           */
/* Version   : V1.0                                                                */
/* Date      : 09 MAr. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Gaurd*********************************/
/***********************************************************************************/
#ifndef TIMER1_H_
#define TIMER1_H_


/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "HELPER.h"
#include "TIMER1_CFG.h"
#include "avr/interrupt.h"


static volatile void (*MTIMER_1_CALLBACK)(void);

static u32 numberOfRequiredOverFlows;
static u32 reminderOfReuiredOverFlows;

static u32 numberOfComparingMatchs;




/***********************************************************************************/
/* Function Name  : MTIMER_1_vInit	                                               */
/* Function Info  : Inits Timer1				    			                   */
/* Function Input : Pointer to timer configurations  							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MTIMER_1_vInit(TIMER1_t* Ptr_tTimer);

/***********************************************************************************/
/* Function Name  : MTIMER_1_vSetTime                                              */
/* Function Info  : Sets time delay in ms for Timer1							   */
/* Function Input : - Pointer to timer configurations							   */
/*					- Time in ms												   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MTIMER_1_vSetTime(TIMER1_t*,u32);


/***********************************************************************************/
/* Function Name  : MTIMER_1_vStart	                                               */
/* Function Info  : Starts Timer1												   */
/* Function Input : Pointer to timer configurations  							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MTIMER_1_vStart(TIMER1_t*);


/***********************************************************************************/
/* Function Name  : MTIMER_1_vStop	                                               */
/* Function Info  : Starts Timer1												   */
/* Function Input : None														   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MTIMER_1_vStop(void);

/***********************************************************************************/
/* Function Name  : MTIMER_1_vSetCallback                                          */
/* Function Info  : Sets call back for Timer1 ISR								   */
/* Function Input : Pointer to a callback										   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MTIMER_1_vSetCallback(void (*FUNC)(void));


/***********************************************************************************/
/* Function Name  : MPWM_1_vInit	                                               */
/* Function Info  : Inits PWM on timer 0		    			                   */
/* Function Input : Pointer to PWM Configuration obj							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MPWM_1_vInit(TIMER1_t *Ptr_tTimer);



/***********************************************************************************/
/* Function Name  : MPWM_1_vSetDutyCycle                                           */
/* Function Info  : Sets ducty cycle for generated wave			                   */
/* Function Input : - Pointer to PWM Configuration obj							   */
/*					- Duty cycle value in presentage							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MPWM_1_vSetDutyCycle(TIMER1_t*Ptr_tTimer,u8 Copy_u8DutyCycle);



/***********************************************************************************/
/* Function Name  : MPWM_1_vStart	                                               */
/* Function Info  : Starts PWM on timer 1		    			                   */
/* Function Input : Pointer to PWM Configuration obj							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MPWM_1_vStart(TIMER1_t*Ptr_tTimer);



/***********************************************************************************/
/* Function Name  : MPWM_1_vStop	                                               */
/* Function Info  : Stops PWM on timer 1		    			                   */
/* Function Input : Pointer to PWM Configuration obj							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MPWM_1_vStop(void);
#endif /* TIMER1_H_ */