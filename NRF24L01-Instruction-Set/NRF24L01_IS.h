#include "main.h"
#include "stm32f4xx_hal.h"

typedef enum 
{
  RX_MODE      				= 0x00U,
  TX_MODE    					= 0x01U,
  STANDBY_I_MODE      = 0x02U,
  STANDBY_II_MODE			= 0x03U,
	POWER_DOWN_MODE 		= 0x04U
} NRF_ModeTypeDef;

typedef struct{
	SPI_HandleTypeDef*  hspi;
	NRF_ModeTypeDef 		mode;
	
}NRF24L01_t;



HAL_StatusTypeDef NRF_INS_Read_Reg(			   NRF24L01_t* nrf,
																				   uint8_t adr, 
																				   uint8_t d_len, 
																				   uint8_t* pdata, 
																				   uint8_t* STAT_Reg );

HAL_StatusTypeDef NRF_INS_Write_Reg(		   NRF24L01_t* nrf,
																				   uint8_t adr, 
																				   uint8_t d_len, 
																				   uint8_t* pdata, 
																				   uint8_t* STAT_Reg );

HAL_StatusTypeDef NRF_INS_Read_Rx_PL(		   NRF24L01_t* nrf, 
																				   uint8_t d_len, 
																				   uint8_t* pdata, 
																				   uint8_t* STAT_Reg );

HAL_StatusTypeDef NRF_INS_Write_Tx_PL(	   NRF24L01_t* nrf, 
																				   uint8_t d_len, 
																				   uint8_t* pdata, 
																				   uint8_t* STAT_Reg );

HAL_StatusTypeDef NRF_INS_Flush_Tx(			   NRF24L01_t* nrf,
																				   uint8_t* STAT_Reg );

HAL_StatusTypeDef NRF_INS_Flush_Rx(			   NRF24L01_t* nrf,
																				   uint8_t* STAT_Reg );

HAL_StatusTypeDef NRF_INS_Reuse_TxPL(		   NRF24L01_t* nrf,
																				   uint8_t* STAT_Reg );

HAL_StatusTypeDef NRF_INS_NOP(					   NRF24L01_t* nrf,
																				   uint8_t* STAT_Reg );
																				
HAL_StatusTypeDef NRF_W_TX_PAYLOAD_NO_ACK( NRF24L01_t* nrf,
                                           uint8_t* STAT_Reg);