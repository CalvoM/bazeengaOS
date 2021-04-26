#include "../drivers/screen.h"
#include "../cpu/isr.h"
#include "../cpu/timer.h"
void dummy(){

}
void main(){
	clear_screen();
	isr_setup();
	__asm__("sti");
	init_timer(50);
}
