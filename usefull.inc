%macro print 2
  mov rax, 1
  mov rdi, 1
  mov rsi, %1
  mov rdx, %2
  syscall
%endmacro

%macro exit 0
  mov rax, 60
  mov rdi, 0
  syscall
%endmacro

%macro printNumber 3
 
  mov rax, %3
  mov rcx, %1
  mov rbx, 10
  mov [rcx], rbx
  inc rcx
  mov [%2], rcx

  %%readDigits:
    mov rdx, 0
    mov rbx, 10
    div rbx
    add rdx, 48

    mov rcx, [%2]
    mov [rcx], dl
    inc rcx
    mov [%2], rcx

    cmp rax, 0
    jne %%readDigits

  %%actualPrint:
    mov rcx, [%2]
    print rcx, 1

    mov rcx, [%2]
    dec rcx
    mov [%2], rcx

    cmp rcx, %1
    jge %%actualPrint

%endmacro
 
%macro atoi 1
  xor rbx, rbx    ; clear rbx
  %%next_digit:
    movzx rax, byte[%1]

    cmp al, 0
    je %%end

    cmp al, '0'
    jl %%end
    cmp al, '9'
    jg %%end

    inc rsi
    sub al, '0'    ; convert from ASCII to number
    imul rbx, 10
    add rbx, rax   ; rbx = rbx*10 + rax
    jmp %%next_digit
  %%end:
  mov rax, rbx
%endmacro


