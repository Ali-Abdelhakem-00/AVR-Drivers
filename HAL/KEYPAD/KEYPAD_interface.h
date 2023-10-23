/*
 * KEYPAD_interface.h
 *
 *  Created on: Aug 6, 2023
 *      Author: alibo
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_



#define NOT_PRESSED  0xff

void KEYPAD_void_Init(void);
u8 KEYPAD_u8GetPresed(void);

#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
