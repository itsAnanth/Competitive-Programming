assume ds:data, cs:code
data segment   
    str db "hello"
    len db $ - str     
    search db "w"
    
data ends

code segment
    start:       
    mov ax, data
    mov ds, ax 
    mov al, search
    mov cl, len
    
    lea si, str
    
    iterate:    
   
        
        cmp al, [si]  
        je found
          
        inc si
        dec cl
        
        jnz iterate

        jmp notfound   
     
    
    notfound:
        mov al, 0
        jmp last
    found:
        mov al, 1
        jmp last
    last:
        int 21h

  
    
    code ends
end start
