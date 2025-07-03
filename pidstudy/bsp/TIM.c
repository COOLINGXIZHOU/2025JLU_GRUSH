#include "headfile.h"
#define EPSILON 0.00001
int16_t speedA,locationA,speedB,locationB;
float TargetA,OutA,ActualA;
float KpA=0,KiA=0,KdA=0;
float Error0A,Error1A,ErrorIntA,Error2A;
float TargetB,OutB,ActualB;
float KpB=0,KiB=0,KdB=0;
float Error0B,Error1B,ErrorIntB,Error2B;
float MaxA=100,MaxB=100;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	static uint8_t counts1,counts2;
	if(htim->Instance==TIM1)//TIM1用于读取按键值的扫描和读取编码器速度位置的扫描
	{
		Key_Tick();
		counts1++;
		if(counts1>=40)
		{
			counts1=0;
			speedA=Encoder_GetA();
			locationA+=speedA;
			speedB=Encoder_GetB();
			locationB+=speedB;
		}
	}
	if(htim->Instance==TIM2)
	{
		counts2++;
		if(counts2>=40)
		{
			counts2=0;
			ActualA=speedA;
			//Error2A=Error1A;增量式pid打开这一行，位置式pid关闭
			Error1A=Error0A;
			Error0A=TargetA-ActualA;
			ActualB=speedB;
			//Error2B=Error1B;增量式pid打开这一行，位置式pid关闭
			Error1B=Error0B;
			Error0B=TargetB-ActualB;
			/*积分部分  如果使用增量式pid注释掉积分部分，使用位置式pid则打开*/
			if(fabs(KiA)>EPSILON)
		{
			ErrorIntA+=Error0A;
		}
			else
		{
			ErrorIntA=0;
		}
			if(fabs(KiB)>EPSILON)
		{
			ErrorIntB+=Error0B;
		}
			else
		{
			ErrorIntB=0;
		}
			
			OutA=KpA*Error0A+KiA*ErrorIntA+KdA*(Error0A-Error1A);
			OutB=KpB*Error0B+KiB*ErrorIntB+KdB*(Error0B-Error1B);
			/*使用增量式pid则打开下面注释，将上面注释掉*/
			//OutA+=KpA*(Error0A-Error1A)+KiA*Error0A+KdA*(Error0A-2*Error1A+Error2A);
			//OutB+=KpB*(Error0B-Error1B)+KiB*Error0B+KdB*(Error0B-2*Error1B+Error2B);
		
			if(OutA>MaxA) {OutA=MaxA;}
			if(OutB>MaxB) {OutB=MaxB;}
			
			Motor_SetPWM9_1(-OutA);
			Motor_SetPWM9_2(-OutB);
		}
	}
}