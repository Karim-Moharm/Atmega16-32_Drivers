/*
 * tmr_services.c
 *
 * Created: 11/4/2022 10:45:01 AM
 *  Author: YN
 */ 

#include "tmr_services.h"

volatile u16 t1,t2,t3;
static volatile u8 flag;
static u16 int_set=0;
static void FUNC_ICR(void);
static void (*pf_oc)(void)=NULL_ptr;
void Timer0_setInterrupt_us_8_(u8 time,void(*local_ptr)(void))
{
	//time=OCR0-1;
	OCR0=time-1;
	timer0_OC0_SetCallback_(local_ptr);
	Timer0_OC_enable();
	
}

void Timer0_setInterrupt_ms(u8 time,void(*local_ptr)(void))
{
	//time=OCR0-1;
	OCR0=time*1000-1;
	timer0_OC0_SetCallback_(local_ptr);
	Timer0_OC_enable();
	
}

void Timer0_setInterrupt_us_16_(u16 time,void(*local_ptr)(void))
{
	int_set=time/100;   /* number of interrupt */ 
	OCR0=99;    /* interrupt happen each 100us */ 
	pf_oc=local_ptr;
	timer0_OC0_SetCallback_(func_OC);
	Timer0_OC_enable();
	
}

void func_OC (void)
{
	static u8 c=0;
	c++;
	if(c==int_set)
	{
		pf_oc();
	}
	
}


/******************************************************************************************/
/*********************************************  timer1 **********************************/

void PWM_measure (u32 *freq,u8 *duty_cyc)  
{
	u16 ton,toff;
	TCNT1=0;
	Timer1_ICU_SetCallback_(FUNC_ICR);
	Timer1_Input_CaptureEdge(ICP1_RISING);
	Timer1_ICU_int_enable();
	flag=0;
	while(flag<3);
	ton=t2-t1;
	toff=t3-t2;
	*freq=(u32)1000000/((u32)(ton+toff));
	*duty_cyc=((u32)(ton*100))/((u32)ton+toff);
	
}

static void FUNC_ICR(void)
{	
	if(flag==0)
	{
		t1=TCNT1;
		Timer1_Input_CaptureEdge(ICP1_FALLING);
		flag=1;	
	}
	else if(flag==1)
	{
		t2=TCNT1;
		Timer1_Input_CaptureEdge(ICP1_RISING);
		flag=2;
	}
	else if(flag==2)
	{
		t3=TCNT1;
		Timer1_ICU_int_disable();
		flag=3;
		
	}
	
}