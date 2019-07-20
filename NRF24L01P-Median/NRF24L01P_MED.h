#ifndef __NRF24L01P_MED_H
#define __NRF24L01P_MED_H

#include "NRF24L01P_EX.h"

/* CONFIG <= BEGIN => */
typedef enum 
{
  RX_DR_IRQ_ENABLE      			= 0x00U,
  RX_DR_IRQ_DISABLE						= 0x01U
	
} NRF24L01P_MED_RX_DR_IRQ_Mask;

typedef enum 
{
  TX_DS_IRQ_ENABLE      			= 0x00U,
  TX_DS_IRQ_DISABLE						= 0x01U
	
} NRF24L01P_MED_TX_DS_IRQ_Mask;

typedef enum 
{
  MAX_RT_IRQ_ENABLE      			= 0x00U,
  MAX_RT_IRQ_DISABLE					= 0x01U
	
} NRF24L01P_MED_MAX_RT_IRQ_Mask;

typedef enum 
{
  CRC_DISABLE      						= 0x00U,
  CRC_ENABLE									= 0x01U
	
} NRF24L01P_MED_EN_CRC;

typedef enum 
{
  CRC_1_BYTE      						= 0x00U,
  CRC_2_BYTES									= 0x01U
	
} NRF24L01P_MED_CRC_Encoding_Scheme;


/* CONFIG <= END => */
typedef enum 
{
  TX_PRIMARY_MODE      				= 0x00U,
  RX_PRIMARY_MODE    					= 0x01U
	
} NRF24L01P_MED_PrimaryModeTypeDef;


typedef enum {
    NRF_DATA_RATE_250KBPS 		= 1U,
    NRF_DATA_RATE_1MBPS   		= 0U,
    NRF_DATA_RATE_2MBPS   		= 2U
	
} NRF24L01P_MED_DataRateTypeDef;

typedef enum {
    NRF_TX_PWR_M18dBm 				= 0U,
    NRF_TX_PWR_M12dBm 				= 1U,
    NRF_TX_PWR_M6dBm  				= 2U,
    NRF_TX_PWR_0dBm   				= 3U
	
} NRF24L01P_MED_TxPowerTypeDef;



typedef struct{
	NRF24L01P_MED_PrimaryModeTypeDef	P_Mode;
	NRF24L01P_MED_DataRateTypeDef  		Data_Rate;
  NRF24L01P_MED_TxPowerTypeDef     	TX_Power;	
                                  
} NRF24L01P_MED_InitTypeDef;

HAL_StatusTypeDef	NRF_H_PowerUp(			NRF24L01P_ExTypeDef* 			nrf,
																			uint8_t*									STAT_Reg );

HAL_StatusTypeDef	NRF_H_PowerDown(		NRF24L01P_ExTypeDef* 			nrf,
																			uint8_t*									STAT_Reg );





#endif //#ifndef __NRF24L01P_MED_H
