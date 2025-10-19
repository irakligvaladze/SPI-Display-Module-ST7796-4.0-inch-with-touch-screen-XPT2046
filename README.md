# SPI-Display-Module-ST7796-4.0-inch-with-touch-screen-XPT2046

Modular C library for the **ST7796 4.0” SPI LCD** with **XPT2046 touch**, providing portable drawing and touch functions. The library is configurable via header files for a specific MCU and includes ready-to-run example projects.

---
![MSP4021-002](https://github.com/user-attachments/assets/e92da91c-1989-4123-ba69-333680145c98)

## Features
- Portable C library for STM32 and other microcontrollers.
- Provides **drawing primitives**: pixels, lines, rectangles, circles, text, and images.
- Provides **touch functions**: X/Y/Z reading, touch detection.
- Easy to integrate with bare-metal or RTOS projects.
- Includes ready-to-run example code demonstrating all features.

---

## MCU Adaptation

To adapt this library to your specific microcontroller:

1. **Display (ST7796) Porting**  
   - Modify `ST7796S_port.h` for your MCU's GPIO and SPI configuration.  
   - Currently configured for **STM32F104 using HAL libraries**.

2. **Touch (XPT2046) Porting**  
   - Modify `XPT2046_port.h` and `XPT2046_port.c` to match your MCU's GPIO and SPI setup.  
   - Ensure proper SPI speed (XPT2046 max 5 MHz, 2.5 MHz recommended for reliable readings).

3. **Touch Calibration**  
   - If your touch panel requires calibration, adjust the constants in `XPT2046_touch.c`:
     ```c
     const float b0x = 0.1782f;
     const float b1x = -20.4f;
     const float b0y = -0.26f;
     const float b1y = 512.8f;
     ```
   - Adjust `#define Z_THRESHOLD 10000` in `XPT2046_touch.c` for valid touch detection.

---

## Important Notes

- **SPI Speed:**  
  - ST7796 LCD can run up to **20 MHz** SPI.  
  - XPT2046 touch controller can run up to **5 MHz**, but **2.5 MHz is recommended** for stability.

- **Port Header Files:**  
  - `ST7796S_port.h` → display-specific MCU pins and SPI.  
  - `XPT2046_port.h` and `XPT2046_port.c` → touch-specific MCU pins and SPI.  

- By modifying only these port files, the library can be **adapted to almost any MCU platform**.

---

## Examples

The library includes example functions demonstrating common usage:

```c
void DrawTestPage(char *str);
void Test_Color(void);
void Test_FillRec(void);
void Test_Circle(void);
void Test_Triangle(void);
void English_Font_test(void);
void Pic_test(void);
void Load_Drow_Dialog(void);
void Touch_Test(void);
void main_test(void);
void Rotate_Test(void);
