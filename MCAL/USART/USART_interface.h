#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

void USART_voidInit(void);
void USART_voidSendCharacterSynch(u8 Copy_u8Data);
void USART_voidReceiveCharacter(u8 *Copy_pu8ReceivedCharacter);
void USART_voidReceiveSetCallBack(void (*Copy_pvNotificationFunction)(void));


/*REGISTER SELECT (UCSRC or UBRRH) BIT 7*/
#define REG_SEL_RESET 0b01111111
#define UCSRC_Mode 0b10000000
#define UBRRH_Mode 0b00000000

/*USART MODE SELECT (ASYNCH OR SYNCH) BIT 6*/
#define USMEL_RESET 0b10111111
#define USMEL_ASYNCH 0b00000000
#define USMEL_SYNCH 0b01000000

/*PARITY MODE (DISABLED, EVEN PARITY, ODD PARITY)*/
#define UPM_RESET 0b11001111
#define DIS_PARITY 0b00000000
#define EVN_PARITY 0b00100000
#define ODD_PARITY 0b00110000

/*STOP-BIT (1-bit or 2-bit)*/
#define STPBIT_RESET 0B11110111
#define STOPBIT_1 0B00000000
#define STOPBIT_2 0B00001000

/*CHARACTER SIZE 5~9BITS*/ 
#define CHAR_SIZE_RST 0B11111001
#define	BITS5 0
#define BITS6 1
#define BITS7 2
#define BITS8 3
#define BITS9 4

/*CLOCK POLARITY  */
#define POLARITY_RST 0B11111110
#define POLARITY_RISING 0B00000000
#define POLARITY_FALLING 0B00000001

/*DOUBLE SPEED*/
#define DBL_RST 0B11111101
#define DBL_DISABLED 0B00000000
#define DBL_ENABLED 0B00000010




#endif
