/* This file is part of the libopencm3 project.
 *
 * It was generated by the irq2nvic_h script from ./include/libopencm3/pac55xx/irq.json
 */

#ifndef LIBOPENCM3_PAC55XX_H_
#define LIBOPENCM3_PAC55XX_H_

#include <libopencm3/cm3/nvic.h>

/** @defgroup CM3_nvic_defines_irqs User interrupts for PAC55XX Series
    @ingroup CM3_nvic_defines

    @{*/

#define NVIC_MEMCTL_IRQ 0
#define NVIC_WDT_IRQ 1
#define NVIC_RTC_IRQ 2
#define NVIC_ADC0_IRQ 3
#define NVIC_ADC1_IRQ 4
#define NVIC_ADC2_IRQ 5
#define NVIC_ADC3_IRQ 6
#define NVIC_TIMERA_IRQ 7
#define NVIC_TIMERB_IRQ 8
#define NVIC_TIMERC_IRQ 9
#define NVIC_TIMERD_IRQ 10
#define NVIC_TIMERA_QEP_IRQ 11
#define NVIC_TIMERB_QEP_IRQ 12
#define NVIC_TIMERC_QEP_IRQ 13
#define NVIC_TIMERD_QEP_IRQ 14
#define NVIC_GPIOA_IRQ 15
#define NVIC_GPIOB_IRQ 16
#define NVIC_GPIOC_IRQ 17
#define NVIC_GPIOD_IRQ 18
#define NVIC_GPIOE_IRQ 19
#define NVIC_GPIOF_IRQ 20
#define NVIC_GPIOG_IRQ 21
#define NVIC_I2C_IRQ 22
#define NVIC_USARTA_IRQ 23
#define NVIC_USARTB_IRQ 24
#define NVIC_USARTC_IRQ 25
#define NVIC_USARTD_IRQ 26
#define NVIC_CAN_IRQ 27
#define NVIC_GPTIMERA_IRQ 28
#define NVIC_GPTIMERB_IRQ 29
#define NVIC_SCC_IRQ 30

#define NVIC_IRQ_COUNT 31

/**@}*/

/** @defgroup CM3_nvic_isrprototypes_PAC55XX User interrupt service routines (ISR) prototypes for PAC55XX Series
    @ingroup CM3_nvic_isrprototypes

    @{*/

BEGIN_DECLS

void memctl_isr(void);
void wdt_isr(void);
void rtc_isr(void);
void adc0_isr(void);
void adc1_isr(void);
void adc2_isr(void);
void adc3_isr(void);
void timera_isr(void);
void timerb_isr(void);
void timerc_isr(void);
void timerd_isr(void);
void timera_qep_isr(void);
void timerb_qep_isr(void);
void timerc_qep_isr(void);
void timerd_qep_isr(void);
void gpioa_isr(void);
void gpiob_isr(void);
void gpioc_isr(void);
void gpiod_isr(void);
void gpioe_isr(void);
void gpiof_isr(void);
void gpiog_isr(void);
void i2c_isr(void);
void usarta_isr(void);
void usartb_isr(void);
void usartc_isr(void);
void usartd_isr(void);
void can_isr(void);
void gptimera_isr(void);
void gptimerb_isr(void);
void scc_isr(void);

END_DECLS

/**@}*/

#endif /* LIBOPENCM3_PAC55XX_H_ */
