#include "pic.h"
#include "../drivers/low_level.h"

void PIC_sendEOI(u8 irq) {
  if (irq >= 8)
    port_byte_out(PIC2_CMD, PIC_EOI);
  port_byte_out(PIC1_CMD, PIC_EOI);
}

void PIC_init() {
  // send ICW1
  port_byte_out(PIC1_CMD, ICW1_INIT | ICW1_ICW4);
  port_byte_out(PIC2_CMD, ICW1_INIT | ICW1_ICW4);
  // send ICW2
  port_byte_out(PIC1_DATA, 0x20);
  port_byte_out(PIC2_DATA, 0x28);
}

void PIC_clear_mask() {
  port_byte_out(PIC1_DATA, 0x0);
  port_byte_out(PIC2_DATA, 0x0);
}
void PIC_remap(int offset, int offset2) {
  // Initialize PIC
  PIC_init();
  // ICW3
  port_byte_out(PIC1_DATA, offset);
  port_byte_out(PIC2_DATA, offset2);
  PIC_clear_mask();
}
