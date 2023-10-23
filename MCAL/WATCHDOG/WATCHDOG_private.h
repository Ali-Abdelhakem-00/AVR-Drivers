/*
 * WATCHDOG_private.h
 *
 *  Created on: Aug 19, 2023
 *      Author: alibo
 */

#ifndef MCAL_WATCHDOG_WATCHDOG_PRIVATE_H_
#define MCAL_WATCHDOG_WATCHDOG_PRIVATE_H_


#define WDTCR    *( (volatile u8*)  (0x41) )

#define WDTOE   4
#define WDE     3

#endif /* MCAL_WATCHDOG_WATCHDOG_PRIVATE_H_ */
