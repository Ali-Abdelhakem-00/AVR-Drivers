/*
 * LED_program.c
 *
 *  Created on: Aug 3, 2023
 *      Author: alibo
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../../MCAL/DIO/DIO_interface.h"
#include"LED_interface.h"

void LED_voidInit  (LED_Type *copy_ptrToStruct)
{
	DIO_voidSetPinDirection(copy_ptrToStruct->Port,copy_ptrToStruct->Pin,DIO_OUTPUT);
	switch (copy_ptrToStruct -> Active_State)
	{
	case ACTIVE_HIGH:
		DIO_voidSetPinValue(copy_ptrToStruct->Port, copy_ptrToStruct->Pin , DIO_LOW);
		break;

	case ACTIVE_LOW:
		DIO_voidSetPinValue(copy_ptrToStruct->Port, copy_ptrToStruct->Pin , DIO_HIGH);
		break;
	default:
		break;
    }
}



void LED_voidON    (LED_Type *copy_ptrToStruct)
{
	switch (copy_ptrToStruct -> Active_State)
	{
	case ACTIVE_HIGH:
		DIO_voidSetPinValue(copy_ptrToStruct->Port, copy_ptrToStruct->Pin , DIO_HIGH);
		break;


	case ACTIVE_LOW:
		DIO_voidSetPinValue(copy_ptrToStruct->Port, copy_ptrToStruct->Pin , DIO_LOW);
		break;
	default:
		break;
    }

}


void LED_voidOFF   (LED_Type *copy_ptrToStruct)
{
	switch (copy_ptrToStruct -> Active_State)
	{
	case ACTIVE_HIGH:
		DIO_voidSetPinValue(copy_ptrToStruct->Port, copy_ptrToStruct->Pin , DIO_LOW);
		break;


	case ACTIVE_LOW:
		DIO_voidSetPinValue(copy_ptrToStruct->Port, copy_ptrToStruct->Pin , DIO_HIGH);
		break;
	default:
		break;
    }
}
