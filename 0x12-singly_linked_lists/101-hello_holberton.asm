section .data
    message db 'Hello, Holberton', 0Ah, 0

section .text
    global main
    extern printf

main:
    push rbp
    mov rbp, rsp

    ; call printf to print the message
    mov rdi, message
    xor rax, rax
    call printf

    ; return 0
    xor eax, eax
    pop rbp
    ret

