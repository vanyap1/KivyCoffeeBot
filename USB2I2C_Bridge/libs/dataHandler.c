/*
 * dataHandler.c
 *bb
 * Created: 19.04.2024 0:22:57
 *  Author: Vanya
 */ 
#include <stdint.h>
#include "dataHandler.h"


uint8_t dataParce(uint8_t* inputByteArray, bridgeDatagram* destStructure){
	if (inputByteArray == NULL || destStructure == NULL) {
		return 0;
	}
	uint8_t fgf = 0;
	for (int i = 0; inputByteArray[i]; i++) {
        inputByteArray[i] = tolower(inputByteArray[i]);
		fgf++;
    }
	
	char* token;
    char* saveptr;
    char* ifType, *action, *devAddr, *devReg, *dataBuff;

    token = strtok_r((char*)inputByteArray, ";,", &saveptr);
    ifType = token;
    token = strtok_r(NULL, ";,", &saveptr);
    action = token;
    token = strtok_r(NULL, ";,", &saveptr);
    devAddr = token;
    token = strtok_r(NULL, ";,", &saveptr);
    devReg = token;
    token = strtok_r(NULL, ";,", &saveptr);
    dataBuff = token;
	
	if (strcmp(ifType, "i2c") == 0) {
		destStructure->ifType = I2C;
		} else if (strcmp(ifType, "spi") == 0) {
		destStructure->ifType = SPI;
		} else if (strcmp(ifType, "uart") == 0) {
		destStructure->ifType = UART;
		} else if (strcmp(ifType, "gpio") == 0) {
		destStructure->ifType = GPIO;
		} else {
		destStructure->ifType = UNDEFINED;
	}
	
	destStructure->action = (strcmp(action, "w") == 0) ? 0x01 : 0x00;
	sscanf(devAddr, "%x", &destStructure->devAddr);
	sscanf(devReg, "%x", &destStructure->devReg);
	uint8_t bytesToConvert = strlen(dataBuff);
	destStructure->datagramLength = bytesToConvert/2;
	destStructure->actionReq = 1;
	memset(destStructure->dataBuff, 0, sizeof(destStructure->dataBuff));
	for (int i = 0; i < bytesToConvert; i++) {
		sscanf(dataBuff + i * HEX_STRING_LENGTH, "%2hhx", &(destStructure->dataBuff[i]));
	}
	return 1;
	
	
}



