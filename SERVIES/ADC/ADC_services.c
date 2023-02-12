/*
 * ADC_services.c
 *
 * Created: 12/10/2022 2:45:31 AM
 *  Author: YN
 */ 

#include "ADC_Services.h"

u16 ADC_Read_Volt(ADC_INChannel channel)
{
	
	ADC_StartConversion(channel);
	u16 adc = ADC_Read();
	
	/// volt in milli volt
	u16 volt = ((u32)5000*adc)/1024;
	
	return volt;
	
}