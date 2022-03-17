// @Description Rewrite Sub_8043138_EntityAI_0x45_Tmain_zako_tumiki_4, make toy blocks be able to interact with conveyor belts
// @HookAddress 0x78E914
// @HookString P
// Made by ssp (shinespeciall)

/**
 * changelog: 
 * directly modified from the IDA pro's generated C code.
 * change its hitbox type, and make its drop down logic more accurate.
 *            ---- by ssp (shinespeciall), 2021/04/31
 * put a part of the rock's AI logic into this function,
 * now we can pick it up and throw it around.
 *            ---- by ssp (shinespeciall), 2022/03/13
 */


// 00(Entry) 01(Emerald) 02(Ruby) 03(Topaz) 04(Sapphire) 05(Golden)
#define PassageID (*(volatile unsigned char*) 0x3000002)
// 00(first lvl) 01(second lvl) 02(third lvl) 03(fourth lvl) 05(Mini-Game Shop) 04(Boss)
#define InPassageLevelID (*(volatile unsigned char*) 0x3000003)
#define CurrentRoomId (*(volatile unsigned char*) 0x3000024)

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

struct ENEMY_DATA {
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
    signed char CurEnemy_HitboxY0;
    signed char CurEnemy_HitboxY1;
    signed char CurEnemy_HitboxX0;
    signed char CurEnemy_HitboxX1;
    unsigned char CurEnemy_TWork0;
    unsigned char CurEnemy_TWork1;
    unsigned char CurEnemy_TWork2;
    unsigned char CurEnemy_TWork3;
    unsigned char CurEnemy_padding;
};

struct EntityLoadInfo {
    unsigned char YPos;
    unsigned char XPos;
    unsigned char EntityIdInEntityset;
};

#define Terrain_usKoka_SolidOrWater (*(volatile unsigned short*) 0x30000A2)
#define EntityLeftOverStateList ((volatile unsigned char*) 0x3000564)
#define CurrentEntityLoadInfoList ((volatile struct EntityLoadInfo*) 0x3000964)
#define ucThit1 (*(volatile unsigned char*) 0x3000A50)
#define ucThit2 (*(volatile unsigned char*) 0x3000A51)
#define Wario_ucTumiki (*(volatile unsigned char*) 0x300189E)
#define CurrentEnemyData (*(volatile struct ENEMY_DATA*) 0x3000A24)

#define Sub_8001DA4_m4aSongNumStart ((void (*)(int)) 0x8001DA5)
#define Sub_8023A60_DropCorrectedBgAttact ((int (*)()) 0x8023A61)
#define Sub_8023B88_T_DivaBellyAttactCheck ((void (*)()) 0x8023B89)
#define Sub_8023BFC_T_NoCorrectionBgAttack ((void (*)()) 0x8023BFD)
#define Sub_8026838_EnemyWanderingCom ((void (*)()) 0x8026839)
#define Sub_8042D70_Tumiki_4_Rakka_AtariCheck() ((void (*)()) 0x8042D71)
#define Sub_80766E8_TOptObjSet ((int (*)(int, int, char)) 0x80766E9) // to emit various objects ; a1 = Y, a2 = X, a3 = ID of object

#define Sub_8025634_Throw_L_com ((void (*)()) 0x8025635) // throw
#define Sub_80256D4_TThrow_L_com ((void (*)()) 0x80256D5)
#define Sub_8025774_UThrow_L_com ((void (*)()) 0x8025775)
#define Sub_8025814_UTThrow_L_com ((void (*)()) 0x8025815)
#define Sub_8025A00_Throw_R_com ((void (*)()) 0x8025A01)
#define Sub_8025AA0_TThrow_R_com ((void (*)()) 0x8025AA1)
#define Sub_8025B40_UThrow_R_com ((void (*)()) 0x8025B41)
#define Sub_8025BE0_UTThrow_R_com ((void (*)()) 0x8025BE1)

#define Tbuf (*(volatile unsigned char*) 0x03000A24)

// rock functions
#define Q_INITIAL_zako_iwa ((int (*)()) 0x803E55F)
#define Q_K0_WALK_zako_iwa ((int (*)()) 0x803E591)
#define K0_WALK_zako_iwa ((void (*)()) 0x803E5C1)
#define Q_H_RAKKA_V_zako_iwa ((void (*)()) 0x803E62D)
#define Q_HIKKURI_L_zako_iwa ((void (*)()) 0x803E641)
#define Q_HIKKURI_R_zako_iwa ((void (*)()) 0x803E655)
#define Q_H_RAKKA_L_zako_iwa ((int (*)()) 0x803E669)
#define Q_H_RAKKA_R_zako_iwa ((int (*)()) 0x803E685)
#define Q_K4_LEFT_zako_iwa ((int (*)()) 0x803E6A1)
#define Q_K4_RIGHT_zako_iwa ((int (*)()) 0x803E6C5)
#define Q_K5_HIP_zako_iwa ((void (*)()) 0x803E6E9)
#define Q_K3_LEFT_zako_iwa ((int (*)()) 0x803E70D)
#define Q_K3_RIGHT_zako_iwa ((int (*)()) 0x803E719)
#define Q_LF_MOVE_L_zako_iwa ((int (*)()) 0x803E725)
#define Q_LF_MOVE_R_zako_iwa ((int (*)()) 0x803E74D)

// common function
#define H_RAKKA_V_com ((void (*)()) 0x8023EE1) // drop
#define HIKKURI_L_com ((void (*)()) 0x8024479) // flip
#define HIKKURI_R_com ((void (*)()) 0x802449D)

#define Q_BOUND1_L_com ((void (*)()) 0x8024689)
#define BOUND1_L_com ((void (*)()) 0x80246B9)
#define Q_BOUND2_L_com ((void (*)()) 0x802473D)
#define BOUND2_L_com ((void (*)()) 0x802476D)
#define Q_BOUND3_L_com ((void (*)()) 0x80247F1)
#define BOUND3_L_com ((void (*)()) 0x8024821)
#define Q_BOUND1_R_com	((void (*)()) 0x80248A5)
#define BOUND1_R_com ((void (*)()) 0x80248D5)
#define Q_BOUND2_R_com ((void (*)()) 0x8024959)
#define BOUND2_R_com ((void (*)()) 0x8024989)
#define Q_BOUND3_R_com ((void (*)()) 0x8024A0D)
#define BOUND3_R_com ((void (*)()) 0x8024A3D)

#define Q_NH_RAKKA_L_com ((void (*)()) 0x8024AC1)
#define Q_NH_RAKKA_R_com ((void (*)()) 0x8024BED)
#define H_RAKKA_L_com ((void (*)()) 0x8024AD5)
#define H_RAKKA_R_com ((void (*)()) 0x8024C01)

#define K3_LEFT_com ((void (*)()) 0x8024D19)
#define K3_RIGHT_com ((void (*)()) 0x8024E59)
#define LF_MOVE_L_com ((void (*)()) 0x8024F99)
#define LF_MOVE_R_com ((void (*)()) 0x8025241)

#define NAGE_L_com ((void (*)()) 0x8025635) // throw
#define TNAGE_L_com ((void (*)()) 0x80256D5)
#define UNAGE_L_com ((void (*)()) 0x8025775)
#define UTNAGE_L_com ((void (*)()) 0x8025815)
#define NAGE_R_com ((void (*)()) 0x8025A01)
#define TNAGE_R_com ((void (*)()) 0x8025AA1)
#define UNAGE_R_com ((void (*)()) 0x8025B41)
#define UTNAGE_R_com ((void (*)()) 0x8025BE1)

#define Q_SOKUSI_com ((void (*)()) 0x8024555) // instant kill
#define TOptObjSet ((void (*)(unsigned short, unsigned short, char)) 0x80766E9)
#define m4aSongNumStart ((void (*)(int)) 0x8001DA5)
#define T_NoHoseiBgAtari ((void (*)(unsigned short, unsigned short)) 0x8023BFD)

#define Wario_ucReact (*(volatile char*) 0x3001898)
#define Wario_usPosX  (*(volatile short*) 0x30018AA) // rightwards positive
#define Wario_usPosY  (*(volatile short*) 0x30018AC) // downwards positive
#define Wario_ucPlace  (*(volatile unsigned char*) 0x30018B2)
#define WarioYPos_backup  (*(volatile short*) 0x30019F4)

#define word_83C7A6C ((volatile short*) 0x83C7A6C)
#define WarioChng_React ((volatile unsigned int*) 0x83C7A6C)

#define Sub_8094DFC_call_via_r0 ((int (*)(unsigned int)) 0x8094DFD)
#define Sub_8094E00_call_via_r1 ((int (*)(int*, int)) 0x8094E01)

void Rewritten_Sub_8043138_EntityAI_0x45_Tmain_zako_tumiki_4()
{
	// run the old AI in some cases
    // you can see the vanilla game do something like this in "Sub_8033708_Q_INITIAL_zako_moguramen()"
    int use_old_AI = 1;
    if ( !PassageID && !InPassageLevelID ) // in 0-0
    {
        // Room 0, slot 0x12 use the old AI, slot 0x13 use the new one
        if ( !CurrentRoomId && \
        CurrentEntityLoadInfoList[CurrentEnemyData.CurEnemy_RoomEntitySlotId].EntityIdInEntityset == 0x13 )
        {
            use_old_AI = 0;
        }
        // in other Rooms, slot 0x11 use the old AI, slot 0x12 use the new one
        if ( CurrentRoomId && \
        CurrentEntityLoadInfoList[CurrentEnemyData.CurEnemy_RoomEntitySlotId].EntityIdInEntityset == 0x12 )
        {
            use_old_AI = 0;
        }
    }
    if (use_old_AI) // it uses the old AI as default
    {
        return Sub_8094DFC_call_via_r0(0x8043139); // EntitiesAIVectorTable[0x45]
    }

    // Change the CurEnemy_GuardAndDamageParam realtime
    if (Wario_usPosY <= (CurrentEnemyData.CurEnemy_YPos - 8))
    {
        CurrentEnemyData.CurEnemy_GuardAndDamageParam = NORU_HAKO_NH;
    }
    else
    {
        CurrentEnemyData.CurEnemy_GuardAndDamageParam = 5;
    }
    /**
     * TUMIKI_4_H, 22, only has hitbox, can walk atop
     * NORU_HAKO, // wario will bounce away on the side of the enemy, can walk atop
     * NORU_HAKO2, // same with NORU_HAKO
     * NORU_HAKO_NH,
     * NORU_HAKO2_NH, // 2 same
     * NORU_YUKA_1,
     * NORU_YUKA_1ND,
     * NORU_YUKA_1A,
     */

    // Rewrite the whole function using switch case
    // Remove tile16 putting and removing functions
	// Change the CurEnemy_GuardAndDamageParam
    // better drop checking logic
    switch (CurrentEnemyData.CurEnemy_CurrentAnimationId)
    {
        case Q_INITIAL:
        {
            CurrentEnemyData.CurEnemy_XPos += 32;
            // use 0x408u to let it scroll out when too far, use 0x8408u to not let it scroll out
            if (!PassageID && !InPassageLevelID)
            { // don't scroll out in 0-0, Room 1 or Room 5
                if (CurrentRoomId == 1 || CurrentRoomId == 5)
                {
                    CurrentEnemyData.CurEnemy_usStatus |= /*0x8020u*/ 0x8408u;
                }
            } // one more interesting thing, the vanilla toy box won't scroll out either
            else
            {
                CurrentEnemyData.CurEnemy_usStatus |= /*0x8020u*/ 0x408u;
            }
            CurrentEnemyData.CurEnemy_Prio = 1;
            CurrentEnemyData.CurEnemy_paletteId = 1;
            CurrentEnemyData.CurEnemy_SizeY0_Bottom = 32;
            CurrentEnemyData.CurEnemy_SizeY1_Top = 0;
            CurrentEnemyData.CurEnemy_SizeX_LeftRight = 16;
            CurrentEnemyData.CurEnemy_HitboxY0 = 128;
            CurrentEnemyData.CurEnemy_HitboxY1 = 0;
            CurrentEnemyData.CurEnemy_HitboxX0 = 64;
            CurrentEnemyData.CurEnemy_HitboxX1 = 60;
            CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = 0x83C799C;
            CurrentEnemyData.CurEnemy_RealFrameCountForCurrentAnimationFrame = 0;
            CurrentEnemyData.CurEnemy_CurrentAnimationFrameId = 0;
            CurrentEnemyData.CurEnemy_CurrentAnimationId = 16;
            CurrentEnemyData.CurEnemy_TWork0 = 0;
        } // fall through
        case K0_WALK:
        {
            Sub_8023B88_T_DivaBellyAttactCheck();
            if ( !ucThit1 )
            {
                if ( (CurrentEnemyData.CurEnemy_usStatus & 0x40) != 0 )
                    Sub_8023BFC_T_NoCorrectionBgAttack( \
                        CurrentEnemyData.CurEnemy_YPos, \
                        CurrentEnemyData.CurEnemy_XPos - CurrentEnemyData.CurEnemy_HitboxX0);
                else
                    Sub_8023BFC_T_NoCorrectionBgAttack( \
                        CurrentEnemyData.CurEnemy_YPos, \
                        CurrentEnemyData.CurEnemy_XPos + CurrentEnemyData.CurEnemy_HitboxX1);
                if ( !ucThit2 )
                    CurrentEnemyData.CurEnemy_CurrentAnimationId = Q_N_RAKKA_V;
            }
            break;
        }
        case Q_N_RAKKA_V:
        {
            CurrentEnemyData.CurEnemy_CurrentAnimationId = H_RAKKA_V;
		    CurrentEnemyData.CurEnemy_padding = 0;
        } // fall through
        case H_RAKKA_V:
        {
            Sub_8042D70_Tumiki_4_Rakka_AtariCheck();
            Wario_ucTumiki = 0;
            if ( CurrentEnemyData.CurEnemy_padding == 255 )
            {
                CurrentEnemyData.CurEnemy_padding = 0;
                Wario_ucTumiki = 1;
            }
            else
            {
	            short v0, v0_1, v0_2, v1, v2;
                v0_2 = v0 = Sub_8023A60_DropCorrectedBgAttact(CurrentEnemyData.CurEnemy_YPos, CurrentEnemyData.CurEnemy_XPos);
                unsigned char tmp_ucThit1 = ucThit1; // in case ucThit1 data got wiped on the second run of Sub_8023A60_DropCorrectedBgAttact
                v0_1 = Sub_8023A60_DropCorrectedBgAttact(CurrentEnemyData.CurEnemy_YPos, CurrentEnemyData.CurEnemy_XPos + 64);
                unsigned char tmp_ucThit2 = ucThit1;
                if ((CurrentEnemyData.CurEnemy_XPos - CurrentEnemyData.CurEnemy_HitboxX1) & 63)
                    v0_2 = Sub_8023A60_DropCorrectedBgAttact(CurrentEnemyData.CurEnemy_YPos, CurrentEnemyData.CurEnemy_XPos - 64);
                
                if (!ucThit1) ucThit1 = (!tmp_ucThit1) ? tmp_ucThit2 : tmp_ucThit1;
                if ( Terrain_usKoka_SolidOrWater == /*YK_MIZU*/ 1 )
                {
                    CurrentEnemyData.CurEnemy_usStatus |= 0x800u;
                    Sub_8001DA4_m4aSongNumStart(/*S_TEKI_WATER_IN*/ 0x3D);
                }
                if ( ucThit1 )
                {
                    short tmp_min = (v0 >= v0_1) ? v0_1 : v0;
                    CurrentEnemyData.CurEnemy_YPos = (tmp_min >= v0_2) ? v0_2 : tmp_min;
                    CurrentEnemyData.CurEnemy_CurrentAnimationId = K0_WALK;
                    Sub_8001DA4_m4aSongNumStart(/*S_BLOCK_BOUND*/ 0xF9);
                }
                else
                {
                    v1 = word_83C7A6C[CurrentEnemyData.CurEnemy_padding];
                    if ( v1 == 0x7FFF )
                    {
                        v2 = CurrentEnemyData.CurEnemy_YPos + word_83C7A6C[CurrentEnemyData.CurEnemy_padding - 1];
                    }
                    else
                    {
                        ++CurrentEnemyData.CurEnemy_padding;
                        v2 = CurrentEnemyData.CurEnemy_YPos + v1;
                    }
                CurrentEnemyData.CurEnemy_YPos = v2;
                }
            }
            break;
        }
        case 31:
        case 35:
        case 51:
        case 79:
        case 106:
            Q_K4_LEFT_zako_iwa();
            goto LABEL_25;
        case 33:
        case 37:
        case 53:
        case 80:
        case 105:
            Q_K4_RIGHT_zako_iwa();
            goto LABEL_19;
        // this part of logic will let the box keep moving on the ground
        // --------------- comment out ---------------
        // case 43:
        //     Q_HIKKURI_L_zako_iwa();
        //     goto LABEL_10;
        // case 44:
        // LABEL_10:
        //     HIKKURI_L_com();
        //     break;
        // case 45:
        //     Q_HIKKURI_R_zako_iwa();
        //     goto LABEL_12;
        // case 46:
        // LABEL_12:
        //     HIKKURI_R_com();
        //     break;
        // ------------------------------------------
        case 49:
            Q_K5_HIP_zako_iwa();
            break;
        case 52:
        case 64:
            goto LABEL_25;
        case 54:
        case 58:
            goto LABEL_19;
        case 55:
            Q_BOUND1_L_com();
            goto LABEL_17;
        case 56:
        LABEL_17:
            BOUND1_L_com();
            break;
        case 57:
            Q_BOUND2_L_com();
        LABEL_19:
            BOUND2_L_com();
            break;
        case 59:
            Q_BOUND3_L_com();
            goto LABEL_21;
        case 60:
        LABEL_21:
            BOUND3_L_com();
            break;
        case 61:
            Q_BOUND1_R_com();
            goto LABEL_23;
        case 62:
        LABEL_23:
            BOUND1_R_com();
            break;
        case 63:
            Q_BOUND2_R_com();
        LABEL_25:
            BOUND2_R_com();
            break;
        case 65:
            Q_BOUND3_R_com();
            goto LABEL_27;
        case 66:
        LABEL_27:
            BOUND3_R_com();
            break;
        case 67:
            Q_NH_RAKKA_L_com();
            goto LABEL_31;
        case 68:
        case 72:
            goto LABEL_31;
        case 69:
            Q_NH_RAKKA_R_com();
            goto LABEL_33;
        case 70:
        case 74:
            goto LABEL_33;
        case 71:
            Q_H_RAKKA_L_zako_iwa();
        LABEL_31:
            Tbuf &= 0xF7FFu;
            H_RAKKA_L_com();
            break;
        case 73:
            Q_H_RAKKA_R_zako_iwa();
        LABEL_33:
            Tbuf &= 0xF7FFu;
            H_RAKKA_R_com();
            break;
        case 81:
            Q_K3_LEFT_zako_iwa();
            break;
        case 82:
            K3_LEFT_com();
            break;
        case 83:
            Q_K3_RIGHT_zako_iwa();
            break;
        case 84:
            K3_RIGHT_com();
            break;
        case 85:
            Q_LF_MOVE_R_zako_iwa();
            break;
        case 86:
            Tbuf &= 0xF7FFu;
            LF_MOVE_R_com();
            break;
        case 87:
            Q_LF_MOVE_L_zako_iwa();
            break;
        case 88:
            Tbuf &= 0xF7FFu;
            LF_MOVE_L_com();
            break;
        case Q_NAGE_L:
            CurrentEnemyData.CurEnemy_CurrentAnimationId = 0x5A;
            // [[fall_through]]
        case NAGE_L:
            CurrentEnemyData.CurEnemy_usStatus &= 0xF7FFu;
            Sub_8025634_Throw_L_com();
            break;
        case Q_NAGE_R:
            CurrentEnemyData.CurEnemy_CurrentAnimationId = 0x5C;
            // [[fall_through]]
        case NAGE_R:
            CurrentEnemyData.CurEnemy_usStatus &= 0xF7FFu;
            Sub_8025A00_Throw_R_com();
            break;
        case Q_TNAGE_L:
            CurrentEnemyData.CurEnemy_CurrentAnimationId = 94;
            CurrentEnemyData.CurEnemy_Life = CurrentEnemyData.CurEnemy_Life & 0xF | 0x10;
            // [[fall_through]]
        case TNAGE_L:
            CurrentEnemyData.CurEnemy_usStatus &= 0xF7FFu;
            Sub_80256D4_TThrow_L_com();
            break;
        case Q_TNAGE_R:
            CurrentEnemyData.CurEnemy_CurrentAnimationId = 96;
            CurrentEnemyData.CurEnemy_Life = CurrentEnemyData.CurEnemy_Life & 0xF | 0x40;
            // [[fall_through]]
        case TNAGE_R:
            CurrentEnemyData.CurEnemy_usStatus &= 0xF7FFu;
            Sub_8025AA0_TThrow_R_com();
            break;
        case Q_UNAGE_L:
            CurrentEnemyData.CurEnemy_CurrentAnimationId = 98;
            // [[fall_through]]
        case UNAGE_L:
            CurrentEnemyData.CurEnemy_usStatus &= 0xF7FFu;
            Sub_8025774_UThrow_L_com();
            break;
        case Q_UNAGE_R:
            CurrentEnemyData.CurEnemy_CurrentAnimationId = 100;
            // [[fall_through]]
        case UNAGE_R:
            CurrentEnemyData.CurEnemy_usStatus &= 0xF7FFu;
            Sub_8025B40_UThrow_R_com();
            break;
        case Q_UTNAGE_L: // charged up-throw
            CurrentEnemyData.CurEnemy_CurrentAnimationId = 102;
            CurrentEnemyData.CurEnemy_Life = CurrentEnemyData.CurEnemy_Life & 0xF | 0x20;
            // [[fall_through]]
        case UTNAGE_L:
            CurrentEnemyData.CurEnemy_usStatus &= 0xF7FFu;
            Sub_8025814_UTThrow_L_com();
            break;
        case Q_UTNAGE_R:
            CurrentEnemyData.CurEnemy_CurrentAnimationId = 104;
            CurrentEnemyData.CurEnemy_Life = CurrentEnemyData.CurEnemy_Life & 0xF | 0x80;
            // [[fall_through]]
        case UTNAGE_R:
            CurrentEnemyData.CurEnemy_usStatus &= 0xF7FFu;
            Sub_8025BE0_UTThrow_R_com();
            break;
        default:
        {
            CurrentEnemyData.CurEnemy_CurrentAnimationId = K0_WALK;
			CurrentEnemyData.CurEnemy_usStatus &= 0xFCFFu;
            break;
        }
    }
    // we need this function to let wario walk on the enemy
    Sub_8026838_EnemyWanderingCom();
}
