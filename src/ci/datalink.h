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

/** 
*    @brief Send message to the Communication interface message queue
*    @retval 1 - if data available, 0 - otherwise
*/
uint32_t dataLinkIsDataAvailable(void);

/** 
*    @brief Get data from data link buffer
*    @param buf      Pointer to store data
*    @param bufSize  Max number bytes to be read
*    @retval  Actual number of bytes read
*/
uint32_t dataLinkReadData(char *buf, uint32_t bufSize);

#endif