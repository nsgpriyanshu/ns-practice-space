LDA 3000H      ; Load first value
MOV B, A       ; Store in B (temporary)

LDA 3001H      ; Load second value
STA 3000H      ; Store into first location

MOV A, B       ; Get first value back
STA 3001H      ; Store into second location

HLT