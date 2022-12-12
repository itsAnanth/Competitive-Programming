ASSUME CS:CODE, DS:DATA

data segment
    str db "hello world$"
    len db $ - str
data ends

code segment
    start:
    
    mov ax, data
    mov ds, ax
    lea dx, str
    mov ah, 9
    int 21h
    mov ah, 4ch
    int 21h
    code ends
end start
