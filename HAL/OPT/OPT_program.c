#include "../../LIB/bitmath.h"
#include "../../LIB/STD_TYPES.h"

//inclusion of lower layer
#include "../../MCAL/DIO/DIO_interface.h"

//inclusion of (self layer) kpd header files
#include "OPT_interface.h"
#include "OPT_private.h"
#include "OPT_config.h"
#include <util/delay.h>


//INITIATE THE H-BRIDGE DRIVER
void OPT_voidInit(void)
{
	DIO_voidSetPinDirection(OPT_PORT,OPT_OUTPUT_PIN1,OUTPUT);
	
	
}

void OPT_voidOptHigh(void)
{
	DIO_voidSetPinValue(OPT_PORT,OPT_OUTPUT_PIN1,HIGH);
}

void OPT_voidOptLow(void)
{
	DIO_voidSetPinValue(OPT_PORT,OPT_OUTPUT_PIN1,LOW);

}

