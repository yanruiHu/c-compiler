%include "grammar/InterMediate/asm_io.inc"
section .text
global main

main:
enter 16,0
push ebx
push ecx
mov [ebp-8],dword 1
mov [ebp-8],dword 3
xor edx,edx
mov eax,dword 10
mov ebx,dword 2
div ebx
mov ebx,eax
push ebx
push dword 3
call pow_i_i
mov ebx,eax
add esp,8
add [ebp-8],ebx
mov ebx,[ebp-8]
mov [ebp-4],ebx
cmp [ebp-4],dword 0
jne label0
jmp label1
label0:
cmp [ebp-4],dword 10
jl label2
jmp label3
label2:
cmp [ebp-8],dword 10
jl label4
jmp label3
label4:
xor edx,edx
mov eax,[ebp-4]
mul dword[ebp-8]
mov ebx,eax
xor edx,edx
mov eax,ebx
mul dword[ebp-8]
mov ebx,eax
mov [ebp-4],ebx
xor edx,edx
mov eax,dword[ebp-8]
mov ebx,dword 2
div ebx
mov ebx,edx
mov [ebp-8],ebx
jmp label0
label3:
mov [ebp-12],dword 0
label6:
cmp [ebp-12],dword 1
jl label5
jmp label1
label5:
mov ebx,[ebp-8]
add ebx,[ebp-4]
mov [ebp-12],ebx
xor ebx,ebx
mov ebx,dword 1
add ebx,dword[ebp-12]
mov [ebp-12],ebx
jmp label6
label1:
mov eax,[ebp-4]
leave
ret
pop ecx
pop ebx
leave
ret
