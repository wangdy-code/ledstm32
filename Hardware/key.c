#include "stm32f10x.h"
#include "delay.h"
void KEY_Init(GPIO_TypeDef *gpiox, uint16_t pin, GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode  = mode;
    GPIO_InitStructure.GPIO_Pin   = pin;
    GPIO_InitStructure.GPIO_Speed = speed;
    GPIO_Init(gpiox, &GPIO_InitStructure);
    // GPIO_SetBits(gpiox, pin);
}

uint8_t Key_GetNum(GPIO_TypeDef *gpiox, uint16_t pin)
{
    uint8_t keyNum = 0;
    if (GPIO_ReadInputDataBit(gpiox, pin) == 0) {
        Delay_ms(20);
        while (GPIO_ReadInputDataBit(gpiox, pin) == 0) {
            /* code */
        }
        Delay_ms(20);
        keyNum = 1;
    }
    return keyNum;
}