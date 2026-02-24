LDA 2300H      ; Load dividend
MOV B, A

LDA 2301H      ; Load divisor
MOV C, A

MVI D, 00H     ; Clear quotient

LOOP: MOV A, B
      CMP C
      JC END

      SUB C
      MOV B, A
      INR D
      JMP LOOP

END:  MOV A, D
      STA 2302H

HLT