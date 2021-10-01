#include "../../LIB/bitmath.h"
#include "../../LIB/STD_TYPES.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"


void SPI_voidMasterInit(void)
{
	/*MASTER SLAVE SELECT*/
	SET_BIT(SPCR,SPCR_MSTR);
	
	/*SELECT PRESACALER*/
	SET_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
	
	/*SETTING clock POLARITY*/
	CLR_BIT(SPCR,SPCR_CPOL);
	
	/*SETTING CLOCK PHASE*/
	CLR_BIT(SPCR,SPCR_CPHA);
	
	/*MSB FIRST*/
	CLR_BIT(SPCR,SPCR_DORD);
	
	/*ENABLE SPI*/
	
	SET_BIT(SPCR,SPCR_SPE);
}

void SPI_voidSlaveInit(void)
{
	/*ENABLE SPI*/

		SET_BIT(SPCR,SPCR_SPE);
	/*MASTER SLAVE SELECT*/
	CLR_BIT(SPCR,SPCR_MSTR);
	
	/*SETTING clock POLARITY*/
	CLR_BIT(SPCR,SPCR_CPOL);
	
	/*SETTING CLOCK PHASE*/
	CLR_BIT(SPCR,SPCR_CPHA);
	
	/*MSB FIRST*/
	CLR_BIT(SPCR,SPCR_DORD);
	
}




void SPI_voidTranceiveData(u8 *Copy_pu8ReceivedData,u8 Copy_u8SendData)
{
	/*SEND DATA THROGH SPDE REGISTER*/
	SPDR=Copy_u8SendData;
	
		
	while(GET_BIT(SPSR,SPSR_SPIF)==0);
	
	CLR_BIT(SPSR,SPSR_SPIF);	
	
	*Copy_pu8ReceivedData=SPDR;
}
