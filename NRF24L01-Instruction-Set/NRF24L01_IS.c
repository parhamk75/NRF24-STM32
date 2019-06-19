#include "NRF24L01_IS.h"


HAL_StatusTypeDef NRF_INS_Read_Reg(NRF24L01_t* nrf, uint8_t adr, uint8_t d_len, uint8_t* pdata, uint8_t* STAT_Reg){

	if( adr >= 32 )
		return HAL_ERROR;
	
	HAL_SPI_TransmitReceive( nrf->hspi, &adr, STAT_Reg, 1, HAL_MAX_DELAY);
	HAL_SPI_Receive( nrf->hspi, pdata, d_len, HAL_MAX_DELAY);
	
	return HAL_OK;
}


