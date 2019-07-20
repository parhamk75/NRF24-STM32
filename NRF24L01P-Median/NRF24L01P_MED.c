#include "NRF24L01P_MED.h"


HAL_StatusTypeDef	NRF_H_PowerUp( NRF24L01P_ExTypeDef* nrf, uint8_t* STAT_REG )
{
	/*
		This Function Powers up the NRF by setting the PWR_UP to '1'
	
		<- ! -> If you don't need to have status register, pass a 'NULL' to STAT_REG input argument
	*/
	
	uint8_t tmp_reg[1];
	
	if( NRF_EX_Read_Reg( nrf, NRF_REG_CONFIG, 1, tmp_reg, STAT_REG) != HAL_OK )
	{
		return HAL_ERROR;
	}
	
	tmp_reg[0] |= 0x02U;
	
	if( NRF_EX_Write_Reg( nrf, NRF_REG_CONFIG, 1, tmp_reg, STAT_REG) != HAL_OK )
	{
		return HAL_ERROR;
	}	
	
	return HAL_OK;
}


HAL_StatusTypeDef	NRF_H_PowerDown( NRF24L01P_ExTypeDef* nrf, uint8_t* STAT_REG )
{
	/*
		This Function Powers down the NRF by setting the PWR_UP to '0'
	
		<- ! -> If you don't need to have status register, pass a 'NULL' to STAT_REG input argument
	*/
	
	uint8_t tmp_reg[1];
	
	if( NRF_EX_Read_Reg( nrf, NRF_REG_CONFIG, 1, tmp_reg, STAT_REG) != HAL_OK )
	{
		return HAL_ERROR;
	}
	
	tmp_reg[0] &= ~(0x02U);
	
	if( NRF_EX_Write_Reg( nrf, NRF_REG_CONFIG, 1, tmp_reg, STAT_REG) != HAL_OK )
	{
		return HAL_ERROR;
	}
	
	return HAL_OK;
}


