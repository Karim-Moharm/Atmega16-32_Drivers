
#include "ADC_main.h"
#include "../../MCAL/ADC/ADC.h"
#include "data_types.h"
#include "LCD.h"
#include "Sensors/Sensors.h"

void POT (void)
{
	
	
	DIO_INIT();
	LCD_INIT();
	ADC_INIT(Vref_AVCC,DIV_64);
	ADC_Enable();
	
	u16 x;
	u8 msg[]="volt:";
	LCD_WriteString(msg);

	while (1)
	{
		
		
		//ADC_read(POT_PIN);
		LCD_SetPos(0,5);
		x=POT_volt();
		LCD_writeNumber_4D(x);
		

		
		/*
		ADC_StartConversion(ADC0);
		if (ADC_GetRead(&x))
		{
			x=POT_volt();
			LCD_SetDisplay(0,5);
			LCD_writeNumber_4D(x);
		}
		
		ADC_StartConversion(ADC1);
		if (ADC_GetRead(&temp))
		{
			temp=lm35();
			
			LCD_SetDisplay(1,5);
			/ *LCD_WriteNumber(temp/10);
			LCD_WriteChar('.');
			LCD_WriteNumber(temp%10);* /
			LCD_WriteFloat(temp,1);
		}
		*/	
	
	
}

}

//* sensor temperature *//
void LM35 (void)
{
	
	
	/*DIO_INIT();
	LCD_INIT();
	ADC_INIT(Vref_AVCC,DIV_64);
	ADC_Enable();
	
	u8 msg[]="temp:";
	LCD_WriteString(msg);
	
	
	u16 temp;
	
	
	while(1)
	{
		ADC_read(LM_PIN);
		LCD_SetDisplay(1,5);
		temp=lm35();
		LCD_WriteFloat(temp,1);
	}
	*/
	
}

//* humidity tempreture *//
void MPX (void)
{
	
	DIO_INIT();
	LCD_INIT();
	ADC_INIT(Vref_AVCC,DIV_64);
	ADC_Enable();
	
	u16 pre;
	
	LCD_SetPos(1,0);
	u8 msg[]="pressure:";
	LCD_WriteString(msg);
	
	
	while(1)
	{
		
		 //ADC_read(MPX_PIN);
		LCD_SetPos(1,8);
		pre=pressure_sens();
		LCD_WriteFloat(pre,1);
		
	}
	
	
	
	
}