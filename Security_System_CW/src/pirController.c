/**
  ******************************************************************************
  * @file    pirController.c
  * @author  Tiberiu Simion Voicu, Ioakim Ioakim
  * @version V1.0.0
  * @date    17 April 2018
  * @brief   This file provides implementation of the functions 
  			 used to control the pir sensor
  ******************************************************************************
  */

#include "gpioController.h"
#include "pirController.h"

void initPir () {
	initGPIO(pir_GPIO_Num, GPIO_MODE_IT_RISING, GPIO_NOPULL, GPIO_SPEED_HIGH, 0);
	HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}
 

	 
 

