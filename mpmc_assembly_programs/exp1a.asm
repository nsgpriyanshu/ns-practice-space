LDA 2000H     ; Load first number into A
MOV B, A      ; Move to B (optional clarity)

LDA 2001H     ; Load second number
ADD B         ; A = A + B

STA 2002H     ; Store result

HLT