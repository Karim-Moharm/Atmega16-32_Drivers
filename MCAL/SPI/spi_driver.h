/*
 * spi_driver.h
 *
 * Created: 12/3/2022 1:58:26 AM
 *  Author: Karim Moharm
 */ 


#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_

#include "data_types.h"
#include "../../bitwise.h"
#include "../../Mem_Map.h"


typedef enum {
	F_osc2,
	F_osc4
	}SCK_freq;
	
typedef enum {
	SPI_Mode0,
	SPI_Mode1,
	SPI_Mode2,
	SPI_Mode3
	}SPI_Mode;

void SPI_MasterINIT(SCK_freq ocs_freq,SPI_Mode Mode);
void SPI_SlaveINIT(SPI_Mode Mode);

u8 SPI_Send_Receive(u8 data);
void SPI_SendNoBlock(u8 data);
u8 SPI_ReceiveNoBlock(void);
u8 SPI_Receive_with_Checking(u8*data);



#endif /* SPI_DRIVER_H_ */