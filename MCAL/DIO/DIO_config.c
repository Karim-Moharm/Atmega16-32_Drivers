
/*
 * DIO_lcfg.c
 *
 * Created: 10/20/2022 10:19:09 PM
 * Author: Karim Moharm
 */ 

#include "DIO_interface.h"

// configuration file contains pin status
const DIO_pin_state pin_status_array[TOTAL_PINS] = {
	IN_PLDOWN,   /* PORT A PIN 0*/  // sensor pin
	OUTPUT,   /* PORT A PIN 1*/
	OUTPUT,    /* PORT A PIN 2*/
	IN_PLDOWN,    /* PORT A PIN 3*/	   
	IN_PLDOWN,    /* PORT A PIN 4*/	   
	IN_PLDOWN,    /* PORT A PIN 5*/	   
	IN_PLDOWN,    /* PORT A PIN 6*/	   
	IN_PLDOWN,    /* PORT A PIN 7*/	   
	
	/*	B	*/
	OUTPUT,   /* PORT B PIN 0*/
	OUTPUT,  /* PORT B PIN 1*/
	OUTPUT,   /* PORT B PIN 2*//*INT2*/
	OUTPUT,   /* PORT B PIN 3*//*OC0*/
	OUTPUT,   /* PORT B PIN 4*/
	OUTPUT,   /* PORT B PIN 5*/
	OUTPUT,   /* PORT B PIN 6*/
	OUTPUT,   /* PORT B PIN 7*/
	
	/*	C	*/
	OUTPUT,   /* PORT C PIN 0*/
	OUTPUT,   /* PORT C PIN 1*/
	OUTPUT,   /* PORT C PIN 2*/
	OUTPUT,   /* PORT C PIN 3*/
	OUTPUT,   /* PORT C PIN 4*/
	OUTPUT,   /* PORT C PIN 5*/
	OUTPUT,   /* PORT C PIN 6*/
	OUTPUT,   /* PORT C PIN 7*/
	
	/*	D	*/
	OUTPUT,   /* PORT D PIN 0*/
	OUTPUT,   /* PORT D PIN 1*/
	OUTPUT,   /* PORT D PIN 2*//*INT0*/
	OUTPUT,   /* PORT D PIN 3*/
	OUTPUT,   /* PORT D PIN 4*//* OCR1B*/
	OUTPUT,   /* PORT D PIN 5*//* OCR1A*/
	OUTPUT,   /* PORT D PIN 6*//*ICP1*/
	OUTPUT,   /* PORT D PIN 7*/
	
		
	
};