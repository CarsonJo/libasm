section .text
    global ft_strcmp

greater:
    mov rax, 1
    ret
lesser:
    mov rax, -1
    ret
ft_strcmp:
    cld
    xor rax, rax
cmp_loop:
    mov al, [rsi]
    ;cmpsb ;normal
    cmp byte [rdi], byte al ;valgrind compliant
    jg greater
    jl lesser
    add rdi, 1 ;valgrind compliant
    add rsi, 1 ;valgrind compliant
    cmp al, 0
    jne cmp_loop
    ret
    