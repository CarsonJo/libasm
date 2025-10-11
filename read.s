section .text
	global my_read
extern __errno_location
error:
	not rax
	add rax, 1
	mov rdx, rax
	call __errno_location wrt ..plt
	mov [rax], rdx
	mov rax, -1
	ret
my_read:
	push rbp
	mov rbp,rsp
	mov rax, 0
	syscall
	cmp rax, 0
	js error
	mov rsp, rbp
	pop rbp
	ret
