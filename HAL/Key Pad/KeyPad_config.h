/*
 * KeyPad_config.h
 *
 * Created: 10/24/2022 2:49:16 PM
 *  Author:  Karim Moharm
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_


#include "KeyPad.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../data_types.h"


#define ROWs  4
#define COLs  4




/************   first OUTPUT pin ****************/
#define FIRST_OUT   PIND0

/************   first INPUT pin ****************/
#define FIRST_IN	PIND4

/************ the default key if no button is pressed ****************/
#define DEFAULT_KEY		'_'


#endif /* KEYPAD_CONFIG_H_ */