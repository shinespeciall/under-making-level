// @Description hook at the tail of Sub_801BEA8_GmVblkIntr1_InGameUpdateWarioOAMAndSpritesTiles() since it force-set layer offset there per frame
// @HookAddress 0x1BF9A
// Mode: Thumb
// Made by ssp(shinespeciall)
// from 0x1BF9A to 0x1BFD7, no passed-in params for the vanilla function. i just copied the hookstring from somewhere else
// @HookString 024a 9646024a 10470000 d9bf0108 P

/* Patch & Hook details
 
 .thumb
    .dcb 1
    ldr r2, .DATA
    mov lr, r2
    ldr r2, .DATA + 4
    bx r2
    .dcb 1
  .DATA:
    .word 0x0801BFD9
    .word 0xAAAAAAAA
 */

#define REG_BG0HOFS (*(volatile unsigned int*) 0x4000010)
#define REG_BG0VOFS (*(volatile unsigned int*) 0x4000012)
#define REG_BG1HOFS (*(volatile unsigned int*) 0x4000014)
#define REG_BG1VOFS (*(volatile unsigned int*) 0x4000016)
#define REG_BG2HOFS (*(volatile unsigned int*) 0x4000018)
#define REG_BG2VOFS (*(volatile unsigned int*) 0x400001A)
#define REG_BG3HOFS (*(volatile unsigned int*) 0x400001C)
#define REG_BG3VOFS (*(volatile unsigned int*) 0x400001E)
#define REG_MOSAIC (*(volatile unsigned int*) 0x400004C)

#define word_30000A8 (*(volatile unsigned short*) 0x30000A8)
#define word_30000AA (*(volatile unsigned short*) 0x30000AA)
#define word_30000AC (*(volatile unsigned short*) 0x30000AC)
#define word_30000AE (*(volatile unsigned short*) 0x30000AE)
#define word_30000B0 (*(volatile unsigned short*) 0x30000B0)
#define word_30000B2 (*(volatile unsigned short*) 0x30000B2)
#define word_30000B4 (*(volatile unsigned short*) 0x30000B4)
#define word_30000B6 (*(volatile unsigned short*) 0x30000B6)
#define usBgMosaic (*(volatile unsigned short*) 0x3001860)

// my variables
#define unk_300001F (*(volatile unsigned char*) 0x300001F)

void Sub_801BEA8_GmVblkIntr1_CustomBgOffset()
{
    REG_MOSAIC = (16 * usBgMosaic) | usBgMosaic;  // LCD mosaic
    REG_BG0HOFS = word_30000A8;                   // BG0 X-offset
    REG_BG0VOFS = word_30000AA;                   // BG0 Y-offset
    REG_BG1HOFS = word_30000AC;                   // Similarly, i am lazy
    REG_BG1VOFS = word_30000AE;
    REG_BG2HOFS = word_30000B0;
    REG_BG2VOFS = word_30000B2;
    if(unk_300001F == 0)
    {
        REG_BG3HOFS = word_30000B4;
        REG_BG3VOFS = word_30000B6;
    }
}
