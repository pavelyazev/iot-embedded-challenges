#ifndef _VALVE_H
#define _VALVE_H

#define VALVE_STATUS_OK     (0)
#define VALVE_STATUS_ERR   (-1)

/** 
*    @brief  Valve initialization
*    @retval Status code
*/
int32_t valveInit(void);

/** 
*    @brief  Setup valve
*    @param  Valve state binary on/off or some opening percentage
*    @retval Status code
*/
int32_t valveSetup(uint16_t val);


#endif
