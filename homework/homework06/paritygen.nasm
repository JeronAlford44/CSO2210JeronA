default rel
section .data
output db "Parity is even: %d", 10, 0

section .text
extern printf
extern exit
global _start

; Function to check the parity of a byte
; Input: AL = byte to check
; Output: AL = 1 if parity is even, 0 if odd
check_parity:
    test al, al    ; Perform a test operation, which affects the parity flag
    setp al        ; Set AL to 1 if parity flag is set (even parity), 0 otherwise
    ret

_start:
    mov al, 0x54     ; Load a byte value into AL
    call check_parity ; Check its parity

    ; Print the result
    mov esi, eax      ; Move the result to esi, which is the second argument for printf
    mov rdi, output   ; First argument (format string)
    xor eax, eax      ; Sets eax register to 0
    call printf

    ; Exit the program
    mov edi, 0        ; Exit code,  could use xor edi, edi
    call exit