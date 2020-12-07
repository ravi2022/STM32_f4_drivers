/*
 * stm32_spi_api.h
 *
 *  Created on: 3-Dec-2020
 *      Author: RAVISHANKAR GAIKWAD
 */

#ifndef INC_STM32_SPI_API_H_

#define INC_STM32_SPI_API_H_
#include "stm32f407xx.h"

typedef struct
{
uint32_t SPI_DeviceModde;
uint32_t SPI_BusConfig;
uint32_t SPI_SclkSpeed;
uint32_t SPI_DFF;
uint32_t SPI_CPOL;
uint32_t SPI_CPHA;
uint32_t SPI_SSM;

}SPI_config;


typedef struct
{
	SPI_reg_def *pSPIx;
	SPI_config SPI_configur;


}SPI_handle;


/*@
 @Dvice mode
 */
#define SPI_master 1
#define SPI_slave 0


/*
 @BUs configuration
 */

#define SPI_Bus_config_FD 		0
#define SPI_Bus_config_HD 		1
#define SPI_Bus_config_simplex_receive_only 		2




void SPI_peri_clock_control(uint32_t SPI_port_no);
void SPI_init(SPI_handle *pSPI_handle_t);
void SPI_transmit(SPI_reg_def *pSPIx,uint8_t *pTXbuffer,uint32_t len);
void SPI_receive(SPI_reg_def *pSPIx,uint8_t *pRXbuffer,uint32_t len);


#endif /* INC_STM32_SPI_API_H_ */