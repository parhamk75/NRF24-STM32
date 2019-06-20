#include "NRF24L01_IS.h"


HAL_StatusTypeDef NRF_INS_Read_Reg   (NRF24L01_t* nrf,
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

HAL_StatusTypeDef NRF_INS_Write_Reg(		NRF24L01_t* nrf,
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

HAL_StatusTypeDef NRF_INS_Read_Rx_PL(		NRF24L01_t* nrf, 
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

																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													
																													