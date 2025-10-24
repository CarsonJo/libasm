section .text
    global ft_strdup
    extern malloc
    extern ft_strlen
ft_strdup:
    push rdi;save variable
    call ft_strlen wrt ..plt
    mov rdi, rax
    add rdi, 1
    push rax ;save return from strlen
	push rbp
    call malloc wrt ..plt
	pop rbp
	pop rcx ;set up loop termination from strlen
    pop rsi

    cld
    mov rdi, rax ;dest string
    rep movsb
    mov [rdi], byte 0
    ret
