use16
mov ax,0x7c0
mov ds,ax
add ax,0x20;Have the stack begin after bootloader
mov ss,ax
mov sp,0x8e00 ;4kb from start of ss
call set_screen_size
;call set_cursor_center
mov si,welcome
call print_msg
cli
hlt
%include "routines.asm"
welcome db "Welcome to BazeengaOS",0
times 510-($-$$) db 0
dw 0xaa55
