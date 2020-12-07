*
 * stm32_spi_api.c
 *
 *  Created on: 4-Dec-2020
 *      Author: RAVISHANKAR GAIKWAD
 */

#ifndef SRC_STM32_SPI_API_C_
#define SRC_STM32_SPI_API_C_

#include "stm32_spi_api.h"

void SPI_peri_clock_control(uint32_t SPI_port_no)
{
	if (SPI_port_no==1)
	{
		RCC->APB2ENR |=(1<<12);


	}
	else
		if(SPI_port_no==4)
		{
			RCC->APB2ENR |=(1<<13);
		}
		else
			if(SPI_port_no==3)
			{
				RCC->APB1ENR |=(1<<15);
			}
			else
			{
				RCC->APB1ENR |=(1<<14);
			}

}



void SPI_init(SPI_handle *pSPI_handle_t)
{
	//configure device mode
	uint32_t temp=0;
	temp |=pSPI_handle_t->SPI_configur.SPI_DeviceModde << 2;

	//configure bus configuration like full duplex or half duplex
	if (pSPI_handle_t->SPI_configur.SPI_BusConfig==SPI_Bus_config_FD)
		temp |= (1<<15);
	else
		{
		if(pSPI_handle_t->SPI_configur.SPI_BusConfig==SPI_Bus_confih_HD)
		{
			temp &= ~(1<<15);
		}
		else
		{
			if(pSPI_handle_t->SPI_configur.SPI_BusConfig==SPI_Bus_config_simplex_receive_only)
			{
				temp &= ~(1<<15);
				temp |=1<< 10;
			}
		}

		}
	// configure CPOL and CPHA





}



#endif /* SRC_STM32_SPI_API_C_ */