#pragma once

#include <stdint.h>

struct UARTRegisters {
  volatile uint8_t BDH;	// UART Baud Rate Registers: High [0]
  volatile uint8_t BDL;	// UART Baud Rate Registers: Low [1]
  volatile uint8_t C1;	// UART Control Register 1 [2]
  volatile uint8_t C2;	// UART Control Register 2 [3]
  volatile uint8_t S1;	// UART Status Register 1 [4]
  volatile uint8_t S2;	// UART Status Register 2 [5]
  volatile uint8_t C3;	// UART Control Register 3 [6]
  volatile uint8_t D;	// UART Data Register [7]
  volatile uint8_t MA1;	// UART Match Address Registers 1 [8]
  volatile uint8_t MA2;	// UART Match Address Registers 2 [9]
  volatile uint8_t C4;	// UART Control Register 4 [a]
  volatile uint8_t C5;	// UART Control Register 5 [b]
  volatile uint8_t ED;	// UART Extended Data Register [c]
  volatile uint8_t MODEM;	// UART Modem Register [d]
  volatile uint8_t IR;	// UART Infrared Register [e]
  volatile uint8_t _reserved_15[1];
  volatile uint8_t PFIFO;	// UART FIFO Parameters [10]
  volatile uint8_t CFIFO;	// UART FIFO Control Register [11]
  volatile uint8_t SFIFO;	// UART FIFO Status Register [12]
  volatile uint8_t TWFIFO;	// UART FIFO Transmit Watermark [13]
  volatile uint8_t TCFIFO;	// UART FIFO Transmit Count [14]
  volatile uint8_t RWFIFO;	// UART FIFO Receive Watermark [15]
  volatile uint8_t RCFIFO;	// UART FIFO Receive Count [16]
};

// BDH (UART Baud Rate Registers: High)
#define BDH_SBR_mask       (0x1FU) // UART Baud Rate Bits
#define BDH_SBR_width      (5)
#define BDH_SBR(n)         ((n) << BDH_SBR_offset)
#define BDH_SBR_get(n)     (((n) >> BDH_SBR_offset) & 0x1FU)
#define BDH_SBR_offset     (0)
#define BDH_SBNS           (0x20U) // Stop Bit Number Select
#define BDH_SBNS_offset    (5)
#define BDH_RXEDGIE        (0x40U) // RxD Input Active Edge Interrupt Enable
#define BDH_RXEDGIE_offset (6)
#define BDH_LBKDIE         (0x80U) // LIN Break Detect Interrupt Enable
#define BDH_LBKDIE_offset  (7)

// C1 (UART Control Register 1)
#define C1_PT              (0x01U) // Parity Type
#define C1_PT_offset       (0)
#define C1_PE              (0x02U) // Parity Enable
#define C1_PE_offset       (1)
#define C1_ILT             (0x04U) // Idle Line Type Select
#define C1_ILT_offset      (2)
#define C1_WAKE            (0x08U) // Receiver Wakeup Method Select
#define C1_WAKE_offset     (3)
#define C1_M               (0x10U) // 9-bit or 8-bit Mode Select
#define C1_M_offset        (4)
#define C1_RSRC            (0x20U) // Receiver Source Select
#define C1_RSRC_offset     (5)
#define C1_UARTSWAI        (0x40U) // UART Stops in Wait Mode
#define C1_UARTSWAI_offset (6)
#define C1_LOOPS           (0x80U) // Loop Mode Select
#define C1_LOOPS_offset    (7)

// C2 (UART Control Register 2)
#define C2_SBK         (0x01U) // Send Break
#define C2_SBK_offset  (0)
#define C2_RWU         (0x02U) // Receiver Wakeup Control
#define C2_RWU_offset  (1)
#define C2_RE          (0x04U) // Receiver Enable
#define C2_RE_offset   (2)
#define C2_TE          (0x08U) // Transmitter Enable
#define C2_TE_offset   (3)
#define C2_ILIE        (0x10U) // Idle Line Interrupt Enable
#define C2_ILIE_offset (4)
#define C2_RIE         (0x20U) // Receiver Full Interrupt or DMA Transfer Enable
#define C2_RIE_offset  (5)
#define C2_TCIE        (0x40U) // Transmission Complete Interrupt Enable
#define C2_TCIE_offset (6)
#define C2_TIE         (0x80U) // Transmitter Interrupt or DMA Transfer Enable
#define C2_TIE_offset  (7)

// S1 (UART Status Register 1)
#define S1_PF          (0x01U) // Parity Error Flag
#define S1_PF_offset   (0)
#define S1_FE          (0x02U) // Framing Error Flag
#define S1_FE_offset   (1)
#define S1_NF          (0x04U) // Noise Flag
#define S1_NF_offset   (2)
#define S1_OR          (0x08U) // Receiver Overrun Flag
#define S1_OR_offset   (3)
#define S1_IDLE        (0x10U) // Idle Line Flag
#define S1_IDLE_offset (4)
#define S1_RDRF        (0x20U) // Receive Data Register Full Flag
#define S1_RDRF_offset (5)
#define S1_TC          (0x40U) // Transmit Complete Flag
#define S1_TC_offset   (6)
#define S1_TDRE        (0x80U) // Transmit Data Register Empty Flag
#define S1_TDRE_offset (7)

// S2 (UART Status Register 2)
#define S2_RAF            (0x01U) // Receiver Active Flag
#define S2_RAF_offset     (0)
#define S2_LBKDE          (0x02U) // LIN Break Detection Enable
#define S2_LBKDE_offset   (1)
#define S2_BRK13          (0x04U) // Break Transmit Character Length
#define S2_BRK13_offset   (2)
#define S2_RWUID          (0x08U) // Receive Wakeup Idle Detect
#define S2_RWUID_offset   (3)
#define S2_RXINV          (0x10U) // Receive Data Inversion
#define S2_RXINV_offset   (4)
#define S2_MSBF           (0x20U) // Most Significant Bit First
#define S2_MSBF_offset    (5)
#define S2_RXEDGIF        (0x40U) // RxD Pin Active Edge Interrupt Flag
#define S2_RXEDGIF_offset (6)
#define S2_LBKDIF         (0x80U) // LIN Break Detect Interrupt Flag
#define S2_LBKDIF_offset  (7)

// C3 (UART Control Register 3)
#define C3_PEIE         (0x01U) // Parity Error Interrupt Enable
#define C3_PEIE_offset  (0)
#define C3_FEIE         (0x02U) // Framing Error Interrupt Enable
#define C3_FEIE_offset  (1)
#define C3_NEIE         (0x04U) // Noise Error Interrupt Enable
#define C3_NEIE_offset  (2)
#define C3_ORIE         (0x08U) // Overrun Error Interrupt Enable
#define C3_ORIE_offset  (3)
#define C3_TXINV        (0x10U) // Transmit Data Inversion
#define C3_TXINV_offset (4)
#define C3_TXDIR        (0x20U) // Transmitter Pin Data Direction in Single-Wire mode
#define C3_TXDIR_offset (5)
#define C3_T8           (0x40U) // Transmit Bit 8
#define C3_T8_offset    (6)
#define C3_R8           (0x80U) // Received Bit 8
#define C3_R8_offset    (7)

// C4 (UART Control Register 4)
#define C4_BRFA_mask    (0x1FU) // Baud Rate Fine Adjust
#define C4_BRFA_width   (5)
#define C4_BRFA(n)      ((n) << C4_BRFA_offset)
#define C4_BRFA_get(n)  (((n) >> C4_BRFA_offset) & 0x1FU)
#define C4_BRFA_offset  (0)
#define C4_M10          (0x20U) // 10-bit Mode select
#define C4_M10_offset   (5)
#define C4_MAEN2        (0x40U) // Match Address Mode Enable 2
#define C4_MAEN2_offset (6)
#define C4_MAEN1        (0x80U) // Match Address Mode Enable 1
#define C4_MAEN1_offset (7)

// C5 (UART Control Register 5)
#define C5_RDMAS        (0x20U) // Receiver Full DMA Select
#define C5_RDMAS_offset (5)
#define C5_TDMAS        (0x80U) // Transmitter DMA Select
#define C5_TDMAS_offset (7)

// ED (UART Extended Data Register)
#define ED_PARITYE        (0x40U) // The current received dataword contained in D and C3[R8] was received with a parity error
#define ED_PARITYE_offset (6)
#define ED_NOISY          (0x80U) // The current received dataword contained in D and C3[R8] was received with noise
#define ED_NOISY_offset   (7)

// MODEM (UART Modem Register)
#define MODEM_TXCTSE          (0x01U) // Transmitter clear-to-send enable
#define MODEM_TXCTSE_offset   (0)
#define MODEM_TXRTSE          (0x02U) // Transmitter request-to-send enable
#define MODEM_TXRTSE_offset   (1)
#define MODEM_TXRTSPOL        (0x04U) // Transmitter request-to-send polarity
#define MODEM_TXRTSPOL_offset (2)
#define MODEM_RXRTSE          (0x08U) // Receiver request-to-send enable
#define MODEM_RXRTSE_offset   (3)

// IR (UART Infrared Register)
#define IR_TNP_mask    (0x03U) // Transmitter narrow pulse
#define IR_TNP_width   (2)
#define IR_TNP(n)      ((n) << IR_TNP_offset)
#define IR_TNP_get(n)  (((n) >> IR_TNP_offset) & 0x3U)
#define IR_TNP_offset  (0)
#define IR_IREN        (0x04U) // Infrared enable
#define IR_IREN_offset (2)

// PFIFO (UART FIFO Parameters)
#define PFIFO_RXFIFOSIZE_mask   (0x07U) // Receive FIFO. Buffer Depth
#define PFIFO_RXFIFOSIZE_width  (3)
#define PFIFO_RXFIFOSIZE(n)     ((n) << PFIFO_RXFIFOSIZE_offset)
#define PFIFO_RXFIFOSIZE_get(n) (((n) >> PFIFO_RXFIFOSIZE_offset) & 0x7U)
#define PFIFO_RXFIFOSIZE_offset (0)
#define PFIFO_RXFE              (0x08U) // Receive FIFO Enable
#define PFIFO_RXFE_offset       (3)
#define PFIFO_TXFIFOSIZE_mask   (0x70U) // Transmit FIFO. Buffer Depth
#define PFIFO_TXFIFOSIZE_width  (3)
#define PFIFO_TXFIFOSIZE(n)     ((n) << PFIFO_TXFIFOSIZE_offset)
#define PFIFO_TXFIFOSIZE_get(n) (((n) >> PFIFO_TXFIFOSIZE_offset) & 0x7U)
#define PFIFO_TXFIFOSIZE_offset (4)
#define PFIFO_TXFE              (0x80U) // Transmit FIFO Enable
#define PFIFO_TXFE_offset       (7)

// CFIFO (UART FIFO Control Register)
#define CFIFO_RXUFE          (0x01U) // Receive FIFO Underflow Interrupt Enable
#define CFIFO_RXUFE_offset   (0)
#define CFIFO_TXOFE          (0x02U) // Transmit FIFO Overflow Interrupt Enable
#define CFIFO_TXOFE_offset   (1)
#define CFIFO_RXOFE          (0x04U) // Receive FIFO Overflow Interrupt Enable
#define CFIFO_RXOFE_offset   (2)
#define CFIFO_RXFLUSH        (0x40U) // Receive FIFO/Buffer Flush
#define CFIFO_RXFLUSH_offset (6)
#define CFIFO_TXFLUSH        (0x80U) // Transmit FIFO/Buffer Flush
#define CFIFO_TXFLUSH_offset (7)

// SFIFO (UART FIFO Status Register)
#define SFIFO_RXUF          (0x01U) // Receiver Buffer Underflow Flag
#define SFIFO_RXUF_offset   (0)
#define SFIFO_TXOF          (0x02U) // Transmitter Buffer Overflow Flag
#define SFIFO_TXOF_offset   (1)
#define SFIFO_RXOF          (0x04U) // Receiver Buffer Overflow Flag
#define SFIFO_RXOF_offset   (2)
#define SFIFO_RXEMPT        (0x40U) // Receive Buffer/FIFO Empty
#define SFIFO_RXEMPT_offset (6)
#define SFIFO_TXEMPT        (0x80U) // Transmit Buffer/FIFO Empty
#define SFIFO_TXEMPT_offset (7)
