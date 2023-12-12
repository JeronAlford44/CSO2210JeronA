;  nasm -f elf64 -o findGCDfunc.o findGCDfunc.nasm
;  gcc -o gcdFinder gcdFinder.c findGCDfunc.o
;  ./gcdFinder




section .text
    global _find_gcd

; The GCD function
; Arguments:
;   rdi - first number
;   rsi - second number
; Returns:
;   rax - GCD of rdi and rsi
_find_gcd:
    mov rax, rdi      ; Move first number to rax register
    mov rbx, rsi      ; Move second number to rbx register
    test rbx, rbx     ; Check if second number is 0, sets zero flag to 1 if true
    jz .gcd_done      ; If yes, GCD is in rax (first number)

.gcd_loop:
    ; Perform the Euclidean algorithm
    mov rdx, 0
    div rbx           ; Divide rax by rbx, remainder in rdx
    mov rax, rbx
    mov rbx, rdx
    test rbx, rbx     ; Check if remainder is 0
    jnz .gcd_loop     ; If not, continue the loop

.gcd_done:
    ret
