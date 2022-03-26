/***********************************************************************************/
/* File Name : I2C_CFG.h														   */
/* File Info : Contains configuration options for I2C	                           */
/* Version   : V1.0                                                                */
/* Date      : 24 MAr. 2022                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Gaurd*********************************/
/***********************************************************************************/
#ifndef I2C_CFG_H_
#define I2C_CFG_H_

#define I2C_SLAVE_ADDRESS		0x02
#define I2C_TWBR_VALUE			12   /*for 8MHz and using TWI prescaler 0 TWBR should set to 12*/
#define I2C_EN_GENERAL_CALL		0


#endif /* I2C_CFG_H_ */