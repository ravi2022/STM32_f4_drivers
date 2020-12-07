
/*
 * stm32_gpio_api.h
 *
 *  Created on: 25-Nov-2020
 *      Author: RAVISHANKAR GAIKWAD
 */

#ifndef INC_STM32_GPIO_API_H_

#define INC_STM32_GPIO_API_H_



#include "stm32f407xx.h"

typedef struct
{
	uint8_t Gpio_PinNumber;
	uint8_t Gpio_PinMode;
	uint8_t Gpio_PinSpeed;
	uint8_t Gpio_PinPuPdControl;
	uint8_t Gpio_PinOpType;
	uint8_t Gpio_PinAltFn;
}Pin_confg;




typedef struct
{	// base address to which the port belongs
	Gpio_reg_def *pGpio_base;
	Pin_confg  Gpio_user;

}Gpio_handle;

void Gpio_init(Gpio_handle *pGpio_user_handle);

void Gpio_noinit(void);
void Gpio_Peri_Clock_contrl(uint8_t EnorDs,uint8_t port_num);
uint8_t Gpio_read_Pin(Gpio_reg_def *pGpiox,uint8_t PinNumber);
uint16_t Gpio_read_Port(Gpio_reg_def *pGpiox);
void Gpio_write_Pin(Gpio_reg_def *pGpiox,uint8_t PinNumber,uint8_t value);
void Gpio_write_Port(Gpio_reg_def *pGpiox,uint16_t value);




#endif /* INC_STM32_GPIO_API_H_ */