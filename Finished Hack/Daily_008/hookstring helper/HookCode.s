.thumb
    mov r0, r4 // passing param
    ldr r1, .DATA
    mov lr, r1
    ldr r1, .DATA + 4
    bx r1
    .dcb 1
.DATA:
    .word 0x08013D5D
    .word 0xAAAAAAAA