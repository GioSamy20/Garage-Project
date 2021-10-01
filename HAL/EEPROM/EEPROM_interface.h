#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H

void EEPROM_voidWriteDataByte(u16 Copy_u16LocationAddress,u8 Copy_u8Databyte);
void EEPROM_voidReadDataByte(u16 Copy_u16LocationAddress,u8 * Copy_pu8ReceivedData);


#endif