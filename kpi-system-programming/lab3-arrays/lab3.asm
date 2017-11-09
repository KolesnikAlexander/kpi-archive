.386        ;laba_3
 
 
Data1 segment PARA USE16
 
bytes_num dw 0
    A1  dw  5 dup (6 dup (6 dup (5 dup (?))))
Data1 ends
 
 
Data2 segment PARA USE16
I1      db  0
I2      db  0
I3      db  0
I4      db  0
 
    A2  dd  5 dup (6 dup (6 dup (5 dup (0abcd0123h))))
Data2 ends
 
 
 
Code1 segment use16
    ASSUME cs:Code1,ds:Data2,es:Data1       
	
begin:
 
    mov ax,Data2                ; data2  in ax
    mov ds,ax                   ; in ds -> data2
    mov ax,Data1                ; data1 in ax
    mov es,ax                   ; in es -> data1
    
    mov esi,offset A2           ; регистр esi содержит указатель на A2
    mov edi,offset A1           ; регистр edi содержит указатель на A1
 
    mov I1,5                    ; записываем значение (5, 6, 6, 5) в адреса (I1, I2, I3, I4)
    mov I2,6
    mov I3,6
    mov I4,5
 
    cld                         ;сброс в ноль флага направления df
    
    _beg:                       ;начало цикла
                inc esi         
                movsw           ;переслать элемент из одной ячейки памяти в другую
                inc esi
            
                dec I4
                jnz _beg
            mov I4,5
            dec I3
            jnz _beg
        mov I3,6
        dec I2
        jnz _beg
    mov I2,6
    dec I1
    jnz _beg
    
    jmp far ptr _c2
Code1 ends
 
 
 
Code2 segment USE16
    _c2 label far
 
    ASSUME cs:Code2,es:Data2,ds:Data1       
    
    mov ax,Data2
    mov es,ax
    mov ax,Data1
    mov ds,ax
        
    mov edi,offset A2
    mov eax,0abh                ; в eax значение "0abh"
    
    mov ecx, 5*6*6*5*4;         ; размер A2
    xor ebx,ebx                 ; обнуление ebx
    
    cld
        _beg2:
            repne scasb                 ; повторение и поиск значения в последовательности (цепочке) элементов в памяти
                                        ; то есть нашего значения "0abh"
            jcxz _end2                  ; переход внутри текущего сегмента команд, проверка на раенство 
            inc bx
            jmp _beg2
        _end2:
            nop
            cmp es:[edi - 1], al        ; проверка на последний элемент
            jne _end2_1
            inc bx
        _end2_1:
    
    mov bytes_num,bx
    
    nop 
    nop
    nop
    
    mov ax,400h             ; завершение работы программы
    int 21h
 
Code2 ends
end begin