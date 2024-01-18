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
#include "delay.h"
int main()
{
    OLED_Init();
    Delay_Init();
    while (1) {
        OLED_ShowString(1, 1, "Hello World !");
        for (uint16_t i = 0; i < 1000; i++) {

            OLED_ShowNum(2, 1, i, 3);
            Delay_ms(100);
        }
    }
}
