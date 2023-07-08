/*
 * LCD_Program.c
 *
 *  Created on: Jun 16, 2023
 *      Author: armmw
 */

#include <util/delay.h>
#include "LCD_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"

#include "../../MCAL/DIO_V1/DIO_Interface.h"


void LCD_init(void)
{
	/* Configure the direction for RS and E pins as output pins */
	DIO_voidSetPinDirection(LCD_RS_PORT_ID,LCD_RS_PIN_ID,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(LCD_E_PORT_ID,LCD_E_PIN_ID,DIO_u8_OUTPUT);

	_delay_ms(20);		/* LCD Power ON delay always > 15ms */


#if(LCD_DATA_BITS_MODE == 4)
	/* Configure 4 pins in the data port as output pins */
	DIO_voidSetPinDirection(LCD_u8_DATA_PORT,LCD_DB0_PIN_ID,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(LCD_u8_DATA_PORT,LCD_DB1_PIN_ID,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(LCD_u8_DATA_PORT,LCD_DB2_PIN_ID,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(LCD_u8_DATA_PORT,LCD_DB4_PIN_ID,DIO_u8_OUTPUT);

	/* Send for 4 bit initialization of LCD  */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

	/* use 2-lines LCD + 4-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_FOUR_BITS_MODE);

#elif(LCD_DATA_BITS_MODE == 8)
	/* Configure the data port as output port */
	DIO_voidSetPortDirection(LCD_u8_DATA_PORT,PORT_OUTPUT);

	/* use 2-lines LCD + 8-bits Data Mode + 5*7 dot display Mode */
	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);

#endif

	LCD_sendCommand(LCD_CURSOR_OFF); /* cursor off */
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* clear LCD at the beginning */
}

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(u8 command)
{
	DIO_voidSetPinValue(LCD_RS_PORT_ID,LCD_RS_PIN_ID,DIO_u8_LOW); /* Instruction Mode RS=0 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	DIO_voidSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,DIO_u8_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

#if(LCD_DATA_BITS_MODE == 4)
	DIO_voidSetPinValue(LCD_u8_DATA_PORT,LCD_DB0_PIN_ID,GET_BIT(command,0));
	DIO_voidSetPinValue(LCD_u8_DATA_PORT,LCD_DB1_PIN_ID,GET_BIT(command,1));
	DIO_voidSetPinValue(LCD_u8_DATA_PORT,LCD_DB2_PIN_ID,GET_BIT(command,2));
	DIO_voidSetPinValue(LCD_u8_DATA_PORT,LCD_DB4_PIN_ID,GET_BIT(command,4));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_voidSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,DIO_u8_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	DIO_voidSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,DIO_u8_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	DIO_voidSetPinValue(LCD_u8_DATA_PORT,LCD_DB0_PIN_ID,GET_BIT(command,0));
	DIO_voidSetPinValue(LCD_u8_DATA_PORT,LCD_DB1_PIN_ID,GET_BIT(command,1));
	DIO_voidSetPinValue(LCD_u8_DATA_PORT,LCD_DB2_PIN_ID,GET_BIT(command,2));
	DIO_voidSetPinValue(LCD_u8_DATA_PORT,LCD_DB4_PIN_ID,GET_BIT(command,4));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_voidSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,DIO_u8_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */

#elif(LCD_DATA_BITS_MODE == 8)
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,command); /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_voidSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,DIO_u8_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
#endif
}

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(u8 data)
{
	DIO_voidSetPinValue(LCD_RS_PORT_ID,LCD_RS_PIN_ID,DIO_u8_HIGH); /* Data Mode RS=1 */
	_delay_ms(1); /* delay for processing Tas = 50ns */
	DIO_voidSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,DIO_u8_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

#if(LCD_DATA_BITS_MODE == 4)
	DIO_voidSetPinValue(LCD_u8_DATA_PORT,LCD_DB0_PIN_ID,GET_BIT(data,4));
	DIO_voidSetPinValue(LCD_u8_DATA_PORT,LCD_DB1_PIN_ID,GET_BIT(data,5));
	DIO_voidSetPinValue(LCD_u8_DATA_PORT,LCD_DB2_PIN_ID,GET_BIT(data,6));
	DIO_voidSetPinValue(LCD_u8_DATA_PORT,LCD_DB4_PIN_ID,GET_BIT(data,7));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_voidSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,DIO_u8_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
	DIO_voidSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,DIO_u8_HIGH); /* Enable LCD E=1 */
	_delay_ms(1); /* delay for processing Tpw - Tdws = 190ns */

	DIO_voidSetPinValue(LCD_u8_DATA_PORT,LCD_DB0_PIN_ID,GET_BIT(data,0));
	DIO_voidSetPinValue(LCD_u8_DATA_PORT,LCD_DB1_PIN_ID,GET_BIT(data,1));
	DIO_voidSetPinValue(LCD_u8_DATA_PORT,LCD_DB2_PIN_ID,GET_BIT(data,2));
	DIO_voidSetPinValue(LCD_u8_DATA_PORT,LCD_DB4_PIN_ID,GET_BIT(data,3));

	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_voidSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,DIO_u8_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */

#elif(LCD_DATA_BITS_MODE == 8)
	DIO_voidSetPinValue(LCD_DATA_PORT_ID,data); /* out the required command to the data bus D0 --> D7 */
	_delay_ms(1); /* delay for processing Tdsw = 100ns */
	DIO_voidSetPinValue(LCD_E_PORT_ID,LCD_E_PIN_ID,DIO_u8_LOW); /* Disable LCD E=0 */
	_delay_ms(1); /* delay for processing Th = 13ns */
#endif
}

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(const char *Str)
{
	u8 i = 0;
	while(Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}

}

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(u8 row,u8 col)
{
	u8 lcd_memory_address;

	/* Calculate the required address in the LCD DDRAM */
	switch(row)
	{
		case 0:
			lcd_memory_address=col;
				break;
		case 1:
			lcd_memory_address=col+0x40;
				break;
		case 2:
			lcd_memory_address=col+0x10;
				break;
		case 3:
			lcd_memory_address=col+0x50;
				break;
	}
	/* Move the LCD cursor to this specific address */
	LCD_sendCommand(lcd_memory_address | LCD_SET_CURSOR_LOCATION);
}

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(u8 row,u8 col,const char *Str)
{
	LCD_moveCursor(row,col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToString(int data)
{
   char buff[16]; /* String to hold the ascii result */
   itoa(data,buff,10); /* Use itoa C function to convert the data to its corresponding ASCII value, 10 for decimal */
   LCD_displayString(buff); /* Display the string */
}

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND); /* Send clear display command */
}
