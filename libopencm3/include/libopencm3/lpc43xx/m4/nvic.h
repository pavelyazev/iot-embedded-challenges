/* This file is part of the libopencm3 project.
 *
 * It was generated by the irq2nvic_h script from ./include/libopencm3/lpc43xx/m4/irq.json
 */

#ifndef LIBOPENCM3_LPC43xx_M4_NVIC_H
#define LIBOPENCM3_LPC43xx_M4_NVIC_H

#include <libopencm3/cm3/nvic.h>

/** @defgroup CM3_nvic_defines_irqs User interrupts for LPC 43xx series M4 core
    @ingroup CM3_nvic_defines

    @{*/

#define NVIC_EVENTROUTER_IRQ 42
#define NVIC_C_CAN1_IRQ 43
#define NVIC_WWDT_IRQ 49
#define NVIC_QEI_IRQ 52
#define NVIC_USART0_IRQ 24
#define NVIC_UART1_IRQ 25
#define NVIC_USART2_IRQ 26
#define NVIC_USART3_IRQ 27
#define NVIC_SPI_IRQ 20
#define NVIC_ADC1_IRQ 21
#define NVIC_SSP0_IRQ 22
#define NVIC_SSP1_IRQ 23
#define NVIC_ATIMER_IRQ 46
#define NVIC_RTC_IRQ 47
#define NVIC_I2S0_IRQ 28
#define NVIC_I2S1_IRQ 29
#define NVIC_GINT0_IRQ 40
#define NVIC_GINT1_IRQ 41
#define NVIC_M0CORE_IRQ 1
#define NVIC_DAC_IRQ 0
#define NVIC_DMA_IRQ 2
#define NVIC_ETHERNET_IRQ 5
#define NVIC_LCD_IRQ 7
#define NVIC_SDIO_IRQ 6
#define NVIC_USB1_IRQ 9
#define NVIC_USB0_IRQ 8
#define NVIC_C_CAN0_IRQ 51
#define NVIC_PIN_INT7_IRQ 39
#define NVIC_PIN_INT6_IRQ 38
#define NVIC_RITIMER_IRQ 11
#define NVIC_SCT_IRQ 10
#define NVIC_TIMER1_IRQ 13
#define NVIC_TIMER0_IRQ 12
#define NVIC_TIMER3_IRQ 15
#define NVIC_TIMER2_IRQ 14
#define NVIC_ADC0_IRQ 17
#define NVIC_MCPWM_IRQ 16
#define NVIC_I2C1_IRQ 19
#define NVIC_I2C0_IRQ 18
#define NVIC_SGPIO_IRQ 31
#define NVIC_SPIFI_IRQ 30
#define NVIC_PIN_INT5_IRQ 37
#define NVIC_PIN_INT4_IRQ 36
#define NVIC_PIN_INT3_IRQ 35
#define NVIC_PIN_INT2_IRQ 34
#define NVIC_PIN_INT1_IRQ 33
#define NVIC_PIN_INT0_IRQ 32

#define NVIC_IRQ_COUNT 53

/**@}*/

/** @defgroup CM3_nvic_isrprototypes_LPC43xx (M4) User interrupt service routines (ISR) prototypes for LPC 43xx series M4 core
    @ingroup CM3_nvic_isrprototypes

    @{*/

BEGIN_DECLS

void eventrouter_isr(void);
void c_can1_isr(void);
void wwdt_isr(void);
void qei_isr(void);
void usart0_isr(void);
void uart1_isr(void);
void usart2_isr(void);
void usart3_isr(void);
void spi_isr(void);
void adc1_isr(void);
void ssp0_isr(void);
void ssp1_isr(void);
void atimer_isr(void);
void rtc_isr(void);
void i2s0_isr(void);
void i2s1_isr(void);
void gint0_isr(void);
void gint1_isr(void);
void m0core_isr(void);
void dac_isr(void);
void dma_isr(void);
void ethernet_isr(void);
void lcd_isr(void);
void sdio_isr(void);
void usb1_isr(void);
void usb0_isr(void);
void c_can0_isr(void);
void pin_int7_isr(void);
void pin_int6_isr(void);
void ritimer_isr(void);
void sct_isr(void);
void timer1_isr(void);
void timer0_isr(void);
void timer3_isr(void);
void timer2_isr(void);
void adc0_isr(void);
void mcpwm_isr(void);
void i2c1_isr(void);
void i2c0_isr(void);
void sgpio_isr(void);
void spifi_isr(void);
void pin_int5_isr(void);
void pin_int4_isr(void);
void pin_int3_isr(void);
void pin_int2_isr(void);
void pin_int1_isr(void);
void pin_int0_isr(void);

END_DECLS

/**@}*/

#endif /* LIBOPENCM3_LPC43xx_M4_NVIC_H */
