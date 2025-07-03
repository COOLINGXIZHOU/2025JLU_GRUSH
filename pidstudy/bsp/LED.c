#include "headfile.h"
void LED_ON()
{
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,1);
}
void LED_OFF()
{
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,0);
}

void led_showR(uint8_t mode)
{
   
    
    if(mode)
    {
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_RESET);
    }
    else
    {
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,GPIO_PIN_SET);
    }   
}
void led_showG(uint8_t mode)
{
   
    
    if(mode)
    {
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_RESET);
    }
    else
    {
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_4,GPIO_PIN_SET);
    }   
}
void led_showB(uint8_t mode)
{
   
    
    if(mode)
    {
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,GPIO_PIN_RESET);
    }
    else
    {
        HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,GPIO_PIN_SET);
    }   
}
