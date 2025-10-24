section .text
    global ft_strcpy

ft_strcpy:
    cld
	push rdi
copy_loop:
    lodsb; load in al from [rsi]
    stosb; store al to [rdi]
    cmp al, 0
    jnz copy_loop
    sub rdi, 1
    pop rax
    ret

