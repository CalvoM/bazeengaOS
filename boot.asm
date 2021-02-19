use16
mov ax,0x7c0
mov ds,ax
add ax,0x20;Have the stack begin after bootloader
mov ss,ax
mov sp,0x8e00 ;4kb from start of ss
mov ax, 13h
int 10h
call set_screen_size
call clear_screen
mov si,welcome
call print_msg
call load_second_bootloader
jmp 0x9000
cli
hlt
%include "routines.asm"
welcome db "Getting the OS...",0
times 510-($-$$) db 0
dw 0xaa55
