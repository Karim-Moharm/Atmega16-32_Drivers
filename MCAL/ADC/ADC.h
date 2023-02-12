/*
 * ADC.h
 *
 * Created: 10/25/2022 8:25:38 PM
 *  Author: Karim Moharm
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "data_types.h"
#include "Mem_Map.h"
#include "bitwise.h"



typedef enum {
			Vref_AREF,
			Vref_AVCC,
			Vref_internal
	}ADC_Vref;
	
typedef enum {
			DIV_2=1,	
			DIV_4,		
			DIV_8,		
			DIV_16,
			DIV_32,
			DIV_64,
			DIV_128   
			
	}ADC_prescaler;
	
typedef enum {
			ADC0,
			ADC1,
			ADC2,
			ADC3,
			ADC4,
			ADC5,
			ADC6,
			ADC7	
	}ADC_INChannel;
	
void ADC_INIT(ADC_Vref vref,ADC_prescaler div_fac);
void ADC_Enable(void);

u16 ADC_read_Channel(ADC_INChannel pins);
//u8 ADC_read_2(u8 channel_num);
u16 ADC_Read(void);

void ADC_StartConversion(ADC_INChannel pin);
/*u16 ADC_GetRead(void);*/
u16 ADC_GetRead(u16 *data);


#endif /* ADC_H_ */