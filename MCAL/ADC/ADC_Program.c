/*
 * ACD_Program.c
 *
 *  Created on: Jun 17, 2023
 *      Author: Ahmed Hussein
 */
#include "ADC_Interface.h"
#include "../General/Bit_Macros.h"
#include "avr/io.h"



void ADC_voidInit(u8 ADC_VREF_Selection, u8 ADC_Prescaler_Selection)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 = 01 to choose AVCC = 5v as reference voltage
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
#if ADC_VREF_Selection == AREF_INTERNAL_VREF_OFF
	CLEAR_BIT(ADC_u8_ADMUX_REG,REFS0);
	CLEAR_BIT(ADC_u8_ADMUX_REG,REFS1);
#endif

#if ADC_VREF_Selection == AVCC_EXTERNAL_OCCILATOR_AT_AREF
	CLEAR_BIT(ADC_u8_ADMUX_REG,REFS0);
	CLEAR_BIT(ADC_u8_ADMUX_REG,REFS1);
#endif

#if ADC_VREF_Selection == INTERNAL_2_56_V_AT_AREF
	CLEAR_BIT(ADC_u8_ADMUX_REG,REFS0);
	CLEAR_BIT(ADC_u8_ADMUX_REG,REFS1);
#endif

#if ADC_Prescaler_Selection == ADC_PRESCALER_DIV_2
	CLEAR_BIT(ADC_u8_ADCSRA_REG,ADXPS0);
	CLEAR_BIT(ADC_u8_ADCSRA_REG,ADXPS1);
	CLEAR_BIT(ADC_u8_ADCSRA_REG,ADXPS1);
#endif

#if ADC_Prescaler_Selection == ADC_PRESCALER_DIV_4
	CLEAR_BIT(ADC_u8_ADCSRA_REG,ADXPS0);
	SET_BIT(ADC_u8_ADCSRA_REG,ADXPS1);
	CLEAR_BIT(ADC_u8_ADCSRA_REG,ADXPS1);
#endif

#if ADC_Prescaler_Selection == ADC_PRESCALER_DIV_8
	SET_BIT(ADC_u8_ADCSRA_REG,ADXPS0);
	SET_BIT(ADC_u8_ADCSRA_REG,ADXPS1);
	CLEAR_BIT(ADC_u8_ADCSRA_REG,ADXPS1);
#endif

#if ADC_Prescaler_Selection == ADC_PRESCALER_DIV_16
	CLEAR_BIT(ADC_u8_ADCSRA_REG,ADXPS0);
	CLEAR_BIT(ADC_u8_ADCSRA_REG,ADXPS1);
	SET_BIT(ADC_u8_ADCSRA_REG,ADXPS1);
#endif

#if ADC_Prescaler_Selection == ADC_PRESCALER_DIV_32
	SET_BIT(ADC_u8_ADCSRA_REG,ADXPS0);
	CLEAR_BIT(ADC_u8_ADCSRA_REG,ADXPS1);
	SET_BIT(ADC_u8_ADCSRA_REG,ADXPS1);
#endif

#if ADC_Prescaler_Selection == ADC_PRESCALER_DIV_64
	CLEAR_BIT(ADC_u8_ADCSRA_REG,ADXPS0);
	SET_BIT(ADC_u8_ADCSRA_REG,ADXPS1);
	SET_BIT(ADC_u8_ADCSRA_REG,ADXPS1);
#endif

#if ADC_Prescaler_Selection == ADC_PRESCALER_DIV_128
	SET_BIT(ADC_u8_ADCSRA_REG,ADXPS0);
	SET_BIT(ADC_u8_ADCSRA_REG,ADXPS1);
	SET_BIT(ADC_u8_ADCSRA_REG,ADXPS1);
#endif


	CLEAR_BIT(ADC_u8_ADMUX_REG,ADLAR);
	SET_BIT(ADC_u8_ADCSRA_REG,ADEN);
	SET_BIT(ADC_u8_ADCSRA_REG,ADIE);


//	ADC_u8_ADMUX_REG = (1<<REFS0);
//
//	/* ADCSRA Register Bits Description:
//	 * ADEN    = 1 Enable ADC
//	 * ADIE    = 0 Disable ADC Interrupt
//	 * ADATE   = 0 Disable Auto Trigger
//	 * ADPS2:0 = 111 to choose ADC_Clock = F_CPU/128 = 16Mhz/128 = 125Khz --> ADC must operate in range 50-200Khz
//	 */
//	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
}

u16 ADC_u16ReadChannel(u8 ADC_u8ChannelNum)
{
	ADC_u8ChannelNum &= 0x07; /* Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | ADC_u8ChannelNum; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}
