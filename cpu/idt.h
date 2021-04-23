#ifndef IDT_H_
#define IDT_H_
#include "types.h"
#define MAX_IDT_ENTRIES 256
typedef struct{
	u16 offset_low;//Low 16 bits of address offset
	u16 selector;
	u8 null_byte;//Always a byte of zero
	u8 flags;
	//0-3rd bit -> GateType, eg. for interrupts 0x1110
	//4th bit -> Storage, 0 for interrupts and trap gates
	//5-6th bit ->DPL(Descriptor Priviledge Level) 
	//7th bit -> Present? 1- Present 0-Absent
	u16 offset_high;//High 16 bits of address offset
}__attribute__((packed)) idt_entry_t;

typedef struct{
	u16 limit;// IDT length in bytes -1
	u32 base;// where IDT starts
}__attribute__((packed)) idtr_ptr_t;

idt_entry_t idt[MAX_IDT_ENTRIES];
idtr_ptr_t idt_reg;

void set_idt_entry(int n, u32 handler);
void set_idt();
#endif
