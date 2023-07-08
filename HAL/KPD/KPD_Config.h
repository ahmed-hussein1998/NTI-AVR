/*
 * KEYPAD_Config.h
 *
 *  Created on: Jun 12, 2023
 *      Author: armmw
 */

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_u8_C_PORT       DIO_u8_PORTD
#define KPD_u8_R_PORT       DIO_u8_PORTC

#define KPD_u8_C1_PIN     DIO_u8_PIN7
#define KPD_u8_C2_PIN     DIO_u8_PIN6
#define KPD_u8_C3_PIN     DIO_u8_PIN5
#define KPD_u8_C4_PIN     DIO_u8_PIN3

#define KPD_u8_R1_PIN     DIO_u8_PIN5
#define KPD_u8_R2_PIN     DIO_u8_PIN4
#define KPD_u8_R3_PIN     DIO_u8_PIN3
#define KPD_u8_R4_PIN     DIO_u8_PIN2

#define KPD_u8_ROW_NUM     4
#define KPD_u8_COL_NUM     4

#define KPD_u8_DEBOUNCING_MS    20
#define KPD_KEY_NOT_PRESSED     0xFF


#define KPD_Au8_KEYS   {{'1', '2', '3', '+'}, \
						   {'4', '5', '6', '-'}, \
						   {'7', '8', '9', '*'}, \
						   {'0', '=', '%', '/'}}

#define KPD_Au8Cols  {KPD_u8_C1_PIN, KPD_u8_C2_PIN, KPD_u8_C3_PIN, KPD_u8_C4_PIN}
#define KPD_Au8ROWs  {KPD_u8_R1_PIN, KPD_u8_R2_PIN, KPD_u8_R3_PIN, KPD_u8_R4_PIN}



#endif /* KPD_CONFIG_H_ */
