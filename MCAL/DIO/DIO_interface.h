#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0
#define PULLUP 1
#define NOPULLUP 0

void DIO_voidSetPinDirection(u8 Copy_u8PortName , u8 Copy_u8PinName , u8 Copy_u8PinMode);
void DIO_voidSetPinValue(u8 Copy_u8PortName , u8 Copy_u8PinName , u8 Copy_u8PinState);
u8 DIO_u8GetPinValue (u8 Copy_u8PortName,u8 Copy_u8PinName);
void DIO_voidSetPortDirection (u8 Copy_u8PortName,u8 Copy_u8PortMode);
void DIO_voidSetPortValue (u8 Copy_u8PortName , u8 Copy_u8PortState);
u8 DIO_u8GetPortValue (u8 Copy_u8PortName);
void DIO_voidSetPortSpecificValue(u8 Copy_u8PortName,u8 Copy_u8PortValue);
void DIO_voidSetPortSpecificDirection(u8 Copy_u8PortName,u8 Copy_u8PortValue);



#endif