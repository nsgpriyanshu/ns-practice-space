LDA 3001H      ; Load tens digit
MOV B, A

MVI A, 00H     ; Clear A (result)
MVI C, 0AH     ; 10

LOOP: ADD C
      DCR B
      JNZ LOOP

MOV D, A       ; Save tens*10

LDA 3002H      ; Load units
ADD D

STA 3003H      ; Store binary result

HLT