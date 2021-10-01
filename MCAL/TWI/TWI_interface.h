#ifndef TWI_INTERFACE_H
#define TWI_INTERFACE_H


/*ERRORS DEFINITION*/
typedef enum
{
	No_Error,
	Start_Condition_Error,
	Repeated_Start_Error,
	SlaveAddWithWriteError,
	SlaveAddWithReadError,
	MasterWriteDataByteError,
	MasterReadDataByteError,
	
}TWI_Errorstatus_t;


void TWI_voidMasterInit(u8 Copy_u8SlaveAddress);
void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);
TWI_Errorstatus_t TWI_ErrorStatusSendStartCondition(void);
TWI_Errorstatus_t TWI_ErrorStatusSendRepeatedStartCondition(void);
TWI_Errorstatus_t TWI_ErrorStatusSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);
TWI_Errorstatus_t TWI_ErrorStatusSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);
TWI_Errorstatus_t TWI_ErrorStatusMasterWriteDataByte(u8 Copy_u8DataByte);
TWI_Errorstatus_t TWI_ErrorStatusMasterReadDataByte(u8 * Copy_pu8ReceivedDataByte);
void TWI_voidSendStopCondition(void);



#endif 