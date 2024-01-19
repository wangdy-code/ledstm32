/*
 * ************************************************
 *
 *              STM32 blink gcc demo
 *
 *  CPU: STM32F103C8
 *  PIN: PA1
 *
 * ************************************************
 */

#include "stm32f10x.h"

#include "OLED.h"
#include "encoder.h"

int16_t Num = 0;
int main()
{
    OLED_Init();
    Encoder_Init();
    OLED_ShowString(1, 1, "encoder");
    while (1) {
        Num += Encoder_Get();
        OLED_ShowString(2, 1, "Num: ");
        OLED_ShowSignedNum(2, 8, Num, 5);
    }
}
