 /******************************************************************************
 *
 * Module: TIMER 1
 *
 * File Name: timer1_private.h
 *
 * Author: Ahmed Hussein
 *
 *******************************************************************************/


#ifndef MCAL_TIMER1_TIMER1_PRIVATE_H_
#define MCAL_TIMER1_TIMER1_PRIVATE_H_

#include "timer1_config.h"

typedef struct{
	TIMER1_ModeTypes              TIMER1_Mode;
	TIMER1_PrescalerTypes         TIMER1_Prescaler;
	TIMER1_CompareOutputTypes     TIMER_CompareOutputA;
	TIMER1_CompareOutputTypes     TIMER_CompareOutputB;

}TIMER1_ConfigTypes;


#endif /* MCAL_TIMER1_TIMER1_PRIVATE_H_ */
