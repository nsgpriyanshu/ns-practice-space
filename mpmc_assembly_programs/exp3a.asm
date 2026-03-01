LDA 3000H      ; Load binary number
MOV B, A       ; Store in B

MVI C, 00H     ; C = tens counter
MVI D, 0AH     ; D = 10

LOOP: MOV A, B
      SUB D
      JC DONE

      MOV B, A
      INR C
      JMP LOOP

DONE: MOV A, C
      STA 3001H    ; Store tens

      MOV A, B
      STA 3002H    ; Store units

HLT