// @Description rewrite Sub_80717E4_GameHblkIntrRASTER_BG3_B1 to custom layer 3 moving during the count down
// @HookAddress 0x716D0
// Mode: Thumb
// Made by ssp(shinespeciall)
// directly hook inside the switch case data part in Sub_8071600_GameHblkSet
// @HookString P

#define REG_VCOUNT (*(volatile unsigned short*) 0x4000006)

#define REG_BG3HOFS (*(volatile unsigned int*) 0x400001C)
#define REG_BG3VOFS (*(volatile unsigned int*) 0x400001E)


#define word_30000B4 (*(volatile unsigned short*) 0x30000B4)
#define word_30000B6 (*(volatile unsigned short*) 0x30000B6)

#define sHblkBuf1 ((volatile unsigned short*) 0x300342E)

// my variables
#define unk_300001F (*(volatile unsigned char*) 0x300001F)

void Sub_801BEA8_GmVblkIntr1_CustomBgOffset()
{
    int result = sHblkBuf1[REG_VCOUNT] + word_30000B4;
    if(unk_300001F == 0)
    {
        REG_BG3HOFS = sHblkBuf1[REG_VCOUNT] + word_30000B4;
        REG_BG3VOFS = 16 * 2;
    }
    else
    {
        REG_BG3HOFS = 0;
        REG_BG3VOFS = 0;
    }
    return result;
}
