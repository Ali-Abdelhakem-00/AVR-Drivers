/*
 * I2C_private.h
 *
 *  Created on: Aug 22, 2023
 *      Author: alibo
 */

#ifndef MCAL_I2C_I2C_PRIVATE_H_
#define MCAL_I2C_I2C_PRIVATE_H_

#define TWBR_REG  *( (volatile u8*) (0x20) )
#define TWDR_REG  *( (volatile u8*) (0x23) )
#define TWCR_REG  *( (volatile u8*) (0x56) )
#define TWSR_REG  *( (volatile u8*) (0x21) )
#define TWAR_REG  *( (volatile u8*) (0x22) )

#define TWCR_INTERRUPT_FLAG_BIT        7
#define TWCR_ENABLE_ACK_BIT            6
#define TWCR_START_COND_BIT            5
#define TWCR_STOP_COND_BIT             4
#define TWCR_ENABLE_BIT                2



#define TWSR_TWPS0                   0
#define TWSR_TWPS1                   1

#define START_ACK                0x08 //start has been sent
#define REP_START_ACK            0x10 //repeated start
#define SLAVE_ADD_AND_WR_ACK     0x18 //Master transmit ( slave address + Write request ) ACK
#define SLAVE_ADD_AND_RD_ACK     0x40 //Master transmit ( slave address + Read request ) ACK
#define MSTR_WR_BYTE_ACK         0x28 //Master transmit data ACK
#define MSTR_RD_BYTE_WITH_ACK    0x50 //Master received data with ACK
#define MSTR_RD_BYTE_WITH_NACK   0x58 //Master received data with not ACK
#define SLAVE_ADD_RCVD_RD_REQ    0xA8 //means that slave address is received with read request
#define SLAVE_ADD_RCVD_WR_REQ    0x60 //means that slave address is received with write request
#define SLAVE_DATA_RECEIVED      0x80 //means that a byte is received
#define SLAVE_BYTE_TRANSMITTED   0xB8 //means that the written byte is transmitted

#endif /* MCAL_I2C_I2C_PRIVATE_H_ */
