#pragma once
/**
 * Register definitions for SIM peripheral
 * AUTOMATICALLY GENERATED. DO NOT EDIT MANUALLY
 */

#include <stdint.h>

struct SIMRegisters {
  volatile uint32_t SOPT1;	// System Options Register 1 [0]
  volatile uint32_t SOPT1CFG;	// SOPT1 Configuration Register [4]
  volatile uint8_t _reserved_8[4092];
  volatile uint32_t SOPT2;	// System Options Register 2 [1004]
  volatile uint8_t _reserved_4104[4];
  volatile uint32_t SOPT4;	// System Options Register 4 [100c]
  volatile uint32_t SOPT5;	// System Options Register 5 [1010]
  volatile uint8_t _reserved_4116[4];
  volatile uint32_t SOPT7;	// System Options Register 7 [1018]
  volatile uint8_t _reserved_4124[8];
  volatile uint32_t SDID;	// System Device Identification Register [1024]
  volatile uint8_t _reserved_4136[12];
  volatile uint32_t SCGC4;	// System Clock Gating Control Register 4 [1034]
  volatile uint32_t SCGC5;	// System Clock Gating Control Register 5 [1038]
  volatile uint32_t SCGC6;	// System Clock Gating Control Register 6 [103c]
  volatile uint32_t SCGC7;	// System Clock Gating Control Register 7 [1040]
  volatile uint32_t CLKDIV1;	// System Clock Divider Register 1 [1044]
  volatile uint32_t CLKDIV2;	// System Clock Divider Register 2 [1048]
  volatile uint32_t FCFG1;	// Flash Configuration Register 1 [104c]
  volatile uint32_t FCFG2;	// Flash Configuration Register 2 [1050]
  volatile uint32_t UIDH;	// Unique Identification Register High [1054]
  volatile uint32_t UIDMH;	// Unique Identification Register Mid-High [1058]
  volatile uint32_t UIDML;	// Unique Identification Register Mid Low [105c]
  volatile uint32_t UIDL;	// Unique Identification Register Low [1060]
};

// SOPT1 (System Options Register 1)
#define SOPT1_RAMSIZE_mask     (0x0000F000U) // RAM size
#define SOPT1_RAMSIZE_width    (4)
#define SOPT1_RAMSIZE(n)       ((n) << SOPT1_RAMSIZE_offset)
#define SOPT1_RAMSIZE_get(n)   (((n) >> SOPT1_RAMSIZE_offset) & 0xFU)
#define SOPT1_RAMSIZE_offset   (12)
#define SOPT1_OSC32KSEL_mask   (0x000C0000U) // 32K oscillator clock select
#define SOPT1_OSC32KSEL_width  (2)
#define SOPT1_OSC32KSEL(n)     ((n) << SOPT1_OSC32KSEL_offset)
#define SOPT1_OSC32KSEL_get(n) (((n) >> SOPT1_OSC32KSEL_offset) & 0x3U)
#define SOPT1_OSC32KSEL_offset (18)
#define SOPT1_USBVSTBY         (0x20000000U) // USB voltage regulator in standby mode during VLPR and VLPW modes
#define SOPT1_USBVSTBY_offset  (29)
#define SOPT1_USBSSTBY         (0x40000000U) // USB voltage regulator in standby mode during Stop, VLPS, LLS and VLLS modes
#define SOPT1_USBSSTBY_offset  (30)
#define SOPT1_USBREGEN         (0x80000000U) // USB voltage regulator enable
#define SOPT1_USBREGEN_offset  (31)

// SOPT1CFG (SOPT1 Configuration Register)
#define SOPT1CFG_URWE         (0x01000000U) // USB voltage regulator enable write enable
#define SOPT1CFG_URWE_offset  (24)
#define SOPT1CFG_UVSWE        (0x02000000U) // USB voltage regulator VLP standby write enable
#define SOPT1CFG_UVSWE_offset (25)
#define SOPT1CFG_USSWE        (0x04000000U) // USB voltage regulator stop standby write enable
#define SOPT1CFG_USSWE_offset (26)

// SOPT2 (System Options Register 2)
#define SOPT2_RTCCLKOUTSEL        (0x00000010U) // RTC clock out select
#define SOPT2_RTCCLKOUTSEL_offset (4)
#define SOPT2_CLKOUTSEL_mask      (0x000000E0U) // CLKOUT select
#define SOPT2_CLKOUTSEL_width     (3)
#define SOPT2_CLKOUTSEL(n)        ((n) << SOPT2_CLKOUTSEL_offset)
#define SOPT2_CLKOUTSEL_get(n)    (((n) >> SOPT2_CLKOUTSEL_offset) & 0x7U)
#define SOPT2_CLKOUTSEL_offset    (5)
#define SOPT2_PTD7PAD             (0x00000800U) // PTD7 pad drive strength
#define SOPT2_PTD7PAD_offset      (11)
#define SOPT2_TRACECLKSEL         (0x00001000U) // Debug trace clock select
#define SOPT2_TRACECLKSEL_offset  (12)
#define SOPT2_PLLFLLSEL           (0x00010000U) // PLL/FLL clock select
#define SOPT2_PLLFLLSEL_offset    (16)
#define SOPT2_USBSRC              (0x00040000U) // USB clock source select
#define SOPT2_USBSRC_offset       (18)

// SOPT4 (System Options Register 4)
#define SOPT4_FTM0FLT0           (0x00000001U) // FTM0 Fault 0 Select
#define SOPT4_FTM0FLT0_offset    (0)
#define SOPT4_FTM0FLT1           (0x00000002U) // FTM0 Fault 1 Select
#define SOPT4_FTM0FLT1_offset    (1)
#define SOPT4_FTM1FLT0           (0x00000010U) // FTM1 Fault 0 Select
#define SOPT4_FTM1FLT0_offset    (4)
#define SOPT4_FTM1CH0SRC_mask    (0x000C0000U) // FTM1 channel 0 input capture source select
#define SOPT4_FTM1CH0SRC_width   (2)
#define SOPT4_FTM1CH0SRC(n)      ((n) << SOPT4_FTM1CH0SRC_offset)
#define SOPT4_FTM1CH0SRC_get(n)  (((n) >> SOPT4_FTM1CH0SRC_offset) & 0x3U)
#define SOPT4_FTM1CH0SRC_offset  (18)
#define SOPT4_FTM0CLKSEL         (0x01000000U) // FlexTimer 0 External Clock Pin Select
#define SOPT4_FTM0CLKSEL_offset  (24)
#define SOPT4_FTM1CLKSEL         (0x02000000U) // FTM1 External Clock Pin Select
#define SOPT4_FTM1CLKSEL_offset  (25)
#define SOPT4_FTM0TRG0SRC        (0x10000000U) // FlexTimer 0 Hardware Trigger 0 Source Select
#define SOPT4_FTM0TRG0SRC_offset (28)

// SOPT5 (System Options Register 5)
#define SOPT5_UART0TXSRC        (0x00000001U) // UART 0 transmit data source select
#define SOPT5_UART0TXSRC_offset (0)
#define SOPT5_UART0RXSRC_mask   (0x0000000CU) // UART 0 receive data source select
#define SOPT5_UART0RXSRC_width  (2)
#define SOPT5_UART0RXSRC(n)     ((n) << SOPT5_UART0RXSRC_offset)
#define SOPT5_UART0RXSRC_get(n) (((n) >> SOPT5_UART0RXSRC_offset) & 0x3U)
#define SOPT5_UART0RXSRC_offset (2)
#define SOPT5_UART1TXSRC        (0x00000010U) // UART 1 transmit data source select
#define SOPT5_UART1TXSRC_offset (4)
#define SOPT5_UART1RXSRC_mask   (0x000000C0U) // UART 1 receive data source select
#define SOPT5_UART1RXSRC_width  (2)
#define SOPT5_UART1RXSRC(n)     ((n) << SOPT5_UART1RXSRC_offset)
#define SOPT5_UART1RXSRC_get(n) (((n) >> SOPT5_UART1RXSRC_offset) & 0x3U)
#define SOPT5_UART1RXSRC_offset (6)

// SOPT7 (System Options Register 7)
#define SOPT7_ADC0TRGSEL_mask      (0x0000000FU) // ADC0 trigger select
#define SOPT7_ADC0TRGSEL_width     (4)
#define SOPT7_ADC0TRGSEL(n)        ((n) << SOPT7_ADC0TRGSEL_offset)
#define SOPT7_ADC0TRGSEL_get(n)    (((n) >> SOPT7_ADC0TRGSEL_offset) & 0xFU)
#define SOPT7_ADC0TRGSEL_offset    (0)
#define SOPT7_ADC0PRETRGSEL        (0x00000010U) // ADC0 pretrigger select
#define SOPT7_ADC0PRETRGSEL_offset (4)
#define SOPT7_ADC0ALTTRGEN         (0x00000080U) // ADC0 alternate trigger enable
#define SOPT7_ADC0ALTTRGEN_offset  (7)

// SDID (System Device Identification Register)
#define SDID_PINID_mask   (0x0000000FU) // Pincount identification
#define SDID_PINID_width  (4)
#define SDID_PINID(n)     ((n) << SDID_PINID_offset)
#define SDID_PINID_get(n) (((n) >> SDID_PINID_offset) & 0xFU)
#define SDID_PINID_offset (0)
#define SDID_FAMID_mask   (0x00000070U) // Kinetis family identification
#define SDID_FAMID_width  (3)
#define SDID_FAMID(n)     ((n) << SDID_FAMID_offset)
#define SDID_FAMID_get(n) (((n) >> SDID_FAMID_offset) & 0x7U)
#define SDID_FAMID_offset (4)
#define SDID_REVID_mask   (0x0000F000U) // Device revision number
#define SDID_REVID_width  (4)
#define SDID_REVID(n)     ((n) << SDID_REVID_offset)
#define SDID_REVID_get(n) (((n) >> SDID_REVID_offset) & 0xFU)
#define SDID_REVID_offset (12)

// SCGC4 (System Clock Gating Control Register 4)
#define SCGC4_EWM           (0x00000002U) // EWM Clock Gate Control
#define SCGC4_EWM_offset    (1)
#define SCGC4_CMT           (0x00000004U) // CMT Clock Gate Control
#define SCGC4_CMT_offset    (2)
#define SCGC4_I2C0          (0x00000040U) // I2C0 Clock Gate Control
#define SCGC4_I2C0_offset   (6)
#define SCGC4_UART0         (0x00000400U) // UART0 Clock Gate Control
#define SCGC4_UART0_offset  (10)
#define SCGC4_UART1         (0x00000800U) // UART1 Clock Gate Control
#define SCGC4_UART1_offset  (11)
#define SCGC4_UART2         (0x00001000U) // UART2 Clock Gate Control
#define SCGC4_UART2_offset  (12)
#define SCGC4_USBOTG        (0x00040000U) // USB Clock Gate Control
#define SCGC4_USBOTG_offset (18)
#define SCGC4_CMP           (0x00080000U) // Comparator Clock Gate Control
#define SCGC4_CMP_offset    (19)
#define SCGC4_VREF          (0x00100000U) // VREF Clock Gate Control
#define SCGC4_VREF_offset   (20)

// SCGC5 (System Clock Gating Control Register 5)
#define SCGC5_LPTIMER        (0x00000001U) // Low Power Timer Access Control
#define SCGC5_LPTIMER_offset (0)
#define SCGC5_TSI            (0x00000020U) // TSI Clock Gate Control
#define SCGC5_TSI_offset     (5)
#define SCGC5_PORTA          (0x00000200U) // Port A Clock Gate Control
#define SCGC5_PORTA_offset   (9)
#define SCGC5_PORTB          (0x00000400U) // Port B Clock Gate Control
#define SCGC5_PORTB_offset   (10)
#define SCGC5_PORTC          (0x00000800U) // Port C Clock Gate Control
#define SCGC5_PORTC_offset   (11)
#define SCGC5_PORTD          (0x00001000U) // Port D Clock Gate Control
#define SCGC5_PORTD_offset   (12)
#define SCGC5_PORTE          (0x00002000U) // Port E Clock Gate Control
#define SCGC5_PORTE_offset   (13)

// SCGC6 (System Clock Gating Control Register 6)
#define SCGC6_FTFL          (0x00000001U) // Flash Memory Clock Gate Control
#define SCGC6_FTFL_offset   (0)
#define SCGC6_DMAMUX        (0x00000002U) // DMA Mux Clock Gate Control
#define SCGC6_DMAMUX_offset (1)
#define SCGC6_SPI0          (0x00001000U) // SPI0 Clock Gate Control
#define SCGC6_SPI0_offset   (12)
#define SCGC6_I2S           (0x00008000U) // I2S Clock Gate Control
#define SCGC6_I2S_offset    (15)
#define SCGC6_CRC           (0x00040000U) // CRC Clock Gate Control
#define SCGC6_CRC_offset    (18)
#define SCGC6_USBDCD        (0x00200000U) // USB DCD Clock Gate Control
#define SCGC6_USBDCD_offset (21)
#define SCGC6_PDB           (0x00400000U) // PDB Clock Gate Control
#define SCGC6_PDB_offset    (22)
#define SCGC6_PIT           (0x00800000U) // PIT Clock Gate Control
#define SCGC6_PIT_offset    (23)
#define SCGC6_FTM0          (0x01000000U) // FTM0 Clock Gate Control
#define SCGC6_FTM0_offset   (24)
#define SCGC6_FTM1          (0x02000000U) // FTM1 Clock Gate Control
#define SCGC6_FTM1_offset   (25)
#define SCGC6_ADC0          (0x08000000U) // ADC0 Clock Gate Control
#define SCGC6_ADC0_offset   (27)
#define SCGC6_RTC           (0x20000000U) // RTC Access Control
#define SCGC6_RTC_offset    (29)

// SCGC7 (System Clock Gating Control Register 7)
#define SCGC7_DMA        (0x00000002U) // DMA Clock Gate Control
#define SCGC7_DMA_offset (1)

// CLKDIV1 (System Clock Divider Register 1)
#define CLKDIV1_OUTDIV4_mask   (0x000F0000U) // Clock 4 output divider value
#define CLKDIV1_OUTDIV4_width  (4)
#define CLKDIV1_OUTDIV4(n)     ((n) << CLKDIV1_OUTDIV4_offset)
#define CLKDIV1_OUTDIV4_get(n) (((n) >> CLKDIV1_OUTDIV4_offset) & 0xFU)
#define CLKDIV1_OUTDIV4_offset (16)
#define CLKDIV1_OUTDIV2_mask   (0x0F000000U) // Clock 2 output divider value
#define CLKDIV1_OUTDIV2_width  (4)
#define CLKDIV1_OUTDIV2(n)     ((n) << CLKDIV1_OUTDIV2_offset)
#define CLKDIV1_OUTDIV2_get(n) (((n) >> CLKDIV1_OUTDIV2_offset) & 0xFU)
#define CLKDIV1_OUTDIV2_offset (24)
#define CLKDIV1_OUTDIV1_mask   (0xF0000000U) // Clock 1 output divider value
#define CLKDIV1_OUTDIV1_width  (4)
#define CLKDIV1_OUTDIV1(n)     ((n) << CLKDIV1_OUTDIV1_offset)
#define CLKDIV1_OUTDIV1_get(n) (((n) >> CLKDIV1_OUTDIV1_offset) & 0xFU)
#define CLKDIV1_OUTDIV1_offset (28)

// CLKDIV2 (System Clock Divider Register 2)
#define CLKDIV2_USBFRAC        (0x00000001U) // USB clock divider fraction
#define CLKDIV2_USBFRAC_offset (0)
#define CLKDIV2_USBDIV_mask    (0x0000000EU) // USB clock divider divisor
#define CLKDIV2_USBDIV_width   (3)
#define CLKDIV2_USBDIV(n)      ((n) << CLKDIV2_USBDIV_offset)
#define CLKDIV2_USBDIV_get(n)  (((n) >> CLKDIV2_USBDIV_offset) & 0x7U)
#define CLKDIV2_USBDIV_offset  (1)

// FCFG1 (Flash Configuration Register 1)
#define FCFG1_FLASHDIS         (0x00000001U) // Flash Disable
#define FCFG1_FLASHDIS_offset  (0)
#define FCFG1_FLASHDOZE        (0x00000002U) // Flash Doze
#define FCFG1_FLASHDOZE_offset (1)
#define FCFG1_DEPART_mask      (0x00000F00U) // FlexNVM partition
#define FCFG1_DEPART_width     (4)
#define FCFG1_DEPART(n)        ((n) << FCFG1_DEPART_offset)
#define FCFG1_DEPART_get(n)    (((n) >> FCFG1_DEPART_offset) & 0xFU)
#define FCFG1_DEPART_offset    (8)
#define FCFG1_EESIZE_mask      (0x000F0000U) // EEPROM size
#define FCFG1_EESIZE_width     (4)
#define FCFG1_EESIZE(n)        ((n) << FCFG1_EESIZE_offset)
#define FCFG1_EESIZE_get(n)    (((n) >> FCFG1_EESIZE_offset) & 0xFU)
#define FCFG1_EESIZE_offset    (16)
#define FCFG1_PFSIZE_mask      (0x0F000000U) // Program flash size
#define FCFG1_PFSIZE_width     (4)
#define FCFG1_PFSIZE(n)        ((n) << FCFG1_PFSIZE_offset)
#define FCFG1_PFSIZE_get(n)    (((n) >> FCFG1_PFSIZE_offset) & 0xFU)
#define FCFG1_PFSIZE_offset    (24)
#define FCFG1_NVMSIZE_mask     (0xF0000000U) // FlexNVM size
#define FCFG1_NVMSIZE_width    (4)
#define FCFG1_NVMSIZE(n)       ((n) << FCFG1_NVMSIZE_offset)
#define FCFG1_NVMSIZE_get(n)   (((n) >> FCFG1_NVMSIZE_offset) & 0xFU)
#define FCFG1_NVMSIZE_offset   (28)

// FCFG2 (Flash Configuration Register 2)
#define FCFG2_MAXADDR1_mask   (0x007F0000U) // Max address block 1
#define FCFG2_MAXADDR1_width  (7)
#define FCFG2_MAXADDR1(n)     ((n) << FCFG2_MAXADDR1_offset)
#define FCFG2_MAXADDR1_get(n) (((n) >> FCFG2_MAXADDR1_offset) & 0x7FU)
#define FCFG2_MAXADDR1_offset (16)
#define FCFG2_PFLSH           (0x00800000U) // Program flash
#define FCFG2_PFLSH_offset    (23)
#define FCFG2_MAXADDR0_mask   (0x7F000000U) // Max address block 0
#define FCFG2_MAXADDR0_width  (7)
#define FCFG2_MAXADDR0(n)     ((n) << FCFG2_MAXADDR0_offset)
#define FCFG2_MAXADDR0_get(n) (((n) >> FCFG2_MAXADDR0_offset) & 0x7FU)
#define FCFG2_MAXADDR0_offset (24)

#define SIM ((struct SIMRegisters*)0x40047000)
