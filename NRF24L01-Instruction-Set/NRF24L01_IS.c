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
		if(nrf->mode==0x02U || nrf->mode==0x03U	|| 	nrf->mode==0x04U)
		{
       if( adr >= 32 )
		     return HAL_ERROR;		

	      adr+=32;
	      HAL_SPI_TransmitReceive( nrf->hspi, &adr, STAT_Reg, 1, HAL_MAX_DELAY);
	    //HAL_Delay(1);
	      HAL_SPI_Transmit( nrf->hspi, pdata, d_len, HAL_MAX_DELAY);
    }
																					
	 return HAL_ERROR;												
																			                   	}

