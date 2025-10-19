/*
 * XPT2046.c
 *
 *  Created on: Oct 19, 2025
 *      Author: irakli
 */

#include "XPT2046_port.h"

// Implement for your MCU
#include "spi.h"

u8 XPT2046_SPI_transfer(u8 tx){
	u8 rx;
	HAL_SPI_TransmitReceive(&hspi2, &tx, &rx, 1, HAL_MAX_DELAY);

	return rx;
}
