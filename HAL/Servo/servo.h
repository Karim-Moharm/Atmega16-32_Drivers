/*
 * servo.h
 *
 * Created: 11/6/2022 3:53:24 PM
 *  Author: YN
 */ 

#include "Timer/Timer.h"

#ifndef SERVO_H_
#define SERVO_H_


void Servo_INIT(void);
void Servo_set_Angle(u8 angle);
#define SERVO_PIN		OCR1A




#endif /* SERVO_H_ */