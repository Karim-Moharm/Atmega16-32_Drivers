/*
 * LCD_main.c
 *
 * Created: 10/23/2022 6:06:13 PM
 *  Author: Karim Moharm
 */ 


#define F_CPU 8000000UL
#include <util/delay.h>

#include "MCAL/DIO/DIO_interface.h"
#include "LCD.h"
#include "data_types.h"
#include "LCD_config.h"


void LCD_main (void)
{
	
	
	DIO_INIT();
	LCD_INIT();
	
	
	
	/*LCD_WriteData('k');
	LCD_Writechar('a');
	LCD_Writechar('r');
	LCD_WriteData('i');
	LCD_WriteData('m');*/
	
		
	
	  /*LCD_WriteString ("8*5  =");
	  LCD_SetDisplay(1,8);
	  LCD_WriteNumber(5*8);
	  
	  LCD_SetDisplay(2,0);
	  LCD_WriteString("100/8=");
	  LCD_SetDisplay(2,8);
	  LCD_WriteNumber(100/8);*/
	  
	 
	/*LCD_WriteNumber(2001200270783204); */
	
	/*u8 name[]="**KARIM**>15";*/
	
	/* LCD_WriteString(name); */
	
	/*LCD_correctPattern();  // creating correct sign 
	LCD_SetDisplay(1,0);  // called after creating a pattern 
	LCD_WriteData(0);
	*/
		/*LCD_WriteBinary(12);
		LCD_SetDisplay(2,0);
		LCD_writeBinary_2(12);
	
	*/
		
		
		
		u8 x=0;		// set LCD_PORT to PA in LCD_config,  // RS,RW,EN  on PINB0, PINB1 ,PINB2
		u8 str[]="num: ";
		LCD_SetPos(0,0);
		LCD_WriteString(str);
		u8 str2[]="Bin: ";
		LCD_SetPos(1,0);
		LCD_WriteString(str2);
		
		
		
		// LCD_WriteNumber(12054);
		
	/*	LCD_writeNumber_IN(1,5,-487678);*/
	while(1)
	{
		
		
		LCD_writeNumber_IN(0,5,x);
		LCD_SetPos(1,5);
		LCD_WriteBinary(x++);
		_delay_ms(500);		//x++;
		
				/*LCD_SetDisplay(1,5);	// line 1,  5th column
				LCD_WriteString(name);
				_delay_ms(600);
				LCD_Clear();
				LCD_SetDisplay(1,5);
				LCD_WriteNumber(1542001);
				_delay_ms(200);
				LCD_Clear();*/
				
		
			
			
				/*if(DIO_ReadPin(PIND0)==LOW)
				{
					
					while(DIO_ReadPin(PINC0)==LOW);
					LCD_Clear();
					
				}
			
			
		*/
	
}

	
	
}