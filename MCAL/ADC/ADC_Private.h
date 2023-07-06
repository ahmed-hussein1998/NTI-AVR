/*
 * ADC_Private.h
 *
 *  Created on: Jun 17, 2023
 *      Author: Ahmed Hussein
 */

#ifndef MCAL_ADC_V1_ADC_PRIVATE_H_
#define MCAL_ADC_V1_ADC_PRIVATE_H_

#include "../General/STD_Types.h"


#define ADC_u8_ADMUX_REG		*((volatile u8*) 27)
#define ADC_u8_ADCSRA_REG		*((volatile u8*) 26)
#define ADC_u8_ADCL_REG			*((volatile u8*) 24)
#define ADC_u8_ADCH_REG			*((volatile u8*) 25)
#define ADC_u8_SFIOR_REG		*((volatile u8*) 50)



#endif /* MCAL_ADC_V1_ADC_PRIVATE_H_ */
