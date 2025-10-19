/*
 * lcd_port.h
 *
 *  Created on: Oct 14, 2025
 *      Author: irakli
 */


/// EDIT THIS FILE FOR YOUR MCU

#ifndef INC_ST7796S_PORT_H_
#define INC_ST7796S_PORT_H_

#include "stm32f1xx_hal.h"
#include "string.h"
#include "spi.h"

//////////////////////////////////////////////////////////////////
//-----------------LCD----------------
#define LCD_GPIO_PORT   GPIOB

#define LCD_LED_PIN     GPIO_PIN_9
#define LCD_CS_PIN      GPIO_PIN_11
#define LCD_RS_PIN      GPIO_PIN_10
#define LCD_RST_PIN     GPIO_PIN_12

// Short macros using HAL functions:

// Backlight LED control
#define LCD_LED_SET()      HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_LED_PIN, GPIO_PIN_SET)
#define LCD_LED_CLR()      HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_LED_PIN, GPIO_PIN_RESET)

// LCD control pins
#define LCD_CS_SET()       HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_CS_PIN, GPIO_PIN_SET)
#define LCD_CS_CLR()       HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_CS_PIN, GPIO_PIN_RESET)

#define LCD_RS_SET()       HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_RS_PIN, GPIO_PIN_SET)
#define LCD_RS_CLR()       HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_RS_PIN, GPIO_PIN_RESET)

#define LCD_RST_SET()      HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_RST_PIN, GPIO_PIN_SET)
#define LCD_RST_CLR()      HAL_GPIO_WritePin(LCD_GPIO_PORT, LCD_RST_PIN, GPIO_PIN_RESET)

#define Delay_ms(var) HAL_Delay(var)
#define LCD_SPI_Transfer(data) HAL_SPI_Transmit(&hspi2, &data, 1, HAL_MAX_DELAY);

#define u8	    uint8_t
#define u16 	uint16_t
#define u32		uint32_t

#define strlen_stud(str) strlen((const char *)(str))

/* Or if you dont want to use string.h
 #define strlen_stud(str) ({ \
    const char *_s = (str); \
    size_t _len = 0; \
    while (*_s++) _len++; \
    _len; \
})
 */
#endif /* INC_ST7796S_PORT_H_ */
