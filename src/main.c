#include "cmsis_os.h"
#include "platform.h"
#include "controller.h"




int main(void)
{
    platformInit();
    controllerInit();

    // Start FreeRTOS scheduler
    osKernelStart(NULL, NULL);

    return 0;
}

