.model SMALL

.DATA

msg0 dw 13,10,"Enter no of elements ( less than 10 ): $"                
msg1 dw 13,10,"Enter the elements : $"
msg2 dw 13,10,"Enter the element you want to find : $"
msg3 dw 13,10,"Element is Found at Location : $"
msg4 dw 13,10,"Element Not Found... $"

array db 15 dup('$')    

n db ?       ; variable for storing size

.CODE
.STARTUP

; msg0 display
mov dx,offset msg0
mov ah,09h
int 21h    
     
; take user input     
mov ah, 01h
int 21h   
; handling ascii
sub al, '0'
mov n, al       ; value of size in n 
 
mov ax, 0000h   ; clear garbage
mov cx, 0000h   ; clear garbage

mov cl, n       ; loop counter
mov si,0        ; source index


enter:            
; msg1 disp
mov dx,offset msg1
mov ah,09h
int 21h

; user input
mov ah,1
int 21h
mov array[si],al
inc si
loop enter

; msg2
mov dx,offset msg2
mov ah,09h
int 21h

; numeric user input
mov ah,01h
int 21h
mov bh,al     ; storing key in BH
         
                  
mov bl,02h       ; a constant '2' for division (l+h)/2
mov bp,0         ; bp = 0 , initial index    
mov ax, 0000h    ; removing garbage from ax 
mov al, n        ; take input in al
dec al           ; -1 for size adjust to n-1
mov si,ax        ; index set to n-1 
mov ax, 0000h    ; removing garbage from ax 

find:
add ax,si      ; add UB (si)
div bl      ; div by 2
mov ah,0    ; ah=0 , removing garbage - remove if not necessary   
mov di,ax   ; this is the key index
cmp bh,array[di]  ; comparing BH with a[di]
je found    ; for unsigned, jump if equal
jb below   ;  jump if below
ja above   ; jump if above


found:       
; msg3 
mov dx,offset msg3
mov ah, 9h      ; 09 for printing   from data segment
int 21h

; printing the found index
mov dx,di
add dx,1    ; add 1 for user interface
add dx,30h  ; add 30h for ascii handling

;display answer
mov ah,02h  ; 02 for writing    from memory
int 21h
jmp c


below:
cmp bp,si      ; bp (LB)  and  si (UB)
je n_f          ; not equal
dec di         ; dec di
mov si,di      ; new si(UB) 
mov ah,0       ; put LB in ah , as next is addition with si
jmp find


above:
cmp bp,si      ; bp (LB)  and  si (UB)
je n_f            ; not equal
inc di           ; inc di
mov bp,di        ; new bp (LB)
mov ax,bp        ; put LB in ax, as next is add with si
jmp find

n_f:
; msg4
mov dx,offset msg4
mov ah,09h
int 21h

c:         
.EXIT         
         
END