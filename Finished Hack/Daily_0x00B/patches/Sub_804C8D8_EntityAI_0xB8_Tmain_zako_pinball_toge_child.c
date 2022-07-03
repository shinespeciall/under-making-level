// @Description modify Sub_804C8D8_EntityAI_0xB8_Tmain_zako_pinball_toge_child, called by AI no. 0x5E
// @HookAddress 0x4C8DA
// from 0x6D4C2 to 0x4C90C, no passed-in param for the vanilla function
// @HookString 0248 86460248 00470000 0dc90408 P

/* Patch & Hook details
 
.thumb
    .dcb 1
    ldr r0, .DATA
    mov lr, r0
    ldr r0, .DATA + 4
    bx r0
    .dcb 1
.DATA:
    .word 0x0804C90D
    .word 0xAAAAAAAA
 */

/**
 * changelog: 
 * directly modified from the IDA pro's generated C code.
 *            ---- by ssp (shinespeciall), 2022/07/01
 */

enum enemyAnimationType{
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

enum THantei_enum{
    NO_ATA_H,
    NO_TOGE,
    NO_TOGE2_H,
    MAE_TOGE,
    MAE_TOGE2_H,
    MOTSU,
    L_COIN,
    FLOWER_H,
    ALL_TOGE,
    ALL_TOGE2,
    ALL_TOGE3,
    ALL_TOGE4,
    ALL_TOGE5,
    ALL_TOGE_BOSS_H,
    ALL_MOERU,
    ALL_DEBU,
    ALL_ZONBI,
    ALL_ZONBI2,
    ALL_YUKI,
    ALL_BAT_H,
    ALL_ICE_H,
    OTAFUKU_H,
    TUMIKI_4_H,
    NORU_HAKO,
    NORU_HAKO2,
    NORU_HAKO_NH,
    NORU_HAKO2_NH,
    NORU_YUKA_1,
    NORU_YUKA_1ND,
    NORU_YUKA_1A,
    D_MOAI_H1,
    D_MOAI_H2,
    S_BIRD_H1,
    UE_TOGE,
    PROPERA_H,
    HARIMEN_H1,
    HARIMEN_H2,
    MAE_UE_TOGE,
    USHIRO_UE_TOGE,
    ALL_BALLOON,
    ALL_BALLOON_BOSS_H,
    BIG_MARUMEN_H,
    BIG_MARUMEN_H2,
    BIG_MARUMEN_H3,
    PUUTIN_H,
    PUUTIN2_H,
    SHITA_TOGE,
    SHITA_MAE_TOGE_H,
    J_SWITCH_H,
    HATI_H,
    HATI2_H,
    SHITA_BANE_H,
    SHITA_MAE_BANE_H,
    MENISI_H,
    ROULETTE_H,
    TOBAWANI_UE_TOGE_H,
    ALL_TOGE_MAGMA_H,
    MAE_ALL_TOGE_H,
    MAE_ALL_TOGE_N_H,
    UE_TOGE_MOTSU_TOGEDON_H,
    FURAWANA_HEAD_H,
    ALL_ZONBI_MODORI_H,
    TUNAMI_H,
    DORAMORI_H,
    DORAMORI2_H,
    DORAMORI_HEAD_H,
    KONTOGE_SHABERU_H,
    KONTOGE_SHABERU_H2,
    KONTOGE_SHABERU_H3,
    ALL_TOGE_ZERO_H,
    PIYO_BOMB_H,
    KONTOGE_OYA_H,
    MOUJA_OMEN_H,
    MOUJA_FACE_H,
    ALL_AWA,
    MAE_UE_TOGE_WH,
    SHITA_MIGI_TOGE_WH,
    UE_MIGI_TOGE_WH,
    SHELL_WH,
    TOBAWANI_WH,
    TOBAWANI_NOTOGE_WH,
    ALL_TOGE_WH,
    ALL_HAJIKU_WH,
    DORIZAME_WH,
    DORIZAME2_WH,
};

struct EnemyDataStructure {
    unsigned short CurEnemy_usStatus;
    unsigned char pAnmData1;
    unsigned char pAnmData2;
    unsigned int OAMDataPackPointerForCurrentAnimation;
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

#define CurrentEnemyData (*(volatile struct EnemyDataStructure*) 0x3000A24)

// 00(Entry) 01(Emerald) 02(Ruby) 03(Topaz) 04(Sapphire) 05(Golden) 06(Sound Room)
#define CurrentPassage (*(volatile unsigned char*) 0x3000002)
// 00(first lvl) 01(second lvl) 02(third lvl) 03(fourth lvl) 04(Boss) 05(Mini-Game Shop)
#define CurrentLevel (*(volatile unsigned char*) 0x3000003)
#define CurrentRoom (*(volatile unsigned char*) 0x03000024)

enum {
    YK_NASHI,    //00: nothing
    YK_MIZU,    //01: inside water
};

#define Terrain_usKoka_SolidOrWater (*(volatile unsigned short*) 0x30000A2)
#define ucThit1 (*(volatile unsigned char*) 0x3000A50)
#define ucThit2 (*(volatile unsigned char*) 0x3000A51)

#define Sub_8023A60_DropCorrectedBgAttact ((unsigned int (*)(int, int)) 0x8023A61)

void Sub_804C8D8_EntityAI_0xB8_Tmain_zako_pinball_toge_child()
{
    if ( CurrentEnemyData.CurEnemy_CurrentAnimationId == K0_WALK )
    {
        // moving logic
        // if ( CurrentEnemyData.CurEnemy_TWork0 ) // raise up and prepare for emitting
        // {
        //     --CurrentEnemyData.CurEnemy_TWork0;
        //     --CurrentEnemyData.CurEnemy_RealFrameCountForCurrentAnimationFrame;
        //     CurrentEnemyData.CurEnemy_YPos -= 2;
        // }
        // else // emitting and dropping
        {
            Sub_8023A60_DropCorrectedBgAttact(CurrentEnemyData.CurEnemy_YPos, CurrentEnemyData.CurEnemy_XPos);
            if ( Terrain_usKoka_SolidOrWater == YK_MIZU || (ucThit1 & 0xF) != 0 )
            {
                CurrentEnemyData.CurEnemy_CurrentAnimationId = Q_K5_HIP;
            }
            else
            {
                if (!(CurrentEnemyData.CurEnemy_padding & 4))  // set CurEnemy_padding |= 2 to disable goes up and down
                {
                    if (CurrentEnemyData.CurEnemy_padding & 1)
                    {   // go up
                        CurrentEnemyData.CurEnemy_YPos -= CurrentEnemyData.CurEnemy_TWork2;
                    }
                    else
                    {   // go down by default
                        CurrentEnemyData.CurEnemy_YPos += CurrentEnemyData.CurEnemy_TWork2;
                    }
                }
                

                if (!(CurrentEnemyData.CurEnemy_padding & 2)) // set CurEnemy_padding |= 2 to disable goes left and right
                {
                    if ( (CurrentEnemyData.CurEnemy_usStatus & 0x40) != 0 )  // right
                    {
                        CurrentEnemyData.CurEnemy_XPos += CurrentEnemyData.CurEnemy_TWork2;
                    }
                    else // left, at least the ball still can move left anyway
                    {
                        CurrentEnemyData.CurEnemy_XPos -= CurrentEnemyData.CurEnemy_TWork2;
                    }
                }

                if ((CurrentEnemyData.CurEnemy_padding & 2) && (CurrentEnemyData.CurEnemy_padding & 4)) // both disabled
                {
                    // goes down by default
                    CurrentEnemyData.CurEnemy_YPos += CurrentEnemyData.CurEnemy_TWork2;
                }
            }
        }
    }
    else if ( CurrentEnemyData.CurEnemy_CurrentAnimationId > 0x10u )
    {  // set disappear
        if ( CurrentEnemyData.CurEnemy_CurrentAnimationId != K5_HIP )
        {
            goto LABEL_10;
        }

        // graphic effect things after disappear
        CurrentEnemyData.CurEnemy_DisableInteractionWithWarioCountdown = 1;
        --CurrentEnemyData.CurEnemy_TWork0;
        if ( !CurrentEnemyData.CurEnemy_TWork0 )
        {
            CurrentEnemyData.CurEnemy_usStatus = CurrentEnemyData.CurEnemy_TWork0;
        }
    }
    else
    {
        if ( CurrentEnemyData.CurEnemy_CurrentAnimationId )
        {
LABEL_10:   // set disappear
            CurrentEnemyData.CurEnemy_DisableInteractionWithWarioCountdown = 1;
            CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = 0x83D0D64;
            CurrentEnemyData.CurEnemy_RealFrameCountForCurrentAnimationFrame = 0;
            CurrentEnemyData.CurEnemy_CurrentAnimationFrameId = 0;
            CurrentEnemyData.CurEnemy_CurrentAnimationId = K5_HIP;
            CurrentEnemyData.CurEnemy_TWork0 = 0x1B;
            CurrentEnemyData.CurEnemy_usStatus |= 0x400u;
            return;
        }

        // initial
        CurrentEnemyData.CurEnemy_usStatus = (CurrentEnemyData.CurEnemy_usStatus | 0x28) & 0xFFFB;
        CurrentEnemyData.CurEnemy_SizeY0_Bottom = 16;
        CurrentEnemyData.CurEnemy_SizeY1_Top = 16;
        CurrentEnemyData.CurEnemy_SizeX_LeftRight = 16;
        CurrentEnemyData.CurEnemy_HitboxY0 = 32;
        CurrentEnemyData.CurEnemy_HitboxY1 = 28;
        CurrentEnemyData.CurEnemy_HitboxX0 = 32;
        CurrentEnemyData.CurEnemy_HitboxX1 = 28;
        CurrentEnemyData.CurEnemy_RealFrameCountForCurrentAnimationFrame = 0;
        CurrentEnemyData.CurEnemy_CurrentAnimationFrameId = 0;
        CurrentEnemyData.CurEnemy_GuardAndDamageParam = MENISI_H; // ALL_TOGE2
        if (!CurrentPassage && !CurrentLevel && (CurrentRoom == 9))
        {
            CurrentEnemyData.CurEnemy_GuardAndDamageParam = NORU_HAKO_NH;
        }
        CurrentEnemyData.CurEnemy_TWork0 = 0; // vanilla value: 36
        CurrentEnemyData.CurEnemy_TWork2 = 8;
        CurrentEnemyData.CurEnemy_TWork3 = 0;
        CurrentEnemyData.CurEnemy_CurrentAnimationId = K0_WALK;
        CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = 0x83D0D3C;
    }
    return;
}