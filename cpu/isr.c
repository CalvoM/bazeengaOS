#include "isr.h"
#include "../drivers/screen.h"
#include "idt.h"
#include "pic.h"

void isr_setup() {
  PIC_remap(ISR_IRQ0, ISR_IRQ0 + 8);
  set_idt_entry(ISR_IRQ0, (u32)isr0);
  set_idt_entry(ISR_IRQ0 + IRQ_KEYBOARD, (u32)isr1);
  set_idt_entry(ISR_IRQ0 + 2, (u32)isr2);
  set_idt_entry(ISR_IRQ0 + 3, (u32)isr3);
  set_idt_entry(ISR_IRQ0 + 4, (u32)isr4);
  set_idt_entry(ISR_IRQ0 + 5, (u32)isr5);
  set_idt_entry(ISR_IRQ0 + 6, (u32)isr6);
  set_idt_entry(ISR_IRQ0 + 7, (u32)isr7);
  set_idt_entry(ISR_IRQ0 + 8, (u32)isr8);
  set_idt_entry(ISR_IRQ0 + 9, (u32)isr9);
  set_idt_entry(ISR_IRQ0 + 10, (u32)isr10);
  set_idt_entry(ISR_IRQ0 + 11, (u32)isr11);
  set_idt_entry(ISR_IRQ0 + 12, (u32)isr12);
  set_idt_entry(ISR_IRQ0 + 13, (u32)isr13);
  set_idt_entry(ISR_IRQ0 + 14, (u32)isr14);
  set_idt_entry(ISR_IRQ0 + 15, (u32)isr15);
  set_idt();
  fault_init();
}

void isr_handler(registers_t r) {
  if (r.interrupt_no < ISR_IRQ0 || r.interrupt_no == 255) {
    kmonitor("Encountered a fault: ");
    kmonitor("\n\r");
    fault_handler(r);
  } else if (r.interrupt_no < ISR_IRQ0 + ISR_NUM) {
    kmonitor("RECEIVED INTERRUPT: ");
    kmonitor("\n\r");
  } else {
    kmonitor("RECEIVED: ");
    kmonitor("\n\r");
  }
  // syscall
}
