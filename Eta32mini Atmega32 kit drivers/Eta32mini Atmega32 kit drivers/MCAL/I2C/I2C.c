/***********************************************************************************/
/* File Name : I2C.c	                                                           */
/* File Info : Contains functions implementation					               */
/* Version   : V1.0                                                                */
/* Date      : 24 Mar 2021                                                         */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "I2C.h"
#include "LED.h"
#include "HELPER.h"
LED_t led= {C,PIN2};

/***********************************************************************************/
/* Function Name  : MI2C_vInit						                               */
/* Function Info  : Inits I2C										               */
/* Function Input : None													       */
/* Function Return: None													       */
/***********************************************************************************/
void MI2C_vInit(){
	TWSR =0x00;
	TWBR =0x47;
	TWCR = (1<<TWEN);
	HLED_vInit(&led);
	/*to set SCL to 400KHz*/
	/*sets prescaler to 0*/
	//CLR_BIT(TWSR,TWPS0);
	//CLR_BIT(TWSR,TWPS1);
	/*sets TWBR */
	//TWBR = I2C_TWBR_VALUE;

	/*sets slave address in case it is addressed*/
	//TWAR = (I2C_SLAVE_ADDRESS<<0x01);

	/*enables the recognition of a General Call*/
	//TWAR |= I2C_EN_GENERAL_CALL;

	/*TWI Enable Acknowledge Bit to send ACK*/
	//SET_BIT(TWCR,TWEA);


	/*TWI Enable interrupt*/
	/*SET_BIT(TWCR,TWIE);
	ENABLE_GLOBAL_INT();*/
	/*enables TWI*/
	/*SET_BIT(TWCR,TWEN);*/
	//TWI_START_OPERATION;
}

/***********************************************************************************/
/* Function Name  : MI2C_vStartCondition_Block		                               */
/* Function Info  : Sends Start Condition							               */
/* Function Input : None													       */
/* Function Return: None													       */
/***********************************************************************************/
void MI2C_vStartCondition_Block(){
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
	/*SET_BIT(TWCR,TWSTA);
	SET_BIT(TWCR,TWEN);
	TWI_START_OPERATION;*/
	//TWCR= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);    
	//while(GET_BIT(TWCR,TWINT)==0){}
	/*it will stay forever if NACK is RECEIVED*/
	/*while(GET_TWI_STATUS != TWI_TRANS_START_ACK){}*/
}

/***********************************************************************************/
/* Function Name  : MI2C_vStopCondition_Block		                               */
/* Function Info  : Sends Stop Condition							               */
/* Function Input : None													       */
/* Function Return: None													       */
/***********************************************************************************/
void MI2C_vStopCondition_Block(){
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
	/*SET_BIT(TWCR,TWSTO);
	SET_BIT(TWCR,TWEN);
	TWI_START_OPERATION;*/
}


/***********************************************************************************/
/* Function Name  : MI2C_vRepeatedStart_Block		                               */
/* Function Info  : Sends Repeated Start										   */
/* Function Input : None													       */
/* Function Return: None													       */
/***********************************************************************************/
void MI2C_vRepeatedStart_Block(){
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
	/*SET_BIT(TWCR,TWSTA);
	SET_BIT(TWCR,TWEN);
	TWI_START_OPERATION;
	while(GET_BIT(TWCR,TWINT)==0){}*/
	/*it will stay forever if NACK is RECEIVED*/
	/*while(GET_TWI_STATUS != TWI_TRANS_REP_ACK){}*/
}

/***********************************************************************************/
/* Function Name  : MI2C_vCallSlaveToWrite_Block	                               */
/* Function Info  : Sends byte to address the slave	to write					   */
/* Function Input : Slave Address											       */
/* Function Return: None													       */
/***********************************************************************************/
void MI2C_vCallSlaveToWrite_Block(u8 Copy_u8SlaveAddress){
	TWDR=Copy_u8SlaveAddress<<1;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
	//TWDR = (Copy_u8SlaveAddress<<0x01);
	/*clears Start condition*/
	/*CLR_BIT(TWCR,TWSTA);
	SET_BIT(TWCR,TWEN);
	TWI_START_OPERATION;
	while(GET_BIT(TWCR,TWINT)==0){}
	while(GET_TWI_STATUS != TWI_TRANS_SLW_ACK){}*/
}

/***********************************************************************************/
/* Function Name  : MI2C_vCallSlaveToRead_Block		                               */
/* Function Info  : Sends byte to address the slave	to read 					   */
/* Function Input : Slave Address											       */
/* Function Return: None													       */
/***********************************************************************************/
void MI2C_vCallSlaveToRead_Block(u8 Copy_u8SlaveAddress){
	TWDR=(Copy_u8SlaveAddress<<1) |(0x01);
	TWCR=(1<<TWINT)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
	/*TWDR = (Copy_u8SlaveAddress<<0x01)| (0x01);*/
	/*clears Start condition*/
	/*CLR_BIT(TWCR,TWSTA);
	SET_BIT(TWCR,TWEN);
	TWI_START_OPERATION;
	while(GET_BIT(TWCR,TWINT)==0){}
	while(GET_TWI_STATUS != TWI_TRANS_SLR_ACK){}*/
}


/***********************************************************************************/
/* Function Name  : MI2C_vSendByte_Block			                               */
/* Function Info  : Sends byte to  the slave				 					   */
/* Function Input : Data													       */
/* Function Return: None													       */
/***********************************************************************************/
void MI2C_vSendByte_Block(u8 Copy_u8Data){
	TWDR=Copy_u8Data;
	TWCR=(1<<TWINT)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
	//TWDR = Copy_u8Data;
	/*clears Start condition*/
	/*CLR_BIT(TWCR,TWSTA);
	SET_BIT(TWCR,TWEN);
	TWI_START_OPERATION;
	while(GET_BIT(TWCR,TWINT)==0){}
	while(GET_TWI_STATUS != TWI_TRANS_DATA_ACK){}*/
}

/***********************************************************************************/
/* Function Name  : MI2C_u8ReceiveByte_Block		                               */
/* Function Info  : Receive data from  the slave			 					   */
/* Function Input : None													       */
/* Function Return: Data													       */
/***********************************************************************************/
u8 MI2C_u8ReceiveByte_Block(){
	/*CLR_BIT(TWCR,TWSTA);
	CLR_BIT(TWCR,TWSTO);
	SET_BIT(TWCR,TWEA);
	SET_BIT(TWCR,TWEN);
	TWI_START_OPERATION;
	while(GET_BIT(TWCR,TWINT)==0){}
	while(GET_TWI_STATUS != TWI_REC_BYTE_ACK){}*/
	TWCR = (1<<TWINT)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
	return TWDR;
}


/***********************************************************************************/
/* Function Name  : MI2C_vSetCallback				                               */
/* Function Info  : Sets callback for I2C					 					   */
/* Function Input : Pointer to function										       */
/* Function Return: None													       */
/***********************************************************************************/
void MI2C_vSetCallback(void (*Ptr_Function)(void)){
	MTWI_CALLBACK= Ptr_Function;
}

/***********************************************************************************/
/* Function Name  : MI2C_u8GetStatus				                               */
/* Function Info  : Gets I2C status							 					   */
/* Function Input : None													       */
/* Function Return: TWI status												       */
/***********************************************************************************/
u8 MI2C_u8GetStatus(){
	return MTWI_STATUES;
}

/***********************************************************************************/
/* Function Info  : ISR to handle of Timer 0 clear on compare  match interrupt     */
/***********************************************************************************/
void __vector_19(void)  {
	HLED_vToggle(&led);
	MTWI_STATUES = TWSR&0xF8;
}