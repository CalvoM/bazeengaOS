#include "kbd.h"
#include "low_level.h"
#include "screen.h"
#include "../kernel/util.h"
#include "../cpu/isr.h"

static void kbd_cb(registers_t r){
    u8 scancode = port_byte_in(0x60);
    char buf[6] = {0};
    stringify(scancode,buf); 
    kmonitor(buf);
    kbd_print(scancode);
    kmonitor("\n");
}

void init_kbd(){
    register_interrupt_handler(KBD_IRQ,kbd_cb);
}

void kbd_print(u8 scancode){
    switch(scancode){
        case 0x0:
            kmonitor("ERROR");
            break;
        case 0xff:
            kmonitor("ERROR");
            break;
        case 0x1:
            kmonitor("ESC");
            break;
        
    }
}