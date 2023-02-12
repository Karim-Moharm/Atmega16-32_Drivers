/*
 * DC_Motor_driver.h
 *
 * Created: 12/4/2022 5:18:10 PM
 *  Author: Karim Moharm
 */ 


#ifndef DC_MOTOR_DRIVER_H_
#define DC_MOTOR_DRIVER_H_

#include "MCAL/DIO/DIO_interface.h"
#include "data_types.h"


/*
 * to control direction
 */
#define MOTOR_PORT_CONTROL PORTA
#define MOTOR_PIN0_CONTROL PINA1   /* IN1 in L293D  */
#define MOTOR_PIN1_CONTROL PINA2  /* IN2 in L293D */

typedef enum{
	motor_stop,motor_cw,motor_c_cw
	}DC_Motor_state;
	
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * function responsible for initialize DC-motor
 */
void DC_Motor_Init(void);

/*
 * setup DC-motor state as clock wise or counter-clock wise or stop
 * setup DC-motor speed, input speed should be from 0:100
 */
void DC_Motor_Rotate(DC_Motor_state state,u8 speed);



#endif /* DC_MOTOR_DRIVER_H_ */