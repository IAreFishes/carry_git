/*************************************************************************************
*	@file			correct_task.c
* @author	 	NCURM
*	@version 	V1.0
*	@date			2018/9/22
* @brief		

	  `''```''```''```''```''```''```''`````  
		`                           :``:.    '
		`                         ''    .'.  '
		`                         `.QTI1 ''  '
		`     '`'':               '`     ''  '��ͷ
		`   `'     ''              `!;:!;.   '
		`   ``QTI2 ``                        '
		`   `'     ''                        '
		`     '!||:                          '
		``''```''```''```''```''```''```''```` 
		
		��������Ҫ���ⲿ��Ϣ:	1. ����run_task�ĳ����˶�״̬
													2. �����жϵ�qit״̬
													
		����������ṩ����Ϣ:	1. ��ǰ���µ�������Ϣ
													2. ��λ�����״̬�������״̬ΪLocation_Busyʱ��ֹת�䳵���˶�����

*************************************************************************************/
/* Includes ------------------------------------------------------------------------*/
#include "location_task.h"

/* External variables --------------------------------------------------------*/
//����ǰ���˶�״̬
extern enum car_state Car_State; 
//������
extern osThreadId location_taskHandle;

/* Internal variables --------------------------------------------------------*/

//��λ�����õĵ�ǰ���µ�����
float x_now = 0.5; //��ʼֵΪ0.5
float y_now = 0.5;
//qti״̬�ı任���
float Qti1_flag[5] = {White};
float Qti2_flag[5] = {White};
//��׼����¾������ߵ�״̬�仯˳��
float std_x[3] = {White,Black,White};			 				 //�����ǵ���
float std_y[5] = {White,Black,White,Black,White};	 //������˫�����
//��λ״̬
uint8_t location_sate = Location_Ok;
/* Private function prototypes -----------------------------------------------*/

/*
** Descriptions: X����qit״̬ƥ�亯��
** Input: 	
**			 car_state  �����˶�״̬ 
**					
**					
** Output: location_ok    ��λ���
**				 location_busy	qti���ڹ��ߣ���ֹ����
*/
int  X_Match(enum car_state state)
{
	float unit = 0;
	float *buff;
	double intpart = 0;
	
	if(state == x_pos)//x������
	{
		unit = 0.5;
	}
	else
	{
		unit = -0.5;		
	}
	
	if(modf(x_now,&intpart) == 0.5) //��ʾ��С������qti1����ʾ������q
	{
		buff = Qti1_flag;
	}
	else		//qti2����ʾС����
	{
		buff = Qti1_flag;
	}
	
		if(CMP_X(buff) == 0) //Ϊ���ʾƥ��ɹ�������
	{
		x_now += unit;
		return Location_Ok;
	}
	else
	{
		//���ڹ��߽�ֹ����
		return Location_Busy;
	}
}
/*
** Descriptions: Y����qit״̬ƥ�亯��
** Input: 	
**			 car_state  �����˶�״̬ 
**					
**					
** Output: location_ok    ��λ���
**				 location_busy	qti���ڹ��ߣ���ֹ����
*/
int Y_Match(enum car_state state)
{
	float unit = 0;
	
	if(state == y_pos)//y������
	{
		unit = 0.5;
	}
	else
	{
		unit = -0.5;		
	}
	
	if(y_now - (int)y_now > 0) //��ʾ��С������qti1����ʾ������q
	{
		if(CMP_Y(Qti1_flag) == 0)
		{
			y_now += unit;
			return Location_Ok;
		}
		else
		{
			//���ڹ��߽�ֹ����
			return Location_Busy;
		}
	}
	else		//qti2����ʾС����
	{
		if(CMP_Y(Qti2_flag) == 0)
		{
			y_now += unit;
			return Location_Ok;
		}
		else
		{
			return Location_Busy;
		}
	}

}

void Location_Task(void const * argument)
{
	uint32_t NotifyVaule;
	
	static float test = 0;
	
  for(;;)
  {
		NotifyVaule = ulTaskNotifyTake(pdTRUE,portMAX_DELAY);
		if(NotifyVaule == 1)
		{	
			NotifyVaule = 0;
			test = x_now - (int)x_now;
			switch(Car_State)
			{
				case x_pos:
									{
										HAL_GPIO_TogglePin(LED6_GPIO_Port,LED6_Pin);

										/*ƥ��״̬,����Ƿ���ߣ������ض�λ״̬*/
										location_sate = X_Match(x_pos);
									}
				break;
				case x_nag:
									{
										location_sate = X_Match(x_nag);
									}
				break;
				case y_pos:
									{
										location_sate = Y_Match(y_pos);
									}
				break;
				case y_nag:
									{
										location_sate = Y_Match(y_nag);
									}
				break;
				default: ;
			}
			 //�������һ�ι��߼ǵ�
			if(location_sate == Location_Ok)
			{
				//����ڴ�,����ƥ���ʱ�����
				memset(Qti1_flag,0,5);
				memset(Qti2_flag,0,5);
				//���¼��һ�ε�ǰqit״̬
				Qti1_flag[0] = QTI1;
				Qti2_flag[0] = QTI2;
			}
			
		}
		
  }
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
