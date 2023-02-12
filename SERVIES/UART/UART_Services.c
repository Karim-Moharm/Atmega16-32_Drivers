/*
 * UART_Services.c
 *
 * Created: 11/29/2022 5:53:54 PM
 *  Author: Karim Moharm
 */ 

#include "UART_Services.h"
#include "LCD.h"

u8*PsendData=0;
u8*PreceiveData=0;
static volatile u8 endflag=0;
/***********************************/
void UART_Send_Int(u32 num)
{
	UART_TX((u8)num);  
	UART_TX((u8)(num>>8));
	UART_TX((u8)(num>>16));
	UART_TX((u8)(num>>24));

}
u32 UART_Receive_Int(void)
{
	u8 Byte_1=UART_RX();
	u8 Byte_2=UART_RX();
	u8 Byte_3=UART_RX();
	u8 Byte_4=UART_RX();
	u32 num=Byte_1|((u32)Byte_2<<8)|((u32)Byte_3<<16)|((u32)Byte_4<<24);
	return num;
}



void UART_Send_String(u8 *str)
{
	u8 i;
	for(i=0;str[i];i++){
	UART_TX(str[i]);
	}
	UART_TX('.');   // send . at the end of string to know that the string sentence is finished 
}


void UART_Receive_String(u8*str)
{
	u8 i=0;
	str[i]=UART_RX();
	while(str[i]!='.'){
		i++;
		str[i]=UART_RX();
	}
	str[i]=0;   // put 0 instead of # after the string is all sent 
}



void UART_SendString_ChkSum(u8*str)   // check sum 
{
	u8 i=0;
	u16 sum=0;
	for (i=0;str[i];i++){
		sum=sum+str[i];   // sum of letters in hex 
	}
	UART_TX(i);   // number of letters in the string 
	
	for (i=0;str[i];i++){
		UART_TX(str[i]);
	}
	UART_TX(sum);    
	UART_TX(sum>>8);
	
}

u8 UART_ReceiveString_ChkSum(u8*str)
{
	u8 i,length,byte_1,byte_2;
	u16 sum_rece,sum=0;
	length=UART_RX();
	for (i=0;i<length;i++)
	{
		str[i]=UART_RX();
		if(i==3)
		str[i]='d';
		sum=sum+str[i];
	}
	byte_1=UART_RX();
	byte_2=UART_RX();
	sum_rece=byte_1|(u16)byte_2<<8;
	
	LCD_SetPos(1,0);
	LCD_writeNumber_4D(length);
	LCD_WriteChar('-');
	LCD_writeNumber_4D(sum);
	LCD_WriteChar('-');
	LCD_writeNumber_4D(sum_rece);
	
	
	/******************************************/
	if (sum==sum_rece)
	{
		return 1;
	}
	else
	return 0;

}

u8 get_flag(void)
{
	return endflag;
}


/*******************************************************/
void UART_SendString_Asynch(u8*str)
{
	UART_TX_InterruptEnable();
	UART_SendNoBlock(str[0]);
	PsendData=str;
}

void UART_ReceiveString_Asynch(u8*str)
{
		UART_RX_InterruptEnable();
		PreceiveData=str;
}
