#pragma once
/**
 * Register definitions for SIM peripheral
 * AUTOMATICALLY GENERATED. DO NOT EDIT MANUALLY
 */

#include <stdint.h>

typedef struct {
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
} SIMRegisters;

// SOPT1 (System Options Register 1)
#define SIM_SOPT1_RAMSIZE_mask     (0x0000F000U) // RAM size
#define SIM_SOPT1_RAMSIZE_offset   (12)
#define SIM_SOPT1_RAMSIZE_width    (4)
#define SIM_SOPT1_OSC32KSEL_mask   (0x000C0000U) // 32K oscillator clock select
#define SIM_SOPT1_OSC32KSEL_offset (18)
#define SIM_SOPT1_OSC32KSEL_width  (2)
#define SIM_SOPT1_USBVSTBY_mask    (0x20000000U) // USB voltage regulator in standby mode during VLPR and VLPW modes
#define SIM_SOPT1_USBVSTBY_offset  (29)
#define SIM_SOPT1_USBVSTBY_width   (1)
#define SIM_SOPT1_USBSSTBY_mask    (0x40000000U) // USB voltage regulator in standby mode during Stop, VLPS, LLS and VLLS modes
#define SIM_SOPT1_USBSSTBY_offset  (30)
#define SIM_SOPT1_USBSSTBY_width   (1)
#define SIM_SOPT1_USBREGEN_mask    (0x80000000U) // USB voltage regulator enable
#define SIM_SOPT1_USBREGEN_offset  (31)
#define SIM_SOPT1_USBREGEN_width   (1)

// SOPT1CFG (SOPT1 Configuration Register)
#define SIM_SOPT1CFG_URWE_mask    (0x01000000U) // USB voltage regulator enable write enable
#define SIM_SOPT1CFG_URWE_offset  (24)
#define SIM_SOPT1CFG_URWE_width   (1)
#define SIM_SOPT1CFG_UVSWE_mask   (0x02000000U) // USB voltage regulator VLP standby write enable
#define SIM_SOPT1CFG_UVSWE_offset (25)
#define SIM_SOPT1CFG_UVSWE_width  (1)
#define SIM_SOPT1CFG_USSWE_mask   (0x04000000U) // USB voltage regulator stop standby write enable
#define SIM_SOPT1CFG_USSWE_offset (26)
#define SIM_SOPT1CFG_USSWE_width  (1)

// SOPT2 (System Options Register 2)
#define SIM_SOPT2_RTCCLKOUTSEL_mask   (0x00000010U) // RTC clock out select
#define SIM_SOPT2_RTCCLKOUTSEL_offset (4)
#define SIM_SOPT2_RTCCLKOUTSEL_width  (1)
#define SIM_SOPT2_CLKOUTSEL_mask      (0x000000E0U) // CLKOUT select
#define SIM_SOPT2_CLKOUTSEL_offset    (5)
#define SIM_SOPT2_CLKOUTSEL_width     (3)
#define SIM_SOPT2_PTD7PAD_mask        (0x00000800U) // PTD7 pad drive strength
#define SIM_SOPT2_PTD7PAD_offset      (11)
#define SIM_SOPT2_PTD7PAD_width       (1)
#define SIM_SOPT2_TRACECLKSEL_mask    (0x00001000U) // Debug trace clock select
#define SIM_SOPT2_TRACECLKSEL_offset  (12)
#define SIM_SOPT2_TRACECLKSEL_width   (1)
#define SIM_SOPT2_PLLFLLSEL_mask      (0x00010000U) // PLL/FLL clock select
#define SIM_SOPT2_PLLFLLSEL_offset    (16)
#define SIM_SOPT2_PLLFLLSEL_width     (1)
#define SIM_SOPT2_USBSRC_mask         (0x00040000U) // USB clock source select
#define SIM_SOPT2_USBSRC_offset       (18)
#define SIM_SOPT2_USBSRC_width        (1)

// SOPT4 (System Options Register 4)
#define SIM_SOPT4_FTM0FLT0_mask      (0x00000001U) // FTM0 Fault 0 Select
#define SIM_SOPT4_FTM0FLT0_offset    (0)
#define SIM_SOPT4_FTM0FLT0_width     (1)
#define SIM_SOPT4_FTM0FLT1_mask      (0x00000002U) // FTM0 Fault 1 Select
#define SIM_SOPT4_FTM0FLT1_offset    (1)
#define SIM_SOPT4_FTM0FLT1_width     (1)
#define SIM_SOPT4_FTM1FLT0_mask      (0x00000010U) // FTM1 Fault 0 Select
#define SIM_SOPT4_FTM1FLT0_offset    (4)
#define SIM_SOPT4_FTM1FLT0_width     (1)
#define SIM_SOPT4_FTM1CH0SRC_mask    (0x000C0000U) // FTM1 channel 0 input capture source select
#define SIM_SOPT4_FTM1CH0SRC_offset  (18)
#define SIM_SOPT4_FTM1CH0SRC_width   (2)
#define SIM_SOPT4_FTM0CLKSEL_mask    (0x01000000U) // FlexTimer 0 External Clock Pin Select
#define SIM_SOPT4_FTM0CLKSEL_offset  (24)
#define SIM_SOPT4_FTM0CLKSEL_width   (1)
#define SIM_SOPT4_FTM1CLKSEL_mask    (0x02000000U) // FTM1 External Clock Pin Select
#define SIM_SOPT4_FTM1CLKSEL_offset  (25)
#define SIM_SOPT4_FTM1CLKSEL_width   (1)
#define SIM_SOPT4_FTM0TRG0SRC_mask   (0x10000000U) // FlexTimer 0 Hardware Trigger 0 Source Select
#define SIM_SOPT4_FTM0TRG0SRC_offset (28)
#define SIM_SOPT4_FTM0TRG0SRC_width  (1)

// SOPT5 (System Options Register 5)
#define SIM_SOPT5_UART0TXSRC_mask   (0x00000001U) // UART 0 transmit data source select
#define SIM_SOPT5_UART0TXSRC_offset (0)
#define SIM_SOPT5_UART0TXSRC_width  (1)
#define SIM_SOPT5_UART0RXSRC_mask   (0x0000000CU) // UART 0 receive data source select
#define SIM_SOPT5_UART0RXSRC_offset (2)
#define SIM_SOPT5_UART0RXSRC_width  (2)
#define SIM_SOPT5_UART1TXSRC_mask   (0x00000010U) // UART 1 transmit data source select
#define SIM_SOPT5_UART1TXSRC_offset (4)
#define SIM_SOPT5_UART1TXSRC_width  (1)
#define SIM_SOPT5_UART1RXSRC_mask   (0x000000C0U) // UART 1 receive data source select
#define SIM_SOPT5_UART1RXSRC_offset (6)
#define SIM_SOPT5_UART1RXSRC_width  (2)

// SOPT7 (System Options Register 7)
#define SIM_SOPT7_ADC0TRGSEL_mask      (0x0000000FU) // ADC0 trigger select
#define SIM_SOPT7_ADC0TRGSEL_offset    (0)
#define SIM_SOPT7_ADC0TRGSEL_width     (4)
#define SIM_SOPT7_ADC0PRETRGSEL_mask   (0x00000010U) // ADC0 pretrigger select
#define SIM_SOPT7_ADC0PRETRGSEL_offset (4)
#define SIM_SOPT7_ADC0PRETRGSEL_width  (1)
#define SIM_SOPT7_ADC0ALTTRGEN_mask    (0x00000080U) // ADC0 alternate trigger enable
#define SIM_SOPT7_ADC0ALTTRGEN_offset  (7)
#define SIM_SOPT7_ADC0ALTTRGEN_width   (1)

// SDID (System Device Identification Register)
#define SIM_SDID_PINID_mask   (0x0000000FU) // Pincount identification
#define SIM_SDID_PINID_offset (0)
#define SIM_SDID_PINID_width  (4)
#define SIM_SDID_FAMID_mask   (0x00000070U) // Kinetis family identification
#define SIM_SDID_FAMID_offset (4)
#define SIM_SDID_FAMID_width  (3)
#define SIM_SDID_REVID_mask   (0x0000F000U) // Device revision number
#define SIM_SDID_REVID_offset (12)
#define SIM_SDID_REVID_width  (4)

// SCGC4 (System Clock Gating Control Register 4)
#define SIM_SCGC4_EWM_mask      (0x00000002U) // EWM Clock Gate Control
#define SIM_SCGC4_EWM_offset    (1)
#define SIM_SCGC4_EWM_width     (1)
#define SIM_SCGC4_CMT_mask      (0x00000004U) // CMT Clock Gate Control
#define SIM_SCGC4_CMT_offset    (2)
#define SIM_SCGC4_CMT_width     (1)
#define SIM_SCGC4_I2C0_mask     (0x00000040U) // I2C0 Clock Gate Control
#define SIM_SCGC4_I2C0_offset   (6)
#define SIM_SCGC4_I2C0_width    (1)
#define SIM_SCGC4_UART0_mask    (0x00000400U) // UART0 Clock Gate Control
#define SIM_SCGC4_UART0_offset  (10)
#define SIM_SCGC4_UART0_width   (1)
#define SIM_SCGC4_UART1_mask    (0x00000800U) // UART1 Clock Gate Control
#define SIM_SCGC4_UART1_offset  (11)
#define SIM_SCGC4_UART1_width   (1)
#define SIM_SCGC4_UART2_mask    (0x00001000U) // UART2 Clock Gate Control
#define SIM_SCGC4_UART2_offset  (12)
#define SIM_SCGC4_UART2_width   (1)
#define SIM_SCGC4_USBOTG_mask   (0x00040000U) // USB Clock Gate Control
#define SIM_SCGC4_USBOTG_offset (18)
#define SIM_SCGC4_USBOTG_width  (1)
#define SIM_SCGC4_CMP_mask      (0x00080000U) // Comparator Clock Gate Control
#define SIM_SCGC4_CMP_offset    (19)
#define SIM_SCGC4_CMP_width     (1)
#define SIM_SCGC4_VREF_mask     (0x00100000U) // VREF Clock Gate Control
#define SIM_SCGC4_VREF_offset   (20)
#define SIM_SCGC4_VREF_width    (1)

// SCGC5 (System Clock Gating Control Register 5)
#define SIM_SCGC5_LPTIMER_mask   (0x00000001U) // Low Power Timer Access Control
#define SIM_SCGC5_LPTIMER_offset (0)
#define SIM_SCGC5_LPTIMER_width  (1)
#define SIM_SCGC5_TSI_mask       (0x00000020U) // TSI Clock Gate Control
#define SIM_SCGC5_TSI_offset     (5)
#define SIM_SCGC5_TSI_width      (1)
#define SIM_SCGC5_PORTA_mask     (0x00000200U) // Port A Clock Gate Control
#define SIM_SCGC5_PORTA_offset   (9)
#define SIM_SCGC5_PORTA_width    (1)
#define SIM_SCGC5_PORTB_mask     (0x00000400U) // Port B Clock Gate Control
#define SIM_SCGC5_PORTB_offset   (10)
#define SIM_SCGC5_PORTB_width    (1)
#define SIM_SCGC5_PORTC_mask     (0x00000800U) // Port C Clock Gate Control
#define SIM_SCGC5_PORTC_offset   (11)
#define SIM_SCGC5_PORTC_width    (1)
#define SIM_SCGC5_PORTD_mask     (0x00001000U) // Port D Clock Gate Control
#define SIM_SCGC5_PORTD_offset   (12)
#define SIM_SCGC5_PORTD_width    (1)
#define SIM_SCGC5_PORTE_mask     (0x00002000U) // Port E Clock Gate Control
#define SIM_SCGC5_PORTE_offset   (13)
#define SIM_SCGC5_PORTE_width    (1)

// SCGC6 (System Clock Gating Control Register 6)
#define SIM_SCGC6_FTFL_mask     (0x00000001U) // Flash Memory Clock Gate Control
#define SIM_SCGC6_FTFL_offset   (0)
#define SIM_SCGC6_FTFL_width    (1)
#define SIM_SCGC6_DMAMUX_mask   (0x00000002U) // DMA Mux Clock Gate Control
#define SIM_SCGC6_DMAMUX_offset (1)
#define SIM_SCGC6_DMAMUX_width  (1)
#define SIM_SCGC6_SPI0_mask     (0x00001000U) // SPI0 Clock Gate Control
#define SIM_SCGC6_SPI0_offset   (12)
#define SIM_SCGC6_SPI0_width    (1)
#define SIM_SCGC6_I2S_mask      (0x00008000U) // I2S Clock Gate Control
#define SIM_SCGC6_I2S_offset    (15)
#define SIM_SCGC6_I2S_width     (1)
#define SIM_SCGC6_CRC_mask      (0x00040000U) // CRC Clock Gate Control
#define SIM_SCGC6_CRC_offset    (18)
#define SIM_SCGC6_CRC_width     (1)
#define SIM_SCGC6_USBDCD_mask   (0x00200000U) // USB DCD Clock Gate Control
#define SIM_SCGC6_USBDCD_offset (21)
#define SIM_SCGC6_USBDCD_width  (1)
#define SIM_SCGC6_PDB_mask      (0x00400000U) // PDB Clock Gate Control
#define SIM_SCGC6_PDB_offset    (22)
#define SIM_SCGC6_PDB_width     (1)
#define SIM_SCGC6_PIT_mask      (0x00800000U) // PIT Clock Gate Control
#define SIM_SCGC6_PIT_offset    (23)
#define SIM_SCGC6_PIT_width     (1)
#define SIM_SCGC6_FTM0_mask     (0x01000000U) // FTM0 Clock Gate Control
#define SIM_SCGC6_FTM0_offset   (24)
#define SIM_SCGC6_FTM0_width    (1)
#define SIM_SCGC6_FTM1_mask     (0x02000000U) // FTM1 Clock Gate Control
#define SIM_SCGC6_FTM1_offset   (25)
#define SIM_SCGC6_FTM1_width    (1)
#define SIM_SCGC6_ADC0_mask     (0x08000000U) // ADC0 Clock Gate Control
#define SIM_SCGC6_ADC0_offset   (27)
#define SIM_SCGC6_ADC0_width    (1)
#define SIM_SCGC6_RTC_mask      (0x20000000U) // RTC Access Control
#define SIM_SCGC6_RTC_offset    (29)
#define SIM_SCGC6_RTC_width     (1)

// SCGC7 (System Clock Gating Control Register 7)
#define SIM_SCGC7_DMA_mask   (0x00000002U) // DMA Clock Gate Control
#define SIM_SCGC7_DMA_offset (1)
#define SIM_SCGC7_DMA_width  (1)

// CLKDIV1 (System Clock Divider Register 1)
#define SIM_CLKDIV1_OUTDIV4_mask   (0x000F0000U) // Clock 4 output divider value
#define SIM_CLKDIV1_OUTDIV4_offset (16)
#define SIM_CLKDIV1_OUTDIV4_width  (4)
#define SIM_CLKDIV1_OUTDIV2_mask   (0x0F000000U) // Clock 2 output divider value
#define SIM_CLKDIV1_OUTDIV2_offset (24)
#define SIM_CLKDIV1_OUTDIV2_width  (4)
#define SIM_CLKDIV1_OUTDIV1_mask   (0xF0000000U) // Clock 1 output divider value
#define SIM_CLKDIV1_OUTDIV1_offset (28)
#define SIM_CLKDIV1_OUTDIV1_width  (4)

// CLKDIV2 (System Clock Divider Register 2)
#define SIM_CLKDIV2_USBFRAC_mask   (0x00000001U) // USB clock divider fraction
#define SIM_CLKDIV2_USBFRAC_offset (0)
#define SIM_CLKDIV2_USBFRAC_width  (1)
#define SIM_CLKDIV2_USBDIV_mask    (0x0000000EU) // USB clock divider divisor
#define SIM_CLKDIV2_USBDIV_offset  (1)
#define SIM_CLKDIV2_USBDIV_width   (3)

// FCFG1 (Flash Configuration Register 1)
#define SIM_FCFG1_FLASHDIS_mask    (0x00000001U) // Flash Disable
#define SIM_FCFG1_FLASHDIS_offset  (0)
#define SIM_FCFG1_FLASHDIS_width   (1)
#define SIM_FCFG1_FLASHDOZE_mask   (0x00000002U) // Flash Doze
#define SIM_FCFG1_FLASHDOZE_offset (1)
#define SIM_FCFG1_FLASHDOZE_width  (1)
#define SIM_FCFG1_DEPART_mask      (0x00000F00U) // FlexNVM partition
#define SIM_FCFG1_DEPART_offset    (8)
#define SIM_FCFG1_DEPART_width     (4)
#define SIM_FCFG1_EESIZE_mask      (0x000F0000U) // EEPROM size
#define SIM_FCFG1_EESIZE_offset    (16)
#define SIM_FCFG1_EESIZE_width     (4)
#define SIM_FCFG1_PFSIZE_mask      (0x0F000000U) // Program flash size
#define SIM_FCFG1_PFSIZE_offset    (24)
#define SIM_FCFG1_PFSIZE_width     (4)
#define SIM_FCFG1_NVMSIZE_mask     (0xF0000000U) // FlexNVM size
#define SIM_FCFG1_NVMSIZE_offset   (28)
#define SIM_FCFG1_NVMSIZE_width    (4)

// FCFG2 (Flash Configuration Register 2)
#define SIM_FCFG2_MAXADDR1_mask   (0x007F0000U) // Max address block 1
#define SIM_FCFG2_MAXADDR1_offset (16)
#define SIM_FCFG2_MAXADDR1_width  (7)
#define SIM_FCFG2_PFLSH_mask      (0x00800000U) // Program flash
#define SIM_FCFG2_PFLSH_offset    (23)
#define SIM_FCFG2_PFLSH_width     (1)
#define SIM_FCFG2_MAXADDR0_mask   (0x7F000000U) // Max address block 0
#define SIM_FCFG2_MAXADDR0_offset (24)
#define SIM_FCFG2_MAXADDR0_width  (7)

#define SIM ((SIMRegisters*)0x40047000)
