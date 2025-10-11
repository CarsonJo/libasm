section .data
	msg db "test %d",0
section .text
	global my_strlen
my_strlen:
	mov r8, rax ;copy the pointer pass as arg
	mov rax, 4  ; code syscall write
	mov rbx, 1	;
	mov rcx, r8	;
	mov rdx, 8	;write 8 char de l'argument
	int 0x80 ; appelle du kernel pour execution syscall

	mov rdi, r8
	mov rax, 0
	mov rcx, 0xffffffffffffffff
	mov al, 0
	repne scasb
	mov rax, 0xffffffffffffffff
	sub rax, rcx
	sub rax, 1
	ret
