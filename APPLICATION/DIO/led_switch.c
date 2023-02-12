/*
 * led_switch.c
 *
 * Created: 10/20/2022 11:19:50 AM
 *  Author: Karim Moharm
 */ 
#include "Mem_Map.h"
#include "data_types.h"
#include  "bitwise.h"
#include "MCAL/DIO/DIO_interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>



u8 x=1;
u8 count=0;
v8 i;


void LED (void) 
{
	
	DIO_INIT();
	
	while (1)
	{
		
		DIO_writePin(PIND1,HIGH);
		_delay_ms(300);
		DIO_writePin(PIND1,LOW);
		_delay_ms(300);
		DIO_writePin(PIND7,HIGH);
		DIO_writePin(PINB1,LOW);


	if(DIO_ReadPin(PINC2)==LOW)
	{
		DIO_togglepin(PINA2);
		while(DIO_ReadPin(PINC2)==LOW);
	}
	
		
		if (DIO_ReadPin(PINC0)==LOW)	// pull up
		{
			DIO_writePorts(PA,255);
		}
		
		if(DIO_ReadPin(PINC1)==LOW)
			DIO_writePorts(PA,0);	
		
		if(DIO_ReadPin(PINC2)==LOW)
		{
			DIO_togglepin(PINA2);
			while(DIO_ReadPin(PINC2)==LOW);
		}
		
		
		if (DIO_readPorts(PC)==0b11111111)			// NOT WORKING......
		{
			count++;
			DIO_writePorts(PA,count);
			while (DIO_readPorts(PC)==0b11111111);
		}
		
		if (DIO_ReadPin(PINC6)==HIGH)
		{
			for(i=0;i<8;i++)
			{
				DIO_writePorts(PA,x);
				x=x<<1;
			} x=64;
			
			for (i=0;i<8;i++)
			{
				DIO_writePorts(PA,x);
				x=x>>1;
				
			} x=2;
			
		}
			


		}
	
}