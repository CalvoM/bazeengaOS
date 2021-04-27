#include "../drivers/screen.h"
#include "../cpu/isr.h"
#include "../cpu/timer.h"
#include "../drivers/kbd.h"
void dummy(){

}
void main(){
	clear_screen();
	isr_setup();
	__asm__("sti");
	init_kbd();
	init_timer(50);
}
