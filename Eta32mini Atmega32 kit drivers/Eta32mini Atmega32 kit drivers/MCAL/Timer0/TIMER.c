/***********************************************************************************/
/* File Name : TIMER0.c	                                                           */
/* File Info : Contains functions implementation for timer0			               */
/* Version   : V1.0                                                                */
/* Date      : 07 Mar 2021                                                         */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "TIMER0_CFG.h"
#include "TIMER0.h"



/***********************************************************************************/
/* Function Name  : MTIMER_0_vInit	                                               */
/* Function Info  : Inits Timer0				    			                   */
/* Function Input : Pointer to timer configurations  							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MTIMER_0_vInit(TIMER0_t* Ptr_tTimer){
		if(Ptr_tTimer->Mode ==	NORMAL_MODE){
			CLR_BIT(TCCR0,WGM00);
			CLR_BIT(TCCR0,WGM01);
			/*to enable overflow interrupt for timer0*/
			SET_BIT(TIMSK,TOIE0);
			/*to enable global interrupt for timer0*/
			ENABLE_GLOBAL_INT();
		}else if(Ptr_tTimer->Mode ==	CTC_MODE){
			CLR_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
			/*to enable compare match interrupt for timer0*/
			SET_BIT(TIMSK,OCIE0);
			/*to enable global interrupt for timer0*/
			ENABLE_GLOBAL_INT();
		}		
		
		if(Ptr_tTimer->COM_OUT == DISCONNECTED) {
			CLR_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
		}else if(Ptr_tTimer->COM_OUT == TOGGLE_CMP_NON_PWM) {
			SET_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
		}else if(Ptr_tTimer->COM_OUT == Clear_CMP_NON_PWM) {
			CLR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			DIO_t PWM_OUTPUT={B,PIN3,OUTPUT_MODE,NOT_SET};
			MDIO_vInitPin(&PWM_OUTPUT);
		}else if(Ptr_tTimer->COM_OUT == SET_CMP_NON_PWM) {
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			DIO_t PWM_OUTPUT={B,PIN3,OUTPUT_MODE,NOT_SET};
			MDIO_vInitPin(&PWM_OUTPUT);
		}
}

/***********************************************************************************/
/* Function Name  : MTIMER_0_vSetTime                                              */
/* Function Info  : Sets time delay in ms for Timer0							   */
/* Function Input : - Pointer to timer configurations							   */
/*					- Time in ms												   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MTIMER_0_vSetTime(TIMER0_t* Ptr_tTimer,u32 Copy_u32TimeInMili){
		if(Ptr_tTimer->Mode ==	NORMAL_MODE){
			u32 tickTime = (Ptr_tTimer->Prescaler* 1000UL )/ CLK_FREQUENCY;
			u32 totalTicks =  (Copy_u32TimeInMili * 1000000UL)/tickTime;
			numberOfRequiredOverFlows =totalTicks / 256;
			reminderOfReuiredOverFlows=totalTicks%256;
			if(reminderOfReuiredOverFlows != 0){
				TCNT0 = 256-reminderOfReuiredOverFlows;
				numberOfRequiredOverFlows++;
			}
				
		}else if(Ptr_tTimer->Mode ==	CTC_MODE){
			u32 tickTime = (Ptr_tTimer->Prescaler*1000UL )/ CLK_FREQUENCY;		/*Result in Nano Second*/
			u32 totalTicks =  (Copy_u32TimeInMili * 1000000UL)/tickTime;
			u8 division_factor = 255;
			for(;division_factor > 0;division_factor--)
			{
				if((totalTicks % division_factor) == 0)
				{
					break;
				}
			}
			OCR0= division_factor -1;
			numberOfComparingMatchs = totalTicks /division_factor;

		}

}	


/***********************************************************************************/
/* Function Name  : MTIMER_0_vStart	                                               */
/* Function Info  : Starts Timer0												   */
/* Function Input : Pointer to timer configurations  							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MTIMER_0_vStart(TIMER0_t* Ptr_tTimer){
	if(Ptr_tTimer->Prescaler == _01_PRESCALER){
			SET_BIT(TCCR0,CS00);
			CLR_BIT(TCCR0,CS01);
			CLR_BIT(TCCR0,CS02);
	}else if(Ptr_tTimer->Prescaler == _08_PRESCALER){
			CLR_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			CLR_BIT(TCCR0,CS02);
	}else if(Ptr_tTimer->Prescaler == _64_PRESCALER){
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			CLR_BIT(TCCR0,CS02);
	}else if(Ptr_tTimer->Prescaler == _256_PRESCALER){
			CLR_BIT(TCCR0,CS00);
			CLR_BIT(TCCR0,CS01);
			SET_BIT(TCCR0,CS02);
	}else if(Ptr_tTimer->Prescaler == _1024_PRESCALER){
			SET_BIT(TCCR0,CS00);
			CLR_BIT(TCCR0,CS01);
			SET_BIT(TCCR0,CS02);
	}
	else if(Ptr_tTimer->Prescaler == EXT_FALING_EDGE){
			CLR_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			SET_BIT(TCCR0,CS02);
	}
	else if(Ptr_tTimer->Prescaler == EXT_RAISING_EDGE){
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			SET_BIT(TCCR0,CS02);
	}
	/*transitions on the T0 pin will
	clock the counter even if the pin is configured as an output
	*/
}


/***********************************************************************************/
/* Function Name  : MTIMER_0_vStop	                                               */
/* Function Info  : Starts Timer0												   */
/* Function Input : None														   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MTIMER_0_vStop(void){
		/*Disconnect CLK source*/
		CLR_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);
}

/***********************************************************************************/
/* Function Name  : MTIMER_0_vSetCallback                                          */
/* Function Info  : Sets call back for Timer0 ISR								   */
/* Function Input : Pointer to a callback										   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MTIMER_0_vSetCallback(void (*Ptr_tFunction)(void)){
	MTIMER_0_CALLBACK =Ptr_tFunction;
}



/***********************************************************************************/
/* Function Name  : MPWM_0_vInit	                                               */
/* Function Info  : Inits PWM on timer 0		    			                   */
/* Function Input : Pointer to PWM Configuration obj							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MPWM_0_vInit(TIMER0_t *Ptr_tTimer){
	if(Ptr_tTimer->Mode ==	FAST_PWM){
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
	}else if(Ptr_tTimer->Mode == PAHSE_CORRECT_PWM){
		SET_BIT(TCCR0,WGM00);
		CLR_BIT(TCCR0,WGM01);
	}
	if(Ptr_tTimer->COM_OUT ==	NON_INVERTING_PWM){
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		DIO_t PWM_OUTPUT={B,PIN3,OUTPUT_MODE,NOT_SET};
		MDIO_vInitPin(&PWM_OUTPUT);
	}else if(Ptr_tTimer->COM_OUT == INVERTING_PWM){
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		DIO_t PWM_OUTPUT={B,PIN3,OUTPUT_MODE,NOT_SET};
		MDIO_vInitPin(&PWM_OUTPUT);
	}
}


/***********************************************************************************/
/* Function Name  : MPWM_0_vSetDutyCycle                                           */
/* Function Info  : Sets ducty cycle for generated wave			                   */
/* Function Input : - Pointer to PWM Configuration obj							   */
/*					- Duty cycle value in presentage							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MPWM_0_vSetDutyCycle(TIMER0_t*Ptr_tTimer,u8 Copy_u8DutyCycle){
	if(Ptr_tTimer->Mode ==	FAST_PWM){
		if(Ptr_tTimer->COM_OUT ==	NON_INVERTING_PWM){
				OCR0 = ((((u32)Copy_u8DutyCycle * 256) / 100) - 1);
			}else if(Ptr_tTimer->COM_OUT == INVERTING_PWM){
				//TODO:checking
				OCR0 = 255-((((u32)Copy_u8DutyCycle * 256) / 100));
		}
	}else if(Ptr_tTimer->Mode == PAHSE_CORRECT_PWM){
		if(Ptr_tTimer->COM_OUT ==	NON_INVERTING_PWM){
			OCR0 = (((u32)Copy_u8DutyCycle * 255) / 100);
		}else if(Ptr_tTimer->COM_OUT == INVERTING_PWM){
			//TODO:checking
			OCR0 = ((((u32)Copy_u8DutyCycle * 255) / 100));
		}
	}
	
}



/***********************************************************************************/
/* Function Name  : MPWM_0_vStart	                                               */
/* Function Info  : Starts PWM on timer 0		    			                   */
/* Function Input : Pointer to PWM Configuration obj							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MPWM_0_vStart(TIMER0_t*Ptr_tTimer){
	MTIMER_0_vStart(Ptr_tTimer);
}



/***********************************************************************************/
/* Function Name  : MPWM_0_vStop	                                               */
/* Function Info  : Stops PWM on timer 0		    			                   */
/* Function Input : Pointer to PWM Configuration obj							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MPWM_0_vStop(void){
	MTIMER_0_vStop();
}

/***********************************************************************************/
/* Function Info  : ISR to handle of Timer 0 overflow interrupt	                   */
/***********************************************************************************/
ISR(TIMER0_OVF_vect){

	static u32 counter = 0;
	counter++;
	if(counter == numberOfRequiredOverFlows)
	{
		MTIMER_0_CALLBACK();
		counter = 0;
		TCNT0 = 256 - reminderOfReuiredOverFlows;
	}
}

/***********************************************************************************/
/* Function Info  : ISR to handle of Timer 0 clear on compare  match interrupt     */
/***********************************************************************************/
ISR(TIMER0_COMP_vect)
{
	static u32 counter = 0;
	counter++;
	if (counter == numberOfComparingMatchs)
	{
	MTIMER_0_CALLBACK();
	counter = 0;
	}
}
