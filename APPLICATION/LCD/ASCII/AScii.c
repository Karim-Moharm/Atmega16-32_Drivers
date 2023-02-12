/*
 * AScii.c
 *
 * Created: 10/22/2022 5:05:30 PM
 *  Author: Karim Moharm
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>


#include "MCAL/DIO/DIO_interface.h"
#include "LCD.h"
#include "LCD_config.h"
#include "data_types.h"


void ASCII (void)
{
	DIO_INIT();
	LCD_INIT();
	
	
	
	u8 str1[]="char : ";
	u8 str2[]="ASCII: ";
	LCD_SetPos(0,0);
	LCD_WriteString (str1);
	LCD_SetPos(1,0);
	LCD_WriteString(str2);
	
	u8  count='A';
	
	
	while (1)
	{
		LCD_SetPos(0,8);
		LCD_WriteData(count);
		LCD_SetPos(1,8);
		LCD_WriteNumber_S32(count);
		count++;
		_delay_ms(500);
		
	}
		

}


