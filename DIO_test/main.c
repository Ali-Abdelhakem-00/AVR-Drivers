/*
 * main.c
 *
 *  Created on: Aug 3, 2023
 *      Author: alibo
 */


#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include"MCAL/DIO/DIO_interface.h"
#define  F_CPU          8000000UL
#include<util/delay.h>





int  main(void)
{
	u8 local_variable ;/*
	 DIO_voidSetPinDirection    (DIO_PORTA, DIO_PIN0 , DIO_OUTPUT );
	 DIO_voidSetPinValue    (DIO_PORTA , DIO_PIN0 , DIO_HIGH );
	 local_variable = DIO_u8GetPinValue        (DIO_PORTA ,  DIO_PIN0 );*/

	 DIO_voidSetPortDirection(DIO_PORTA,DIO_OUTPUT);
	 DIO_voidSetPinDirection    (DIO_PORTC, DIO_PIN1 , DIO_OUTPUT );

	 DIO_voidSetPortValue(DIO_PORTA,50);





	 local_variable= 	DIO_u8GetPortValue(DIO_PORTA);
	 while(1)

		 {
		 switch (local_variable)
	 {
	 case 50 :  DIO_voidSetPinValue    (DIO_PORTC , DIO_PIN1 , DIO_HIGH );
		 break;


	 case 0:
		 break;

	 }

		 }

	return 0;
}
