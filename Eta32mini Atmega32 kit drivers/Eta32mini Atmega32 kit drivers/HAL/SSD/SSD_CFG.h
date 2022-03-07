/***********************************************************************************/
/* File Name : SSD_CFG.h														   */
/* File Info : Contains configuration options for SSD	                           */
/* Version   : V1.0                                                                */
/* Date      : 06 MAr. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Gaurd*********************************/
/***********************************************************************************/
#ifndef SSD_CFG_H_
#define SSD_CFG_H_



/***********************************************************************************/
/***********************User-defined data types and Macros**************************/
/***********************************************************************************/

#define ONE_DIGIT_MODE			0
#define TWO_DIGITS_MODE			1
#define FOUR_DIGITS_MODE		2


#define WITHOUT_DECODER			0
#define WITH_DECODER			1

#define SSD_DISPLAY_DELAY		10
#define LOOP_MAX				50

/*	SSD modes options =>
*	ONE_DIGIT_MODE,
*	TWO_DIGITS_MODE,
*	FOUR_DIGITS_MODE
*/
#define SSD_MODE ONE_DIGIT_MODE


/*	SSD DECODER modes =>
*	WITH_DECODER
*	WITHOUT_DECODER
*/
#define SSD_DECODER_MODE WITHOUT_DECODER

/***********************************************************************************/
/* SSD Pins Configurations : - Data		=> PA1->PA7								   */
/*							 - SSD1_EN	=> PC6									   */
/*							 - SSD2_EN	=> PC7									   */
/***********************************************************************************/
#if SSD_MODE == ONE_DIGIT_MODE && SSD_DECODER_MODE == WITHOUT_DECODER
	static DIO_t SSD_PINA ={A,PIN1,OUTPUT_MODE,NOT_SET};
	static DIO_t SSD_PINB ={A,PIN2,OUTPUT_MODE,NOT_SET};
	static DIO_t SSD_PINC ={A,PIN3,OUTPUT_MODE,NOT_SET};
	static DIO_t SSD_PIND ={A,PIN4,OUTPUT_MODE,NOT_SET};
	static DIO_t SSD_PINE ={A,PIN5,OUTPUT_MODE,NOT_SET};
	static DIO_t SSD_PINF ={A,PIN6,OUTPUT_MODE,NOT_SET};
	static DIO_t SSD_PING ={A,PIN7,OUTPUT_MODE,NOT_SET};
	static DIO_t SSD1_En  ={C,PIN6,OUTPUT_MODE,NOT_SET};
#elif SSD_MODE == TWO_DIGITS_MODE && SSD_DECODER_MODE == WITHOUT_DECODER
	static DIO_t SSD_PINA ={A,PIN1,OUTPUT_MODE,NOT_SET};
	static DIO_t SSD_PINB ={A,PIN2,OUTPUT_MODE,NOT_SET};
	static DIO_t SSD_PINC ={A,PIN3,OUTPUT_MODE,NOT_SET};
	static DIO_t SSD_PIND ={A,PIN4,OUTPUT_MODE,NOT_SET};
	static DIO_t SSD_PINE ={A,PIN5,OUTPUT_MODE,NOT_SET};
	static DIO_t SSD_PINF ={A,PIN6,OUTPUT_MODE,NOT_SET};
	static DIO_t SSD_PING ={A,PIN7,OUTPUT_MODE,NOT_SET};
	static DIO_t SSD1_En  ={C,PIN6,OUTPUT_MODE,NOT_SET};
	static DIO_t SSD2_En  ={C,PIN7,OUTPUT_MODE,NOT_SET};
	
#elif SSD_MODE == ONE_DIGIT_MODE && SSD_DECODER_MODE == WITH_DECODER
	static DIO_t SSD_DECODER_PINA ={A,PIN1,OUTPUT_MODE,NOT_SET};
	static DIO_t SSD_DECODER_PINB ={A,PIN2,OUTPUT_MODE,NOT_SET};
	static DIO_t SSD_DECODER_PINC ={A,PIN3,OUTPUT_MODE,NOT_SET};
	static DIO_t SSD_DECODER_PIND ={A,PIN4,OUTPUT_MODE,NOT_SET};
#endif



#endif /* SSD_CFG_H_ */