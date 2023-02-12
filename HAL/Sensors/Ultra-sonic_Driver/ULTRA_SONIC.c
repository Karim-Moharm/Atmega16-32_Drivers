/*
 * ULTRA_SONIC.c
 *
 * Created: 11/8/2022 10:16:58 PM
 *  Author: YN
 */ 

#include "HAL/Sensors/Ultra-sonic_Driver/ULTRA_SONIC.h"

static volatile u16 flag=0,t1,t2;
static volatile u16 c;
static void func_ICU (void);
static void func_OVF(void);

void ultra_sonic_INIT(void)
{
	Timer1_INIT(TIMER1_normal,CLK_8,OC1A_NON_Inverting,OC1B_NON_Inverting);
	Timer1_OVF_SetCallback_(func_OVF);
	Timer1_ICU_SetCallback_(func_ICU);  
}

u8 UltraSonic_GetDistance(ULTRASONIC_PIN US_pin)
{
	u8 distance;
	u16 time;
	c=0;
	flag=0;
	//tcnt1=0;
	DIO_writePin(US_pin,HIGH);
	_delay_us(10);
	DIO_writePin(US_pin,LOW);
	Timer1_Input_CaptureEdge(ICP1_RISING);
	Timer1_ICU_int_enable();
	Timer1_ovf_enable();
	while(flag<2);
	time=t2-t1+((u32)c*65535);
	distance=time/58;
	Timer1_ICU_int_disable();
	flag=0;
	return distance;
}

static void func_ICU (void)
{
	if(flag==0)
	{
		c=0;
		t1=ICR1;
		flag=1;
		Timer1_Input_CaptureEdge(ICP1_FALLING);
	}
	else if(flag==2)
	{
		t2=ICR1;
		flag=2;
		Timer1_Input_CaptureEdge(ICP1_RISING);
		Timer1_ovf_disable();
		Timer1_ICU_int_disable();
	}
	
}

static void func_OVF(void)
{
	c++;
}