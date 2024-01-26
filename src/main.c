#include "stm32f10x.h"
#include "Timer.h"
#include "OLED.h"
#include "encoder.h"
#include "pwm.h"
#include "delay.h"
#include "Motor.h"
#include "key.h"
int main()
{
    OLED_Init();
    Motor_Init();
    KEY_Init();
    OLED_ShowString(1, 1, "Speed:");
    int16_t speed = -50;
    OLED_ShowSignedNum(1, 8, speed, 2);
    Motor_SetSpeed(speed);
    while (1) {
        if (Key_GetNum() == 1) {
            speed += 10;
            Motor_SetSpeed(speed);
            OLED_ShowSignedNum(1, 15, speed, 3);
        }
    }
    return 0;
}
