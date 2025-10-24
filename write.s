extern __errno_location
section .text
	global ft_write
positive:
	not rax
	add rax, 1; transform the error code into a positive number
	mov rdx, rax
	call __errno_location wrt ..plt
	mov [rax], rdx
	mov rax, -1
	ret
ft_write:
	push rbp
	mov rax, 1
	syscall ; call write syscall number 1
	cmp rax, 0
	pop rbp
	js positive ; si erreur transforme en positive pour l'ecrire dans errno
	ret
