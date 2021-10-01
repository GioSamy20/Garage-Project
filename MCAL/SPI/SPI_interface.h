#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H



void SPI_voidMasterInit(void);

void SPI_voidSlaveInit(void);
void SPI_voidTranceiveData(u8 *Copy_pu8ReceivedData,u8 Copy_u8SendData);

#endif
