global mac

mac:
    mov r9, rdx
    ; rdi -- &a
    ; rsi -- &x
    ; r9  -- &y
    ; [rdi + 8]  a->hi
    ; [rdi]      a->lo

    mov rax, [rsi]   ; (a->lo + x->lo * y->lo) % 2^64
    mov r10, [r9]
    mul r10; Unsigned multiply (RDX:RAX ← RAX ∗ r/m64).
    add rax, [rdi]

    ; rax zawiera poprawnie obliczone res->lo
    ; rdx zawiera górne bity  x->lo * y->lo
    ; CF zawiera 1, jeśli nastąpiło przeniesienie przy ostatnim dodawaniu
    ; obliczyć (a->hi + x->hi*y->lo + x->lo*y->hi + (a->lo + x->lo*y->lo)/2^64)
    adc rdx, [rdi+8]

    imul r10, [rsi+8]
    add rdx, r10

    mov r10, [rsi]
    imul r10, [r9+8]
    add rdx, r10

    ret