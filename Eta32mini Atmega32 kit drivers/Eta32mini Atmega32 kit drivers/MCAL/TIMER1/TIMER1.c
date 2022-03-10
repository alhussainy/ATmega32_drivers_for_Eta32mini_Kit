/***********************************************************************************/
/* File Name : TIMER1.c	                                                           */
/* File Info : Contains functions implementation for timer1			               */
/* Version   : V1.0                                                                */
/* Date      : 09 Mar 2021                                                         */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "TIMER1.h"



/***********************************************************************************/
/* Function Name  : MTIMER_1_vInit	                                               */
/* Function Info  : Inits Timer1				    			                   */
/* Function Input : Pointer to timer configurations  							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MTIMER_1_vInit(TIMER1_t* Ptr_tTimer){
	if(Ptr_tTimer->Mode ==	NORMAL_MODE){
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
		/*to enable overflow interrupt for timer1*/
		SET_BIT(TIMSK,TOIE1);
		/*to enable global interrupt*/
		ENABLE_GLOBAL_INT();
	}else if(Ptr_tTimer->Mode == CTC_MODE_OCR1A){
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
		/*to enable compare match interrupt for timer1*/
		SET_BIT(TIMSK,OCIE1A);
		/*to enable global interrupt*/
		ENABLE_GLOBAL_INT();
	}else if(Ptr_tTimer->Mode == CTC_MODE_ICR1){
		CLR_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		/*to enable compare match interrupt for timer1*/
		SET_BIT(TIMSK,OCIE1A);
		/*to enable global interrupt*/
		ENABLE_GLOBAL_INT();
	}
	
	if(Ptr_tTimer->COM_OUT_A == DISCONNECTED) {
		CLR_BIT(TCCR1A,COM1A0);
		CLR_BIT(TCCR1A,COM1A1);
	}else if(Ptr_tTimer->COM_OUT_A == TOGGLE_CMP_NON_PWM) {
		SET_BIT(TCCR1A,COM1A0);
		CLR_BIT(TCCR1A,COM1A1);
		DIO_t PWM_OUTPUT={D,PIN5,OUTPUT_MODE,NOT_SET};
		MDIO_vInitPin(&PWM_OUTPUT);
	}else if(Ptr_tTimer->COM_OUT_A == Clear_CMP_NON_PWM) {
		CLR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		DIO_t PWM_OUTPUT={D,PIN5,OUTPUT_MODE,NOT_SET};
		MDIO_vInitPin(&PWM_OUTPUT);
	}else if(Ptr_tTimer->COM_OUT_A == SET_CMP_NON_PWM) {
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		DIO_t PWM_OUTPUT={D,PIN5,OUTPUT_MODE,NOT_SET};
		MDIO_vInitPin(&PWM_OUTPUT);
	}

	if(Ptr_tTimer->COM_OUT_B == DISCONNECTED) {
		CLR_BIT(TCCR1B,COM1B0);
		CLR_BIT(TCCR1B,COM1B1);
	}else if(Ptr_tTimer->COM_OUT_B == TOGGLE_CMP_NON_PWM) {
		SET_BIT(TCCR1B,COM1B0);
		CLR_BIT(TCCR1B,COM1B1);
		DIO_t PWM_OUTPUT={D,PIN4,OUTPUT_MODE,NOT_SET};
		MDIO_vInitPin(&PWM_OUTPUT);
	}else if(Ptr_tTimer->COM_OUT_B == Clear_CMP_NON_PWM) {
		CLR_BIT(TCCR1B,COM1B0);
		SET_BIT(TCCR1B,COM1B1);
		DIO_t PWM_OUTPUT={D,PIN4,OUTPUT_MODE,NOT_SET};
		MDIO_vInitPin(&PWM_OUTPUT);
	}else if(Ptr_tTimer->COM_OUT_B == SET_CMP_NON_PWM) {
		SET_BIT(TCCR1B,COM1B0);
		SET_BIT(TCCR1B,COM1B1);
		DIO_t PWM_OUTPUT={D,PIN4,OUTPUT_MODE,NOT_SET};
		MDIO_vInitPin(&PWM_OUTPUT);
	}
}

/***********************************************************************************/
/* Function Name  : MTIMER_1_vSetTime                                              */
/* Function Info  : Sets time delay in ms for Timer1							   */
/* Function Input : - Pointer to timer configurations							   */
/*					- Time in ms												   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MTIMER_1_vSetTime(TIMER1_t* Ptr_tTimer,u32 Copy_u32TimeInMili){
	if(Ptr_tTimer->Mode ==	NORMAL_MODE){
		u32 tickTime = ((u32)Ptr_tTimer->Prescaler* 1000UL )/ CLK_FREQUENCY;
		u32 totalTicks =  (Copy_u32TimeInMili * 1000000UL)/tickTime;
		numberOfRequiredOverFlows =totalTicks / 0xFFFFUL;
		reminderOfReuiredOverFlows=totalTicks%0xFFFF;
		if(reminderOfReuiredOverFlows != 0){
			TCNT1 = 0xFFFF-reminderOfReuiredOverFlows;
			numberOfRequiredOverFlows++;
		}
		
		}else if(Ptr_tTimer->Mode ==	CTC_MODE_OCR1A){
			u32 tickTime = (Ptr_tTimer->Prescaler*1000UL )/ CLK_FREQUENCY;		/*Result in Nano Second*/
			u32 totalTicks =  (Copy_u32TimeInMili * 1000000UL)/tickTime;
			u8 division_factor = 0xFFFE;
			for(;division_factor > 0;division_factor--)
			{
				if((totalTicks % division_factor) == 0)
				{
					break;
				}
			}
			OCR1A= division_factor -1;
			numberOfComparingMatchs = totalTicks /division_factor;

	}else if(Ptr_tTimer->Mode ==	CTC_MODE_ICR1){
		u32 tickTime = (Ptr_tTimer->Prescaler*1000UL )/ CLK_FREQUENCY;		/*Result in Nano Second*/
		u32 totalTicks =  (Copy_u32TimeInMili * 1000000UL)/tickTime;
		u8 division_factor = 0xFFFE;
		for(;division_factor > 0;division_factor--)
		{
			if((totalTicks % division_factor) == 0)
			{
				break;
			}
		}
		ICR1= division_factor -1;
		numberOfComparingMatchs = totalTicks /division_factor;
	}
}


/***********************************************************************************/
/* Function Name  : MTIMER_1_vStart	                                               */
/* Function Info  : Starts Timer1												   */
/* Function Input : Pointer to timer configurations  							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MTIMER_1_vStart(TIMER1_t* Ptr_tTimer){
	if(Ptr_tTimer->Prescaler == _01_PRESCALER){
			SET_BIT(TCCR1B,CS10);
			CLR_BIT(TCCR1B,CS11);
			CLR_BIT(TCCR1B,CS12);
	}else if(Ptr_tTimer->Prescaler == _08_PRESCALER){
			CLR_BIT(TCCR1B,CS10);
			SET_BIT(TCCR1B,CS11);
			CLR_BIT(TCCR1B,CS12);
	}else if(Ptr_tTimer->Prescaler == _64_PRESCALER){
			SET_BIT(TCCR1B,CS10);
			SET_BIT(TCCR1B,CS11);
			CLR_BIT(TCCR1B,CS12);
	}else if(Ptr_tTimer->Prescaler == _256_PRESCALER){
			CLR_BIT(TCCR1B,CS10);
			CLR_BIT(TCCR1B,CS11);
			SET_BIT(TCCR1B,CS12);
	}else if(Ptr_tTimer->Prescaler == _1024_PRESCALER){
			SET_BIT(TCCR1B,CS10);
			CLR_BIT(TCCR1B,CS11);
			SET_BIT(TCCR1B,CS12);
	}
	else if(Ptr_tTimer->Prescaler == EXT_FALING_EDGE){
			CLR_BIT(TCCR1B,CS10);
			SET_BIT(TCCR1B,CS11);
			SET_BIT(TCCR1B,CS12);
	}
	else if(Ptr_tTimer->Prescaler == EXT_RAISING_EDGE){
			SET_BIT(TCCR1B,CS10);
			SET_BIT(TCCR1B,CS11);
			SET_BIT(TCCR1B,CS12);
	}
	/*transitions on the T0 pin will
	clock the counter even if the pin is configured as an output
	*/
}


/***********************************************************************************/
/* Function Name  : MTIMER_1_vStop	                                               */
/* Function Info  : Starts Timer1												   */
/* Function Input : None														   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MTIMER_1_vStop(void){
	/*Disconnect CLK source*/
	CLR_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);
}

/***********************************************************************************/
/* Function Name  : MTIMER_1_vSetCallback                                          */
/* Function Info  : Sets call back for Timer1 ISR								   */
/* Function Input : Pointer to a callback										   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MTIMER_1_vSetCallback(void (*Ptr_fCallback)(void)){
		MTIMER_1_CALLBACK = Ptr_fCallback;
}


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


/***********************************************************************************/
/* Function Info  : ISR to handle of Timer 1 overflow interrupt	                   */
/***********************************************************************************/
ISR(TIMER1_OVF_vect){

	static u32 counter = 0;
	counter++;
	if(counter == numberOfRequiredOverFlows)
	{
		MTIMER_1_CALLBACK();
		counter = 0;
		TCNT0 = 256 - reminderOfReuiredOverFlows;
	}
}

/***********************************************************************************/
/* Function Info  : ISR to handle of Timer 1 clear on compare  match interrupt     */
/*					on channel A												   */
/***********************************************************************************/
ISR(TIMER1_COMPA_vect)
{
	static u32 counter = 0;
	counter++;
	if (counter == numberOfComparingMatchs)
	{
		MTIMER_1_CALLBACK();
		counter = 0;
	}
}


/***********************************************************************************/
/* Function Info  : ISR to handle of Timer 1 clear on compare  match interrupt     */
/*					on channel B												   */
/***********************************************************************************/
ISR(TIMER1_COMPB_vect)
{
	static u32 counter = 0;
	counter++;
	if (counter == numberOfComparingMatchs)
	{
		MTIMER_1_CALLBACK();
		counter = 0;
	}
}

