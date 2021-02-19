org 0x9000
use16
call set_screen_size
; mov ah,0x07
; mov al,0x00
; mov bh,0xef 
; mov dh,30
; mov dl,79
; int 0x10
mov si, os_msg
call print_msg
%include "routines.asm"
os_msg db "Bazzenga Os"
times ((0x200) - ($ - $$)) db 0x00