
/*
 * Created: 10/21/2022 11:20:07 AM
 *  Author: Karim Moharm
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>

//#include "../../MCAL/ADC/ADC.h"
#include "LCD.h"    
#include "LCD_config.h" 
#include "Mem_Map.h"     
#include "../../MCAL/External Interrupt/EX_Int.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/Timer/Timer.h"
#include "../SERVIES/Timer/tmr_services.h"   
#include "../../HAL/Servo/servo.h"
#include "APPLICATION/servo_app/servo_app.h"
#include "../../HAL/Sensors/Ultra-sonic_Driver/ULTRA_SONIC.h"
#include "MCAL/USART/uart_driver.h"
#include "SERVIES/UART/UART_Services.h"
#include "MCAL/SPI/spi_driver.h"
#include "HAL/DC Motor/DC_Motor_driver.h"  
#include "MCAL/PWM/pwm.h" 


#include "../../MCAL/ADC/ADC.h"    
#include "SERVIES/ADC/ADC_services.h"  
 
/*
#include "HAL/Sensors/Sensors.h"
*/
//#include "APPLICATION/KeyPad/KeyPad_main.h"
//#include "APPLICATION/LCD/ASCII/ASCii.h"
//#include "APPLICATION/LCD/LCD_test/LCD_main.h"
//#include "APPLICATION/ADC/ADC_main.h"
//#include "APPLICATION/calculator/calculator.h"
//#include "APPLICATION/Interrupt/interrupt_main.h"

int main(void)
{  
	DIO_INIT();
	LCD_INIT();
	ADC_INIT(Vref_AVCC,DIV_128);
	ADC_Enable();
	
	u16 data;
	u8 ADC_reading[]="ADC";
	LCD_WriteString_IN(0,0,ADC_reading);
	LCD_WriteString_IN(1,0,"reading");
	while(1)
	{
		data=ADC_read_Channel(ADC0);
		LCD_SetPos(1,11);
		LCD_WriteNumber_S16(data);
		
		
	}
		
		
}
	
	
	
	









