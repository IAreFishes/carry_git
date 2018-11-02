/*************************************************************************************
*	@file			run_task.h
* @author	 	Ekko
*	@version 	V1.0
*	@date			2018/9/22
* @brief		NONE
*************************************************************************************/
#ifndef __LOCATIONTASK_H
#define __LOCATIONTASK_H

/* Includes ------------------------------------------------------------------*/
#include "cmsis_os.h"
#include "string.h"
#include "bsp.h"
#include "math.h"
/* Private function prototypes -----------------------------------------------*/

//��λ״̬
#define Location_Busy 0     //��λ����æ(��ǰqti���ں������Ϸ������ڲ��ܱ��жϵ�״̬)
#define Location_Ok		1

//qit������״̬
#define QTI1 			HAL_GPIO_ReadPin(QTI1_GPIO_Port,QTI1_Pin)
#define QTI2 			HAL_GPIO_ReadPin(QTI2_GPIO_Port,QTI2_Pin) 
#define Black     GPIO_PIN_SET
#define	White			GPIO_PIN_RESET										 //��ʱ

 //���׼״̬�仯�Ƚϣ�����0��ʾ���
#define CMP_X(x)		memcmp(std_x,x,3)								
#define CMP_Y(y)		memcmp(std_y,y,5)

extern float x_now;
extern float y_now;
extern float Qti1_flag[5];
extern float Qti2_flag[5];

//���к������������
void Location_Task(void const * argument);





#endif
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
