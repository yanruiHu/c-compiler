%include "grammar/InterMediate/asm_io.inc"
section .text
global main

swap-p-p:
enter 8,0
push ebx
push ecx
mov ebx,[ebp+12]
mov ebx,[ebx]
mov [ebp-4],ebx
mov ebx,[ebp+8]
mov ebx,[ebx]
mov edx,[ebp+12]
mov [edx],ebx
mov ebx,[ebp-4]
mov edx,[ebp+8]
mov [edx],ebx
pop ecx
pop ebx
leave
ret
main:
enter 20,0
push ebx
push ecx
mov [ebp-4],dword 2
mov [ebp-8],dword 3
mov ebx,ebp
sub ebx,4
mov [ebp-12],ebx
mov ebx,ebp
sub ebx,8
mov [ebp-16],ebx
push dword[ebp-12]
push dword[ebp-16]
call swap-p-p
add esp,8
pop ecx
pop ebx
leave
ret
