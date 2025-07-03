#include "headfile.h"
/**
  * 函    数：获取编码器的增量值
  * 参    数：无
  * 返 回 值：自上此调用此函数后，编码器的增量值
  */
int16_t Encoder_GetA(void)
{
	int16_t Temp;
	Temp = __HAL_TIM_GET_COUNTER(&htim4);
	__HAL_TIM_SET_COUNTER(&htim4,0);
	return Temp;
}
int16_t Encoder_GetB(void)
{
	int16_t Temp;
	Temp = __HAL_TIM_GET_COUNTER(&htim8);
	__HAL_TIM_SET_COUNTER(&htim8,0);
	return Temp;
}
