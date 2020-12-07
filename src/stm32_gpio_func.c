/*
 * stm32_gpio_api.c
 *
 *  Created on: 2-Dec-2020
 *      Author: RAVISHANKAR GAIKWAD
 */
#include "stm32_gpio_api.h"
#include "stm32f407xx.h"


void Gpio_init(Gpio_handle *pGpio_handle) //port_num is like 1 for PORTA,2 for PORTB and so on
{
	uint32_t temp;
	//setting Mode For Pin
	if(pGpio_handle->Gpio_user.Gpio_PinMode <= Gpio_Mode_Analog)
	{


		temp=0;
		temp = pGpio_handle->Gpio_user.Gpio_PinMode <<(2*pGpio_handle->Gpio_user.Gpio_PinNumber);
		pGpio_handle->pGpio_base->MODER &= ~(1<<2*pGpio_handle->Gpio_user.Gpio_PinNumber);//clearing bit field
		pGpio_handle->pGpio_base->MODER |= temp;
		temp=0;


	}
	else
	{
// for  interrupt mode
	}

	//config speed

    temp=0;
    temp=pGpio_handle->Gpio_user.Gpio_PinSpeed <<(2*pGpio_handle->Gpio_user.Gpio_PinNumber);
    pGpio_handle->pGpio_base->OSPEEDR &= ~(1<<2*pGpio_handle->Gpio_user.Gpio_PinNumber);//clearing bit field
    pGpio_handle->pGpio_Base->OSPEEDR |= temp;
    temp=0;

    //confg the pullup registers
    temp=0;
    temp=pGpio_handle->Gpio_user.Gpio_PinPuPdControl <<(2*pGpio_handle->Gpio_user.Gpio_PinNumber);
    pGpio_handle->pGpio_base->PUPDR &= ~(1<<2*pGpio_handle->Gpio_user.Gpio_PinNumber);//clearing bit field
    pGpio_handle->pGpio_base->PUPDR |= temp;
    temp=0;

    //configure the output type

    temp=0;
    temp=pGpio_handle->Gpio_user.Gpio_PinOpType <<(2*pGpio_handle->Gpio_user.Gpio_PinNumber);
    pGpio_handle->pGpio_base->OTYPER &= ~(1<<2*pGpio_handle->Gpio_user.Gpio_PinNumber);//clearing bit field
    pGpio_handle->pGpio_base->OTYPER |= temp;
    temp=0;

   /* //configure the alt functionality
    temp=0;
    temp=pGpio_handle->Gpio_user.Gpio_PinMode <<(2*pGpio_handle->Gpio_user.Gpio_PinNumber);
    pGpio_handle->pGpio_base->PUPDR &= ~(1<<2*pGpio_handle->Gpio_user.Gpio_PinNumber);//clearing bit field
    pGpio_handle->pGpio_base->PUPDR |= temp;
    temp=0;
    */


}




void Gpio_noinit(uint8_t PortNumber)
{
	// port number is 0 for Port A ,1 for Port B and so on
	RCC->AHB1RSTR |=(1<<PortNumber); //reset the port
	RCC->AHB1RSTR &= ~(1<<PortNumber); //exit the port from reset

}



void Gpio_Peri_Clock_contrl(uint8_t EnorDs,uint8_t port_num)
{
	if(EnorDs==1)
	{
      RCC->AHB1ENR |=(1<<port_num);
	}
	else
		{
		RCC->AHB1ENR &=~(1<<port_num);
	   }
 }



uint8_t Gpio_read_Pin(Gpio_reg_def *pGpiox,uint8_t PinNumber)
{
	uint8_t value;
	value =(uint8_t)((pGpiox->IDR >>PinNumber) &=0x00000001);
    return value;
}

uint16_t Gpio_read_Port(Gpio_reg_def *pGpiox)
{
	uint16_t value;
	value=(uint16_t)pGpiox->ODR;
	return value;

}
void Gpio_write_Pin(Gpio_reg_def *pGpiox,uint8_t PinNumber,uint8_t value)
{
	if(value)
	{
	pGpiox->ODR |=(1<<PinNumber);
	}
	else
	{

		pGpiox->ODR &= ~(1<<PinNumber);
	}

}


void Gpio_write_Port(Gpio_reg_def *pGpiox,uint16_t value)
{
	pGpiox->ODR =value;

}