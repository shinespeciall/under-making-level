// @Description code will be excute once every frame, modified from UnlimitedRockBouncing
// @HookAddress 0x6C75E
// Mode: Thumb
// Made by Goldensunboy, ssp(shinespeciall)
// Verison 1
// P.S. I make changes to the code frequently, so the version is only some kind of release number record -- ssp

/* Hook details
------------------------- this only works when the new function push lr at first and bx lr at last.
0x806C75E: LDR R0, 0x806C767    | 4803
0x806C760: MOV LR, R0           | 4686
0x806C762: LDR R0, pointer      | 4801
0x806C764: BX R0                | 4700
0x806C766: B 0x806C770          | E002
0x806C768: .fill a pointer      | 0XXXXXXX ; end with 1 (in binary) to make it run in thumb mode
0x806C76C: .fill 67C70608       | 0806C767 ; end with 1 (in binary) to make it run in thumb mode
0x806C770: nop                  | 46C0     ; i.e. mov r8, r8
0x806C772: nop....
-------------------------
Hook String:
@HookString 03 48 86 46 01 48 00 47 02 E0 P 67 C7 06 08 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46
count:                                     ^14                                                                     ^38
Hook length: 38 Bytes
*/

struct OAM_REC {
    char PAD[2];
    unsigned char EntityID;
};

#define OAM ((volatile struct OAM_REC*) 0x3000964)

struct ENTITY_REC {
    char PAD1;
    unsigned char CollisionFlag;
    char PAD2[0x15];
    unsigned char EntityID;
    char PAD3[0x14];
};

#define ENTITIES ((volatile struct ENTITY_REC*) 0x03000104)
#define GameState (*(volatile unsigned char*) 0x3000C3C)
#define unk_300001B (*(volatile unsigned char*) 0x300001B)
#define unk_3000046 (*(volatile unsigned char*) 0x3000046)
#define sub_806E08C ((void (*)()) 0x806E08D)

#define WarioState (*(volatile unsigned char*) 0x3001898)
#define WarioAnimation (*(volatile unsigned char*) 0x3001899)
#define WarioXPos (*(volatile unsigned short*) 0x30018AA)
#define WarioYPos (*(volatile unsigned short*) 0x30018AC)
#define WarioInvincibility (*(volatile unsigned char*) 0x300189C)
#define uknown_counter (*(volatile unsigned char*) 0x30018A2)
#define word_30018CE (*(volatile unsigned short*) 0x30018CE)
#define word_30018CC (*(volatile unsigned short*) 0x30018CC)
#define Layer0_DecompressedDataPointer (*(volatile unsigned int*) 0x3000054)
#define CurrentTileset_EventIdTablePointer (*(volatile unsigned int*) 0x30031FC)
#define Layer0_Width (*(volatile unsigned short*) 0x3000058)
#define CurrentRoomHeader_Layer0MappingType (*(volatile unsigned char*) 0x3000075)

#define myflag_Iscounting (*(volatile unsigned char*) 0x30000E6)

#define cGmStartFlg (*(volatile unsigned char*) 0x3000C3F)
#define cPauseFlag (*(volatile unsigned char*) 0x3000C35)
#define soft_reset (*(volatile unsigned char*) 0x300001E)
#define ADDR_KEY_4 (*(volatile unsigned short*) 0x3001848)


__attribute__((no_caller_saved_registers))
void FrameOperations()
{
    // vanilla code for animated tiles loading
    if ( (GameState == 2 || GameState == 6 || GameState == 4 && unk_300001B == 1) && !unk_3000046 )
    {
        sub_806E08C();
    }

    // Process all active entities
    for(int i = 0; i < 24; ++i)
    {
        // End when the last active entity has passed
        if (OAM[i].EntityID == 0xFF)
        {
            break;
        }

        // If it is a rock, set its bounce state
        switch(ENTITIES[i].EntityID)
        {
            case 0x15: // Rock
            case 0x80: // Arewo Shitain-Hakase
            ENTITIES[i].CollisionFlag = 1;
        }
    }

    // Set Wario state to normal when getting out from water
    // Still unstable on both edge
    // Wario can walk into the water without changing state, need to fix too
    if(WarioState == 1 && CurrentRoomHeader_Layer0MappingType == 0x10 && (WarioAnimation == 4 || WarioAnimation == 3))
    {
        int v20 = (((unsigned short)word_30018CE << 16 >> 17) + (unsigned short)WarioXPos) >> 6;// wario x
        int v21 = (((unsigned short)word_30018CE << 16 >> 17) + (unsigned short)WarioXPos - 0x8) >> 6;
        int v0 = (((unsigned short)word_30018CC << 16 >> 17) + (unsigned short)WarioYPos + 0x40) >> 6;// wario y
        int v6 = *(unsigned short*)(2 * *(unsigned short*)(2 * (v0 * Layer0_Width + v20) + Layer0_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
        int v8 = *(unsigned short*)(2 * *(unsigned short*)(2 * (v0 * Layer0_Width + v21) + Layer0_DecompressedDataPointer) + CurrentTileset_EventIdTablePointer);
        if(v6 == 0)
        {
            WarioState = 0;
            WarioAnimation = 0;
        } else if (v8 == 0) {
            WarioState = 0;
            WarioAnimation = 0;
        }
    }

    // Fix Wario gets stuck in the water when knock into spikes
    if (WarioState == 1 && WarioInvincibility == 1 && myflag_Iscounting == 0)
    {
        uknown_counter = 0x50; // not in the water using 0x40, in the water using 0x50
        myflag_Iscounting = 1;
    }
    if (WarioInvincibility == 0)
    {
        myflag_Iscounting = 0;
    }

    // Press L to trigger Debug Mod
    if(cGmStartFlg == 1 && cPauseFlag == 0 && soft_reset == 0)
    {
        if(ADDR_KEY_4 == 0x200)
        {
            if(GameState == 8)
            {
                GameState = 2;
            }
            else if(GameState == 2)
            {
                GameState = 8;
            }
        }
    }
}
