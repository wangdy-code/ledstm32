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

#include "countSensor.h"
#include "OLED.h"


int main()
{
    OLED_Init();
    CountSensor_Init();
    OLED_ShowString(1,1,"CountSensor");
    while (1) {
        OLED_ShowString(2,1,"counts: ");
        OLED_ShowNum(2,10,CountSensor_GetCounts(),3);
        
    }
}
