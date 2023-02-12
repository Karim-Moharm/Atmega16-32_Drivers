/*
 * Key_Pad.c
 *
 * Created: 10/23/2022 2:49:16 PM
 *  Author: Karim Moharm
 */ 

#include "KeyPad.h"
#include "Keypad_config.h"

static const u8 KeyPad_array [ROWs][COLs]={ {7,8,9,'/'}, 
										{4,5,6,'*'},
										{1,2,3,'-'},
										{'c',0,'=','+'}, };
										  

u8 KP_getButton(void)
{
	u8 R,C, key= DEFAULT_KEY;
	 /* initializing all OUT pins as HIGH as input is PULL-	UP*/
	DIO_writePin(FIRST_OUT,HIGH); 
	DIO_writePin(FIRST_OUT+1,HIGH); 
	DIO_writePin(FIRST_OUT+2,HIGH); 
	DIO_writePin(FIRST_OUT+3,HIGH); 
	
	
	for (R=0; R<ROWs; R++ )
	{
		DIO_writePin(FIRST_OUT+R, LOW);  
		for (C=0; C<COLs; C++)
		{
			if (! DIO_ReadPin(FIRST_IN+C) )  // if the any pin of input pins was low, means the user click on that button 
			{
				
				key=KeyPad_array[R][C];
				while(! DIO_ReadPin(FIRST_IN+C) );		//pooling
			}
			
		} DIO_writePin(FIRST_OUT+R , HIGH);	// check if any pins of input is low then return the o/p pin to high  
					
		
	}  return key;



	
}

