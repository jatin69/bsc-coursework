; table for ascii value
; dec       ascii       hexcode
; '0'       48          30h
; '1'       49          31h     
; similarly ... all

.model tiny

.data

msg  dw "Enter the Ascii Code : $ "
msg1 dw 13,10,"Binary String : $" 
array db 8 dup(0)     
; 'array' is an array of size 8 bytes

.code
 
; display user message  
mov dx, offset msg
mov ah,09h
int 21h

; taking user input
mov ah,01h
int 21h

mov bl,2    ; used as a constant== 2           
mov cx,8    ; counter register ==8, for looping
mov si, offset array    ; starting base address of array loaded into si

calculate:    
mov ah, 00h        ; setting upper half of AX to zero, to prevent any garbage value
div bl              ; div contents of aL by bL, quotient is stored in AL and remainder in AH
mov array[si], ah  ; stores remainder in array1[si]
inc si           ; increment si
loop calculate      ; loop calculate, decrement cx by 1 each time     
    
 
; display msg1
mov dx,offset msg1
mov ah,09h
int 21h

; NOTE THAT, the array needs to be printed backwards
mov cx, 8       ; for looping
mov si, offset array   ; si=0
add si, 8               ; si=8  
dec si      ; printing from a[7] to a[0]

print:
mov dl,array[si]
; to handle ascii problem
add dl,30h  
; printing
mov ah,02h
int 21h  

dec si
loop print
   
.exit
end