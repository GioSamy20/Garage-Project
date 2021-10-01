//inclusion of libraries
#include "../../LIB/bitmath.h"
#include "../../LIB/STD_TYPES.h"

//inclusion of lower layer
#include "../../MCAL/DIO/DIO_interface.h"

//inclusion of (self layer) lcd header files
#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"

#include <util/delay.h> 


void LCD_voidSendCommand(u8 Copy_u8Command)
//rs 0 for command 1 for data
//r/w 0 write 1 read
{
	DIO_voidSetPinValue(LCD_CTRL_PORT ,LCD_RS_PIN , LOW );
	DIO_voidSetPinValue(LCD_CTRL_PORT ,LCD_RW_PIN , LOW );
	DIO_voidSetPortSpecificValue(LCD_DATA_PORT ,Copy_u8Command );
	DIO_voidSetPinValue(LCD_CTRL_PORT ,LCD_EN_PIN , HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CTRL_PORT ,LCD_EN_PIN , LOW);
}

void LCD_voidSendData(u8 Copy_u8Data)
//rs 0 for command 1 for data
//r/w 0 write 1 read
{
	DIO_voidSetPinValue(LCD_CTRL_PORT ,LCD_RS_PIN , HIGH );
	DIO_voidSetPinValue(LCD_CTRL_PORT ,LCD_RW_PIN , LOW );
	DIO_voidSetPortSpecificValue(LCD_DATA_PORT ,Copy_u8Data );
	DIO_voidSetPinValue(LCD_CTRL_PORT ,LCD_EN_PIN , HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CTRL_PORT ,LCD_EN_PIN , LOW);
}

void LCD_voidInit(void) //intialize LCD 
{
	DIO_voidSetPortDirection(LCD_DATA_PORT,OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_RS_PIN,OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_RW_PIN,OUTPUT);
	DIO_voidSetPinDirection(LCD_CTRL_PORT,LCD_EN_PIN,OUTPUT);
	_delay_ms(40);
	LCD_voidSendCommand(0x38);
	LCD_voidSendCommand(0x0f);
	LCD_voidSendCommand(0x01);
	
	
}

void LCD_voidCursorGoToXY(u8 Copy_u8X,u8 Copy_u8Y)  //Move cursor using x and y inputs from user // x row ,y column
{
	LCD_voidSendCommand(RETURN_HOME);
	u8 steps;
	if (Copy_u8Y>=0 && Copy_u8Y<16) //Copy_u8Y FROM 0 TO 15
	{
	if (Copy_u8X==1) //Copy_u8X -> 0 FOR 1ST ROW AND 1 FOR THE 2ND
	{

	steps=Copy_u8Y+40;
	}
	else if (Copy_u8X==0)
	{
		steps=Copy_u8Y;
	}
	for (u8 i=0;i<steps;i++)
	{
		LCD_voidSendCommand(SHIFT_CURSOR_RIGHT);
	}
	}

}

void LCD_voidGoToXY(u8 Copy_u8X,u8 Copy_u8Y)
{
	u8 Local_u8DDRAAddress;
	switch(Copy_u8X)
	{
	case 0:
		Local_u8DDRAAddress=Copy_u8Y;
		break;
	case 1:
		Local_u8DDRAAddress=Copy_u8Y+DDRAM_CONST_ADDRESS;
			break;
	}
	SET_BIT(Local_u8DDRAAddress,7);
	LCD_voidSendCommand(Local_u8DDRAAddress);
}

void LCD_voidSendString(u8 *Copy_pu8String)
{

	for (u8 i=0;Copy_pu8String[i]!='\0';i++)
	{
		LCD_voidSendData(Copy_pu8String[i]);
	}
}


void LCD_voidSendCustomPattern(u8*Copy_pu8CustomPattern,u8 Copy_u8PatternNum, u8 Copy_u8X,u8 Copy_u8Y)
{
	u8 Local_u8counter=0;
	u8 Local_u8CGRAMAddress;
	Local_u8CGRAMAddress=Copy_u8PatternNum*8;
	SET_BIT(Local_u8CGRAMAddress,6);
	LCD_voidSendCommand(Local_u8CGRAMAddress);
	for(Local_u8counter=0;Local_u8counter<8;Local_u8counter++)
	
	{
	LCD_voidSendData(Copy_pu8CustomPattern[Local_u8counter]);
	
	}
	LCD_voidGoToXY(Copy_u8X,Copy_u8Y);
	LCD_voidSendData(Copy_u8PatternNum);
	
	
}









