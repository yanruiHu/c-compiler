%include "io/asm_io.inc"
section .text
global main

main:
enter 52,0
push ecx
push ecx
mov [ebp-44],dword 0
mov [ebp-48],dword 0
label2:
cmp [ebp-44],dword 10
jl label0
jmp label1
label0:
xor ebx,ebx
mov ebx,dword[ebp-48]
add ebx,dword 1
mov [ebp-48],ebx
xor ebx,ebx
mov ebx,dword[ebp-44]
add ebx,dword 1
mov [ebp-44],ebx
jmp label2
label1:
mov [ebp-44],dword 0
label5:
cmp [ebp-44],dword 10
jl label3
jmp label4
label3:
mov edx,ebp
sub edx,[ebp-44]
sub edx,[ebp-44]
sub edx,[ebp-44]
sub edx,[ebp-44]
mov ebx,[edx]
mov eax,ebx
call print_int_i
add esp,4
xor ecx,ecx
mov ecx,dword[ebp-44]
add ecx,dword 1
mov [ebp-44],ecx
jmp label5
label4:
pop ecx
pop ecx
leave
ret
pop ecx
pop ecx
leave
ret
