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


/***************EEPROM_BITS**************/

#endif /* BITS_H_ */