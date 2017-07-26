; bubble sort in c++
;void bubbleSort(int arr[], int n) { int i, j;
;   for (i = 0; i <= n-1; i++)      
;       for (j = 0; j <= n-1-i; j++) 
;           if (arr[j] > arr[j+1]) {  swap(&arr[j], &arr[j+1]); }   }


; Note that this n-1-i is handled super smartly
; that is n-1-i  is equal to in outer -> (n-1)-(i) , that is, its iteration window
 
;Bubble sort



.MODEL SMALL
.DATA
   ARRAY DB 15 DUP (?)
   M1 DB 13,10,'Enter the number of elements:$'
   M2 DB 13,10,'Enter the numbers(in any random order):$'
   M3 DB 13,10,'Sorted sequence is:$'
   N DB ?
 
.CODE 
.STARTUP
        
        ; display m1 msg
        MOV AH,09H
        MOV DX,OFFSET M1
        INT 21H
        
        ; taking input
        mov AH,01h
        int 21h     
           
        ; sub 30h from input to make it into machine format   
        SUB AL,30H
        
        ; hold no of element in N
        MOV N,AL 
        
        ; holding N in CL register - Decremented on each loop iteration - IMPORTANT
        MOV CL,N
        
        ; Source index set to starting of ARRAY    , SI=0
        MOV SI,OFFSET ARRAY
  
  ; enter elements loop
  ENT: 
        ; display input msg m2
        MOV AH,09H
        MOV DX,OFFSET M2
        INT 21H                
        
        ; then read that number
        MOV AH,01H
        INT 21H
        
        ;sub 30H to store it in machine format 
        SUB AL,30H       
        
        ; move to array[SI]
        MOV ARRAY[SI],AL
        INC SI
        
        ; LOOP back to enter numbers
        LOOP ENT

; enter elements loop done

        ; for safety
        MOV CH,00H
        ; move N to CL to start the Loop
        MOV CL,N
        ; sub 1 from CL, as bubble sort loop runs from 0 to n-1
        SUB CL,01H
   
  ; outer loop       
  LOOP1:   
        ; start from SI=0
        MOV SI,OFFSET ARRAY
        ; store CX ( decrements on each loop iteration ) in DI ( a safe house )        
        MOV DI,CX
      
  
  ; Inner loop
  LOOP2:
         ; we need to compare a[i] and a[i+1],
         
         ; for that move a[i] to AL
         MOV AL,ARRAY[SI]          
         
         ; then compare
         CMP AL,ARRAY[SI+1]
         ; if a[i] <= a[i+1] , then no swapping required, SKIP that and directly jump to P1,
         JLE P1                              
         
         ; comes here only when a[i]>a[i+1],
         ; swap contents of AL (derived from a[i]) with a[i+1]
         XCHG AL,ARRAY[SI+1]                                  
         ; move the swapped value to original owner
         MOV ARRAY[SI],AL
         
       ; go ahead with P1                 
       P1:
      
       ; increment value of SI ( 'i' of outer loop ) 
       INC SI    
       ; loop back to inner loop if CX >0, 
       LOOP LOOP2
       
       ; move from the safehouse back to CX, so it can decrement on iteration
       MOV CX,DI  
       ; loop back to outer loop
       LOOP LOOP1   
       
      ; printing msg3 m3
      MOV AH,09H
      MOV DX,OFFSET M3
      INT 21H           
      
      ; make SI=0
      MOV SI,OFFSET ARRAY
      ; set CL to N 
      MOV CL,N
      
      ; display loop
      DISPLAY:
      
      ; to prevent garbage value, set DH=0
      MOV DH,00H                          
      ; set DL = a[i]
      MOV DL,ARRAY[SI]
      ; add 30H to adjust for ascii change
      ADD DL,30H
      ; display it 
      MOV AH,02H    ; AH value is 02, disp from variable
      INT 21H                                           
      ; increment 'i'
      INC SI         
      ; loop back, decreases CX by 1   ; LOOPS only when CX>0
      LOOP DISPLAY              
      
      ; after all this is done
      JMP EXIT
      
      ; smooth exit
      EXIT:
        .EXIT          

 ; end of code
 END
