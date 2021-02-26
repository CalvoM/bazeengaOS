use32

video_mem equ 0xb8000
white_on_black equ 0x0e

print_string_pm:
    pusha
    mov edx,video_mem
print_string_pm_lp:
    mov al,[ebx]
    mov ah,white_on_black
    cmp al,0
    je print_string_pm_done
    mov [edx],ax
    add ebx,1
    add edx,2
    jmp print_string_pm_lp
print_string_pm_done:
    popa
    ret