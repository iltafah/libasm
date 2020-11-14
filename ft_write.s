global _ft_write:
section .text
extern ___error

_ft_write:
	mov rax, 0x2000004 ; write
	syscall
	jc  _ft_write_error
	ret

_ft_write_error:
	push rax
	call ___error
	pop  rcx
	mov  [rax], rcx
	mov  rax, -1
	ret