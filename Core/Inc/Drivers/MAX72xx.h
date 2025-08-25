#ifndef MAX7219XX_H
#define MAX7219XX_H

#include "stm32f4xx_hal.h"

// Register Address Map
#define NO_OP 			(0x00)
#define DIGIT_0 		(0x01)
#define DIGIT_1 		(0x02)
#define DIGIT_2 		(0x03)
#define DIGIT_3 		(0x04)
#define DIGIT_4 		(0x05)
#define DIGIT_5 		(0x06)
#define DIGIT_6 		(0x07)
#define DIGIT_7 		(0x08)
#define DECODE_MODE 	(0x09)
#define INTENSITY 		(0x0A)
#define SCAN_LIMIT 		(0x0B)
#define SHUTDOWN 		(0x0C)
#define DISPLAY_TEST 	(0x0F)

// Shutdown Register Format
#define SHUTDOWN_MODE 		(0x00)
#define NORMAL_OPERATION 	(0x01)

void MAX72xx_Init(SPI_HandleTypeDef *phspi);
void MAX72xx_Write(SPI_HandleTypeDef *phspi, uint8_t msb, uint8_t lsb);
void MAX72xx_Clear(SPI_HandleTypeDef *phspi);
void MAX72xx_Write_Pixel(SPI_HandleTypeDef *phspi, uint8_t x, uint8_t y);
void MAX72xx_WriteChar(SPI_HandleTypeDef *phspi);

#endif // MAX7219xx_H
