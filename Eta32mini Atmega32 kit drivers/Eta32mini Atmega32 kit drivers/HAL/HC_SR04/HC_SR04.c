/***********************************************************************************/
/* File Name : HC_SR04.c		                                                   */
/* File Info : Contains functions implementation					               */
/* Version   : V1.0                                                                */
/* Date      : 14 Mar 2021                                                         */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "HC_SR04.h"
#include "avr/delay.h"


/***********************************************************************************/
/* Function Name  : HHC_SR04_vInit					                               */
/* Function Info  : Inits a HC_SR04 module							               */
/* Function Input : A pointer to HC_SR04 initial obj						       */
/* Function Return: None													       */
/***********************************************************************************/
void HHC_SR04_vInit(HC_SR04_t* HC_SR04){
	MDIO_vInitPin(&HC_SR04->Trig);
	//MDIO_vInitPin(&HC_SR04->Echo);
	MTIMER_1_vInitICU(HC_SR04->Timer);
}

/***********************************************************************************/
/* Function Name  : HHC_SR04_u16GetDistance                                        */
/* Function Info  : Displays a character on LCD						               */
/* Function Input : A pointer to HC_SR04 initial obj						       */
/* Function Return: Distance from the front object							       */
/***********************************************************************************/
u16 HHC_SR04_u16GetDistance(HC_SR04_t* HC_SR04){
	MDIO_vWritePin(&HC_SR04->Trig,OUT_HIGH);
	_delay_ms(100);
	MDIO_vWritePin(&HC_SR04->Trig,OUT_LOW);
	u16 Loc_u16TicksOn = MTIMER_1_u16CalcOnTicks(HC_SR04->Timer);
	u32 tickTime = (HC_SR04->Timer->Prescaler*1000UL )/ CLK_FREQUENCY;	
	u16 Loc_u16Distance=(u32)Loc_u16TicksOn *17150UL *tickTime/1000;
	return Loc_u16TicksOn;
}
