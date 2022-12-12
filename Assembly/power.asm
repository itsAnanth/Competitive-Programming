ASSUME CS:CODE, DS:DATA

data segment
    num db 3
data ends

code segment
    start:
    
    mov ax, data
    mov ds, ax
              
    mov al, num
    mov bl, num
    mov cl, num
    
    dec cl
    iterate:
        mul bl
                   
        dec cl
        jnz iterate
        
   
    int 21h
    code ends
end start
