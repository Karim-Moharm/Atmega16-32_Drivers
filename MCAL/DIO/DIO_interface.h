
/*
 * DIO_interface.h
 *
 * Created: 10/20/2022 10:19:09 PM
 *  Author: Karim Moharm
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#include "bitwise.h"
#include "data_types.h"
#include "Mem_Map.h"

typedef enum {
	PINA0=0,PINA1,PINA2,PINA3,PINA4,PINA5,PINA6,PINA7,  //PA
	
	PINB0,PINB1,PINB2,PINB3,PINB4,PINB5,PINB6,PINB7,   //PB
	
	PINC0,PINC1,PINC2,PINC3,PINC4,PINC5,PINC6,PINC7,   //PC
	
	PIND0,PIND1,PIND2,PIND3,PIND4,PIND5,PIND6,PIND7,   //PD
	
	TOTAL_PINS
}DIO_pin_type;

typedef enum {
	LOW=0,
	HIGH=1
}DIO_pin_voltage;

typedef enum {
	OUTPUT,
	IN_PLDOWN,
	IN_PLUP
	
}DIO_pin_state;

typedef enum {
			PA,
			PB,
			PC,
			PD
} DIO_PORTS;

// first we declare a function to initialize your pin to be input or output
void DIO_initPin(DIO_pin_type pin,DIO_pin_state status );

//function to write 5v or 0v on the bin from the user
void DIO_writePin(DIO_pin_type pin,DIO_pin_voltage volt );

// toggle pin
void DIO_togglepin(DIO_pin_type pin);

// function to read the pin and return HIGH or LOW
DIO_pin_voltage DIO_ReadPin(DIO_pin_type pin);

u8 DIO_readPorts(DIO_PORTS port);

void DIO_writePorts(DIO_PORTS port,u8 data);

void DIO_INIT(void);

extern const DIO_pin_state pin_status_array[TOTAL_PINS];

#endif /* DIO_INTERFACE_H_ */ 