
#include "Sensors.h"

u16 POT_volt (void)
{
	u16 adc=ADC_read_Channel (POT_PIN);
	u16 volt=((u32)5000*adc)/1024;    // the volt unit is milliVolt
	return volt;
	
}
u16 lm35 (void)
{
	u16 adc=ADC_read_Channel(LM_PIN);
	u16 volt=((u32)5000*adc)/1024; 
	u16 temp= volt/10;    // 10mv/0C
	return temp;
	
}
u16 pressure_sens (void)
{
	u16 p;
	u16 adc=ADC_read_Channel(MPX_PIN);
	p=1*(adc-40)+15*10;
	return p;
}


