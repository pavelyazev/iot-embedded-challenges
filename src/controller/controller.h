#ifndef _CONTROLLER_H
#define _CONTROLLER_H

typedef enum
{
    _TMR_,

} MsgID_t;

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


#endif