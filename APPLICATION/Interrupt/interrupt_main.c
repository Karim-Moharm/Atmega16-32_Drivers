/*
 * interrupt_main.c
 *
 * Created: 10/30/2022 9:14:38 PM
 *  Author: YN
 */ 



#define F_CPU 8000000UL
#include <util/delay.h>
#include "interrupt_main.h"
#include "LCD.h"
#include "MCAL/DIO/DIO_interface.h"
#include "Mem_Map.h"
#include "External Interrupt/EX_Int.h"

static volatile  u8 flag=0;
static volatile u8 i=0;

void fun_int0 (void)   // function of interrupt 
{
	DIO_togglepin(PINA0);
	flag=1;
	
}

void fun_int1(void)		 // function of interrupt 
{
	DIO_writePin(PINA1,HIGH);
	flag=2;
}

void Interrupt (void)
{
	sei();   // open the global interrupt
	DIO_INIT();
	LCD_INIT();
	EXInt_SETCallBack(EX_INT0,fun_int0);   
	EXInt_Sense(EX_INT0,Rising_Edge);
	EXInt_Enable(EX_INT0);
	
	EXInt_SETCallBack(EX_INT1,fun_int1);
	EXInt_Sense(EX_INT1,Falling_Edge);
	EXInt_Enable(EX_INT1);
	
	
	while(1)

	{
		
		 // close the global interrupt
		LCD_WriteString_IN(0,0,"Karim");
		
		LCD_writeNumber_IN(1,0,i);
		i++;
		_delay_ms(300);
		if(i==10)
		{
			i=0;
		}
		if(i==5)
		{
			LCD_writeChar_IN(1,8,'*');
			
		}
		if(i==8)
		{
			LCD_Clear();
			_delay_ms(1000);
		}
		if(flag==1)
		{	
			LCD_Clear();
			LCD_WriteString_IN(0,8,"INT0");
		}
		else if(flag==2)  // for INT1
		{
			LCD_WriteString_IN(1,9,"INT1");
			
		}
		
		
	}	

	
	
}

ISR(BAD_vect)
{
	DIO_togglepin(PINB7);   // this pin toggle in case of bad interrupt ( any enabled interrupt without code or without ISR function)
}






