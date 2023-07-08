/*
 * TMR_Config.h
 *
 *  Created on: Jun 18, 2023
 *      Author: armmw
 */

#ifndef MCAL_TIMER_V1_TMR_CONFIG_H_
#define MCAL_TIMER_V1_TMR_CONFIG_H_

#define 	  WAVEFORM_GEN_MODE          PWM_OR_PHASE_COTROL



#define 	 PRESCALER_TYPE     CLK_DIV_BY_8

#define 	 PRESCALER_MASK     0b11111000

#define    NORMAL_MODE      			                            0
#define    PWM_OR_PHASE_COTROL                                      1
#define    CTC_MODE                                                 2
#define    FAST_PWM_MODE                                            3

#define    NON_PWM_NORMAL_PORT_OPRETATION                           0
#define    NON_PWM_TOGGLE_OC0_ON_COMPARE_MATCH                      1
#define    NON_PWM_CLEAR_OC0_ON_COMPARE_MATCH                       2
#define    NON_PWM_SET_OC0_ON_COMPARE_MATCH						    3


#define    FAST_PWM_NORMAL_PORT_OPRETATION                          0
#define    FAST_PWM_CLEAR_OC0_ON_COMPARE_MATCH__SET_OC0_ON_TOP      1
#define    FAST_PWM_SET_OC0_ON_COMPARE_MATCH__CLEAR_OC0_ON_TOP	  	2


#define    CLK_DIV_BY_0										 	    1
#define    CLK_DIV_BY_8										 	    2
#define    CLK_DIV_BY_64                                            3
#define    CLK_DIV_BY_256                                           4
#define    CLK_DIV_BY_1024                                          5
#define    ECS_ON_T0_FALLING_EDGE      								6
#define    ECS_ON_T0_RISING_EDGE       								7

#define	   RISING_EDGE												0
#define	   FALLING_EDGE												1

#endif /* MCAL_TIMER_V1_TMR_CONFIG_H_ */
