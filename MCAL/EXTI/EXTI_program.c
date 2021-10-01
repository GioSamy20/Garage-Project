#include "../../LIB/bitmath.h"
#include "../../LIB/STD_TYPES.h"

#include "../DIO/DIO_interface.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (*EXTI_pvINT0FUNCTION)(void) = NULL_POINTER;

static void (*EXTI_pvINT1FUNCTION)(void) = NULL_POINTER;

static void (*EXTI_pvINT2FUNCTION)(void) = NULL_POINTER;

void EXTI_voidSetINT0SenseControl(u8 Copy_u8SignalControl)
{
	switch(Copy_u8SignalControl)
	{
		case LOW_LEVEL:
			CLR_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
		break;
		case FALLING_EDGE:
		//PAGE 65
			CLR_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
		break;
		case RISING_EDGE :
			SET_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
		break;
		case ON_CHANGE:
			SET_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
		break;
	}
}

void EXTI_voidSetINT1SenseControl(u8 Copy_u8SignalControl)
{
	switch(Copy_u8SignalControl)
	{
		case LOW_LEVEL:
			CLR_BIT(MCUCR,MCUCR_ISC10);
			CLR_BIT(MCUCR,MCUCR_ISC11);
		break;
		case FALLING_EDGE:
		//PAGE 65
			CLR_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
		break;
		case RISING_EDGE :
			SET_BIT(MCUCR,MCUCR_ISC10);
			SET_BIT(MCUCR,MCUCR_ISC11);
		break;
		case ON_CHANGE:
			SET_BIT(MCUCR,MCUCR_ISC10);
			CLR_BIT(MCUCR,MCUCR_ISC11);
		break;
	}
}

void EXTI_voidSetINT2SenseControl(u8 Copy_u8SignalControl)
{
	switch(Copy_u8SignalControl)
	{
		case FALLING_EDGE:
		CLR_BIT(MCUCSR,MCUCSR_ISC2);
		break;
		case RISING_EDGE:
		SET_BIT(MCUCSR,MCUCSR_ISC2);
		break;
	}
}




void EXTI_voidEnableINT0(void)   //SIE control INT0 enable
{
	SET_BIT(GICR,GICR_INT0);
}

void EXTI_voidDisableINT0(void)//SIE control INT0 Disable
{
	CLR_BIT(GICR,GICR_INT0);
}

void EXTI_voidEnableINT1(void)   //SIE control INT1 enable
{
	SET_BIT(GICR,GICR_INT1);
}

void EXTI_voidDisableINT1(void)  //SIE control INT1 Disable
{
	CLR_BIT(GICR,GICR_INT1);
}

void EXTI_voidEnableINT2(void)   //SIE control INT2 enable
{
	SET_BIT(GICR,GICR_INT2);
}

void EXTI_voidDisableINT2(void)  //SIE control INT2 Disable
{
	CLR_BIT(GICR,GICR_INT2);
}


void EXTI_voidINT0SetCallBack(void (*Copy_pvNotificationFun)(void))
{
	EXTI_pvINT0FUNCTION=Copy_pvNotificationFun;
}

void EXTI_voidINT1SetCallBack(void (*Copy_pvNotificationFun)(void))
{
	EXTI_pvINT1FUNCTION=Copy_pvNotificationFun;
}

void EXTI_voidINT2SetCallBack(void (*Copy_pvNotificationFun)(void))
{
	EXTI_pvINT2FUNCTION=Copy_pvNotificationFun;
}

void EXTI_voidINT0Synchronous(void (*Copy_pvNotificationFun)(void))
{
	//polling (busy waiting) untill the event has occurred
	while (GET_BIT(GIFR,GIFR_INTF0)==0);
	//clear the flag
	SET_BIT(GIFR,GIFR_INTF0);
	Copy_pvNotificationFun();
}

void EXTI_voidINT1Synchronous(void (*Copy_pvNotificationFun)(void))
{
	//polling (busy waiting) untill the event has occurred
	while (GET_BIT(GIFR,GIFR_INTF1)==0);
	//clear the flag
	SET_BIT(GIFR,GIFR_INTF1);
	Copy_pvNotificationFun();
}

void EXTI_voidINT2Synchronous(void (*Copy_pvNotificationFun)(void))
{
	//polling (busy waiting) untill the event has occurred
	while (GET_BIT(GIFR,GIFR_INTF2)==0);
	//clear the flag
	SET_BIT(GIFR,GIFR_INTF2);
	Copy_pvNotificationFun();
}

void __vector_1 (void) __attribute__((signal));  //for int0
void __vector_1 (void)
{
	if (EXTI_pvINT0FUNCTION!=NULL_POINTER)
	{
	EXTI_pvINT0FUNCTION();
	}
	else 
	{
		
	}
}

void __vector_2 (void) __attribute__((signal)); //for int1
void __vector_2 (void)
{
	if (EXTI_pvINT1FUNCTION!=NULL_POINTER)
	{
	EXTI_pvINT1FUNCTION();
	}
	else 
	{
		
	}
}

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if (EXTI_pvINT2FUNCTION!=NULL_POINTER)
	{
	EXTI_pvINT2FUNCTION();
	}
	else 
	{
		
	}
}




