/*
 * ADC_Interface.h
 *
 *  Created on: Jun 17, 2023
 *      Author: Ahmed Hussein
 */

#ifndef MCAL_ADC_V1_ADC_INTERFACE_H_
#define MCAL_ADC_V1_ADC_INTERFACE_H_

#include "ADC_Config.h"
#include "ADC_Private.h"



void ADC_init(u8, u8);

u16 ADC_readChannel(u8 ADC_u8ChannelNum);



#endif /* MCAL_ADC_V1_ADC_INTERFACE_H_ */
