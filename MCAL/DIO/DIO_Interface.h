/*
 * DIO_Interface.h
 *
 *  Created on: Jun 14, 2023
 *      Author: armmw
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "DIO_Config.h"
#include "DIO_Private.h"
#include "../General/STD_Types.h"
#include "../General/Bit_Macros.h"

void DIO_voidSetPinDirection(u8 DIO_u8PortID, u8 DIO_u8PinID, u8 DIO_u8PinDirection);
void DIO_voidSetPinValue(u8 DIO_u8PortID, u8 DIO_u8PinID, u8 DIO_u8PinValue);
u8 DIO_u8ReadPinValue(u8 DIO_u8PortID, u8 DIO_u8PinID);
void DIO_voidSetPortDirection(u8 DIO_u8PinID, u8 DIO_u8PortDirection);
void DIO_voidSetPortValue(u8 DIO_u8PortID, u8 DIO_u8PortValue);
u8 DIO_u8ReadPortValue(u8 DIO_u8PortID);











#endif /* DIO_INTERFACE_H_ */
