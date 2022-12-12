ASSUME CS:CODE, DS:DATA

data segment
    str db "hello$"
    len dw $ - str
data ends

code segment
    start:  
    mov ax, data
    mov ds, ax
    lea si, str
    mov cx, len
    ; if string is of length 5, then start from 5 * 2 (10) and decrement to get reverse
    add si, cx
                
    
    iterate:   
        dec si
        mov dl, [si]
        mov ah, 02h
        int 21h
        ;loop iterate
        dec cx
        jnz iterate
    code ends
end start
