/*
 * ULTRA_SONIC.h
 *
 * Created: 11/8/2022 10:17:20 PM
 *  Author: YN
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "Timer/Timer.h"
#include "MCAL/DIO/DIO_interface.h"
#ifndef ULTRA_SONIC_H_
#define ULTRA_SONIC_H_

typedef enum {
			ULTRASONIC_1=PIND0,
			ULTRASONIC_2=PIND1,
			ULTRASONIC_3=PIND2,
			ULTRASONIC_4=PIND3,
			ULTRASONIC_5=PIND4
	}ULTRASONIC_PIN;

u8 UltraSonic_GetDistance(ULTRASONIC_PIN US_pin);
void ultra_sonic_INIT(void);
#endif /* ULTRA_SONIC_H_ */