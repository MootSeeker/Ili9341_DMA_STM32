/*
 *
 *	Description:
 *	------------
 *
 *		Project name:	Ili9341_DMA
 *		Filename:		ili9341.h
 *		Software:		STM32CubeIDE
 *		Version:		1.0.0
 *
 *      Date: 			Oct 7, 2020	  	 
 *		Author:		 	mootseeker
 *
 *		Comment: 		Build first version.
 *
 *				 	 	 	
 *
 *	MIT License
 *	
 *	
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#ifndef ILI9341_H_
#define ILI9341_H_

#include "main.h"
#include "spi.h"

/* Configuration ------------------------------------------------------ */

// LCD RESOLUTION
#define ILI_SCREEN_WIDTH 	320
#define ILI_SCREEN_HEIGHT 	240

// SCREEN ORIENTATION
#define ILI_ROTATION		SCREEN_HORIZONTAL_1

// SPI HANDLE
#define ILI_SPI_HANDLE		hspi1

// CHIP SELECT PIN AND PORT, STANDARD GPIO
#define ILI_CS_PORT			DISP_CS_GPIO_Port
#define ILI_CS_PIN			DISP_CS_Pin

// DATA COMMAND PIN AND PORT, STANDARD GPIO
#define ILI_DC_PORT			DISP_DC_GPIO_Port
#define ILI_DC_PIN			DISP_DC_Pin

// RESET PIN AND PORT, STANDARD GPIO
#define	ILI_RST_PORT		DISP_RST_GPIO_Port
#define	ILI_RST_PIN			DISP_RST_Pin

// DCACHE (Cortex-M7)
#define ILI_DCACHE_ENABLED

/* -------------------------------------------------------------------- */

/* RGB565 Colors */
#define RGB(R,G,B)  ((uint16_t)((((uint8_t)R >> 3) << 11) | (((uint8_t)G >> 2) << 5) | ((uint8_t)B >> 3)))
#define BLACK       0x0000
#define NAVY        0x000F
#define DARKGREEN   0x03E0
#define DARKCYAN    0x03EF
#define MAROON      0x7800
#define PURPLE      0x780F
#define OLIVE       0x7BE0
#define LIGHTGREY   0xC618
#define DARKGREY    0x7BEF
#define BLUE        0x001F
#define GREEN       0x07E0
#define CYAN        0x07FF
#define RED         0xF800
#define MAGENTA     0xF81F
#define YELLOW      0xFFE0
#define WHITE       0xFFFF
#define ORANGE      0xFD20
#define GREENYELLOW 0xAFE5
#define PINK        0xF81F

/* Screen orientation */
#define SCREEN_VERTICAL_1		0
#define SCREEN_HORIZONTAL_1		1
#define SCREEN_VERTICAL_2		2
#define SCREEN_HORIZONTAL_2		3


/* Configuration functions */
void ILI_Reset(void);
void ILI_Enable(void);
void ILI_Init(void);
HAL_StatusTypeDef ILI_Write_Command(uint8_t Command);
HAL_StatusTypeDef ILI_Write_Data(uint8_t Data);
void ILI_Set_Rotation(uint8_t Rotation);
void ILI_Set_Address(uint16_t X, uint16_t Y, uint16_t W, uint16_t H);

/* DMA functions */
HAL_StatusTypeDef ILI_DMA_Load(uint16_t *Buf);
HAL_StatusTypeDef ILI_DMA_Fill(uint16_t Color);
HAL_StatusTypeDef ILI_DMA_Callback(void);
uint8_t ILI_DMA_Busy(void);

#endif /* ILI9341_H_ */
