
#include "cmsis_os.h"
#include "controller.h"


#define CONTROLLER_THREAD_STACK_SIZE (200)
#define CONTROLLER_MESSAGE_QUEUE_LEN  (4)

#define TIMER_PERIOD_MS              (1000)

static void controllerThread(void const * arg);
static void timerCallbackFunction(void const *arg);

static osMessageQId ctrlMsgQ;
static osTimerId    timerID;

void controllerInit(void)
{
    // Controller thread creation
    osThreadDef(ctrl_thread, controllerThread, osPriorityLow, 0, CONTROLLER_THREAD_STACK_SIZE);
    osThreadCreate(osThread(ctrl_thread), NULL);

    // Controller Message Queue creation
    osMessageQDef(ctrl_msgq, CONTROLLER_MESSAGE_QUEUE_LEN, MsgQItem_t);
    ctrlMsgQ = osMessageCreate(osMessageQ(ctrl_msgq), NULL);

    osTimerDef(timer, timerCallbackFunction);
    timerID = osTimerCreate (osTimer(timer), osTimerPeriodic, NULL);

    osTimerStart (timerID, TIMER_PERIOD_MS);
}


void controllerSendMsg(MsgID_t id, uint16_t arg)
{
    /*
    *  Current cmsis-rtos API can send only uint32 words
    *  So we pack a message into word
    */
    MsgQItem_t msgItem;
    msgItem.msg.id  = id;
    msgItem.msg.arg = arg;
	osMessagePut(ctrlMsgQ, msgItem.info, 0);
}



static void controllerThread(void const * arg)
{
    osEvent msg;
    while(1)
    {
	    msg = osMessageGet(ctrlMsgQ, osWaitForever);
       	if(msg.status != osEventMessage)
		    continue;



 
    }
}

void timerCallbackFunction(void const *arg)
{

}