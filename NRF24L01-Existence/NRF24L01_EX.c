#include "NRF24L01_EX.h"


HAL_StatusTypeDef NRF_EX_Read_Reg( NRF24L01_TypeDef* nrf, uint8_t adr, uint8_t d_len, uint8_t* pdata, uint8_t* STAT_Reg)
{
	if( adr > 31 )
	{
		return HAL_ERROR;
	}
	
	if( d_len < 1 || 5 < d_len )
	{
		return HAL_ERROR;
	}
	
	if( STAT_Reg == NULL )
	{
		if( HAL_SPI_Transmit( nrf->hspi, &adr, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}		
	}
	else
	{
		if( HAL_SPI_TransmitReceive( nrf->hspi, &adr, STAT_Reg, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}
	}
	
	if( HAL_SPI_Receive( nrf->hspi, pdata, d_len, HAL_MAX_DELAY) != HAL_OK )
	{
		return HAL_ERROR;
	}

	return HAL_OK;
}
																							 

HAL_StatusTypeDef NRF_EX_Write_Reg( NRF24L01_TypeDef* nrf, uint8_t adr, uint8_t d_len, uint8_t* pdata, uint8_t* STAT_Reg)
{
	if( adr > 31 )
	{
		return HAL_ERROR;
	}
	
	if( d_len < 1 || 5 < d_len )
	{
		return HAL_ERROR;
	}
	
	uint8_t tmp_msg = adr | NRF_CMD_W_REGISTER;
	
	if( STAT_Reg == NULL )
	{	
		if( HAL_SPI_Transmit( nrf->hspi, &tmp_msg, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}		
	}
	else
	{
		if( HAL_SPI_TransmitReceive( nrf->hspi, &tmp_msg, STAT_Reg, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}
	}
	
	if( HAL_SPI_Transmit( nrf->hspi, pdata, d_len, HAL_MAX_DELAY) != HAL_OK )
	{
		return HAL_ERROR;
	}

	return HAL_OK;
}

HAL_StatusTypeDef NRF_EX_Read_Rx_PL( NRF24L01_TypeDef* nrf, uint8_t d_len, uint8_t* pdata, uint8_t* STAT_Reg )
{
	if( d_len < 1 || 32 < d_len )
	{
		return HAL_ERROR;
	}
	
	if( STAT_Reg == NULL )
	{	
		if( HAL_SPI_Transmit( nrf->hspi, (uint8_t*)NRF_CMD_R_RX_PAYLOAD, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}		
	}
	else
	{
		if( HAL_SPI_TransmitReceive( nrf->hspi, (uint8_t*)NRF_CMD_R_RX_PAYLOAD, STAT_Reg, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}
	}
	
	if( HAL_SPI_Receive( nrf->hspi, pdata, d_len, HAL_MAX_DELAY) != HAL_OK )
	{
		return HAL_ERROR;
	}
	

	return HAL_OK;	
}																													 


HAL_StatusTypeDef NRF_EX_Write_Tx_PL( NRF24L01_TypeDef* nrf, uint8_t d_len, uint8_t* pdata, uint8_t* STAT_Reg )
{
	if( d_len < 1 || 32 < d_len )
	{
		return HAL_ERROR;
	}
	
	if( STAT_Reg == NULL )
	{	
		if( HAL_SPI_Transmit( nrf->hspi, (uint8_t*)NRF_CMD_W_TX_PAYLOAD, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}		
	}
	else
	{
		if( HAL_SPI_TransmitReceive( nrf->hspi, (uint8_t*)NRF_CMD_W_TX_PAYLOAD, STAT_Reg, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}
	}
	
	if( HAL_SPI_Transmit( nrf->hspi, pdata, d_len, HAL_MAX_DELAY) != HAL_OK )
	{
		return HAL_ERROR;
	}
	

	return HAL_OK;	
}																													 

HAL_StatusTypeDef NRF_EX_Flush_Tx( NRF24L01_TypeDef* nrf, uint8_t* STAT_Reg )
{
	if( STAT_Reg == NULL )
	{	
		if( HAL_SPI_Transmit( nrf->hspi, (uint8_t*)NRF_CMD_FLUSH_TX, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}		
	}
	else
	{
		if( HAL_SPI_TransmitReceive( nrf->hspi, (uint8_t*)NRF_CMD_FLUSH_TX, STAT_Reg, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}
	}
	
	
	return HAL_OK;
}
	
HAL_StatusTypeDef NRF_EX_Flush_Rx( NRF24L01_TypeDef* nrf, uint8_t* STAT_Reg )
{
	if( STAT_Reg == NULL )
	{	
		if( HAL_SPI_Transmit( nrf->hspi, (uint8_t*)NRF_CMD_FLUSH_RX, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}		
	}
	else
	{
		if( HAL_SPI_TransmitReceive( nrf->hspi, (uint8_t*)NRF_CMD_FLUSH_RX, STAT_Reg, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}
	}
	
	
	return HAL_OK;
}

							 
HAL_StatusTypeDef NRF_EX_Reuse_TxPL( NRF24L01_TypeDef* nrf, uint8_t* STAT_Reg )
{
	if( STAT_Reg == NULL )
	{	
		if( HAL_SPI_Transmit( nrf->hspi, (uint8_t*)NRF_CMD_REUSE_TX_PL, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}		
	}
	else
	{
		if( HAL_SPI_TransmitReceive( nrf->hspi, (uint8_t*)NRF_CMD_REUSE_TX_PL, STAT_Reg, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}
	}
	
	
	return HAL_OK;	
}

HAL_StatusTypeDef NRF_EX_R_RX_PL_WID( NRF24L01_TypeDef* nrf, uint8_t* pdata, uint8_t* STAT_Reg)
{
	if( STAT_Reg == NULL )
	{
		if( HAL_SPI_Transmit( nrf->hspi, (uint8_t*)NRF_CMD_R_RX_PL_WID, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}		
	}
	else
	{
		if( HAL_SPI_TransmitReceive( nrf->hspi, (uint8_t*)NRF_CMD_R_RX_PL_WID, STAT_Reg, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}
	}
	
	if( HAL_SPI_Receive( nrf->hspi, pdata, 1, HAL_MAX_DELAY) != HAL_OK )
	{
		return HAL_ERROR;
	}

	return HAL_OK;
}

HAL_StatusTypeDef NRF_EX_W_ACK_PAYLOAD( NRF24L01_TypeDef* nrf, uint8_t d_len, uint8_t* pdata, uint8_t pipe_n, uint8_t* STAT_Reg)
{
	if( pipe_n > 5 )
	{
		return HAL_ERROR;
	}
	
	if( d_len < 1 || 32 < d_len )
	{
		return HAL_ERROR;
	}
	
	uint8_t tmp_msg = NRF_CMD_W_ACK_PAYLOAD | pipe_n;
	
	if( STAT_Reg == NULL )
	{	
		if( HAL_SPI_Transmit( nrf->hspi, &tmp_msg, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}		
	}
	else
	{
		if( HAL_SPI_TransmitReceive( nrf->hspi, &tmp_msg, STAT_Reg, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}
	}
	
	if( HAL_SPI_Transmit( nrf->hspi, pdata, d_len, HAL_MAX_DELAY) != HAL_OK )
	{
		return HAL_ERROR;
	}

	return HAL_OK;
}

HAL_StatusTypeDef NRF_EX_W_TX_PAYLOAD_NO_ACK( NRF24L01_TypeDef* nrf, uint8_t d_len, uint8_t* pdata, uint8_t* STAT_Reg )
{
	if( d_len < 1 || 32 < d_len )
	{
		return HAL_ERROR;
	}
	
	if( STAT_Reg == NULL )
	{	
		if( HAL_SPI_Transmit( nrf->hspi, (uint8_t*)NRF_CMD_W_TX_PAYLOAD_NOACK, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}		
	}
	else
	{
		if( HAL_SPI_TransmitReceive( nrf->hspi, (uint8_t*)NRF_CMD_W_TX_PAYLOAD_NOACK, STAT_Reg, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}
	}
	
	if( HAL_SPI_Transmit( nrf->hspi, pdata, d_len, HAL_MAX_DELAY) != HAL_OK )
	{
		return HAL_ERROR;
	}
	

	return HAL_OK;	
}

HAL_StatusTypeDef NRF_EX_NOP( NRF24L01_TypeDef* nrf, uint8_t* STAT_Reg )
{
	if( STAT_Reg == NULL )
	{	
		if( HAL_SPI_Transmit( nrf->hspi, (uint8_t*)NRF_CMD_NOP, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}		
	}
	else
	{
		if( HAL_SPI_TransmitReceive( nrf->hspi, (uint8_t*)NRF_CMD_NOP, STAT_Reg, 1, HAL_MAX_DELAY) != HAL_OK )
		{
			return HAL_ERROR;
		}
	}
	
	
	return HAL_OK;	
}

