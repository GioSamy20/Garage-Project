#include "../../LIB/bitmath.h"
#include "../../LIB/STD_TYPES.h"

//inclusion of lower layer
#include "../../MCAL/DIO/DIO_interface.h"

//inclusion of (self layer) kpd header files
#include "DCM_interface.h"
#include "DCM_private.h"
#include "DCM_config.h"
#include <util/delay.h>


//INITIATE THE H-BRIDGE DRIVER
void DCM_voidInit(void)
{
	DIO_voidSetPinDirection(DCM_PORT,DCM_OUTPUT_PIN1,OUTPUT);
	DIO_voidSetPinDirection(DCM_PORT,DCM_OUTPUT_PIN2,OUTPUT);
	
}

void DCM_voidClockwiseMotor(void)
{
	DIO_voidSetPinValue(DCM_PORT,DCM_OUTPUT_PIN2,LOW);
	DIO_voidSetPinValue(DCM_PORT,DCM_OUTPUT_PIN1,HIGH);
}

void DCM_voidQounterClockwiseMotor(void)
{
	DIO_voidSetPinValue(DCM_PORT,DCM_OUTPUT_PIN1,LOW);
	DIO_voidSetPinValue(DCM_PORT,DCM_OUTPUT_PIN2,HIGH);

}

void DCM_voidStopMotor(void)
{
	DIO_voidSetPinValue(DCM_PORT,DCM_OUTPUT_PIN1,LOW);
	DIO_voidSetPinValue(DCM_PORT,DCM_OUTPUT_PIN2,LOW);
}