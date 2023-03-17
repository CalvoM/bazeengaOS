gdt_start:
gdt_null:
    dd 0x0
    dd 0x0
gdt_code:;code segment descriptor
    dw 0xffff ;Limit
    dw 0x0 ;Base Address
    db 0x0 ;Base Address
    db 10011010b ;P[1]-DPL[2]-S[1]-Type[4] P->Present DPL-Privilege 
    db 11001111b ;G[1]-DB[1]-0-0-Limit[4] With granularity 1 means (0xfffff)*(4*1024);4gb
    db 0x0

gdt_data:;data segment descriptor
    dw 0xffff
    dw 0x0
    db 0x0
    db 10010010b
    db 11001111b
    db 0x0
gdt_end:

gdt_descriptor:
    dw gdt_end - gdt_start - 1 ;size
    dd gdt_start ;offset

code_seg equ gdt_code - gdt_start
data_seg equ gdt_data - gdt_start
