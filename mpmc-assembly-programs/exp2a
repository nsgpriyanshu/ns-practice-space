LXI H, 3000H     ; Source
LXI D, 3100H     ; Destination
MVI C, 05H       ; Count = 5 bytes

LOOP: MOV A, M   ; Load source data
      STAX D     ; Store at destination
      INX H      ; Next source
      INX D      ; Next destination
      DCR C      ; Decrease count
      JNZ LOOP

HLT