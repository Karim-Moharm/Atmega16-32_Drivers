/*
 * KM_sensor_2.h
 *
 * Created: 12/10/2022 3:23:03 AM
 *  Author: YN
 */ 


#ifndef KM_SENSOR_2_H_
#define KM_SENSOR_2_H_

#include "../../../../SERVIES/ADC/ADC_services.h"
u16 LM35_Read(ADC_INChannel channel);
u16 LM35_Read_Float(ADC_INChannel channel);



#endif /* KM_SENSOR_2_H_ */