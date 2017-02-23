#pragma once

#include <stdint.h>

typedef struct {
  volatile uint32_t PCR[32];	// Pin Control Register n
  volatile uint32_t GPCLR;	// Global Pin Control Low Register
  volatile uint32_t GPCHR;	// Global Pin Control High Register
  volatile  uint8_t _reserved_136[24];
  volatile uint32_t ISFR;	// Interrupt Status Flag Register
} PORTRegisters;

// PCR (Pin Control Register n)
#define PORT_PCR_PS_mask     (0x00000001U) // Pull Select
#define PORT_PCR_PS_offset   (0)
#define PORT_PCR_PS_width    (1)
#define PORT_PCR_PE_mask     (0x00000002U) // Pull Enable
#define PORT_PCR_PE_offset   (1)
#define PORT_PCR_PE_width    (1)
#define PORT_PCR_SRE_mask    (0x00000004U) // Slew Rate Enable
#define PORT_PCR_SRE_offset  (2)
#define PORT_PCR_SRE_width   (1)
#define PORT_PCR_PFE_mask    (0x00000010U) // Passive Filter Enable
#define PORT_PCR_PFE_offset  (4)
#define PORT_PCR_PFE_width   (1)
#define PORT_PCR_ODE_mask    (0x00000020U) // Open Drain Enable
#define PORT_PCR_ODE_offset  (5)
#define PORT_PCR_ODE_width   (1)
#define PORT_PCR_DSE_mask    (0x00000040U) // Drive Strength Enable
#define PORT_PCR_DSE_offset  (6)
#define PORT_PCR_DSE_width   (1)
#define PORT_PCR_MUX_mask    (0x00000700U) // Pin Mux Control
#define PORT_PCR_MUX_offset  (8)
#define PORT_PCR_MUX_width   (3)
#define PORT_PCR_LK_mask     (0x00008000U) // Lock Register
#define PORT_PCR_LK_offset   (15)
#define PORT_PCR_LK_width    (1)
#define PORT_PCR_IRQC_mask   (0x000F0000U) // Interrupt Configuration
#define PORT_PCR_IRQC_offset (16)
#define PORT_PCR_IRQC_width  (4)
#define PORT_PCR_ISF_mask    (0x01000000U) // Interrupt Status Flag
#define PORT_PCR_ISF_offset  (24)
#define PORT_PCR_ISF_width   (1)

// GPCLR (Global Pin Control Low Register)
#define PORT_GPCLR_GPWD_mask   (0x0000FFFFU) // Global Pin Write Data
#define PORT_GPCLR_GPWD_offset (0)
#define PORT_GPCLR_GPWD_width  (16)
#define PORT_GPCLR_GPWE_mask   (0xFFFF0000U) // Global Pin Write Enable
#define PORT_GPCLR_GPWE_offset (16)
#define PORT_GPCLR_GPWE_width  (16)

// GPCHR (Global Pin Control High Register)
#define PORT_GPCHR_GPWD_mask   (0x0000FFFFU) // Global Pin Write Data
#define PORT_GPCHR_GPWD_offset (0)
#define PORT_GPCHR_GPWD_width  (16)
#define PORT_GPCHR_GPWE_mask   (0xFFFF0000U) // Global Pin Write Enable
#define PORT_GPCHR_GPWE_offset (16)
#define PORT_GPCHR_GPWE_width  (16)
