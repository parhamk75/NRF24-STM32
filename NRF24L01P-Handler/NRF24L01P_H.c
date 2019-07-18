#include "NRF24L01P_H.h"

HAL_StatusTypeDef NRF_H_SetChipEn( NRF24L01P_HandlerTypeDef* hnrf )
{
	/*
		This function makes Chip Enable pin high (Set CE)
	*/
	
	HAL_GPIO_WritePin(hnrf->CE_Port,hnrf->CE_Pin,GPIO_PIN_SET);
	
	return HAL_OK;
}


HAL_StatusTypeDef NRF_H_ResetChipEn( NRF24L01P_HandlerTypeDef* hnrf )
{
	/*
		This function makes Chip Enable pin low (Reseet CE)
	*/
	
	HAL_GPIO_WritePin(hnrf->CE_Port,hnrf->CE_Pin,GPIO_PIN_RESET);
	
	return HAL_OK;
}


HAL_StatusTypeDef NRF_H_Init(         NRF24L01P_HandlerTypeDef* hnrf)
{
	
	return HAL_OK;
}

/*

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
	uint8_t Status_reg[8];
	NRF_INS_Read_Reg(nrf,NRF_STATUS,1,Status_reg );
	
	if(Status_reg[1]==0)//Reflect RX_DR as active low interrupt on the RQ pin
		NRF_H_RX_DR_Callback();
	
	else if(Status_reg[2]==0)//Reflect TX_DS as active low interrupt on the IRQ pin
		NRF_H_TX_DS_Callback();
	
	else if(Status_reg[3]==0)//Reflect MAX_RT as active low interrupt on the IRQ pin
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

void NRF_H_RF_CH(	NRF24L01_t* nrf, uint8_t ch){
	  
		NRF_INS_Write_Reg(nrf,NRF_RF_CH, 1,&ch);
}
//Setup of Automatic Retransmission
void NRF_H_SETUP_RETR_Delay(NRF24L01_t* nrf, uint8_t delay){
	//give it in µS
	uint8_t code=(delay/250)-1;
	NRF_INS_Write_Reg(nrf,NRF_SETUP_RETR, 1,&code);
}
//Setup of Address Widths(common for all data pipes)
void NRF_H_SETUP_AW(NRF24L01_t* nrf, uint8_t add_byte){
	//only 3,4 and 5 byte
	add_byte=-2;
	NRF_INS_Write_Reg(nrf,NRF_SETUP_AW, 1,&add_byte);
	//LSByte is used if address width is below 5 bytes
}
//Enable ‘Auto Acknowledgment’ Function
void NRF_H_EN_AA(NRF24L01_t* nrf, uint8_t data_pipe_num){
	uint8_t pdata;	
  NRF_INS_Read_Reg( nrf,NRF_CONFIG,1,&pdata);
	data_pipe_num=2^data_pipe_num;
	NRF_INS_Write_Reg(nrf,NRF_EN_AA, 1,&data_pipe_num);
}

void NRF_H_RF_PWR(NRF24L01_t* nrf, uint8_t data_pipe_num){
	
}
	
void NRF_H_T2R( NRF24L01_t* nrf ){
	
uint8_t pdata;	
NRF_INS_Read_Reg( nrf,NRF_CONFIG,1,&pdata);
pdata=pdata | (uint8_t ) 0x00000001;
NRF_INS_Write_Reg(nrf,NRF_CONFIG, 1,&pdata);																	        
																				      
}

void NRF_H_R2T( NRF24L01_t* nrf ){
	
uint8_t pdata;	
NRF_INS_Read_Reg( nrf,NRF_CONFIG,1,&pdata);
pdata=pdata & (uint8_t ) 0x11111110;
NRF_INS_Write_Reg(nrf,NRF_CONFIG, 1,&pdata);																	        																			      
}


*/







