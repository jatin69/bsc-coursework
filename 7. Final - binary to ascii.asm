.model tiny

.data

msg dw 13,10,"Enter the Binary String : $ "
msg1 dw 13,10,"Ascii Code : $" 
array db 8 dup(0)

.code
 
mov cx,8    ; for looping
mov si,0    ; set si=0

;display msg
mov dx,offset msg
mov ah,09h
int 21h
  
enter:
; take numeric input, single digit
mov ah,01h
int 21h                         
; sub 30h for ascii handling
sub al,30h  
; holding in array 
mov array[si],al  
; inc si
inc si  
; re start loop, taking a total of 8 bits of input
loop enter

  
; MAIN CODE START HERE  
mov bl,2        ; taking a constant ==2
mov ax,0001h    ; puttng 1 in AX, i.e 2^0 =1
mov si,0        ; source index 0
mov di,7        ; destination index n-1 = 8-1 = 7   ; starting from back, from UNIT PLACE

mov cx,8        ; loop construct cx=8

calculate:
cmp array[di],1   ; compare from backward, UNIT PLACE
jne one           ; jump if AX!=1 , 
add si,ax         ; else if ==1 , add si,ax , ax was 1    , SI=SI+AX

one:
mul bl            ; multiply by 2, increasing power of 2, stored in AX, AX=AX*2
dec di            ; decrement index
loop calculate    ; loop again
           
; disp msg1           
mov dx,offset msg1
mov ah,09h
int 21h

; move contents of SI to DX for display
mov dx,si
mov ah,02h
int 21h
   
.exit
end