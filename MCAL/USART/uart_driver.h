/*
 * uart_driver.h
 *
 * Created: 11/29/2022 1:38:11 AM
 *  Author: Karim Moharm
 */ 


#ifndef UART_DRIVER_H_
#define UART_DRIVER_H_

#include "data_types.h"
#include "Mem_Map.h"
#include "bitwise.h"

void UART_INIT(void);
void UART_TX(u8 data);
u8 UART_RX(void); 
void UART_RX_InterruptEnable(void);
void UART_RX_InterruptDisable(void);
void UART_TX_InterruptEnable(void);
void UART_TX_InterruptDisable(void);
void send_string (u8*str);




#endif /* UART_DRIVER_H_ */