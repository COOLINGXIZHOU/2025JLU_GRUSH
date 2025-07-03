#include "headfile.h"

//uint8_t Key_Num;

//uint8_t Key_GetNum(void)
//{
//	uint8_t Temp;
//	if (Key_Num)
//	{
//		Temp = Key_Num;
//		Key_Num = 0;
//		return Temp;
//	}
//	return 0;
//}

//uint8_t Key_GetState(void)
//{
//	if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_1) == 0)
//	{
//		return 1;
//	}
//	if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_2) == 0)
//	{
//		return 2;
//	}
//	if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_3) == 0)
//	{
//		return 3;
//	}
//	if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) == 0)
//	{
//		return 4;
//	}
//	return 0;
//}

//void Key_Tick(void)
//{
//	static uint8_t Count;
//	static uint8_t CurrState, PrevState;
//	
//	Count ++;
//	if (Count >= 20)
//	{
//		Count = 0;
//		
//		PrevState = CurrState;
//		CurrState = Key_GetState();
//		
//		if (CurrState == 0 && PrevState != 0)
//		{
//			Key_Num = PrevState;
//		}
//	}
//}
#define blank_time 50
uint8_t B1_state;
uint8_t B1_laststate=0;
uint8_t B2_state;
uint8_t B2_laststate=0;
uint8_t B3_state;
uint8_t B3_laststate=0;
uint8_t B4_state;
uint8_t B4_laststate=0;

uint8_t B1_FLAG;
uint16_t B1_BLANK;
uint8_t B1_DOUBLE;

uint8_t B2_FLAG;
uint16_t B2_BLANK;
uint8_t B2_DOUBLE;

uint8_t B3_FLAG;
uint16_t B3_BLANK;
uint8_t B3_DOUBLE;

uint8_t B4_FLAG;
uint16_t B4_BLANK;
uint8_t B4_DOUBLE;

uint8_t KeyNum;
void Key_Scan(void)
{
	B1_state=HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_1);
	B2_state=HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_2);
	B3_state=HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_3);
	B4_state=HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_4);
//单击或者双击
    if(B1_FLAG==0)
    {
      if(B1_state ==1 && B1_laststate ==0 )
        {
            B1_FLAG=1;
        }  
    }
    if(B1_FLAG==1)
    {
			B1_BLANK++;
      if(B1_state ==0 && B1_laststate ==1 )
        {
            B1_DOUBLE=1;
        }  
    }
    if(B1_BLANK>=blank_time)
    {
        if(B1_DOUBLE)
            KeyNum=5;
        else
            KeyNum=1;
				B1_BLANK=0;
        B1_DOUBLE=0;
        B1_FLAG=0;
    }
//单击或者双击
    if(B2_FLAG==0)
    {
      if(B2_state ==1 && B2_laststate ==0 )
        {
            B2_FLAG=1;
        }  
    }
    if(B2_FLAG==1)
    {
			B2_BLANK++;
      if(B2_state ==0 && B2_laststate ==1 )
        {
            B2_DOUBLE=1;
        }  
    }
    if(B2_BLANK>=blank_time)
    {
        if(B2_DOUBLE)
            KeyNum=6;
        else
            KeyNum=2;
				B2_BLANK=0;
        B2_DOUBLE=0;
        B2_FLAG=0;
    }
//单击或者双击
    if(B3_FLAG==0)
    {
      if(B3_state ==1 && B3_laststate ==0 )
        {
            B3_FLAG=1;
        }  
    }
    if(B3_FLAG==1)
    {
			B3_BLANK++;
      if(B3_state ==0 && B3_laststate ==1 )
        {
            B3_DOUBLE=1;
        }  
    }
    if(B3_BLANK>=blank_time)
    {
        if(B3_DOUBLE)
            KeyNum=7;
        else
            KeyNum=3;
				B3_BLANK=0;
        B3_DOUBLE=0;
        B3_FLAG=0;
    }
//单击或者双击
    if(B4_FLAG==0)
    {
      if(B4_state ==1 && B4_laststate ==0 )
        {
            B4_FLAG=1;
        }  
    }
    if(B4_FLAG==1)
    {
			B4_BLANK++;
      if(B4_state ==0 && B4_laststate ==1 )
        {
            B4_DOUBLE=1;
        }  
    }
    if(B4_BLANK>=blank_time)
    {
        if(B4_DOUBLE)
            KeyNum=8;
        else
            KeyNum=4;
				B4_BLANK=0;
        B4_DOUBLE=0;
        B4_FLAG=0;
    }    
    B1_laststate=B1_state;
    B2_laststate=B2_state;
    B3_laststate=B3_state;
    B4_laststate=B4_state;
		
}
