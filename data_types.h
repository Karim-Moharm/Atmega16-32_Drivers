
#ifndef DATA_TYPES_H_
#define DATA_TYPES_H_


typedef unsigned char u8;   // 8 bits 
typedef signed char s8; 
typedef volatile unsigned char v8;   
typedef unsigned short  u16;   // 16 bits
typedef signed short  s16;
typedef unsigned long u32;
typedef signed long s32;
typedef unsigned long long u64;
typedef signed long long s64;
typedef float f32;

#define NULL_ptr ((void*)0)

typedef enum{false,true} bool_t ;   // false>> 0       // true>> 1



#endif /* DATA_TYPES_H_ */