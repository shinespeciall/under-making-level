// @Description Add extra things into the Set Wario_ucPlace logic in Sub_801C1C0_LoadNewRoom()
// @HookAddress 0x1C476
// directly hook inside the Atari function pointer table
// @HookString 7846 09308646 03480047 0000034a 00480047 99c40108 P 98180003

/* Patch & Hook details
.thumb
    .dcb 1
    mov r0, pc
    add r0, #9
    mov lr, r0         @ set r14 as the return addr
    ldr r0, .DATA + 4
    bx r0              @ jump to the new function
    .dcb 1
.L1:
    ldr r2, .DATA + 8  @ r2 = Wario_ucReact
    ldr r0, .DATA
    bx r0
.DATA:
    .word 0x0801C499
    .word 0xAAAAAAAA
    .word 0x03001898
 */

/**
 * changelog: 
 * create the patch.
 *            ---- by ssp (shinespeciall), 2022/11/13
 */

#define cPauseFlag (*(volatile char*) 0x3000C35)

#define Wario_ucReact (*(volatile unsigned char*) 0x3001898)
#define Wario_ucStat (*(volatile unsigned char*) 0x3001899)
#define Wario_ucReact_ucStat (*(volatile unsigned short*) 0x3001898)
#define Wario_ucPlace (*(volatile unsigned char*) 0x30018B2)
#define Wario_ucAnmPat (*(volatile unsigned char*) 0x30018B7)

#define ucGateFlg (*(volatile unsigned char*) 0x30031BE)


unsigned int Sub_801C1C0_LoadNewRoom_Set_Wario_ucPlace()
{
    if (Wario_ucReact == 0 && Wario_ucStat == 0x31)
    {
        Wario_ucStat = 50;
        Wario_ucAnmPat = 0;
        ucGateFlg = 0;
    }

    // custom if statement to make it won't stop wario rolling on some enemy when unpause
    if (Wario_ucPlace == 1 && cPauseFlag == 0)
    {
        Wario_ucPlace = 2;
    }
}
