section .data
   string: db "Hello, Holberton", 10, 0
   format: db "%s", 0

extern printf

section .text

   global main
main:
   push rbp

   mov rdi, format
   mov rsi, string

   call printf

   pop rbp

   mov rax, 0
   ret
