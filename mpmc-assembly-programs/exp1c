LDA 2200H      ; Load multiplicand
MOV B, A

LDA 2201H      ; Load multiplier
MOV C, A

MVI A, 00H     ; Clear accumulator (result)

LOOP: ADD B    ; Add multiplicand
      DCR C    ; Decrease counter
      JNZ LOOP ; Repeat until zero

STA 2202H      ; Store result

HLT