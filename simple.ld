/**
 * Standard in-flash layout with fixed memory areas. Note that ld also contains
 * existing built-in rules that will be added to this one.
 */

OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(Reset_Handler)

MEMORY {
  VECTORS (r): ORIGIN = 0x00000000, LENGTH = 0x400 
  /* TODO: Not sure whether this will work though. We need more code to
     test whether leaking from the front will work or not */
  FLASHCONFIG (r): ORIGIN = 0x0400, LENGTH = 16
  FLASH (rx) : ORIGIN = 0x00000410, LENGTH = 0xFBF0
  SRAM (rwx) : ORIGIN = 0x20000000, LENGTH = 0x2000
}

SECTIONS {
  vectors : {
    /* First place the interrupt vectors from the crt0 (if any). On cortex
       this contains the cortex common table and the SP setup */
    KEEP(crt0.o (vectors));
    /* Then place the secondary source for vectors if any (so that they
       come after the primary vectors). On cortex this is chip specific.
       This is still untested */
    KEEP(* (vectors));
  } > VECTORS

  flash_config : {
    KEEP(*(flash_config))
  } > FLASHCONFIG

  .rodata : {
    * (.rodata .rodata.*);
  } > FLASH

  .text : {
    /* Select .text sections from all objects (*). Support per-func sections */
    * (.text .text.*);
    /* Make symbol that will contain the address of this location at end */
    __text_end = .;
  } > FLASH

  .data : {
    __data_start = .;
    * (.data .data.*);
    __data_end = .;
  } > SRAM AT> FLASH

  /**
   * Will be copied by the startup into proper place when the sdata/edata are
   * known. Source of copy is text_end, destination is data_start. count is
   * __data_end-__data_start
   */
  .bss : {
    __bss_start = .;
    * (.bss .bss.*);
    __bss_end = .;
  }

  /**
   * TODO: Make main stack reservation to guard against over-commit
   */
}
