assume cs:code, ds:data
data segment
    nos db 4, 2, 8, 9
    res db ?    
    len db $-nos
data ends

code segment
    start:
    mov ax, data
    mov ds, ax     
    lea si, nos
    mov cl, len
    
    mov res, 00h
    
    up:
    mov al, [si]
    cmp al, bl
    jl iterate
    mov bl, al
    
    iterate:
    inc si
    dec cl
    jnz up
    
    
    mov res, bl

    
    int 21h
    code ends
end start
