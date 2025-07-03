#include "headfile.h"
/**
  * 函    数：PWM设置CCR
  * 参    数：Compare 要写入的CCR的值，范围：0~100
  * 返 回 值：无
  * 注意事项：CCR和ARR共同决定占空比，此函数仅设置CCR的值，并不直接是占空比
  *           占空比Duty = CCR / (ARR + 1)
  */
void PWM_SetCompare9_1(uint16_t Compare)
{
	TIM9->CCR1=Compare;
}
void PWM_SetCompare9_2(uint16_t Compare)
{
	TIM9->CCR2=Compare;
}
