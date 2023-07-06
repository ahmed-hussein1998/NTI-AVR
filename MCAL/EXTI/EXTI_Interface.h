/*
 * EXTI_Interface.h
 *
 *  Created on: Jun 16, 2023
 *      Author: armmw
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


#include "EXTI_Private.h"
#include "EXTI_Config.h"
#include "../General/Bit_Macros.h"
#include "../General/STD_Types.h"



void EXTI_voidEXTIEnable(u8 EXTI_u8Num, u8 EXTI_u8Sense);



void EXTI_voidEXTIDisable(u8 EXTI_u8Num);

void EXTI_voidSetCallBack(void (*Ptr2Func) (void) , u8 u8EXTIIndex);


#endif /* EXTI_INTERFACE_H_ */
