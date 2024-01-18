#ifndef __KEY_H
void KEY_Init(GPIO_TypeDef *gpiox, uint16_t pin, GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed);
uint8_t Key_GetNum(GPIO_TypeDef *gpiox, uint16_t pin);
#endif // !__KEY_H