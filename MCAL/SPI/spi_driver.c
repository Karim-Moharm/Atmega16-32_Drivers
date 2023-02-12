/*
 * spi_driver.c
 *
 * Created: 12/3/2022 1:58:10 AM
 *  Author: Karim Moharm
 */ 

#include "SPI/spi_driver.h"

void SPI_MasterINIT(SCK_freq ocs_freq,SPI_Mode Mode)
{
	// master 
	set_bit(SPCR,MSTR);
	
	// clock for master 
	switch (ocs_freq)
	{
		case F_osc4:			/*oscillator frequency divided by 4*/
		clear_bit(SPCR,SPR0);	clear_bit(SPCR,SPR1);	clear_bit(SPCR,SPI2X);	break;
		case F_osc2:			/*oscillator frequency divided by 2*/
		clear_bit(SPCR,SPR0);	clear_bit(SPCR,SPR1);	set_bit(SPCR,SPI2X);	break;
		
	}
	
	// SPI polarity and clock phase 
	switch(Mode)
	{
		case SPI_Mode0:
		clear_bit(SPCR,CPOL); clear_bit(SPCR,CPHA);		break;
		case SPI_Mode1:
		clear_bit(SPCR,CPOL); set_bit(SPCR,CPHA);		break;
		case SPI_Mode2:
		set_bit(SPCR,CPOL); clear_bit(SPCR,CPHA);		break;
		case SPI_Mode3:
		set_bit(SPCR,CPOL); set_bit(SPCR,CPHA);			break;
	}
	
	//SPI Enable
	set_bit(SPCR,SPE);
}

void SPI_SlaveINIT(SPI_Mode Mode)
{
	// slave
	clear_bit(SPCR,MSTR);
	
	// SPI polarity and clock phase
	switch(Mode)
	{
		case SPI_Mode0:
		clear_bit(SPCR,CPOL); clear_bit(SPCR,CPHA);		break;
		case SPI_Mode1:
		clear_bit(SPCR,CPOL); set_bit(SPCR,CPHA);		break;
		case SPI_Mode2:
		set_bit(SPCR,CPOL); clear_bit(SPCR,CPHA);		break;
		case SPI_Mode3:
		set_bit(SPCR,CPOL); set_bit(SPCR,CPHA);			break;
	}
	//SPI Enable
	set_bit(SPCR,SPE);
}

u8 SPI_Send_Receive(u8 data)
{
	// send data 
	SPDR=data;
	while(!read_bit(SPSR,SPIF));  
	 /* When a serial transfer is complete (the data completely being sent), the SPIF Flag is set, so cpu will get out from the pooling until spif bit is 1
	 (stuck in the pooling as long as the bit not equal 1) */
	 
	 // after that we can receive the data
	 return SPDR;
}

void SPI_SendNoBlock(u8 data)   /* used to send data in slave only and with interrupt */
{
	SPDR=data;
}

u8 SPI_ReceiveNoBlock(void)
{
	return SPDR;
}

u8 SPI_Receive_with_Checking(u8*data)
{
	if(read_bit(SPSR,SPIF)){
		*data=SPDR;
		return 1;
	}
	else
		return 0;
}