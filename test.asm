%include "io/asm_io.inc"
section .text
global main

main:
enter 44,0
push ebx
push ecx
pop ecx
pop ebx
leave
ret
pop ecx
pop ebx
leave
ret
