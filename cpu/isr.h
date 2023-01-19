#ifndef ISR_H_
#define ISR_H_

#include "types.h"

#define ISR_IRQ0 0X20    // irq remmapped start
#define ISR_NUM 0x10     // number of irqs registered
#define ISR_SYSCALL 0x80 // syscall irq

#define IRQ_TIMER 0
#define IRQ_KEYBOARD 1

// Reserved CPU exceptions
extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();

// Contains the registers saved on stack during interrupt call.
// The fields are in reverse order of pushing
typedef struct {
  u32 ds;
  u32 edi, esi, ebp, esp, ebx, edx, ecx, eax;
  u32 interrupt_no, err_code;
  u32 eip, cs, eflags, curr_sp, ss; // automatically saves internally by CPU
} registers_t;

void isr_setup();
void isr_handler(registers_t r);
void fault_handler(registers_t r);
void fault_init();
#endif
