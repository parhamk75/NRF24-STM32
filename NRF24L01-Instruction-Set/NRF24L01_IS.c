#include "NRF24L01_IS.h"


HAL_StatusTypeDef NRF_INS_Read_Reg   (   NRF24L01_t* nrf,
                                         uint8_t adr, 
																			   uint8_t d_len,
																			   uint8_t* pdata,
																			   uint8_t* STAT_Reg){

	if( adr >= 32 )
		return HAL_ERROR;
	
	HAL_SPI_TransmitReceive( nrf->hspi, &adr, STAT_Reg, 1, HAL_MAX_DELAY);
//HAL_Delay(1);
	HAL_SPI_Receive( nrf->hspi, pdata, d_len, HAL_MAX_DELAY);
	
	
	return HAL_OK;
}

HAL_StatusTypeDef NRF_INS_Write_Reg(		 NRF24L01_t* nrf,
																				 uint8_t adr, 
																				 uint8_t d_len, 
																				 uint8_t* pdata, 
																				 uint8_t* STAT_Reg ){				
	 // Executable in power down and standby mode only
		if(nrf->mode==STANDBY_I_MODE || nrf->mode==STANDBY_II_MODE || 	nrf->mode==POWER_DOWN_MODE)
		{
       if( adr >= 32 )
		     return HAL_ERROR;		

	      adr+=32;
	      HAL_SPI_TransmitReceive( nrf->hspi, &adr, STAT_Reg, 1, HAL_MAX_DELAY);
	    //HAL_Delay(1);
	      HAL_SPI_Transmit( nrf->hspi, pdata, d_len, HAL_MAX_DELAY);
    }
		
   else		
	    return HAL_ERROR;												
																			                   	}

HAL_StatusTypeDef NRF_INS_Read_Rx_PL(		 NRF24L01_t* nrf, 
																				 uint8_t d_len, 
																				 uint8_t* pdata, 
																				 uint8_t* STAT_Reg ){
			//Used in RX mode
      if(nrf->mode != RX_MODE)
				return HAL_ERROR;		
																		
			uint8_t Read_Rx_PL=97;
				 HAL_SPI_TransmitReceive( nrf->hspi, &Read_Rx_PL, STAT_Reg, 1, HAL_MAX_DELAY);
			 //HAL_Delay(1);
	       HAL_SPI_Receive( nrf->hspi, pdata, d_len, HAL_MAX_DELAY);	
			
																	                         }
	
HAL_StatusTypeDef NRF_INS_Write_Tx_PL(	 NRF24L01_t* nrf, 
																				 uint8_t d_len, 
																				 uint8_t* pdata, 
																				 uint8_t* STAT_Reg ){
			//Used in TX mode
      if(nrf->mode != TX_MODE)
				return HAL_ERROR;	

			uint8_t Write_Tx_PL=160;
				 HAL_SPI_TransmitReceive( nrf->hspi, &Write_Tx_PL, STAT_Reg, 1, HAL_MAX_DELAY);
			 //HAL_Delay(1);
	       HAL_SPI_Transmit( nrf->hspi, pdata, d_len, HAL_MAX_DELAY);	
			
																				                   }	

																													 
HAL_StatusTypeDef NRF_INS_Flush_Tx(			 NRF24L01_t* nrf,
																				 uint8_t* STAT_Reg ){
		 //Used in TX mode
      if(nrf->mode != TX_MODE)
				return HAL_ERROR;															
																					
			 uint8_t	_Flush_Tx=225;
			 HAL_SPI_TransmitReceive( nrf->hspi, &_Flush_Tx, STAT_Reg, 1, HAL_MAX_DELAY);
	
																				                   }
																				
HAL_StatusTypeDef NRF_INS_Flush_Rx(			 NRF24L01_t* nrf,
																				 uint8_t* STAT_Reg ){
																				
			 //Used in RX mode
         if(nrf->mode != RX_MODE)
				   return HAL_ERROR;															
																					
			 uint8_t	_Flush_Rx=226;
			 HAL_SPI_TransmitReceive( nrf->hspi, &_Flush_Rx, STAT_Reg, 1, HAL_MAX_DELAY);																	
																				
									                                         }
																				 
HAL_StatusTypeDef NRF_INS_Reuse_TxPL(		  NRF24L01_t* nrf,
																				  uint8_t* STAT_Reg ){
						
       uint8_t	_Reuse_TxPL=227;
			 HAL_SPI_TransmitReceive( nrf->hspi, &_Reuse_TxPL, STAT_Reg, 1, HAL_MAX_DELAY);																									
																				
																				
																				                   }
																													 
HAL_StatusTypeDef NRF_INS_NOP(					  NRF24L01_t* nrf,
																				  uint8_t* STAT_Reg ){
									
       uint8_t	_NOP=255;
			 HAL_SPI_TransmitReceive( nrf->hspi, &_NOP, STAT_Reg, 1, HAL_MAX_DELAY);																							
																				
																				                     }

HAL_StatusTypeDef NRF_IS_W_TX_PAYLOAD_NO_ACK( NRF24L01_t* nrf,
                                          uint8_t* STAT_Reg){
		 /*//Used in TX mode
      if(nrf->mode != TX_MODE)
				return HAL_ERROR;		
			else*/
			
				//Enables the W_TX_PAYLOAD_NOACK command first
				 uint8_t	W_TX_PAYLOAD_NO_ACK= (uint8_t)0x10110000 ;
			 HAL_SPI_TransmitReceive( nrf->hspi, &W_TX_PAYLOAD_NO_ACK, STAT_Reg, 1, HAL_MAX_DELAY);		
				
																					                  }																												
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													