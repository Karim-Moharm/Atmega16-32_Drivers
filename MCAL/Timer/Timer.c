/*
 * Timer.c
 *
 * Created: 11/3/2022 3:35:05 PM
 *  Author: YN
 */ 

#include "Timer.h"

/*************************************************************************************************************************************/
/****************************************************************** TIMER0 ************************************************************/
/**********************************************************************************************************************************/
static void (*ptrF_OC0)(void)=NULL_ptr;
static void (*ptrF_OVF)(void)=NULL_ptr;

void Timer0_INIT(Timer0_Mode Mode,Timer_Prescaler scale,Timer0_OC_mode compare)
{
	switch(Mode)
	{
		case TIMER0_Normal:
		clear_bit(TCCR0,WGM00);
		clear_bit(TCCR0,WGM01);    break;
		case TIMER0_PWM:
		set_bit(TCCR0,WGM00);
		clear_bit(TCCR0,WGM01);    break;
		case TIMER0_CTC:
		clear_bit(TCCR0,WGM00);
		set_bit(TCCR0,WGM01);    break;
		case TIMER0_Fast_PWM:
		set_bit(TCCR0,WGM00);
		set_bit(TCCR0,WGM01);    break;
	}
	 
	TCCR0&=0xf8;   // 0b11111000    // last 3 bits in TCCR0
	TCCR0|=scale;
	
	switch(compare)
	{
		case OC0_disconnected:
		clear_bit(TCCR0,COM00);
		clear_bit(TCCR0,COM01);		break;
		case OC0_Toggle:
		set_bit(TCCR0,COM00);
		clear_bit(TCCR0,COM01);		break;
		case OC0_NON_Inverting:
		clear_bit(TCCR0,COM00);
		set_bit(TCCR0,COM01);		break;
		case OC0_Inverting:
		set_bit(TCCR0,COM00);
		set_bit(TCCR0,COM01);		break;
		
		
	}
	
	
}

void Timer0_OV_enable(void)
{
	set_bit(TIMSK,TOIE0);
	
}
void Timer0_OV_disable(void)
{
	clear_bit(TIMSK,TOIE0);
	
}
void Timer0_OC_enable(void)
{
	set_bit(TIMSK,OCIE0);
	
}
void Timer0_OC_disable(void)
{
	clear_bit(TIMSK,OCIE0);
	
}

void timer0_OC0_SetCallback_(void(*local_ptr)(void))
{
	ptrF_OC0=local_ptr;
}
void timer0_OVF_SetCallback_(void(*local_ptr)(void))
{
	ptrF_OVF=local_ptr;
}


ISR(TIMER0_COMP_VECT)
{
	if(ptrF_OC0!=NULL_ptr)
	ptrF_OC0();
	
}

ISR(TIMER0_OVF_VECT)
{
	if(ptrF_OVF!=NULL_ptr)
	ptrF_OVF();
	
}

/*************************************************************************************************************************************/
/****************************************************************** TIMER1 ************************************************************/
/**********************************************************************************************************************************/

static void (*TIMER1_ptrF_OVF)(void)=NULL_ptr;
static void (*TIMER1_ptrF_OCA)(void)=NULL_ptr;
static void (*TIMER1_ptrF_OCB)(void)=NULL_ptr;
static void (*TIMER1_ptrF_ICU)(void)=NULL_ptr;


void Timer1_INIT(Timer1_Gen_mode Mode, Timer_Prescaler scale, Timer1_OCA_mode OCR_A, Timer1_OCB_mode OCR_B)
{
	switch(Mode)
	{
		case TIMER1_normal:								
		clear_bit(TCCR1B, WGM10);	clear_bit(TCCR1B, WGM11);	clear_bit(TCCR1A, WGM12);	clear_bit(TCCR1B, WGM13);		 break;
		case TIMER1_CTC_OCR1A:						
		clear_bit(TCCR1B, WGM10);	 clear_bit(TCCR1B, WGM11);	 set_bit(TCCR1A, WGM12);	 clear_bit(TCCR1B, WGM13);		 break;
		case TIMER1_Phase_and_Freq_Correct_ICR:			
		clear_bit(TCCR1B, WGM10);	clear_bit(TCCR1B, WGM11);	clear_bit(TCCR1A, WGM12);	set_bit(TCCR1B, WGM13);			 break;
		case TIMER1_Phase_Correct_ICR:			
		clear_bit(TCCR1B, WGM10);	 set_bit(TCCR1B, WGM11);	clear_bit(TCCR1A, WGM12);	 set_bit(TCCR1B, WGM13);		 break;
		case TIMER1_Phase_Correct_OCR1A:						
		set_bit(TCCR1B, WGM10);		set_bit(TCCR1B, WGM11);		clear_bit(TCCR1A, WGM12);	 set_bit(TCCR1B, WGM13);		 break;
		case TIMER0_CTC_ICR:
		clear_bit(TCCR1B, WGM10);	 clear_bit(TCCR1B, WGM11);	 set_bit(TCCR1A, WGM12);	set_bit(TCCR1B, WGM13);			 break;
		case TIMER1_fast_PWM_ICR1:
		clear_bit(TCCR1B, WGM10);	 set_bit(TCCR1B, WGM11);	set_bit(TCCR1A, WGM12);	 set_bit(TCCR1B, WGM13);			 break;
		case TIMER1_fast_PWM_OCR1A:
		set_bit(TCCR1B, WGM10);		set_bit(TCCR1B, WGM11);	 set_bit(TCCR1A, WGM12);	 set_bit(TCCR1B, WGM13);			 break;
	}
	/*  for prescaler */
		TCCR1B &= 0xF8;
		TCCR1B |= scale;
		
		
		/*	output compare mode	for OCRA*/
	switch(OCR_A)
	{
		case OC0_disconnected:			clear_bit(TCCR1A,COM1A0);			clear_bit(TCCR1A,COM1A1);		break;
		case OC0_Toggle:				set_bit(TCCR1A,COM1A0);			    clear_bit(TCCR1A,COM1A1);		break;
		case OC0_NON_Inverting:			clear_bit(TCCR1A,COM1A0);			set_bit(TCCR1A,COM1A1);			break;
		case OC0_Inverting:				set_bit(TCCR1A,COM1A0);				set_bit(TCCR1A,COM1A1);			break;
		
	}
		/*	output compare mode	for OCRB*/
	switch(OCR_B)
	{
		case OC0_disconnected:			clear_bit(TCCR1A,COM1B0);			clear_bit(TCCR1A,COM1B1);		break;
		case OC0_Toggle:				set_bit(TCCR1A,COM1B0);			    clear_bit(TCCR1A,COM1B1);		break;
		case OC0_NON_Inverting:			clear_bit(TCCR1A,COM1B0);			set_bit(TCCR1A,COM1B1);			break;
		case OC0_Inverting:				set_bit(TCCR1A,COM1B0);				set_bit(TCCR1A,COM1B1);			break;
		
	}
	

}

void Timer1_Input_CaptureEdge(ICU_EDGE_TYPE edge)
{
	switch(edge)
	{
		case ICP1_FALLING:		clear_bit(TCCR1B,ICES1);			break;
		case ICP1_RISING:		set_bit(TCCR1B,ICES1);				break;
	}

}

/******************************* IIMER1 interrupt enables and disables functions *****************************/
void Timer1_ICU_int_enable(void)    //timer/Counter1, Input Capture Interrupt Enable
{
	set_bit(TIMSK,TICIE1);
}
void Timer1_ICU_int_disable(void)
{
	clear_bit(TIMSK,TICIE1);
}
void Timer1_OC_A_int_enable(void)
{
	set_bit(TIMSK,OCIE1A);
}
void Timer1_OC_A_int_disable(void)
{
	clear_bit(TIMSK,OCIE1A);
}
void Timer1_OC_B_int_enable(void)
{
	set_bit(TIMSK,OCIE1B);
}
void Timer1_OC_B_int_disable(void)
{
	clear_bit(TIMSK,OCIE1B);
}
void Timer1_ovf_enable(void)
{
	set_bit(TIMSK,TOIE1);
}
void Timer1_ovf_disable(void)
{
	clear_bit(TIMSK,TOIE1);
}

/******************************* TIMER1 setcall back functions *****************************/

void Timer1_OVF_SetCallback_(void(*local_ptr)(void))
{
	TIMER1_ptrF_OVF=local_ptr;
}
void Timer1_OCA_SetCallback_(void(*local_ptr)(void))
{
	TIMER1_ptrF_OCA=local_ptr;
}
void Timer1_OCB_SetCallback_(void(*local_ptr)(void))
{
	TIMER1_ptrF_OCB=local_ptr;
}
void Timer1_ICU_SetCallback_(void(*local_ptr)(void))
{
	TIMER1_ptrF_ICU=local_ptr;
}
/******************************* TIMER1 ISR functions *****************************/
ISR(TIMER1_OVF_VECT)
{
	if(TIMER1_ptrF_OVF!=NULL_ptr)
	{
		TIMER1_ptrF_OVF();
	}
	
}
ISR(TIMER1_COMPA_VECT)
{
	if(TIMER1_ptrF_OCA!=NULL_ptr)
	{
		TIMER1_ptrF_OCA();
	}
	
}
ISR(TIMER1_COMPB_VECT)
{
	if(TIMER1_ptrF_OCB!=NULL_ptr)
	{
		TIMER1_ptrF_OCB();
	}
	
}
ISR(TIMER1_CAPT_VECT)
{
	if(TIMER1_ptrF_ICU!=NULL_ptr)
	{
		TIMER1_ptrF_ICU();
	}
	
}