[extern isr_handler]

isr_call_procedure:
;Before calling the isr handler we save the state on the stack
	pusha
	mov ax,ds
	push eax
	mov ax,0x10 ;Data segment addr from GDT setup
	mov ds,ax
	mov es,ax
	mov fs,ax
	mov gs,ax
;Call the ISR handler
	call isr_handler
;After calling the isr handler, restore the state of interrupt procedure
	pop eax
	mov ds,ax
	mov es,ax
	mov fs,ax
	mov gs,ax
	popa
	add esp, 8 ; //deal with error code and ISR number
	sti
	iret; Remove the internally saved states of CS,EIP,EFLAGS,SS,ESP

global isr0
global isr1
global isr2
global isr3
global isr4
global isr5
global isr6
global isr7
global isr8
global isr9
global isr10
global isr11
global isr12
global isr13
global isr14
global isr15
global isr16
global isr17
global isr18
global isr19
global isr20
global isr21
global isr22
global isr23
global isr24
global isr25
global isr26
global isr27
global isr28
global isr29
global isr30
global isr31

; 0: Divide By Zero Exception
isr0:
    cli
    push byte 0
    push byte 0
    jmp isr_call_procedure

; 1: Debug Exception
isr1:
    cli
    push byte 0
    push byte 1
    jmp isr_call_procedure

; 2: Non Maskable Interrupt Exception
isr2:
    cli
    push byte 0
    push byte 2
    jmp isr_call_procedure

; 3: Int 3 Exception
isr3:
    cli
    push byte 0
    push byte 3
    jmp isr_call_procedure

; 4: INTO Exception
isr4:
    cli
    push byte 0
    push byte 4
    jmp isr_call_procedure

; 5: Out of Bounds Exception
isr5:
    cli
    push byte 0
    push byte 5
    jmp isr_call_procedure

; 6: Invalid Opcode Exception
isr6:
    cli
    push byte 0
    push byte 6
    jmp isr_call_procedure

; 7: Coprocessor Not Available Exception
isr7:
    cli
    push byte 0
    push byte 7
    jmp isr_call_procedure

; 8: Double Fault Exception (With Error Code!)
isr8:
    cli
    push byte 8
    jmp isr_call_procedure

; 9: Coprocessor Segment Overrun Exception
isr9:
    cli
    push byte 0
    push byte 9
    jmp isr_call_procedure

; 10: Bad TSS Exception (With Error Code!)
isr10:
    cli
    push byte 10
    jmp isr_call_procedure

; 11: Segment Not Present Exception (With Error Code!)
isr11:
    cli
    push byte 11
    jmp isr_call_procedure

; 12: Stack Fault Exception (With Error Code!)
isr12:
    cli
    push byte 12
    jmp isr_call_procedure

; 13: General Protection Fault Exception (With Error Code!)
isr13:
    cli
    push byte 13
    jmp isr_call_procedure

; 14: Page Fault Exception (With Error Code!)
isr14:
    cli
    push byte 14
    jmp isr_call_procedure

; 15: Reserved Exception
isr15:
    cli
    push byte 0
    push byte 15
    jmp isr_call_procedure

; 16: Floating Point Exception
isr16:
    cli
    push byte 0
    push byte 16
    jmp isr_call_procedure

; 17: Alignment Check Exception
isr17:
    cli
    push byte 0
    push byte 17
    jmp isr_call_procedure

; 18: Machine Check Exception
isr18:
    cli
    push byte 0
    push byte 18
    jmp isr_call_procedure

; 19: Reserved
isr19:
    cli
    push byte 0
    push byte 19
    jmp isr_call_procedure

; 20: Reserved
isr20:
    cli
    push byte 0
    push byte 20
    jmp isr_call_procedure

; 21: Reserved
isr21:
    cli
    push byte 0
    push byte 21
    jmp isr_call_procedure

; 22: Reserved
isr22:
    cli
    push byte 0
    push byte 22
    jmp isr_call_procedure

; 23: Reserved
isr23:
    cli
    push byte 0
    push byte 23
    jmp isr_call_procedure

; 24: Reserved
isr24:
    cli
    push byte 0
    push byte 24
    jmp isr_call_procedure

; 25: Reserved
isr25:
    cli
    push byte 0
    push byte 25
    jmp isr_call_procedure

; 26: Reserved
isr26:
    cli
    push byte 0
    push byte 26
    jmp isr_call_procedure

; 27: Reserved
isr27:
    cli
    push byte 0
    push byte 27
    jmp isr_call_procedure

; 28: Reserved
isr28:
    cli
    push byte 0
    push byte 28
    jmp isr_call_procedure

; 29: Reserved
isr29:
    cli
    push byte 0
    push byte 29
    jmp isr_call_procedure

; 30: Reserved
isr30:
    cli
    push byte 0
    push byte 30
    jmp isr_call_procedure

; 31: Reserved
isr31:
    cli
    push byte 0
    push byte 31
    jmp isr_call_procedure
