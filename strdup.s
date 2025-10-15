section .text   
    global ft_strdup
    extern malloc
    extern ft_strlen
ft_strdup:
    push rbp
    push rbx
    push rdi
    cld

    call ft_strlen wrt ..plt
    mov rdi, rax
    add rdi, 1
    mov rbx, rax
    call malloc wrt ..plt
    mov rcx, rbx
    mov rdi, rax
    pop rsi
    rep movsb
    mov [rdi], byte 0
    pop rbx
    pop rbp
    ret