#ifndef _SENSOR_H
#define _SENSOR_H


#define SENSOR_STATUS_OK     (0)
#define SENSOR_STATUS_ERR   (-1)

/** 
*    @brief  Sensor initialization
*    @retval Status code
*/
int32_t sensorInit(void);

/** 
*    @brief  Readin raw value from temperature sensor
*    @param  Pointer to save read value
*    @retval Status code
*/
int32_t sensorRawRead(uint16_t *val);



#endif