#ifndef Omnidirectional_Wheel_H
#define Omnidirectional_Wheel_H

#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "stdint.h"
#include "math.h"

void motor_move_setvmmps(float  wheel[4],float dstVmmps_X,float dstVmmps_Y,float dstVmmps_W);

#endif



