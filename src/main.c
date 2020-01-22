#include "cmsis_os.h"
#include "platform.h"
#include "controller.h"
#include "ci.h"



int main(void)
{
    platformInit();
    controllerInit();
    ciInit();

    // Start FreeRTOS scheduler
    osKernelStart(NULL, NULL);

    return 0;
}

