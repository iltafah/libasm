global  _ft_list_sort
    section .text

_ft_list_sort:  ;   rax  ft_list_sort(rdi, rsi)
    push    r12
    push    r15
    cmp     rdi, 0              ;list = NULL
    jz      _exit               ;list  ?= 0
    mov     r15, [rdi]          ;list = *begin_list
    cmp     r15, 0              ;list ?= 0
    jz      _exit
    mov     r12, [r15 + 8]      ;n_ptr = list->next
    cmp     r12, 0
    jz      _exit

_loop_list:
    push    rbx
    push    rbp
    mov     rbx, [r15]          ;rbx = list->data
    mov     rbp, [r12]          ;rbp = n_ptr->data

_compare:
    push    rdi
    push    rsi
    mov     rax, rsi            ;call cmp function
    mov     rdi, qword rbx      
    mov     rsi, qword rbp      
    call    rax                 
    pop     rsi
    pop     rdi
    cmp     eax, dword 0
    jge     _swap
    pop     rbp
    pop     rbx
    jmp     _inc_next

_swap:
    mov     [r15], qword rbp
    mov     [r12], qword rbx
    pop     rbp
    pop     rbx
    jmp     _inc_next

_inc_next:
    mov     r12, [r12 + 8]
    cmp     r12, 0
    jz      _inc_list
    jmp     _loop_list
 
_inc_list:
    mov     r15, [r15 + 8]
    cmp     r15, 0
    jz      _exit
    mov     r12, [r15 + 8]
    cmp     r12, 0
    jz      _exit
    jmp     _loop_list
    
_exit:
    pop     r15
    pop     r12
    mov     rax, 0
    ret
