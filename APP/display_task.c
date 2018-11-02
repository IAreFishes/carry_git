/*************************************************************************************
*	@file			display_task.c
* @author	 	Ekko
*	@version 	V1.0
*	@date			2018/9/22
* @brief		NONE
*************************************************************************************/
/* Includes ------------------------------------------------------------------------*/
#include "display_task.h"

/* External variables --------------------------------------------------------*/


/* Internal variables --------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

void Display_Task(void const * argument)
{
		
	//��λ���Ƕȣ����ƽǶ�0~300
	//      RPM�����ת��114RPM
	float servo[7][6] = {
					{180,290,230,100,100,50},//�ȶ���̬
					{100,100,100,100,100,50},//ץȡ���
					{100,100,100,100,100,50},//�������
					{100,100,100,100,100,50},//�м���̬
					{100,100,100,100,100,50},//�ſ�צ��
					{100,100,100,100,100,50},//ץ��צ��
					{180,290,240,100,100,50},//Ԥ����̬(��չ��̬)
					};
	servo_set(servo);
					
  for(;;)
  {
		static uint8_t LED3_NUM = 0;
		
		if(LED3_NUM > 30)
		{
			HAL_GPIO_TogglePin(LED3_GPIO_Port,LED3_Pin);
			LED3_NUM = 0;
		}
		
		LED3_NUM++;
		
    LCD_Display_float(LB_1.id,1,1);
		LCD_Display_float(LB_1.direction,1,2);
		LCD_Display_float(LB_1.distance,1,3);
		LCD_Display_float(LB_1.site,1,4);

    //LCD_Display_int(angle * 0.293,1,1);
		


		StretchPose();	//0

     osDelay(5);
  }
  
}




/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

