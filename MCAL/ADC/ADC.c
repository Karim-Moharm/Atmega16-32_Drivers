/*
 * ADC.c
 *
 * Created: 10/25/2022 8:25:27 PM
 *  Author: Karim Moharm
 */ 


#include "ADC.h"
//#include <avr/io.h>

static u8 ADC_Readflag=0;


void ADC_INIT(ADC_Vref vref,ADC_prescaler div_fac)
{
	// reference voltage
	switch(vref) 
	{
		case Vref_AREF:
		clear_bit(ADMUX,6);
		clear_bit(ADMUX,7);
		break;
		
		case Vref_AVCC:
		set_bit(ADMUX,6);
		clear_bit(ADMUX,7);
		break;
		
		case Vref_internal: 
		set_bit(ADMUX,6);
		set_bit(ADMUX,7);
		break;
		
	}	
	
	// clock cycle 
	ADCSRA&=0xf8;	  /* 0b11111 000*/  // put zero on the first 3 bits (scaler bits) in ADCSRA reg to clear them in case there's old prescaler
	div_fac&=0x07;   //		to ensure that the bits starting from 3 to 7 are zeros    // 0b00000 ***  first 3 bits according to the chosen prescaler
	ADCSRA|=div_fac;	
	
	// adjust right reading
	
	clear_bit(ADMUX,ADLAR);   // ADCL>> 8its and ADCH>> 2 bits   /* right adjust */
	
}

void ADC_Enable(void)  // called after ADC_INIT
{
	set_bit(ADCSRA,ADEN);
}

u16 ADC_read_Channel(ADC_INChannel pins)
{
	ADMUX&=0xE0;		//  0b11100000  *  // put zeros in first 5 bits in ADMUX reg   // from Mux0 >>Mux5 
	ADMUX|=pins;
	
	set_bit(ADCSRA,ADSC);  // start the conversion * write '1' to ADSC *
	while(read_bit(ADCSRA,ADSC));  // don't do any return unless the ADC ends the process of conversion 

 	return ADC_data;	// ADC_data is a pointer start from address 0x24 to 0x25 * two bytes pointer *   // works onlu=y incase right adjust
	 
	 /* or
	   u16 ADC_data=(ADCL |(u16) ADCH<<8);
		 return ADC_data;	*/
	
	
// 	ADMUX = 0x40 | (pins & 0x07);   /* set input channel to read */
// 	ADCSRA |= (1<<ADSC);               /* Start ADC conversion */
// 	while (!(ADCSRA & (1<<ADIF)));     /* Wait until end of conversion by polling ADC interrupt flag */
// 	ADCSRA |= (1<<ADIF);               /* Clear interrupt flag */
// 	_delay_ms(1);                      /* Wait a little bit */
// 	return ADCW;                       /* Return ADC word */
}

u16 ADC_Read(void)
{

	// polling (busy wait)
	while(GET_BIT(ADCSRA ,ADSC));
	ADC_Readflag = 0;
	return ADC_data;   // ADC_data is a pointer start from address 0x24 to 0x25 * two bytes pointer * 
	
}


void ADC_StartConversion(ADC_INChannel pins)  // start conversion for the chosen bit // the conversion type is single conversion
// single conversion mode means to write this bit to one to start each conversion

{
	if (ADC_Readflag==0)
	{
		ADMUX&=0b11100000;  // put zeros in last 5bits in ADMUX reg
		ADMUX|=pins;

		set_bit(ADCSRA,ADSC);  // start the conversion
		ADC_Readflag=1;
	} 
	
}

/*
u16 ADC_GetRead(void)
{
	while(read_bit(ADCSRA,ADSC));   // wait until the conversion done 
	return ADC_READ;
}*/
	
u16 ADC_GetRead(u16 *data)
{
	if(read_bit(ADCSRA,ADSC)==0)  // if the conversion done and return 0  (periodic check pooling)
	{
		
		*data=ADC_data;
		ADC_Readflag=0;
		return 1;  // if the conversion process completed 
	} 
	else 
		return 0;	// if the conversion process not done 
}