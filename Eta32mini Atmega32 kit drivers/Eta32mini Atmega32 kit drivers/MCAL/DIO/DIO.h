/***********************************************************************************/
/* File Name : DIO.h															   */
/* File Info : Contains functions prototypes for DIO	                           */
/* Version   : V1.0                                                                */
/* Date      : 06 MAr. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Gaurd*********************************/
/***********************************************************************************/
#ifndef DIO_H_
#define DIO_H_

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "DIO_CFG.h"
#include "REG.h"
#include "BIT_MATH.h"



/***********************************************************************************/
/*****************************User-defined data types*******************************/
/***********************************************************************************/
typedef enum{
	A	=	0	,
	B			,
	C			,
	D
}PORT_t;


typedef enum{
	PIN0	=	0	,
	PIN1			,
	PIN2			,
	PIN3			,
	PIN4			,
	PIN5			,
	PIN6			,
	PIN7			
}PIN_t;

typedef enum{
	OUT_LOW		=	0	,
	OUT_HIGH			
}OUTPUT_t;

typedef enum{
	INPUT_MODE	=	0	,
	OUTPUT_MODE	
}DIO_MODE_t;

typedef enum{
	PULL_UP_DIS	=	0	,
	PULL_UP_EN			,
	NOT_SET
}PULL_UP_t;


typedef struct{
	PORT_t		Port;
	PIN_t		Pin;
	DIO_MODE_t	Mode;
	PULL_UP_t	PullUpEn;
}DIO_t;


typedef struct{
	PORT_t		Port;
	u8			DataBitsMask;
	DIO_MODE_t	Mode;
	PULL_UP_t	PullUpEn;
}DIO_PORT_t;

typedef enum{
	_4_BIT_DATA		=	0	,
	_8_BIT_DATA
}DATA_LENGTH_t;
/***********************************************************************************/
/*******************************Functions prototypes********************************/
/***********************************************************************************/


/***********************************************************************************/
/* Function Name  : MDIO_vInitPin					                               */
/* Function Info  : Inits a pin										               */
/* Function Input : - Pin initing obj										       */
/* Function Return: None													       */
/***********************************************************************************/
void MDIO_vInitPin(DIO_t *);

/***********************************************************************************/
/* Function Name  : MDIO_vSetPinMode                                               */
/* Function Info  : Sets mode for a pin								               */
/* Function Input : - Pin number(PIN_t)										       */
/*					- Pin mode(DIO_MODE_t)										   */
/* Function Return: None													       */
/***********************************************************************************/
void MDIO_vSetPinMode(DIO_t *);


/***********************************************************************************/
/* Function Name  : MDIO_vWritePin	                                               */
/* Function Info  : Writes value on a pin							               */
/* Function Input : - Pin number(PIN_t)										       */
/*					- Output value(OUTPUT_t)									   */
/* Function Return: None													       */
/***********************************************************************************/
void MDIO_vWritePin(DIO_t *,OUTPUT_t);

/***********************************************************************************/
/* Function Name  : MDIO_vReadPin	                                               */
/* Function Info  : Gets value from a pin							               */
/* Function Input : - Pin number(PIN_t)										       */
/* Function Return: Output value(OUTPUT_t)									       */
/***********************************************************************************/
OUTPUT_t MDIO_tReadPin(DIO_t *);

/***********************************************************************************/
/* Function Name  : MDIO_vTogglePin	                                               */
/* Function Info  : Toggles value on a pin							               */
/* Function Input : - Pin number(PIN_t)										       */
/* Function Return: None													       */
/***********************************************************************************/
void MDIO_vTogglePin(DIO_t *);



/***********************************************************************************/
/* Function Name  : MDIO_vSetPullUpRes                                             */
/* Function Info  : Writes value on a pin							               */
/* Function Input : - Pin number(PIN_t)										       */
/*					- Pull up state(PULL_UP_t)									   */
/* Function Return: None													       */
/***********************************************************************************/
void MDIO_vSetPullUpRes(DIO_t *);


/***********************************************************************************/
/* Function Name  : MDIO_vInitPORT					                               */
/* Function Info  : Inits a pin										               */
/* Function Input : - Pointer to port obj									       */
/* Function Return: None													       */
/***********************************************************************************/
void MDIO_vInitPORT(DIO_PORT_t *);

/***********************************************************************************/
/* Function Name  : MDIO_vSetPortMode                                              */
/* Function Info  : Sets mode for a pin								               */
/* Function Input : - Pointer to port obj									       */
/*					- Pin mode(DIO_MODE_t)										   */
/* Function Return: None													       */
/***********************************************************************************/
void MDIO_vSetPortMode(DIO_PORT_t *);


/***********************************************************************************/
/* Function Name  : MDIO_vWritePin	                                               */
/* Function Info  : Writes value on a pin							               */
/* Function Input : -Pointer to port obj									       */
/*					- Output value(OUTPUT_t)									   */
/* Function Return: None													       */
/***********************************************************************************/
void MDIO_vWritePort(DIO_PORT_t *Ptr_tPort,u8 Copy_u8Data,PIN_t Copy_tStartPin,DATA_LENGTH_t Copy_tDataLength);

/***********************************************************************************/
/* Function Name  : MDIO_vReadPin	                                               */
/* Function Info  : Gets value from a port							               */
/* Function Input : - Pointer to port obj									       */
/* Function Return: Output value											       */
/***********************************************************************************/
u8 MDIO_tReadPort(DIO_PORT_t *);

/***********************************************************************************/
/* Function Name  : MDIO_vTogglePort	                                           */
/* Function Info  : Toggles value on a port							               */
/* Function Input : - Pointer to port obj									       */
/* Function Return: None													       */
/***********************************************************************************/
void MDIO_vTogglePort(DIO_PORT_t *);



/***********************************************************************************/
/* Function Name  : MDIO_vSetPullUpResForPort                                      */
/* Function Info  : Writes value on a pin							               */
/* Function Input : - Pointer to port obj									       */
/* Function Return: None													       */
/***********************************************************************************/
void MDIO_vSetPullUpResForPort(DIO_PORT_t *);

#endif /* DIO_H_ */