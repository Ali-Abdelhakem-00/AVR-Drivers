/*
 * main.c
 *
 *  Created on: Aug 15, 2023
 *      Author: alibo
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "freeRTOS/FreeRTOS.h"
#include "freeRTOS/task.h"
#include "freeRTOS/semphr.h"
#include <util/delay.h>
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/LCD/LCD_interface.h"

void APP1 (void *ptr);
void APP2 (void *ptr);
void APP3 (void *ptr);

void LCD_T1(void *ptr);
void LCD_T2(void *ptr);

void Blink_Led  (void *ptr);
void Push_Button(void *ptr);


xSemaphoreHandle LCD_semaphor ;
xSemaphoreHandle Button_semaphor ;

static u8 button ;
int main(void)
{
	LCD_voidInit();

	/* LAB1
	DIO_voidSetPinDirection(DIO_PORTA , DIO_PIN0 , DIO_OUTPUT) ;
	DIO_voidSetPinDirection(DIO_PORTA , DIO_PIN1 , DIO_OUTPUT) ;
	DIO_voidSetPinDirection(DIO_PORTA , DIO_PIN2 , DIO_OUTPUT) ;
	         xTaskCreate(APP1 , NULL , 300 , NULL , 1, NULL);
             xTaskCreate(APP2 , NULL , 300 , NULL , 1, NULL);
             xTaskCreate(APP3 , NULL , 300 , NULL , 1, NULL);*/


	/* LAB2
	vSemaphoreCreateBinary(LCD_semaphor);
	xTaskCreate( LCD_T1 , NULL , 300 , NULL , 1 , NULL );
	xTaskCreate( LCD_T2 , NULL , 300 , NULL , 1 , NULL );
		//create counting semaphore
	xSemaphoreCreateCounting(1 , 0);*/


      // ASS
	DIO_voidSetPinDirection (DIO_PORTA , DIO_PIN0 , DIO_OUTPUT);
	DIO_voidSetPinDirection (DIO_PORTB , DIO_PIN0 , DIO_INPUT);
	DIO_voidSetPinValue     (DIO_PORTB , DIO_PIN0 , DIO_HIGH);
	vSemaphoreCreateBinary(Button_semaphor);
	xSemaphoreTake(Button_semaphor, 0);
	xTaskCreate( Push_Button , NULL , 300 , NULL , 2 , NULL );
	xTaskCreate( Blink_Led   , NULL , 100 , NULL , 1 , NULL );
	vTaskStartScheduler();
	while(1)
	{

	}
	return 0;
}

void Push_Button(void *ptr)
{
	while(1)
	{
		button = DIO_u8GetPinValue ( DIO_PORTB , DIO_PIN0 ) ;
		if(  button == 0)
		{
			xSemaphoreGive(Button_semaphor);
			vTaskDelay(500);
		}
	}
}
void Blink_Led  (void *ptr)
{
	static u8 Local_u8State = 0 ;
	while(1)
	{
		if( xSemaphoreTake(Button_semaphor , portMAX_DELAY) == pdPASS )
		{
			TOG_BIT (Local_u8State , 0);
			DIO_voidSetPinValue(DIO_PORTA , DIO_PIN0 , Local_u8State ) ;
			xSemaphoreGive(Button_semaphor);
			vTaskDelay(500);
		}
	}
}

void LCD_T1(void *ptr)
{
	while(1)
	{
		if(xSemaphoreTake(LCD_semaphor , portMAX_DELAY) == pdPASS)
		{
			LCD_voidSendString((u8*)"IM Task1");
			xSemaphoreGive(LCD_semaphor);
			vTaskDelay(1000);
		}

	}
}

void LCD_T2(void *ptr)
{
	while(1)
	{
		if(xSemaphoreTake(LCD_semaphor , portMAX_DELAY) == pdPASS)
		{
			LCD_voidSendString((u8*)"IM Task2");
			xSemaphoreGive(LCD_semaphor);
			vTaskDelay(1000);
		}

	}
}

void APP1 (void * ptr)
{
	static u8 Local_u8State = 0 ;

	while(1)
	{
		TOG_BIT (Local_u8State , 0);
		DIO_voidSetPinValue(DIO_PORTA , DIO_PIN0 , Local_u8State ) ;
		vTaskDelay(1000);

	}
}
void APP2 (void *ptr)
{
	static u8 Local_u8State = 0 ;

	while(1)
	{
		TOG_BIT (Local_u8State , 0);
		DIO_voidSetPinValue(DIO_PORTA , DIO_PIN1 , Local_u8State ) ;
		vTaskDelay(2000);

	}
}
void APP3 (void *ptr)
{
	static u8 Local_u8State = 0 ;

	while(1)
	{
		TOG_BIT (Local_u8State , 0);
		DIO_voidSetPinValue(DIO_PORTA , DIO_PIN2 , Local_u8State ) ;
		vTaskDelay(3000);

	}
}

