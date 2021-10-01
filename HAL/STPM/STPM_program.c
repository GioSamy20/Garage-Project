#include "../../LIB/bitmath.h"
#include "../../LIB/STD_TYPES.h"

//inclusion of lower layer
#include "../../MCAL/DIO/DIO_interface.h"

//inclusion of (self layer) kpd header files
#include "STPM_interface.h"
#include "STPM_private.h"
#include "STPM_config.h"
#include <util/delay.h>


//INITIATE THE stepper motor DRIVER
void STPM_voidInit(void)
{
	DIO_voidSetPinDirection(STPM_PORT,STPM_OUTPUT_PIN0,OUTPUT);
	DIO_voidSetPinDirection(STPM_PORT,STPM_OUTPUT_PIN1,OUTPUT);
	DIO_voidSetPinDirection(STPM_PORT,STPM_OUTPUT_PIN2,OUTPUT);
	DIO_voidSetPinDirection(STPM_PORT,STPM_OUTPUT_PIN3,OUTPUT);	
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN0,HIGH);
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN1,HIGH);
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN2,HIGH);
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN3,HIGH);

}

void STPM_voidClockwiseMotor(f32 Copy_f32InputAngle)
{
	f32 CoilSteps=(Copy_f32InputAngle*64.0)/(11.25*4);
	for (u16 CoilIteration=0;CoilIteration<CoilSteps;CoilIteration++)
	{
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN0,LOW);
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN1,HIGH);
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN2,HIGH);
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN3,HIGH);
	_delay_ms(STPM_TIME);
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN0,HIGH);
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN1,LOW);
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN2,HIGH);
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN3,HIGH);
	_delay_ms(STPM_TIME);
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN0,HIGH);
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN1,HIGH);
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN2,LOW);
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN3,HIGH);
	_delay_ms(STPM_TIME);
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN0,HIGH);
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN1,HIGH);
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN2,HIGH);
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN3,LOW);
	_delay_ms(STPM_TIME);
	}
}

void STPM_voidQounterClockwiseMotor(f32 Copy_f32InputAngle)
{
	f32 CoilSteps=(Copy_f32InputAngle*64.0)/(11.25*4);
		for (u16 CoilIteration=0;CoilIteration<CoilSteps;CoilIteration++)
		{
		DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN0,HIGH);
		DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN1,HIGH);
		DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN2,HIGH);
		DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN3,LOW);
		_delay_ms(STPM_TIME);
		DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN0,HIGH);
		DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN1,HIGH);
		DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN2,LOW);
		DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN3,HIGH);
		_delay_ms(STPM_TIME);
		DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN0,HIGH);
		DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN1,LOW);
		DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN2,HIGH);
		DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN3,HIGH);
		_delay_ms(STPM_TIME);
		DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN0,LOW);
		DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN1,HIGH);
		DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN2,HIGH);
		DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN3,HIGH);
		_delay_ms(STPM_TIME);
		}

}

void STPM_voidStopMotor(void)
{
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN1,LOW);
	DIO_voidSetPinValue(STPM_PORT,STPM_OUTPUT_PIN2,LOW);
}
