[org 0x9000]
Boot2:
    mov [boot_drive],cl
    call set_screen_size
    mov si, os_msg
    call print_msg
    call load_kernel
    call switch_to_pm

%include "routines.asm"
%include "switch_to_pm.asm"
use16
load_kernel:
    mov si,kern_msg
    call print_msg
    mov bx,0x1000
    mov dh,1
    mov cl,3;sector to load
    mov dl,[boot_drive]
    call cls
    call load_to_memory
    ret
boot_drive: db 0
kern_offset equ 0x1000
os_msg db 0x0a,0x0d,"This is Bazzenga Os",0
kern_msg db 0x0a,0x0d,"Loading the kernel...",0
times ((0x200) - ($ - $$)) db 0x00