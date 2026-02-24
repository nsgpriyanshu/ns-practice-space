LDA 3000H      ; Load first number into A
MOV B, A       ; Save first number

LDA 3001H      ; Load second number
CMP B          ; Compare A with B

JZ EQUAL       ; If Zero flag = 1
JC LESS        ; If Carry = 1

; If here → First > Second
MVI A, 01H
STA 3002H
HLT

EQUAL: MVI A, 02H
       STA 3002H
       HLT

LESS:  MVI A, 03H
       STA 3002H
       HLT