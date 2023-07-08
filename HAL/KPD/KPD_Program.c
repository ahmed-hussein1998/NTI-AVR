

#include <avr/io.h>
#include <util/delay.h>
#include "../General/STD_Types.h"




#include "KPD_Interface.h"



u8 KPD_Au8Keys [KPD_u8_ROW_NUM][KPD_u8_COL_NUM] = KPD_Au8_KEYS;

u8 KPD_Au8RowsPins[KPD_u8_ROW_NUM] = KPD_Au8ROWs;
u8 KPD_Au8ColsPins[KPD_u8_COL_NUM] = KPD_Au8Cols;

void KEYPAD_VoidInit(void)
{
	DIO_voidSetPinDirection(KPD_u8_C_PORT,DIO_u8_PIN0,DIO_u8_INPUT);
	DIO_voidSetPinDirection(KPD_u8_C_PORT,DIO_u8_PIN1,DIO_u8_INPUT);
	DIO_voidSetPinDirection(KPD_u8_C_PORT,DIO_u8_PIN2,DIO_u8_INPUT);
	DIO_voidSetPinDirection(KPD_u8_C_PORT,DIO_u8_PIN3,DIO_u8_INPUT);
	DIO_voidSetPinDirection(KPD_u8_R_PORT,DIO_u8_PIN4,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(KPD_u8_R_PORT,DIO_u8_PIN5,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(KPD_u8_R_PORT,DIO_u8_PIN6,DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(KPD_u8_R_PORT,DIO_u8_PIN7,DIO_u8_OUTPUT);

	DIO_voidSetPinValue(KPD_u8_C_PORT,DIO_u8_PIN0,DIO_u8_HIGH);
	DIO_voidSetPinValue(KPD_u8_C_PORT,DIO_u8_PIN1,DIO_u8_HIGH);
	DIO_voidSetPinValue(KPD_u8_C_PORT,DIO_u8_PIN2,DIO_u8_HIGH);
	DIO_voidSetPinValue(KPD_u8_C_PORT,DIO_u8_PIN3,DIO_u8_HIGH);
	DIO_voidSetPinValue(KPD_u8_R_PORT,DIO_u8_PIN4,DIO_u8_HIGH);
	DIO_voidSetPinValue(KPD_u8_R_PORT,DIO_u8_PIN5,DIO_u8_HIGH);
	DIO_voidSetPinValue(KPD_u8_R_PORT,DIO_u8_PIN6,DIO_u8_HIGH);
	DIO_voidSetPinValue(KPD_u8_R_PORT,DIO_u8_PIN7,DIO_u8_HIGH);

}


u8 KPD_u8GetPressedKey(void)
{
	u8 col, row, pin_value, key_value = KPD_KEY_NOT_PRESSED, flag;
	for(row=0; row<KPD_u8_ROW_NUM; row++)
	{
		DIO_voidSetPinValue(KPD_u8_R_PORT,KPD_Au8RowsPins[row] , DIO_u8_LOW);
		for(col=0; col<KPD_u8_COL_NUM; col++)
		{
			pin_value = DIO_u8ReadPinValue(KPD_u8_C_PORT, KPD_Au8ColsPins[col]);

			if(pin_value == DIO_u8_LOW)
			{
				_delay_ms(KPD_u8_DEBOUNCING_MS);
				pin_value = DIO_u8ReadPinValue(KPD_u8_C_PORT, KPD_Au8ColsPins[col]);

				while (pin_value == DIO_u8_LOW)
				{
					pin_value= DIO_u8ReadPinValue(KPD_u8_C_PORT, KPD_Au8ColsPins[col]); //Get row value
				}
				key_value = KPD_Au8Keys [row][col]; //Read
				flag = KPD_u8_FLAG_UP;
				break;
			}
		}
		DIO_voidSetPinValue(KPD_u8_R_PORT, KPD_Au8RowsPins[row], DIO_u8_HIGH);
		if (flag==KPD_u8_FLAG_UP)
		{
			break;
		}
	}
	return key_value;


}

