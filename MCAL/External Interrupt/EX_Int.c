/*
 * EX_Int.c
 *
 * Created: 10/28/2022 11:24:03 AM
 *  Author: YN
 */ 

#include <avr/io.h>
#include "EX_Int.h"


static void (*PtrF_INT0)(void);    // pointer to function 
static void (*PtrF_INT1)(void);    
static void (*PtrF_INT2)(void);		



void EXInt_Enable(EXInterrupt_Source INTSource)
{
	switch(INTSource)
	{
		case EX_INT0:
		set_bit(GICR,INT0);  break;
		case EX_INT1:
		set_bit(GICR,INT1);  break;
		case EX_INT2:
		set_bit(GICR,INT2);  break;
	}
}


void EXInt_Disable(EXInterrupt_Source INTSource)
{
	switch(INTSource)
	{
		case EX_INT0:
		clear_bit(GICR,INT0);  break;
		case EX_INT1:
		clear_bit(GICR,INT1);  break;
		case EX_INT2:
		clear_bit(GICR,INT2);  break;
	}
}


void EXInt_Sense (EXInterrupt_Source INTSource,EXInterrupt_Sense sense)
{
	switch(INTSource)
	{
		case EX_INT0:
		switch(sense)
		{
			case Low_Level:
			clear_bit(MCUCR,ISC01);
			clear_bit(MCUCR,ISC00);  break;
			
			case Any_Logic_change:
			clear_bit(MCUCR,ISC01);
			set_bit(MCUCR,ISC00);  break;	
			
			case Falling_Edge:
			set_bit(MCUCR,ISC01);
			clear_bit(MCUCR,ISC00);  break;
			
			case Rising_Edge:
			set_bit(MCUCR,ISC01);
			set_bit(MCUCR,ISC00);  break;
		}  break;
		
		case EX_INT1:
		switch(sense)
		{
			case Low_Level:
			clear_bit(MCUCR,ISC11);
			clear_bit(MCUCR,ISC10);  break;
			
			case Any_Logic_change:
			clear_bit(MCUCR,ISC11);
			set_bit(MCUCR,ISC10);  break;
			
			case Falling_Edge:
			set_bit(MCUCR,ISC11);
			clear_bit(MCUCR,ISC10);  break;
			
			case Rising_Edge:
			set_bit(MCUCR,ISC11);
			set_bit(MCUCR,ISC10);  break;
		}  break;
		
		case EX_INT2:
		switch(sense)
		{
			case Low_Level:
		    break;
			
			case Any_Logic_change:
			break;
			
			case Falling_Edge:		
			clear_bit(MCUCSR,ISC2);  break;
			
			case Rising_Edge:
			set_bit(MCUCSR,ISC2);  break;
		}  break;
		
		
	}
}

void EXInt_SETCallBack(EXInterrupt_Source INTSource, void(*pf_local)(void))
{
	switch(INTSource)
	{
		case EX_INT0:
		PtrF_INT0=pf_local;  break;
		case EX_INT1:
		PtrF_INT1=pf_local;  break;
		case EX_INT2:
		PtrF_INT2=pf_local;  break;
	}
	
}


ISR(INT0_VECT)
{
	if(PtrF_INT0!=((void*)0))
	PtrF_INT0();
}
ISR(INT1_VECT)
{
	if(PtrF_INT1!=((void*)0))
	PtrF_INT1();
}

ISR(INT2_VECT)
{
	if(PtrF_INT2!=((void*)0))
	PtrF_INT2();
}
