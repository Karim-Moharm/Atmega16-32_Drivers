/*
 * uart_driver.c
 *
 * Created: 11/29/2022 1:37:51 AM
 *  Author: Karim Moharm
 */ 

#include "USART/uart_driver.h"
void UART_INIT(void)
{
	
	//baud rate 9600 
	UBRRL=51;      // 51 from the table in page 167 in datesheet 
	//TX, RX enable 
	set_bit(UCSRB,TXEN);
	set_bit(UCSRB,RXEN);
}

void UART_TX(u8 data)   // transmit (send data)
{
	while(!read_bit(UCSRA,UDRE));
	UDR=data;
}
u8 UART_RX(void)   // receiver 
{
	while(!read_bit(UCSRA,RXC));
	return UDR;
}

void UART_SendNoBlock(u8 data)
{
	UDR=data;
}
u8 UART_ReceiveNoBlock(void)
{
	return UDR;
}

void UART_RX_InterruptEnable(void)
{
	set_bit(UCSRB,RXCIE);
}

void UART_RX_InterruptDisable(void)
{
	clear_bit(UCSRB,RXCIE);
}

void UART_TX_InterruptEnable(void)
{
	set_bit(UCSRB,TXCIE);
}

void UART_TX_InterruptDisable(void)
{
	clear_bit(UCSRB,TXCIE);
}

void send_string (u8*str){
	u8 i=0;
	for(i=0;str[i];i++){
		UART_TX(str[i]);
		
	}
}