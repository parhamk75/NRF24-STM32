#include "NRF24L01P_MED.h"


HAL_StatusTypeDef	NRF_MED_Set_PrimaryMode(		NRF24L01P_ExTypeDef* nrf, NRF24L01P_MED_PrimaryModeTypeDef	pmode, uint8_t* STAT_Reg )
{
	/*
		This Function set the primary mode of the NRF by setting the PRIM_RX
	
		<- ! -> If you don't need to have status register, pass a 'NULL' to STAT_Reg input argument
	*/
	
	uint8_t tmp_reg[1];
	
	if( NRF_EX_Read_Reg( nrf, NRF_REG_CONFIG, 1, tmp_reg, STAT_Reg) != HAL_OK )
	{
		return HAL_ERROR;
	}
	
	switch (pmode)
  {
  	case NRF_PRIMARY_MODE_RX:
		{
			// TODO: You can define (or enumerate) bit_numbers to shift by their names
			tmp_reg[0] |= (0x01U) << 0;
  		break;
		}
  	case NRF_PRIMARY_MODE_TX:
		{
			tmp_reg[0] &= ~(0x01U) << 0;		
  		break;
		}
  	default:
		{
			return HAL_ERROR;
  		break;
		}
  }
	
	if( NRF_EX_Write_Reg( nrf, NRF_REG_CONFIG, 1, tmp_reg, STAT_Reg) != HAL_OK )
	{
		return HAL_ERROR;
	}	
	
	return HAL_OK;
}


HAL_StatusTypeDef	NRF_MED_Set_PowerUp( NRF24L01P_ExTypeDef* nrf, NRF24L01P_MED_PowerUpTypeDef pwr, uint8_t* STAT_Reg )
{
	/*
		This Function Powers up the NRF by setting the PWR_UP
	
		<- ! -> If you don't need to have status register, pass a 'NULL' to STAT_Reg input argument
	*/
	
	uint8_t tmp_reg[1];
	
	if( NRF_EX_Read_Reg( nrf, NRF_REG_CONFIG, 1, tmp_reg, STAT_Reg) != HAL_OK )
	{
		return HAL_ERROR;
	}
	
	switch (pwr)
  {
  	case NRF_POWER_UP:
		{
			// TODO: You can define (or enumerate) bit_numbers to shift by their names
			tmp_reg[0] |= (0x01U) << 1;
  		break;
		}
  	case NRF_POWER_DOWN:
		{
			tmp_reg[0] &= ~(0x01U) << 1;		
  		break;
		}
  	default:
		{
			return HAL_ERROR;
  		break;
		}
  }
	
	if( NRF_EX_Write_Reg( nrf, NRF_REG_CONFIG, 1, tmp_reg, STAT_Reg) != HAL_OK )
	{
		return HAL_ERROR;
	}	
	
	return HAL_OK;
}


