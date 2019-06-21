#include "NRF24L01_IS.h"


HAL_StatusTypeDef NRF_INS_Read_Reg   (         NRF24L01_t* nrf,
                                               uint8_t adr, 
																			         uint8_t d_len,
																			         uint8_t* pdata,
																			         uint8_t* STAT_Reg){

	HAL_SPI_TransmitReceive( nrf->hspi, &adr, STAT_Reg, 1, HAL_MAX_DELAY);
	HAL_SPI_Receive( nrf->hspi, pdata, d_len, HAL_MAX_DELAY);

	return HAL_OK;
                                                           }

HAL_StatusTypeDef NRF_INS_Write_Reg(		       NRF24L01_t* nrf,
																				       uint8_t adr, 
																			     	  uint8_t d_len, 
																				       uint8_t* pdata, 
																				       uint8_t* STAT_Reg){				
	//Executable in power down and standby mode only
	adr+=32;
	HAL_SPI_TransmitReceive( nrf->hspi, &adr, STAT_Reg, 1, HAL_MAX_DELAY);
	HAL_SPI_Transmit( nrf->hspi, pdata, d_len, HAL_MAX_DELAY);
																					 
 	return HAL_OK;					
																			                   	 }

HAL_StatusTypeDef NRF_INS_Read_Rx_PL(		       NRF24L01_t* nrf, 
																				       uint8_t d_len, 
																				       uint8_t* pdata, 
																				       uint8_t* STAT_Reg ){
	
  //Used in RX mode																					 
	uint8_t Read_Rx_PL = 0x61;
	HAL_SPI_TransmitReceive( nrf->hspi, &Read_Rx_PL, STAT_Reg, 1, HAL_MAX_DELAY);
	HAL_SPI_Receive( nrf->hspi, pdata, d_len, HAL_MAX_DELAY);	
	
  return HAL_OK;																					 
																	                         }
	
HAL_StatusTypeDef NRF_INS_Write_Tx_PL(	       NRF24L01_t* nrf, 
																				       uint8_t d_len, 
																				       uint8_t* pdata, 
																				       uint8_t* STAT_Reg ){
  //Used in TX mode
	uint8_t Write_Tx_PL=0xA0;
	HAL_SPI_TransmitReceive( nrf->hspi, &Write_Tx_PL, STAT_Reg, 1, HAL_MAX_DELAY);
	HAL_SPI_Transmit( nrf->hspi, pdata, d_len, HAL_MAX_DELAY);	
			
	return HAL_OK;
																				                   }	

																													 
HAL_StatusTypeDef NRF_INS_Flush_Tx(			       NRF24L01_t* nrf,
																				       uint8_t* STAT_Reg ){
																					 
	//Used in TX mode
	uint8_t	_Flush_Tx=0xE1;
	HAL_SPI_TransmitReceive( nrf->hspi, &_Flush_Tx, STAT_Reg, 1, HAL_MAX_DELAY);
																					 
	return HAL_OK;
																				                   }
																				
HAL_StatusTypeDef NRF_INS_Flush_Rx(			       NRF24L01_t* nrf,
																				       uint8_t* STAT_Reg ){
																				
	//Used in RX mode																	
	uint8_t	_Flush_Rx=0xE2;
	HAL_SPI_TransmitReceive( nrf->hspi, &_Flush_Rx, STAT_Reg, 1, HAL_MAX_DELAY);	

  return HAL_OK;																					 
									                                         }
																				 
HAL_StatusTypeDef NRF_INS_Reuse_TxPL(		       NRF24L01_t* nrf,
																				       uint8_t* STAT_Reg ){
						
  uint8_t	_Reuse_TxPL= 0xE3;
	HAL_SPI_TransmitReceive( nrf->hspi, &_Reuse_TxPL, STAT_Reg, 1, HAL_MAX_DELAY);																						
																				
	return HAL_OK;																			
																				                   }
																													 
HAL_StatusTypeDef NRF_INS_NOP(					       NRF24L01_t* nrf,
																				       uint8_t* STAT_Reg ){
									
  uint8_t	_NOP= 0xFF;
	HAL_SPI_TransmitReceive( nrf->hspi, &_NOP, STAT_Reg, 1, HAL_MAX_DELAY);																						
		
  return HAL_OK;																						
																				                     }

HAL_StatusTypeDef NRF_INS_W_TX_PAYLOAD_NO_ACK( NRF24L01_t* nrf,
                                               uint8_t* STAT_Reg){
	//Used in TX mode
	//Enables the W_TX_PAYLOAD_NOACK command first
	uint8_t	W_TX_PAYLOAD_NO_ACK= 0xB0 ;
	HAL_SPI_TransmitReceive( nrf->hspi, &W_TX_PAYLOAD_NO_ACK, STAT_Reg, 1, HAL_MAX_DELAY);	

	return HAL_OK;
																					                  }																												
																													
HAL_StatusTypeDef NRF_INS_R_RX_PL_WID(          NRF24L01_t* nrf,
                                                uint8_t* STAT_Reg){
																								 
	uint8_t	_R_RX_PL_WID= 0x60 ;
	HAL_SPI_TransmitReceive( nrf->hspi, &_R_RX_PL_WID, STAT_Reg, 1, HAL_MAX_DELAY);	

  return HAL_OK;																								 
																							 
																							                   }
HAL_StatusTypeDef NRF_INS_W_ACK_PAYLOAD(        NRF24L01_t* nrf,
                                                uint8_t pipe_n,
                                                uint8_t* STAT_Reg){
	//Used in Rx mode																						 
  uint8_t _W_ACK_PAYLOAD=0xA8+ pipe_n;																		 
	HAL_SPI_TransmitReceive( nrf->hspi, &_W_ACK_PAYLOAD, STAT_Reg, 1, HAL_MAX_DELAY);	

	return HAL_OK;	 
																							 }																							 

																						 
																						 
																					                  
																					 
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													