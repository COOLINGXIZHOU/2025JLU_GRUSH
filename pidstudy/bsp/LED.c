#include "headfile.h"
void LED_ON()
{
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,1);
}
void LED_OFF()
{
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,0);
}