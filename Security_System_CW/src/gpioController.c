#include "gpioController.h"

static const GPIO_PIN GPIO_PINS[] = {
	{GPIOC, GPIO_PIN_7}, 	//D0
	{GPIOC, GPIO_PIN_6},		//D1
	{GPIOG, GPIO_PIN_6},		//D2
	{GPIOB, GPIO_PIN_4},		//D3	
	{GPIOG, GPIO_PIN_7}		//D4
};
GPIO_PIN getPin(uint8_t dIndex) {
	return GPIO_PINS[dIndex];
}
void LED_Initialize (int8_t Dindex) {
	GPIO_TypeDef *port = GPIO_PINS[Dindex].port;
	uint16_t pin = GPIO_PINS[Dindex].pin;
  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
	// TODO NOT HAVE TO CHANGE GPIOX every time
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /* Configure GPIO pin: PI1 (LD1) */
  GPIO_InitStruct.Pin   = pin;
  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(port, &GPIO_InitStruct);
}
void digitalWrite (uint8_t num, int set) {
	if(set == 1) {
		HAL_GPIO_WritePin(GPIO_PINS[num].port, GPIO_PINS[num].pin, GPIO_PIN_SET);
  }
	else {
		HAL_GPIO_WritePin(GPIO_PINS[num].port, GPIO_PINS[num].pin, GPIO_PIN_RESET);
	}
}

void init_button(int8_t Dindex) {
	GPIO_TypeDef *port = GPIO_PINS[Dindex].port;
	uint16_t pin = GPIO_PINS[Dindex].pin;
  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
	// TODO NOT HAVE TO CHANGE GPIOX every time
  //__HAL_RCC_GPIOC_CLK_ENABLE();

  /* Configure GPIO pin: PI1 (LD1) */
  GPIO_InitStruct.Pin   = pin;
  GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull  = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
  HAL_GPIO_Init(port, &GPIO_InitStruct);
}
int digitalRead(uint8_t num) {
	return HAL_GPIO_ReadPin(GPIO_PINS[num].port, GPIO_PINS[num].pin);
}
