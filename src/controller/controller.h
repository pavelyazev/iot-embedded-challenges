#ifndef _CONTROLLER_H
#define _CONTROLLER_H

typedef enum
{
    _POLL_TEMP_SENSOR_,
    _UPDATE_VALVE_,
    _UPDATE_MIN_TEMP_,
    _UPDATE_MAX_TEMP_,
    
} MsgID_t;

/** 
*    @brief Definition control message structure 
*    
*/
typedef struct 
{
    uint16_t id;
    uint16_t arg;  
} CtrlMsg_t;


typedef union
{
    CtrlMsg_t msg;
    uint32_t info;
} MsgQItem_t;

/** 
*    @brief Controller intitialization
*/
void controllerInit(void);

/** 
*    @brief Send message to the controller message queue
*    @param id   Message ID
*    @param arg  Optional argument
*/
void controllerSendMsg(MsgID_t id, uint16_t arg);

#endif