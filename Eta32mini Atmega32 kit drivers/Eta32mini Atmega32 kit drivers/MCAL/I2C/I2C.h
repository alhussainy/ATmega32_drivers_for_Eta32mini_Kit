/***********************************************************************************/
/* File Name : I2C.h															   */
/* File Info : Contains functions prototypes for I2C	                           */
/* Version   : V1.0                                                                */
/* Date      : 24 MAr. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Gaurd*********************************/
/***********************************************************************************/
#ifndef I2C_H_
#define I2C_H_



/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "REG.h"
#include "BITS.h"
#include "I2C_CFG.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/***********************************************************************************/
/*****************************User-defined data types*******************************/
/***********************************************************************************/

static volatile void (*MTWI_CALLBACK)(void);
static volatile	u8 MTWI_STATUES = 0;
typedef enum{
	TWI_TRANS_START_ACK		=	0x08,
	TWI_TRANS_REP_ACK		=	0x10,
	TWI_TRANS_SLW_ACK		=	0x18,
	TWI_TRANS_SLW_NACK		=	0x20,
	TWI_TRANS_DATA_ACK		=	0x28,
	TWI_TRANS_ARB_LOST		=	0x38,
	TWI_TRANS_SLR_ACK		=	0x40,
	TWI_TRANS_SLR_NACK		=	0x48,
	TWI_REC_BYTE_ACK		=	0x50,
	TWI_REC_BYTE_NACK		=	0x58,
}TWI_STATUS_t;
/***********************************************************************************/
/*******************************Macro like function*********************************/
/***********************************************************************************/
#define GET_TWI_STATUS				(TWSR&0xF8)
#define TWI_START_OPERATION			SET_BIT(TWCR,TWINT)
#define TWI_OPERATION_END_CONDITION	(GET_BIT(TWCR,TWINT)==0)
/***********************************************************************************/
/*******************************Functions prototypes********************************/
/***********************************************************************************/


/***********************************************************************************/
/* Function Name  : MI2C_vInit						                               */
/* Function Info  : Inits I2C										               */
/* Function Input : None													       */
/* Function Return: None													       */
/***********************************************************************************/
void MI2C_vInit();

/***********************************************************************************/
/* Function Name  : MI2C_vStartCondition_Block		                               */
/* Function Info  : Sends Start Condition							               */
/* Function Input : None													       */
/* Function Return: None													       */
/***********************************************************************************/
void MI2C_vStartCondition_Block();

/***********************************************************************************/
/* Function Name  : MI2C_vStopCondition_Block		                               */
/* Function Info  : Sends Stop Condition							               */
/* Function Input : None													       */
/* Function Return: None													       */
/***********************************************************************************/
void MI2C_vStopCondition_Block();


/***********************************************************************************/
/* Function Name  : MI2C_vRepeatedStart_Block		                               */
/* Function Info  : Sends Repeated Start										   */
/* Function Input : None													       */
/* Function Return: None													       */
/***********************************************************************************/
void MI2C_vRepeatedStart_Block();

/***********************************************************************************/
/* Function Name  : MI2C_vCallSlaveToWrite_Block	                               */
/* Function Info  : Sends byte to address the slave	to write					   */
/* Function Input : Slave Address											       */
/* Function Return: None													       */
/***********************************************************************************/
void MI2C_vCallSlaveToWrite_Block(u8);

/***********************************************************************************/
/* Function Name  : MI2C_vCallSlaveToRead_Block		                               */
/* Function Info  : Sends byte to address the slave	to read 					   */
/* Function Input : Slave Address											       */
/* Function Return: None													       */
/***********************************************************************************/
void MI2C_vCallSlaveToRead_Block(u8);


/***********************************************************************************/
/* Function Name  : MI2C_vSendByte_Block			                               */
/* Function Info  : Sends byte to  the slave				 					   */
/* Function Input : Data													       */
/* Function Return: None													       */
/***********************************************************************************/
void MI2C_vSendByte_Block(u8);

/***********************************************************************************/
/* Function Name  : MI2C_u8ReceiveByte_Block		                               */
/* Function Info  : Receive data from  the slave			 					   */
/* Function Input : None													       */
/* Function Return: Data													       */
/***********************************************************************************/
u8 MI2C_u8ReceiveByte_Block();



/***********************************************************************************/
/* Function Name  : MI2C_vSetCallback				                               */
/* Function Info  : Sets callback for I2C					 					   */
/* Function Input : Pointer to function										       */
/* Function Return: None													       */
/***********************************************************************************/
void MI2C_vSetCallback(void (*Ptr_Function)(void));

/***********************************************************************************/
/* Function Name  : MI2C_u8GetStatus				                               */
/* Function Info  : Gets I2C status							 					   */
/* Function Input : None													       */
/* Function Return: TWI status												       */
/***********************************************************************************/
u8 MI2C_u8GetStatus();

/***********************************************************************************/
/* Function Info  : ISR to handle of TWI interrupt								   */
/***********************************************************************************/
void __vector_19(void)     __attribute__((signal));


#endif /* I2C_H_ */