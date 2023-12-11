;  gcc -no-pie wrapper.o makeNBON.o makeNBOC.o -o makeNBON
;  nasm -f elf64 -o makeNBON.o makeNBON.nasm
;  ./makeNBON


section .data
    test_values dd 0x12345678, 0xAABBCCDD, 0x87654321, 0x0F1E5D3C, 0xDEADBEEF
    num_tests   equ 5
    format db "Result: 0x%x", 10, 0  ; Format string for printf

section .text
    global assembly_main
    extern printf
    extern make_network_byte_order

assembly_main:
    sub rsp, 8              ; Align stack to 16 bytes
    mov rsi, test_values    ; Pointer to test values array
    mov rcx, num_tests      ; Number of test values

loop_start:
    mov eax, [rsi]          ; Load test value into EAX
    mov edi, eax            ; Move value to EDI for make_network_byte_order
    call make_network_byte_order
    ; No need to adjust rsp if we're not pushing to stack

    ; Prepare to call printf
    mov rdi, format         ; Format string
    mov rsi, rax            ; Result to print
    xor eax, eax            ; Clear eax (number of floating point params)
    call printf

    add rsi, 4              ; Move to the next value
    dec rcx                 ; Decrement loop counter
    jnz loop_start          ; Loop if not zero

    ; Exit
    add rsp, 8              ; Realign original stack
    mov eax, 60             ; Exit syscall
    xor edi, edi            ; Exit code 0
    syscall
