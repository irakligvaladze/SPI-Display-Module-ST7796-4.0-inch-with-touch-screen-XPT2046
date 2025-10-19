/*
 * XPT2046_port.h
 *
 *  Created on: Oct 19, 2025
 *      Author: irakli
 */

#ifndef INC_XPT2046_PORT_H_
#define INC_XPT2046_PORT_H_

// Implement this for your MCU dont forget to initialize IRQ PIN and CS PIN
#include <stdint.h>
#include "stm32f1xx_hal.h"

#define XPT2046_IRQ_PORT    	GPIOB
#define XPT2046_IRQ_PIN    		GPIO_PIN_4

#define XPT2046_CS_PORT   		GPIOB
#define XPT2046_CS_PIN   		GPIO_PIN_3

#define XPT2046_Touch()			!HAL_GPIO_ReadPin(XPT2046_IRQ_PORT, XPT2046_IRQ_PIN)

#define XPT2046_CS_SET()     	HAL_GPIO_WritePin(XPT2046_CS_PORT, XPT2046_CS_PIN, GPIO_PIN_SET)
#define XPT2046_CS_CLR()        HAL_GPIO_WritePin(XPT2046_CS_PORT, XPT2046_CS_PIN, GPIO_PIN_RESET)

#define u8	    uint8_t
#define u16 	uint16_t


// SPI speed should be less then 5MHz, 2MHz is considered safe
u8 XPT2046_SPI_transfer(u8 tx);


#endif /* INC_XPT2046_PORT_H_ */
