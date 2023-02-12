/*
 * LCD_config.c
 *
 * Created: 10/21/2022 11:14:46 PM
 *  Author: Karim Moharm
 */ 
#include "MCAL/DIO/DIO_interface.h"


/*****************************	CONFIGURATION   **********************/
// edited by the USER

#define LCD_MODE	_8_bit



/* for 8-bit mode */
#define LCD_PORT	PD	//the port where you will interface your LCD

/* for 4-bit mode */
#define D4		PIND4  //the pins where you will interface your LCD
#define D5		PIND5
#define D6		PORTA
#define D7		PIND7


#define RS		PINC0	// the pin for register selection (RS) on LCD
#define RW		PINC1	// the pin for R/W on the LCD
#define EN		PINC2	// for E symbol on the LCD




/**********************************************************************/
