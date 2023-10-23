/*
 * WATCHDOG_program.c
 *
 *  Created on: Aug 19, 2023
 *      Author: alibo
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../../MCAL/DIO/DIO_interface.h"
#include"WATCHDOG_intefrace.h"
#include"WATCHDOG_private.h"




void WDT_voidEnable(WDT_Prescale_t Copy_Prescaler)
{
	WDTCR = 0xF8 ;
     WDTCR |=  Copy_Prescaler ;
}
void WDT_voidDisable(void)
{
	WDTCR |= (2<< 3);
}
