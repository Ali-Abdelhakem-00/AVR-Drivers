/*
 * KEYPAD_program.c
 *
 *  Created on: Aug 6, 2023
 *      Author: alibo
 */


#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../../MCAL/DIO/DIO_interface.h"
#define F_CPU   8000000UL
#include<util/delay.h>
#include"KEYPAD_interface.h"
#include"KEYPAD_private.h"
#include"KEYPAD_config.h"




void KEYPAD_void_Init(void)
{
	DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_COL1_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_COL2_PIN,DIO_OUTPUT);

	DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_COL3_PIN,DIO_OUTPUT);
	DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_COL4_PIN,DIO_OUTPUT);

	DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_ROW1_PIN,DIO_INPUT);
	DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_ROW2_PIN,DIO_INPUT);
	DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_ROW3_PIN,DIO_INPUT);
	DIO_voidSetPinDirection(KEYPAD_PORT,KEYPAD_ROW4_PIN,DIO_INPUT);

	DIO_voidSetPortValue(KEYPAD_PORT,0xff);

}

u8 KEYPAD_u8GetPresed(void)
{


	u8 Local_u8KeyPressed = NOT_PRESSED;

	for(u8 col_index=0 ; col_index < NUM_OF_COLS ; col_index++)
	{
		DIO_voidSetPinValue(KEYPAD_PORT,col_pins[col_index],DIO_LOW);

		for(u8 row_index=0; row_index < NUM_OF_ROWS ;row_index ++)
		{
			if( DIO_u8GetPinValue(KEYPAD_PORT,row_pins[row_index])  == 0)
			{

				Local_u8KeyPressed = KEYPAD[row_index][col_index];

                    while( DIO_u8GetPinValue(KEYPAD_PORT,row_pins[row_index] )  == 0)
                    {

                    }

                    _delay_ms(20);
			}
			else
			{

			}
		}

		DIO_voidSetPinValue(KEYPAD_PORT,col_pins[col_index],DIO_HIGH);
	}
	return Local_u8KeyPressed;



}
