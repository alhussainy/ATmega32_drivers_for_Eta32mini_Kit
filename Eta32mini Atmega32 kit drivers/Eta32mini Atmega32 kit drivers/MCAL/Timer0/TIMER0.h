/***********************************************************************************/
/* File Name : TIMER0.h															   */
/* File Info : Contains functions prototypes for Timer0	                           */
/* Version   : V1.0                                                                */
/* Date      : 07 MAr. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Gaurd*********************************/
/***********************************************************************************/
#ifndef TIMER0_H_
#define TIMER0_H_



/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "HELPER.h"
#include "TIMER0_CFG.h"
//#include "avr/interrupt.h"


static volatile void (*MTIMER_0_CALLBACK)(void);

static u32 numberOfRequiredOverFlows;
static u32 reminderOfReuiredOverFlows;

static u32 numberOfComparingMatchs;

/***********************************************************************************/
/* Function Name  : MTIMER_0_vInit	                                               */
/* Function Info  : Inits Timer0				    			                   */
/* Function Input : Pointer to timer configurations  							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MTIMER_0_vInit(TIMER0_t* Ptr_tTimer);

/***********************************************************************************/
/* Function Name  : MTIMER_0_vSetTime                                              */
/* Function Info  : Sets time delay in ms for Timer0							   */
/* Function Input : - Pointer to timer configurations							   */
/*					- Time in ms												   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MTIMER_0_vSetTime(TIMER0_t*,u32);


/***********************************************************************************/
/* Function Name  : MTIMER_0_vStart	                                               */
/* Function Info  : Starts Timer0												   */
/* Function Input : Pointer to timer configurations  							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MTIMER_0_vStart(TIMER0_t*);


/***********************************************************************************/
/* Function Name  : MTIMER_0_vStop	                                               */
/* Function Info  : Starts Timer0												   */
/* Function Input : None														   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MTIMER_0_vStop(void);

/***********************************************************************************/
/* Function Name  : MTIMER_0_vSetCallback                                          */
/* Function Info  : Sets call back for Timer0 ISR								   */
/* Function Input : Pointer to a callback										   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MTIMER_0_vSetCallback(void (*FUNC)(void));


/***********************************************************************************/
/* Function Name  : MPWM_0_vInit	                                               */
/* Function Info  : Inits PWM on timer 0		    			                   */
/* Function Input : Pointer to PWM Configuration obj							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MPWM_0_vInit(TIMER0_t *Ptr_tTimer);



/***********************************************************************************/
/* Function Name  : MPWM_0_vSetDutyCycle                                           */
/* Function Info  : Sets ducty cycle for generated wave			                   */
/* Function Input : - Pointer to PWM Configuration obj							   */
/*					- Duty cycle value in presentage							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MPWM_0_vSetDutyCycle(TIMER0_t*Ptr_tTimer,u8 Copy_u8DutyCycle);



/***********************************************************************************/
/* Function Name  : MPWM_0_vStart	                                               */
/* Function Info  : Starts PWM on timer 0		    			                   */
/* Function Input : Pointer to PWM Configuration obj							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MPWM_0_vStart(TIMER0_t*Ptr_tTimer);



/***********************************************************************************/
/* Function Name  : MPWM_0_vStop	                                               */
/* Function Info  : Stops PWM on timer 0		    			                   */
/* Function Input : Pointer to PWM Configuration obj							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MPWM_0_vStop(void);


/***********************************************************************************/
/* Function Info  : ISR to handle of Timer 0 overflow interrupt	                   */
/***********************************************************************************/
//void __vector_11(void)     __attribute__((signal));

/***********************************************************************************/
/* Function Info  : ISR to handle of Timer 0 clear on compare  match interrupt     */
/***********************************************************************************/
void __vector_10(void)     __attribute__((signal));


#endif /* TIMER0_H_ */