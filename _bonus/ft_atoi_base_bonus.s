global      _ft_atoi_base
section     .text

_ft_atoi_base:                  ;rax    ft_atoi_base(rdi, rsi)
    push    rcx
    push    r8
    xor     r12, r12            ;d_base
    xor     r13, r13            ;count
    xor     r14, r14            ;neg
    xor     r15, r15            ;num
    xor     rcx, rcx
    xor     r8, r8
    mov     ecx, dword -1
    mov     r14d, dword 1
    mov     r8b, byte '-'
    cmp     [rdi], r8b
    cmove   r14d, ecx
    xor     rcx, rcx
    mov     cl, byte '+'
    cmp     [rdi], cl
    je      _increment
    mov     cl, byte '-'
    cmp     [rdi], cl
    je      _increment
    jmp     _ft_atoi_base_1
_increment:
    inc     rdi
_ft_atoi_base_1:
    push    rdi
    push    rsi
    mov     rdi, rsi
    call    _check_base
    pop     rsi
    pop     rdi
    cmp     rax, 2
    jl      _ft_atoi_base_error
    mov     r12, rax            ;move the result of check_base to d_base (r12)
    push    rdi
    push    rsi
    call    _check_num
    pop     rsi
    pop     rdi
    cmp     rax, 0
    je      _ft_atoi_base_error
    mov     r13, rax            ;move the result of check_num to count (r13)
    push    rdi                 ;str
    push    rsi                 ;base
    push    rdx
    push    rcx
    mov     rdx, r12            ;d_base
    mov     rcx, r13            ;count
    call    _convert_num_to_decimal
    pop     rcx
    pop     rdx
    pop     rsi
    pop     rdi
    mov     r15, rax            ;move the result of convert_num_to_decimal to num (r15)
    mov     r12, r15
    neg     r12
    cmp     r14, 1
    cmovne  r15, r12
    mov     rax, r15
    pop     r8
    pop     rcx;
    ret
_ft_atoi_base_error:
    mov     rax, -42
    pop     r8
    pop     rcx;
    ret
 ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
_check_base:                    ;rax  check_base(rdi)
    push    rbx
    push    r12
    mov     r12, 0
    mov     rbx, rdi
    inc     rbx
_check_base_loop:
    cmp     [rdi + r12], byte 0
    jz      _check_base_ret
    push    rdi
    push    rsi
    push    rbx
    xor     rcx, rcx
    mov     cl, byte [rdi + r12]
    movzx   rdi, cl
    mov     rsi, rbx
    call    _check_errors       ;check if there is an error and return 1 in rax if there is
    pop     rbx
    pop     rsi
    pop     rdi
    cmp     rax, 1
    jz      _check_base_ret
    inc     r12
    inc     rbx
    jmp     _check_base_loop
_check_base_ret:
    xor     rbx, rbx
    mov     ebx, 0
    cmp     rax, 1
    cmove   r12d, ebx
    mov     rax, r12
    pop     r12
    pop     rbx
    ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
_check_errors:
    xor     rcx, rcx
    mov     cl, byte '+'
    cmp     dil, cl
    je      _return_error
    xor     rcx, rcx
    mov     cl, byte '-'
    cmp     dil, cl
    je      _return_error
    cmp     [rsi], byte 0
    jne      _check_errors_loop
_exit:
    mov     rax, 0
    ret
_check_errors_loop:
    xor     rcx, rcx
    mov     cl, byte [rsi]
    cmp     dil, cl
    je      _return_error
    inc     rsi
    cmp     [rsi], byte 0
    jnz     _check_errors_loop 
    mov     rax, 0
    ret
_return_error:
    mov     rax, 1
    ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
_check_num:
    mov     r8, 0
    cmp     [rdi], byte 0
    jz     _check_num_error
_check_num_loop:
    push    rdi
    push    rsi
    xor     rcx, rcx
    mov     cl, byte [rdi]
    movsx   rdi, byte cl
    call    _check_existence
    pop     rsi
    pop     rdi
    cmp     rax, 0
    je      _check_num_error
    inc     rdi
    inc     r8
    cmp     [rdi], byte 0
    jnz     _check_num_loop 
    mov     rax, r8
    ret
_check_num_error:
    mov     rax, 0
    ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
_check_existence:
    xor     rcx, rcx
_check_existence_loop:
    mov     cl, byte [rsi]
    cmp     dil, cl
    jz      _check_existence_error
    inc     rsi
    cmp     [rsi], byte 0
    jnz     _check_existence_loop
    mov     rax, 0
    ret
_check_existence_error:
    mov     rax, 1
    ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
_convert_num_to_decimal:
    push    r10
    push    r9
    push    r8
    mov     r9, 0                   ;num
    mov     r10, 1                  ;base_pow
    dec     rcx
    cmp     rcx, 0
    jl      _convert_num_to_decimal_ret
_convert_num_to_decimal_loop:
    push    rdi
    push    rsi
    mov     r8b, byte [rdi + rcx]   ;not sure about this line
    movzx   rdi, byte r8b 
    call    _get_value
    pop     rsi
    pop     rdi
    push    rdx
    mov     r8, rdx
    mul     r10
    add     r9, rax
    mov     rax, r10
    mul     r8
    mov     r10, rax
    pop     rdx
    cmp     rcx, 0
    dec     rcx
    jnl     _convert_num_to_decimal_loop
_convert_num_to_decimal_ret:
    mov     rax, r9
    pop     r8
    pop     r9
    pop     r10
    ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
_get_value:
    push    r8
    mov     rax, 0
_get_value_loop:
    mov     r8b, byte [rsi + rax]
    cmp     dil, r8b
    je      _get_value_ret
    inc     rax
    cmp     [rsi + rax], byte 0
    jne     _get_value_loop
_get_value_ret:
    pop     r8
    ret