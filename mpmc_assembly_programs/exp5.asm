LXI H, 4000H     ; Source (Peripheral buffer)
LXI D, 3000H     ; Destination (Memory)
MVI C, 05H       ; Number of bytes

LOOP: MOV A, M
      STAX D

      INX H
      INX D

      DCR C
      JNZ LOOP

HLT