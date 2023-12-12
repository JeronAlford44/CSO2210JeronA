section .data
    num1 dq 0          ; Placeholder for the first number
    num2 dq 0          ; Placeholder for the second number
    format db "%llu", 0 ; Format string for scanf and printf

section .bss
    result resq 1      ; Space for the GCD result

; section .text
    global _main
    extern _scanf, _printf
    default rel

section .text

_main:
    ; Prompt user for input
    mov rdi, format    ; Format string for scanf
    mov rsi, num1      ; Address of num1
    mov rdx, num2      ; Address of num2
    call _scanf         ; Call scanf to read two numbers

    ; Load numbers into registers
    mov rax, [num1]
    mov rbx, [num2]

    ; Call gcd function
    call gcd

    ; Print result
    mov rdi, format    ; Format string for printf
    mov rsi, rax       ; GCD result
    call _printf        ; Call printf to print the result

    ; Exit
;    mov rax, 60        ; System call number for exit
;    xor rdi, rdi       ; Exit code 0
;    syscall
    ret

; Function to calculate GCD
gcd:
    cmp rbx, 0         ; Check if second number is 0
    je gcd_done        ; If yes, GCD is in rax (first number)
    ; Perform the Euclidean algorithm
    mov rdx, 0
    div rbx            ; Divide rax by rbx, remainder in rdx
    mov rax, rbx
    mov rbx, rdx
    jmp gcd            ; Repeat the process
gcd_done:
    ret
