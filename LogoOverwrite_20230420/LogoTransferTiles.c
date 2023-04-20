// @Description Overwrite the tile transfer to vram for WL4 logo in scene 5
// @HookAddress 0x5F70
// from 0x5F70 to 0x5F98
// @HookString 78460730 86460348 00470349 00480047 19630008 P 602c0003

/* Patch & Hook details
.thumb
    mov r0, pc
    add r0, #7
    mov lr, r0         @ set r14 as the return addr
    ldr r0, .DATA + 4
    bx r0              @ jump to the new function
.L1:
    ldr r1, .DATA + 8  @ r1 = sLocalSeq
    ldr r0, .DATA
    bx r0
.DATA:
    .word 0x08006319
    .word 0xAAAAAAAA
    .word 0x03002C60
 */

/**
 * changelog: 
 * directly modified from the IDA pro's generated C code.
 * make the hookstring, add the vanilla logic for LogoTransferTiles() function
 *            ---- by ssp (shinespeciall), 2022/09/27
 */

extern const unsigned char logoTiles[16384];
extern const unsigned char logoMap[1024];
extern const unsigned char logoPal[32];

#define Sub_8003224_LZ77UnCompVram ((void (*)(unsigned int src, unsigned int dst)) 0x8003225)

void LogoTransferTiles()
{
    // this is the background and foreground tiles
    Sub_8003224_LZ77UnCompVram(0x829443C, 0x6000000u);

    // this is for the logo, rewrite as you like
    // Sub_8003224_LZ77UnCompVram(0x8295954, 0x6004000u);
    memcpy(0x6004000, logoTiles, 16384);
}