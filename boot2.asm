[org 0x9000]
Boot2:
    call set_screen_size
    mov si, os_msg
    call print_msg
    call switch_to_pm
%include "routines.asm"
%include "gdt_def.asm"
%include "print_string_pm.asm"
%include "switch_to_pm.asm"
os_msg db 0x0a,0x0d,"This is Bazzenga Os",0
os_prot_msg db "We are safe and secure!",0
times ((0x200) - ($ - $$)) db 0x00