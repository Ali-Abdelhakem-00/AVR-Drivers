/*
 * I2C_program.c
 *
 *  Created on: Aug 22, 2023
 *      Author: alibo
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"


void TWI_voidInitMaster (u8 copy_u8MasterAdress)
{
	/*enable ack */
	SET_BIT( TWCR_REG , TWCR_ENABLE_ACK_BIT );

	// set SCL FREQ TO 100KHZ WITH 8MHZ
	TWBR_REG = 8 ;

	//set  prescaler to 1
	CLR_BIT( TWSR_REG , TWSR_TWPS0);
	CLR_BIT( TWSR_REG , TWSR_TWPS1);

	if( copy_u8MasterAdress == 0)
	{

	}
	else
	{
		// PUT MASTER ADRESS
		TWAR_REG = (copy_u8MasterAdress << 1 );
	}

	// ENABLE TWI
	SET_BIT( TWCR_REG , TWCR_ENABLE_BIT );
}

void TWI_voidInitSlave(u8 copy_u8SlaveAdress)
{
	// SET THE ADDRESS
	TWAR_REG = (copy_u8SlaveAdress << 1 );
	//ENABLE ACK
	SET_BIT( TWCR_REG , TWCR_ENABLE_ACK_BIT );
	//ENABLE TWI
	SET_BIT( TWCR_REG , TWCR_ENABLE_BIT );

}

TWI_ErrorStatus_t TWI_ErrorStatus_Send_StartCondition(void)
{
	u8 localError = NoERROR;
	//send a start condition
	SET_BIT( TWCR_REG , TWCR_START_COND_BIT );
	//Clear the twint flag
	SET_BIT( TWCR_REG , TWCR_INTERRUPT_FLAG_BIT );
	//wait until the operation finishes and flag raised again
	while( GET_BIT( TWCR_REG , TWCR_INTERRUPT_FLAG_BIT) == 0 );

	//check if the start condition was sent Successfully.
	if(  (TWSR_REG & 0b11111000) == START_ACK )
	{
	}
	else
	{
		localError = STARTCONDITION_ERROR ;
	}
	return localError ;
}

TWI_ErrorStatus_t TWI_ErrorStatus_Send_RepeatedStartCondition(void)
{
	u8 localError = NoERROR;
	//send a start condition
	SET_BIT( TWCR_REG , TWCR_START_COND_BIT );
	//Clear the twint flag
	SET_BIT( TWCR_REG , TWCR_INTERRUPT_FLAG_BIT );
	//wait until the operation finishes and flag raised again
	while( GET_BIT( TWCR_REG , TWCR_INTERRUPT_FLAG_BIT) == 0 );

	//check if the start condition was sent Successfully.
	if(  (TWSR_REG & 0b11111000) == REP_START_ACK )
	{
	}
	else
	{
		localError = REPEATED_STARTCONDITION_ERROR ;
	}
	return localError ;

}


TWI_ErrorStatus_t TWI_ErrorStatus_Send_SlaveAddress_And_Write(u8 copy_u8SlaveAdress)
{
	u8 localError = NoERROR;

	TWDR_REG = (copy_u8SlaveAdress << 1) & 0b11111110 ;

	// clear start condition
	CLR_BIT( TWCR_REG , TWCR_START_COND_BIT );
	//clear twin flag
	SET_BIT( TWCR_REG , TWCR_INTERRUPT_FLAG_BIT );
	//wait until operation finishs
	while( GET_BIT( TWCR_REG , TWCR_INTERRUPT_FLAG_BIT) == 0 );
	//check for condition status code
	if(  (TWSR_REG & 0b11111000) == SLAVE_ADD_AND_WR_ACK )
	{
	}
	else
	{
		localError = SEND_SLAVEADDRESS_ANDWRITE_ERROR ;
	}
	return localError ;
}

TWI_ErrorStatus_t TWI_ErrorStatus_Send_SlaveAddress_And_Read(u8 copy_u8SlaveAdress)
{
	u8 localError = NoERROR;

	TWDR_REG = (copy_u8SlaveAdress << 1) | 1 ;

	// clear start condition
	CLR_BIT( TWCR_REG , TWCR_START_COND_BIT );
	//clear twin flag
	SET_BIT( TWCR_REG , TWCR_INTERRUPT_FLAG_BIT );
	//wait until operation finishes
	while( GET_BIT( TWCR_REG , TWCR_INTERRUPT_FLAG_BIT) == 0 );
	//check for condition status code
	if(  (TWSR_REG & 0b11111000) == SLAVE_ADD_AND_RD_ACK )
	{
	}
	else
	{
		localError = SEND_SLAVEADDRESS_ANDREAD_ERROR ;
	}
	return localError ;
}


TWI_ErrorStatus_t TWI_ErrorStatus_MasterWriteData(u8 copy_u8Data)
{
	u8 localError = NoERROR;
	TWDR_REG = copy_u8Data ;

	//clear twin flag
	SET_BIT( TWCR_REG , TWCR_INTERRUPT_FLAG_BIT );
	//wait until operation finishes
	while( GET_BIT( TWCR_REG , TWCR_INTERRUPT_FLAG_BIT) == 0 );
	//check for condition status code
	if(  (TWSR_REG & 0b11111000) == MSTR_WR_BYTE_ACK )
	{
	}
	else
	{
		localError = MASTER_WRITEBYTE_ERROR ;
	}

	return localError ;
}


TWI_ErrorStatus_t TWI_ErrorStatus_MasterReadData(u8 *copy_PtrTou8ReceivedData)
{
	u8 localError = NoERROR;


	//clear twin flag
	SET_BIT( TWCR_REG , TWCR_INTERRUPT_FLAG_BIT );
	//wait until operation finishes
	while( GET_BIT( TWCR_REG , TWCR_INTERRUPT_FLAG_BIT) == 0 );
	//check for condition status code
	if(  (TWSR_REG & 0b11111000) == MSTR_RD_BYTE_WITH_ACK )
	{
		 *copy_PtrTou8ReceivedData = TWDR_REG ;
	}
	else
	{
		localError = MASTER_RECEIVEBYTE_ERROR ;
	}

	return localError ;
}


void TWI_voidSendStopCondition(void)
{
	SET_BIT( TWCR_REG , TWCR_STOP_COND_BIT);

	SET_BIT( TWCR_REG , TWCR_INTERRUPT_FLAG_BIT);
}
