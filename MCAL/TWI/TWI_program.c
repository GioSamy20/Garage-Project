/************************INCLUSION OF LIBRARIES************************/
#include "../../LIB/bitmath.h"
#include "../../LIB/STD_TYPES.h"
/************************INCLUSION OF SELF LAYER***********************/

#include "TWI_interface.h"
#include "TWI_private.h"
#include "TWI_config.h"

/************************PROGRAM FUNCTIONS ****************************/

void TWI_voidMasterInit(u8 Copy_u8SlaveAddress)
{
	/*ENABLE ACK*/
	SET_BIT(TWCR,TWCR_TWEA);
	/*set SCL */
	TWBR=2;
	CLR_BIT(TWSR,TWSR_TWPS0);
	CLR_BIT(TWSR,TWSR_TWPS1);
	/*CHECK IF ADDRESS IS ZERO OR AN ACTUALL ADDRESS*/
	if (Copy_u8SlaveAddress==0)
	{
		
	}
	else
	{
		TWAR=Copy_u8SlaveAddress<<1;
	}
	/*ENABLE TWI*/
	SET_BIT(TWCR,TWCR_TWEN);
	
}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{
	/*ENABLE ACK*/
	SET_BIT(TWCR,TWCR_TWEA);
	
	/*GIVEN ADDRESS OF SLAVE*/
	
		TWAR=Copy_u8SlaveAddress<<1;
	
	/*ENABLE TWI*/
	SET_BIT(TWCR,TWCR_TWEN);
	
}

TWI_Errorstatus_t TWI_ErrorStatusSendStartCondition(void)
{
	u8 Local_ErrorStatus=No_Error;
	/*send start condition*/
	SET_BIT(TWCR,TWCR_TWSTA);
	
	/*CLEAR THE FLAG TO TAKE THE WANTED ACTION*/
	SET_BIT(TWCR,TWCR_TWINT);
	/*BUSY WAITING THE FLAG TO RAISE AGAIN*/
	while (GET_BIT(TWCR,TWCR_TWINT)==0);
	
	
	/*CHECK FOR STATUS CODE IF ANY ERROR OCCURED*/
	if ((TWSR&0XF8)!=START_CONDITION_CODE)
	{
		Local_ErrorStatus=Start_Condition_Error;
	}
	else
	{
		
	}
	return Local_ErrorStatus;
}

TWI_Errorstatus_t TWI_ErrorStatusSendRepeatedStartCondition(void)
{
	u8 Local_ErrorStatus=No_Error;
	/*send start condition*/
	SET_BIT(TWCR,TWCR_TWSTA);
	
	/*CLEAR THE FLAG TO TAKE THE WANTED ACTION*/
	SET_BIT(TWCR,TWCR_TWINT);
	/*BUSY WAITING THE FLAG TO RAISE AGAIN*/
	while (GET_BIT(TWCR,TWCR_TWINT)==0);
	
	
	/*CHECK FOR STATUS CODE IF ANY ERROR OCCURED*/
	if ((TWSR&0XF8)!=REPEATED_START_CONDITION_CODE)
	{
		Local_ErrorStatus=Repeated_Start_Error;
	}
	else
	{
		
	}
	return Local_ErrorStatus;
}

TWI_Errorstatus_t TWI_ErrorStatusSendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	u8 Local_ErrorStatus=No_Error;
	/*CLEAR THE start condition BIT*/
	CLR_BIT(TWCR,TWCR_TWSTA);
	/*Set Slave Address*/
	TWDR=Copy_u8SlaveAddress<<1;
	
	/*clear bit 0 it TWDR ,write =0*/
	
	CLR_BIT(TWDR,0);
	/*CLEAR FLAG*/
		SET_BIT(TWCR,TWCR_TWINT);

	/*WAIT FOR FLAG*/
		while (GET_BIT(TWCR,TWCR_TWINT)==0);

	/*CHECK FOR THE STATUS CODE*/
	if ((TWSR&0XF8)!=SLAVE_ADD_WITH_WRITE_ERROR)
	{
		Local_ErrorStatus=SlaveAddWithWriteError;
	}
	else
	{
		
	}
	return Local_ErrorStatus;
}


TWI_Errorstatus_t TWI_ErrorStatusSendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	u8 Local_ErrorStatus=No_Error;
	/*CLEAR THE start condition BIT*/
	CLR_BIT(TWCR,TWCR_TWSTA);
	
	/*Set Slave Address*/
	TWDR=Copy_u8SlaveAddress<<1;
	
	/*SET bit 0 it TWDR ,write =0*/
	
	SET_BIT(TWDR,0);
	/*CLEAR FLAG*/
		SET_BIT(TWCR,TWCR_TWINT);

	/*WAIT FOR FLAG*/
		while (GET_BIT(TWCR,TWCR_TWINT)==0);

	/*CHECK FOR THE STATUS CODE*/
	if ((TWSR&0XF8)!=SLAVE_ADD_WITH_READ_ERROR)
	{
		Local_ErrorStatus=SlaveAddWithReadError;
	}
	else
	{
		
	}
	return Local_ErrorStatus;
}


TWI_Errorstatus_t TWI_ErrorStatusMasterWriteDataByte(u8 Copy_u8DataByte)
{
	u8 Local_ErrorStatus=No_Error;
	/*MASTER SENDS DATA TO DATA BUS*/
	TWDR=Copy_u8DataByte;
	
	/*CLEAR FLAG*/
		SET_BIT(TWCR,TWCR_TWINT);

	/*WAIT FOR FLAG*/
		while (GET_BIT(TWCR,TWCR_TWINT)==0);

	/*CHECK FOR THE STATUS CODE*/
	if ((TWSR&0XF8)!=MASTER_WRITE_DATA_BYTE_ERROR)
	{
		Local_ErrorStatus=MasterWriteDataByteError;
	}
	else
	{
		
	}
	return Local_ErrorStatus;
	
}


TWI_Errorstatus_t TWI_ErrorStatusMasterReadDataByte(u8 * Copy_pu8ReceivedDataByte)
{
	u8 Local_ErrorStatus=No_Error;
	/*MASTER READ DATA FROM SLAVE BY CLEARING THE FLAG*/
	
	
	/*CLEAR FLAG*/
		SET_BIT(TWCR,TWCR_TWINT);

	/*WAIT FOR FLAG*/
		while (GET_BIT(TWCR,TWCR_TWINT)==0);

		
	
	/*CHECK FOR THE STATUS CODE*/
	if ((TWSR&0XF8)!=MASTER_READ_DATA_BYTE_ERROR)
	{
		Local_ErrorStatus=MasterReadDataByteError;
	}
	else
	{
		/*return the value to the pointer*/
		*Copy_pu8ReceivedDataByte=TWDR;
	}
	return Local_ErrorStatus;
	
}


void TWI_voidSendStopCondition(void)
{
	/*SEND STOP CONDITION*/
	SET_BIT(TWCR,TWCR_TWSTO);
	
	/*CLEAR FLAG*/
		SET_BIT(TWCR,TWCR_TWINT);

	/*WAIT FOR FLAG*/
		while (GET_BIT(TWCR,TWCR_TWINT)==0);

}

