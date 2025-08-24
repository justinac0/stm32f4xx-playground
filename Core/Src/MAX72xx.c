#include <Drivers/MAX72xx.h>

void MAX72xx_Init(SPI_HandleTypeDef *phspi) {
	MAX72xx_Write(phspi, DISPLAY_TEST, NORMAL_OPERATION);
	HAL_Delay(500);
	MAX72xx_Write(phspi, DISPLAY_TEST, SHUTDOWN_MODE);
	HAL_Delay(500);

	MAX72xx_Write(phspi, SHUTDOWN, NORMAL_OPERATION);
	MAX72xx_Write(phspi, INTENSITY, 0x00);
	MAX72xx_Write(phspi, SCAN_LIMIT, 0x0f);
	MAX72xx_Write(phspi, DECODE_MODE, 0x00);

	MAX72xx_Clear(phspi);
}

inline void MAX72xx_Write(SPI_HandleTypeDef *phspi, uint8_t msb, uint8_t lsb) {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
	HAL_SPI_Transmit(phspi, &msb, 1, 10);
	HAL_SPI_Transmit(phspi, &lsb, 1, 10);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
}

inline void MAX72xx_Write_Pixel(SPI_HandleTypeDef *phspi, uint8_t x, uint8_t y) {
	if (x > 8) return;
	if (y > 8) return;

	MAX72xx_Write(phspi, x+1, 1 << y);
}

void MAX72xx_Clear(SPI_HandleTypeDef *phspi) {
	for (uint8_t i = 1; i <= 8; i++) {
		MAX72xx_Write(phspi, i, 0);
	}
}
