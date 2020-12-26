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
push dword -781080912
call func-i
mov ecx,eax
add esp,4
mov [ebp-12],dword -781080688
pop ecx
pop ebx
leave
ret
pop ecx
pop ebx
leave
ret
