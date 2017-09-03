#pragma once

#include <stdint.h>

struct PORTRegisters {
  volatile uint32_t PCR[32];	// Pin Control Register n [0]
  volatile uint32_t GPCLR;	// Global Pin Control Low Register [80]
  volatile uint32_t GPCHR;	// Global Pin Control High Register [84]
  volatile uint8_t _reserved_136[24];
  volatile uint32_t ISFR;	// Interrupt Status Flag Register [a0]
};

// PCR (Pin Control Register n)
#define PCR_PS          (0x00000001U) // Pull Select
#define PCR_PS_offset   (0)
#define PCR_PE          (0x00000002U) // Pull Enable
#define PCR_PE_offset   (1)
#define PCR_SRE         (0x00000004U) // Slew Rate Enable
#define PCR_SRE_offset  (2)
#define PCR_PFE         (0x00000010U) // Passive Filter Enable
#define PCR_PFE_offset  (4)
#define PCR_ODE         (0x00000020U) // Open Drain Enable
#define PCR_ODE_offset  (5)
#define PCR_DSE         (0x00000040U) // Drive Strength Enable
#define PCR_DSE_offset  (6)
#define PCR_MUX_mask    (0x00000700U) // Pin Mux Control
#define PCR_MUX_width   (3)
#define PCR_MUX(n)      ((n) << PCR_MUX_offset)
#define PCR_MUX_get(n)  (((n) >> PCR_MUX_offset) & 0x7U)
#define PCR_MUX_offset  (8)
#define PCR_LK          (0x00008000U) // Lock Register
#define PCR_LK_offset   (15)
#define PCR_IRQC_mask   (0x000F0000U) // Interrupt Configuration
#define PCR_IRQC_width  (4)
#define PCR_IRQC(n)     ((n) << PCR_IRQC_offset)
#define PCR_IRQC_get(n) (((n) >> PCR_IRQC_offset) & 0xFU)
#define PCR_IRQC_offset (16)
#define PCR_ISF         (0x01000000U) // Interrupt Status Flag
#define PCR_ISF_offset  (24)

// GPCLR (Global Pin Control Low Register)
#define GPCLR_GPWD_mask   (0x0000FFFFU) // Global Pin Write Data
#define GPCLR_GPWD_width  (16)
#define GPCLR_GPWD(n)     ((n) << GPCLR_GPWD_offset)
#define GPCLR_GPWD_get(n) (((n) >> GPCLR_GPWD_offset) & 0xFFFFU)
#define GPCLR_GPWD_offset (0)
#define GPCLR_GPWE_mask   (0xFFFF0000U) // Global Pin Write Enable
#define GPCLR_GPWE_width  (16)
#define GPCLR_GPWE(n)     ((n) << GPCLR_GPWE_offset)
#define GPCLR_GPWE_get(n) (((n) >> GPCLR_GPWE_offset) & 0xFFFFU)
#define GPCLR_GPWE_offset (16)

// GPCHR (Global Pin Control High Register)
#define GPCHR_GPWD_mask   (0x0000FFFFU) // Global Pin Write Data
#define GPCHR_GPWD_width  (16)
#define GPCHR_GPWD(n)     ((n) << GPCHR_GPWD_offset)
#define GPCHR_GPWD_get(n) (((n) >> GPCHR_GPWD_offset) & 0xFFFFU)
#define GPCHR_GPWD_offset (0)
#define GPCHR_GPWE_mask   (0xFFFF0000U) // Global Pin Write Enable
#define GPCHR_GPWE_width  (16)
#define GPCHR_GPWE(n)     ((n) << GPCHR_GPWE_offset)
#define GPCHR_GPWE_get(n) (((n) >> GPCHR_GPWE_offset) & 0xFFFFU)
#define GPCHR_GPWE_offset (16)
