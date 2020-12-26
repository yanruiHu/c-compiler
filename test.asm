%include "grammar/InterMediate/asm_io.inc"
section .text
global main

func-i:
enter 4,0
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
main:
enter 16,0
push ebx
push ecx
mov edx,ebp
sub edx,4
mov [edx],dword 1
mov edx,ebp
sub edx,4
mov [edx],dword 2
mov ebx,[ebp-4]
push ebx
call func-i
mov ebx,eax
add esp,4
mov [ebp-12],ebx
pop ecx
pop ebx
leave
ret
pop ecx
pop ebx
leave
ret
