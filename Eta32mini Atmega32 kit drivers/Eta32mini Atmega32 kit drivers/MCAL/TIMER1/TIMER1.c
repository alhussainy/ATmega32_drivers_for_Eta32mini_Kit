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
		/*
		When the ICR1 is used as TOP value , the ICP1 is disconnected and consequently
		the input capture function is disabled.
		*/
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




/*
FAST_PWM_10BIT				,
PHASE_FREQ_ICR1_PWM			,
PHASE_FREQ_OCR1A_PWM		,
PHASE_CORRECT_ICR1_PWM		,
PHASE_CORRECT_OCR1A_PWM		,
			,
FAST_PWM_ICR1				,
FAST_PWM_OCR1A*/
/***********************************************************************************/
/* Function Name  : MPWM_1_vInit	                                               */
/* Function Info  : Inits PWM on timer 1		    			                   */
/* Function Input : Pointer to PWM Configuration obj							   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MPWM_1_vInit(TIMER1_t *Ptr_tTimer){
	if(Ptr_tTimer->Mode ==	PAHSE_CORRECT_PWM_8BIT){
		SET_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	}else if(Ptr_tTimer->Mode == PAHSE_CORRECT_PWM_9BIT){
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	}else if(Ptr_tTimer->Mode == PAHSE_CORRECT_PWM_10BIT){
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		CLR_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	}else if(Ptr_tTimer->Mode == FAST_PWM_8BIT){
		SET_BIT(TCCR1A,WGM10);
		CLR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	}else if(Ptr_tTimer->Mode == FAST_PWM_9BIT){
		CLR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLR_BIT(TCCR1B,WGM13);
	}

	
}



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
/* Function Name  : MTIMER_1_vInitICU	                                           */
/* Function Info  : Inits ICU on timer 1		    			                   */
/* Function Input : Pointer to  Configuration obj								   */
/* Function Return: None						                                   */
/***********************************************************************************/
void MTIMER_1_vInitICU(TIMER1_t*Ptr_tTimer){
	MPWM_1_vInit(Ptr_tTimer);
	/*activate Input capture Noise Canceller*/
	SET_BIT(TCCR1B,ICNC1);
	//DIO_t ICP1 = {D,PIN6,INPUT_MODE,NOT_SET};
	//MDIO_vInitPin(&ICP1);
}


/***********************************************************************************/
/* Function Name  : MTIMER_1_u16CalcOnTicks                                        */
/* Function Info  : Gets Ticks when ICP1 is high    			                   */
/* Function Input : Pointer to  Configuration obj								   */
/* Function Return: Ticks when ICP1 is high			                               */
/***********************************************************************************/
u16 MTIMER_1_u16CalcOnTicks(TIMER1_t*Ptr_tTimer){
	DISABLE_GLOBAL_INT();
	u16 Loc_u16FirstEdge=0;
	u16 Loc_u16LastEdge=0;
	/*clear ICF1 flag*/
	SET_BIT(TIFR,ICF1);
	/*select  rising edge*/
	SET_BIT(TCCR1B,ICES1);
	while(GET_BIT(TIFR,ICF1)==0){}
	Loc_u16FirstEdge = ICR1;

	/*clear ICF1 flag*/
	SET_BIT(TIFR,ICF1);
	/*select  failing edge*/
	CLR_BIT(TCCR1B,ICES1);
	while(GET_BIT(TIFR,ICF1)==0){}
	
	Loc_u16LastEdge = ICR1;
	/*clear ICF1 flag*/
	SET_BIT(TIFR,ICF1);	

	return Loc_u16LastEdge-Loc_u16FirstEdge;
}


u32 TIMER_1_CALC_TIME(void)
{
	
	SET_BIT(DDRD,7);

	long long a,b,high,distance;
	TCCR1A = 0;
	TIFR = (1<<5);  	/* Clear ICF (Input Capture flag)  */
	SET_BIT(PORTD,7);
	_delay_ms(100);
	
	CLR_BIT(PORTD,7);
	TCCR1B = 0xc1;  	/* Rising edge, no prescaler , noise canceler*/
	while ((TIFR&(1<<5)) == 0);
	a = ICR1;  		/* Take value of capture register */
	TIFR = (1<<5);  	/* Clear ICF flag */
	TCCR1B = 0x81;  	/* Falling edge, no prescaler ,noise canceler*/
	while ((TIFR&(1<<5)) == 0);
	b = ICR1;  		/* Take value of capture register */
	TIFR = (1<<5);  	/* Clear ICF flag */
	TCNT1=0;
	TCCR1B = 0;  		/* Stop the timer */
	high=b-a;
	distance=((high*34600)/(8000000/8))/10 ;
	return distance;

}


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
//ISR(TIMER1_COMPA_vect)
//{
	//static u32 counter = 0;
	//counter++;
	//if (counter == numberOfComparingMatchs)
	//{
		//MTIMER_1_CALLBACK();
		//counter = 0;
	//}
//}


/***********************************************************************************/
/* Function Info  : ISR to handle of Timer 1 clear on compare  match interrupt     */
/*					on channel B												   */
/***********************************************************************************/
//ISR(TIMER1_COMPB_vect)
//{
	//static u32 counter = 0;
	//counter++;
	//if (counter == numberOfComparingMatchs)
	//{
		//MTIMER_1_CALLBACK();
		//counter = 0;
	//}
//}

