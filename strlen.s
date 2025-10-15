section .text
	global ft_strlen
ft_strlen:
	xor al, al
	mov rdx, rdi
	mov rcx, 0xffffffffffffffff
	repnz scasb
	sub rdi, rdx
	sub rdi, 1
	mov rax, rdi
	ret
