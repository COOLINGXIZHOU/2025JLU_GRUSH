#include "headfile.h"
uint8_t huidu[8];
void Huidu_Get()
{
	huidu[0]=HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_0);
	huidu[1]=HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_1);
	huidu[2]=HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_2);
	huidu[3]=HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_3);
	huidu[4]=HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_4);
	huidu[5]=HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_5);
	huidu[6]=HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_6);
	huidu[7]=HAL_GPIO_ReadPin(GPIOD,GPIO_PIN_7);
}