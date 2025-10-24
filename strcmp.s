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
    mov al, [rsi] ; for checking end string
    ;cmpsb ;normal
    ;jg lesser ;normal
    ;jl greater ;normal

    cmp byte [rdi], byte al ;valgrind compliant
	jg greater ;valgrind
    jl lesser ; valgrind
    add rdi, 1 ;valgrind compliant
    add rsi, 1 ;valgrind compliant


    cmp al, 0 ;if end of string stop else continue
    jne cmp_loop
    ret
