/*
 * TMR_Private.h
 *
 *  Created on: Jun 18, 2023
 *      Author: armmw
 */

#ifndef MCAL_TIMER_V1_TMR_PRIVATE_H_
#define MCAL_TIMER_V1_TMR_PRIVATE_H_

#define     TIM0_u8_TCCR0_REG		      *((volatile u8 *)(0x53))		// Timer/Counter0 Control Register
#define     TIM0_u8_TCCR0_FOC0            7								// Force On Compare
#define     TIM0_u8_TCCR0_WGM00           6                             // Wave Generation Mode 0
#define     TIM0_u8_TCCR0_COM01           5                             // Compare match output mode 1
#define     TIM0_u8_TCCR0_COM00           4                             // Compare match output mode 0
#define     TIM0_u8_TCCR0_WGM01           3                             // Wave Generation Mode 1
#define     TIM0_u8_TCCR0_CS02            2                             // Clock Select 02
#define     TIM0_u8_TCCR0_CS01            1                             // Clock Select 01
#define     TIM0_u8_TCCR0_CS00            0                             // Clock Select 00

#define     TIM0_u8_TCNT0_REG		      *((volatile u8 *)(0x52))		// Timer/Counter0 Register

#define     TIM0_u8_OCR0_REG		      *((volatile u8 *)(0x5C))		// Output Compare0 Register

#define     TIM0_u8_TIMSK_REG		      *((volatile u8 *)(0x59))		// Timer0 Mask Register
#define     TIM0_u8_TIMSK_TOIE0           0								// Timer Overflow Interrupt Enable
#define     TIM0_u8_TIMSK_OCIE0           1                             // Timer On Compare Interrupt Enable
#define		TIM0_u8_TIMSK_TOIE1		      2								// Timer/Counter1 Overflow Interrupt Enable
#define		TIM0_u8_TIMSK_OCIE1B	      3								// Timer/Counter1 Output Compare B Interrupt Enable
#define		TIM0_u8_TIMSK_OCIE1A	      4								// Timer/Counter1 Output Compare A Interrupt Enable
#define		TIM0_u8_TIMSK_TICIE1	      5								// Timer/Counter1 Input Capture Interrupt Enable
#define     TIM0_u8_TIMSK_TOIE2           6								// Timer/Counter2 Overflow Interrupt Enable
#define     TIM0_u8_TIMSK_OCIE2           7								// Timer/Counter2 Output Compare Interrupt Enable

#define     TIM0_u8_TIFR_REG              *((volatile u8 *)(0x58))		// Timer/Counter0 Interrupt Flag Register
#define     TIM0_u8_TIFR_TOV0             0								// Timer/Counter0 Overflow flag
#define     TIM0_u8_TIFR_OCF0             1                             // Timer/Counter0 Output Compare flag
#define		TIM0_u8_TIFR_TOV1		      2								// Timer/Counter1 Overflow Flag
#define		TIM0_u8_TIFR_OCF1B		      3								// Timer/Counter1 Output Compare B Flag
#define		TIM0_u8_TIFR_OCF1A		      4								// Timer/Counter1 Output Compare A Flag
#define		TIM0_u8_TIFR_ICF1		      5								// Timer/Counter1 Input Capture Flag
#define     TIM0_u8_TIFR_TOV2             6								// Timer/Counter2 Overflow flag
#define     TIM0_u8_TIFR_OCF2             7                             // Timer/Counter2 Output Compare flag



#endif /* MCAL_TIMER_V1_TMR_PRIVATE_H_ */
