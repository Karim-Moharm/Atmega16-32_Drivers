

#ifndef SENSORS_H_
#define SENSORS_H_

#include "ADC/ADC.h"
#include "data_types.h"

#define POT_PIN	ADC0
#define LM_PIN  ADC1
#define MPX_PIN ADC2

u16 POT_volt (void);
u16 lm35 (void);
u16 pressure_sens (void);

#endif /* SENSORS_H_ */