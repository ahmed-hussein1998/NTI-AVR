 /******************************************************************************
 *
 * Module: TIMER 1
 *
 * File Name: timer1_config.h
 *
 * Author: Ahmed Hussein
 *
 *******************************************************************************/
#ifndef MCAL_TIMER1_TIMER1_CONFIG_H_
#define MCAL_TIMER1_TIMER1_CONFIG_H_

typedef enum{
	TIMER1_NORMAL,TIMER1_CTC_OCR1A=4,TIMER1_PWM_PHASE_CORRECT_ICR1=10,
	TIMER1_PWM_PHASE_CORRECT_OCR1A=11,TIMER1_CTC_ICR1=12,TIMER1_FAST_PWM_ICR1=14,
	TIMER1_FAST_PWM_OCR1A=15

}TIMER1_ModeTypes;

typedef enum{
	TIMER1_NO_CLK, TIMER1_F_CPU_1, TIMER1_F_CPU_8, TIMER1_F_CPU_64, TIMER1_F_CPU_256,
	TIMER1_F_CPU_1024,TIMER1_EXTERNAL_CLK_RISING, TIMER1_EXTERNAL_CLK_FALLING
}TIMER1_PrescalerTypes;

typedef enum{
	DISCONNECT_OCX, TOGGLE_OCX, CLEAR_OCX_NONINVERTING, SET_OCX_INVERTING
}TIMER1_CompareOutputTypes;




#endif /* MCAL_TIMER1_TIMER1_CONFIG_H_ */
