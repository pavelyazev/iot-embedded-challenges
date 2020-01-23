#include "cmsis_os.h"
#include "platform.h"
#include "controller.h"
#include "datalink.h"
#include "ci.h"



int main(void)
{
    platformInit();
    controllerInit();
    dataLinkInit();
    ciInit();

    // Start FreeRTOS scheduler
    osKernelStart(NULL, NULL);

    return 0;
}

