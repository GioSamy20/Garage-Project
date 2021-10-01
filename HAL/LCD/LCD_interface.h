#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H	




void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendData(u8 Copy_u8Data);
void LCD_voidInit(void);
void LCD_voidCursorGoToXY(u8 Copy_u8X,u8 Copy_u8Y);
void LCD_voidGoToXY(u8 Copy_u8X,u8 Copy_u8Y);
void LCD_voidSendString(u8 *Copy_pu8String);
void LCD_voidSendCustomPattern(u8*Copy_pu8CustomPattern,u8 Copy_u8PatternNum, u8 Copy_u8X,u8 Copy_u8Y);



#endif
