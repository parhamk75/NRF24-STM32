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


HAL_StatusTypeDef NRF_INS_Flush_Tx(			       NRF24L01_t* nrf,
																				       uint8_t* STAT_Reg ){
																					 
	//Used in TX mode
	uint8_t	_Flush_Tx=NRF_CMD_FLUSH_TX;
	HAL_SPI_TransmitReceive( nrf->hspi, &_Flush_Tx, STAT_Reg, 1, HAL_MAX_DELAY);
																					 
	return HAL_OK;
																				                   }
																				
HAL_StatusTypeDef NRF_INS_Flush_Rx(			       NRF24L01_t* nrf,
																				       uint8_t* STAT_Reg ){
																				
	//Used in RX mode																	
	uint8_t	_Flush_Rx=NRF_CMD_FLUSH_RX;
	HAL_SPI_TransmitReceive( nrf->hspi, &_Flush_Rx, STAT_Reg, 1, HAL_MAX_DELAY);	

  return HAL_OK;																					 
									                                         }
																				 
HAL_StatusTypeDef NRF_INS_Reuse_TxPL(		       NRF24L01_t* nrf,
																				       uint8_t* STAT_Reg ){
						
  uint8_t	_Reuse_TxPL= NRF_CMD_REUSE_TX_PL;
	HAL_SPI_TransmitReceive( nrf->hspi, &_Reuse_TxPL, STAT_Reg, 1, HAL_MAX_DELAY);																						
																				
	return HAL_OK;																			
																				                   }
																													 
HAL_StatusTypeDef NRF_INS_NOP(					       NRF24L01_t* nrf,
																				       uint8_t* STAT_Reg ){
									
  uint8_t	_NOP= NRF_CMD_NOP;
	HAL_SPI_TransmitReceive( nrf->hspi, &_NOP, STAT_Reg, 1, HAL_MAX_DELAY);																						
		
  return HAL_OK;																						
																				                     }

HAL_StatusTypeDef NRF_INS_W_TX_PAYLOAD_NO_ACK( NRF24L01_t* nrf,
                                               uint8_t* STAT_Reg){
	//Used in TX mode
	//Enables the W_TX_PAYLOAD_NOACK command first
	uint8_t	W_TX_PAYLOAD_NO_ACK= NRF_CMD_W_TX_PAYLOAD_NOACK ;
	HAL_SPI_TransmitReceive( nrf->hspi, &W_TX_PAYLOAD_NO_ACK, STAT_Reg, 1, HAL_MAX_DELAY);	

	return HAL_OK;
																					                  }																												
																													
HAL_StatusTypeDef NRF_INS_R_RX_PL_WID(          NRF24L01_t* nrf,
																				        uint8_t* pdata, 
                                                uint8_t* STAT_Reg){
																								 
	uint8_t	_R_RX_PL_WID= NRF_CMD_R_RX_PL_WID ;
	HAL_SPI_TransmitReceive( nrf->hspi, &_R_RX_PL_WID, STAT_Reg, 1, HAL_MAX_DELAY);	
  HAL_SPI_Receive( nrf->hspi, pdata, 1, HAL_MAX_DELAY);	
  return HAL_OK;																								 
																							 
																							                   }
HAL_StatusTypeDef NRF_INS_W_ACK_PAYLOAD(       NRF24L01_t* nrf,
	                                             uint8_t d_len, 
																				       uint8_t* pdata, 
                                               uint8_t pipe_n,
                                               uint8_t* STAT_Reg){
	//Used in Rx mode																						 
  uint8_t _W_ACK_PAYLOAD=NRF_CMD_W_ACK_PAYLOAD+ pipe_n;																		 
	HAL_SPI_TransmitReceive( nrf->hspi, &_W_ACK_PAYLOAD, STAT_Reg, 1, HAL_MAX_DELAY);	
  HAL_SPI_Transmit( nrf->hspi, pdata, d_len, HAL_MAX_DELAY);	
	return HAL_OK;	 
}																							 