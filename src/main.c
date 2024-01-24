#include "stm32f10x.h"
#include "Timer.h"
#include "OLED.h"
#include "encoder.h"
uint16_t Num = 0;
int main()
{
    OLED_Init();
    Timer_Init();
    while (1) {
        Num =Timer_Get();
        OLED_ShowString(2, 1, "Num: ");
        OLED_ShowNum(2, 8, Num, 5);
    }
    return 0;
}
