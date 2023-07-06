

#include "DIO_Interface.h"


void DIO_voidSetPinDirection(u8 DIO_u8PortID, u8 DIO_u8PinID, u8 DIO_u8PinDirection)
{
	if((DIO_u8PortID <= DIO_u8_PORTD) && (DIO_u8PinID <= DIO_u8_PIN7))
	{
		if(DIO_u8PinDirection == DIO_u8_OUTPUT)
		{
			switch(DIO_u8PortID)
			{
			case DIO_u8_PORTA:SET_BIT(DIO_u8_DDRA_REG,DIO_u8PinID);break;
			case DIO_u8_PORTB:SET_BIT(DIO_u8_DDRB_REG,DIO_u8PinID);break;
			case DIO_u8_PORTC:SET_BIT(DIO_u8_DDRC_REG,DIO_u8PinID);break;
			case DIO_u8_PORTD:SET_BIT(DIO_u8_DDRD_REG,DIO_u8PinID);break;
			}
		}
		else if (DIO_u8PinDirection == DIO_u8_INPUT)
		{
			switch(DIO_u8PortID)
			{
			case DIO_u8_PORTA:CLEAR_BIT(DIO_u8_DDRA_REG,DIO_u8PinID);break;
			case DIO_u8_PORTB:CLEAR_BIT(DIO_u8_DDRB_REG,DIO_u8PinID);break;
			case DIO_u8_PORTC:CLEAR_BIT(DIO_u8_DDRC_REG,DIO_u8PinID);break;
			case DIO_u8_PORTD:CLEAR_BIT(DIO_u8_DDRD_REG,DIO_u8PinID);break;
			}
		}
	}
	else
	{
		// Do Nothing
	}

}


void DIO_voidSetPinValue(u8 DIO_u8PortID, u8 DIO_u8PinID, u8 DIO_u8PinValue)
{
	if((DIO_u8PortID <= DIO_u8_PORTD) && (DIO_u8PinID <= DIO_u8_PIN7))
	{
		if(DIO_u8PinValue == DIO_u8_HIGH)
		{
			switch(DIO_u8PortID)
			{
			case DIO_u8_PORTA:SET_BIT(DIO_u8_PORTA_REG,DIO_u8PinID);break;
			case DIO_u8_PORTB:SET_BIT(DIO_u8_PORTB_REG,DIO_u8PinID);break;
			case DIO_u8_PORTC:SET_BIT(DIO_u8_PORTC_REG,DIO_u8PinID);break;
			case DIO_u8_PORTD:SET_BIT(DIO_u8_PORTD_REG,DIO_u8PinID);break;
			}
		}
		else if (DIO_u8PinValue == DIO_u8_INPUT)
		{
			switch(DIO_u8PortID)
			{
			case DIO_u8_PORTA:CLEAR_BIT(DIO_u8_DDRA_REG,DIO_u8PinID);break;
			case DIO_u8_PORTB:CLEAR_BIT(DIO_u8_DDRB_REG,DIO_u8PinID);break;
			case DIO_u8_PORTC:CLEAR_BIT(DIO_u8_DDRC_REG,DIO_u8PinID);break;
			case DIO_u8_PORTD:CLEAR_BIT(DIO_u8_DDRD_REG,DIO_u8PinID);break;
			}
		}
	}
	else
	{
		// Do Nothing
	}
}




//DIO_voidTogglePin();
u8 DIO_u8ReadPinValue(u8 DIO_u8PortID, u8 DIO_u8PinID)
{
	u8 DIO_8uLocPinValue = DIO_u8_LOW;

		switch(DIO_u8PortID)
		{
		case DIO_u8_PORTA: DIO_8uLocPinValue = GET_BIT(DIO_u8_PINA_REG,DIO_u8PinID);break;
		case DIO_u8_PORTB: DIO_8uLocPinValue = GET_BIT(DIO_u8_PINB_REG,DIO_u8PinID);break;
		case DIO_u8_PORTC: DIO_8uLocPinValue = GET_BIT(DIO_u8_PINC_REG,DIO_u8PinID);break;
		case DIO_u8_PORTD: DIO_8uLocPinValue = GET_BIT(DIO_u8_PIND_REG,DIO_u8PinID);break;

		}
		return DIO_8uLocPinValue;
}


void DIO_voidSetPortDirection(u8 DIO_u8PinID, u8 DIO_u8PortDirection)
{
	switch(DIO_u8PinID)
	{
	case DIO_u8_PORTA:DIO_u8_DDRA_REG = DIO_u8PortDirection;	break;
	case DIO_u8_PORTB:DIO_u8_DDRB_REG = DIO_u8PortDirection;	break;
	case DIO_u8_PORTC:DIO_u8_DDRC_REG = DIO_u8PortDirection; 	break;
	case DIO_u8_PORTD:DIO_u8_DDRD_REG = DIO_u8PortDirection;	break;



	}
}
void DIO_voidSetPortValue(u8 DIO_u8PortID, u8 DIO_u8PortValue)
{
	switch(DIO_u8PortID)
	{
	case DIO_u8_PORTA:DIO_u8_PORTA_REG = DIO_u8PortValue; break;
	case DIO_u8_PORTB:DIO_u8_PORTB_REG = DIO_u8PortValue; break;
	case DIO_u8_PORTC:DIO_u8_PORTC_REG = DIO_u8PortValue; break;
	case DIO_u8_PORTD:DIO_u8_PORTD_REG = DIO_u8PortValue; break;

	}


}
//DIO_voidTogglePort();
u8 DIO_u8ReadPortValue(u8 DIO_u8PortID)
{

	u8 DIO_u8LocPortValue = DIO_u8_LOW;
	switch(DIO_u8PortID)
	{
	case DIO_u8_PORTA:DIO_u8LocPortValue = DIO_u8_PINA_REG; break;
	case DIO_u8_PORTB:DIO_u8LocPortValue = DIO_u8_PINB_REG;	break;
	case DIO_u8_PORTC:DIO_u8LocPortValue = DIO_u8_PINC_REG;	break;
	case DIO_u8_PORTD:DIO_u8LocPortValue = DIO_u8_PIND_REG;	break;

	}
	return DIO_u8LocPortValue;
}

