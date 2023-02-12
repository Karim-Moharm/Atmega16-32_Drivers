/*
 * LM35_sensor.h
 *
 * Created: 12/5/2022 1:36:48 AM
 *  
 */ 


#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "data_types.h"
#include "ADC2/adc_driver_2.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         ADC0
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/



/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
u8 LM35_getTemperature(void);



#endif /* LM35_SENSOR_H_ */