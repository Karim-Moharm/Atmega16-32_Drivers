
/*
 * Created: 10/21/2022 11:20:07 AM
 *  Author: Karim Moharm
 */ 

#include "data_types.h"
#include "servo_app/servo_app.h"
#include "Timer/Timer.h"
void servo (void)
{
	Timer1_INIT(TIMER1_fast_PWM_ICR1,CLK_8,OC1A_NON_Inverting,OC1B_NON_Inverting);
	Servo_INIT();

	u16 a=0;
	_delay_ms(1000);
	while(1)
	{
		Servo_set_Angle(a);
		_delay_ms(1000);
		a+=10;  // every second the angle increases by 10
		if(a>180)
		{
			a=0;
		}
		
	}
	
	
}








