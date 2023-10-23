/*
 * EXTI_program.c
 *
 *  Created on: Aug 12, 2023
 *      Author: alibo
 */

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (*Global_PtrToFun_Notification[3]) (void) = {NULL, NULL, NULL};


void EXTI_voidInit (void)
{
#if SENSE_CONTROL_EXTI0 == EXTI_FALLING_EDGE
	SET_BIT(MCUCR_REG , 1 );
	CLR_BIT(MCUCR_REG , 0 );

#elif SENSE_CONTROL_EXTI0 == EXTI_RAISING_EDGE
	SET_BIT(MCUCR_REG , 1 );
	SET_BIT(MCUCR_REG , 0 );

#elif SENSE_CONTROL_EXTI0 == EXTI_ON_CHANGE
	CLR_BIT(MCUCR_REG , 1 );
	SET_BIT(MCUCR_REG , 0 );

#elif SENSE_CONTROL_EXTI0 == EXTI_LOW_LEVEL
	CLR_BIT(MCUCR_REG , 1 );
	CLR_BIT(MCUCR_REG , 0 );
#endif





#if SENSE_CONTROL_EXTI1 == EXTI_FALLING_EDGE
	SET_BIT(MCUCR_REG , 3 );
	CLR_BIT(MCUCR_REG , 2 );

#elif SENSE_CONTROL_EXTI1 == EXTI_RAISING_EDGE
	SET_BIT(MCUCR_REG , 3 );
	SET_BIT(MCUCR_REG , 2 );

#elif SENSE_CONTROL_EXTI1 == EXTI_ON_CHANGE
	CLR_BIT(MCUCR_REG , 3 );
	SET_BIT(MCUCR_REG , 2 );

#elif SENSE_CONTROL_EXTI1 == EXTI_LOW_LEVEL
	CLR_BIT(MCUCR_REG , 3 );
	CLR_BIT(MCUCR_REG , 2 );
#endif





#if SENSE_CONTROL_EXTI2 == EXTI_FALLING_EDGE

	CLR_BIT(MCUCSR_REG , 6);

#elif SENSE_CONTROL_EXTI2 == EXTI_RAISING_EDGE
	SET_BIT(MCUCSR_REG , 6);

#elif SENSE_CONTROL_EXTI2 == EXTI_ON_CHANGE
#error "Not valid "

#elif SENSE_CONTROL_EXTI2 == EXTI_FALLING_EDGE
#error "Not valid "
#endif


}


void EXTI_voidChangeSenseControl(u8 Copy_u8IntId , u8 Copy_u8SenseControl)
{
	switch(Copy_u8IntId)
	{
	case EXTI_INT0:
		switch(Copy_u8SenseControl)
		{
		case EXTI_RAISING_EDGE:
			SET_BIT(MCUCR_REG , 1 );
			SET_BIT(MCUCR_REG , 0 );
			break;

		case EXTI_FALLING_EDGE:
			SET_BIT(MCUCR_REG , 1 );
			CLR_BIT(MCUCR_REG , 0 );

			break;

		case EXTI_ON_CHANGE:
			CLR_BIT(MCUCR_REG , 1 );
			SET_BIT(MCUCR_REG , 0 );
			break;


		case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR_REG , 1 );
			CLR_BIT(MCUCR_REG , 0 );
			break;
		default:
			break;
		}
		break;

		case EXTI_INT1:
			switch(Copy_u8SenseControl)
			{
			case EXTI_RAISING_EDGE:
				SET_BIT(MCUCR_REG , 3 );
				SET_BIT(MCUCR_REG , 2 );
				break;

			case EXTI_FALLING_EDGE:
				SET_BIT(MCUCR_REG , 3 );
				CLR_BIT(MCUCR_REG , 2 );
				break;

			case EXTI_ON_CHANGE:
				CLR_BIT(MCUCR_REG , 3 );
				SET_BIT(MCUCR_REG , 2 );

				break;

			case EXTI_LOW_LEVEL:
				CLR_BIT(MCUCR_REG , 3 );
				CLR_BIT(MCUCR_REG , 2 );
				break;
			default:
				break;
			}
			break;

			case EXTI_INT2:
				switch(Copy_u8SenseControl)
				{
				case EXTI_RAISING_EDGE:
					SET_BIT(MCUCSR_REG , 6);
					break;

				case EXTI_FALLING_EDGE:
					CLR_BIT(MCUCSR_REG , 6);

					break;

				default:
					break;
				}
				break;
				default:
					break;
	}
}
void EXTI_voidEnable(u8 Copy_u8IntId)
{
	switch (Copy_u8IntId)
	{
	case EXTI_INT0:
		SET_BIT(GICR_REG , 6 );
		break;

	case EXTI_INT1:
		SET_BIT(GICR_REG , 7 );
		break;

	case EXTI_INT2:
		SET_BIT(GICR_REG , 5 );
		break;

	default:
		break;
	}

}
void EXTI_voidDisable(u8 Copy_u8IntId)
{
	switch (Copy_u8IntId)
	{
	case EXTI_INT0:
		CLR_BIT(GICR_REG , 6 );
		break;

	case EXTI_INT1:
		CLR_BIT(GICR_REG , 7 );
		break;

	case EXTI_INT2:
		CLR_BIT(GICR_REG , 5 );
		break;

	default:
		break;
	}

}
void EXTI_voidSetCallBack (u8 Copy_u8InitId , void(*pf) (void) )
{
	if(pf != NULL)
	{
		switch(Copy_u8InitId)
		{
		case EXTI_INT0:
			Global_PtrToFun_Notification[0] = pf;
			break;

		case EXTI_INT1:
			Global_PtrToFun_Notification[1] = pf;
			break;

		case EXTI_INT2:
			Global_PtrToFun_Notification[2] = pf;
			break;

		default:
			break;
		}
	}
}

void __vector_1(void) __attribute__((signal));// 3a4an el function mattms74
void __vector_1(void)
{
	if(Global_PtrToFun_Notification[0] != NULL)
	{
		Global_PtrToFun_Notification[0]();// ptr
	}
}


void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(Global_PtrToFun_Notification[1] != NULL)
	{
		Global_PtrToFun_Notification[1]();
	}
}


void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(Global_PtrToFun_Notification[2] != NULL)
	{
		Global_PtrToFun_Notification[2]();
	}
}
