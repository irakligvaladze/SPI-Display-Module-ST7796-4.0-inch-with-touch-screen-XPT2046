/*==========================================================
   Pseudo-code for MCU using ST7796 + XPT2046 examples
==========================================================*/

#include "examples.h"

int main(void)
{
    // Initialize MCU peripherals

    // Initialize system clock if needed
    SystemClock_Config();

    // Initialize GPIO pins
    GPIO_Init();

    // Initialize SPI interface
    SPI_Init();

    // Initialize LCD
    LCD_Init();

   
    while (1)
    {
        main_test();          // Main interface test
        Test_Color();         // Color fill test
        Test_FillRec();       // Rectangle fill test
        Test_Circle();        // Circle draw/fill test
        Test_Triangle();      // Triangle draw/fill test
        English_Font_test();  // Font display test
        Pic_test();           // Picture display test
        Load_Drow_Dialog();   // Dialog box load/draw test
        Rotate_Test();        // LCD rotation test
        Touch_Test(); 
    }

    return 0; /
}
