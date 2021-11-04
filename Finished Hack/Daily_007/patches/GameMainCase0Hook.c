// @Description a Hook on the GameMain function's case 0 routine
// @HookAddress 0x1B908
// Mode: Thumb
// Made by ssp(shinespeciall)

// Changelog:
// v1.0 on 2021/10/26 by ssp
// implement switch reset and enemy revive

// v1.1 on 2021/11/4  by ssp
// fix the switch reset be triggered when pause and unpause in game


/** starts from 1B908, no alignment byte needed
 *  ends at 1B928 with a branch instruction to jump out
 * .thumb
    ldr r0, .DATA
    mov lr, r0
    ldr r0, .DATA + 4
    bx r0
 * .DATA:
    .word 0x0801B929
    .word 0xAAAAAAAA
 * 
 * Hook String generated by gcc: 01488646 01480047 29b90108 aaaaaaaa
 * 1B908 + 4 * 4 = 1B918
 * 1B928 = 1B918 = 4 * 4
 * @HookString 01488646 01480047 29b90108 P C046C046 C046C046 C046C046 C046C046
 */

#define cGmStartFlg (*(volatile unsigned char*) 0x3000C3F)
#define ucDemoSwitch ((volatile unsigned char*) 0x3001894)

// 5 map switches in total
#define MapSw ((volatile unsigned char*) 0x300002E)

// 00(Entry) 01(Emerald) 02(Ruby) 03(Topaz) 04(Sapphire) 05(Golden) 06(Sound Room)
#define CurrentPassage (*(volatile unsigned char*) 0x3000002)
// 00(first lvl) 01(second lvl) 02(third lvl) 03(fourth lvl) 04(Boss) 05(Mini-Game Shop)
#define CurrentLevel (*(volatile unsigned char*) 0x3000003)
#define CurrentRoom (*(volatile unsigned char*) 0x03000024)

// from 0x3000564 to 0x3000964
#define EntityStateSlotInRoom ((volatile unsigned char*) 0x3000564)

//OFF 0, ON 1, RETURN 2, RETIRE 3, SAVE 4
#define cPauseFlag (*(volatile signed char*) 0x3000C35)

#define Sub_8010438_GmDemoKey_Init ((void (*)()) 0x8010439)
#define Sub_8010404_GmDemoKey_Auto2 ((int (*)()) 0x8010405)
#define Sub_801C1C0_LoadNewRoom ((void (*)()) 0x801C1C1)

// since some routine in Case3 in GameMain() will set sGameSeq = 0, so we need to skip those case(s)
void GameMainCase0Hook()
{
    // custom code part 1, have to be in front of the vanilla code
    // or EntityStateSlotInRoom reset cannot work on the first run
    // Enemies can revive when Wario goes into some Room(s) again
    // 0x3000964 - 0x3000564 = 0x400
    // Entry Passage - Level 0
    if (!CurrentPassage && !CurrentLevel && !cPauseFlag)
    {
        // Room 2
        if (CurrentRoom == 2)
        {
            unsigned char *p_EntityStateSlotInRoom = &EntityStateSlotInRoom[64 * CurrentRoom];
            for (int i = 0; i < 64; ++i)
            {
                // if the current enemy is dead
                if (*p_EntityStateSlotInRoom == 2)
                    // revive it
                    *p_EntityStateSlotInRoom = 1;
                    p_EntityStateSlotInRoom++;
            }
        }
    }

    // custom code part 2. cPauseFlag will be reset to 0 in vanilla code
    // have to be in front of the vanilla code
    // toggle off the MapSw[1] and MapSw[2] every time when loading a new Room
    if (!cPauseFlag)
    {
        MapSw[1] = 0;
        MapSw[2] = 0;
    }

    // Vanilla code
    if ( !cGmStartFlg )
        Sub_8010438_GmDemoKey_Init();
    if ( ucDemoSwitch[0] == 2 )
        Sub_8010404_GmDemoKey_Auto2();
    Sub_801C1C0_LoadNewRoom();
}
