 /******************************************************************************
 *
 * Module: TIMER 1
 *
 * File Name: timer1_interface.h
 *
 * Author: Ahmed Hussein
 *
 *******************************************************************************/

#ifndef MCAL_TIMER1_TIMER1_INTERFACE_H_
#define MCAL_TIMER1_TIMER1_INTERFACE_H_

#include "STD_Types.h"
#include "timer1_private.h"

void TIMER1_voidInit(TIMER1_ConfigTypes * TIMER1_Config);
void TIMER1_voidStart(TIMER1_ConfigTypes * TIMER1_Config);
void TIMER1_voidDeinit(void);
void TIMER1_voidSetPreLoad(u8 value);
u8 TIMER1_voidGetPreLoad(void);
void TIMER1_voidSetCompareVal(TIMER1_ConfigTypes * TIMER1_Config,u16 value);
void TIMER1_voidSetDutyCycle(TIMER1_ConfigTypes * TIMER1_Config,u16 value);
void TIMER_setCallBackFunc(void volatile (*a_functionAddressPtr) (void));








#endif /* MCAL_TIMER1_TIMER1_INTERFACE_H_ */
