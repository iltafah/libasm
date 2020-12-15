global _ft_strcmp
section .text

_ft_strcmp: 			;rax ft_strcmp(rdi, rsi)
	cmp [rdi], byte 0
	jz _ft_strcmp_null
	mov al, [rdi]
	cmp al, [rsi]
	jnz _ft_strcmp_null
	inc rdi
	inc rsi
	jmp _ft_strcmp

_ft_strcmp_null:
	mov al, [rdi]
	sub al, [rsi]
	movsx rax, al
	ret
