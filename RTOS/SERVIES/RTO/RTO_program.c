/*
 * RTO_program.c
 *
 *  Created on: Aug 26, 2023
 *      Author: alibo
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/TIMER/TIMER_interface.h"

#include "RTO_interface.h"
#include "RTO_private.h"
#include "RTO_config.h"

RTO_TCB RTO_AstrTasks [RTO_MAX_PRIORITY] ;

void RTO_voidInit(void)
{
	// ini timer //timer1 ctc ocr = 1000 , pie ,

	TIMER_CONFIG_T1 mytimer1 = { .timer_mode_T1   = CTC_T1_OCRA1_TOP ,
	                             .control_oc_T1   =  OC1A__OC1B_DISCONNECTED_NONPWM,
	                             .clock_source_T1 =  FCPU_DIVBY_8_T1
	                           };

	Timer_voidCallBackFun( RTO_voidStartScheudler );


	Timer_voidSetCompareMatchValueT1A(Timer_Tick_CPU);

	Timer_voidT1Init(&mytimer1);

	// timer start

}

u8 RTO_u8CreateTask( u8 Copy_u8Pariority  , u16 Copy_u16periodicity  , u16 Copy_firstdelay , void (*LDF) (void))
{
	u8 Local_u8ErrorState  = STD_TYPE_OK ;
	if( (LDF != NULL) && (Copy_u8Pariority < RTO_MAX_PRIORITY) )
	{
	RTO_AstrTasks [Copy_u8Pariority].firstdelay = Copy_firstdelay;
	RTO_AstrTasks [Copy_u8Pariority].periodicty = Copy_u16periodicity;
	RTO_AstrTasks [Copy_u8Pariority].pf = LDF ;
	}
	else
	{
		Local_u8ErrorState = STD_TYPE_NOTOK ;
	}
	return Local_u8ErrorState;
}

static void RTO_voidStartScheudler(void)
{
	u8 local_u8counter =0 ;
	for(local_u8counter = 0 ; local_u8counter < RTO_MAX_PRIORITY ; local_u8counter++)
	{
		if( RTO_AstrTasks [local_u8counter].firstdelay == 0)
		{
			// run task
			 RTO_AstrTasks [local_u8counter].pf();
			//next run
			 RTO_AstrTasks [local_u8counter].firstdelay =  (RTO_AstrTasks [local_u8counter].periodicty) - 1   ;
		}
		else
		{
			 RTO_AstrTasks [local_u8counter].firstdelay -- ;
		}
	}
}
