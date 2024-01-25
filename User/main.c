#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "PWM.h"
#include "IC.h"
#include "Buzzer.h"

/*����¼��
PA6�����벶��ڣ�PA0�Ƿ���������ڡ�
PA6��PA0��Ƶ�ʡ�
Buzzer_SetTone�Ĺ�ʽ����д���ˡ���
*/

int main(void)
{
	OLED_Init();
	PWM_Init();
	IC_Init();
	
	OLED_ShowString(1, 1, "Freq:00000Hz");
	
	Buzzer_SetTone(200);
	
	//PWM_SetPrescaler(287 - 1);			//Freq = 72M / (PSC + 1) / 100
	PWM_SetCompare1(50);				//Duty = CCR / 100
	
	while (1)
	{
		OLED_ShowNum(1, 6, IC_GetFreq(), 5);
	}
}
