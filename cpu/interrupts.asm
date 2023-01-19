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

%macro m_isr 1
[global isr%1]
isr%1:
    cli
    push 0
    push %1+0x20
    jmp isr_call_procedure
%endmacro

%assign i 0
%rep 0x10
    m_isr i
%assign i i+1
%endrep

%macro m_fault 1
[global fault%1]
fault%1:
	cli
	push %1
	jmp isr_call_procedure
%endmacro

%assign i 0
%rep 0x20
    m_fault i
    %assign i i + 1
%endrep
