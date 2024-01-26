#include "stm32f10x.h"
#include "Timer.h"
#include "OLED.h"
#include "encoder.h"
#include "pwm.h"
#include "delay.h"
#include "IC.h"
int main()
{
    IC_Init();
    OLED_Init();
    Pwm_Init();
    Delay_Init();

    OLED_ShowString(1, 1, "Freq:00000Hz");
    OLED_ShowString(2, 1, "Duty:00\%");
    PWM_SetPrescaler(720 - 1);
    PWM_SetCompare1(99);
    while (1) {
        OLED_ShowNum(1, 6, IC_GetFreq(), 5);
        OLED_ShowNum(2, 6, IC_GetDuty(), 2);
    }
    return 0;
}
