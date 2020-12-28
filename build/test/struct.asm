%include "io/asm_io.inc"
section .text
global main

main:
enter 16,0
push ecx
push ecx
mov edx,ebp
sub edx,8
mov [edx],dword 1
mov edx,ebp
sub edx,4
mov [edx],dword 1
mov ebx,[ebp-8]
mov ecx,[ebp-4]
mov eax,[ebp-4]
xor edx,edx
mov eax,ecx
mul ecx
mov ecx,eax
add ebx,ecx
mov ecx,[ebp-4]
add ebx,ecx
mov edx,ebp
sub edx,4
mov [edx],ebx
mov [ebp-12],dword 1
xor edx,edx
mov eax,[ebp-12]
mul dword[ebp-12]
mov ebx,eax
add ebx,[ebp-12]
mov [ebp-12],ebx
mov ebx,[ebp-4]
mov eax,ebx
call print_int_i
add esp,4
pop ecx
pop ecx
leave
ret
