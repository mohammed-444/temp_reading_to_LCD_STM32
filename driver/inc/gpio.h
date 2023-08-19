/*
 * gpio.h
 *
 *  Created on: May 27, 2022
 *      Author: hp
 */

#ifndef INCLUDE_GPIO_H_
#define INCLUDE_GPIO_H_
#include "stm32f4xx.h"

void GPIO_Init (GPIO_TypeDef * GPIOx,char pin,char dir,char enable_pin);
char GPIO_Write(GPIO_TypeDef * GPIOx,char pin,char state);
char GPIO_Read(GPIO_TypeDef * GPIOx,char pin);
void pull(GPIO_TypeDef * GPIOx,char pin,char up);

#endif /* INCLUDE_GPIO_H_ */

