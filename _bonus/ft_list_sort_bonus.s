global  _ft_list_sort

    section .data
_NULL_msg : db "1_ it is null = 0",10
len:   equ     $ - _NULL_msg
_NULL_msg2 : db "2_ it is null = 0",10
len2:   equ     $ - _NULL_msg2
_nNULL_msg : db "it is not null != 0",10
len3:   equ     $ - _nNULL_msg
_njmp_msg  : db "didn't jump",10
len4:   equ     $ - _njmp_msg
_jmp_msg  : db "jumped",10
len5:   equ     $ - _jmp_msg


    section .text
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

_ft_list_sort:  ;   rax  ft_list_sort(rdi, rsi)
    push    r12
    push    r15

    cmp     rdi, 0              ;list = NULL
    jz      _NULL               ;list  ?= 0

    mov     r15, [rdi]          ;list = *begin_list
    cmp     r15, 0              ;list ?= 0
    jz      _NULL2

    mov     r12, [r15 + 8]      ;n_ptr = list->next
    cmp     r12, 0
    jz      _NULL
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
_loop_list:
    push    rbx
    push    rbp
    mov     rbx, [r15]          ;rbx = list->data
    mov     rbp, [r12]          ;rbp = n_ptr->data

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
_compare:
    push    rdi
    push    rsi


    mov     rax, rsi            ;call cmp function
    mov     rdi, qword rbx      ;
    mov     rsi, qword rbp      ;
    call    rax                 ;

    pop     rsi
    pop     rdi

    cmp     eax, dword 0
    jge     _swap
    
    pop rbp
    pop rbx
   
    jmp     _inc_next

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; 
_swap:
    mov     [r15], dword ebp
    mov     [r12], dword ebx

;/////////////////write//////////////
push    rdi                         ;
push    rsi                         ;
push    rdx                         ;
mov     rax, 0x2000004              ;
mov     rdi, 1                      ;
mov     rsi, _jmp_msg               ;
mov     rdx, len5                   ;
syscall                             ;
pop     rdx                         ;
pop     rsi                         ;
pop     rdi                         ;
;////////////////////////////////////
    
    pop rbp
    pop rbx
jmp     _loop_list
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
_inc_next:
    mov     r12, [r12 + 8]
    cmp     r12, 0
    jz      _inc_list
    jmp     _loop_list
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; 
_inc_list:
    mov     r15, [r15 + 8]
    cmp     r15, 0
    jz      _end
    mov     r12, [r15 + 8]
    cmp     r12, 0
    jz      _end
    jmp     _loop_list
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
_NULL:
    pop     r15
    pop     r12

;/////////////////write/////////////
push    rdi                        ;
push    rsi                        ;
push    rdx                        ;
mov     rax, 0x2000004             ;
mov     rdi, 1                     ;    
mov     rsi, _NULL_msg             ;
mov     rdx, len                   ;
syscall                            ;
pop     rdx                        ;
pop     rsi                        ;
pop     rdi                        ;
;///////////////////////////////////

    mov     rax, 0
    ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
_NULL2:
    pop     r15
    pop     r12

;/////////////////write/////////////
push    rdi                        ;
push    rsi                        ;
push    rdx                        ;
mov     rax, 0x2000004             ;
mov     rdi, 1                     ;    
mov     rsi, _NULL_msg2            ;
mov     rdx, len2                  ;
syscall                            ;
pop     rdx                        ;
pop     rsi                        ;
pop     rdi                        ;
;///////////////////////////////////

    mov     rax, 0
    ret
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
_end:
    pop     r15
    pop     r12
    mov     rax, 0
    ret