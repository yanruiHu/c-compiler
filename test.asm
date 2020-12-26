%include "grammar/InterMediate/asm_io.inc"
section .text
global main

main:
enter 20,0
push ebx
push ecx
mov edx,ebp
sub edx,4
mov [edx],dword 1
mov edx,ebp
sub edx,8
mov [edx],dword 2
mov edx,ebp
sub edx,12
mov [edx],dword 3
mov ebx,[ebp-8]
mov ecx,[ebp-12]
xor edx,edx
mov eax,ebx
mul ecx
mov ebx,eax
mov edx,ebp
sub edx,16
mov [edx],ebx
pop ecx
pop ebx
leave
ret
