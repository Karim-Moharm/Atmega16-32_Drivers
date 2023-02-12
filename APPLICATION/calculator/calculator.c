/*
 * calculator.c
 *
 * Created: 10/27/2022 8:19:54 PM
 *  Author:  Karim Moharm
 */ 


#include "calculator.h"
#include "LCD.h"
#include "LCD_config.h"
#include "HAL/Key Pad/KeyPad.h"
#include "HAL/Key Pad/KeyPad_config.h"
#include "MCAL/External Interrupt/EX_Int.h"
/*variables */
u8 number1[5];  // array of five digits
u8 number2[5];
u8 kp_value=255;
u8 operation=0;   // for arithmetic operation
u8 counter1=0;   // for 1st number

/*
void func1 (void)
{
	LCD_Clear();
}*/
void calc (void)
{
	sei();
	DIO_INIT();
	LCD_INIT();
	
	/******** interrupt for restart *********/
	EXT_SETCallBack(EX_INT2,0);
	EXInt_Sense(INT2,Falling_Edge);
	EXInt_Enable(EX_INT2);
	/******************/
	u8 msg0[]="loading";
	LCD_WriteString_IN(0,0,msg0);
	for(u8 i=0;i<4;i++)
	{
		LCD_writeChar_IN(0,i+7,'.');
		_delay_ms(100);
	}
	_delay_ms(350);
	LCD_Clear();
	u8 msg[]="starting the ";
	u8 msg2[]="calculator";
	LCD_WriteString_IN(0,0,msg);
	LCD_WriteString_IN(1,0,msg2);
	_delay_ms(600);
	LCD_Clear();
	
	LCD_WriteString_IN(0,0,msg2);
	
	
	
	while(1)
	{
		
		// repeat:
		
		while(1)   // for first number
		{
			do{
				kp_value=KP_getButton();
				//_delay_ms(30);
				
			  }  while(kp_value==DEFAULT_KEY);
			  
			  if(kp_value=='+' || kp_value=='-' || kp_value=='*' || kp_value=='/') 
			  {
				  operation=kp_value;
				  LCD_writeChar_IN(1,counter1,operation);
				  break;     // break the loop once the user enter '+' or '-' or '/' or '*' 
				  
			  }
			  number1[counter1]=kp_value;   // store the number in number1 array 
			  counter1++;   // in case u want enter more than 1 digit 
			  LCD_writeNumber_IN(1,counter1-1,kp_value);    
			  
		} 
		
		
		u8 counter2=counter1;     /*  for 2nd number  */
		u8 counter3=0; // to store the element of number 2
		/*	another while loop for the second number  */
		
		while(1)   // for second number
		{
			do{
				kp_value=KP_getButton();
				_delay_ms(100);
				
			} while(kp_value==DEFAULT_KEY);   // once u enter any number the condition became false 
			
			if(kp_value=='=')
			{
				LCD_writeChar_IN(1,counter2+1,kp_value);
				break;
			}
			
			number2[counter3]=kp_value;
			counter2++;
			counter3++;
			LCD_writeNumber_IN(1,counter2,kp_value);   // the position of number2 is after the value of number1  and the operation char
			
			
		}
		
		/*  operations */
		
		
		u16 num1=0;
		u16 num2=0;
		u8 sub=0;
		
		switch(operation)
		{
			
			case '+':
			// 654
			for(u8 i=0; i<counter1;i++)   // if number of entered digit were 3 ,the counter will be 4 
			{
				
				num1=num1*10+number1[i];  // num1=0*10+6=6    // num1=6*10+5=65
			}
			
			for(u8 i=0; i<counter3;i++)
			{
				num2=num2*10+number2[i];
			}
			
			LCD_writeNumber_IN(1,counter2+2,(num1+num2));  break;
			/*num1=0;
			num2=0;*/
			/*******************************************************************/
			/********************	SUBTRACTION		****************************/	
			case '-':
			
			for(u8 i=0; i<counter1;i++)
			{
				
				num1=num1*10+number1[i];
			}
			
			for(u8 i=0; i<counter3;i++)
			{
				num2=num2*10+number2[i];
			}
	
			if(num1<num2)
			{
				sub=num1-num2;
				sub=sub*-1;
				LCD_writeChar_IN(1,counter2+2,'-');
				LCD_writeNumber_IN(1,counter2+3,sub);
			}
			else {LCD_writeNumber_IN(1,counter2+2,(num1-num2)); } break;
			
			
			/*num1=0;
			num2=0;*/
			/******************************************************************/
			/*********************	MULTIPLICATION	***************************/
			
			case '*':
			
			for(u8 i=0; i<counter1;i++)
			{
				
				num1=num1*10+number1[i];
			}
			
			for(u8 i=0; i<counter3;i++)
			{
				num2=num2*10+number2[i];
			}
			
			LCD_writeNumber_IN(1,counter2+2,(num1*num2));  break;
			/*num1=0;
			num2=0;*/
			
			/****************************************************************/
			/***********************	DIVISION	*************************/
			case '/':
			
			for(u8 i=0; i<counter1;i++)
			{
				
				num1=num1*10+number1[i];
			}
			
			for(u8 i=0; i<counter3;i++)
			{
				num2=num2*10+number2[i];
			}
			
			LCD_writeNumber_IN(1,counter2+2,(num1/num2));  break;
			
			
			/************************************************/
			/************************************************/
			
			
		}
		
	/*	if (kp_value=='c')           	not working.....*/
		/* {
			LCD_Clear();
			u8 operation=0;   
			u8 counter1=0;
			u8 counter2=0;
			u8 counter3=0;
			u8 number1[5]={0};  
			u8 number2[5]={0};
			goto repeat;
		}*/
		
		
		/*if(KP_getButton=='c')
		{
			LCD_WriteString_IN(1,0,"				");
		}*/
		
		
		/*if(DIO_ReadPin(PINB7)==LOW)
		{
			LCD_Clear();
		}*/
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
}
