set_screen_size:
    mov ah,0x00
    mov al, 0x03
    int 0x10
    ret
clear_screen:
    mov ah,0x07
    mov al,0x00
    mov bh,0xe0 
    mov dh,30
    mov dl,79
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
    mov cx,0x1e
    mov dx,0x8480
    mov ah,0x86
    int 0x15
    popa
    ret
load_second_bootloader:
    pusha
   	mov ah, 0x02
	mov al, dh
	mov ch, 0x00
	mov dh, 0x00
	mov cl, 0x02
    mov dl,0x80
    ;mov bx,0x9000
	int 0x13
    popa
    ret