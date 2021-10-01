#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define LOW_LEVEL 0
#define RISING_EDGE 1
#define FALLING_EDGE 2
#define ON_CHANGE 3

void EXTI_voidSetINT0SenseControl(u8 Copy_u8SignalControl);
void EXTI_voidSetINT1SenseControl(u8 Copy_u8SignalControl);
void EXTI_voidSetINT2SenseControl(u8 Copy_u8SignalControl);




void EXTI_voidEnableINT0(void);
void EXTI_voidDisableINT0(void);

void EXTI_voidEnableINT1(void);
void EXTI_voidDisableINT1(void);

void EXTI_voidEnableINT2(void);
void EXTI_voidDisableINT2(void);


void EXTI_voidINT0SetCallBack(void (*Copy_pvNotificationFun)(void));
void EXTI_voidINT1SetCallBack(void (*Copy_pvNotificationFun)(void));
void EXTI_voidINT2SetCallBack(void (*Copy_pvNotificationFun)(void));
               
               
void EXTI_voidINT0Synchronous(void (*Copy_pvNotificationFun)(void));
void EXTI_voidINT1Synchronous(void (*Copy_pvNotificationFun)(void));
void EXTI_voidINT2Synchronous(void (*Copy_pvNotificationFun)(void));

#endif