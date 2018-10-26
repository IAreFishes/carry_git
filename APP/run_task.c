/*************************************************************************************
*	@file			run_task.c
* @author	 	Ekko
*	@version 	V1.0
*	@date			2018/9/22
* @brief		NONE
*************************************************************************************/
/* Includes ------------------------------------------------------------------------*/
#include "run_task.h"

/* External variables --------------------------------------------------------*/
extern Pixy_Color Pixy;

pid_t pid_GM25_spd[4];
GM_25_type GM_25_spd_set;
GM_25_type GM_25;
/* Internal variables --------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/



void Chassis_pid_init(void)
{
		for(int i=0; i<4; i++)
		{ 
			PID_struct_init(&pid_GM25_spd[i], POSITION_PID, 5000, 2000,
										1.0f,	0.1f,	5.0f ,0.0f ,0.0f	);  //4 motos angular rate closeloop.
		}
	}
	
	
void Run_Task(void const * argument)
{
	static float wheel[4]={0,0,0,0};
	static int16_t Val[4]={0,0,0,0}; 
	Chassis_pid_init();
	
  for(;;)
  {
		
   motor_move_setvmmps(wheel,GM_25_spd_set.dstVmmps_X,GM_25_spd_set.dstVmmps_Y,GM_25_spd_set.dstVmmps_W);

   for(int i=0;i<4;i++)
		{
		   pid_calc(&pid_GM25_spd[i],GM_25.motor_count[i],wheel[i] );
			 Val[i] += pid_GM25_spd[i].pout;
		}
		
			if(wheel[0]>0)
			{
				 Motor1(Val[0] ,0);
			}else  Motor1(0,Val[0]);
			
			if(wheel[1]>0)
			{
				Motor1(Val[1] ,0);
			}else  Motor1(0,Val[1]);
		
			if(wheel[2]>0)
			{
			  Motor1(Val[2] ,0);
			}else  Motor1(0,Val[2]);
			
			if(wheel[3]>0)
			{
			  Motor1(Val[3] ,0);
			}else  Motor1(0,Val[3]);
		
			
			
    LCD_Display_int(wheel[0],1,1);
    osDelay(5);
  }
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
