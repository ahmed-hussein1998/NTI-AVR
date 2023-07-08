/******************************************************************************
 *
 * Module: TIMER 1
 *
 * File Name: timer1_programe.c
 *
 * Author: Ahmed Hussein
 *
 *******************************************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
#include"Bit_Macros.h"
#include"DIO_Interface.h"
#include "STD_Types.h"
#include "timer1_interface.h"
#include "timer1_config.h"
#include "timer1_private.h"

static volatile void (*g_callBackPtr)(void) = NULL_PTR;

ISR(TIMER1_OVF_vect){
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}

ISR(TIMER1_COMPA_vect){
	if(g_callBackPtr != NULL_PTR)
	{
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}



void TIMER1_voidInit(TIMER1_ConfigTypes * TIMER1_Config){
	TCCR1A|=((TIMER1_Config->TIMER1_Mode)&0x03);
	TCCR1B|=((((TIMER1_Config->TIMER1_Mode)>>2)&0x03)<<WGM12);
	if((TIMER1_Config->TIMER1_Mode==TIMER1_NORMAL)||(TIMER1_Config->TIMER1_Mode==TIMER1_CTC_OCR1A)||(TIMER1_Config->TIMER1_Mode==TIMER1_CTC_ICR1)){
		TCCR1A|= (1<<FOC1A) | (1<<FOC1B);
	}
	if((TIMER1_Config->TIMER_CompareOutputA==TOGGLE_OCX)||(TIMER1_Config->TIMER_CompareOutputA==CLEAR_OCX_NONINVERTING)||(TIMER1_Config->TIMER_CompareOutputA==SET_OCX_INVERTING)){
		DIO_voidSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN5 ,DIO_u8_OUTPUT);
	}
	if((TIMER1_Config->TIMER_CompareOutputB==TOGGLE_OCX)||(TIMER1_Config->TIMER_CompareOutputB==CLEAR_OCX_NONINVERTING)||(TIMER1_Config->TIMER_CompareOutputB==SET_OCX_INVERTING)){
		DIO_voidSetPinDirection(DIO_u8_PORTD,DIO_u8_PIN4 ,DIO_u8_OUTPUT);
	}

}

void TIMER1_voidStart(TIMER1_ConfigTypes * TIMER1_Config){
	TCCR1A|= ((TIMER1_Config->TIMER_CompareOutputB)<<COM1B0)|((TIMER1_Config->TIMER_CompareOutputA)<<COM1A0);
	TCCR1B|= TIMER1_Config->TIMER1_Prescaler;
	if(TIMER1_Config->TIMER1_Mode==TIMER1_NORMAL){
		TIMSK|=(1<<TOIE1);
	}
	else if((TIMER1_Config->TIMER1_Mode==TIMER1_CTC_OCR1A)||(TIMER1_Config->TIMER1_Mode==TIMER1_CTC_ICR1)){
		TIMSK|=(1<<OCIE1A);
	}
}

void TIMER1_voidSetPreLoad(u8 value){
	TCNT1=value;
}
u8 TIMER1_voidGetPreLoad(void){
	return TCNT1;
}

void TIMER1_voidSetCompareVal(TIMER1_ConfigTypes * TIMER1_Config,u16 value){
	if(TIMER1_Config->TIMER1_Mode==TIMER1_CTC_OCR1A){
		OCR1A=value;
	}
	else if(TIMER1_Config->TIMER1_Mode==TIMER1_CTC_ICR1){
		ICR1=value;
	}
}

void TIMER1_voidSetDutyCycle(TIMER1_ConfigTypes * TIMER1_Config,u16 value){
	if((TIMER1_Config->TIMER1_Mode==TIMER1_PWM_PHASE_CORRECT_OCR1A)||(TIMER1_Config->TIMER1_Mode==TIMER1_FAST_PWM_OCR1A)){
		OCR1A=value;
	}
	else if((TIMER1_Config->TIMER1_Mode==TIMER1_PWM_PHASE_CORRECT_ICR1)||(TIMER1_Config->TIMER1_Mode==TIMER1_FAST_PWM_ICR1)){
		ICR1=value;
	}
}

void TIMER_setCallBackFunc(void volatile (*a_functionAddressPtr) (void)){
	g_callBackPtr = a_functionAddressPtr;
}
void TIMER1_voidDeinit(void){
	TCCR1A=0;
	TCCR1B=0;
	TIMSK&=0xC3;
}
