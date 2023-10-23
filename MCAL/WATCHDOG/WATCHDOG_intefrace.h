/*
 * WATCHDOG_intefrace.h
 *
 *  Created on: Aug 19, 2023
 *      Author: alibo
 */

#ifndef MCAL_WATCHDOG_WATCHDOG_INTEFRACE_H_
#define MCAL_WATCHDOG_WATCHDOG_INTEFRACE_H_

typedef enum
{
	oscillator_16k , oscillator_32k , oscillator_64k ,oscillator_128k,
	oscillator_256k , oscillator_512k , oscillator_1024k ,oscillator_2048k

}WDT_Prescale_t;

void WDT_voidEnable(WDT_Prescale_t Copy_Prescaler);
void WDT_voidDisable(void);


#endif /* MCAL_WATCHDOG_WATCHDOG_INTEFRACE_H_ */
