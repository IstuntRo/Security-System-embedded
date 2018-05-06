#ifndef TOUCHINPUTCONTROLLER_H_   /* Include guard */
#define TOUCHINPUTCONTROLLER_H_
#include "GLCD_Config.h"
#include "Board_GLCD.h"
#include "Board_Touch.h"
#include "pirController.h"
#include "gpioController.h"
#include "LedBuzzerController.h"
#include "stm32746g_discovery_ts.h"

extern GLCD_FONT     GLCD_Font_16x24;
#define pass1 				"1234"

/**
  * @brief  Initiate GLCD and Touch
  * @param  None
  * @retval None
  */
void initGLCD(void);

/**
  * @brief  Draw keypad on GLCD
  * @param  None
  * @retval None
  */
void drawKeypad(void);

/**
  * @brief  Get the symbol resulted from touching a certain area of the display
  * @param  None
  * @retval None
  */
char getTouch(void);

/**
  * @brief  Add a key to password to be checked whether it's correct
  * @param  Key: the char that was selected
  * @retval None
  */
void addKey(char key);
#endif // TOUCHINPUTCONTROLLER_H_
