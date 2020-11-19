global _ft_strcpy
section .text

_ft_strcpy:   ;rax ft_strcpy(rdi, rsi)
	xor rcx, rcx
	mov rcx, 0

_ft_strcpy_loop:
	cmp [rsi + rcx], byte 0
	jz _ft_strcpy_null
	mov bl, [rsi + rcx]
	mov [rdi + rcx], bl
	inc rcx
	jmp _ft_strcpy_loop

_ft_strcpy_null:
	mov [rdi + rcx], byte 0
	mov rax, rdi
	ret
