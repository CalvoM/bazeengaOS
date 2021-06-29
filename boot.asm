[org 0x7c00] ; address in memory where BIOS loads the MBR
mov ah,0x00
int 0x13 ; reset the disk system and recalibrate the drive heads
jc disk_error 
mov [boot_drive],dl ;save driver number identified by bios
mov ax,0x7e0
mov ss,ax ; set the stack segment just after MBR
mov bp,0x8000
mov sp,bp ; set the stack to start at 0x8000
mov si,welcome
call print_msg ; print welcome message
mov bx,boot_two_addr
mov dh,0x01
xor ax,ax
mov dl,[boot_drive]
push bx
mov bx,0x04 ;minor delay
call init_wait
pop bx
call load_second_bootloader; loads the second bootloader code to memory
jmp boot_two_addr
%include "routines.asm"
boot_drive: db 0
boot_two_addr equ 0x9000 ; Address for the 2nd bootloader in memory
welcome db "Setting up OS"
times 510-($-$$) db 0
dw 0xaa55 ; make the last two bytes the MBR magic signature