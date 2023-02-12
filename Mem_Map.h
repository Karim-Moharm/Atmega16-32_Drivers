
/*
 * Mem_Map.h
 *
 * Created: 10/21/2022 8:25:38 PM
 * Author: Karim Moharm
 */ 

#ifndef MEM_MAP_H_
#define MEM_MAP_H_

/********************************	DIO		********************************************************************/
/******************************************************************************************************/
/***********PORTA**********/
#define PORTA	(*(volatile unsigned char *)0x3B)
#define DDRA	(*(volatile unsigned char *)0x3A)
#define PINA	(*(volatile unsigned char *)0x39)
/***********PORTB**********/
#define PORTB   (*(volatile unsigned char *)0x38)
#define DDRB	(*(volatile unsigned char *)0x37)
#define PINB	(*(volatile unsigned char *)0x36)
/***********PORTC**********/
#define PORTC	(*(volatile unsigned char *)0x35)
#define DDRC	(*(volatile unsigned char *)0x34)
#define PINC	(*(volatile unsigned char *)0x33)
/***********PORTD**********/
#define PORTD   (*(volatile unsigned char *)0x32)
#define DDRD	(*(volatile unsigned char *)0x31)
#define PIND	(*(volatile unsigned char *)0x30)



/********************************	ADC 	***************************************************************************/
/***************************************************************************************************************/

#define ADMUX (*(v8 *)0x27)		//ADC Multiplexer Selection Register   // v8 means volatile unsigned char
#define ADCSRA (*(v8 *)0x26)	//ADC Control and Status Register A
#define ADCH (*(v8 *)0x25)		//ADC Data Register High Byte
#define ADCL (*(v8 *)0x24)		//ADC Data Register low Byte


#define REFS0	6
#define REFS1	7
#define ADC_data (*(u16 *)0x24);    // 0x24 and 0x25 because it is a pointer   // u16>> unsigned short  (2 bytes )


/* ACSR */

#define ACD     7
#define ACBG    6
#define ACO     5
#define ACI     4
#define ACIE    3
#define ACIC    2
#define ACIS1   1
#define ACIS0   0


/* ADCSRA */

#define ADEN    7
#define ADSC    6
#define ADATE   5
#define ADIF    4
#define ADIE    3
#define ADPS2   2
#define ADPS1   1
#define ADPS0   0

/* ADMUX */

#define REFS1   7
#define REFS0   6
#define ADLAR   5
#define MUX4    4
#define MUX3    3
#define MUX2    2
#define MUX1    1
#define MUX0    0

/********************************	INTERRUPT 	****************************************************************************/
/***************************************************************************************************************/


/*	assembly function for interrupt */
#define NULLptr (void*)0
#define sei()		__asm__ __volatile__ ("sei" ::)  // set the global interrupt
#define cli()		__asm__ __volatile__ ("cli" ::)  // clear the global interrupt
#define reti()		__asm__ __volatile__ ("reti" ::)  // return function for interrupt, used to set the global interrupt after finishing the interrupt function 
#define ret()		__asm__ __volatile__ ("ret" ::)   // return 

/* interrupt vector functions */
//#define RESET_VECT							__vector_1

#define INT0_VECT							__vector_1		// external interrupt 0
#define INT1_VECT							__vector_2		// external interrupt 1
#define INT2_VECT							__vector_3		// external interrupt 2
#define TIMER2_COMP_VECT					__vector_4
#define TIMER2_OVF_VECT						__vector_5
#define TIMER1_CAPT_VECT					__vector_6
#define TIMER1_COMPA_VECT					__vector_7
#define TIMER1_COMPB_VECT					__vector_8
#define TIMER1_OVF_VECT						__vector_9
#define TIMER0_COMP_VECT					__vector_10		//Timer/Counter0 Output Compare Match Interrupt 
#define TIMER0_OVF_VECT						__vector_11     // Timer/Counter0 Overflow Interrupt 
#define SPI_STC_VECT						__vector_12
#define USART_RXC_VECT						__vector_13
#define USART_UDRE_VECT						__vector_14
#define USART_TXC_VECT						__vector_15
#define ADC_VECT							__vector_16
#define EE_RDY_VECT							__vector_17
#define ANA_COMP_VECT						__vector_18
#define TWI_VECT							__vector_19
#define SPM_RDY_VECT						__vector_20

#define ISR(vector)  \
void vector (void)__attribute__((signal));	\
void vector (void)		
/* GICR */
#define INT1    7
#define INT0    6
#define INT2    5
#define IVSEL   1
#define IVCE    0

/* GIFR */
#define INTF1   7
#define INTF0   6
#define INTF2   5

/* MCUCR */
#define SE      7
#define SM2     6
#define SM1     5
#define SM0     4
#define ISC11   3
#define ISC10   2
#define ISC01   1
#define ISC00   0

/* MCUCSR */
#define JTD     7
#define ISC2    6


/********************************	TIMER	****************************************************************************/
/***************************************************************************************************************/


#define TCCR0 (*(volatile unsigned char*)0x53)
#define TCNT0 (*(volatile unsigned char*)0x52)
#define TIMSK (*(volatile unsigned char*)0x59)
#define TIFR (*(volatile unsigned char*)0x58)
#define OCR0 (*(volatile unsigned char*)0x5c)
#define TCCR1A (*(volatile unsigned char*)0x4F)
#define TCCR1B (*(volatile unsigned char*)0x4E)
#define OCR1AH (*(volatile unsigned char*)0x4B)
#define OCR1AL (*(volatile unsigned char*)0x4A)
#define OCR1A (*(volatile unsigned short*)0x4A)
#define OCR1BH (*(volatile unsigned char*)0x49)
#define OCR1BL (*(volatile unsigned char*)0x48)
#define OCR1B (*(volatile unsigned short*)0x48)
#define ICR1H (*(volatile unsigned char*)0x47)
#define ICR1L (*(volatile unsigned char*)0x46)
#define ICR1 (*(volatile unsigned short*)0x46)
#define TCCR2 (*(volatile unsigned char*)0x45)
#define TCNT2 (*(volatile unsigned char*)0x44)
#define TCNT1H  (*(volatile unsigned char *)0x4D)
#define TCNT1L  (*(volatile unsigned char *)0x4C)
#define TCNT1	(*(volatile unsigned short *)0x4C)

/* TCCR0 */
#define FOC0    7
#define WGM00   6		//Waveform Generation Mode
#define COM01   5
#define COM00   4     
#define WGM01   3	   // Waveform Generation Mode
#define CS02    2      // for prescaling 
#define CS01    1	   // for prescaling 
#define CS00    0	   // for prescaling 

/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1	// Timer/Counter0 Output Compare Match Interrupt Enable
#define TOIE0   0	// Timer/Counter0 Overflow Interrupt Enable

/* TIFR */
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0

/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

/* TCCR1B */
#define ICNC1   7
#define ICES1   6      // Input Capture Edge Select
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2   //  prescaler 
#define CS11    1   //  prescaler 	
#define CS10    0   //  prescaler 


/********************************	USART 	****************************************************************************/
/***************************************************************************************************************/

/* USART */
#define UBRRL   (*(volatile unsigned char*)0x29)
#define UCSRB    (*(volatile unsigned char*)0x2A)
#define UCSRA    (*(volatile unsigned char*)0x2B)
#define UCSRC    (*(volatile unsigned char*)0x40)
#define UBRRH    (*(volatile unsigned char*)0x40)
#define UDR     (*(volatile unsigned char*)0x2C)
/* UCSRA */
#define RXC     7
#define TXC     6
#define UDRE    5
#define FE      4
#define DOR     3
#define PE      2
#define U2X     1
#define MPCM    0

/* UCSRB */
#define RXCIE   7
#define TXCIE   6
#define UDRIE   5
#define RXEN    4
#define TXEN    3
#define UCSZ2   2
#define RXB8    1
#define TXB8    0

/* UCSRC */
#define URSEL   7
#define UMSEL   6
#define UPM1    5
#define UPM0    4
#define USBS    3
#define UCSZ1   2
#define UCSZ0   1
#define UCPOL   0
/********************************	SPI 	****************************************************************************/
/***************************************************************************************************************/

/* SPI */
/*	SPI control register */
#define SPCR    (*(volatile unsigned char*)0x2D)
/* SPI status register*/
#define SPSR    (*(volatile unsigned char*)0x2E)
/* SPI data register */
#define SPDR    (*(volatile unsigned char*)0x2F)

/* SPSR */
#define SPIF    7
#define WCOL    6
/* bits 5-1 reserved */
#define SPI2X   0

/* SPCR */
#define SPIE    7   /*SPI Interrupt Enable*/
#define SPE     6	/*SPI Enable*/
#define DORD    5
#define MSTR    4	/*Master/Slave Select*/  /* master when written to 1 and slave when written  to zero */
#define CPOL    3	/*Clock Polarity*/
#define CPHA    2	/*Clock Phase*/
#define SPR1    1
#define SPR0    0

#endif /* MEM_MAP_H_ */