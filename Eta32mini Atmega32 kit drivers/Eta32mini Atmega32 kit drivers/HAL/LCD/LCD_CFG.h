/***********************************************************************************/
/* File Name : LCD_CFG.h														   */
/* File Info : Contains configuration options for SSD	                           */
/* Version   : V1.0                                                                */
/* Date      : 07 MAr. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Gaurd*********************************/
/***********************************************************************************/
#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "DIO.h"
/*TODO: use timer delay*/
#define F_CPU 8000000UL
#include "avr/delay.h"

/***********************************************************************************/
/***********************User-defined data types and Macros**************************/
/***********************************************************************************/
#define _4_BIT_MODE       4
#define _8_BIT_MODE       8
/*options -> _8_BIT_MODE  ,  _4_BIT_MODE*/
#define LCD_MODE       _4_BIT_MODE

/*LCD PINS should be adjacent*/
#define LCD_DATA_PIN_4        PIN3
#define LCD_DATA_PIN_5        PIN4
#define LCD_DATA_PIN_6        PIN5
#define LCD_DATA_PIN_7        PIN6
#define LCD_RS_PIN            PIN1
#define LCD_EN_PIN            PIN2
#if LCD_MODE     ==  _4_BIT_MODE
#define MASKING_PINS   MASKING_PINS_FUN(LCD_DATA_PIN_4,LCD_DATA_PIN_5,LCD_DATA_PIN_6,LCD_DATA_PIN_7)
static DIO_PORT_t	LCD		= {A,((1<<(LCD_DATA_PIN_4))|(1<<(LCD_DATA_PIN_5))|(1<<(LCD_DATA_PIN_6))|(1<<(LCD_DATA_PIN_7))),OUTPUT_MODE,NOT_SET};
#elif
static DIO_PORT_t	LCD		= {A,0xFF,OUTPUT_MODE,NOT_SET};
#endif
static DIO_t		LCD_EN	= {A,LCD_EN_PIN,OUTPUT_MODE,NOT_SET};
static DIO_t		LCD_RS	= {A,LCD_RS_PIN,OUTPUT_MODE,NOT_SET};

#endif /* LCD_CFG_H_ */