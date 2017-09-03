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
  volatile uint32_t SCGC1;	// System Clock Gating Control Register 1 [1028]
  volatile uint32_t SCGC2;	// System Clock Gating Control Register 2 [102c]
  volatile uint32_t SCGC3;	// System Clock Gating Control Register 3 [1030]
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
#define SOPT2_FBSL_mask           (0x00000300U) // FlexBus security level
#define SOPT2_FBSL_width          (2)
#define SOPT2_FBSL(n)             ((n) << SOPT2_FBSL_offset)
#define SOPT2_FBSL_get(n)         (((n) >> SOPT2_FBSL_offset) & 0x3U)
#define SOPT2_FBSL_offset         (8)
#define SOPT2_PTD7PAD             (0x00000800U) // PTD7 pad drive strength
#define SOPT2_PTD7PAD_offset      (11)
#define SOPT2_TRACECLKSEL         (0x00001000U) // Debug trace clock select
#define SOPT2_TRACECLKSEL_offset  (12)
#define SOPT2_PLLFLLSEL_mask      (0x00030000U) // PLL/FLL clock select
#define SOPT2_PLLFLLSEL_width     (2)
#define SOPT2_PLLFLLSEL(n)        ((n) << SOPT2_PLLFLLSEL_offset)
#define SOPT2_PLLFLLSEL_get(n)    (((n) >> SOPT2_PLLFLLSEL_offset) & 0x3U)
#define SOPT2_PLLFLLSEL_offset    (16)
#define SOPT2_USBSRC              (0x00040000U) // USB clock source select
#define SOPT2_USBSRC_offset       (18)
#define SOPT2_RMIISRC             (0x00080000U) // RMII clock source select
#define SOPT2_RMIISRC_offset      (19)
#define SOPT2_TIMESRC_mask        (0x00300000U) // IEEE 1588 timestamp clock source select
#define SOPT2_TIMESRC_width       (2)
#define SOPT2_TIMESRC(n)          ((n) << SOPT2_TIMESRC_offset)
#define SOPT2_TIMESRC_get(n)      (((n) >> SOPT2_TIMESRC_offset) & 0x3U)
#define SOPT2_TIMESRC_offset      (20)
#define SOPT2_SDHCSRC_mask        (0x30000000U) // SDHC clock source select
#define SOPT2_SDHCSRC_width       (2)
#define SOPT2_SDHCSRC(n)          ((n) << SOPT2_SDHCSRC_offset)
#define SOPT2_SDHCSRC_get(n)      (((n) >> SOPT2_SDHCSRC_offset) & 0x3U)
#define SOPT2_SDHCSRC_offset      (28)

// SOPT4 (System Options Register 4)
#define SOPT4_FTM0FLT0           (0x00000001U) // FTM0 Fault 0 Select
#define SOPT4_FTM0FLT0_offset    (0)
#define SOPT4_FTM0FLT1           (0x00000002U) // FTM0 Fault 1 Select
#define SOPT4_FTM0FLT1_offset    (1)
#define SOPT4_FTM0FLT2           (0x00000004U) // FTM0 Fault 2 Select
#define SOPT4_FTM0FLT2_offset    (2)
#define SOPT4_FTM1FLT0           (0x00000010U) // FTM1 Fault 0 Select
#define SOPT4_FTM1FLT0_offset    (4)
#define SOPT4_FTM2FLT0           (0x00000100U) // FTM2 Fault 0 Select
#define SOPT4_FTM2FLT0_offset    (8)
#define SOPT4_FTM3FLT0           (0x00001000U) // FTM3 Fault 0 Select
#define SOPT4_FTM3FLT0_offset    (12)
#define SOPT4_FTM1CH0SRC_mask    (0x000C0000U) // FTM1 channel 0 input capture source select
#define SOPT4_FTM1CH0SRC_width   (2)
#define SOPT4_FTM1CH0SRC(n)      ((n) << SOPT4_FTM1CH0SRC_offset)
#define SOPT4_FTM1CH0SRC_get(n)  (((n) >> SOPT4_FTM1CH0SRC_offset) & 0x3U)
#define SOPT4_FTM1CH0SRC_offset  (18)
#define SOPT4_FTM2CH0SRC_mask    (0x00300000U) // FTM2 channel 0 input capture source select
#define SOPT4_FTM2CH0SRC_width   (2)
#define SOPT4_FTM2CH0SRC(n)      ((n) << SOPT4_FTM2CH0SRC_offset)
#define SOPT4_FTM2CH0SRC_get(n)  (((n) >> SOPT4_FTM2CH0SRC_offset) & 0x3U)
#define SOPT4_FTM2CH0SRC_offset  (20)
#define SOPT4_FTM0CLKSEL         (0x01000000U) // FlexTimer 0 External Clock Pin Select
#define SOPT4_FTM0CLKSEL_offset  (24)
#define SOPT4_FTM1CLKSEL         (0x02000000U) // FTM1 External Clock Pin Select
#define SOPT4_FTM1CLKSEL_offset  (25)
#define SOPT4_FTM2CLKSEL         (0x04000000U) // FlexTimer 2 External Clock Pin Select
#define SOPT4_FTM2CLKSEL_offset  (26)
#define SOPT4_FTM3CLKSEL         (0x08000000U) // FlexTimer 3 External Clock Pin Select
#define SOPT4_FTM3CLKSEL_offset  (27)
#define SOPT4_FTM0TRG0SRC        (0x10000000U) // FlexTimer 0 Hardware Trigger 0 Source Select
#define SOPT4_FTM0TRG0SRC_offset (28)
#define SOPT4_FTM0TRG1SRC        (0x20000000U) // FlexTimer 0 Hardware Trigger 1 Source Select
#define SOPT4_FTM0TRG1SRC_offset (29)
#define SOPT4_FTM3TRG0SRC        (0x40000000U) // FlexTimer 3 Hardware Trigger 0 Source Select
#define SOPT4_FTM3TRG0SRC_offset (30)
#define SOPT4_FTM3TRG1SRC        (0x80000000U) // FlexTimer 3 Hardware Trigger 1 Source Select
#define SOPT4_FTM3TRG1SRC_offset (31)

// SOPT5 (System Options Register 5)
#define SOPT5_UART0TXSRC_mask   (0x00000003U) // UART 0 transmit data source select
#define SOPT5_UART0TXSRC_width  (2)
#define SOPT5_UART0TXSRC(n)     ((n) << SOPT5_UART0TXSRC_offset)
#define SOPT5_UART0TXSRC_get(n) (((n) >> SOPT5_UART0TXSRC_offset) & 0x3U)
#define SOPT5_UART0TXSRC_offset (0)
#define SOPT5_UART0RXSRC_mask   (0x0000000CU) // UART 0 receive data source select
#define SOPT5_UART0RXSRC_width  (2)
#define SOPT5_UART0RXSRC(n)     ((n) << SOPT5_UART0RXSRC_offset)
#define SOPT5_UART0RXSRC_get(n) (((n) >> SOPT5_UART0RXSRC_offset) & 0x3U)
#define SOPT5_UART0RXSRC_offset (2)
#define SOPT5_UART1TXSRC_mask   (0x00000030U) // UART 1 transmit data source select
#define SOPT5_UART1TXSRC_width  (2)
#define SOPT5_UART1TXSRC(n)     ((n) << SOPT5_UART1TXSRC_offset)
#define SOPT5_UART1TXSRC_get(n) (((n) >> SOPT5_UART1TXSRC_offset) & 0x3U)
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
#define SOPT7_ADC1TRGSEL_mask      (0x00000F00U) // ADC1 trigger select
#define SOPT7_ADC1TRGSEL_width     (4)
#define SOPT7_ADC1TRGSEL(n)        ((n) << SOPT7_ADC1TRGSEL_offset)
#define SOPT7_ADC1TRGSEL_get(n)    (((n) >> SOPT7_ADC1TRGSEL_offset) & 0xFU)
#define SOPT7_ADC1TRGSEL_offset    (8)
#define SOPT7_ADC1PRETRGSEL        (0x00001000U) // ADC1 pre-trigger select
#define SOPT7_ADC1PRETRGSEL_offset (12)
#define SOPT7_ADC1ALTTRGEN         (0x00008000U) // ADC1 alternate trigger enable
#define SOPT7_ADC1ALTTRGEN_offset  (15)

// SDID (System Device Identification Register)
#define SDID_PINID_mask      (0x0000000FU) // Pincount identification
#define SDID_PINID_width     (4)
#define SDID_PINID(n)        ((n) << SDID_PINID_offset)
#define SDID_PINID_get(n)    (((n) >> SDID_PINID_offset) & 0xFU)
#define SDID_PINID_offset    (0)
#define SDID_FAMID_mask      (0x00000070U) // Kinetis family identification
#define SDID_FAMID_width     (3)
#define SDID_FAMID(n)        ((n) << SDID_FAMID_offset)
#define SDID_FAMID_get(n)    (((n) >> SDID_FAMID_offset) & 0x7U)
#define SDID_FAMID_offset    (4)
#define SDID_DIEID_mask      (0x00000F80U) // Device Die ID
#define SDID_DIEID_width     (5)
#define SDID_DIEID(n)        ((n) << SDID_DIEID_offset)
#define SDID_DIEID_get(n)    (((n) >> SDID_DIEID_offset) & 0x1FU)
#define SDID_DIEID_offset    (7)
#define SDID_REVID_mask      (0x0000F000U) // Device revision number
#define SDID_REVID_width     (4)
#define SDID_REVID(n)        ((n) << SDID_REVID_offset)
#define SDID_REVID_get(n)    (((n) >> SDID_REVID_offset) & 0xFU)
#define SDID_REVID_offset    (12)
#define SDID_SERIESID_mask   (0x00F00000U) // Kinetis Series ID
#define SDID_SERIESID_width  (4)
#define SDID_SERIESID(n)     ((n) << SDID_SERIESID_offset)
#define SDID_SERIESID_get(n) (((n) >> SDID_SERIESID_offset) & 0xFU)
#define SDID_SERIESID_offset (20)
#define SDID_SUBFAMID_mask   (0x0F000000U) // Kinetis Sub-Family ID
#define SDID_SUBFAMID_width  (4)
#define SDID_SUBFAMID(n)     ((n) << SDID_SUBFAMID_offset)
#define SDID_SUBFAMID_get(n) (((n) >> SDID_SUBFAMID_offset) & 0xFU)
#define SDID_SUBFAMID_offset (24)
#define SDID_FAMILYID_mask   (0xF0000000U) // Kinetis Family ID
#define SDID_FAMILYID_width  (4)
#define SDID_FAMILYID(n)     ((n) << SDID_FAMILYID_offset)
#define SDID_FAMILYID_get(n) (((n) >> SDID_FAMILYID_offset) & 0xFU)
#define SDID_FAMILYID_offset (28)

// SCGC1 (System Clock Gating Control Register 1)
#define SCGC1_I2C2         (0x00000040U) // I2C2 Clock Gate Control
#define SCGC1_I2C2_offset  (6)
#define SCGC1_UART4        (0x00000400U) // UART4 Clock Gate Control
#define SCGC1_UART4_offset (10)
#define SCGC1_UART5        (0x00000800U) // UART5 Clock Gate Control
#define SCGC1_UART5_offset (11)

// SCGC2 (System Clock Gating Control Register 2)
#define SCGC2_ENET        (0x00000001U) // ENET Clock Gate Control
#define SCGC2_ENET_offset (0)
#define SCGC2_DAC0        (0x00001000U) // DAC0 Clock Gate Control
#define SCGC2_DAC0_offset (12)
#define SCGC2_DAC1        (0x00002000U) // DAC1 Clock Gate Control
#define SCGC2_DAC1_offset (13)

// SCGC3 (System Clock Gating Control Register 3)
#define SCGC3_RNGA        (0x00000001U) // RNGA Clock Gate Control
#define SCGC3_RNGA_offset (0)
#define SCGC3_SPI2        (0x00001000U) // SPI2 Clock Gate Control
#define SCGC3_SPI2_offset (12)
#define SCGC3_SDHC        (0x00020000U) // SDHC Clock Gate Control
#define SCGC3_SDHC_offset (17)
#define SCGC3_FTM2        (0x01000000U) // FTM2 Clock Gate Control
#define SCGC3_FTM2_offset (24)
#define SCGC3_FTM3        (0x02000000U) // FTM3 Clock Gate Control
#define SCGC3_FTM3_offset (25)
#define SCGC3_ADC1        (0x08000000U) // ADC1 Clock Gate Control
#define SCGC3_ADC1_offset (27)

// SCGC4 (System Clock Gating Control Register 4)
#define SCGC4_EWM           (0x00000002U) // EWM Clock Gate Control
#define SCGC4_EWM_offset    (1)
#define SCGC4_CMT           (0x00000004U) // CMT Clock Gate Control
#define SCGC4_CMT_offset    (2)
#define SCGC4_I2C0          (0x00000040U) // I2C0 Clock Gate Control
#define SCGC4_I2C0_offset   (6)
#define SCGC4_I2C1          (0x00000080U) // I2C1 Clock Gate Control
#define SCGC4_I2C1_offset   (7)
#define SCGC4_UART0         (0x00000400U) // UART0 Clock Gate Control
#define SCGC4_UART0_offset  (10)
#define SCGC4_UART1         (0x00000800U) // UART1 Clock Gate Control
#define SCGC4_UART1_offset  (11)
#define SCGC4_UART2         (0x00001000U) // UART2 Clock Gate Control
#define SCGC4_UART2_offset  (12)
#define SCGC4_UART3         (0x00002000U) // UART3 Clock Gate Control
#define SCGC4_UART3_offset  (13)
#define SCGC4_USBOTG        (0x00040000U) // USB Clock Gate Control
#define SCGC4_USBOTG_offset (18)
#define SCGC4_CMP           (0x00080000U) // Comparator Clock Gate Control
#define SCGC4_CMP_offset    (19)
#define SCGC4_VREF          (0x00100000U) // VREF Clock Gate Control
#define SCGC4_VREF_offset   (20)

// SCGC5 (System Clock Gating Control Register 5)
#define SCGC5_LPTMR        (0x00000001U) // Low Power Timer Access Control
#define SCGC5_LPTMR_offset (0)
#define SCGC5_PORTA        (0x00000200U) // Port A Clock Gate Control
#define SCGC5_PORTA_offset (9)
#define SCGC5_PORTB        (0x00000400U) // Port B Clock Gate Control
#define SCGC5_PORTB_offset (10)
#define SCGC5_PORTC        (0x00000800U) // Port C Clock Gate Control
#define SCGC5_PORTC_offset (11)
#define SCGC5_PORTD        (0x00001000U) // Port D Clock Gate Control
#define SCGC5_PORTD_offset (12)
#define SCGC5_PORTE        (0x00002000U) // Port E Clock Gate Control
#define SCGC5_PORTE_offset (13)

// SCGC6 (System Clock Gating Control Register 6)
#define SCGC6_FTF             (0x00000001U) // Flash Memory Clock Gate Control
#define SCGC6_FTF_offset      (0)
#define SCGC6_DMAMUX          (0x00000002U) // DMA Mux Clock Gate Control
#define SCGC6_DMAMUX_offset   (1)
#define SCGC6_FLEXCAN0        (0x00000010U) // FlexCAN0 Clock Gate Control
#define SCGC6_FLEXCAN0_offset (4)
#define SCGC6_RNGA            (0x00000200U) // RNGA Clock Gate Control
#define SCGC6_RNGA_offset     (9)
#define SCGC6_SPI0            (0x00001000U) // SPI0 Clock Gate Control
#define SCGC6_SPI0_offset     (12)
#define SCGC6_SPI1            (0x00002000U) // SPI1 Clock Gate Control
#define SCGC6_SPI1_offset     (13)
#define SCGC6_I2S             (0x00008000U) // I2S Clock Gate Control
#define SCGC6_I2S_offset      (15)
#define SCGC6_CRC             (0x00040000U) // CRC Clock Gate Control
#define SCGC6_CRC_offset      (18)
#define SCGC6_USBDCD          (0x00200000U) // USB DCD Clock Gate Control
#define SCGC6_USBDCD_offset   (21)
#define SCGC6_PDB             (0x00400000U) // PDB Clock Gate Control
#define SCGC6_PDB_offset      (22)
#define SCGC6_PIT             (0x00800000U) // PIT Clock Gate Control
#define SCGC6_PIT_offset      (23)
#define SCGC6_FTM0            (0x01000000U) // FTM0 Clock Gate Control
#define SCGC6_FTM0_offset     (24)
#define SCGC6_FTM1            (0x02000000U) // FTM1 Clock Gate Control
#define SCGC6_FTM1_offset     (25)
#define SCGC6_FTM2            (0x04000000U) // FTM2 Clock Gate Control
#define SCGC6_FTM2_offset     (26)
#define SCGC6_ADC0            (0x08000000U) // ADC0 Clock Gate Control
#define SCGC6_ADC0_offset     (27)
#define SCGC6_RTC             (0x20000000U) // RTC Access Control
#define SCGC6_RTC_offset      (29)
#define SCGC6_DAC0            (0x80000000U) // DAC0 Clock Gate Control
#define SCGC6_DAC0_offset     (31)

// SCGC7 (System Clock Gating Control Register 7)
#define SCGC7_FLEXBUS        (0x00000001U) // FlexBus Clock Gate Control
#define SCGC7_FLEXBUS_offset (0)
#define SCGC7_DMA            (0x00000002U) // DMA Clock Gate Control
#define SCGC7_DMA_offset     (1)
#define SCGC7_MPU            (0x00000004U) // MPU Clock Gate Control
#define SCGC7_MPU_offset     (2)

// CLKDIV1 (System Clock Divider Register 1)
#define CLKDIV1_OUTDIV4_mask   (0x000F0000U) // Clock 4 output divider value
#define CLKDIV1_OUTDIV4_width  (4)
#define CLKDIV1_OUTDIV4(n)     ((n) << CLKDIV1_OUTDIV4_offset)
#define CLKDIV1_OUTDIV4_get(n) (((n) >> CLKDIV1_OUTDIV4_offset) & 0xFU)
#define CLKDIV1_OUTDIV4_offset (16)
#define CLKDIV1_OUTDIV3_mask   (0x00F00000U) // Clock 3 output divider value
#define CLKDIV1_OUTDIV3_width  (4)
#define CLKDIV1_OUTDIV3(n)     ((n) << CLKDIV1_OUTDIV3_offset)
#define CLKDIV1_OUTDIV3_get(n) (((n) >> CLKDIV1_OUTDIV3_offset) & 0xFU)
#define CLKDIV1_OUTDIV3_offset (20)
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
#define FCFG2_PFLSH           (0x00800000U) // Program flash only
#define FCFG2_PFLSH_offset    (23)
#define FCFG2_MAXADDR0_mask   (0x7F000000U) // Max address block 0
#define FCFG2_MAXADDR0_width  (7)
#define FCFG2_MAXADDR0(n)     ((n) << FCFG2_MAXADDR0_offset)
#define FCFG2_MAXADDR0_get(n) (((n) >> FCFG2_MAXADDR0_offset) & 0x7FU)
#define FCFG2_MAXADDR0_offset (24)

#define SIM ((struct SIMRegisters*)0x40047000)
