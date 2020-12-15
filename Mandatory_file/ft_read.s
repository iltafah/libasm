global _ft_read:
section .text
extern ___error

_ft_read:
	mov rax, 0x2000003
	syscall
	jc	_ft_read_error
	ret
	
_ft_read_error:
	push rax
	call ___error
	pop rcx
	mov [rax], rcx
	mov rax, -1
	ret