#include "stm32f4xx_hal.h"
#include "main.h"
#include "NRF24L01_IS.h"

void NRF_H_SetChipEn(    NRF24L01_t* nrf);

void NRF_H_ReSetChipEn(  NRF24L01_t* nrf);

void NRF_H_Init(         NRF24L01_t* nrf);