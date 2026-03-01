LXI H, 3004H     ; Point to last element
MVI C, 02H       ; Number of shifts needed

LOOP: MOV A, M   ; Load current element
      INX H
      MOV M, A   ; Move to next position
      DCX H
      DCX H      ; Move back two positions
      DCR C
      JNZ LOOP

MVI A, 99H
STA 3002H        ; Insert new element

HLT