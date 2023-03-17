#include "../drivers/screen.h"
#include "../cpu/idt.h"
#include "../cpu/isr.h"
void dummy(){

}
void main(){
	clear_screen();
	isr_setup();
	__asm__ __volatile__("int $2");
	__asm__ __volatile__("int $3");
}
