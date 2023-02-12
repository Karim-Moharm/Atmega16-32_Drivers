/*
 * servo.c
 *
 * Created: 11/6/2022 3:53:04 PM
 *  Author: YN
 */ 

#include "Servo/servo.h"

void Servo_INIT(void)
{
	
	ICR1=19999;    // max servo ticks is 20000
	SERVO_PIN=999;   // when servo is 1000us the angle is zero 	
}
void Servo_set_Angle(u8 angle)
{
	SERVO_PIN=(((u32)angle*1000)/180)+999;
}