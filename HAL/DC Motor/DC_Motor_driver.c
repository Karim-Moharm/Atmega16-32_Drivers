/*
 * DC_Motor_driver.c
 *
 * Created: 12/4/2022 5:17:49 PM
 *  Author: Karim Moharm
 */ 

#include "DC_Motor_driver.h"
#include "MCAL/PWM/pwm.h"

void DC_Motor_Init(void){
	/* put the pins connected to IN1 & IN2 in the motor driver as output */ /*  pins responsible for direction */
	DIO_initPin(MOTOR_PIN0_CONTROL,OUTPUT);
	DIO_initPin(MOTOR_PIN1_CONTROL,OUTPUT);
	
	/* Motor is stop at the beginning */
	DIO_writePin(MOTOR_PIN0_CONTROL, LOW);
	DIO_writePin(MOTOR_PIN1_CONTROL, LOW);  
	
	
}

void DC_Motor_Rotate(DC_Motor_state state,u8 speed){

	 /* setup DC-motor state as clock wise or counter-clock wise or stop  */

	switch(state){
		case motor_stop:		
		DIO_writePin(MOTOR_PIN0_CONTROL, LOW);
		DIO_writePin(MOTOR_PIN1_CONTROL, LOW);
		break;
		case motor_c_cw:   // motor rotate with the clock wise 
		DIO_writePin(MOTOR_PIN0_CONTROL, LOW);
		DIO_writePin(MOTOR_PIN1_CONTROL, HIGH);
		break;
		case motor_cw:		// motor rototas with counter clock wise 
		DIO_writePin(MOTOR_PIN0_CONTROL, HIGH);
		DIO_writePin(MOTOR_PIN1_CONTROL, LOW);
		break;
	}

/*
 * setup DC-motor speed, input speed should be from 0:100
 */
	u8 duty_cycle= (u8) ( (speed/100.0f)*255 ) ;
	PWM_Timer0_Start(duty_cycle); //generate duty cycle
/*
*	if u put the speed as 50 (half speed of motor) the pwm will be 128... so the motor will rotate with its half speed
*/
}