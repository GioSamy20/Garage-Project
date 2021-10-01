/*INCLUSION OF LIBRARY*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/bitmath.h"
#include <util/delay.h>

#include "../../MCAL/DIO/DIO_interface.h"

/*INCLUSION OF SELF LAYERS*/
#include "KPD_Interface.h"
#include "KPD_Private.h"
#include "KPD_Config.h"



void KPD_voidInit(void)
{
	/*set the row pins to be input pulled up*/
	DIO_voidSetPinDirection(KPD_PORT,KPD_ROW0_PIN,INPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_ROW1_PIN,INPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_ROW2_PIN,INPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_ROW3_PIN,INPUT);

	/*turn on the pull up resistor*/
	DIO_voidSetPinValue(KPD_PORT,KPD_ROW0_PIN,PULLUP);
	DIO_voidSetPinValue(KPD_PORT,KPD_ROW1_PIN,PULLUP);
	DIO_voidSetPinValue(KPD_PORT,KPD_ROW2_PIN,PULLUP);
	DIO_voidSetPinValue(KPD_PORT,KPD_ROW3_PIN,PULLUP);

	/*set the columns pins to be output high */
	DIO_voidSetPinDirection(KPD_PORT,KPD_Col0_PIN,OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_Col1_PIN,OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_Col2_PIN,OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT,KPD_Col3_PIN,OUTPUT);

	/*set high to be the columns pins */
	DIO_voidSetPinValue(KPD_PORT,KPD_Col0_PIN,HIGH);
	DIO_voidSetPinValue(KPD_PORT,KPD_Col1_PIN,HIGH);
	DIO_voidSetPinValue(KPD_PORT,KPD_Col2_PIN,HIGH);
	DIO_voidSetPinValue(KPD_PORT,KPD_Col3_PIN,HIGH);
}
u8 KPD_u8GetPresseedKey(void)
{
	u8 Local_u8PressedKey=NoPreesdKey;
	static u8 Local_u8KPDArr[ROWS_NUM][COLUMNS_NUM]=KPD_Arr_Value;
	u8 Local_u8ColumnsCounter;
	u8 Local_u8RowsCounter;
	static u8 Local_u8ColumnsArr[COLUMNS_NUM]={ KPD_Col0_PIN ,
                                         KPD_Col1_PIN ,
                                         KPD_Col2_PIN ,
                                         KPD_Col3_PIN
                                                	  };
	static u8 Local_u8RowsArr[ROWS_NUM]={ KPD_ROW0_PIN ,
                                   KPD_ROW1_PIN ,
                                   KPD_ROW2_PIN ,
                                   KPD_ROW3_PIN
                                             	 };
	for(Local_u8ColumnsCounter=0;Local_u8ColumnsCounter<COLUMNS_NUM;Local_u8ColumnsCounter++)
	{
		/*active current columns*/
		DIO_voidSetPinValue(KPD_PORT,Local_u8ColumnsArr[Local_u8ColumnsCounter],LOW);
		for(Local_u8RowsCounter=0;Local_u8RowsCounter<ROWS_NUM;Local_u8RowsCounter++)
		{
			/* Read The Current Low*/
			DIO_u8GetPinValue(KPD_PORT,Local_u8RowsArr[Local_u8RowsCounter]);
			/*Check if switch is pressed*/
			if(DIO_u8GetPinValue(KPD_PORT,Local_u8RowsArr[Local_u8RowsCounter])==LOW)
			{
				Local_u8PressedKey=Local_u8KPDArr[Local_u8RowsCounter][Local_u8ColumnsCounter];
				/*Polling(busy waiting until the key is released)*/
				while(DIO_u8GetPinValue(KPD_PORT,Local_u8RowsArr[Local_u8RowsCounter])==LOW)
				{
					DIO_u8GetPinValue(KPD_PORT,Local_u8RowsArr[Local_u8RowsCounter]);
				}
				return Local_u8PressedKey;
			}
		}
		/*deactivate the current columns*/
		DIO_voidSetPinValue(KPD_PORT,Local_u8ColumnsArr[Local_u8ColumnsCounter],HIGH);

	}
	return Local_u8PressedKey ;
}



