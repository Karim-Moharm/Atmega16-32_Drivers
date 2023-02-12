/*
 * LCD.h
 *
 * Created: 10/21/2022 10:18:58 PM
 *  Author: Karim Moharm
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "MCAL/DIO/DIO_interface.h"
#include "../../data_types.h"

#define F_CPU 8000000UL
#include <util/delay.h>

#define		_4_bit	 0
#define		_8_bit	 1

/****************************************/


  /*	functions prototype		*/
void LCD_WriteCommand (u8 command );
void LCD_WriteData (u8 data);
void LCD_INIT(void);

void LCD_Clear (void);
void LCD_SetPos (u8 line, u8 x);		// set DDRAM address
void LCD_CreatePattern(u8 *pattern,u8 block_num);
void LCD_correctsign (void);
void LCD_CursorOn(void);
void LCD_CursorOff(void);

void LCD_WriteChar(u8 c);
void LCD_WriteString (u8 *str);
void LCD_WriteString_IN(u8 line,u8 x, u8 *string);
void LCD_writeChar_IN(u8 line,u8 x, u8 ch);

void LCD_WriteNumber_S64(s64 number);
void LCD_WriteNumber_S16 (s16 number);
void LCD_WriteNumber_S32 (s32 number);
void LCD_writeNumber_IN(u8 line,u8 x, s64 number);
void LCD_writeNumber_4D (u16 number);
void LCD_writeNumber_3D (u8 number);
void LCD_WriteFloat(u32 number,u16 number_after_point);
void LCD_WriteBinary(u8 num);
void LCD_writeBinary_without0(u8 num);
void LCD_writeFloat_IN(u8 line,u8 x, u32 number,u16  number_after_point);



#endif /* LCD_H_ */