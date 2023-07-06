/*
 * ADC_Config.h
 *
 *  Created on: Jun 17, 2023
 *      Author: Ahmed Hussein
 */

#ifndef MCAL_ADC_V1_ADC_CONFIG_H_
#define MCAL_ADC_V1_ADC_CONFIG_H_

#define VOLTAGE_REFERENCE_SELECTION AVCC_EXTERNAL_OCCILATOR_AT_AREF


#define ADC_AREF_INTERNAL_VREF_OFF 				0
#define ADC_AVCC_EXTERNAL_OCCILATOR_AT_AREF 	1
#define ADC_INTERNAL_2_56_V_AT_AREF 			3


#define ADC_PRESCALER_DIV_2						1
#define ADC_PRESCALER_DIV_4						2
#define ADC_PRESCALER_DIV_8						3
#define ADC_PRESCALER_DIV_16					4
#define ADC_PRESCALER_DIV_32					5
#define ADC_PRESCALER_DIV_64					6
#define ADC_PRESCALER_DIV_128					7

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   5

#endif /* MCAL_ADC_V1_ADC_CONFIG_H_ */
