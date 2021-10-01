/************************INCLUSION OF LIBRARIES************************/
#include "../../LIB/bitmath.h"
#include "../../LIB/STD_TYPES.h"
#include <util/delay.h>
/************************INCLUSION OF LOWER LAYER***********************/
#include "../../MCAL/TWI/TWI_interface.h"


/************************INCLUSION OF SELF LAYER***********************/

#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"


/************************PROGRAM FUNCTIONS*****************************/

void EEPROM_voidWriteDataByte(u16 Copy_u16LocationAddress,u8 Copy_u8Databyte)
{
	u8 Local_Address;
	/*start condition*/
	TWI_ErrorStatusSendStartCondition();
	/*Address configuration and send to EEPROM*/
	Local_Address=FIXED_ADDRESS|(A2_PIN_CONFIG<<2)|(u8)(Copy_u16LocationAddress>>8);
	TWI_ErrorStatusSendSlaveAddressWithWrite(Local_Address);
	/*sending the location address*/
	TWI_ErrorStatusMasterWriteDataByte((u8)Copy_u16LocationAddress);
	/*sending data*/
	TWI_ErrorStatusMasterWriteDataByte(Copy_u8Databyte);
	/*sending stop condition*/
	TWI_voidSendStopCondition();
	_delay_ms(10);

}

void EEPROM_voidReadDataByte(u16 Copy_u16LocationAddress,u8 * Copy_pu8ReceivedData)
{
	u8 Local_Address;
	/*start condition*/
	TWI_ErrorStatusSendStartCondition();
	/*Address configuration and send to EEPROM*/
	Local_Address=FIXED_ADDRESS|(A2_PIN_CONFIG<<2)|(u8)(Copy_u16LocationAddress>>8);
	TWI_ErrorStatusSendSlaveAddressWithWrite(Local_Address);
	/*sending the location address*/
	TWI_ErrorStatusMasterWriteDataByte((u8)Copy_u16LocationAddress);
	/*Send repeated start*/
	TWI_ErrorStatusSendRepeatedStartCondition();
	/*Send slave address with read*/
	TWI_ErrorStatusSendSlaveAddressWithRead(Local_Address);
	/*receive the data byte*/
	TWI_ErrorStatusMasterReadDataByte(Copy_pu8ReceivedData);
	/*sending stop condition*/
	TWI_voidSendStopCondition();
}