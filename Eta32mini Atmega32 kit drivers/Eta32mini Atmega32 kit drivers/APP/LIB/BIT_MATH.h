/***********************************************************************************/
/* File Name : BIT_MATH.h                                                          */
/* File Info : Contains Macro like functions to manipulate bits in registers       */
/* Version   : V1.0                                                                */
/* Date      : 06 Mar. 2021                                                        */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Gaurd*********************************/
/***********************************************************************************/
#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bit)   (reg |= (1<<bit))
#define CLR_BIT(reg,bit)   (reg &= ~(1<<bit))
#define TOG_BIT(reg,bit)   (reg ^= (1<<bit))
#define GET_BIT(REG,BIT)   ((REG >> BIT)&1)

#endif /* BIT_MATH_H_ */