/*
 * ssd_interface.h
 *
 *  Created on: Aug 4, 2023
 *      Author: alibo
 */

#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_

#define state_anode     1
#define state_cathode   0


// for anode
#define ZERO   0b11000000
#define ONE    0b11111001
#define TWO    0b10100100
#define THREE  0b10110000
#define FOUR   0b10011001
#define FIVE   0b10010010
#define SIX    0b10000010
#define SEVEN  0b11111000
#define EIGHT  0b10000000
#define NINE   0b10010000
const static u8 numbers_arr[10]={ZERO, ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
typedef struct
{
	u8 SSD_port;
	u8 common_state;
}SSD_Type;



void SSD_void_Init   (SSD_Type   *u8_copy_ptr_to_StructSSD);
void SSD_void_Enable (SSD_Type   *u8_copy_ptr_to_StructSSD,u8 copy_number);
void SSD_void_Disable(SSD_Type   *u8_copy_ptr_to_StructSSD);
void SSD_void_DisplayNumber_2SSD_SamePort (SSD_Type *copy_p_SSD_Type_1Anode ,  SSD_Type *copy_p_SSD_Type_2Cathod , u8 copy_number);


#endif /* HAL_SSD_SSD_INTERFACE_H_ */
