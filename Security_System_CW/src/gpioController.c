/**
  ******************************************************************************
  * @file    gpioController.c 
  * @author  Tiberiu Simion Voicu, Ioakim Ioakim
  * @version V1.0.0
  * @date    17 April 2018
  * @brief   This file provides implementation of the functions used 
  			 to control the GPIO pins
  ******************************************************************************
  */

#include "gpioController.h"

 
GPIO_PIN getPin(uint8_t dIndex) {
	return GPIO_PINS[dIndex];
}
void enableClocksGPIO(void){
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOG_CLK_ENABLE();
	__HAL_RCC_GPIOI_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
}
void initGPIO(uint32_t Dindex, uint32_t mode, uint32_t pull, uint32_t speed, uint32_t alternate) {
	GPIO_TypeDef *port = GPIO_PINS[Dindex].port;
	uint16_t pin = GPIO_PINS[Dindex].pin;
  	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.Pin   = pin;
	GPIO_InitStruct.Mode  = mode;
	GPIO_InitStruct.Pull  = pull;
	GPIO_InitStruct.Speed = speed;
	// Only used if GPIO set to alternate Mode
	if( alternate != 0 ) 
		GPIO_InitStruct.Alternate = alternate;

	HAL_GPIO_Init(port, &GPIO_InitStruct);
}

void digitalWrite (uint8_t num, uint8_t set) {
	// set pin HIGH
	if(set == 1) {
		HAL_GPIO_WritePin(GPIO_PINS[num].port, GPIO_PINS[num].pin, GPIO_PIN_SET);
  }
	// set pin Low
	else if( set == 0 ){
		HAL_GPIO_WritePin(GPIO_PINS[num].port, GPIO_PINS[num].pin, GPIO_PIN_RESET);
	}
}

void init_button(int8_t Dindex) {
	initGPIO(Dindex, GPIO_MODE_INPUT, GPIO_NOPULL, GPIO_SPEED_LOW, 0);
}
uint8_t digitalRead(uint8_t Dindex) {
	return HAL_GPIO_ReadPin(GPIO_PINS[Dindex].port, GPIO_PINS[Dindex].pin);
}
void delayMicro(uint64_t micros) {
	int i = micros;
	while(i != 0) 
		i--;
}
