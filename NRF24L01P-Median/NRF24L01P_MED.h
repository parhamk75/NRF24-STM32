#ifndef __NRF24L01P_MED_H
#define __NRF24L01P_MED_H

#include "NRF24L01P_EX.h"

/* CONFIG <= BEGIN => */
typedef enum 
{
  NRF_RX_DR_IRQ_ENABLE      			= 0x00U,
  NRF_RX_DR_IRQ_DISABLE						= 0x01U
	
} NRF24L01P_MED_RX_DR_IRQ_MaskTypeDef;

typedef enum 
{
  NRF_TX_DS_IRQ_ENABLE      			= 0x00U,
  NRF_TX_DS_IRQ_DISABLE						= 0x01U
	
} NRF24L01P_MED_TX_DS_IRQ_MaskTypeDef;

typedef enum 
{
  NRF_MAX_RT_IRQ_ENABLE      			= 0x00U,
  NRF_MAX_RT_IRQ_DISABLE					= 0x01U
	
} NRF24L01P_MED_MAX_RT_IRQ_MaskTypeDef;

typedef enum 
{
  NRF_CRC_DISABLE      						= 0x00U,
  NRF_CRC_ENABLE									= 0x01U
	
} NRF24L01P_MED_EN_CRCTypeDef;

typedef enum 
{
  NRF_CRC_1_BYTE      						= 0x00U,
  NRF_CRC_2_BYTES									= 0x01U
	
} NRF24L01P_MED_CRC_EncodingSchemeTypeDef;

typedef enum 
{
  NRF_POWER_DOWN									= 0x00U,
  NRF_POWER_UP										= 0x01U
	
} NRF24L01P_MED_PowerUpTypeDef;

typedef enum 
{
  NRF_PRIMARY_MODE_TX      				= 0x00U,
  NRF_PRIMARY_MODE_RX    					= 0x01U
	
} NRF24L01P_MED_PrimaryModeTypeDef;

/* CONFIG <= END => */



typedef enum {
    NRF_DATA_RATE_250KBPS 				= 1U,
    NRF_DATA_RATE_1MBPS   				= 0U,
    NRF_DATA_RATE_2MBPS   				= 2U
	
} NRF24L01P_MED_DataRateTypeDef;

typedef enum {
    NRF_TX_PWR_M18dBm 						= 0U,
    NRF_TX_PWR_M12dBm 						= 1U,
    NRF_TX_PWR_M6dBm  						= 2U,
    NRF_TX_PWR_0dBm   						= 3U
	
} NRF24L01P_MED_TxPowerTypeDef;



typedef struct{
	NRF24L01P_MED_PrimaryModeTypeDef	P_Mode;
	NRF24L01P_MED_DataRateTypeDef  		Data_Rate;
  NRF24L01P_MED_TxPowerTypeDef     	TX_Power;	
                                  
} NRF24L01P_MED_InitTypeDef;


HAL_StatusTypeDef	NRF_MED_Set_PrimaryMode(		NRF24L01P_ExTypeDef* 											nrf,
																							NRF24L01P_MED_PrimaryModeTypeDef					pmode,
																							uint8_t*																	STAT_Reg );

HAL_StatusTypeDef	NRF_MED_Set_PowerUp(				NRF24L01P_ExTypeDef* 											nrf,
																							NRF24L01P_MED_PowerUpTypeDef							pwr,
																							uint8_t*																	STAT_Reg );


#endif //#ifndef __NRF24L01P_MED_H
