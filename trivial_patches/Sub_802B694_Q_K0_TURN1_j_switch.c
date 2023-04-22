// @Description Sub_802B694_Q_K0_TURN1_j_switch wrapper
// @HookAddress 0x2B696
// @HookString 0248 86460248 0047c046 0fb70208 P
// @EntryFunctionSymbol Sub_802B694_Q_K0_TURN1_j_switch

/** Patch & Hook details:
.thumb
    .dcb 1
    ldr r0, .DATA
    mov lr, r0
    ldr r0, .DATA + 4
    bx r0
    .dcb 1
.DATA:
    .word 0x0802B70F
    .word 0xAAAAAAAA
 */

/**
 * changelog: 
 * create the patch.
 * Notice: i cannot find some easy way to respawn enemy on the current screen easily.
 * so, you had better put the frogswitch in a single room, and let wario use a door after pressing frog switch.
 * then you can see all the regular enemy revive in every Room in the current Level.
 *            ---- by ssp (shinespeciall), 2023/4/22
 */

enum
{
    Q_INITIAL,
    Q_INITIAL2,
    Q_INITIAL3,
    Q_INITIAL4,
    Q_INITIAL5,
    Q_INITIAL6,
    Q_INITIAL7,
    Q_INITIAL8,
    Q_INITIAL9,
    Q_INITIAL10,
    Q_INITIAL11,
    Q_INITIAL12,
    Q_INITIAL13,
    Q_INITIAL14,
    Q_INITIAL15,
    Q_K0_WALK,
    K0_WALK,
    Q_K0_TURN1,
    K0_TURN1,
    Q_K0_TURN2,
    K0_TURN2,
    Q_K0_TURN3,
    K0_TURN3,
    Q_JITTO,
    JITTO,
    Q_TOBIOKI,
    TOBIOKI,
    Q_N_RAKKA_V,
    N_RAKKA_V,
    Q_H_RAKKA_V,
    H_RAKKA_V,
    Q_K2_LEFT,

    K2_LEFT,
    Q_K2_RIGHT,
    K2_RIGHT,
    Q_K1_LEFT,
    K1_LEFT,
    Q_K1_RIGHT,
    K1_RIGHT,
    Q_K6_LEFT,
    K6_LEFT,
    Q_K6_RIGHT,
    K6_RIGHT,
    Q_HIKKURI_L,
    HIKKURI_L,
    Q_HIKKURI_R,
    HIKKURI_R,
    Q_H_JITABAT,

    H_JITABAT,
    Q_K5_HIP,
    K5_HIP,
    Q_K4_LEFT,
    K4_LEFT,
    Q_K4_RIGHT,
    K4_RIGHT,
    Q_BOUND1_L,
    BOUND1_L,
    Q_BOUND2_L,
    BOUND2_L,
    Q_BOUND3_L,
    BOUND3_L,
    Q_BOUND1_R,
    BOUND1_R,
    Q_BOUND2_R,

    BOUND2_R,
    Q_BOUND3_R,
    BOUND3_R,
    Q_NH_RAKKA_L,
    NH_RAKKA_L,
    Q_NH_RAKKA_R,
    NH_RAKKA_R,
    Q_H_RAKKA_L,
    H_RAKKA_L,
    Q_H_RAKKA_R,
    H_RAKKA_R,
    Q_JISHINTOBI1,
    JISHINTOBI1,
    JISHINTOBI2,
    JISHINTOBI3,
    Q_K2D_LEFT,

    Q_K2D_RIGHT,
    Q_K3_LEFT,
    K3_LEFT,
    Q_K3_RIGHT,
    K3_RIGHT,
    Q_LF_MOVE_R,
    LF_MOVE_R,
    Q_LF_MOVE_L,
    LF_MOVE_L,
    Q_NAGE_L,
    NAGE_L,
    Q_NAGE_R,
    NAGE_R,
    Q_TNAGE_L,
    TNAGE_L,
    Q_TNAGE_R,

    TNAGE_R,
    Q_UNAGE_L,
    UNAGE_L,
    Q_UNAGE_R,
    UNAGE_R,
    Q_UTNAGE_L,
    UTNAGE_L,
    Q_UTNAGE_R,
    UTNAGE_R,
    Q_TD_ATA_R,
    Q_TD_ATA_L,
    Q_SOKUSI,
    Q_K5_HIP2,
    K5_HIP2,
    Q_T_AUX_0,
    T_AUX_0,
    Q_T_AUX_1,
    T_AUX_1,
    Q_T_AUX_2,
    T_AUX_2,
    Q_T_AUX_3,
    T_AUX_3,
    Q_T_AUX_4,
    T_AUX_4,
    Q_T_AUX_5,
    T_AUX_5,
    Q_T_AUX_6,
    T_AUX_6,
};

struct EnemyDataStructure {
    unsigned short CurEnemy_usStatus;
    unsigned char pAnmData1;
    unsigned char pAnmData2;
    unsigned long OAMDataPackPointerForCurrentAnimation;
    unsigned short CurEnemy_YPos;
    unsigned short CurEnemy_XPos;
    unsigned short CurEnemy_AffinePA;
    unsigned short CurEnemy_AffinePB;
    unsigned short CurEnemy_AffinePC;
    unsigned short CurEnemy_AffinePD;
    unsigned short CurEnemy_CurrentAnimationFrameId;
    unsigned char CurEnemy_RealFrameCountForCurrentAnimationFrame;
    unsigned char CurEnemy_GlobalId;
    unsigned char CurEnemy_RoomEntitySlotId;
    unsigned char CurEnemy_ucChrOfs;
    unsigned char CurEnemy_Prio;
    unsigned char CurEnemy_paletteId;
    unsigned char CurEnemy_CurrentAnimationId;
    unsigned char CurEnemy_Life;
    unsigned char CurEnemy_GuardAndDamageParam;
    unsigned char CurEnemy_DisableInteractionWithWarioCountdown;
    unsigned char CurEnemy_SizeY0_Bottom;
    unsigned char CurEnemy_SizeY1_Top;
    unsigned char CurEnemy_SizeX_LeftRight;
    unsigned char CurEnemy_HitboxY0;
    unsigned char CurEnemy_HitboxY1;
    unsigned char CurEnemy_HitboxX0;
    unsigned char CurEnemy_HitboxX1;
    unsigned char CurEnemy_TWork0;
    unsigned char CurEnemy_TWork1;
    unsigned char CurEnemy_TWork2;
    unsigned char CurEnemy_TWork3;
    unsigned char CurEnemy_padding;
};

// global variables
// 00(Entry) 01(Emerald) 02(Ruby) 03(Topaz) 04(Sapphire) 05(Golden) 06(Sound Room)
#define CurrentPassage (*(volatile unsigned char*) 0x3000002)
// 00(first lvl) 01(second lvl) 02(third lvl) 03(fourth lvl) 04(Boss) 05(Mini-Game Shop)
#define CurrentLevel (*(volatile unsigned char*) 0x3000003)
#define CurrentRoom (*(volatile unsigned char*) 0x03000024)
#define MapSw ((volatile unsigned char*) 0x300002E)
#define ucBgCountDown (*(volatile unsigned char*) 0x03000035)
#define ucTimeUp (*(volatile unsigned char*) 0x03000047)

#define ENTITIES ((volatile struct EnemyDataStructure*) 0x3000104)
#define CurrentEnemyData (*(volatile struct EnemyDataStructure *)0x3000A24)

#define EntityStateSlotInRoom ((volatile unsigned char*) 0x3000564)

#define iGmTimeFrame (*(volatile unsigned int *)0x03000BEC)

#define ucGmTime_Tflg (*(volatile unsigned char*) 0x03000C01)
#define ucGmScore_Tflg (*(volatile unsigned char*) 0x03000C02)
#define ucGmTimeCc_Tflg (*(volatile unsigned char*) 0x03000C03)

#define ucJSwitchOnFlg (*(volatile unsigned char*) 0x03000C0D)

#define usBg1Hofs_CameraXPos (*(volatile short*) 0x300187A)
#define usBg1Vofs_CameraYPos (*(volatile short*) 0x300187C)

#define Wario_usPosX (*(volatile short*) 0x30018AA) // rightwards positive
#define Wario_usPosY (*(volatile short*) 0x30018AC) // downwards positive

// fucntions
#define Sub_8001ED8_m4aMPlayAllStop ((void (*)()) 0x8001ED9)
#define Sub_801E1C0_EnemyMapOutStartScreen ((void (*)()) 0x801E1C1)
#define Sub_801E258_EnemyMapOutOutOfScreen ((void (*)(int)) 0x801E259)

#define Sub_80766E8_TOptObjSet ((void (*)(unsigned short, unsigned short, char)) 0x80766E9)

void Sub_802B694_Q_K0_TURN1_j_switch()
{
    // vanilla code to do frog switch job
    EntityStateSlotInRoom[64 * CurrentRoom + CurrentEnemyData.CurEnemy_RoomEntitySlotId] = 33;
    CurrentEnemyData.CurEnemy_GuardAndDamageParam = 29;
    CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = 0x83B59FC;
    CurrentEnemyData.CurEnemy_RealFrameCountForCurrentAnimationFrame = 0;
    CurrentEnemyData.CurEnemy_CurrentAnimationFrameId = 0;
    CurrentEnemyData.CurEnemy_CurrentAnimationId = K0_TURN1;
    CurrentEnemyData.CurEnemy_TWork0 = 13;
    ucJSwitchOnFlg = 1;
    ucBgCountDown = 1;
    MapSw[4] = 2;
    ucTimeUp = 1;
    iGmTimeFrame = 0;
    ucGmTime_Tflg = 3;
    ucGmTimeCc_Tflg = 2;
    Sub_80766E8_TOptObjSet(200, 384, 78);
    Sub_80766E8_TOptObjSet(Wario_usPosY - usBg1Vofs_CameraYPos, Wario_usPosX - (usBg1Hofs_CameraXPos + 64), 79);
    Sub_8001ED8_m4aMPlayAllStop();

    // custom logic to revive all the enemy in all Rooms on the current Level
    /**
     * logic from https://github.com/wario-land/WL4Editor, LevelComponents/Level.cpp
     */
    unsigned char *p_rom = 0x8000000;
    int offset = 0x6391C4 + CurrentPassage * 24 + CurrentLevel * 4;
    int levelHeaderIndex = *((unsigned int*)(p_rom + offset));
    int levelHeaderPointer = 0x639068 + levelHeaderIndex * 12;
    unsigned char *levelHeaderData = p_rom + levelHeaderPointer;
    int roomCount = levelHeaderData[1];

    // revive all the sprites from the ram
    for (int j = 0; j < roomCount; ++j)
    {
        unsigned char *p_EntityStateSlotInRoom = &EntityStateSlotInRoom[64 * j];
        for (int i = 0; i < 64; ++i)
        {
            // if the current enemy is dead
            if (*p_EntityStateSlotInRoom == 2)
                // revive it
                *p_EntityStateSlotInRoom = 1;
                p_EntityStateSlotInRoom++;
        }
    }

    // no, this part of stuff seems cannot work
    // Sub_801E1C0_EnemyMapOutStartScreen();
    // Sub_801E258_EnemyMapOutOutOfScreen(1);
    // Sub_801E258_EnemyMapOutOutOfScreen(2);
}
