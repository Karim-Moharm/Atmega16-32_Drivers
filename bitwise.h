

#ifndef BITWISE_H_
#define BITWISE_H_


#define read_bit(reg,bit)   ((reg>>bit)&1)		// read memory 
#define set_bit(reg,bit)    (reg|=(1<<bit))			// form 1 or 0 to __1__  < oring >
#define toggle_bit(reg,bit)  (reg^=(1<<bit))			// used to toggle the state of the pin
#define clear_bit(reg,bit)	  (reg&=~(1<<bit))	   	// form 1 or 0 to __0__  ( unset )  
#define GET_BIT(reg, bit)       ((reg>>bit) & 0x01)

#endif /* BITWISE_H_ */