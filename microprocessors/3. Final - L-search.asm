; Linear Search

.MODEL SMALL  

.DATA
ARRAY DB 5 DUP(?)
M0 DB 13,10,'Enter 5 number below -$'
M1 DB 13,10,'Enter the number:$'
M2 DB 13,10,'Enter the number to be searched:$'
M3 DB 13,10,'Number found at position: $'
M4 DB 13,10,'Number not found !! $'

.CODE
.STARTUP

; starting index of array SI=0
MOV SI,OFFSET ARRAY           
; CX=5 , for LOOP 
MOV CX,5

; print msg from data segment
MOV AH,09H
MOV DX,OFFSET M0
INT 21H


; user input loop
ENTER:
; print msg from data segment
MOV AH,09H
MOV DX,OFFSET M1
INT 21H

; read user input
MOV AH,01H
INT 21H 
; sub 30H for ascii handling
SUB AL,30H

; move into array
MOV ARRAY[SI],AL 
; increment index
INC SI           
; loop back
LOOP ENTER
 
; display m2 from code segment 
MOV AH,09H
MOV DX,OFFSET M2
INT 21H                       
; take user input -> numeric
MOV AH,01H
INT 21H 
; subtract 30H for handling ascii 
SUB AL,30H

; reset array index
MOV SI,OFFSET ARRAY
MOV CX,5

; just one loop required, LOOP1
LOOP1:
; compare user input element with a[i]                         
CMP AL,ARRAY[SI]                      
; if equal, jump to FOUND
JE FOUND                 
; else, just increment 'i'
INC SI 
; and loop back
LOOP LOOP1

; if loop ends and comes here, that means not found         
NOTFOUND:
; display not found message from data segment         
MOV AH,09H
MOV DX,OFFSET M4
INT 21H                                    
; proceed to exit
JMP MYEXIT
 
; come here when found 
FOUND:
; display message "found at loc: "
MOV AH,09H
MOV DX,OFFSET M3
INT 21H                           
; increment SI(found index) for USER understanding
INC SI                                            

; delete garbage value from DX
MOV DX,0H                     
; move SI to DX
MOV DX,SI      
; add 30h to handle ascii problem
ADD DX,30H                       
; then display on screen
MOV AH,02H
INT 21H

; exit lable
MYEXIT:
.EXIT

END