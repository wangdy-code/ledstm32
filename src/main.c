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
#include "led.h"
#include "delay.h"
#include "key.h"
#include "buzzer.h"
#include "lightSensor.h"

#define LED_PERIPH RCC_APB2Periph_GPIOA
#define LED_PORT   GPIOA
#define LED_PIN    GPIO_Pin_0

#define KEY_PIN    GPIO_Pin_1

int main()
{
    Delay_Init();
    KEY_Init(GPIOB, KEY_PIN, GPIO_Mode_IPU, GPIO_Speed_50MHz);
    LED_Init(GPIOA, LED_PIN, GPIO_Mode_Out_PP, GPIO_Speed_50MHz);
    Buzzer_Init(GPIOB, GPIO_Pin_12, GPIO_Mode_Out_PP, GPIO_Speed_50MHz);
    LightSensor_Init(GPIOB, GPIO_Pin_13, GPIO_Mode_IPU, GPIO_Speed_50MHz);

    while (1) {
        if (LightSensor_Get(GPIOB, GPIO_Pin_13) == 1) {
            Buzzer_ON(GPIOB, GPIO_Pin_12);
            LED_ON(GPIOA,GPIO_Pin_0);
        } else {
            Buzzer_OFF(GPIOB, GPIO_Pin_12);
            LED_OFF(GPIOA,GPIO_Pin_0);
        }
    }
}
