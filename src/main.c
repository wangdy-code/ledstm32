#include "stm32f10x.h"
#include "Timer.h"
#include "OLED.h"
#include "encoder.h"
#include "pwm.h"
#include "delay.h"
#include "servo.h"
int main()
{
    OLED_Init();
    Delay_Init();
    Servo_Init();

    while (1) {
        for (uint16_t i = 0; i <= 180; i += 1) {
            Servo_SetAngle(i);
            OLED_ShowString(1, 1, "Angle: ");
            OLED_ShowNum(1, 9, i,3);
            Delay_ms(100);
        }
        for (uint16_t i = 0; i <= 180; i += 1) {
            Servo_SetAngle(180 - i);
            OLED_ShowString(1, 1, "Angle: ");
            OLED_ShowNum(1, 9,180 - i,3);
            Delay_ms(100);
        }
    }
    return 0;
}
