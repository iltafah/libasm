global  _ft_lstsize
section .text

_ft_lstsize:      ;rax    ft_lstsize_bonus(rdi)
    push    r12
    xor     r12, r12
    ;mov     r12, 0
    ;xor     r11, r11

ft_loop:
    ;mov     r12, rdi
    
    ;push    rdi
    ;mov     rax, 0x2000004
    ;mov     rdi, 1
    ;mov     rsi, r11
    ;mov     rdx, 1
    ;syscall
    
    inc     r12

    ;pop     rdi

    mov     r8, [rdi + 8]
    cmp     r8, 0
    jz      _ft_1

    mov     rdi, [rdi + 8]
    jmp     ft_loop

_ft_1:
    mov     rax, r12
    pop     r12
    ret

    ;cmp [c]

   ; mov rax, 0x2000004
    ;mov rdi, 1
    ;mov rsi, msg
    ;mov rdx, 1
    ;syscall

; rdi = list
; push rdi
; mov       rdi, 16
; call      _malloc ; malloc(16) ==> 16 bytes
; cmp       rax, 0
; pop       rdi
; jz        exit
