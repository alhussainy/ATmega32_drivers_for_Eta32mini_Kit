/***********************************************************************************/
/* File Name : DIO.c	                                                           */
/* File Info : Contains functions implementation					               */
/* Version   : V1.0                                                                */
/* Date      : 06 Mar 2021                                                         */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "DIO.h"


/***********************************************************************************/
/* Function Name  : MDIO_vInitPin					                               */
/* Function Info  : Inits a pin										               */
/* Function Input : - Pointer to pin struct(DIO_t)							       */
/* Function Return: None													       */
/***********************************************************************************/
void MDIO_vInitPin(DIO_t * Ptr_tPin){
	MDIO_vSetPinMode(Ptr_tPin);
	if(Ptr_tPin->PullUpEn != NOT_SET){
		MDIO_vSetPullUpRes(Ptr_tPin);
	}

}
/***********************************************************************************/
/* Function Name  : MDIO_vSetPinMode                                               */
/* Function Info  : Sets mode for a pin								               */
/* Function Input : - - Pointer to pin struct(DIO_t)						       */
/* Function Return: None													       */
/***********************************************************************************/
void MDIO_vSetPinMode(DIO_t * Ptr_tPin){
	switch(Ptr_tPin->Mode){
		case INPUT_MODE:
		switch(Ptr_tPin->Port){
			case A:
			CLR_BIT(DDRA,Ptr_tPin->Pin);
			break;
			case B:
			CLR_BIT(DDRB,Ptr_tPin->Pin);
			break;
			case C:
			CLR_BIT(DDRC,Ptr_tPin->Pin);
			break;
			case D:
			CLR_BIT(DDRD,Ptr_tPin->Pin);
			break;
			default:
			break;
		}
		break;
		case OUTPUT_MODE:
		switch(Ptr_tPin->Port){
			case A:
			SET_BIT(DDRA,Ptr_tPin->Pin);
			break;
			case B:
			SET_BIT(DDRB,Ptr_tPin->Pin);
			break;
			case C:
			SET_BIT(DDRC,Ptr_tPin->Pin);
			break;
			case D:
			SET_BIT(DDRD,Ptr_tPin->Pin);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}

/***********************************************************************************/
/* Function Name  : MDIO_vWritePin	                                               */
/* Function Info  : Writes value on a pin							               */
/* Function Input : - Pointer to pin struct(DIO_t)							       */
/*					- Output value(OUTPUT_t)									   */
/* Function Return: None													       */
/***********************************************************************************/
void MDIO_vWritePin(DIO_t * Ptr_tPin,OUTPUT_t Copy_tOuput){
	switch(Copy_tOuput){
		case OUT_LOW:
		switch(Ptr_tPin->Port){
			case A:
			CLR_BIT(PORTA,Ptr_tPin->Pin);
			break;
			case B:
			CLR_BIT(PORTB,Ptr_tPin->Pin);
			break;
			case C:
			CLR_BIT(PORTC,Ptr_tPin->Pin);
			break;
			case D:
			CLR_BIT(PORTD,Ptr_tPin->Pin);
			break;
			default:
			break;
		}
		break;
		case OUT_HIGH:
		switch(Ptr_tPin->Port){
			case A:
			SET_BIT(PORTA,Ptr_tPin->Pin);
			break;
			case B:
			SET_BIT(PORTB,Ptr_tPin->Pin);
			break;
			case C:
			SET_BIT(PORTC,Ptr_tPin->Pin);
			break;
			case D:
			SET_BIT(PORTD,Ptr_tPin->Pin);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}

/***********************************************************************************/
/* Function Name  : MDIO_vReadPin	                                               */
/* Function Info  : Gets value from a pin							               */
/* Function Input : - Pointer to pin struct(DIO_t)							       */
/* Function Return: Output value(OUTPUT_t)									       */
/***********************************************************************************/
OUTPUT_t MDIO_tReadPin(DIO_t * Ptr_tPin){

	OUTPUT_t Value=OUT_LOW;
	switch(Ptr_tPin->Port){
		case A:
		Value = GET_BIT(PINA,Ptr_tPin->Pin);
		break;
		case B:
		Value = GET_BIT(PINB,Ptr_tPin->Pin);
		break;
		case C:
		Value = GET_BIT(PINC,Ptr_tPin->Pin);
		break;
		case D:
		Value = GET_BIT(PIND,Ptr_tPin->Pin);
		break;
		default:
		break;
	}
	return Value;
}


/***********************************************************************************/
/* Function Name  : MDIO_vTogglePin	                                               */
/* Function Info  : Toggles value on a pin							               */
/* Function Input : - Pointer to pin struct(DIO_t)							       */
/* Function Return: None													       */
/***********************************************************************************/
void MDIO_vTogglePin(DIO_t * Ptr_tPin){
	switch(Ptr_tPin->Port){
		case A:
		TOG_BIT(PORTA,Ptr_tPin->Pin);
		break;
		case B:
		TOG_BIT(PORTB,Ptr_tPin->Pin);
		break;
		case C:
		TOG_BIT(PORTC,Ptr_tPin->Pin);
		break;
		case D:
		TOG_BIT(PORTD,Ptr_tPin->Pin);
		break;
		default:
		break;
	}
}


/***********************************************************************************/
/* Function Name  : MDIO_vSetPullUpRes                                             */
/* Function Info  : Writes value on a pin							               */
/* Function Input : - Pointer to pin struct(DIO_t)							       */
/* Function Return: None													       */
/***********************************************************************************/
void MDIO_vSetPullUpRes(DIO_t * Ptr_tPin){
	switch(Ptr_tPin->PullUpEn){
		case PULL_UP_DIS:
		switch(Ptr_tPin->Port){
			case A:
			CLR_BIT(PORTA,Ptr_tPin->Pin);
			break;
			case B:
			CLR_BIT(PORTB,Ptr_tPin->Pin);
			break;
			case C:
			CLR_BIT(PORTC,Ptr_tPin->Pin);
			break;
			case D:
			CLR_BIT(PORTD,Ptr_tPin->Pin);
			break;
			default:
			break;
		}
		break;
		case PULL_UP_EN:
		switch(Ptr_tPin->Port){
			case A:
			SET_BIT(PORTA,Ptr_tPin->Pin);
			break;
			case B:
			SET_BIT(PORTB,Ptr_tPin->Pin);
			break;
			case C:
			SET_BIT(PORTC,Ptr_tPin->Pin);
			break;
			case D:
			SET_BIT(PORTD,Ptr_tPin->Pin);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}



/***********************************************************************************/
/* Function Name  : MDIO_vInitPORT					                               */
/* Function Info  : Inits a pin										               */
/* Function Input : - Pointer to port obj									       */
/* Function Return: None													       */
/***********************************************************************************/
void MDIO_vInitPORT(DIO_PORT_t * Ptr_tPort){
		MDIO_vSetPortMode(Ptr_tPort);
		if(Ptr_tPort->PullUpEn != NOT_SET){
			MDIO_vSetPortMode(Ptr_tPort);
		}
}

/***********************************************************************************/
/* Function Name  : MDIO_vSetPortMode                                              */
/* Function Info  : Sets mode for a pin								               */
/* Function Input : - Pointer to port obj									       */
/*					- Pin mode(DIO_MODE_t)										   */
/* Function Return: None													       */
/***********************************************************************************/
void MDIO_vSetPortMode(DIO_PORT_t *Ptr_tPort){
	switch(Ptr_tPort->Mode){
		case INPUT_MODE:
			switch(Ptr_tPort->Port){
				case A:
					DDRA &= (~(Ptr_tPort->DataBitsMask));
				break;
				case B:
					DDRB &= (~(Ptr_tPort->DataBitsMask));
				break;
				case C:
					DDRC &= (~(Ptr_tPort->DataBitsMask));
				break;
				case D:
					DDRD &= (~(Ptr_tPort->DataBitsMask));
				break;
				default:
				break;
			}
		break;
		case OUTPUT_MODE:
			switch(Ptr_tPort->Port){
				case A:
					DDRA |= (Ptr_tPort->DataBitsMask);
				break;
				case B:
					DDRB |= (Ptr_tPort->DataBitsMask);
				break;
				case C:
					DDRC |= (Ptr_tPort->DataBitsMask);
				break;
				case D:
					DDRD |= (Ptr_tPort->DataBitsMask);
				break;
				default:
				break;
			}
		break;
		default:
		break;
	}
}


/***********************************************************************************/
/* Function Name  : MDIO_vWritePin	                                               */
/* Function Info  : Writes value on a pin							               */
/* Function Input : - Pointer to port obj									       */
/*					- Output value												   */
/* Function Return: None													       */
/***********************************************************************************/
void MDIO_vWritePort(DIO_PORT_t *Ptr_tPort,u8 Copy_u8Data,PIN_t Copy_tStartPin,DATA_LENGTH_t Copy_tDataLength){
	switch(Copy_tDataLength){
		case _8_BIT_DATA:
			switch(Ptr_tPort->Port){
				case A:
					PORTA = ((Ptr_tPort->DataBitsMask)&((Copy_u8Data)<<Copy_tStartPin));
				break;
				case B:
					PORTB = ((Ptr_tPort->DataBitsMask)&((Copy_u8Data)<<Copy_tStartPin));
				break;
				case C:
					PORTC = ((Ptr_tPort->DataBitsMask)&((Copy_u8Data)<<Copy_tStartPin));
				break;
				case D:
					PORTD = ((Ptr_tPort->DataBitsMask)&((Copy_u8Data)<<Copy_tStartPin));
				break;
				default:
				break;
			}
		break;
		case _4_BIT_DATA:
			switch(Ptr_tPort->Port){
				case A:
					PORTA = (PORTA&(~(0x0F<<Copy_tStartPin)))|((Ptr_tPort->DataBitsMask)&((Copy_u8Data)<<Copy_tStartPin));
				break;
				case B:
					PORTB = (PORTB&(~(0x0F<<Copy_tStartPin)))|((Ptr_tPort->DataBitsMask)&((Copy_u8Data)<<Copy_tStartPin));
				break;
				case C:
					PORTC =	(PORTB&(~(0x0F<<Copy_tStartPin)))|((Ptr_tPort->DataBitsMask)&((Copy_u8Data)<<Copy_tStartPin));
				break;
				case D:
					PORTD = (PORTB&(~(0x0F<<Copy_tStartPin)))|((Ptr_tPort->DataBitsMask)&((Copy_u8Data)<<Copy_tStartPin));
				break;
				default:
				break;
			}
		break;
		default:
		break;
	}
	
}

/***********************************************************************************/
/* Function Name  : MDIO_vReadPin	                                               */
/* Function Info  : Gets value from a port							               */
/* Function Input : - Pointer to port obj									       */
/* Function Return: Output value											       */
/***********************************************************************************/
u8 MDIO_tReadPort(DIO_PORT_t *Ptr_tPort){
	u8 returnValue=0;
	switch(Ptr_tPort->Port){
		case A:
			returnValue = ((Ptr_tPort->DataBitsMask)&(PORTA));
		break;
		case B:
			returnValue = ((Ptr_tPort->DataBitsMask)&(PORTA));
		break;
		case C:
			returnValue = ((Ptr_tPort->DataBitsMask)&(PORTA));
		break;
		case D:
			returnValue = ((Ptr_tPort->DataBitsMask)&(PORTA));
		break;
		default:
		break;
	}
	return returnValue;
}

/***********************************************************************************/
/* Function Name  : MDIO_vTogglePort	                                           */
/* Function Info  : Toggles value on a port							               */
/* Function Input : - Pointer to port obj									       */
/* Function Return: None													       */
/***********************************************************************************/
void MDIO_vTogglePort(DIO_PORT_t *Ptr_tPort){
	switch(Ptr_tPort->Port){
		case A:
			DDRA ^= (Ptr_tPort->DataBitsMask);
		break;
		case B:
			DDRB ^= (Ptr_tPort->DataBitsMask);
		break;
		case C:
			DDRC ^= (Ptr_tPort->DataBitsMask);
		break;
		case D:
			DDRD ^= (Ptr_tPort->DataBitsMask);
		break;
		default:
		break;
	}
}



/***********************************************************************************/
/* Function Name  : MDIO_vSetPullUpResForPort                                      */
/* Function Info  : Writes value on a pin							               */
/* Function Input : - Pointer to port obj									       */
/* Function Return: None													       */
/***********************************************************************************/
void MDIO_vSetPullUpResForPort(DIO_PORT_t *Ptr_tPort){
	switch(Ptr_tPort->PullUpEn){
		case PULL_UP_EN:
		switch(Ptr_tPort->Port){
			case A:
				PORTA |= (Ptr_tPort->DataBitsMask);
			break;
			case B:
				PORTB |= (Ptr_tPort->DataBitsMask);
			break;
			case C:
				PORTC |= (Ptr_tPort->DataBitsMask);
			break;
			case D:
				PORTD |= (Ptr_tPort->DataBitsMask);
			break;
			default:
			break;
		}
		break;
		case PULL_UP_DIS:
		switch(Ptr_tPort->Port){
			case A:
				PORTA &= (~(Ptr_tPort->DataBitsMask));
			break;
			case B:
				PORTB &= (~(Ptr_tPort->DataBitsMask));
			break;
			case C:
				PORTC &= (~(Ptr_tPort->DataBitsMask));
			break;
			case D:
				PORTD &= (~(Ptr_tPort->DataBitsMask));
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}