#include "main.h"
#include "stm32f4xx_hal.h"


typedef enum 
{
  RX_InitMODE      				= 0x00U,
  TX_InitMODE    					= 0x01U
} NRF_InitialModeTypeDef;


/* Commands */
typedef enum {
   NRF_CMD_R_REGISTER         = 0x00,
   NRF_CMD_W_REGISTER         = 0x20,
   NRF_CMD_R_RX_PAYLOAD       = 0x61,
   NRF_CMD_W_TX_PAYLOAD       = 0xA0,
   NRF_CMD_FLUSH_TX           = 0xE1,
   NRF_CMD_FLUSH_RX           = 0xE2,
   NRF_CMD_REUSE_TX_PL        = 0xE3,
   NRF_CMD_R_RX_PL_WID        = 0x60,
   NRF_CMD_W_ACK_PAYLOAD      = 0xA8,
   NRF_CMD_W_TX_PAYLOAD_NOACK = 0xB0,
   NRF_CMD_NOP                = 0xFF
} NRF_CommandTypeDef;

/* Registers */
typedef enum {
    NRF_CONFIG      = 0x00,
    NRF_EN_AA       = 0x01,
    NRF_EN_RXADDR   = 0x02,
    NRF_SETUP_AW    = 0x03,
    NRF_SETUP_RETR  = 0x04,
    NRF_RF_CH       = 0x05,
    NRF_RF_SETUP    = 0x06,
    NRF_STATUS      = 0x07,
    NRF_OBSERVE_TX  = 0x08,
    NRF_CD          = 0x09,
    NRF_RX_ADDR_P0  = 0x0A,
    NRF_RX_ADDR_P1  = 0x0B,
    NRF_RX_ADDR_P2  = 0x0C,
    NRF_RX_ADDR_P3  = 0x0D,
    NRF_RX_ADDR_P4  = 0x0E,
    NRF_RX_ADDR_P5  = 0x0F,
    NRF_TX_ADDR     = 0x10,
    NRF_RX_PW_P0    = 0x11,
    NRF_RX_PW_P1    = 0x12,
    NRF_RX_PW_P2    = 0x13,
    NRF_RX_PW_P3    = 0x14,
    NRF_RX_PW_P4    = 0x15,
    NRF_RX_PW_P5    = 0x16,
    NRF_FIFO_STATUS = 0x17,
    NRF_DYNPD       = 0x1C,
    NRF_FEATURE     = 0x1D
} NRF_RegisterTypeDef;

typedef enum {
    NRF_DATA_RATE_250KBPS = 1,
    NRF_DATA_RATE_1MBPS   = 0,
    NRF_DATA_RATE_2MBPS   = 2
} NRF_DATA_RATE;

typedef enum {
    NRF_TX_PWR_M18dBm = 0,
    NRF_TX_PWR_M12dBm = 1,
    NRF_TX_PWR_M6dBm  = 2,
    NRF_TX_PWR_0dBm   = 3
} NRF_TX_PWR;

typedef struct{
	SPI_HandleTypeDef*  				hspi;
	NRF_ModeTypeDef 						mode;
	NRF_InitialModeTypeDef 			InitMode;
	NRF_DATA_RATE  							data_rate;
  NRF_TX_PWR     							tx_power;
	GPIO_TypeDef* 							SPI_MOSI_port;
	GPIO_TypeDef* 							SPI_MISO_port;
	GPIO_TypeDef* 							SPI_CSN_port;
	GPIO_TypeDef* 							SPI_SCK_port;
	GPIO_TypeDef* 							IRQ_port;
	GPIO_TypeDef* 							CE_port;
	uint16_t 										SPI_MOSI_pin;
	uint16_t 										SPI_MISO_pin;
	uint16_t 										SPI_CSN_pin;
	uint16_t 										SPI_SCK_pin;
	uint16_t 										IRQ_pin;
	uint16_t 										CE_pin;	
}	NRF24L01_t;

HAL_StatusTypeDef NRF_INS_Read_Reg_STAT(			       NRF24L01_t* nrf,
																				       uint8_t adr, 
																				       uint8_t d_len, 
																				       uint8_t* pdata, 
																				       uint8_t* STAT_Reg );

HAL_StatusTypeDef NRF_INS_Read_Reg(			       NRF24L01_t* nrf,
																				       uint8_t adr, 
																				       uint8_t d_len, 
																				       uint8_t* pdata );

HAL_StatusTypeDef NRF_INS_Write_Reg_STAT(		       NRF24L01_t* nrf,
																				       uint8_t adr, 
																				       uint8_t d_len, 
																				       uint8_t* pdata, 
																				       uint8_t* STAT_Reg );

HAL_StatusTypeDef NRF_INS_Write_Reg(		       NRF24L01_t* nrf,
																				       uint8_t adr, 
																				       uint8_t d_len, 
																				       uint8_t* pdata );

HAL_StatusTypeDef NRF_INS_Read_Rx_PL(		       NRF24L01_t* nrf, 
																				       uint8_t d_len, 
																				       uint8_t* pdata, 
																				       uint8_t* STAT_Reg );

HAL_StatusTypeDef NRF_INS_Write_Tx_PL(	       NRF24L01_t* nrf, 
																				       uint8_t d_len, 
																				       uint8_t* pdata, 
																				       uint8_t* STAT_Reg );

HAL_StatusTypeDef NRF_INS_Flush_Tx(			       NRF24L01_t* nrf,
																				       uint8_t* STAT_Reg );

HAL_StatusTypeDef NRF_INS_Flush_Rx(			       NRF24L01_t* nrf,
																				       uint8_t* STAT_Reg );

HAL_StatusTypeDef NRF_INS_Reuse_TxPL(		       NRF24L01_t* nrf,
																				       uint8_t* STAT_Reg );

HAL_StatusTypeDef NRF_INS_NOP(					       NRF24L01_t* nrf,
																				       uint8_t* STAT_Reg );
																																									
HAL_StatusTypeDef NRF_INS_W_TX_PAYLOAD_NO_ACK( NRF24L01_t* nrf,
                                               uint8_t* STAT_Reg);
																					 
HAL_StatusTypeDef NRF_INS_R_RX_PL_WID(         NRF24L01_t* nrf,	                                             
																				       uint8_t* pdata, 
                                               uint8_t* STAT_Reg);
																					 
HAL_StatusTypeDef NRF_INS_W_ACK_PAYLOAD(       NRF24L01_t* nrf,
	                                             uint8_t d_len, 
																				       uint8_t* pdata, 
                                               uint8_t pipe_n,
                                               uint8_t* STAT_Reg);


