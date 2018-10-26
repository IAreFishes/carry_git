#ifndef  __Motor_USE_TIM_H
#define  __Motor_USE_TIM_H

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "stdint.h"
#include "tim.h"
#include "run_task.h"

#define highspeed 200
#define lowspeed  1000



void TIM3_PWM_Init(uint32_t speed1,uint32_t speed2);
void GUN_Init(void);
void Friction_Wheel_Motor(uint32_t wheelone,uint32_t wheeltwo);
void Friction_Wheel_Motor_Stop(void);
void Motor_Count(void);
void Motor1(uint32_t speed1,uint32_t speed2);
void Motor2(uint32_t speed1,uint32_t speed2);
void Motor3(uint32_t speed1,uint32_t speed2);
void Motor4(uint32_t speed1,uint32_t speed2);
#endif
