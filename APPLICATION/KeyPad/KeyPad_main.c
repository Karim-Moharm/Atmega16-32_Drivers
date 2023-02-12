/*
 * KeyPad_main.c
 *
 * Created: 10/24/2022 4:55:52 PM
 *  Author: Karim Moharm
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>


#include "MCAL/DIO/DIO_interface.h"
#include "LCD.h"
#include "data_types.h"
#include "HAL/Key Pad/KeyPad.h"
#include "HAL/Key Pad/KeyPad_config.h"


void KEYPAD (void)
{
	u8 x=255;
	DIO_INIT();
	LCD_INIT();
	
	
	u8 msg[]="keypad...";
	LCD_WriteString(msg);
	LCD_SetPos(1,0);	
	
	while(1)
	{
		x=KP_getButton();
		if (x!=DEFAULT_KEY)
		{	
		LCD_WriteChar(x);
		}
			
	}
		
	
}
