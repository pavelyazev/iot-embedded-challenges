
#include "libopencm3/stm32/rcc.h"


// Definition for FreeRTOS
uint32_t SystemCoreClock = 168000000;



void platform_init(void)
{
    rcc_clock_setup_pll(&rcc_hse_8mhz_3v3[RCC_CLOCK_3V3_168MHZ]);
}
