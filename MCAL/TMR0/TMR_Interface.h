/*
 * TMR_Interface.h
 *
 *  Created on: Jun 18, 2023
 *      Author: armmw
 */

#ifndef MCAL_TIMER_V1_TMR_INTERFACE_H_
#define MCAL_TIMER_V1_TMR_INTERFACE_H_

#include "TMR_Config.h"
#include "TMR_Private.h"
#include "STD_Types.h"



void TMR_voidTimer0Init(void);

void TIMER_voidTimer0SetCompareValue(u8 );

void TMR_voidTime0Stop(void);


void TIMER_voidTimer0SetCallBack(void (*Copy_pvNotificationFunction)(void));


#endif /* MCAL_TIMER_V1_TMR_INTERFACE_H_ */
