#include "stm32f10x.h"
#include "PWM.h"

void Buzzer_Init(void)
{
	PWM_Init();
}

void Buzzer_SetTone(uint32_t tone)
{
	PWM_SetPrescaler(72000000 / (tone * 100) + 1);
}
