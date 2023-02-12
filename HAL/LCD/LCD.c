/*
 * LCD.c
 *
 * Created: 10/21/2022 10:19:09 PM
 *  Author: Karim Moharm
 */ 

#include "../../HAL/LCD/LCD.h"
#include "../../HAL/LCD/LCD_config.h"
#include "data_types.h"

#if (LCD_MODE == _8_bit)

void LCD_WriteCommand(u8 command)   // for  8 bits 
{
	DIO_writePin(RS,LOW);
	DIO_writePin(RW,LOW);
	DIO_writePorts(LCD_PORT,command);
	
	DIO_writePin(EN,HIGH);		// enable from high to low 
	_delay_ms(1);
	DIO_writePin(EN,LOW);
	_delay_ms(1);
	
}
void LCD_WriteData(u8 data)	// for  8 bits 
{
	DIO_writePin(RS,HIGH);
	DIO_writePin(RW,LOW);
	DIO_writePorts(LCD_PORT,data);
	
	DIO_writePin(EN,HIGH);
	_delay_ms(1);
	DIO_writePin(EN,LOW);
	_delay_ms(1);
	
}

void LCD_INIT(void)		// initialization for 8_bit
{
	_delay_ms(40);
	LCD_WriteCommand(0x38);		// 8 bits, two lines, font 5x7 dot   (0x38)
	// 0x30  8 bits, one line		// 0x2c  8 bits, two lines, font 5x10 dot 
	_delay_ms(1);
	LCD_WriteCommand(0x0c);		// turn on LCD, cursor is off, blink of cursor is off   
	// 0x0c -->> without cursor,	 0x0E -->with the cursor but without blinkig,	  0x0F --> with cursor and blinking 
	_delay_ms(1);
	LCD_WriteCommand(0x01);		// display clear 
	_delay_ms(2);
	LCD_WriteCommand(0x06);		// increase, the display does not shift  

	_delay_ms(1);
	
}

#elif (LCD_MODE == _4_bit)

void LCD_WriteCommand(u8 command )   // for  4 bits
{
	DIO_writePin(RS,LOW);
	DIO_writePin(RW,LOW);
	DIO_writePin(D4,read_bit(command,4));
	DIO_writePin(D5,read_bit(command,5));
	DIO_writePin(D6,read_bit(command,6));
	DIO_writePin(D7,read_bit(command,7));
	
	DIO_writePin(EN,HIGH);		// enable from high to low
	_delay_ms(1);
	DIO_writePin(EN,LOW);
	_delay_ms(1);
	
	DIO_writePin(D4,read_bit(command,0));
	DIO_writePin(D5,read_bit(command,1));
	DIO_writePin(D6,read_bit(command,2));
	DIO_writePin(D7,read_bit(command,3));
	
	DIO_writePin(EN,HIGH);
	_delay_ms(1);
	DIO_writePin(EN,LOW);
	_delay_ms(1);
	
}

void LCD_WriteData(u8 data )   // for  4 bits
{
	DIO_writePin(RS,HIGH);
	DIO_writePin(RW,LOW);
	DIO_writePin(D4,read_bit(data,4));
	DIO_writePin(D5,read_bit(data,5));
	DIO_writePin(D6,read_bit(data,6));
	DIO_writePin(D7,read_bit(data,7));
	
	DIO_writePin(EN,HIGH);		// enable from high to low
	_delay_ms(1);
	DIO_writePin(EN,LOW);
	_delay_ms(1);
	
	DIO_writePin(D4,read_bit(data,0));
	DIO_writePin(D5,read_bit(data,1));
	DIO_writePin(D6,read_bit(data,2));
	DIO_writePin(D7,read_bit(data,3));
	
	DIO_writePin(EN,HIGH);
	_delay_ms(1);
	DIO_writePin(EN,LOW);
	_delay_ms(1);
	
}

void LCD_INIT(void)		// initialization for 4_bits
{
	_delay_ms(40);
	LCD_WriteCommand(0x02);
	_delay_ms(1);
	LCD_WriteCommand(0x28);		// 4 bits, two lines, font 5x7 dot   (0x28)
	// 0x20  4 bits, one line		
	_delay_ms(1);
	LCD_WriteCommand(0x0c);		// turn on LCD, cursor is off, blink of cursor is off
	// 0x0c -->> without cursor,	 0x0E -->with the cursor but without blinkig,	  0x0F --> with cursor and blinking
	_delay_ms(1);
	LCD_WriteCommand(0x01);		// display clear
	_delay_ms(2);
	LCD_WriteCommand(0x06);		// increase, the display does not shift
	_delay_ms(1);
	
}

#endif
 
 /********************************************************************************************/
 /*******************************	function to write string on LCD	******************************/
 /*******************************************************************************************/
 void LCD_WriteString (u8 *str)
{
	u8 i=0;
	while (str[i]!='\0')
	{
		LCD_WriteData(str[i]);
		i++;
	}
}

 /********************************************************************************************/
 /*******************************	functions to write a number on LCD	******************************/
 /*******************************************************************************************/

/************ write numbers on LCD ****************/
void LCD_WriteNumber_S64(s64 number)   /* 124587 */
{
	u8 rem,arr[16]={0} , i=0,j;
	if (number==0)
	{
		LCD_WriteData('0');
	}
	else
	{
		if (number<0)	
		{
			number=number * -1;
			LCD_WriteData('-');
		}
																					 
	}
		while(number>0)	 /* or using for loop */								
		{
			rem=number % 10;
			arr[i]=rem+'0';
			i++;
			number/=10;
			
		}		/* 785421	*/
			//after looping i=number+1
			
			for (j=i;j>0;j--)
			{
				LCD_WriteData(arr[j-1]);
			}
			/* 124587 */
		}
		
	
	
void LCD_WriteNumber_S32 (s32 number) 
{
	LCD_WriteNumber_S64((s64)number);
}

void LCD_WriteNumber_S16 (s16 number)
{
	LCD_WriteNumber_S64((s64)number);
}


	/********** writing numbers or char with determining the place digits ************************/
void LCD_writeNumber_IN(u8 line,u8 x, s64 number)
{
	LCD_SetPos(line,x);
	LCD_WriteNumber_S64(number);
}

void LCD_WriteString_IN(u8 line,u8 x, u8 *string)
{
	LCD_SetPos(line,x);
	LCD_WriteString(string);
}

void LCD_writeChar_IN(u8 line,u8 x, u8 ch)
{
	LCD_SetPos(line,x);
	LCD_WriteChar(ch);
}
 


/*	function for writing numbers in four digits */
void LCD_writeNumber_4D (u16 number)
{
	// assume the number was 4927
	LCD_WriteData (( (number % 10000) / 1000) +  '0');		//4
	LCD_WriteData (( (number % 1000) / 100)	  +  '0');		//9
	LCD_WriteData (( (number % 100) / 10)	  +  '0');		//2
	LCD_WriteData (( (number % 10) / 1)       +  '0');		//7
}

/*	function for writing numbers in three digits */
void LCD_writeNumber_3D (u8 number)
{
	// assume the number was 492
	LCD_WriteData (( (number % 1000) / 100)+'0');	// 4
	LCD_WriteData (( (number % 100) / 10)+'0');		// 9
	LCD_WriteData (( (number % 10) / 1)+'0');		// 2
}

 /********************************************************************************************/
 /*******************************************************************************************/
/* function to clear the LCD  */
void LCD_Clear (void)
{
	LCD_WriteCommand(0x01);
	_delay_ms(10);
}

 /********************************************************************************************/
 /*******************************************************************************************/

void LCD_WriteChar(u8 c)
{
	LCD_WriteData(c);
}


 /********************************************************************************************/
 /*******************************************************************************************/
/* function determines the place where you want to start writing on LCD */ 

void LCD_SetPos (u8 line, u8 x)  
{
	u8 command=0x80;   // first line in place 0 (initial place)   // Set DDRAM from data sheet  (P_16)
	switch (line)
	{
		case 0:	// starts from first line
		command= command + x;		// 0x80+ 5 >>> if want to start writing from 5th column
		LCD_WriteCommand(command);
		break;
		
		case 1: // starts from  second line
		command= command + 0x40 + x;
		LCD_WriteCommand(command);
		break;
		
	}	// or using if and else if 
}

 /********************************************************************************************/
 /*******************************************************************************************/
// function to create pattern 
void LCD_CreatePattern(u8 *pattern,u8 block_num)
{
	u8 i=0;
	LCD_WriteCommand(0x40+(block_num*8));		 // 0x40 >>to set CGRAM address for creating char
	
	for (i=0;i<=7;i++)
	{
		LCD_WriteData(pattern[i]);
	}
	
} 

void LCD_correctsign (void)
{
	u8 pattern[]={0x00,0x01,0x02,0x14,0x18,0x10,0x00,0x0}; 
	LCD_CreatePattern(pattern,0);
	
}

 /********************************************************************************************/
 /*******************************************************************************************/
void LCD_WriteBinary(u8 num) 
{
	s8 i;
	for (i=7;i>=0;i--)
	{
		LCD_WriteData( ((num>>i)&1)+ '0' );
	}
	
	
}

void LCD_writeBinary_without0(u8 num)	// print the binary of numbers without zeros in left side 
{
	s8 i,flag=0;
	for (i=7;i>=0;i--)
	{
		if ( ((num>>i)&1) )
			flag =1;
			
		if (flag==1)
		{
			LCD_WriteData( ((num>>i) &1) +'0' );
		}
		
	}
}

void LCD_WriteFloat(u32 number,u16 number_after_point)
{
	switch(number_after_point)
	{
		case 1:
		LCD_WriteNumber_S64(number/10);
		LCD_WriteChar('.');
		LCD_WriteNumber_S64(number%10);
		break;
		
		case 2:
		LCD_WriteNumber_S64(number/100);
		LCD_WriteChar('.');
		LCD_WriteNumber_S64(number%100);
		break;
		
		case 3:
		LCD_WriteNumber_S64(number/1000);
		LCD_WriteChar('.');
		LCD_WriteNumber_S64(number%1000);
		break;
		
		case 4:
		LCD_WriteNumber_S64(number/10000);
		LCD_WriteChar('.');
		LCD_WriteNumber_S64(number%10000);
		break;
			
	}
	
}

void LCD_writeFloat_IN(u8 line,u8 x, u32 number,u16  number_after_point)
{
	LCD_SetPos(line,x);
	LCD_WriteFloat(number, number_after_point);
}


void LCD_CursorOn(void){
	LCD_WriteCommand(0x38 | 0x02);
}
void LCD_CursorOff(void){
	LCD_WriteCommand(0x38 & 0xFD);
}