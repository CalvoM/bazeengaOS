use16
switch_to_pm:
    cli
    lgdt[gdt_descriptor]
    mov eax,cr0
    or eax,0x01
    mov cr0,eax
    jmp code_seg:pm_init

use32
pm_init:
    mov ax, data_seg
    mov ds,ax
    mov ss,ax
    mov es,ax
    mov fs,ax
    mov gs,ax
    mov ebp,0x90000
    mov esp,ebp

    call begin_pm

begin_pm:
    mov ebx, os_prot_msg
    call print_string_pm
    jmp kern_offset
    jmp $

%include "gdt_def.asm"
%include "print_string_pm.asm"
os_prot_msg db "We are safe and secure!",0
kern_offset equ 0x1000
