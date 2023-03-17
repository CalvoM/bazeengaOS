#include "idt.h"
#include "types.h"

void set_idt_entry(int n, u32 handler){
	idt[n].offset_low = low_16(handler);
	idt[n].selector =CODE_SEG;
	idt[n].null_byte = 0;
	idt[n].flags = 0b10001110;
	idt[n].offset_high = high_16(handler);
}

void set_idt(){
	idt_reg.base = (u32) &idt;
	idt_reg.limit = MAX_IDT_ENTRIES * sizeof(idt_entry_t) -1;
	__asm__ __volatile__("lidtl (%0)" : : "r" (&idt_reg));
}
