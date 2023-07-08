/*
 * TMR_Program.c
 *
 *  Created on: Jun 18, 2023
 *      Author: armmw
 */


#include "TMR_Interface.h"
#include "STD_Types.h"
#include "Bit_Macros.h"
#include "DIO_Interface.h"




void (* TIMER_pvTimer0NotificationFunction)(void) = NULL;




void TMR_voidTimer0Init(void)
{
#if WAVEFORM_GEN_MODE == NORMAL_MODE
	/*Set Timer 0 in NORMAL_MODE*/
	CLEAR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM00);
	CLEAR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM01);

#elif WAVEFORM_GEN_MODE == PWM_OR_PHASE_COTROL
	/*Set Timer 0 in PWM_OR_PHASE_COTROL Mode*/
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM00);
	CLEAR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM01);

#elif WAVEFORM_GEN_MODE == CTC_MODE
	/*Set Timer 0 in CTC_MODE*/
	CLEAR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM00);
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM01);
	switch(NON_PWM_CLEAR_OC0_ON_COMPARE_MATCH)
	{
	case NON_PWM_NORMAL_PORT_OPRETATION:				/*Normal Port Operation*/
		CLEAR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
		CLEAR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
		break;
	case NON_PWM_TOGGLE_OC0_ON_COMPARE_MATCH:	        /*Toggle OC0 on Compare Match*/
		SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
		CLEAR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
		break;
	case NON_PWM_CLEAR_OC0_ON_COMPARE_MATCH:	        /*Clear OC0 on Compare Match*/
		CLEAR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
		SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
		break;
	case NON_PWM_SET_OC0_ON_COMPARE_MATCH:	            /*Set OC0 on Compare Match*/
		SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
		SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
		break;
	default: break;
	}

#elif WAVEFORM_GEN_MODE == FAST_PWM_MODE
	/*Set Timer 0 in FAST_PWM_MODE*/
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM00);
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_WGM01);
	switch(FAST_PWM_CLEAR_OC0_ON_COMPARE_MATCH__SET_OC0_ON_TOP)
	{

		case FAST_PWM_NORMAL_PORT_OPRETATION:						/*Normal Port Operation*/
			CLEAR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
			CLEAR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
			break;
		case FAST_PWM_CLEAR_OC0_ON_COMPARE_MATCH__SET_OC0_ON_TOP:	/*Set The "Clear On Compare, Sets On TOP" Mode (Non-Inverted)*/
			CLEAR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
			SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
			break;
		case FAST_PWM_SET_OC0_ON_COMPARE_MATCH__CLEAR_OC0_ON_TOP:	/*Set The "Set On Compare, Clear On TOP" Mode (Inverted)*/
			SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM00);
			SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_COM01);
			break;
		default: break;
	}
#endif



#if PRESCALER_TYPE == CLK_DIV_BY_0

	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_CS00);
	CLEAR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_CS01);
	CLEAR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_CS02);


#endif


#if PRESCALER_TYPE == CLK_DIV_BY_8

	CLEAR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_CS00);
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_CS01);
	CLEAR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_CS02);


#endif

#if PRESCALER_TYPE == CLK_DIV_BY_64

	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_CS00);
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_CS01);
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_CS02);


#endif

#if PRESCALER_TYPE == CLK_DIV_BY_256

	CLEAR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_CS00);
	CLEAR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_CS01);
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_CS02);


#endif


#if PRESCALER_TYPE == CLK_DIV_BY_1024

	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_CS00);
	CLEAR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_CS01);
	SET_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_CS02);


#endif

}



void TIMER_voidTimer0SetCallBack(void (*Copy_pvNotificationFunction)(void))
{


	TIMER_pvTimer0NotificationFunction = Copy_pvNotificationFunction;
}


void TIMER_voidTimer0SetCompareValue(u8 Copy_u8CompareValue)
{
	/*Set The Compare Value to the OCR0 Register*/
	TIM0_u8_OCR0_REG = Copy_u8CompareValue;
}


void TMR_voidTime0Stop()
{

	CLEAR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_CS00);
	CLEAR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_CS01);
	CLEAR_BIT(TIM0_u8_TCCR0_REG, TIM0_u8_TCCR0_CS02);
}


void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{

	TIMER_pvTimer0NotificationFunction();


}


