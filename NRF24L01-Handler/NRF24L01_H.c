#include "NRF24L01_H.h"

void NRF_H_SetChipEn(       NRF24L01_t* nrf) {
	
	 HAL_GPIO_WritePin(nrf->CE_port,nrf->CE_pin,GPIO_PIN_SET);		 
														 
													                   }
													 
void NRF_H_ReSetChipEn(     NRF24L01_t* nrf) {
	
   HAL_GPIO_WritePin(nrf->CE_port,nrf->CE_pin,GPIO_PIN_RESET);																 

														                 }

void NRF_H_SetCSN(          NRF24L01_t* nrf) {
	
	 HAL_GPIO_WritePin(nrf->SPI_CSN_port,nrf->SPI_CSN_pin,GPIO_PIN_SET);		 
														 
													                   }
													 
void NRF_H_ReSetCSN(        NRF24L01_t* nrf) {
	
   HAL_GPIO_WritePin(nrf->SPI_CSN_port,nrf->SPI_CSN_pin,GPIO_PIN_RESET);																 

														                 }
void NRF_H_Init(            NRF24L01_t* nrf){
	
	//TODO configure gpio pins
	HAL_Delay(100);
	//Set PWR_UP and Tx and Rx mode
	if(nrf->InitMode==RX_InitMODE)
	{
	  uint8_t Rx=0x0B;
		NRF_INS_Write_Reg(nrf,NRF_CONFIG, 1,&Rx);
	}
	if(nrf->InitMode==TX_InitMODE)
	{
	  uint8_t Tx=0x0A;
		NRF_INS_Write_Reg(nrf,NRF_CONFIG, 1,&Tx);
	}
	
}

void NRF_H_IRQ_Handler(  NRF24L01_t* nrf ){
	//Every new command must be started by a high to low transition on CSN
	NRF_H_SetCSN(nrf);
	HAL_Delay(1);
	NRF_H_ReSetCSN(nrf);
	//Read configure Register
	uint8_t Config_reg[8];
	NRF_INS_Read_Reg(nrf,NRF_CONFIG,1,Config_reg );
	
	if(Config_reg[1]==0)//Reflect RX_DR as active low interrupt on the RQ pin
		NRF_H_RX_DR_Callback();
	
	else if(Config_reg[2]==0)//Reflect TX_DS as active low interrupt on the IRQ pin
		NRF_H_TX_DS_Callback();
	
	else if(Config_reg[3]==0)//Reflect MAX_RT as active low interrupt on the IRQ pin
		NRF_H_MAX_RT_Callback();
	
	UNUSED(0);
}

__weak void NRF_H_TX_DS_Callback(void){
	UNUSED(0);
}

__weak void NRF_H_RX_DR_Callback(void){
	UNUSED(0);
}

__weak void NRF_H_MAX_RT_Callback(void){
	UNUSED(0);
}	
	