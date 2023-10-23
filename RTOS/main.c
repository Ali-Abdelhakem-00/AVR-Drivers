/*
 * main.c
 *
 *  Created on: Aug 15, 2023
 *      Author: alibo
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include <util/delay.h>
#define  F_CPU          8000000UL
#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIMER/TIMER_interface.h"
#include "MCAL/GIE/GIE_interface.h"
#include "HAL/LCD/LCD_interface.h"
#include "HAL/KEYPAD/KEYPAD_interface.h"
#include "SERVIES/RTO/RTO_interface.h"


void APP1 (void);
void APP2 (void);
void APP3 (void);
int main(void)
{


	DIO_voidSetPinDirection(DIO_PORTA , DIO_PIN0 , DIO_OUTPUT) ;
	DIO_voidSetPinDirection(DIO_PORTA , DIO_PIN1 , DIO_OUTPUT) ;
	DIO_voidSetPinDirection(DIO_PORTA , DIO_PIN2 , DIO_OUTPUT) ;



RTO_u8CreateTask( 0 , 1000 , 0 , APP1);
RTO_u8CreateTask( 1 , 3000 , 0 , APP2);
RTO_u8CreateTask( 2 , 5000 , 0 , APP3);

GIE_voidEnable();

RTO_voidInit();
	while(1)
	{
	}
	return 0;
}

void APP1 (void)
{

	TOG_BIT ( *((volatile u8*)0x3b) , 0);
}
void APP2 (void)
{

	TOG_BIT(  *((volatile u8*)0x3b) , 1);

}
void APP3 (void)
{

	TOG_BIT(  *((volatile u8*)0x3b) , 2);

}
