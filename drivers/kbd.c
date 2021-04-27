#include "kbd.h"
// The various scancode ascii
#define SCAN_MAX 0x39
#define BACKSPACE 0x0E
#define ENTER 0x1C

static char content_buffer[256];
const char sc_ascii[] = { '?', '?', '1', '2', '3', '4', '5', '6',     
    '7', '8', '9', '0', '-', '=', '?', '?', 'Q', 'W', 'E', 'R', 'T', 'Y', 
        'U', 'I', 'O', 'P', '[', ']', '?', '?', 'A', 'S', 'D', 'F', 'G', 
        'H', 'J', 'K', 'L', ';', '\'', '`', '?', '\\', 'Z', 'X', 'C', 'V', 
        'B', 'N', 'M', ',', '.', '/', '?', '?', '?', ' '};
static void kbd_cb(registers_t r){
    u8 scancode = port_byte_in(0x60);
    if(scancode > SCAN_MAX) return;
    if(scancode == BACKSPACE){
        handle_backspace(content_buffer);
        kmonitor_backspace();
    }else if(scancode == ENTER){
        kmonitor("\n");
        parse_user_input(content_buffer);
        content_buffer[0] = '\0';
    }else{
        char letter = sc_ascii[(int)scancode];
        char str[2] = {letter, '\0'};
        append(content_buffer,letter);
        kmonitor(str);
    }
}

void init_kbd(){
    register_interrupt_handler(KBD_IRQ,kbd_cb);
}

void append(char buf[], char letter){
    int len = strlen(buf);
    buf[len] = letter;
    buf[len+1] = '\0';
}
void handle_backspace(char buf[]){
    int len = strlen(buf);
    buf[len - 1] = '\0';
}