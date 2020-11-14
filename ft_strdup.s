global _ft_strdup
section .text
extern _ft_strlen
extern _ft_strcpy
extern _malloc

_ft_strdup:         ;rax ft_strdup(rdi)
	cmp	 rdi, 0
	jz	 _ft_strdup_null
	push rdi
	call _ft_strlen ; (rdi) is passed to (rdi) of ft_strlen(rdi) and it will be stored in (rax)
	mov rdi, rax	; number of bytes we need to pass it to malloc
	add rdi, 1
	call _malloc
	mov rdi, rax
	pop rsi
	call _ft_strcpy
	ret

_ft_strdup_null:
	mov  rax, 0
	ret
