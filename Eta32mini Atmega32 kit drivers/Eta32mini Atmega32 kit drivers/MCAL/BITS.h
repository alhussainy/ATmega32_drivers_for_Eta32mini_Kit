/***********************************************************************************/
/* File Name : BITS.h		                                                       */
/* File Info : Contains bits names and numbers for registers		               */
/* Version   : V1.0                                                                */
/* Date      : 06 Mar. 2021                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Gaurd*********************************/
/***********************************************************************************/
#ifndef BITS_H_
#define BITS_H_

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/



/***********************************************************************************/
/****************************Macro Constant Definition******************************/
/***********************************************************************************/
/*************TCCRC0_BITS********/
#define	CS00		0
#define CS01		1
#define CS02		2
#define	WGM01		3
#define COM00		4
#define COM01		5
#define WGM00		6

#define FOC0		7	/*Force Output Compare*/
/*The FOC0 bit is only active when the WGM00 bit specifies a non-PWM mode.*/
/*When writing a logical one to the FOC0 bit, an immediate compare match is
forced on the Waveform Generation unit but the TCNT0 is not changed*/
/*The FOC0 bit is always read as zero*/

/************TIMSK_BITS**********/
#define TOIE0		0	/*Timer/Counter0 Overflow Interrupt Enable*/
#define OCIE0		1	/*Timer/Counter0 Output Compare Match Interrupt Enable*/
	
#define TICIE1		5	/*Timer/Counter1, Input Capture Interrupt Enable*/
#define OCIE1A		4	/*Timer/Counter1, Output Compare A Match Interrupt Enable*/
#define OCIE1B		3	/*Timer/Counter1, Output Compare B Match Interrupt Enable*/
#define TOIE1		2	/*Timer/Counter1, Overflow Interrupt Enable*/


/************TIFR_BITS**********/
#define TOV0		0	/*Timer/Counter0 Overflow Interrupt Flag*/
#define OCF0		1	/*Timer/Counter0 Output Compare Match Interrupt Flag*/

#define ICF1		5	/*Timer/Counter1, Input Capture Interrupt Flag*/
#define OCF1A		4	/*Timer/Counter1, Output Compare A Match Interrupt Flag*/
#define OCF1B		3	/*Timer/Counter1, Output Compare B Match Interrupt Flag*/
#define TOV1		2	/*Timer/Counter1, Overflow Interrupt Flag*/

/*Note: All TIFR bits are automatically cleared when corresponding vector executed
		or by writing logical one on them
*/

/************SREG_BITS**********/
#define I_BIT		7
#define T_BIT		6
#define H_BIT		5
#define S_BIT		4
#define V_BIT		3
#define N_BIT		2
#define Z_BIT		1
#define C_BIT		0

/************EECR_BITS**********/
/**Internal EEPROM Control Register Bits*/
/*EEPROM Read Enable*/
#define EECR_EERE	0
/*EEPROM Write Enable*/
#define EECR_EEWE	1
/*EEPROM Master Write Enable*/
#define EECR_EEMWE	2
/*EEPROM Ready Interrupt Enable*/
#define EECR_EERIE	3


/***************TCCR1A_BITS**************/
#define COM1A1		7
#define COM1A0		6
#define COM1B1		5
#define COM1B0		4
#define FOC1A		3	/* Force Output Compare for Channel A*/
#define FOC1B		2	/* Force Output Compare for Channel B*/
#define WGM11		1
#define WGM10		0




/***************TCCR1B_BITS**************/
#define ICNC1		7	/*Input Capture Noise Canceler*/
#define ICES1		6	/*Input Capture Edge Select*/

#define WGM13		4
#define WGM12		3	
#define CS12		2	
#define CS11		1
#define CS10		0


/******************TWSR_BITS**************/

#define TWPS0		0
#define TWPS1		1

/******************TWCR_BITS**************/
#define TWINT		7	/*TWI Interrupt Flag*/
/*The TWINT Flag must be cleared by software by writing a logic one to it*/
/*this flag is not automatically cleared by hardware when executing the 
interrupt routine. Also note that clearing this flag starts the operation 
of the TWI, so all accesses to the TWI Address Register (TWAR), 
TWI Status Register (TWSR), and TWI Data Register (TWDR) must be complete
 before clearing this flag*/

#define TWEA		6	/*TWI Enable Acknowledge Bit*/

#define TWSTA		5	/*TWI START Condition Bit*/
#define TWSTO		4	/* TWI STOP Condition Bit*/
/*In slave mode, setting the TWSTO bit can be used to recover
from an error condition. This will not generate a STOP condition, but the TWI 
returns to a well-defined unaddressed slave mode and releases the SCL and SDA 
lines to a high impedance state.*/
#define TWWC		3	/*TWI Write Collision Flag*/
/*The TWWC bit is set when attempting to write to the TWI Data Register – TWDR when
TWINT is low. This flag is cleared by writing the TWDR Register when TWINT is high.*/
#define TWEN		2	/*TWI Enable Bit*/
#define TWIE		0	/*TWI Interrupt Enable*/


/******************MCUCR_BITS**************/
#define ISC11		3
#define ISC10		2
#define ISC01		1
#define ISC00		0

#define	ISC2		6

/******************GICR_BITS**************/
#define INT1		7
#define INT0		6
#define INT2		5

#endif /* BITS_H_ */