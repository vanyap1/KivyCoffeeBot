/*
 * dataHandler.h
 *bb
 * Created: 19.04.2024 0:23:05
 *  Author: Vanya
 */ 
#include <avr/io.h>
#include "string.h"
#include "stdbool.h"
#include "uart_hal.h"

#ifndef DAT_HAND_H_
#define DAT_HAND_H_

#define	I2C					0x01
#define	UART				0x02
#define	SPI					0x03
#define	GPIO				0x04
#define UNDEFINED			0xff

#define	MAX_DATA_SIZE		32
#define HEX_STRING_LENGTH	2


typedef struct {
	uint8_t ifType;						//required interface
	uint8_t action;						//action - R/W
	uint8_t devAddr;					//destination device address
	uint8_t devReg;					//destination device register
	uint8_t dataBuff[MAX_DATA_SIZE];    //devise read/write data buffer
	uint8_t datagramLength;				//How much bytes need to read or write. Read - replaced user dummy bytes. Write - depends of data buff length received 
	uint8_t actionReq;					//1 - read device immediately
} bridgeDatagram;


uint8_t dataParce(uint8_t* inputByteArray, bridgeDatagram* destStructure);







#endif