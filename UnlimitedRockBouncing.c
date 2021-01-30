// @Description Allows rocks to bounce infinitely
// @HookAddress 0x6C75E
// Mode: Thumb
// Made by Goldensunboy, ssp(shinespeciall)
// Verison 1.1

/**Changelog:
 * 1.1
 * Add Arewo Shitain-Hakase to the bouncing list
 * 
 * 1.0
 * Add basic logic and test the patch
 * /

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

__attribute__((no_caller_saved_registers))
void UnlimitedRockBouncing()
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
}
