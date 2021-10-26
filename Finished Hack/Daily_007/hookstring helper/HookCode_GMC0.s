.thumb
    ldr r0, .DATA
    mov lr, r0
    ldr r0, .DATA + 4
    bx r0
.DATA:
    .word 0x0801B929
    .word 0xAAAAAAAA