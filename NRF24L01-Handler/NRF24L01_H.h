#include "NRF24L01_IS.h"

void NRF_H_SetChipEn(    NRF24L01_t* nrf);

void NRF_H_ReSetChipEn(  NRF24L01_t* nrf);

void NRF_H_Init(         NRF24L01_t* nrf);

void NRF_H_IRQ_Handler(  NRF24L01_t* nrf);

void NRF_H_TX_DS_Callback(void);

void NRF_H_RX_DR_Callback(void);

void NRF_H_MAX_RT_Callback(void);


