global  _ft_list_push_front
section .text
extern  _malloc

_ft_list_push_front:     ;rax    ft_list_push_front(rdi, rsi)
    push    r12
    push    rdi
    push    rsi

    mov     rdi, 16
    call    _malloc

    pop     rsi
    mov     [rax], rsi
    pop     rdi
    mov     r12, [rdi]
    mov     [rax + 8], r12
    mov     [rdi], rax
    pop     r12

    mov     rax, 0
    ret