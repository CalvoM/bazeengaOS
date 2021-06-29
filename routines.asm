set_screen_size:
    mov ah,0x00
    mov al, 0x03
    int 0x10
    ret
clear_screen:
    mov ah,0x07
    mov al,0x00
    mov bh,0x0e 
    mov dh,30
    mov dl,80
    int 0x10
    ret
set_cursor_center:
    mov ah,0x02
    mov bh,0x00
    mov dh,0
    mov dl, 0
    int 0x10
    ret
print_msg:
    lodsb
    or al,al
    jz done
    mov ah,0x0e
    int 0x10
    jmp print_msg
done:
    ret
init_wait:
    pusha
loop_time:
    mov cx,0x0f
    mov dx,0x4240
    mov ah,0x86
    int 0x15
    dec bx
    cmp bx,0x00
    jnz loop_time
    popa
    ret
load_second_bootloader:
    push dx
   	mov ah, 0x02
	mov al, dh ;number of sector to read
	mov ch, 0x00;cylinder no.
	mov dh, 0x00;head number
	mov cl, 0x02;sector no. since the 1st sector contains MBR
	int 0x13
    jc disk_error
    pop dx
    cmp dh,al
    jne disk_error_header
    ret
print_hex:
    mov bx,dx
    and bx,0x000f
    cmp bl,0x09
    jg print_letter
    add bx,0x30
    mov ah,0x0e
    mov al,bl
    int 0x10
    shr dx,4
    rol dx,8
    and dx,dx
    jnz print_hex
    ret
print_letter:
    sub bl,0x09
    dec bl
    add bl,0x61
    mov ah,0x0e
    mov al,bl
    int 0x10
    shr dx,4
    rol dx,8
    and dx,dx
    jnz print_hex
    ret

disk_error:
    mov si,dsk_err_msg
    call print_msg
    jmp $
disk_error_header:
    mov si,dsk_err_head_msg
    call print_msg
    jmp $


dsk_err_msg db "[DISK] Loading error",0
dsk_err_head_msg db "Header loading error",0
buf dw 0x0031
sec dd 0x000f4240