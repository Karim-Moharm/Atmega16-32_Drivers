/*
 * LM_sensor_2.c
 *
 * Created: 12/10/2022 3:22:11 AM
 *  Author: YN
 */ 


#include "LM_sensor_2.h"

u16 LM35_Read(ADC_INChannel channel)
{
	return(ADC_Read_Volt(channel)/10);
}

u16 LM35_Read_Float(ADC_INChannel channel)
{
	return(ADC_Read_Volt(channel));
}