#ifndef __NRF24L01_EX_H
#define __NRF24L01_EX_H

#include "main.h"
#include "stm32f4xx_hal.h"


typedef enum 
{
  TX_PRIMARY_MODE      				= 0x00U,
  RX_PRIMARY_MODE    					= 0x01U
	
} NRF_PrimaryModeTypeDef;

typedef enum {
    NRF_DATA_RATE_250KBPS 		= 1U,
    NRF_DATA_RATE_1MBPS   		= 0U,
    NRF_DATA_RATE_2MBPS   		= 2U
	
} NRF_DATA_RATE;

typedef enum {
    NRF_TX_PWR_M18dBm 				= 0U,
    NRF_TX_PWR_M12dBm 				= 1U,
    NRF_TX_PWR_M6dBm  				= 2U,
    NRF_TX_PWR_0dBm   				= 3U
	
} NRF_TX_PWR;

typedef struct{
	NRF_DATA_RATE  							Data_Rate;
  NRF_TX_PWR     							TX_Power;
	NRF_PrimaryModeTypeDef			P_Mode;
	
} NRF24L01_InitTypeDef;

typedef struct{
	NRF24L01_InitTypeDef				init;	
	SPI_HandleTypeDef*  				hspi;
	
}	NRF24L01_TypeDef;


/* Commands */
typedef enum {
   NRF_CMD_R_REGISTER         = 0x00U,
   NRF_CMD_W_REGISTER         = 0x20U,
   NRF_CMD_R_RX_PAYLOAD       = 0x61U,
   NRF_CMD_W_TX_PAYLOAD       = 0xA0U,
   NRF_CMD_FLUSH_TX           = 0xE1U,
   NRF_CMD_FLUSH_RX           = 0xE2U,
   NRF_CMD_REUSE_TX_PL        = 0xE3U,
   NRF_CMD_R_RX_PL_WID        = 0x60U,
   NRF_CMD_W_ACK_PAYLOAD      = 0xA8U,
   NRF_CMD_W_TX_PAYLOAD_NOACK = 0xB0U,
   NRF_CMD_NOP                = 0xFFU
	
} NRF_CommandTypeDef;

/* Registers */
typedef enum {
    NRF_CONFIG      					= 0x00U,
    NRF_EN_AA       					= 0x01U,
    NRF_EN_RXADDR   					= 0x02U,
    NRF_SETUP_AW    					= 0x03U,
    NRF_SETUP_RETR  					= 0x04U,
    NRF_RF_CH       					= 0x05U,
    NRF_RF_SETUP    					= 0x06U,
    NRF_STATUS      					= 0x07U,
    NRF_OBSERVE_TX  					= 0x08U,
    NRF_CD          					= 0x09U,
    NRF_RX_ADDR_P0  					= 0x0AU,
    NRF_RX_ADDR_P1  					= 0x0BU,
    NRF_RX_ADDR_P2  					= 0x0CU,
    NRF_RX_ADDR_P3  					= 0x0DU,
    NRF_RX_ADDR_P4  					= 0x0EU,
    NRF_RX_ADDR_P5  					= 0x0FU,
    NRF_TX_ADDR     					= 0x10U,
    NRF_RX_PW_P0    					= 0x11U,
    NRF_RX_PW_P1    					= 0x12U,
    NRF_RX_PW_P2    					= 0x13U,
    NRF_RX_PW_P3    					= 0x14U,
    NRF_RX_PW_P4    					= 0x15U,
    NRF_RX_PW_P5    					= 0x16U,
    NRF_FIFO_STATUS 					= 0x17U,
    NRF_DYNPD       					= 0x1CU,
    NRF_FEATURE     					= 0x1DU
		
} NRF_RegisterTypeDef;



HAL_StatusTypeDef NRF_EX_Read_Reg(			 	 		 NRF24L01_TypeDef* 	nrf,
																				       uint8_t 						adr, 
																				       uint8_t 						d_len, 
																				       uint8_t* 					pdata, 
																				       uint8_t* 					P_STAT_Reg );

HAL_StatusTypeDef NRF_EX_Write_Reg(		    		 NRF24L01_TypeDef* 	nrf,
																				       uint8_t 						adr, 
																				       uint8_t 						d_len, 
																				       uint8_t* 					pdata, 
																				       uint8_t* 					P_STAT_Reg );

HAL_StatusTypeDef NRF_EX_Read_Rx_PL(		       NRF24L01_TypeDef* 	nrf, 
																				       uint8_t 						d_len, 
																				       uint8_t*						pdata, 
																				       uint8_t*						STAT_Reg );

HAL_StatusTypeDef NRF_EX_Write_Tx_PL(	       	 NRF24L01_TypeDef* 	nrf, 
																				       uint8_t 						d_len, 
																				       uint8_t* 					pdata, 
																				       uint8_t* 					STAT_Reg );

HAL_StatusTypeDef NRF_EX_Flush_Tx(			       NRF24L01_TypeDef* 	nrf,
																				       uint8_t* 					STAT_Reg );

HAL_StatusTypeDef NRF_EX_Flush_Rx(			       NRF24L01_TypeDef* 	nrf,
																				       uint8_t* 					STAT_Reg );

HAL_StatusTypeDef NRF_EX_Reuse_TxPL(		       NRF24L01_TypeDef* 	nrf,
																				       uint8_t* 					STAT_Reg );

																					 
HAL_StatusTypeDef NRF_EX_R_RX_PL_WID(          NRF24L01_TypeDef* 	nrf,	                                             
																				       uint8_t* 					pdata, 
                                               uint8_t* 					STAT_Reg );
																					 
HAL_StatusTypeDef NRF_EX_W_ACK_PAYLOAD(        NRF24L01_TypeDef* 	nrf,
	                                             uint8_t 						d_len, 
																				       uint8_t* 					pdata, 
                                               uint8_t 						pipe_n,
                                               uint8_t* 					STAT_Reg );
																							 
HAL_StatusTypeDef NRF_EX_W_TX_PAYLOAD_NO_ACK(  NRF24L01_TypeDef* 	nrf, 
																				       uint8_t 						d_len, 
																				       uint8_t* 					pdata, 
																				       uint8_t* 					STAT_Reg );
																							 
HAL_StatusTypeDef NRF_EX_NOP(					         NRF24L01_TypeDef* 	nrf,
																				       uint8_t* 					STAT_Reg );																							 

#endif //#ifndef __NRF24L01_EX_H
