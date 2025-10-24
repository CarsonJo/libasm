section .text
	global ft_strlen
ft_strlen:
	cld ; clear direction flag to increment rdi
	xor al, al
	mov rdx, rdi
	mov rcx, 0xffffffffffffffff ;max value for repnz
	repnz scasb
	sub rdi, rdx
	sub rdi, 1
	mov rax, rdi
	ret
