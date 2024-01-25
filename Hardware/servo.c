#include "stm32f10x.h"
#include "pwm.h"
void Servo_Init(void)
{
    Pwm_Init();
}
void Servo_SetAngle(float Angle)
{
	PWM_SetCompare2(Angle / 180 * 2000 + 500);
}