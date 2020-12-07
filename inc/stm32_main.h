/*
 * stm32f407xx.h
 *
 *  Created on: Dec 03, 2020
 *      Author: RAVISHANKAR GAIKWAD
 */



#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>

#define FLASH 			0x00000000U
#define SRAM1 			0x20000000U
#define SRAM2 			0x2001C000U
#define SRAM  			SRAM1
#define APB1_BASE 		0x40000000U
#define APB2_BASE 		0x40010000U
#define AHB1_BASE 		0x40020000U
#define AHB2_BASE 		0x50000000U
#define AHB3_BASE 		0xA0000000U
#define ROM_BASE  		0x1FFF0000U

#define GPIOA  			0x40020000U
#define GPIOB  			0x40020400U
#define GPIOC  			0x40020800U
#define GPIOD  			0x40020C00U
#define GPIOE  			0x40021000U
#define GPIOF 			0x40021400U
#define GPIOG  			0x40021800U
#define GPIOH  			0x40021C00U
#define GPIOI  			0x40022000U
#define GPIOJ  			0x40022400U
#define GPIOK  			0x40022800U

#define RCC_BASE  		0x40023800U

typedef struct
{
uint32_t MODER;
uint32_t OTYPER;
uint32_t OSPEEDR;
uint32_t PUPDR;
uint32_t IDR;
uint32_t ODR;
uint32_t BSRR;
uint32_t LCKR;
uint32_t AFR[2];

}Gpio_reg_def;


typedef struct
{
volatile uint32_t	CR;
volatile uint32_t		PLLCFGR;
volatile uint32_t		CFGR;
volatile uint32_t		CIR;
volatile uint32_t		AHB1RSTR;
volatile uint32_t		AHB2RSTR;
volatile uint32_t		AHB3RSTR;
volatile uint32_t		RESERVED;
volatile uint32_t		APB1RSTR;
volatile uint32_t		APB2RSTR;
		 uint32_t		RESERVED1[2];
volatile uint32_t		AHB1ENR;
volatile uint32_t		AHB2ENR;
volatile uint32_t		AHB3ENR;
volatile uint32_t		RESERVED6;
volatile uint32_t		APB1ENR;
volatile uint32_t		APB2ENR;
		 uint32_t		RESERVED2[2];
volatile uint32_t		AHB1LPENR;
volatile uint32_t		AHB2LPENR;
volatile uint32_t		AHB3LPENR;
volatile uint32_t	RESERVED5;
volatile uint32_t	APB1LPENR;
volatile uint32_t	APB2LPENR;
 	 	 uint32_t	RESERVED3[2];
volatile uint32_t	BDCR;
volatile uint32_t	CSR;
		 uint32_t	RESERVED4[2];
volatile uint32_t		SSCGR;
volatile uint32_t		PLLI2SCFGR;
volatile uint32_t	PLLSAICFGR;
volatile uint32_t	DCKCFGR;

}RCC_reg_def;

#define RCC        ((RCC_reg_def*)RCC_BASE)





//declaration of SPI here below

#define SPI1_BASE 0x40013000U
#define SPI2_BASE 0x40003800U
#define SPI3_BASE 0x40003C00U
#define SPI4_BASE 0x40013400U


typedef struct
{
	uint32_t CR1;
	uint32_t CR2;
	uint32_t SR;
	uint32_t DR;
	uint32_t CRCPR;
	uint32_t RXCRCR;
	uint32_t TXCRCR;
	uint32_t I2S_CFGR;
	uint32_t I2S_PR;



}SPI_reg_def;

#define SPI1 ((SPI_reg_def*)SPI1_BASE);
#define SPI2 ((SPI_reg_def*)SPI2_BASE);
#define SPI3 ((SPI_reg_def*)SPI3_BASE);
#define SPI4 ((SPI_reg_def*)SPI4_BASE);


#include"stm32_gpio_api.h"
#include"stm32_spi_api.h"
