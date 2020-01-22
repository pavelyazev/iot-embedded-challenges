#ifndef _CI_H
#define _CI_H

typedef enum
{
    _RX_DATA_AVAILABLE_,   // To inform communication interface about data availability 
                           // in data link (like UART, network interface, etc.)
    _SEND_TEMP_,           // To temperature value via data link               

} CiMsgID_t;

/** 
*    @brief Communication interface intitialization
*/
void ciInit(void);

/** 
*    @brief Send message to the Communication interface message queue
*    @param id   Message ID
*    @param arg  Optional argument
*/
void ciSendMsg(CiMsgID_t id, uint16_t arg);


#endif
