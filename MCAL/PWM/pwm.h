/*
 * pwm.h
 *
 * Created: 12/4/2022 9:14:48 PM
 *  Author: YN
 */ 


#ifndef PWM_H_
#define PWM_H_

#include "data_types.h"

/*
 * Function responsible for generating PWM signal on  OC0/PB3
 */
void PWM_Timer0_Start(u8 set_duty_cycle);



#endif /* PWM_H_ */