/*
 * LM35_sensor.c
 *
 * Created: 12/5/2022 1:36:33 AM
 * 
 */ 

#include "HAL/Sensors/LM35_sensor/LM35_sensor.h"
#include "ADC2/adc_driver_2.h"

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
u8 LM35_getTemperature(void)
{
	u8 temp_value = 0;

	u16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_read_2(SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	temp_value = (u8)(((u32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}
