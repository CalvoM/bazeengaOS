#include "../drivers/screen.h"
#include "idt.h"
#include "isr.h"
#include "types.h"

extern void fault0();
extern void fault1();
extern void fault2();
extern void fault3();
extern void fault4();
extern void fault5();
extern void fault6();
extern void fault7();
extern void fault8();
extern void fault9();
extern void fault10();
extern void fault11();
extern void fault12();
extern void fault13();
extern void fault14();
extern void fault15();
extern void fault16();
extern void fault17();
extern void fault18();
extern void fault19();
extern void fault20();
extern void fault21();
extern void fault22();
extern void fault23();
extern void fault24();
extern void fault25();
extern void fault26();
extern void fault27();
extern void fault28();
extern void fault29();
extern void fault30();
extern void fault31();

char *exception_messages[] = {"Division By Zero",
                              "Debug",
                              "Non Maskable Interrupt",
                              "Breakpoint",
                              "Into Detected Overflow",
                              "Out of Bounds",
                              "Invalid Opcode",
                              "No Coprocessor",
                              "Double Fault",
                              "Coprocessor Segment Overrun",
                              "Bad TSS",
                              "Segment Not Present",
                              "Stack Fault",
                              "General Protection Fault",
                              "Page Fault",
                              "Unknown Interrupt",
                              "Coprocessor Fault",
                              "Alignment Check",
                              "Machine Check",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved",
                              "Reserved"};

void fault_init() {
  set_idt_entry(0, (u32)fault0);
  set_idt_entry(1, (u32)fault1);
  set_idt_entry(2, (u32)fault2);
  set_idt_entry(3, (u32)fault3);
  set_idt_entry(4, (u32)fault4);
  set_idt_entry(5, (u32)fault5);
  set_idt_entry(6, (u32)fault6);
  set_idt_entry(7, (u32)fault7);
  set_idt_entry(8, (u32)fault8);
  set_idt_entry(9, (u32)fault9);
  set_idt_entry(10, (u32)fault10);
  set_idt_entry(11, (u32)fault11);
  set_idt_entry(12, (u32)fault12);
  set_idt_entry(13, (u32)fault13);
  set_idt_entry(14, (u32)fault14);
  set_idt_entry(15, (u32)fault15);
  set_idt_entry(16, (u32)fault16);
  set_idt_entry(17, (u32)fault17);
  set_idt_entry(18, (u32)fault18);
  set_idt_entry(19, (u32)fault19);
  set_idt_entry(20, (u32)fault20);
  set_idt_entry(21, (u32)fault21);
  set_idt_entry(22, (u32)fault22);
  set_idt_entry(23, (u32)fault23);
  set_idt_entry(24, (u32)fault24);
  set_idt_entry(25, (u32)fault25);
  set_idt_entry(26, (u32)fault26);
  set_idt_entry(27, (u32)fault27);
  set_idt_entry(28, (u32)fault28);
  set_idt_entry(29, (u32)fault29);
  set_idt_entry(30, (u32)fault30);
  set_idt_entry(31, (u32)fault31);
}

static void page_fault() {
  u32 cr2;
  __asm__ __volatile__("mov %%cr2, %0" : "=r"(cr2));
  kmonitor("Ran into page fault");
}
void fault_handler(registers_t r) {
  if (r.interrupt_no == 0xe) {
    page_fault();
  }
  kmonitor(exception_messages[r.interrupt_no]);
  kmonitor("\n\r");
}
