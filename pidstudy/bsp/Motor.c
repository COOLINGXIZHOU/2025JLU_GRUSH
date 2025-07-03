#include "headfile.h"
/**
  * 函    数：直流电机设置速度
  * 参    数：Speed 要设置的速度，范围：-100~100
  * 返 回 值：无
  */
void Motor_SetPWM9_1(int8_t Speed)
{
	if (Speed >= 0)							//如果设置正转的速度值
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4,GPIO_PIN_SET);	//PB4置高电平
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,GPIO_PIN_RESET);	//PB5置低电平，设置方向为正转
		PWM_SetCompare9_1(Speed);				//PWM设置为速度值
	}
	else									//否则，即设置反转的速度值
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4,GPIO_PIN_RESET);	//PB4置低电平
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,GPIO_PIN_SET);	//PB5置高电平，设置方向为反转
		PWM_SetCompare9_1(-Speed);				//PWM设置为速度值
	}
}
void Motor_SetPWM9_2(int8_t Speed)
{
	if (Speed >= 0)							//如果设置正转的速度值
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6,GPIO_PIN_SET);	//PB6置高电平
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7,GPIO_PIN_RESET);	//PB7置低电平，设置方向为正转
		PWM_SetCompare9_2(Speed);				//PWM设置为速度值
	}
	else									//否则，即设置反转的速度值
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6,GPIO_PIN_RESET);	//PB6置低电平
	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7,GPIO_PIN_SET);	//PB7置高电平，设置方向为反转
		PWM_SetCompare9_2(-Speed);				//PWM设置为速度值
	}
}
