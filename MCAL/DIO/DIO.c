
/*
 * DIO.c
 *
 * Created: 10/20/2022 10:19:09 PM
 *  Author: Karim Moharm
 */ 

#include "DIO_interface.h"

void DIO_initPin(DIO_pin_type pin,DIO_pin_state status)
// EX   DIO_intpin(PINA5,in_PLUP)
{
	DIO_PORTS port= pin/8;		// port number  // 31 /8 equals 3 means port num 3  which is portD   // divided by 8 as there is 8 pins in the port 
	u8 pin_num = pin%8;        // pins numbers  // 31 %8 is 7 which is pin num 7 in  port D 
	switch(status)
	{
		case OUTPUT:
			switch (port)
			{
				case PA:   // case 0:
				set_bit(DDRA,pin_num);		break;
				case PB:	// case 1:
				set_bit(DDRB,pin_num);		break;
				case PC:
				set_bit(DDRC,pin_num);		break;
				case PD:
				set_bit(DDRD,pin_num);		break;
			} break;
		
		case IN_PLDOWN:
			switch (port)
			{
				case PA:
				clear_bit(DDRA,pin_num);
				clear_bit(PORTA,pin_num);	break;
				case PB:
				clear_bit(DDRB,pin_num);
				clear_bit(PORTB,pin_num);	break;
				case PC:
				clear_bit(DDRC,pin_num);
				clear_bit(PORTC,pin_num);	break;
				case PD:
				clear_bit(DDRD,pin_num);
				clear_bit(PORTD,pin_num);	break;
			} break;
		
		case IN_PLUP:
			switch(port)
			{
				case PA:
				clear_bit(DDRA,pin_num);
				set_bit(PORTA,pin_num);		break;
				case PB:
				clear_bit(DDRB,pin_num);
				set_bit(PORTB,pin_num);		break;
				case PC:
				clear_bit(DDRC,pin_num);
				set_bit(PORTC,pin_num);		break;
				case PD:
				clear_bit(DDRD,pin_num);
				set_bit(PORTD,pin_num);		break;
			
		} break;
		
	}

	
}

void DIO_writePin(DIO_pin_type pin,DIO_pin_voltage volt )
{
	DIO_PORTS port=pin/8;
	u8 pin_num = pin%8;

	switch (volt)
	{
		case HIGH:
		switch (port)
		{
			case PA:
			set_bit(PORTA,pin_num);		break;
			case PB:
			set_bit(PORTB,pin_num);		break;
			case PC:
			set_bit(PORTC,pin_num);		break;
			case PD:
			set_bit(PORTD,pin_num);		break;

		} break;
		
		case LOW:
		switch (port)
		{
			case PA:
			clear_bit(PORTA,pin_num);	break;
			case PB:
			clear_bit(PORTB,pin_num);	break;
			case PC:
			clear_bit(PORTC,pin_num);	break;
			case PD:
			clear_bit(PORTD,pin_num);	break;
		} break;
	}
}

void DIO_togglepin(DIO_pin_type pin)
{
	DIO_PORTS port=pin/8;
	u8 pin_num =pin%8;
	switch (port)
	{
		case PA:
		toggle_bit(PORTA,pin_num);		break;
		case PB:
		toggle_bit(PORTB,pin_num);		break;
		case PC:
		toggle_bit(PORTC,pin_num);		break;
		case PD:
		toggle_bit(PORTD,pin_num);		break;   
	}
}

DIO_pin_voltage DIO_ReadPin(DIO_pin_type pin)
{
	DIO_PORTS port=pin/8;
	u8 pin_num=pin%8;
	
	switch(port)
	{
		case PA:
		return read_bit(PINA,pin_num);		break;
		case PB:
		return read_bit(PINB,pin_num);		break;
		case PC:
		return read_bit(PINC,pin_num);		break;
		case PD:
		return read_bit(PIND,pin_num);		break;
		
		default: return 0;
	} 
}


u8 DIO_readPorts(DIO_PORTS port)
{
	switch (port)
	{
		case PA:
		return PINA;	break;
		case PB:
		return PINB;	break;
		case PC:
		return PINC;	break;
		case PD:
		return PIND;	break;
		default: 
		return 0;
	}
	
}
void DIO_writePorts(DIO_PORTS port,u8 data)
{
	switch (port) 
	{
		case PA:
		PORTA=data;		break;
		case PB:
		PORTB=data;		break;
		case PC:
		PORTC=data;		break;
		case PD:
		PORTD=data;		break;
	}
}

void DIO_INIT (void)
{
	DIO_pin_type i;
	for (i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_initPin(i,pin_status_array[i]);
	}
}