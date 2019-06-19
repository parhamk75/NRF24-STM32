#include "main.h"
#include "stm32f4xx_hal.h"

HAL_StatusTypeDef NRF_INS_Read_Reg(SPI_HandleTypeDef* hspi, uint8_t adr, uint8_t d_len, uint8_t* pdata, uint8_t* STAT_Reg );


