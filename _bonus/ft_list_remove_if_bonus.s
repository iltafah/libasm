global _ft_list_remove_if
section .text
extern _free

_ft_list_remove_if:     ;rax	ft_list_remove_if(rdi, rsi, rdx)
    push    r12         ;curr
    push    r13         ;next
    push    r14         ;prev
    cmp     rdi, 0
    jz      _exit_ft_list_remove_if
    mov     r12, [rdi]  ;curr = *begin_list
    mov     r13, 0
    push    rdi         ;&curr == **begin_list
    push    rsi         ;data_ref
    push    rdx         ;cmp
    push    rcx         ;next
    call    _remove_it_from_start
    pop     rcx
    pop     rdx
    pop     rsi
    pop     rdi
    mov     [rdi], r12
    cmp     r12, 0      ;check if (curr != NULL ===> [rdi] != NULL)
    jz      _exit_ft_list_remove_if
    mov     r14, r12
    mov     r12, [r14 + 8]
_ft_list_remove_if_loop:
    mov     r13, [r12 + 8]
    push    rdi
    push    rsi
    push    rdx
    push    rcx
    mov     rdi, [r12]
    call    rdx
    pop     rcx
    pop     rdx
    pop     rsi
    pop     rdi
    cmp     rax, 0
    jnz     _else
_call_free_it:
    push    rdi
    push    rsi
    push    rdx
    push    rcx
    call    _free_it
    pop     rcx
    pop     rdx
    pop     rsi
    pop     rdi
    jmp     _ft_list_remove_if_loop_1
_else:
    mov     r14, r12
    mov     r12, [r14 + 8]
_ft_list_remove_if_loop_1:
    cmp     r12,0
    jnz     _ft_list_remove_if_loop
_exit_ft_list_remove_if:
    pop     r14
    pop     r13
    pop     r12
    mov     rax, 0
    ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
_remove_it_from_start:
_remove_it_from_start_loop:
    cmp     r12, 0
    jz      _remove_it_from_start_exit
    push    rdi
    push    rsi
    push    rdx
    push    rcx
    mov     rdi, [r12]      ;rdi = *curr->data
    call    rdx             ;call strcmp
    pop     rcx
    pop     rdx
    pop     rsi
    pop     rdi
    cmp     rax, 0
    jnz     _remove_it_from_start_exit
    mov     r13, [r12 + 8]  ;r13 : *next = *curr->next
    push    rsi
    push    rdx
    push    rcx
    mov     rdi, r12
    call    _free           ;free(rdi) ==> free(*curr)
    pop     rcx
    pop     rdx
    pop     rsi
    mov     r12, r13        ;*curr = *next
    jmp     _remove_it_from_start_loop
_remove_it_from_start_exit:
    mov     rax, 0
    ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
_free_it:
    push    rsp
    mov     [r14 + 8], r13             ;(*prev)->next = *next
    mov     rdi, r12
    mov     [rdi], byte 0
    call    _free
    mov     r12, r13
    mov     rax, 0
    pop     rsp
    ret