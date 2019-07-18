#ifndef __NRF24L01P_EX_H
#define __NRF24L01P_EX_H

#include "main.h"
#include "stm32f4xx_hal.h"

/* NRF24L01P Existance TypeDef Struct */
typedef struct{	
	SPI_HandleTypeDef*  						hspi;
	GPIO_TypeDef*										spi_cs_port;
	uint16_t												spi_cs_pin;
	
}	NRF24L01P_ExTypeDef;


/* NRF24L01P Instructions */
typedef enum {
   NRF_INS_R_REGISTER         		= 0x00U,
   NRF_INS_W_REGISTER         		= 0x20U,
   NRF_INS_R_RX_PAYLOAD       		= 0x61U,
   NRF_INS_W_TX_PAYLOAD       		= 0xA0U,
   NRF_INS_FLUSH_TX           		= 0xE1U,
   NRF_INS_FLUSH_RX           		= 0xE2U,
   NRF_INS_REUSE_TX_PL        		= 0xE3U,
   NRF_INS_R_RX_PL_WID        		= 0x60U,
   NRF_INS_W_ACK_PAYLOAD      		= 0xA8U,
   NRF_INS_W_TX_PAYLOAD_NOACK 		= 0xB0U,
   NRF_INS_NOP                		= 0xFFU
	
} NRF24L01P_ExInstructionTypeDef;

/* NRF24L01P Register Addresses*/
typedef enum {
    NRF_REG_CONFIG      					= 0x00U,
    NRF_REG_EN_AA       					= 0x01U,
    NRF_REG_EN_RXADDR   					= 0x02U,
    NRF_REG_SETUP_AW    					= 0x03U,
    NRF_REG_SETUP_RETR  					= 0x04U,
    NRF_REG_RF_CH       					= 0x05U,
    NRF_REG_RF_SETUP    					= 0x06U,
    NRF_REG_STATUS      					= 0x07U,
    NRF_REG_OBSERVE_TX  					= 0x08U,
    NRF_REG_CD          					= 0x09U,
    NRF_REG_RX_ADDR_P0  					= 0x0AU,
    NRF_REG_RX_ADDR_P1  					= 0x0BU,
    NRF_REG_RX_ADDR_P2  					= 0x0CU,
    NRF_REG_RX_ADDR_P3  					= 0x0DU,
    NRF_REG_RX_ADDR_P4  					= 0x0EU,
    NRF_REG_RX_ADDR_P5  					= 0x0FU,
    NRF_REG_TX_ADDR     					= 0x10U,
    NRF_REG_RX_PW_P0    					= 0x11U,
    NRF_REG_RX_PW_P1    					= 0x12U,
    NRF_REG_RX_PW_P2    					= 0x13U,
    NRF_REG_RX_PW_P3    					= 0x14U,
    NRF_REG_RX_PW_P4    					= 0x15U,
    NRF_REG_RX_PW_P5    					= 0x16U,
    NRF_REG_FIFO_STATUS 					= 0x17U,
    NRF_REG_DYNPD       					= 0x1CU,
    NRF_REG_FEATURE     					= 0x1DU
		
} NRF24L01P_ExRegisterTypeDef;



HAL_StatusTypeDef NRF_EX_Read_Reg(			 	 		 NRF24L01P_ExTypeDef* 	nrf,
																				       uint8_t 								adr, 
																				       uint8_t 								d_len, 
																				       uint8_t* 							pdata, 
																				       uint8_t* 							P_STAT_Reg );
		
HAL_StatusTypeDef NRF_EX_Write_Reg(		    		 NRF24L01P_ExTypeDef* 	nrf,
																				       uint8_t 								adr, 
																				       uint8_t 								d_len, 
																				       uint8_t* 							pdata, 
																				       uint8_t* 							P_STAT_Reg );
		
HAL_StatusTypeDef NRF_EX_Read_Rx_PL(		       NRF24L01P_ExTypeDef* 	nrf, 
																				       uint8_t 								d_len, 
																				       uint8_t*								pdata, 
																				       uint8_t*								STAT_Reg );
		
HAL_StatusTypeDef NRF_EX_Write_Tx_PL(	       	 NRF24L01P_ExTypeDef* 	nrf, 
																				       uint8_t 								d_len, 
																				       uint8_t* 							pdata, 
																				       uint8_t* 							STAT_Reg );
		
HAL_StatusTypeDef NRF_EX_Flush_Tx(			       NRF24L01P_ExTypeDef* 	nrf,
																				       uint8_t* 							STAT_Reg );
		
HAL_StatusTypeDef NRF_EX_Flush_Rx(			       NRF24L01P_ExTypeDef* 	nrf,
																				       uint8_t* 							STAT_Reg );
		
HAL_StatusTypeDef NRF_EX_Reuse_TxPL(		       NRF24L01P_ExTypeDef* 	nrf,
																				       uint8_t* 							STAT_Reg );
		
																							
HAL_StatusTypeDef NRF_EX_R_RX_PL_WID(          NRF24L01P_ExTypeDef* 	nrf,	                                             
																				       uint8_t* 							pdata, 
                                               uint8_t* 							STAT_Reg );
																							
HAL_StatusTypeDef NRF_EX_W_ACK_PAYLOAD(        NRF24L01P_ExTypeDef* 	nrf,
	                                             uint8_t 								d_len, 
																				       uint8_t* 							pdata, 
                                               uint8_t 								pipe_n,
                                               uint8_t* 							STAT_Reg );
																									
HAL_StatusTypeDef NRF_EX_W_TX_PAYLOAD_NO_ACK(  NRF24L01P_ExTypeDef* 	nrf, 
																				       uint8_t 								d_len, 
																				       uint8_t* 							pdata, 
																				       uint8_t* 							STAT_Reg );
																									
HAL_StatusTypeDef NRF_EX_NOP(					         NRF24L01P_ExTypeDef* 	nrf,
																				       uint8_t* 							STAT_Reg );																							 

#endif //#ifndef __NRF24L01P_EX_H
