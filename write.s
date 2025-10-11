extern __errno_location
section .text
	global my_write
positive:
	not rax
	add rax, 1; transform the error code into a positive number
	mov rdx, rax
	call __errno_location wrt ..plt
	mov [rax], rdx
	mov rax, -1
	ret
my_write:
	push rbp
	mov ebp, esp
	mov rax, 1
	syscall ; call write syscall number 1
	cmp rax, 0
	js positive ; si erreur transforme en positive pour l'ecrire dans errno
	mov esp, ebp
	pop ebp
	ret
