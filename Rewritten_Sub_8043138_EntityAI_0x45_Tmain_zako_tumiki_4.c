// @Description Rewrite Sub_8043138_EntityAI_0x45_Tmain_zako_tumiki_4, make toy blocks be able to interact with conveyor belts
// @HookAddress 0x78E914
// @HookString P
// Made by ssp (shinespeciall)
// Verison 1.0

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
    unsigned char CurEnemy_HitboxY0;
    unsigned char CurEnemy_HitboxY1;
    unsigned char CurEnemy_HitboxX0;
    unsigned char CurEnemy_HitboxX1;
    unsigned char CurEnemy_padding; // possible wrong order
    unsigned char CurEnemy_TWork0;
    unsigned char CurEnemy_TWork1;
    unsigned char CurEnemy_TWork2;
    unsigned char CurEnemy_TWork3;
};

#define Terrain_usKoka_SolidOrWater (*(volatile unsigned short*) 0x30000A2)
#define EntityLeftOverStateList ((volatile unsigned char*) 0x3000564)
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

#define word_83C7A6C ((volatile short*) 0x83C7A6C)

void Rewritten_Sub_8043138_EntityAI_0x45_Tmain_zako_tumiki_4()
{
	// Rewrite the whole function using switch case
    // Remove tile16 putting and removing functions
	// Change the CurEnemy_GuardAndDamageParam
    // better drop checking logic
    switch (CurrentEnemyData.CurEnemy_CurrentAnimationId)
    {
        case Q_INITIAL:
        {
            CurrentEnemyData.CurEnemy_XPos += 32;
            CurrentEnemyData.CurEnemy_usStatus |= /*0x8020u*/ 0x408u;
            CurrentEnemyData.CurEnemy_Prio = 1;
            CurrentEnemyData.CurEnemy_SizeY0_Bottom = 32;
            CurrentEnemyData.CurEnemy_SizeY1_Top = 0;
            CurrentEnemyData.CurEnemy_SizeX_LeftRight = 16;
            CurrentEnemyData.CurEnemy_HitboxY0 = 120;
            CurrentEnemyData.CurEnemy_HitboxY1 = 0;
            CurrentEnemyData.CurEnemy_HitboxX0 = 64;
            CurrentEnemyData.CurEnemy_HitboxX1 = 60;
            CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = 0x83C799C;
            CurrentEnemyData.CurEnemy_RealFrameCountForCurrentAnimationFrame = 0;
            CurrentEnemyData.CurEnemy_CurrentAnimationFrameId = 0;
            CurrentEnemyData.CurEnemy_GuardAndDamageParam = /*TUMIKI_4_H*/ NORU_HAKO_NH; // changed the type
            /**NORU_HAKO, // wario will bounce away on the side of the enemy, can walk atop
             * NORU_HAKO2, // same with NORU_HAKO
             * NORU_HAKO_NH,
             * NORU_HAKO2_NH, // 2 same
             * NORU_YUKA_1,
             * NORU_YUKA_1ND,
             * NORU_YUKA_1A,
             */
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
		    CurrentEnemyData.CurEnemy_TWork2 = 0;
        } // fall through
        case H_RAKKA_V:
        {
            Sub_8042D70_Tumiki_4_Rakka_AtariCheck();
            Wario_ucTumiki = 0;
            if ( CurrentEnemyData.CurEnemy_TWork2 == 255 )
            {
                CurrentEnemyData.CurEnemy_TWork2 = 0;
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
                    v1 = word_83C7A6C[CurrentEnemyData.CurEnemy_TWork2];
                    if ( v1 == 0x7FFF )
                    {
                        v2 = CurrentEnemyData.CurEnemy_YPos + word_83C7A6C[CurrentEnemyData.CurEnemy_TWork2 - 1];
                    }
                    else
                    {
                        ++CurrentEnemyData.CurEnemy_TWork2;
                        v2 = CurrentEnemyData.CurEnemy_YPos + v1;
                    }
                CurrentEnemyData.CurEnemy_YPos = v2;
                }
            }
            break;
        }
        default:
        {
            CurrentEnemyData.CurEnemy_CurrentAnimationId = K0_WALK;
			CurrentEnemyData.CurEnemy_usStatus &= 0xFCFFu;
            break;
        }
    }
    Sub_8026838_EnemyWanderingCom();
}
