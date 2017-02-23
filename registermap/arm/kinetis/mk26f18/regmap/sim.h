#pragma once
/**
 * Register definitions for SIM peripheral
 * AUTOMATICALLY GENERATED. DO NOT EDIT MANUALLY
 */

#include <stdint.h>

typedef struct {
  volatile uint32_t SOPT1;	// System Options Register 1 [0]
  volatile uint32_t SOPT1CFG;	// SOPT1 Configuration Register [4]
  volatile uint32_t USBPHYCTL;	// USB PHY Control Register [8]
  volatile uint8_t _reserved_12[4088];
  volatile uint32_t SOPT2;	// System Options Register 2 [1004]
  volatile uint8_t _reserved_4104[4];
  volatile uint32_t SOPT4;	// System Options Register 4 [100c]
  volatile uint32_t SOPT5;	// System Options Register 5 [1010]
  volatile uint8_t _reserved_4116[4];
  volatile uint32_t SOPT7;	// System Options Register 7 [1018]
  volatile uint32_t SOPT8;	// System Options Register 8 [101c]
  volatile uint32_t SOPT9;	// System Options Register 9 [1020]
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
  volatile uint32_t CLKDIV3;	// System Clock Divider Register 3 [1064]
  volatile uint32_t CLKDIV4;	// System Clock Divider Register 4 [1068]
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

// USBPHYCTL (USB PHY Control Register)
#define SIM_USBPHYCTL_USBVREGSEL_mask    (0x00000100U) // Selects the default input voltage source to the USB Regulator in case both VREG_IN0 and VREG_IN1 are powered
#define SIM_USBPHYCTL_USBVREGSEL_offset  (8)
#define SIM_USBPHYCTL_USBVREGSEL_width   (1)
#define SIM_USBPHYCTL_USBVREGPD_mask     (0x00000200U) // Enables the pulldown on the output of the USB Regulator
#define SIM_USBPHYCTL_USBVREGPD_offset   (9)
#define SIM_USBPHYCTL_USBVREGPD_width    (1)
#define SIM_USBPHYCTL_USB3VOUTTRG_mask   (0x00700000U) // USB 3.3V Output Target
#define SIM_USBPHYCTL_USB3VOUTTRG_offset (20)
#define SIM_USBPHYCTL_USB3VOUTTRG_width  (3)
#define SIM_USBPHYCTL_USBDISILIM_mask    (0x00800000U) // USB Disable Inrush Current Limit
#define SIM_USBPHYCTL_USBDISILIM_offset  (23)
#define SIM_USBPHYCTL_USBDISILIM_width   (1)

// SOPT2 (System Options Register 2)
#define SIM_SOPT2_USBSLSRC_mask       (0x00000001U) // USB Slow Clock Source
#define SIM_SOPT2_USBSLSRC_offset     (0)
#define SIM_SOPT2_USBSLSRC_width      (1)
#define SIM_SOPT2_USBREGEN_mask       (0x00000002U) // USB PHY PLL Regulator Enable
#define SIM_SOPT2_USBREGEN_offset     (1)
#define SIM_SOPT2_USBREGEN_width      (1)
#define SIM_SOPT2_RTCCLKOUTSEL_mask   (0x00000010U) // RTC clock out select
#define SIM_SOPT2_RTCCLKOUTSEL_offset (4)
#define SIM_SOPT2_RTCCLKOUTSEL_width  (1)
#define SIM_SOPT2_CLKOUTSEL_mask      (0x000000E0U) // CLKOUT select
#define SIM_SOPT2_CLKOUTSEL_offset    (5)
#define SIM_SOPT2_CLKOUTSEL_width     (3)
#define SIM_SOPT2_FBSL_mask           (0x00000300U) // FlexBus security level
#define SIM_SOPT2_FBSL_offset         (8)
#define SIM_SOPT2_FBSL_width          (2)
#define SIM_SOPT2_TRACECLKSEL_mask    (0x00001000U) // Debug trace clock select
#define SIM_SOPT2_TRACECLKSEL_offset  (12)
#define SIM_SOPT2_TRACECLKSEL_width   (1)
#define SIM_SOPT2_PLLFLLSEL_mask      (0x00030000U) // PLL/FLL clock select
#define SIM_SOPT2_PLLFLLSEL_offset    (16)
#define SIM_SOPT2_PLLFLLSEL_width     (2)
#define SIM_SOPT2_USBSRC_mask         (0x00040000U) // USB clock source select
#define SIM_SOPT2_USBSRC_offset       (18)
#define SIM_SOPT2_USBSRC_width        (1)
#define SIM_SOPT2_TPMSRC_mask         (0x03000000U) // TPM clock source select
#define SIM_SOPT2_TPMSRC_offset       (24)
#define SIM_SOPT2_TPMSRC_width        (2)
#define SIM_SOPT2_LPUARTSRC_mask      (0x0C000000U) // LPUART clock source select
#define SIM_SOPT2_LPUARTSRC_offset    (26)
#define SIM_SOPT2_LPUARTSRC_width     (2)
#define SIM_SOPT2_SDHCSRC_mask        (0x30000000U) // SDHC clock source select
#define SIM_SOPT2_SDHCSRC_offset      (28)
#define SIM_SOPT2_SDHCSRC_width       (2)

// SOPT4 (System Options Register 4)
#define SIM_SOPT4_FTM0FLT0_mask      (0x00000001U) // FTM0 Fault 0 Select
#define SIM_SOPT4_FTM0FLT0_offset    (0)
#define SIM_SOPT4_FTM0FLT0_width     (1)
#define SIM_SOPT4_FTM0FLT1_mask      (0x00000002U) // FTM0 Fault 1 Select
#define SIM_SOPT4_FTM0FLT1_offset    (1)
#define SIM_SOPT4_FTM0FLT1_width     (1)
#define SIM_SOPT4_FTM0FLT2_mask      (0x00000004U) // FTM0 Fault 2 Select
#define SIM_SOPT4_FTM0FLT2_offset    (2)
#define SIM_SOPT4_FTM0FLT2_width     (1)
#define SIM_SOPT4_FTM0FLT3_mask      (0x00000008U) // FTM0 Fault 3 Select
#define SIM_SOPT4_FTM0FLT3_offset    (3)
#define SIM_SOPT4_FTM0FLT3_width     (1)
#define SIM_SOPT4_FTM1FLT0_mask      (0x00000010U) // FTM1 Fault 0 Select
#define SIM_SOPT4_FTM1FLT0_offset    (4)
#define SIM_SOPT4_FTM1FLT0_width     (1)
#define SIM_SOPT4_FTM2FLT0_mask      (0x00000100U) // FTM2 Fault 0 Select
#define SIM_SOPT4_FTM2FLT0_offset    (8)
#define SIM_SOPT4_FTM2FLT0_width     (1)
#define SIM_SOPT4_FTM3FLT0_mask      (0x00001000U) // FTM3 Fault 0 Select
#define SIM_SOPT4_FTM3FLT0_offset    (12)
#define SIM_SOPT4_FTM3FLT0_width     (1)
#define SIM_SOPT4_FTM1CH0SRC_mask    (0x000C0000U) // FTM1 channel 0 input capture source select
#define SIM_SOPT4_FTM1CH0SRC_offset  (18)
#define SIM_SOPT4_FTM1CH0SRC_width   (2)
#define SIM_SOPT4_FTM2CH0SRC_mask    (0x00300000U) // FTM2 channel 0 input capture source select
#define SIM_SOPT4_FTM2CH0SRC_offset  (20)
#define SIM_SOPT4_FTM2CH0SRC_width   (2)
#define SIM_SOPT4_FTM2CH1SRC_mask    (0x00400000U) // FTM2 channel 1 input capture source select
#define SIM_SOPT4_FTM2CH1SRC_offset  (22)
#define SIM_SOPT4_FTM2CH1SRC_width   (1)
#define SIM_SOPT4_FTM0CLKSEL_mask    (0x01000000U) // FlexTimer 0 External Clock Pin Select
#define SIM_SOPT4_FTM0CLKSEL_offset  (24)
#define SIM_SOPT4_FTM0CLKSEL_width   (1)
#define SIM_SOPT4_FTM1CLKSEL_mask    (0x02000000U) // FTM1 External Clock Pin Select
#define SIM_SOPT4_FTM1CLKSEL_offset  (25)
#define SIM_SOPT4_FTM1CLKSEL_width   (1)
#define SIM_SOPT4_FTM2CLKSEL_mask    (0x04000000U) // FlexTimer 2 External Clock Pin Select
#define SIM_SOPT4_FTM2CLKSEL_offset  (26)
#define SIM_SOPT4_FTM2CLKSEL_width   (1)
#define SIM_SOPT4_FTM3CLKSEL_mask    (0x08000000U) // FlexTimer 3 External Clock Pin Select
#define SIM_SOPT4_FTM3CLKSEL_offset  (27)
#define SIM_SOPT4_FTM3CLKSEL_width   (1)
#define SIM_SOPT4_FTM0TRG0SRC_mask   (0x10000000U) // FlexTimer 0 Hardware Trigger 0 Source Select
#define SIM_SOPT4_FTM0TRG0SRC_offset (28)
#define SIM_SOPT4_FTM0TRG0SRC_width  (1)
#define SIM_SOPT4_FTM0TRG1SRC_mask   (0x20000000U) // FlexTimer 0 Hardware Trigger 1 Source Select
#define SIM_SOPT4_FTM0TRG1SRC_offset (29)
#define SIM_SOPT4_FTM0TRG1SRC_width  (1)
#define SIM_SOPT4_FTM3TRG0SRC_mask   (0x40000000U) // FlexTimer 3 Hardware Trigger 0 Source Select
#define SIM_SOPT4_FTM3TRG0SRC_offset (30)
#define SIM_SOPT4_FTM3TRG0SRC_width  (1)
#define SIM_SOPT4_FTM3TRG1SRC_mask   (0x80000000U) // FlexTimer 3 Hardware Trigger 1 Source Select
#define SIM_SOPT4_FTM3TRG1SRC_offset (31)
#define SIM_SOPT4_FTM3TRG1SRC_width  (1)

// SOPT5 (System Options Register 5)
#define SIM_SOPT5_UART0TXSRC_mask     (0x00000003U) // UART 0 transmit data source select
#define SIM_SOPT5_UART0TXSRC_offset   (0)
#define SIM_SOPT5_UART0TXSRC_width    (2)
#define SIM_SOPT5_UART0RXSRC_mask     (0x0000000CU) // UART 0 receive data source select
#define SIM_SOPT5_UART0RXSRC_offset   (2)
#define SIM_SOPT5_UART0RXSRC_width    (2)
#define SIM_SOPT5_UART1TXSRC_mask     (0x00000030U) // UART 1 transmit data source select
#define SIM_SOPT5_UART1TXSRC_offset   (4)
#define SIM_SOPT5_UART1TXSRC_width    (2)
#define SIM_SOPT5_UART1RXSRC_mask     (0x000000C0U) // UART 1 receive data source select
#define SIM_SOPT5_UART1RXSRC_offset   (6)
#define SIM_SOPT5_UART1RXSRC_width    (2)
#define SIM_SOPT5_LPUART0TXSRC_mask   (0x00030000U) // LPUART0 transmit data source select
#define SIM_SOPT5_LPUART0TXSRC_offset (16)
#define SIM_SOPT5_LPUART0TXSRC_width  (2)
#define SIM_SOPT5_LPUART0RXSRC_mask   (0x000C0000U) // LPUART0 receive data source select
#define SIM_SOPT5_LPUART0RXSRC_offset (18)
#define SIM_SOPT5_LPUART0RXSRC_width  (2)

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
#define SIM_SOPT7_ADC1TRGSEL_mask      (0x00000F00U) // ADC1 trigger select
#define SIM_SOPT7_ADC1TRGSEL_offset    (8)
#define SIM_SOPT7_ADC1TRGSEL_width     (4)
#define SIM_SOPT7_ADC1PRETRGSEL_mask   (0x00001000U) // ADC1 pre-trigger select
#define SIM_SOPT7_ADC1PRETRGSEL_offset (12)
#define SIM_SOPT7_ADC1PRETRGSEL_width  (1)
#define SIM_SOPT7_ADC1ALTTRGEN_mask    (0x00008000U) // ADC1 alternate trigger enable
#define SIM_SOPT7_ADC1ALTTRGEN_offset  (15)
#define SIM_SOPT7_ADC1ALTTRGEN_width   (1)

// SOPT8 (System Options Register 8)
#define SIM_SOPT8_FTM0SYNCBIT_mask   (0x00000001U) // FTM0 Hardware Trigger 0 Software Synchronization
#define SIM_SOPT8_FTM0SYNCBIT_offset (0)
#define SIM_SOPT8_FTM0SYNCBIT_width  (1)
#define SIM_SOPT8_FTM1SYNCBIT_mask   (0x00000002U) // FTM1 Hardware Trigger 0 Software Synchronization
#define SIM_SOPT8_FTM1SYNCBIT_offset (1)
#define SIM_SOPT8_FTM1SYNCBIT_width  (1)
#define SIM_SOPT8_FTM2SYNCBIT_mask   (0x00000004U) // FTM2 Hardware Trigger 0 Software Synchronization
#define SIM_SOPT8_FTM2SYNCBIT_offset (2)
#define SIM_SOPT8_FTM2SYNCBIT_width  (1)
#define SIM_SOPT8_FTM3SYNCBIT_mask   (0x00000008U) // FTM3 Hardware Trigger 0 Software Synchronization
#define SIM_SOPT8_FTM3SYNCBIT_offset (3)
#define SIM_SOPT8_FTM3SYNCBIT_width  (1)
#define SIM_SOPT8_FTM0OCH0SRC_mask   (0x00010000U) // FTM0 channel 0 output source
#define SIM_SOPT8_FTM0OCH0SRC_offset (16)
#define SIM_SOPT8_FTM0OCH0SRC_width  (1)
#define SIM_SOPT8_FTM0OCH1SRC_mask   (0x00020000U) // FTM0 channel 1 output source
#define SIM_SOPT8_FTM0OCH1SRC_offset (17)
#define SIM_SOPT8_FTM0OCH1SRC_width  (1)
#define SIM_SOPT8_FTM0OCH2SRC_mask   (0x00040000U) // FTM0 channel 2 output source
#define SIM_SOPT8_FTM0OCH2SRC_offset (18)
#define SIM_SOPT8_FTM0OCH2SRC_width  (1)
#define SIM_SOPT8_FTM0OCH3SRC_mask   (0x00080000U) // FTM0 channel 3 output source
#define SIM_SOPT8_FTM0OCH3SRC_offset (19)
#define SIM_SOPT8_FTM0OCH3SRC_width  (1)
#define SIM_SOPT8_FTM0OCH4SRC_mask   (0x00100000U) // FTM0 channel 4 output source
#define SIM_SOPT8_FTM0OCH4SRC_offset (20)
#define SIM_SOPT8_FTM0OCH4SRC_width  (1)
#define SIM_SOPT8_FTM0OCH5SRC_mask   (0x00200000U) // FTM0 channel 5 output source
#define SIM_SOPT8_FTM0OCH5SRC_offset (21)
#define SIM_SOPT8_FTM0OCH5SRC_width  (1)
#define SIM_SOPT8_FTM0OCH6SRC_mask   (0x00400000U) // FTM0 channel 6 output source
#define SIM_SOPT8_FTM0OCH6SRC_offset (22)
#define SIM_SOPT8_FTM0OCH6SRC_width  (1)
#define SIM_SOPT8_FTM0OCH7SRC_mask   (0x00800000U) // FTM0 channel 7 output source
#define SIM_SOPT8_FTM0OCH7SRC_offset (23)
#define SIM_SOPT8_FTM0OCH7SRC_width  (1)
#define SIM_SOPT8_FTM3OCH0SRC_mask   (0x01000000U) // FTM3 channel 0 output source
#define SIM_SOPT8_FTM3OCH0SRC_offset (24)
#define SIM_SOPT8_FTM3OCH0SRC_width  (1)
#define SIM_SOPT8_FTM3OCH1SRC_mask   (0x02000000U) // FTM3 channel 1 output source
#define SIM_SOPT8_FTM3OCH1SRC_offset (25)
#define SIM_SOPT8_FTM3OCH1SRC_width  (1)
#define SIM_SOPT8_FTM3OCH2SRC_mask   (0x04000000U) // FTM3 channel 2 output source
#define SIM_SOPT8_FTM3OCH2SRC_offset (26)
#define SIM_SOPT8_FTM3OCH2SRC_width  (1)
#define SIM_SOPT8_FTM3OCH3SRC_mask   (0x08000000U) // FTM3 channel 3 output source
#define SIM_SOPT8_FTM3OCH3SRC_offset (27)
#define SIM_SOPT8_FTM3OCH3SRC_width  (1)
#define SIM_SOPT8_FTM3OCH4SRC_mask   (0x10000000U) // FTM3 channel 4 output source
#define SIM_SOPT8_FTM3OCH4SRC_offset (28)
#define SIM_SOPT8_FTM3OCH4SRC_width  (1)
#define SIM_SOPT8_FTM3OCH5SRC_mask   (0x20000000U) // FTM3 channel 5 output source
#define SIM_SOPT8_FTM3OCH5SRC_offset (29)
#define SIM_SOPT8_FTM3OCH5SRC_width  (1)
#define SIM_SOPT8_FTM3OCH6SRC_mask   (0x40000000U) // FTM3 channel 6 output source
#define SIM_SOPT8_FTM3OCH6SRC_offset (30)
#define SIM_SOPT8_FTM3OCH6SRC_width  (1)
#define SIM_SOPT8_FTM3OCH7SRC_mask   (0x80000000U) // FTM3 channel 7 output source
#define SIM_SOPT8_FTM3OCH7SRC_offset (31)
#define SIM_SOPT8_FTM3OCH7SRC_width  (1)

// SOPT9 (System Options Register 9)
#define SIM_SOPT9_TPM1CH0SRC_mask   (0x000C0000U) // TPM1 channel 0 input capture source select
#define SIM_SOPT9_TPM1CH0SRC_offset (18)
#define SIM_SOPT9_TPM1CH0SRC_width  (2)
#define SIM_SOPT9_TPM2CH0SRC_mask   (0x00300000U) // TPM2 channel 0 input capture source select
#define SIM_SOPT9_TPM2CH0SRC_offset (20)
#define SIM_SOPT9_TPM2CH0SRC_width  (2)
#define SIM_SOPT9_TPM1CLKSEL_mask   (0x02000000U) // TPM1 External Clock Pin Select
#define SIM_SOPT9_TPM1CLKSEL_offset (25)
#define SIM_SOPT9_TPM1CLKSEL_width  (1)
#define SIM_SOPT9_TPM2CLKSEL_mask   (0x04000000U) // TPM2 External Clock Pin Select
#define SIM_SOPT9_TPM2CLKSEL_offset (26)
#define SIM_SOPT9_TPM2CLKSEL_width  (1)

// SDID (System Device Identification Register)
#define SIM_SDID_PINID_mask      (0x0000000FU) // Pincount identification
#define SIM_SDID_PINID_offset    (0)
#define SIM_SDID_PINID_width     (4)
#define SIM_SDID_FAMID_mask      (0x00000070U) // Kinetis family identification
#define SIM_SDID_FAMID_offset    (4)
#define SIM_SDID_FAMID_width     (3)
#define SIM_SDID_DIEID_mask      (0x00000F80U) // Device Die ID
#define SIM_SDID_DIEID_offset    (7)
#define SIM_SDID_DIEID_width     (5)
#define SIM_SDID_REVID_mask      (0x0000F000U) // Device revision number
#define SIM_SDID_REVID_offset    (12)
#define SIM_SDID_REVID_width     (4)
#define SIM_SDID_SERIESID_mask   (0x00F00000U) // Kinetis Series ID
#define SIM_SDID_SERIESID_offset (20)
#define SIM_SDID_SERIESID_width  (4)
#define SIM_SDID_SUBFAMID_mask   (0x0F000000U) // Kinetis Sub-Family ID
#define SIM_SDID_SUBFAMID_offset (24)
#define SIM_SDID_SUBFAMID_width  (4)
#define SIM_SDID_FAMILYID_mask   (0xF0000000U) // Kinetis Family ID
#define SIM_SDID_FAMILYID_offset (28)
#define SIM_SDID_FAMILYID_width  (4)

// SCGC1 (System Clock Gating Control Register 1)
#define SIM_SCGC1_I2C2_mask    (0x00000040U) // I2C2 Clock Gate Control
#define SIM_SCGC1_I2C2_offset  (6)
#define SIM_SCGC1_I2C2_width   (1)
#define SIM_SCGC1_I2C3_mask    (0x00000080U) // I2C3 Clock Gate Control
#define SIM_SCGC1_I2C3_offset  (7)
#define SIM_SCGC1_I2C3_width   (1)
#define SIM_SCGC1_UART4_mask   (0x00000400U) // UART4 Clock Gate Control
#define SIM_SCGC1_UART4_offset (10)
#define SIM_SCGC1_UART4_width  (1)

// SCGC2 (System Clock Gating Control Register 2)
#define SIM_SCGC2_LPUART0_mask   (0x00000010U) // LPUART0 Clock Gate Control
#define SIM_SCGC2_LPUART0_offset (4)
#define SIM_SCGC2_LPUART0_width  (1)
#define SIM_SCGC2_TPM1_mask      (0x00000200U) // TPM1 Clock Gate Control
#define SIM_SCGC2_TPM1_offset    (9)
#define SIM_SCGC2_TPM1_width     (1)
#define SIM_SCGC2_TPM2_mask      (0x00000400U) // TPM2 Clock Gate Control
#define SIM_SCGC2_TPM2_offset    (10)
#define SIM_SCGC2_TPM2_width     (1)
#define SIM_SCGC2_DAC0_mask      (0x00001000U) // DAC0 Clock Gate Control
#define SIM_SCGC2_DAC0_offset    (12)
#define SIM_SCGC2_DAC0_width     (1)
#define SIM_SCGC2_DAC1_mask      (0x00002000U) // DAC1 Clock Gate Control
#define SIM_SCGC2_DAC1_offset    (13)
#define SIM_SCGC2_DAC1_width     (1)

// SCGC3 (System Clock Gating Control Register 3)
#define SIM_SCGC3_RNGA_mask       (0x00000001U) // RNGA Clock Gate Control
#define SIM_SCGC3_RNGA_offset     (0)
#define SIM_SCGC3_RNGA_width      (1)
#define SIM_SCGC3_USBHS_mask      (0x00000002U) // USBHS Clock Gate Control
#define SIM_SCGC3_USBHS_offset    (1)
#define SIM_SCGC3_USBHS_width     (1)
#define SIM_SCGC3_USBHSPHY_mask   (0x00000004U) // USBHS PHY Clock Gate Control
#define SIM_SCGC3_USBHSPHY_offset (2)
#define SIM_SCGC3_USBHSPHY_width  (1)
#define SIM_SCGC3_USBHSDCD_mask   (0x00000008U) // USBHS DCD Clock Gate Control
#define SIM_SCGC3_USBHSDCD_offset (3)
#define SIM_SCGC3_USBHSDCD_width  (1)
#define SIM_SCGC3_FLEXCAN1_mask   (0x00000010U) // FlexCAN1 Clock Gate Control
#define SIM_SCGC3_FLEXCAN1_offset (4)
#define SIM_SCGC3_FLEXCAN1_width  (1)
#define SIM_SCGC3_SPI2_mask       (0x00001000U) // SPI2 Clock Gate Control
#define SIM_SCGC3_SPI2_offset     (12)
#define SIM_SCGC3_SPI2_width      (1)
#define SIM_SCGC3_SDHC_mask       (0x00020000U) // SDHC Clock Gate Control
#define SIM_SCGC3_SDHC_offset     (17)
#define SIM_SCGC3_SDHC_width      (1)
#define SIM_SCGC3_FTM2_mask       (0x01000000U) // FTM2 Clock Gate Control
#define SIM_SCGC3_FTM2_offset     (24)
#define SIM_SCGC3_FTM2_width      (1)
#define SIM_SCGC3_FTM3_mask       (0x02000000U) // FTM3 Clock Gate Control
#define SIM_SCGC3_FTM3_offset     (25)
#define SIM_SCGC3_FTM3_width      (1)
#define SIM_SCGC3_ADC1_mask       (0x08000000U) // ADC1 Clock Gate Control
#define SIM_SCGC3_ADC1_offset     (27)
#define SIM_SCGC3_ADC1_width      (1)

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
#define SIM_SCGC4_I2C1_mask     (0x00000080U) // I2C1 Clock Gate Control
#define SIM_SCGC4_I2C1_offset   (7)
#define SIM_SCGC4_I2C1_width    (1)
#define SIM_SCGC4_UART0_mask    (0x00000400U) // UART0 Clock Gate Control
#define SIM_SCGC4_UART0_offset  (10)
#define SIM_SCGC4_UART0_width   (1)
#define SIM_SCGC4_UART1_mask    (0x00000800U) // UART1 Clock Gate Control
#define SIM_SCGC4_UART1_offset  (11)
#define SIM_SCGC4_UART1_width   (1)
#define SIM_SCGC4_UART2_mask    (0x00001000U) // UART2 Clock Gate Control
#define SIM_SCGC4_UART2_offset  (12)
#define SIM_SCGC4_UART2_width   (1)
#define SIM_SCGC4_UART3_mask    (0x00002000U) // UART3 Clock Gate Control
#define SIM_SCGC4_UART3_offset  (13)
#define SIM_SCGC4_UART3_width   (1)
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
#define SIM_SCGC5_LPTMR_mask   (0x00000001U) // Low Power Timer Access Control
#define SIM_SCGC5_LPTMR_offset (0)
#define SIM_SCGC5_LPTMR_width  (1)
#define SIM_SCGC5_TSI_mask     (0x00000020U) // TSI Clock Gate Control
#define SIM_SCGC5_TSI_offset   (5)
#define SIM_SCGC5_TSI_width    (1)
#define SIM_SCGC5_PORTA_mask   (0x00000200U) // Port A Clock Gate Control
#define SIM_SCGC5_PORTA_offset (9)
#define SIM_SCGC5_PORTA_width  (1)
#define SIM_SCGC5_PORTB_mask   (0x00000400U) // Port B Clock Gate Control
#define SIM_SCGC5_PORTB_offset (10)
#define SIM_SCGC5_PORTB_width  (1)
#define SIM_SCGC5_PORTC_mask   (0x00000800U) // Port C Clock Gate Control
#define SIM_SCGC5_PORTC_offset (11)
#define SIM_SCGC5_PORTC_width  (1)
#define SIM_SCGC5_PORTD_mask   (0x00001000U) // Port D Clock Gate Control
#define SIM_SCGC5_PORTD_offset (12)
#define SIM_SCGC5_PORTD_width  (1)
#define SIM_SCGC5_PORTE_mask   (0x00002000U) // Port E Clock Gate Control
#define SIM_SCGC5_PORTE_offset (13)
#define SIM_SCGC5_PORTE_width  (1)

// SCGC6 (System Clock Gating Control Register 6)
#define SIM_SCGC6_FTF_mask        (0x00000001U) // Flash Memory Clock Gate Control
#define SIM_SCGC6_FTF_offset      (0)
#define SIM_SCGC6_FTF_width       (1)
#define SIM_SCGC6_DMAMUX_mask     (0x00000002U) // DMA Mux Clock Gate Control
#define SIM_SCGC6_DMAMUX_offset   (1)
#define SIM_SCGC6_DMAMUX_width    (1)
#define SIM_SCGC6_FLEXCAN0_mask   (0x00000010U) // FlexCAN0 Clock Gate Control
#define SIM_SCGC6_FLEXCAN0_offset (4)
#define SIM_SCGC6_FLEXCAN0_width  (1)
#define SIM_SCGC6_RNGA_mask       (0x00000200U) // RNGA Clock Gate Control
#define SIM_SCGC6_RNGA_offset     (9)
#define SIM_SCGC6_RNGA_width      (1)
#define SIM_SCGC6_SPI0_mask       (0x00001000U) // SPI0 Clock Gate Control
#define SIM_SCGC6_SPI0_offset     (12)
#define SIM_SCGC6_SPI0_width      (1)
#define SIM_SCGC6_SPI1_mask       (0x00002000U) // SPI1 Clock Gate Control
#define SIM_SCGC6_SPI1_offset     (13)
#define SIM_SCGC6_SPI1_width      (1)
#define SIM_SCGC6_I2S_mask        (0x00008000U) // I2S Clock Gate Control
#define SIM_SCGC6_I2S_offset      (15)
#define SIM_SCGC6_I2S_width       (1)
#define SIM_SCGC6_CRC_mask        (0x00040000U) // CRC Clock Gate Control
#define SIM_SCGC6_CRC_offset      (18)
#define SIM_SCGC6_CRC_width       (1)
#define SIM_SCGC6_USBDCD_mask     (0x00200000U) // USB DCD Clock Gate Control
#define SIM_SCGC6_USBDCD_offset   (21)
#define SIM_SCGC6_USBDCD_width    (1)
#define SIM_SCGC6_PDB_mask        (0x00400000U) // PDB Clock Gate Control
#define SIM_SCGC6_PDB_offset      (22)
#define SIM_SCGC6_PDB_width       (1)
#define SIM_SCGC6_PIT_mask        (0x00800000U) // PIT Clock Gate Control
#define SIM_SCGC6_PIT_offset      (23)
#define SIM_SCGC6_PIT_width       (1)
#define SIM_SCGC6_FTM0_mask       (0x01000000U) // FTM0 Clock Gate Control
#define SIM_SCGC6_FTM0_offset     (24)
#define SIM_SCGC6_FTM0_width      (1)
#define SIM_SCGC6_FTM1_mask       (0x02000000U) // FTM1 Clock Gate Control
#define SIM_SCGC6_FTM1_offset     (25)
#define SIM_SCGC6_FTM1_width      (1)
#define SIM_SCGC6_FTM2_mask       (0x04000000U) // FTM2 Clock Gate Control
#define SIM_SCGC6_FTM2_offset     (26)
#define SIM_SCGC6_FTM2_width      (1)
#define SIM_SCGC6_ADC0_mask       (0x08000000U) // ADC0 Clock Gate Control
#define SIM_SCGC6_ADC0_offset     (27)
#define SIM_SCGC6_ADC0_width      (1)
#define SIM_SCGC6_RTC_mask        (0x20000000U) // RTC Access Control
#define SIM_SCGC6_RTC_offset      (29)
#define SIM_SCGC6_RTC_width       (1)
#define SIM_SCGC6_DAC0_mask       (0x80000000U) // DAC0 Clock Gate Control
#define SIM_SCGC6_DAC0_offset     (31)
#define SIM_SCGC6_DAC0_width      (1)

// SCGC7 (System Clock Gating Control Register 7)
#define SIM_SCGC7_FLEXBUS_mask   (0x00000001U) // FlexBus Clock Gate Control
#define SIM_SCGC7_FLEXBUS_offset (0)
#define SIM_SCGC7_FLEXBUS_width  (1)
#define SIM_SCGC7_DMA_mask       (0x00000002U) // DMA Clock Gate Control
#define SIM_SCGC7_DMA_offset     (1)
#define SIM_SCGC7_DMA_width      (1)
#define SIM_SCGC7_MPU_mask       (0x00000004U) // MPU Clock Gate Control
#define SIM_SCGC7_MPU_offset     (2)
#define SIM_SCGC7_MPU_width      (1)
#define SIM_SCGC7_SDRAMC_mask    (0x00000008U) // SDRAMC Clock Gate Control
#define SIM_SCGC7_SDRAMC_offset  (3)
#define SIM_SCGC7_SDRAMC_width   (1)

// CLKDIV1 (System Clock Divider Register 1)
#define SIM_CLKDIV1_OUTDIV4_mask   (0x000F0000U) // Clock 4 output divider value
#define SIM_CLKDIV1_OUTDIV4_offset (16)
#define SIM_CLKDIV1_OUTDIV4_width  (4)
#define SIM_CLKDIV1_OUTDIV3_mask   (0x00F00000U) // Clock 3 output divider value
#define SIM_CLKDIV1_OUTDIV3_offset (20)
#define SIM_CLKDIV1_OUTDIV3_width  (4)
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
#define SIM_FCFG2_MAXADDR1_mask    (0x007F0000U) // Max address block 1
#define SIM_FCFG2_MAXADDR1_offset  (16)
#define SIM_FCFG2_MAXADDR1_width   (7)
#define SIM_FCFG2_PFLSH_mask       (0x00800000U) // Program flash only
#define SIM_FCFG2_PFLSH_offset     (23)
#define SIM_FCFG2_PFLSH_width      (1)
#define SIM_FCFG2_MAXADDR0_mask    (0x7F000000U) // Max address block 0
#define SIM_FCFG2_MAXADDR0_offset  (24)
#define SIM_FCFG2_MAXADDR0_width   (7)
#define SIM_FCFG2_SWAPPFLSH_mask   (0x80000000U) // Swap program flash
#define SIM_FCFG2_SWAPPFLSH_offset (31)
#define SIM_FCFG2_SWAPPFLSH_width  (1)

// CLKDIV3 (System Clock Divider Register 3)
#define SIM_CLKDIV3_PLLFLLFRAC_mask   (0x00000001U) // PLLFLL clock divider fraction
#define SIM_CLKDIV3_PLLFLLFRAC_offset (0)
#define SIM_CLKDIV3_PLLFLLFRAC_width  (1)
#define SIM_CLKDIV3_PLLFLLDIV_mask    (0x0000000EU) // PLLFLL clock divider divisor
#define SIM_CLKDIV3_PLLFLLDIV_offset  (1)
#define SIM_CLKDIV3_PLLFLLDIV_width   (3)

// CLKDIV4 (System Clock Divider Register 4)
#define SIM_CLKDIV4_TRACEFRAC_mask   (0x00000001U) // Trace clock divider fraction
#define SIM_CLKDIV4_TRACEFRAC_offset (0)
#define SIM_CLKDIV4_TRACEFRAC_width  (1)
#define SIM_CLKDIV4_TRACEDIV_mask    (0x0000000EU) // Trace clock divider divisor
#define SIM_CLKDIV4_TRACEDIV_offset  (1)
#define SIM_CLKDIV4_TRACEDIV_width   (3)

#define SIM ((SIMRegisters*)0x40047000)
