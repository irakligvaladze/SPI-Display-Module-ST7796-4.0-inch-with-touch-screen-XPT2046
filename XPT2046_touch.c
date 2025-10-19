/*
 * XPT2046_touch.c
 *
 *  Created on: Oct 14, 2025
 *      Author: irakli
 */


// * @parameters :direction:0-0 degree
//                          1-90 degree
//						    2-180 degree
//						    3-270 degree

#include "XPT2046_touch.h"
#include "XPT2046_port.h"

// calibration values might need adjustment for your screen
const float b0x = 0.1782f;
const float b1x = -20.4f;
const float b0y = -0.26f;
const float b1y = 512.8f;

u16 XPT2046_Read12Bit(u8 channel)
{
	u8 cmd = XPT2046_MODE;
	cmd |= channel<<4;
    u8 tx[3]; // 1 command + 2 dummy bytes for ADC
    u8 rx[3]; // received bytes
    u16 value;

    tx[0] = cmd;   // send command
    tx[1] = 0x00;  // dummy byte 1
    tx[2] = 0x00;  // dummy byte 2

    rx[0] = 0;

    XPT2046_CS_CLR();

    // Full-duplex transmit & receive
    XPT2046_SPI_transfer(tx[0]);
    rx[1] = XPT2046_SPI_transfer(tx[1]);
    rx[2] = XPT2046_SPI_transfer(tx[2]);
    XPT2046_CS_SET();

    // Combine received bytes: 12-bit data is in rx[1] (MSB) and upper nibble of rx[2] (LSB)
    value = ((u16)rx[1] << 8) | rx[2];
    value >>= 4; // shift down to get 12-bit value

    return value; // 0..4095
}

void XPT2046_GetXY(u16 *x_pixel, u16 *y_pixel, u8 direction)
{

    u16 x_raw = XPT2046_Read12Bit(XPT2046_X);
    u16 y_raw = XPT2046_Read12Bit(XPT2046_Y);

    // map raw to LCD pixels, touch screen and display axis are different
    // that why x and y are mixed
    float xf = y_raw*b0x + b1x;
    float yf = x_raw*b0y + b1y;
    if(xf<0){
    	xf = 0;
    }
    if(xf>=LCD_W){
    	xf = LCD_W-1;
    }
    if(yf<0){
    	yf = 0;
    }
    if(yf>=LCD_H){
    	yf = LCD_H-1;
    }
    u16 x = (u16)xf;
    u16 y = (u16)yf;

    // apply rotation
    u16 x_rot, y_rot;
    switch (direction)
    {
        case 0: // normal
            x_rot = x;
            y_rot = y;
            break;
        case 1: // 90°
            x_rot = y;
            y_rot = LCD_W - 1 - x;
            break;
        case 2: // 180°
            x_rot = LCD_W - 1 - x;
            y_rot = LCD_H - 1 - y;
            break;
        case 3: // 270°
            x_rot = LCD_H - 1 - y;
            y_rot = x;
            break;
        default:
            x_rot = x;
            y_rot = y;
            break;
    }

    *x_pixel = x_rot;
    *y_pixel = y_rot;
}

u16 XPT2046_GetZ(void)
{
    u16 x_raw = XPT2046_Read12Bit(XPT2046_X); // required for Z formula
    u16 z1 = XPT2046_Read12Bit(XPT2046_Z1);
    u16 z2 = XPT2046_Read12Bit(XPT2046_Z2);

    if (z1 == 0) return 0; // avoid division by zero

    // linear approximation
    u16 z = x_raw * (z2 - z1) / z1;

    return z;
}

