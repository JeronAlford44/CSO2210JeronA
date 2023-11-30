section .data
    test_values dd 0x12345678, 0xAABBCCDD, 0x87654321, 0x0F1E5D3C, 0xDEADBEEF
    num_tests   equ 5
    format db "Result: 0x%x", 10, 0  ; Format string for printf, 10 is new line, 0 is null terminator

section .text
    global _start
    extern printf
    extern make_network_byte_order

_start:
    mov rsi, test_values     ; Makes Pointer to the test values array of DoubleWords
    mov rcx, num_tests       ; Number of test values

loop_start:
    mov eax, [rsi]           ; Load the next test value into EAX
    sub rsp, 8               ; Move stack pointer down to allocate for 8 byte function address 
    mov qword [rsp], rax     ; Move the value onto the stack for the function call
    call make_network_byte_order
    add rsp, 8               ; Clean up the stack to realign to a 16-byte boundary

    ; Print the result
    sub rsp, 32              ; Allocate stack space and align stack 10 bytes for string 4 bytes for double word 8 bytes printf function call = 22 bytes --> lowest multiple of 16 is 32
    mov rdi, format          ; Move format string into RDI (first argument for printf)
    mov rsi, rax             ; Move the result into RSI (second argument for printf)
    mov rax, 0               ; Set number of floating point parameters in XMM registers to 0
    call printf
    add rsp, 32              ; Clean up the stack

    add rsi, 4               ; Move to the next value
    dec rcx                  ; Decrement the loop counter
    jnz loop_start           ; If counter is not zero, loop again

    ; Exit the program
    mov eax, 60              ; System call number for exit
    xor edi, edi             ; Exit code 0
    syscall