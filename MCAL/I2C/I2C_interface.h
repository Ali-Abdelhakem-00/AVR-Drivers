/*
 * I2C_interface.h
 *
 *  Created on: Aug 22, 2023
 *      Author: alibo
 */

#ifndef MCAL_I2C_I2C_INTERFACE_H_
#define MCAL_I2C_I2C_INTERFACE_H_

typedef enum
{
	NoERROR,
	STARTCONDITION_ERROR,
	REPEATED_STARTCONDITION_ERROR,
	SEND_SLAVEADDRESS_ANDWRITE_ERROR,
	SEND_SLAVEADDRESS_ANDREAD_ERROR,
	MASTER_WRITEBYTE_ERROR,
	MASTER_RECEIVEBYTE_ERROR
}TWI_ErrorStatus_t;
void TWI_voidInitMaster (u8 copy_u8MasterAdress);

void TWI_voidInitSlave(u8 copy_u8SlaveAdress);

TWI_ErrorStatus_t TWI_ErrorStatus_Send_StartCondition(void);

TWI_ErrorStatus_t TWI_ErrorStatus_Send_RepeatedStartCondition(void);

TWI_ErrorStatus_t TWI_ErrorStatus_Send_SlaveAddress_And_Write(u8 copy_u8SlaveAdress);

TWI_ErrorStatus_t TWI_ErrorStatus_Send_SlaveAddress_And_Read(u8 copy_u8SlaveAdress);

TWI_ErrorStatus_t TWI_ErrorStatus_MasterWriteData(u8 copy_u8Data);

TWI_ErrorStatus_t TWI_ErrorStatus_MasterReadData(u8 *copy_PtrTou8ReceivedData);

void TWI_voidSendStopCondition(void);
#endif /* MCAL_I2C_I2C_INTERFACE_H_ */
