#ifndef __NRF24L01P_H_H
#define __NRF24L01P_H_H

#include "NRF24L01P_EX.h"

typedef enum 
{
  TX_PRIMARY_MODE      				= 0x00U,
  RX_PRIMARY_MODE    					= 0x01U
	
} NRF24L01P_H_PrimaryModeTypeDef;


typedef enum {
    NRF_DATA_RATE_250KBPS 		= 1U,
    NRF_DATA_RATE_1MBPS   		= 0U,
    NRF_DATA_RATE_2MBPS   		= 2U
	
} NRF24L01P_H_DataRateTypeDef;

typedef enum {
    NRF_TX_PWR_M18dBm 				= 0U,
    NRF_TX_PWR_M12dBm 				= 1U,
    NRF_TX_PWR_M6dBm  				= 2U,
    NRF_TX_PWR_0dBm   				= 3U
	
} NRF24L01P_H_TxPowerTypeDef;

typedef struct{
	NRF24L01P_H_PrimaryModeTypeDef	P_Mode;
	NRF24L01P_H_DataRateTypeDef  		Data_Rate;
  NRF24L01P_H_TxPowerTypeDef     	TX_Power;	
                                  
} NRF24L01P_H_InitTypeDef;        
                                  
typedef struct{   
	// NRF24L01P Existance TypeDef
	NRF24L01P_ExTypeDef*						instance;
	
	// NRF24L01P Initialization TypeDef
	NRF24L01P_H_InitTypeDef*				init;
                                  
	// CE GPIO                      
	GPIO_TypeDef*										CE_Port;
	uint16_t												CE_Pin;
	
	// IRQ GPIO                      
	GPIO_TypeDef*										IRQ_Port;
	uint16_t												IRQ_Pin;
	
} NRF24L01P_HandlerTypeDef;

/*
typedef enum 
{
  RX_MODE      				= 0x00U,
  TX_MODE    					= 0x01U,
  STANDBY_I_MODE      = 0x02U,
  STANDBY_II_MODE			= 0x03U,
	POWER_DOWN_MODE 		= 0x04U
} NRF_ModeTypeDef;
*/



HAL_StatusTypeDef NRF_H_SetChipEn(    NRF24L01P_HandlerTypeDef* hnrf );

HAL_StatusTypeDef NRF_H_ResetChipEn(  NRF24L01P_HandlerTypeDef* hnrf );

HAL_StatusTypeDef NRF_H_Init(         NRF24L01P_HandlerTypeDef* hnrf );

//HAL_StatusTypeDef NRF_H_ReConfig(			NRF24L01P_HandlerTypeDef* hnrf);

/*
void NRF_H_IRQ_Handler(  NRF24L01_t* nrf);

void NRF_H_TX_DS_Callback(void);

void NRF_H_RX_DR_Callback(void);

void NRF_H_MAX_RT_Callback(void);

void NRF_H_RF_CH(	NRF24L01_t* nrf, uint8_t ch);

void NRF_H_SETUP_RETR_Delay(NRF24L01_t* nrf, uint8_t delay);

void NRF_H_T2R( NRF24L01_t* nrf );

void NRF_H_R2T( NRF24L01_t* nrf );
*/

#endif //#ifndef __NRF24L01P_H_H
