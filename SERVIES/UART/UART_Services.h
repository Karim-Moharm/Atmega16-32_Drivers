/*
 * UART_SERVICES.h
 *
 * Created: 11/29/2022 5:54:10 PM
 *  Author: Karim Moharm
 */ 


#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_

#include "data_types.h"
#include "MCAL/USART/uart_driver.h"

void UART_Send_Int(u32 num);
u32 UART_Receive_Int(void);

void UART_Send_String(u8 *str);
void UART_Receive_String(u8*str);

void UART_SendString_ChkSum(u8*str);
u8 UART_ReceiveString_ChkSum(u8*str);

void UART_SendString_Asynch(u8*str);
void UART_ReceiveString_Asynch(u8*str);

u8 get_flag(void);



#endif /* UART_SERVICES_H_ */