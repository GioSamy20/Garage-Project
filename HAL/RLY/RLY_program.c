#include "../../LIB/bitmath.h"
#include "../../LIB/STD_TYPES.h"

//inclusion of lower layer
#include "../../MCAL/DIO/DIO_interface.h"

//inclusion of (self layer) RLY header files
#include "RLY_interface.h"
#include "RLY_private.h"
#include "RLY_config.h"
#include <util/delay.h>


//INITIATE THE H-BRIDGE DRIVER
void RLY_voidInit(void)
{
	DIO_voidSetPinDirection(RLY_PORT,RLY_OUTPUT_PIN1,OUTPUT);
	DIO_voidSetPinDirection(RLY_PORT,RLY_OUTPUT_PIN2,OUTPUT);
	DIO_voidSetPinDirection(RLY_PORT,RLY_OUTPUT_PIN3,OUTPUT);//a pin to control. voltage
	
}

void RLY_voidRLYON(void)
{
	DIO_voidSetPinValue(RLY_PORT,RLY_OUTPUT_PIN1,HIGH);
}

void RLY_voidRLYOFF(void)
{
	DIO_voidSetPinValue(RLY_PORT,RLY_OUTPUT_PIN3,LOW);
	DIO_voidSetPinValue(RLY_PORT,RLY_OUTPUT_PIN1,LOW);
	DIO_voidSetPinValue(RLY_PORT,RLY_OUTPUT_PIN2,LOW);

}
void RLY_void2RLYClockwise(void)
{DIO_voidSetPinValue(RLY_PORT,RLY_OUTPUT_PIN3,HIGH);
	DIO_voidSetPinValue(RLY_PORT,RLY_OUTPUT_PIN2,LOW);
	DIO_voidSetPinValue(RLY_PORT,RLY_OUTPUT_PIN1,HIGH);

}
void RLY_void2RLYQounterClockwise(void)
{
	DIO_voidSetPinValue(RLY_PORT,RLY_OUTPUT_PIN3,HIGH);
	DIO_voidSetPinValue(RLY_PORT,RLY_OUTPUT_PIN1,LOW);
	DIO_voidSetPinValue(RLY_PORT,RLY_OUTPUT_PIN2,HIGH);
}

