#ifndef __HEADFILE_H__
#define __HEADFILE_H__

#include "main.h"
#include "tim.h"
#include "gpio.h"
#include "OLED.h"
#include "OLED_Data.h"
#include "Delay.h"
#include "LED.h"
#include "TIM.h"
#include "usart.h"
#include "tim.h"
#include "Key.h"
#include "PWM.h"
#include "Motor.h"
#include "Encoder.h"
#include <stdio.h>
#include <stdarg.h>
#include "string.h"
#include "math.h"
#include "Serial.h"
#include "Huidu.h"
#include "MPU6050.h"
#include "MPU6050_Reg.h"
#include "MyI2C.h"
//#include "dma.h"
#include "ble.h"
extern int16_t location;
extern int16_t speed;
extern TIM_HandleTypeDef htim1;

extern TIM_HandleTypeDef htim2;

extern TIM_HandleTypeDef htim4;

extern TIM_HandleTypeDef htim8;
#endif
