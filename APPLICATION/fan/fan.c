
/*
 *  fan.c
 *  Created: 10/21/2022 11:20:07 AM
 *  Author: Karim Moharm
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>


#include "LCD.h"   
#include "LCD_config.h" 
#include "Mem_Map.h"   
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/Timer/Timer.h"
#include "../SERVIES/Timer/tmr_services.h" 
#include "HAL/DC Motor/DC_Motor_driver.h"  
#include "MCAL/PWM/pwm.h"  
#include "../../MCAL/ADC/ADC.h"  
#include "SERVIES/ADC/ADC_services.h"  


  
void fan (void)
{  
	DIO_INIT();
	LCD_INIT();
	ADC_INIT(Vref_AVCC,DIV_128);
	ADC_Enable();
	/*ADC_ConfigType Config={INERNAL_vref,F_CPU_CLOCK_8};
	ADC_init(&Config);*/

		/* initialize dc-motor driver */
	DC_Motor_Init();
	
	/*	starting the project */
	u8 msg1[]="computer arch";
	u8 msg2[]="project";
	u8 msg3[]="fan controlled";
	u8 msg4[]="Using LM35";
	u8 msg5[]="FAN Is";
	LCD_WriteString_IN(0,0,msg1);
	LCD_WriteString_IN(1,0,msg2);
	_delay_ms(800);
	LCD_Clear();
	LCD_WriteString_IN(0,0,msg3);
	LCD_WriteString_IN(1,0,msg4);
	_delay_ms(1000);
	LCD_Clear();
	/*print state of fan in the first line*/
	LCD_WriteString_IN(0,4,msg5);
	/*print temperature */
	LCD_SetPos(1,0);
	LCD_WriteString("T=   ");
	LCD_writeChar_IN(1,5,'C');
	/*print speed of motor  */
	LCD_WriteString_IN(1,9,"N=   ");
	LCD_writeChar_IN(1,14,'%');

	
	
	/* temp Variable to store the temperature value measured by LM35 */
	 f32 temp;      
	/* string variable to store fan working ON/OFF */
	char* fan_state="OFF";

	/*variables to store fan info */
	u8 motor_speed=0;
	u8 Motor_state=motor_stop;
	while(1)
	{
		/* get temperature from LM35 periodically */
		//temp = (LM35_getTemperature());
		/*temp=LM35_Read(ADC0);*/
		temp =ADC_read_Channel(ADC0) * 4.88;
		temp=(temp)/10;
		//temp=temp*1.4;
	
		//LCD_SetPos(1,2);
		
		LCD_writeNumber_IN(1,2,temp); 
		
		
		//_delay_ms(1000);
	

		if(temp <= 30)
		{
			/*if temperature is less than or equal 30 :
			 * change  state of fan to OFF
			 * speed of  fan = 0
			 *  */
			motor_speed=0;
			Motor_state=motor_stop;
			fan_state=" OFF";
		}
		
		else{
			/*if temperature is higher than 30 :
			 * change  state of fan to ON and control direction
			 * speed of  fan depend on temperature
			 *  */
			fan_state = " ON ";
			Motor_state=motor_cw;

			if (temp < 40) {
				motor_speed=25;
			}
			else if(temp<55) {
				motor_speed=50;
			}
			else if(temp<65) {
				motor_speed=75;
			}
			else if(temp<=150) {
				motor_speed=100;
			}
			
		}
		
		/*control speed and motor speed*/
		DC_Motor_Rotate(Motor_state,motor_speed);

		/*print fan working: OFF/ON */
		LCD_WriteString_IN(0,10,fan_state);
		/*print fan speed*/
		LCD_SetPos(1,11);
		LCD_writeNumber_3D(motor_speed);
				//LCD_writeNumber_IN(motor_speed);

		/*if(motor_speed<100)
		LCD_WriteChar(' ');*/
		
		}
		
		
	}
	
	
	
	









