/*
 * EX_Int.h
 *
 * Created: 10/28/2022 11:24:25 AM
 *  Author: YN
 */ 


#ifndef EX_INT_H_
#define EX_INT_H_

#include "Mem_Map.h"
#include "data_types.h"
#include "bitwise.h"

typedef enum {
			EX_INT0,
			EX_INT1,
			EX_INT2
		}EXInterrupt_Source;
		
typedef enum {
			Low_Level,
			Any_Logic_change,
			Falling_Edge,
			Rising_Edge
			}EXInterrupt_Sense;   
	
	
void EXInt_Enable(EXInterrupt_Source INTSource);
void EXInt_Disable(EXInterrupt_Source INTSource);
void EXInt_Sense (EXInterrupt_Source INTSource,EXInterrupt_Sense sense);
void EXInt_SETCallBack (EXInterrupt_Source INTSource, void(*pf_local)(void));

#endif /* EX_INT_H_ */