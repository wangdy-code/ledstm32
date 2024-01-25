#include "stm32f10x.h"
#include "Timer.h"
#include "OLED.h"
#include "encoder.h"
#include "pwm.h"
#include "delay.h"
int main()
{
    OLED_Init();
    Pwm_Init();
    Delay_Init();
    while (1) {
        for (uint16_t i = 0; i < 100; i++) {
            PWM_SetCompare1(i);
            Delay_ms(10);
        }
        for (uint16_t i = 0; i < 100; i++) {
            PWM_SetCompare1(100-i);
            Delay_ms(10);
        }
    }
    return 0;
}
