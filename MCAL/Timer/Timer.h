/*
 * Timer.h
 *
 * Created: 11/3/2022 3:35:16 PM
 *  Author: YN
 */ 

#include "data_types.h"
#include "Mem_Map.h"
#include "bitwise.h"

#ifndef TIMER_H_
#define TIMER_H_


/************************************  TIMER0  **************************************************************/
typedef enum {
			TIMER0_Normal,
			TIMER0_PWM,   //PWM, Phase Correct
			TIMER0_CTC,
			TIMER0_Fast_PWM
	}Timer0_Mode;
	
typedef enum {
			No_clock,   //No clock source (Timer/Counter stopped).
			CLK_1,
			CLK_8,
			CLK_64,
			CLK_256,
			CLK_1024,
			External_Falling,
			External_Rising
	}Timer_Prescaler;
	
typedef enum {    // for compare
			OC0_disconnected,
			OC0_Toggle,
			OC0_NON_Inverting,
			OC0_Inverting 
	}Timer0_OC_mode;


void Timer0_INIT(Timer0_Mode Mode,Timer_Prescaler scale,Timer0_OC_mode compare);
void Timer0_OV_enable(void);   //Timer/Counter0 Overflow Interrupt Enable
void Timer0_OV_disable(void);
void Timer0_OC_enable(void);   //Timer/Counter0 Output Compare Match Interrupt Enable
void Timer0_OC_disable(void);
void timer0_OC0_SetCallback_(void(*local_ptr)(void));
void timer0_OVF_SetCallback_(void(*local_ptr)(void));

/************************************  TIMER1  **************************************************************/

typedef enum {
			TIMER1_normal,
			TIMER1_CTC_OCR1A,
			TIMER1_Phase_and_Freq_Correct_ICR,
			TIMER1_Phase_Correct_ICR,
			TIMER1_Phase_Correct_OCR1A,
			TIMER0_CTC_ICR,
			TIMER1_fast_PWM_ICR1,
			TIMER1_fast_PWM_OCR1A
			}Timer1_Gen_mode;
			
typedef enum {    // for compare
	OC1A_disconnected,
	OC1A_Toggle,
	OC1A_NON_Inverting,
	OC1A_Inverting
}Timer1_OCA_mode;

typedef enum {    // for compare
	OC1B_disconnected,
	OC1B_Toggle,
	OC1B_NON_Inverting,
	OC1B_Inverting
}Timer1_OCB_mode;

typedef enum {
			ICP1_FALLING,
			ICP1_RISING
}ICU_EDGE_TYPE;

void Timer1_INIT(Timer1_Gen_mode Mode, Timer_Prescaler scale, Timer1_OCA_mode OCR_A, Timer1_OCB_mode OCR_B);
void Timer1_ICU_int_enable(void);
void Timer1_ICU_int_disable(void);
void Timer1_OC_A_int_enable(void);
void Timer1_OC_A_int_disable(void);
void Timer1_OC_B_int_enable(void);
void Timer1_OC_B_int_disable(void);
void Timer1_ovf_enable(void);
void Timer1_ovf_disable(void);
void Timer1_Input_CaptureEdge(ICU_EDGE_TYPE edge);
void Timer1_OVF_SetCallback_(void(*local_ptr)(void));
void Timer1_OCA_SetCallback_(void(*local_ptr)(void));
void Timer1_OCB_SetCallback_(void(*local_ptr)(void));
void Timer1_ICU_SetCallback_(void(*local_ptr)(void));

#endif /* TIMER_H_ */