[org 0x9000]
Boot2:
    call set_screen_size
    call clear_screen
    mov si, os_msg
    call print_msg
    jmp $
%include "routines.asm"
os_msg db 0x0a,0x0d,"This is Bazzenga Os",0
times ((0x200) - ($ - $$)) db 0x00