/*
 * RTO_interface.h
 *
 *  Created on: Aug 26, 2023
 *      Author: alibo
 */

#ifndef SERVIES_RTO_RTO_INTERFACE_H_
#define SERVIES_RTO_RTO_INTERFACE_H_





void RTO_voidInit(void);

u8 RTO_u8CreateTask( u8 copy_u8Pariority  , u16 copy_u16periodicity  , u16 copy_firstdelay , void (*LDF) (void));

#endif /* SERVIES_RTO_RTO_INTERFACE_H_ */
