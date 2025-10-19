/*
 * XPT2046_touch.h
 *
 *  Created on: Oct 14, 2025
 *      Author: irakli
 */

#ifndef INC_XPT2046_TOUCH_H_
#define INC_XPT2046_TOUCH_H_

#include "XPT2046_port.h"



#define LCD_W 320
#define LCD_H 480

#define Z_THRESHOLD 10000 // you might need to adjust this to detect valid touch


#define XPT2046_MODE 	0x80 // 12 bit mode, differential-signal
#define XPT2046_X 		1
#define XPT2046_Y 		5
#define XPT2046_Z1 		3
#define XPT2046_Z2 		4

// Used in 12 bit mode
u16 XPT2046_Read12Bit(u8 channel);
void XPT2046_GetXY(u16 *x_pixel, u16 *y_pixel, u8 direction);
u16 XPT2046_GetZ(void);


#endif /* INC_XPT2046_TOUCH_H_ */
