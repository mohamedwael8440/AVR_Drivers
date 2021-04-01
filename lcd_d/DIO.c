#include "standardtypes.h"
#include "utils.h"
#include "registers.h"
#include "DIO.h"



void DIO_vidSetPinDir (u8 port,u8 pin,u8 dir)
{
	switch(port)
	{
	case 0:
		if(dir==input)
			Clr_Bit(DDRA,pin);
		if(dir==output)
			Set_Bit(DDRA,pin);
		break;

	case 1:
			if(dir==input)
				Clr_Bit(DDRB,pin);
			if(dir==output)
				Set_Bit(DDRB,pin);
			break;

	case 2:
			if(dir==input)
				Clr_Bit(DDRC,pin);
			if(dir==output)
				Set_Bit(DDRC,pin);
			break;

	case 3:
			if(dir==input)
				Clr_Bit(DDRD,pin);
			if(dir==output)
				Set_Bit(DDRD,pin);
			break;
	}
}

	void DIO_vidWritePinValue (u8 port,u8 pin,u8 value)
	{
		switch(port)
		{
		case 0:
			if(value==low)
				Clr_Bit(PORTA,pin);
			if(value==high)
				Set_Bit(PORTA,pin);
			break;

		case 1:
				if(value==low)
					Clr_Bit(PORTB,pin);
				if(value==high)
					Set_Bit(PORTB,pin);
				break;

		case 2:
				if(value==low)
					Clr_Bit(PORTC,pin);
				if(value==high)
					Set_Bit(PORTC,pin);
				break;

		case 3:
				if(value==low)
					Clr_Bit(PORTD,pin);
				if(value==high)
					Set_Bit(PORTD,pin);
				break;
		}
	}

	u8 DIO_u8ReadPinValue(u8 port, u8 pin)
	{
		switch(port)
		{
		case a:
			return Get_Bit(PINA,pin);
			break;
		case b:
			return Get_Bit(PINB,pin);
			break;
		case c:
			return Get_Bit(PINC,pin);
			break;
		case d:
			return Get_Bit(PIND,pin);
			break;
		default :
			return port;
			break;
		}


	}

	void DIO_vidSetPortDir(u8 port, u8 Dir)
		{
			switch(port)
			{
			case a:
				DDRA=Dir;
				break;
			case b:
				DDRB=Dir;
				break;
			case c:
				DDRC=Dir;
				break;
			case d:
				DDRD=Dir;
				break;

			}


		}

	void DIO_vidWritePortValue(u8 port, u8 Value)
			{
				switch(port)
				{
				case a:
					PORTA=Value;
					break;
				case b:
					PORTB=Value;
					break;
				case c:
					PORTC=Value;
					break;
				case d:
					PORTD=Value;
					break;

				}


			}






