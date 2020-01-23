#ifndef _DATALINK_H
#define _DATALINK_H


/** 
*    @brief Data link intitialization
*/
void dataLinkInit(void);

/** 
*    @brief Send message to the Communication interface message queue
*    @param data  Data pointer
*    @param len   Data size
*/
void dataLinkWriteData(char *data, uint32_t len);


#endif