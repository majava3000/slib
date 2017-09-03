#pragma once

#include <stdint.h>

struct GPIORegisters {
  volatile uint32_t PDOR;	// Port Data Output Register [0]
  volatile uint32_t PSOR;	// Port Set Output Register [4]
  volatile uint32_t PCOR;	// Port Clear Output Register [8]
  volatile uint32_t PTOR;	// Port Toggle Output Register [c]
  volatile uint32_t PDIR;	// Port Data Input Register [10]
  volatile uint32_t PDDR;	// Port Data Direction Register [14]
};
