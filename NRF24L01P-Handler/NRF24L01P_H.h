#ifndef __NRF24L01P_H_H
#define __NRF24L01P_H_H

#include "NRF24L01P_MED.h"
        
                                  
typedef struct{   	
	// NRF24L01P Existance TypeDef
	NRF24L01P_ExTypeDef*						instance;
	
	// NRF24L01P Initialization TypeDef
	NRF24L01P_MED_InitTypeDef*			init;

	// STATUS Register	
	uint8_t*												STAT_Reg;
	
	// CE GPIO                      
	GPIO_TypeDef*										CE_Port;
	uint16_t												CE_Pin;
	
	// IRQ GPIO                      
	GPIO_TypeDef*										IRQ_Port;
	uint16_t												IRQ_Pin;
	
	// Maximum ReTransmit IRQ Callback
	void (*Max_RT_IRQ_Callback)(void);
	
	// Tx Data Sent IRQ Callback
	void (*Tx_DS_IRQ_Callback)(void);
	
	// Rx Data Received IRQ Callback
	void (*Rx_DR_IRQ_Callback)(void);
	
	
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

HAL_StatusTypeDef NRF_H_IRQ_Handler(	NRF24L01P_HandlerTypeDef*	hnrf );

//HAL_StatusTypeDef NRF_H_ReConfig(			NRF24L01P_HandlerTypeDef* hnrf);

/*


void NRF_H_RF_CH(	NRF24L01_t* nrf, uint8_t ch);

void NRF_H_SETUP_RETR_Delay(NRF24L01_t* nrf, uint8_t delay);

void NRF_H_T2R( NRF24L01_t* nrf );

void NRF_H_R2T( NRF24L01_t* nrf );
*/

#endif //#ifndef __NRF24L01P_H_H
