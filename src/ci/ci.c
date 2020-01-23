#include "cmsis_os.h"
#include "ci.h"
#include "controller.h"


#define CI_THREAD_STACK_SIZE  200
#define CI_MESSAGE_QUEUE_LEN   4

/** 
*    @brief Definition communication interface message structure 
*    
*/
typedef struct 
{
    uint16_t id;
    uint16_t arg;  
} CiMsg_t;


typedef union
{
    CiMsg_t msg;
    uint32_t info;
} CiMsgQItem_t;


/*
*    Function prototypes
*/
static void ciThread(void const * arg);

/*
*    Static variables 
*/
static osMessageQId ciMsgQ;



void ciInit(void)
{
    // Communication interface thread creation
    osThreadDef(ci_thread, ciThread, osPriorityNormal, 0, CI_THREAD_STACK_SIZE);
    osThreadCreate(osThread(ci_thread), NULL);

    // Communication interface Message Queue creation
    osMessageQDef(ci_msgq, CI_MESSAGE_QUEUE_LEN, CiMsgQItem_t);
    ciMsgQ = osMessageCreate(osMessageQ(ci_msgq), NULL);
}



void ciSendMsg(CiMsgID_t id, uint16_t arg)
{
    CiMsgQItem_t msgItem = {.msg.id = id, .msg.arg = arg};
	osMessagePut(ciMsgQ, msgItem.info, 0);
}


void ciProcessDataFromDataLink(void)
{
    /*  Here we should read all available data from data link buffer
    *   
    *   while(dataLinkIsDataAvailable())
    *      dataLinkReadData();
    * 
    *   Then frame boundary detected, frame decoded
    *
    *   After frame decoding and data extracting
    *   the controller may be notified by the following ways
    * 
    *   controllerSendMsg(_UPDATE_MIN_TEMP_, minTemp);
    *   controllerSendMsg(_UPDATE_MAX_TEMP_, maxTemp);
    */ 
}

void ciSendTemp(uint16_t temp)
{
    /*
    *   Here temp data should be encoded, data frame should be prepared
    *   Frame data should be sent to data link layer
    * 
    *   dataLinkWriteData(frameData);
    */
}


/*
*  Process incomming message
*/
static void ciHandleMsg(CiMsg_t msg)
{
    switch(msg.id)
    {
        case _RX_DATA_AVAILABLE_:
            ciProcessDataFromDataLink();
        break; 

        case _SEND_TEMP_:
            ciSendTemp(msg.arg);
        break;
    }
}


static void ciThread(void const * arg)
{    

    while(1)
    {
	    osEvent msg = osMessageGet(ciMsgQ, osWaitForever);
       	if(msg.status != osEventMessage)
		    continue;

        CiMsgQItem_t msgItem = {.info = msg.value.v};
        ciHandleMsg(msgItem.msg);
    }
}

