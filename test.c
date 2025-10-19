
#include "test.h"
#include "ST7796S_gui.h"
#include "XPT2046_touch.h"
#include "pic.h"
#include "ST7796S_lcd.h"

// It is used in Touch_test() module for sprintf()
#include <stdio.h>

// Set SPI speed to a specific prescaler
void SPI_SetPrescaler(uint32_t prescaler)
{
    __HAL_SPI_DISABLE(&hspi2);  // Disable SPI before changing settings

    // Clear old prescaler bits
    hspi2.Instance->CR1 &= ~SPI_CR1_BR;

    // Set new prescaler
    hspi2.Instance->CR1 |= prescaler;

    __HAL_SPI_ENABLE(&hspi2);   // Re-enable SPI
}

//========================variable==========================//
uint16_t ColorTab[5]={RED,GREEN,BLUE,YELLOW,BRED};
//=====================end of variable======================//

/*****************************************************************************
 * @name       :void DrawTestPage(uint8_t *str)
 * @date       :10-19-2025
 * @function   :Drawing test interface
 * @parameters :str:the start address of the Chinese and English strings
 * @retvalue   :None
******************************************************************************/ 
void DrawTestPage(char *str)
{

LCD_Clear(WHITE);
LCD_Fill(0,0,lcddev.width,20,BLUE);

LCD_Fill(0,lcddev.height-20,lcddev.width,lcddev.height,BLUE);
POINT_COLOR=WHITE;
Gui_StrCenter(0,2,WHITE,BLUE,str,16,1);
Gui_StrCenter(0,lcddev.height-18,WHITE,BLUE,"http://www.lcdwiki.com",16,1);

//LCD_Fill(0,20,lcddev.width,lcddev.height-20,WHITE);
}

/*****************************************************************************
 * @name       :void main_test(void)
 * @date       :10-19-2025
 * @function   :Drawing the main Interface of the Comprehensive Test Program
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void main_test(void)
{
	DrawTestPage("main test");
	Gui_StrCenter(0,30,RED,BLUE,"string 1",16,1);
	Gui_StrCenter(0,60,RED,BLUE,"string 2",16,1);
	Gui_StrCenter(0,90,GREEN,BLUE,"string 3",16,1);
	Gui_StrCenter(0,120,BLUE,BLUE,"string 4",16,1);
	HAL_Delay(1500);
	HAL_Delay(1500);
}

/*****************************************************************************
 * @name       :void Test_Color(void)
 * @date       :10-19-2025
 * @function   :Color fill test(white,black,red,green,blue)
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void Test_Color(void)
{
	//DrawTestPage
	LCD_Fill(0,0,lcddev.width,lcddev.height,WHITE);
	Show_Str(20,30,BLUE,YELLOW,"BL Test",16,1);HAL_Delay(800);
	LCD_Fill(0,0,lcddev.width,lcddev.height,RED);
	Show_Str(20,30,BLUE,YELLOW,"RED ",16,1);HAL_Delay(800);
	LCD_Fill(0,0,lcddev.width,lcddev.height,GREEN);
	Show_Str(20,30,BLUE,YELLOW,"GREEN ",16,1);HAL_Delay(800);
	LCD_Fill(0,0,lcddev.width,lcddev.height,BLUE);
	Show_Str(20,30,RED,YELLOW,"BLUE ",16,1);HAL_Delay(800);
}

/*****************************************************************************
 * @name       :void Test_FillRec(void)
 * @date       :10-19-2025
 * @function   :Rectangular display and fill test
								Display red,green,blue,yellow,pink rectangular boxes in turn,
								1500 milliseconds later,
								Fill the rectangle in red,green,blue,yellow and pink in turn
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void Test_FillRec(void)
{
	uint8_t i=0;
	DrawTestPage("test fill rectangle");
	LCD_Fill(0,20,lcddev.width,lcddev.height-20,WHITE);
	for (i=0; i<5; i++) 
	{
		POINT_COLOR=ColorTab[i];
		LCD_DrawRectangle(lcddev.width/2-80+(i*15),lcddev.height/2-80+(i*15),lcddev.width/2-80+(i*15)+60,lcddev.height/2-80+(i*15)+60); 
	}
	HAL_Delay(1500);
	LCD_Fill(0,20,lcddev.width,lcddev.height-20,WHITE); 
	for (i=0; i<5; i++) 
	{
		POINT_COLOR=ColorTab[i];
		LCD_DrawFillRectangle(lcddev.width/2-80+(i*15),lcddev.height/2-80+(i*15),lcddev.width/2-80+(i*15)+60,lcddev.height/2-80+(i*15)+60); 
	}
	HAL_Delay(1500);
}

/*****************************************************************************
 * @name       :void Test_Circle(void)
 * @date       :10-19-2025
 * @function   :circular display and fill test
								Display red,green,blue,yellow,pink circular boxes in turn,
								1500 milliseconds later,
								Fill the circular in red,green,blue,yellow and pink in turn
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void Test_Circle(void)
{
	uint8_t i=0;
	DrawTestPage("test circle");
	LCD_Fill(0,20,lcddev.width,lcddev.height-20,WHITE);
	for (i=0; i<5; i++)  
		gui_circle(lcddev.width/2-80+(i*25),lcddev.height/2-50+(i*25),ColorTab[i],30,0);
	HAL_Delay(1500);
	LCD_Fill(0,20,lcddev.width,lcddev.height-20,WHITE); 
	for (i=0; i<5; i++) 
	  	gui_circle(lcddev.width/2-80+(i*25),lcddev.height/2-50+(i*25),ColorTab[i],30,1);
	HAL_Delay(1500);
}

/*****************************************************************************
 * @name       :void English_Font_test(void)
 * @date       :10-19-2025
 * @function   :English display test
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void English_Font_test(void)
{
	DrawTestPage("english font test");
	Show_Str(10,30,BLUE,YELLOW,"6X12:abcdefghijklmnopqrstuvwxyz0123456789",12,0);
	Show_Str(10,45,BLUE,YELLOW,"6X12:ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789",12,1);
	Show_Str(10,60,BLUE,YELLOW,"6X12:~!@#$%^&*()_+{}:<>?/|-+.",12,0);
	Show_Str(10,80,BLUE,YELLOW,"8X16:abcdefghijklmnopqrstuvwxyz0123456789",16,0);
	Show_Str(10,100,BLUE,YELLOW,"8X16:ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789",16,1);
	Show_Str(10,120,BLUE,YELLOW,"8X16:~!@#$%^&*()_+{}:<>?/|-+.",16,0); 
	HAL_Delay(1200);
}

/*****************************************************************************
 * @name       :void Test_Triangle(void)
 * @date       :10-19-2025
 * @function   :triangle display and fill test
								Display red,green,blue,yellow,pink triangle boxes in turn,
								1500 milliseconds later,
								Fill the triangle in red,green,blue,yellow and pink in turn
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void Test_Triangle(void)
{
	uint8_t i=0;
	DrawTestPage("test triangle");
	LCD_Fill(0,20,lcddev.width,lcddev.height-20,WHITE);
	for(i=0;i<5;i++)
	{
		POINT_COLOR=ColorTab[i];
		Draw_Triangel(lcddev.width/2-80+(i*20),lcddev.height/2-20+(i*15),lcddev.width/2-50-1+(i*20),lcddev.height/2-20-52-1+(i*15),lcddev.width/2-20-1+(i*20),lcddev.height/2-20+(i*15));
	}
	HAL_Delay(1500);
	LCD_Fill(0,20,lcddev.width,lcddev.height-20,WHITE); 
	for(i=0;i<5;i++)
	{
		POINT_COLOR=ColorTab[i];
		Fill_Triangel(lcddev.width/2-80+(i*20),lcddev.height/2-20+(i*15),lcddev.width/2-50-1+(i*20),lcddev.height/2-20-52-1+(i*15),lcddev.width/2-20-1+(i*20),lcddev.height/2-20+(i*15));
	}
	HAL_Delay(1500);
}



/*****************************************************************************
 * @name       :void Pic_test(void)
 * @date       :10-19-2025
 * @function   :picture display test
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void Pic_test(void)
{
	DrawTestPage("picture test");
	//LCD_Fill(0,20,lcddev.width,lcddev.height-20,WHITE);
	Gui_Drawbmp16(30,30,gImage_qq);
	Show_Str(30+12,75,BLUE,YELLOW,"QQ",16,1);
	Gui_Drawbmp16(90,30,gImage_qq);
	Show_Str(90+12,75,BLUE,YELLOW,"QQ",16,1);
	Gui_Drawbmp16(150,30,gImage_qq);
	Show_Str(150+12,75,BLUE,YELLOW,"QQ",16,1);
	HAL_Delay(1200);
}

/*****************************************************************************
 * @name       :void Rotate_Test(void)
 * @date       :10-19-2025
 * @function   :rotate test
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void Rotate_Test(void)
{
	uint8_t i=0;
	char *Direction[4]={"Rotation:0","Rotation:90","Rotation:180","Rotation:270"};
	
	for(i=0;i<4;i++)
	{
	LCD_direction(i);
	DrawTestPage("rotate test");
	Show_Str(20,30,BLUE,YELLOW,Direction[i],16,1);
	Gui_Drawbmp16(30,50,gImage_qq);
	HAL_Delay(1000);
	HAL_Delay(1000);
	}
	LCD_direction(USE_HORIZONTAL);
}

/*****************************************************************************
 * @name       :void Touch_Test(void)
 * @date       :10-19-2025
 * @function   :touch test
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void Touch_Test(void)
{
	uint8_t radius = 3;

	gui_circle(80,120,RED,radius,1);
	gui_circle(160,120,RED,radius,1);
	gui_circle(240,120,RED,radius,1);

	gui_circle(80,240,RED,radius,1);
	gui_circle(160,240,RED,radius,1);
	gui_circle(240,240,RED,radius,1);

	gui_circle(80,360,RED,radius,1);
	gui_circle(160,360,RED,radius,1);
	gui_circle(240,360,RED,radius,1);

	char str[32];
	//DrawTestPage("Touch test");
	uint16_t x_t, y_t;
	while(1){
		if(XPT2046_Touch()){
			SPI_SetPrescaler(SPI_BAUDRATEPRESCALER_16);
			XPT2046_GetXY(&x_t, &y_t, 0);
			uint16_t z = XPT2046_GetZ();
			SPI_SetPrescaler(SPI_BAUDRATEPRESCALER_2);
			if((z<Z_THRESHOLD)&(z>0)){
				gui_circle(x_t,y_t,MAGENTA,2,1);
				LCD_Fill(0,0,lcddev.width,20,GREEN);
				sprintf(str, "X: %u Y: %u Z: %u", x_t, y_t, z);
				Show_Str(20,2,BLUE,WHITE,str,16,0);
			}
		}
	}
}




