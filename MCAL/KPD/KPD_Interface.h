/*
 * KPD_Interface.h
 *
 *  Created on: Jun 16, 2023
 *      Author: armmw
 */

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

#include "KPD_Config.h"
#include "KPD_Private.h"

#include "../DIO_V1/DIO_Interface.h"

void KPD_voidInit(void);
u8 KPD_u8GetPressedKey (void);




#endif /* KPD_INTERFACE_H_ */
