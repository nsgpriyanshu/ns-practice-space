LXI H, 3002H     ; Start from delete position
MVI C, 02H       ; Number of shifts

LOOP: INX H
      MOV A, M   ; Load next element
      DCX H
      MOV M, A   ; Move left
      INX H
      DCR C
      JNZ LOOP

HLT