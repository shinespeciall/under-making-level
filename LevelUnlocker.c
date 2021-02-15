// @Description patch the passage scene's runtime code to unlock levels without playing them
// @HookAddress 0x7A0B8
// @HookString 01 48 86 46 01 48 00 47 6B A3 07 08 P C0 46 C0 46 C0 46 C0 46 C0 46 C0 46
// Mode: Thumb
// the hook logic is copied from beco's WL4_TA/patches/TimeAttack_SeisanSavePatch.c, made by ssp

// Data
#define	KEY_L		0x200 // L
#define	KEY_R		0x100 // R
#define	KEY_A		0x001 // A
#define	KEY_B		0x002 // B
#define	KEY_DOWN	0x080 // Down
#define	KEY_UP		0x040 // Up
#define	KEY_LEFT	0x020 // Left
#define	KEY_RIGHT	0x010 // Right
#define	KEY_START	0x008 // Start
#define	KEY_SELECT	0x004 // Select
#define	KEY_ALL		0x3FF // Any key

// IRAM
#define PassageID (*(volatile unsigned char*) 0x3000002)
#define InPassageLevelID (*(volatile unsigned char*) 0x3000003)
#define ucSaveFlg (*(volatile unsigned char*) 0x3000013)
#define sGameSeq (*(volatile unsigned char*) 0x3000C3C)
#define W4ItemStatus ((volatile unsigned char*) 0x3000A68)
#define ADDR_KEY_4 (*(volatile unsigned short*) 0x3001848)

// Subroutine
#define sub_80845F0 ((int (*)()) 0x80845F1)
#define sub_807A700 ((int (*)()) 0x807A701)
#define sub_8001DA4_m4aSongNumStart ((void (*)(int)) 0x8001DA5)
#define Sub_8073880_SramBackup_Auto_Write ((void (*)()) 0x8073881)

void PassageSceneRuntime()
{
    // --------------- Vanilla code ---------------
    if (sub_80845F0() && sub_807A700())
    {
        sGameSeq = 0x24;
    }

    // ---------------  Custom code ---------------
    // unlock the next level if possible
    if (ADDR_KEY_4 == KEY_SELECT)
    {
        if(InPassageLevelID <= 3)
        {
            if(!PassageID || PassageID == 5)
            {
                W4ItemStatus[4 * InPassageLevelID + 24 * PassageID] = 0x2f;
            }
            else
            {
                W4ItemStatus[4 * InPassageLevelID + 24 * PassageID] = 0x3f;
            }
            sGameSeq = 0x25; // animation to unlock next level
            sub_8001DA4_m4aSongNumStart(210);
            Sub_8073880_SramBackup_Auto_Write();
            ucSaveFlg = 1; // dk why they set this in vanilla save functions, i just followed it
        }
    }
}