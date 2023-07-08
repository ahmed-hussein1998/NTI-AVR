/*
 * LCD_Config.h
 *
 *  Created on: Jun 16, 2023
 *      Author: armmw
 */

#ifndef MCAL_LCD_V1_LCD_CONFIG_H_
#define MCAL_LCD_V1_LCD_CONFIG_H_

#include "../../MCAL/DIO_V1/DIO_Interface.h"

#define LCD_DATA_BITS_MODE 4

#if((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))

#error "Number of Data bits should be equal to 4 or 8"

#endif


/* LCD HW Ports and Pins Ids */
#define LCD_RS_PORT_ID                 DIO_u8_PORTA
#define LCD_RS_PIN_ID                  DIO_u8_PIN3

#define LCD_E_PORT_ID                  DIO_u8_PORTA
#define LCD_E_PIN_ID                   DIO_u8_PIN2

#define LCD_u8_DATA_PORT               DIO_u8_PORTB

#if (LCD_DATA_BITS_MODE == 4)

#define LCD_DB0_PIN_ID                 DIO_u8_PIN0
#define LCD_DB1_PIN_ID                 DIO_u8_PIN1
#define LCD_DB2_PIN_ID                 DIO_u8_PIN2
#define LCD_DB4_PIN_ID                 DIO_u8_PIN4

#endif




#endif /* MCAL_LCD_V1_LCD_CONFIG_H_ */
