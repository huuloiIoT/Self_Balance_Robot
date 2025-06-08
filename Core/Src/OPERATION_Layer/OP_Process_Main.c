#include "OPERATION_Layer/OP_Header_Main.h"

uint32_t Pulse = 0;

void ProcessMain(void)
{
	  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);

	  /* Set the Capture Compare Register value */
//	  htim4.Instance->CCR1 = Pulse;
	  __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, Pulse);
	  __HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_2, Pulse);
	  Pulse+= 10;
	  if(Pulse >= 800)
	  {
		  Pulse = 0;
	  }
	  HAL_Delay(500);
}
