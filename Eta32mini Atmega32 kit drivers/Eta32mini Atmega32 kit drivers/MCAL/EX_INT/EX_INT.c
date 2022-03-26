/***********************************************************************************/
/* File Name : EXT_INT.h                                                           */
/* File Info : Contains  functions implementation for the external interrupt	   */
/* Version   : V1.0                                                                */
/* Date      : 25 Mar 2022                                                         */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "EX_INT.h"



/***********************************************************************************/
/* Function Name  : MEXT_INT_vInit								                   */
/* Function Info  : Inits external interrupt configurations					       */
/* Function Input : Pointer to external interrupt congiuration			           */
/* Function Return: None						                                   */
/***********************************************************************************/
void MEXT_INT_vInit(EXT_INT_t * Ptr_tExtInterrupt){
	switch(Ptr_tExtInterrupt->EXT_INTNUM){
		case EXT_INT0:
			EXT_INT_0_CALLBACK = Ptr_tExtInterrupt->EXT_INT_FUN;
			switch(Ptr_tExtInterrupt->Trigger){
				case SEN_LOW:
					CLR_BIT(MCUCR,ISC00);
					CLR_BIT(MCUCR,ISC01);
				break;
				case SEN_CHANGE:
					SET_BIT(MCUCR,ISC00);
					CLR_BIT(MCUCR,ISC01);
				break;
				case SEN_FALLING:
					CLR_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
				break;
				case SEN_RAISING:
					SET_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
				break;
				default:
				break;
			}
			SET_BIT(GICR,INT0);
		break;
		case EXT_INT1:
			EXT_INT_1_CALLBACK = Ptr_tExtInterrupt->EXT_INT_FUN;
			switch(Ptr_tExtInterrupt->Trigger){
				case SEN_LOW:
				CLR_BIT(MCUCR,ISC10);
				CLR_BIT(MCUCR,ISC11);
				break;
				case SEN_CHANGE:
				SET_BIT(MCUCR,ISC10);
				CLR_BIT(MCUCR,ISC11);
				break;
				case SEN_FALLING:
				CLR_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
				break;
				case SEN_RAISING:
				SET_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
				break;
				default:
				break;
			}
			SET_BIT(GICR,INT1);
		break;
		case EXT_INT2:
			EXT_INT_2_CALLBACK = Ptr_tExtInterrupt->EXT_INT_FUN;
			switch(Ptr_tExtInterrupt->Trigger){
				case SEN_FALLING:
				CLR_BIT(MCUCSR,ISC2);
				break;
				case SEN_RAISING:
				SET_BIT(MCUCSR,ISC2);
				break;
				default:
				break;
			}
			SET_BIT(GICR,INT2);
		break;
		default:
		break;
	}
	ENABLE_GLOBAL_INT();
}


/***********************************************************************************/
/* Function Info  : ISR to handle of External interrupt	0						   */
/***********************************************************************************/
void __vector_1(void){
	EXT_INT_0_CALLBACK();
}

/***********************************************************************************/
/* Function Info  : ISR to handle of External interrupt	1						   */
/***********************************************************************************/
void __vector_2(void){
	EXT_INT_1_CALLBACK();
}

/***********************************************************************************/
/* Function Info  : ISR to handle of External interrupt	2						   */
/***********************************************************************************/
void __vector_3(void){
	EXT_INT_2_CALLBACK();
}