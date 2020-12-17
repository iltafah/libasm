global      _ft_atoi_base
section     .text

_ft_atoi_base:                  ;rax    ft_atoi_base(rdi, rsi)
    push    rbx
    push    r8
    xor     r12, r12            ;d_base
    xor     r13, r13            ;count
    xor     r14, r14            ;neg
    xor     r15, r15            ;num
    xor     rbx, rbx
    xor     r8, r8
    cmp     rdi, 0
    jz      _ft_atoi_base_error
    cmp     rsi, 0
    jz      _ft_atoi_base_error
    mov     ebx, dword -1
    mov     r14d, dword 1
    mov     r8b, byte '-'
    cmp     [rdi], r8b
    cmove   r14d, ebx
    xor     rbx, rbx
    mov     bl, byte '+'
    cmp     [rdi], bl
    je      _increment
    mov     bl, byte '-'
    cmp     [rdi], bl
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
    mov     r12, rax
    push    rdi
    push    rsi
    call    _check_num
    pop     rsi
    pop     rdi
    cmp     rax, 0
    je      _ft_atoi_base_error
    mov     r13, rax            
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
    mov     r15, rax            
    mov     r12, r15
    neg     r12
    cmp     r14, 1
    cmovne  r15, r12
    mov     rax, r15
    pop     r8
    pop     rcx;
    ret
_ft_atoi_base_error:
    mov     rax, 0
    pop     r8
    pop     rcx;
    ret
 
 

_check_base:                    ;rax  check_base(rdi)
    push    r8
    push    r9
    mov     r9, 0
    mov     r8, rdi
    inc     r8
_check_base_loop:
    cmp     [rdi + r9], byte 0
    jz      _check_base_ret
    push    rdi
    push    rsi
    push    r8
    xor     rbx, rbx
    mov     bl, byte [rdi + r9]
    movzx   rdi, bl
    mov     rsi, r8
    call    _check_errors       
    pop     r8
    pop     rsi
    pop     rdi
    cmp     rax, 1
    jz      _check_base_ret
    inc     r8
    inc     r9
    jmp     _check_base_loop
_check_base_ret:
    xor     rbx, rbx
    mov     ebx, 0
    cmp     rax, 1
    cmove   r9d, ebx
    mov     rax, r9
    pop     r9
    pop     rbx
    ret



_check_errors:
    xor     rbx, rbx
    mov     bl, byte '+'
    cmp     dil, bl
    je      _return_error
    xor     rbx, rbx
    mov     bl, byte '-'
    cmp     dil, bl
    je      _return_error
    cmp     [rsi], byte 0
    jne      _check_errors_loop
_exit:
    mov     rax, 0
    ret
_check_errors_loop:
    xor     rbx, rbx
    mov     bl, byte [rsi]
    cmp     dil, bl
    je      _return_error
    inc     rsi
    cmp     [rsi], byte 0
    jnz     _check_errors_loop 
    mov     rax, 0
    ret
_return_error:
    mov     rax, 1
    ret



_check_num:
    mov     r8, 0
    cmp     [rdi], byte 0
    jz     _check_num_error
_check_num_loop:
    push    rdi
    push    rsi
    xor     rbx, rbx
    mov     bl, byte [rdi]
    movsx   rdi, byte bl
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



_check_existence:
    xor     rbx, rbx
_check_existence_loop:
    mov     bl, byte [rsi]
    cmp     dil, bl
    jz      _check_existence_error
    inc     rsi
    cmp     [rsi], byte 0
    jnz     _check_existence_loop
    mov     rax, 0
    ret
_check_existence_error:
    mov     rax, 1
    ret



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
    xor     rbx, rbx
    mov     bl, byte [rdi + rcx]
    movzx   rdi, byte bl 
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



_get_value:
    xor     rbx, rbx
    mov     rax, 0
_get_value_loop:
    mov     bl, byte [rsi + rax]
    cmp     dil, bl
    je      _get_value_ret
    inc     rax
    cmp     [rsi + rax], byte 0
    jne     _get_value_loop
_get_value_ret:
    ret