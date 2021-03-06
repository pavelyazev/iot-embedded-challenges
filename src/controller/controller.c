
#include "cmsis_os.h"
#include "controller.h"
#include "ci.h"
#include "sensor.h"
#include "valve.h"

#define CONTROLLER_THREAD_STACK_SIZE  200
#define CONTROLLER_MESSAGE_QUEUE_LEN   4
#define TIMER_PERIOD_MS               1000
#define MAX_TEMP_CELSIUS_DEGREE        30 
#define MIN_TEMP_CELSIUS_DEGREE        20    
#define VALVE_INITIAL_STATE            0


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
} CtrlMsgQItem_t;


/*
*    Function prototypes
*/
static void controllerThread(void const * arg);
static void timerCallbackFunction(void const *arg);


/*
*    Static variables 
*/
static osMessageQId ctrlMsgQ;
static osTimerId    timerID;

static int16_t maxTemp = MAX_TEMP_CELSIUS_DEGREE;
static int16_t minTemp = MIN_TEMP_CELSIUS_DEGREE;


void controllerInit(void)
{
    // Controller thread creation
    osThreadDef(ctrl_thread, controllerThread, osPriorityLow, 0, CONTROLLER_THREAD_STACK_SIZE);
    osThreadCreate(osThread(ctrl_thread), NULL);

    // Controller Message Queue creation
    osMessageQDef(ctrl_msgq, CONTROLLER_MESSAGE_QUEUE_LEN, CtrlMsgQItem_t);
    ctrlMsgQ = osMessageCreate(osMessageQ(ctrl_msgq), NULL);

    osTimerDef(timer, timerCallbackFunction);
    timerID = osTimerCreate (osTimer(timer), osTimerPeriodic, NULL);    
}


void controllerSendMsg(CtrlMsgID_t id, uint16_t arg)
{   
    CtrlMsgQItem_t msgItem = {.msg.id = id, .msg.arg = arg};   
	osMessagePut(ctrlMsgQ, msgItem.info, 0);
}

static void controllerTempPollingPrepare(void)
{
    // Initialize temperature sensor and start polling if 
    // everything is Ok with the sensor
    uint32_t res = sensorInit();
    if(res == SENSOR_STATUS_OK)
    {
        // Start polling timer
        osTimerStart (timerID, TIMER_PERIOD_MS);
    }
    else
    {
        // Report error        
    }
}

static void controllerValvePrepare(void)
{
    // Initialize temperature sensor and start polling if 
    // everything is Ok with the sensor
    uint32_t res = valveInit();
    if(res == SENSOR_STATUS_OK)
    {
        res = valveSetup(VALVE_INITIAL_STATE); 
        // Check res here       
    }
    else
    {
        // Report error or do some action       
    }
}

/*
*   Reading temperature sensor
*/
static void controllerGetTemp(void)
{
    uint16_t rawTemp;

    int32_t res = sensorRawRead(&rawTemp);
    if(res == SENSOR_STATUS_OK)
    {
        controllerSendMsg(_UPDATE_VALVE_, rawTemp);
        ciSendMsg(_SEND_TEMP_, rawTemp);            // Send measured temperature via communication interface
    }
    else
    {
        // Report error or do some action       
    }    
}

static void controllerUpdateMinTemp(uint16_t temp)
{
    minTemp = temp;
}

static void controllerUpdateMaxTemp(uint16_t temp)
{
    maxTemp = temp;
}

/*
*   Dummy temperature converter. Provides actual temperature from raw sensor
*   measurement. 
*/
static int16_t tempCovertFromRaw(int16_t rawTemp)
{    
    return rawTemp;
}

/*
*   Here it is situated all logic to control a valve according
*   to the current temperature. In principle PID maybe used or other approaches.
*/
static void controllerUpdateValve(uint16_t rawTemp)
{        
    uint16_t newValveVal;
    int16_t curTemp = tempCovertFromRaw(rawTemp);

    // Relay valve control
    if(curTemp > maxTemp)
        newValveVal = VALVE_CLOSE_VAL;
    else if(curTemp < minTemp)
        newValveVal = VALVE_OPEN_VAL;
    
    int32_t res = valveSetup(newValveVal);
    if(res == SENSOR_STATUS_OK)
    {
        // Do something
    }
    else
    {
       // Report error or do some action        
    }
}

/*
*  Process incomming message
*/
static void controllerHandleMsg(CtrlMsg_t msg)
{
    switch(msg.id)
    {
        case _POLL_TEMP_SENSOR_:
            controllerGetTemp();
        break; 

        case _UPDATE_VALVE_:
            controllerUpdateValve(msg.arg);
        break;

        case _UPDATE_MIN_TEMP_:
            controllerUpdateMinTemp(msg.arg);
        break;

        case _UPDATE_MAX_TEMP_:
            controllerUpdateMaxTemp(msg.arg);
        break;
    }
}


static void controllerThread(void const * arg)
{    
    controllerTempPollingPrepare();
    controllerValvePrepare();    

    while(1)
    {
	    osEvent msg = osMessageGet(ctrlMsgQ, osWaitForever);
       	if(msg.status != osEventMessage)
		    continue;

        CtrlMsgQItem_t msgItem = {.info = msg.value.v};
        controllerHandleMsg(msgItem.msg);
    }
}

static void timerCallbackFunction(void const *arg)
{
    controllerSendMsg(_POLL_TEMP_SENSOR_, 0);
}