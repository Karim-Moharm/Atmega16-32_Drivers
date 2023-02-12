/*
 * tmr_services.h
 *
 * Created: 11/4/2022 10:45:31 AM
 *  Author: YN
 */ 

#include "../../MCAL/Timer/Timer.h"
#ifndef TMR_SERVICES_H_
#define TMR_SERVICES_H_

void Timer0_setInterrupt_us_8_(u8 time,void(*local_ptr)(void));
void Timer0_setInterrupt_ms(u8 time,void(*local_ptr)(void));
void Timer0_setInterrupt_us_16_(u16 time,void(*local_ptr)(void));
void func_OC (void);
void PWM_measure (u32 *freq,u8 *duty_cyc);


#endif /* TMR_SERVICES_H_ */