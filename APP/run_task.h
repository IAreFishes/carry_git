/*************************************************************************************
*	@file			run_task.h
* @author	 	Ekko
*	@version 	V1.0
*	@date			2018/9/22
* @brief		NONE
*************************************************************************************/
#ifndef __RUNTASK_H
#define __RUNTASK_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "pid.h"
#include "rbc_lcd.h"
#include "cmsis_os.h"
#include "Pixy_Camera.h"
#include "Motor_USE_TIM.h"
#include "Omnidirectional_Wheel.h"

/* Private function prototypes -----------------------------------------------*/
typedef struct
{
	float dstVmmps_Y;
	float dstVmmps_X;
	float dstVmmps_W;
	char  flag;
	int16_t motor_count[4];
} GM_25_type;



void Run_Task(void const * argument);
void Chassis_pid_init(void);

extern GM_25_type GM_25;
extern GM_25_type GM_25_spd_set;
extern int16_t motor_count[4];//电机编码器计数





#endif
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
