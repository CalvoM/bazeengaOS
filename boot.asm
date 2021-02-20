[org 0x7c00]
mov ah,0x00
int 0x13
jc disk_error
mov [boot_drive],dl ;save driver number identified by bios
mov ax,0x7e0
mov ss,ax
mov bp,0x8000
mov sp,bp
mov bx,boot_two_addr
mov dh,0x01
xor ax,ax
mov dl,[boot_drive]
push bx
mov bx,0x02 ;minor delay
call init_wait
pop bx
call load_second_bootloader
jmp boot_two_addr
%include "routines.asm"
boot_drive: db 0
boot_two_addr equ 0x9000
times 510-($-$$) db 0
dw 0xaa55
times 512 db 0x00
