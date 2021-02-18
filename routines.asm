set_screen_size:
    mov ah,0x00
    mov al, 0x03
    int 0x10
    ret
clear_screen:
    mov ah,0x07
    mov al,0x00
    mov bh,0x0f 
    mov dh,30
    mov dl,79
    int 0x10
    ret
set_cursor_center:
    mov ah,0x02
    mov dh,14
    mov dl, 30
    int 0x10
    rett
print_msg:
    lodsb
    or al,al
    jz done
    mov ah,0x0e
    mov cl,0x5
    int 0x10
    jmp print_msg
done:
    ret