#include "../../LIB/bitmath.h"
#include "../../LIB/STD_TYPES.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"




void USART_voidInit(void)
{
	u8 UCSRC_val=0;
		/*REGISTER SELECT (UCSRC or UBRRH) BIT 7*/
		UCSRC_val&=REG_SEL_RESET;
		UCSRC_val|=REG_SELECT;
		
		
		//SET_BIT(UCSRC_val,UCSRC_URSEL);
		
		/*USART MODE SELECT (ASYNCH OR SYNCH) BIT 6*/
		UCSRC_val&=USMEL_RESET;
		UCSRC_val|=USART_MODE;
		
		//CLR_BIT(UCSRC_val,UCSRC_UMSEL);

		/*CHARCHTER SIZE*/
		UCSRC_val&=CHAR_SIZE_RST;
		u8 LOCAL_CHAR_SIZE=CHAR_SIZE;
		switch(LOCAL_CHAR_SIZE)
		{
		case BITS5:
					CLR_BIT(UCSRC_val,UCSRC_UCSZ0);
					CLR_BIT(UCSRC_val,UCSRC_UCSZ1);
					CLR_BIT(UCSRB,UCSRB_UCSZ2);
					break;
					case BITS6:
					SET_BIT(UCSRC_val,UCSRC_UCSZ0);
					CLR_BIT(UCSRC_val,UCSRC_UCSZ1);
					CLR_BIT(UCSRB,UCSRB_UCSZ2);
					break;

					case BITS7:
					CLR_BIT(UCSRC_val,UCSRC_UCSZ0);
					SET_BIT(UCSRC_val,UCSRC_UCSZ1);
					CLR_BIT(UCSRB,UCSRB_UCSZ2);
					break;

					case BITS8:
					SET_BIT(UCSRC_val,UCSRC_UCSZ0);
					SET_BIT(UCSRC_val,UCSRC_UCSZ1);
					CLR_BIT(UCSRB,UCSRB_UCSZ2);
					break;

					case BITS9:
					SET_BIT(UCSRC_val,UCSRC_UCSZ0);
					SET_BIT(UCSRC_val,UCSRC_UCSZ1);
					SET_BIT(UCSRB,UCSRB_UCSZ2);
					break;

		}
		
		/*SET_BIT(UCSRC_val,UCSRC_UCSZ0);
		SET_BIT(UCSRC_val,UCSRC_UCSZ1);
		CLR_BIT(UCSRB,UCSRB_UCSZ2);*/


		/*PARITY MODE */
		UCSRC_val&=UPM_RESET;
		UCSRC_val|=PARITY_MODE;

		/*CLR_BIT(UCSRC_val,UCSRC_UPM0);
		CLR_BIT(UCSRC_val,UCSRC_UPM1);*/

		/*STOP-BIT*/
		UCSRC_val&=STPBIT_RESET;
		UCSRC_val|=STOP_BIT;
		
		//CLR_BIT(UCSRC_val,UCSRC_USBS);



		/*enable transmitter and receiver*/

		SET_BIT(UCSRB,UCSRB_TXEN);
		SET_BIT(UCSRB,UCSRB_RXEN);

		/*enable double speed*/
		UCSRA&=DBL_RST;
		UCSRA|=DBL_SPD;
		
		//SET_BIT(UCSRA,UCSRA_U2X);

		/*Baudrate*/
		UBRRL=BAUD_RATE;
		/*send Variable to Register*/
		UCSRC=UCSRC_val;

}

void USART_voidSendCharacterSynch(u8 Copy_u8Data)
{
	while (GET_BIT(UCSRA,UCSRA_UDRE)==0);
	UDR= Copy_u8Data;
	
}



void USART_voidReceiveCharacter(u8 *Copy_pu8ReceivedCharacter)
{
	while (GET_BIT(UCSRA,UCSRA_RXC)==0);
	*Copy_pu8ReceivedCharacter=UDR;
}
static void (*USART_pvNotificationFunction)(void) = NULL_POINTER;

void USART_voidReceiveSetCallBack(void (*Copy_pvNotificationFunction)(void))
{
	USART_pvNotificationFunction=Copy_pvNotificationFunction;
}


void __vector_13(void) __attribute__((signal));
void __vector_13(void)
{
	if(USART_pvNotificationFunction!=NULL_POINTER)
	{
		USART_pvNotificationFunction();
	}
	else
	{
		
	}
}







