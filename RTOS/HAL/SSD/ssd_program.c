/*
 * ssd_program.c
 *
 *  Created on: Aug 4, 2023
 *      Author: alibo
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include <util/delay.h>
#include"../../MCAL/DIO/DIO_interface.h"
#include"ssd_interface.h"





void SSD_void_Init   (SSD_Type * u8_copy_ptr_to_StructSSD)
{
	DIO_voidSetPortDirection(u8_copy_ptr_to_StructSSD->SSD_port, DIO_OUTPUT);
	switch(u8_copy_ptr_to_StructSSD-> common_state)
	{
	case state_anode:
		DIO_voidSetPortValue(u8_copy_ptr_to_StructSSD->SSD_port, 0xff);
		break;

	case state_cathode:
		DIO_voidSetPortValue(u8_copy_ptr_to_StructSSD->SSD_port, 0x00);
		break;

	default:break;
	}

}
void SSD_void_Enable (SSD_Type   *u8_copy_ptr_to_StructSSD,u8 copy_number)
{
	switch(u8_copy_ptr_to_StructSSD-> common_state)
	{
	case state_anode:
		DIO_voidSetPortValue(u8_copy_ptr_to_StructSSD->SSD_port, numbers_arr[copy_number]);
		break;

	case state_cathode:
		DIO_voidSetPortValue(u8_copy_ptr_to_StructSSD->SSD_port, ~numbers_arr[copy_number]);
		break;

	default:break;
	}

}
void SSD_void_Disable(SSD_Type   *u8_copy_ptr_to_StructSSD)
{
	switch(u8_copy_ptr_to_StructSSD-> common_state)
	{
	case state_anode:
		DIO_voidSetPortValue(u8_copy_ptr_to_StructSSD->SSD_port, 0xff);
		break;

	case state_cathode:
		DIO_voidSetPortValue(u8_copy_ptr_to_StructSSD->SSD_port, 0x00);
		break;

	default:break;
	}

}


void SSD_void_DisplayNumber_2SSD_SamePort (SSD_Type *copy_p_SSD_Type_1Anode ,  SSD_Type *copy_p_SSD_Type_2Cathod , u8 copy_number)
{
  int left = (copy_number/10);
  int right = (copy_number%10);
  DIO_voidSetPinValue(copy_p_SSD_Type_2Cathod->SSD_port , DIO_PIN7 , DIO_LOW);
  SSD_void_Enable(  copy_p_SSD_Type_2Cathod , right );
  _delay_ms(70);
  DIO_voidSetPinValue(copy_p_SSD_Type_1Anode->SSD_port , DIO_PIN7 , DIO_HIGH);
	SSD_void_Enable( copy_p_SSD_Type_1Anode ,left );

}

