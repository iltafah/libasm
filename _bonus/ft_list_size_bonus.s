global  _ft_list_size
section .text

_ft_list_size:      ;rax    ft_lstsize_bonus(rdi)
    push    r12
    xor     r12, r12
    cmp     rdi, 0
    jz      exit

ft_loop:
    inc     r12
    mov     r8, [rdi + 8]
    cmp     r8, 0
    jz      exit
    mov     rdi, [rdi + 8]
    jmp     ft_loop

exit:
    mov     rax, r12
    pop     r12
    ret