#include "../../LIB/bitmath.h"
#include "../../LIB/STD_TYPES.h"


#include "../EXTI/EXTI_interface.h"
#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"


static void (*TIMER_pvNotificationFunc)(void) = NULL_POINTER;

void TIMER_voidInit(void)
{
	CLR_BIT(TCCR0,TCCR0_CS00); 
	SET_BIT(TCCR0,TCCR0_CS01);  
	CLR_BIT(TCCR0,TCCR0_CS02);
	SET_BIT(TIMSK,TIMSK_TOIE0);  
	
}

void TIMER_voidSetCallBack(void (*Copy_pvNotificationFunc)(void))
{
	TIMER_pvNotificationFunc=Copy_pvNotificationFunc;
}

void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	if (TIMER_pvNotificationFunc!=NULL_POINTER)
	{
		TIMER_pvNotificationFunc();
	}
	else
	{
		
	}
}