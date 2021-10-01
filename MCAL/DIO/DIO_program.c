#include "../../LIB/bitmath.h"
#include "../../LIB/STD_TYPES.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidSetPinDirection (u8 Copy_u8PortName , u8 Copy_u8PinName , u8 Copy_u8PinMode)
{//function to set pin direction
	switch(Copy_u8PortName)
	{
		case PORTA:
		switch(Copy_u8PinMode)
		{
			case INPUT:
			CLR_BIT(DIO_DDRA,Copy_u8PinName);
			break;
			case OUTPUT:
			SET_BIT(DIO_DDRA,Copy_u8PinName);
			break;
		}
		break;
		case PORTB:
		switch(Copy_u8PinMode)
		{
			case INPUT:
			CLR_BIT(DIO_DDRB,Copy_u8PinName);
			break;
			case OUTPUT:
			SET_BIT(DIO_DDRB,Copy_u8PinName);
			break;
		}
		break;
		case PORTC:
		switch(Copy_u8PinMode)
		{
			case INPUT:
			CLR_BIT(DIO_DDRC,Copy_u8PinName);
			break;
			case OUTPUT:
			SET_BIT(DIO_DDRC,Copy_u8PinName);
			break;
		}
		break;
		case PORTD:
		switch(Copy_u8PinMode)
		{
			case INPUT:
			CLR_BIT(DIO_DDRD,Copy_u8PinName);
			break;
			case OUTPUT:
			SET_BIT(DIO_DDRD,Copy_u8PinName);
			break;
		}
		break;
	}
}

void DIO_voidSetPinValue (u8 Copy_u8PortName , u8 Copy_u8PinName , u8 Copy_u8PinState)
{//function to set pin value
	switch(Copy_u8PortName)
	{
		case PORTA :
		switch(Copy_u8PinState)
		{
			case LOW :
//case NOPULLUP :
			CLR_BIT(DIO_PORTA,Copy_u8PinName);
			break;
			case HIGH :
			//case PULLUP :
			SET_BIT(DIO_PORTA,Copy_u8PinName);
			break;
		}
		break;
		case PORTB :
		switch(Copy_u8PinState)
		{
			case LOW :
			//case NOPULLUP :
			CLR_BIT(DIO_PORTB,Copy_u8PinName);
			break;
			case HIGH :
			//case PULLUP :
			SET_BIT(DIO_PORTB,Copy_u8PinName);
			break;
		}
		break;
		case PORTC :
		switch(Copy_u8PinState)
		{
			case LOW :
			//case NOPULLUP :
			CLR_BIT(DIO_PORTC,Copy_u8PinName);
			break;
			case HIGH :
			//case PULLUP :
			SET_BIT(DIO_PORTC,Copy_u8PinName);
			break;
		}
		break;
		case PORTD :
		switch(Copy_u8PinState)
		{
			case LOW :
			//case NOPULLUP :
			CLR_BIT(DIO_PORTD,Copy_u8PinName);
			break;
			case HIGH :
			//case PULLUP :
			SET_BIT(DIO_PORTD,Copy_u8PinName);
			break;
		}
		break;
	}
}

u8 DIO_u8GetPinValue (u8 Copy_u8PortName,u8 Copy_u8PinName)
{//function to get a specific pin value
	switch (Copy_u8PortName)
	{
		case PORTA :
		return GET_BIT(DIO_PINA,Copy_u8PinName);
		case PORTB :
		return GET_BIT(DIO_PINB,Copy_u8PinName);
		case PORTC :
		return GET_BIT(DIO_PINC,Copy_u8PinName);
		case PORTD :
		return GET_BIT(DIO_PIND,Copy_u8PinName);
		
	}
}

void DIO_voidSetPortDirection (u8 Copy_u8PortName,u8 Copy_u8PortMode)
{//function to set the whole port Direction
	switch (Copy_u8PortName)
	{
		case PORTA :
		switch (Copy_u8PortMode)
		{
			case INPUT:
			DIO_DDRA=INPUT_PORT_VALUE;
			break;
			case OUTPUT:
			DIO_DDRA=OUTPUT_PORT_VALUE;
			break;
		}
		
		break;
		case PORTB :
		switch (Copy_u8PortMode)
		{
			case INPUT:
			DIO_DDRB=INPUT_PORT_VALUE;
			break;
			case OUTPUT:
			DIO_DDRB=OUTPUT_PORT_VALUE;
			break;
		}
		break;
		case PORTC :
		switch (Copy_u8PortMode)
		{
			case INPUT:
			DIO_DDRC=INPUT_PORT_VALUE;
			break;
			case OUTPUT:
			DIO_DDRC=OUTPUT_PORT_VALUE;
			break;
		}
		break;
		case PORTD :
		switch (Copy_u8PortMode)
		{
			case INPUT:
			DIO_DDRD=INPUT_PORT_VALUE;
			break;
			case OUTPUT:
			DIO_DDRD=OUTPUT_PORT_VALUE;
			break;
		}
		break;
	}
}

void DIO_voidSetPortValue (u8 Copy_u8PortName , u8 Copy_u8PortState)
{//function to set the whole port value
	switch(Copy_u8PortName)
	{
		case PORTA :
		switch(Copy_u8PortState)
		{
			case LOW :
			//case NOPULLUP :
			DIO_PORTA=LOW_NOPULLUP_PORT_VALUE;
			break;
			case HIGH :
			//case PULLUP :
			DIO_PORTA=HIGH_PULLUP_PORT_VALUE;
			break;
		}
		break;
		case PORTB :
		switch(Copy_u8PortState)
		{
			case LOW :
			//case NOPULLUP :
			DIO_PORTB=LOW_NOPULLUP_PORT_VALUE;
			break;
			case HIGH :
			//case PULLUP :
			DIO_PORTB=HIGH_PULLUP_PORT_VALUE;
			break;
		}
		break;
		case PORTC :
		switch(Copy_u8PortState)
		{
			case LOW :
			//case NOPULLUP :
			DIO_PORTC=LOW_NOPULLUP_PORT_VALUE;
			break;
			case HIGH :
			//case PULLUP :
			DIO_PORTC=HIGH_PULLUP_PORT_VALUE;
			break;
		}
		break;
		case PORTD :
		switch(Copy_u8PortState)
		{
			case LOW :
			//case NOPULLUP :
			DIO_PORTD=LOW_NOPULLUP_PORT_VALUE;
			break;
			case HIGH :
			//case PULLUP :
			DIO_PORTD=HIGH_PULLUP_PORT_VALUE;
			break;
		}
		break;
	}
}

u8 DIO_u8GetPortValue (u8 Copy_u8PortName)
{//function to get the whole port value
	switch (Copy_u8PortName)
	{
		case PORTA :
		return DIO_PINA;
		case PORTB :
		return DIO_PINB;
		case PORTC :
		return DIO_PINC;
		case PORTD :
		return DIO_PIND;
		
	}
}
 void DIO_voidSetPortSpecificValue(u8 Copy_u8PortName,u8 Copy_u8PortValue)
 {
	 switch (Copy_u8PortName)
	{
		case PORTA :
		DIO_PORTA=Copy_u8PortValue;
		break;
		case PORTB :
		DIO_PORTB=Copy_u8PortValue;
		break;
		case PORTC :
		DIO_PORTC=Copy_u8PortValue;
		break;
		case PORTD :
		DIO_PORTD=Copy_u8PortValue;
		break;
	}
 }
 
 void DIO_voidSetPortSpecificDirection(u8 Copy_u8PortName,u8 Copy_u8PortValue)
 {
	 switch (Copy_u8PortName)
	{
		case PORTA :
		DIO_DDRA=Copy_u8PortValue;
		break;
		case PORTB :
		DIO_DDRB=Copy_u8PortValue;
		break;
		case PORTC :
		DIO_DDRC=Copy_u8PortValue;
		break;
		case PORTD :
		DIO_DDRD=Copy_u8PortValue;
		break;
	}
 }














