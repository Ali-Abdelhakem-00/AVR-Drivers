/*
 * RTO_private.h
 *
 *  Created on: Aug 26, 2023
 *      Author: alibo
 */

#ifndef SERVIES_RTO_RTO_PRIVATE_H_
#define SERVIES_RTO_RTO_PRIVATE_H_

typedef struct
{
	u16 periodicty;
	u16 firstdelay;
	void (*pf) (void);
}RTO_TCB;

static void RTO_voidStartScheudler(void);
#endif /* SERVIES_RTO_RTO_PRIVATE_H_ */
