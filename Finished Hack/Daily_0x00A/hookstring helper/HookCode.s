.thumb
    @ .dcb 1
    push {r0-r3} @ start at 0x6FE68, keep r0 be the tile event id and pass it into the patch function
    ldrh r2, [r4] @ param 2 of Sub_806DDE4_PanelPartWork_Warp_DoorType2
    mov r1, r7
    lsr r1, #16 @ param 1 of Sub_806DDE4_PanelPartWork_Warp_DoorType2
    add r3, pc, #4
    add r3, #3
    mov lr, r3
    ldr r3, .DATA
    bx r3
    lsr r0, #16 @ deal with the return value from the patch function call
    cmp r0, #0 @ if (the return value & 0xFF0000) > 0
    pop {r0-r3}
    bhi .DATA + 10
    ldr r1, .DATA + 4 @ jump to the ret routine of the current function
    bx r1
    .dcb 1
.DATA:
    @ .word 0x0806FE93 @ following logic in the vanilla function
    .word 0xAAAAAAAA
    .word 0x0806FF53 @ ret

@ Contents of section .text:
@  0000 0fb42288 391c090c 01a30333 9e46044b  ..".9......3.F.K
@  0010 1847000c 00280fbc 07d80249 08470000  .G...(.....I.G..
@  0020 aaaaaaaa 53ff0608                    ....S...
