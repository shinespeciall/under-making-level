// @Description modify Sub_8038730_EntityAI_0x26_Tmain_zako_jyuutan
// @HookAddress 0x78E898
// directly hook inside the Enemy AI pointer table
// @HookString P
// @EntryFunctionSymbol Sub_8038730_EntityAI_0x26_Tmain_zako_jyuutan

/**
 * changelog: 
 * directly modified from the IDA pro's generated C code.
 *            ---- by ssp (shinespeciall), 2022/11/05
 * add logic to make carpet enemy has 2 types.
 * the first type can move up when wario is on it and player press up.
 * the second type can only move in one direction, horizontal by default,
 * diagonal goes up or down should be controlled by event tile16s,
 * it will stop moving when wario is not on it.
 * (since i cannot find easy way to keep it moving in the current code logic)
 * HOW_TO_USE:
 * put 2 carpet sprites in the same spriteset,
 * and their local ids should be continuous positive numbers.
 * no other demand, you can put them anywhere in any spriteset.
 * the first one will always be type 1, while the other one will be the type 2.
 * if there is only one in the spriteset, or their ids are not continuous positive numbers,
 * only type 1 carpet can be found when run the game.
 *            ---- by ssp (shinespeciall), 2022/11/06
 * add multiple edge cases check stuff for wario's or enemy's collision with solid or event Tile16.
 * stop moving wario and the carpet when the collisions happen.
 *            ---- by ssp (shinespeciall), 2022/11/12
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
    unsigned char CurEnemy_TWork1_WarioOnTop;
    unsigned char CurEnemy_TWork2;
    unsigned char CurEnemy_TWork3;
    unsigned char CurEnemy_padding;
};

#define CurrentEnemyData (*(volatile struct EnemyDataStructure*) 0x3000A24)
#define ucThit1 (*(volatile unsigned char*) 0x3000A50)
#define ucThit2 (*(volatile unsigned char*) 0x3000A51)

#define KeyPressContinuous (*(volatile unsigned short*) 0x3001844)
/*
VAL_KEY_A = 0x1
VAL_KEY_B = 0x2
VAL_KEY_SELECT = 0x4
VAL_KEY_START = 0x8
VAL_KEY_RIGHT = 0x10
VAL_KEY_LEFT = 0x20
VAL_KEY_UP = 0x40
VAL_KEY_DOWN = 0x80
VAL_KEY_R = 0x100
VAL_KEY_L = 0x200
*/
#define Wario_ucStat (*(volatile unsigned char*) 0x3001899)
#define Wario_usPosX (*(volatile unsigned short*) 0x30018AA)
#define Wario_usPosY (*(volatile unsigned short*) 0x30018AC)
#define Wario_ucPlace (*(volatile unsigned char*) 0x30018B2)

struct WHitDef
{
    unsigned short    usMukiX;
    unsigned short    usMukiY;

    unsigned char    ucFront;
    unsigned char    ucBack;
    short    sDX;

    unsigned char    ucSide;
    unsigned char    ucHead;
    unsigned char    ucYuka;
    unsigned char    ucSPow;

    unsigned char    ucHPow;
    unsigned char    ucYPow;
    unsigned char    ucWSide;
    unsigned char    ucWHead;

    unsigned char    ucWYuka;
    unsigned char    ucPlace;
    unsigned char    ucSStop;
    unsigned char    ucHStop;

    unsigned char    ucYStop;
    unsigned char    unused_0;
    unsigned char    unused_1;
    unsigned char    unused_2;
};
#define WHit (*(volatile struct WHitDef*) 0x03001918)
#define word_82DEB64 ((volatile short*) 0x82DEB64)

#define ucTekiGroup (*(volatile unsigned char*) 0x3000027)
struct SpriteSetLoadInfo {
    unsigned char global_id;
    unsigned char palette_offset;
};
#define EntitySetPointerTable ((volatile struct SpriteSetLoadInfo**) 0x878EF78)
struct EntityLoadInfo {
    unsigned char YPos;
    unsigned char XPos;
    unsigned char EntityIdInEntityset;
};
#define CurrentEntityLoadInfoList ((volatile struct EntityLoadInfo*) 0x3000964)

#define CurrentTileset_TerrainTypeTablePointer (*(volatile unsigned char**) 0x30031F8)
#define CurrentTileset_EventIdTablePointer (*(volatile unsigned short**) 0x30031FC)
#define Layer0_DecompressedDataPointer (*(volatile unsigned short**) 0x3000054)
#define Layer0_Width (*(volatile unsigned short*) 0x3000058)
#define Layer0_Height (*(volatile unsigned short*) 0x300005a)
#define Layer1_DecompressedDataPointer (*(volatile unsigned short**) 0x300005c)
#define Layer1_Width (*(volatile unsigned short*) 0x3000060)
#define Layer1_Height (*(volatile unsigned short*) 0x3000062)
#define Layer2_DecompressedDataPointer (*(volatile unsigned short**) 0x3000064)
#define Layer2_Width (*(volatile unsigned short*) 0x3000068)
#define Layer2_Height (*(volatile unsigned short*) 0x300006a)

#define usBg0Hofs (*(volatile unsigned short*) 0x3001876)
#define usBg0Vofs (*(volatile unsigned short*) 0x3001878)
#define usBg1Hofs_CameraXPos (*(volatile unsigned short*) 0x300187A)
#define usBg1Vofs_CameraYPos (*(volatile unsigned short*) 0x300187C)
#define usBg2Hofs (*(volatile unsigned short*) 0x300187E)
#define usBg2Vofs (*(volatile unsigned short*) 0x3001880)
#define usBg3Hofs (*(volatile unsigned short*) 0x3001882)
#define usBg3Vofs (*(volatile unsigned short*) 0x3001884)

#define event_id_one_diagonal_go_up 0x110
#define event_id_one_diagonal_go_down 0x111
#define event_id_one_horizontal_move 0x112

// function calls
#define Sub_8023B88_T_DivaBellyAttactCheck ((void (*)()) 0x8023B89)

#define Sub_8038064_Q_INITIAL_zako_jyuutan ((void (*)()) 0x8038065)
#define Sub_80380DC_Q_K0_TURN2_zako_jyuutan ((void (*)()) 0x80380DD)
#define Sub_80381F4_K0_WALK_zako_jyuutan ((void (*)()) 0x80381F5)
#define Sub_803828C_K0_TURN1_zako_jyuutan ((void (*)()) 0x803828D)
#define Sub_8038448_K0_TURN2_zako_jyuutan ((void (*)()) 0x8038449)
#define Sub_80385A4_K0_TURN3_zako_jyuutan ((void (*)()) 0x80385A5)
#define Sub_8038174_JITTO_zako_jyuutan ((void (*)()) 0x8038175)
#define Sub_8024554_Q_InstantlyKill_com ((void (*)()) 0x8024555)
#define Sub_8026838_EnemyWanderingCom ((void (*)()) 0x8026839)
#define Sub_8038014_JyuutanDaburiCheck ((void (*)()) 0x8038015)

#define Sub_8023BFC_T_NoCorrectionBgAttack ((void (*)(unsigned short, unsigned short)) 0x8023BFD)
#define Sub_806D4C0_SetWarioAnimation_MapFieldAtari ((unsigned int (*)(int, int)) 0x806D4C1)

#define Sub_8012BAC_GmWarioChng ((void (*)(unsigned char)) 0x8012BAD)
#define Sub_8014090_WarHeadCheck ((int (*)(unsigned char, unsigned short, int)) 0x8014091)

unsigned short GetEventId(unsigned char layerid, unsigned short xpos, unsigned short ypos)
{
    unsigned short result = 0;
    if (layerid == 0) {
        int delta_L1_to_L0_X = (int)usBg0Hofs - (int)usBg1Hofs_CameraXPos;
        int delta_L1_to_L0_Y = (int)usBg0Vofs - (int)usBg1Vofs_CameraYPos;
        int X_value_R6_L0 = ((xpos + delta_L1_to_L0_X) << 16) >> 22;
        int Y_value_R6_L0 = ((ypos + delta_L1_to_L0_Y) << 16) >> 22;
        result = CurrentTileset_EventIdTablePointer[Layer0_DecompressedDataPointer[Y_value_R6_L0 * Layer2_Width + X_value_R6_L0]];
    } else if (layerid == 1) {
        int X_value_R6 = (xpos << 16) >> 22;
        int Y_value_R6 = (ypos << 16) >> 22;
        result = CurrentTileset_EventIdTablePointer[Layer1_DecompressedDataPointer[Y_value_R6 * Layer1_Width + X_value_R6]];
    } else if (layerid == 2) {
        int delta_L1_to_L2_X = (int)usBg2Hofs - (int)usBg1Hofs_CameraXPos;
        int delta_L1_to_L2_Y = (int)usBg2Vofs - (int)usBg1Vofs_CameraYPos;
        int X_value_R6_L2 = ((xpos + delta_L1_to_L2_X) << 16) >> 22;
        int Y_value_R6_L2 = ((ypos + delta_L1_to_L2_Y) << 16) >> 22;
        result = CurrentTileset_EventIdTablePointer[Layer2_DecompressedDataPointer[Y_value_R6_L2 * Layer2_Width + X_value_R6_L2]];
    } else {
        result = 0;
    }

    return result;
}

void Sub_8038730_EntityAI_0x26_Tmain_zako_jyuutan()
{
    // ---------------- custom logic starts ---------------- 
    unsigned short enemy_ypos_bk = CurrentEnemyData.CurEnemy_YPos;
    unsigned short wario_xpos_bk = Wario_usPosX;
    unsigned short enemy_xpos_bk = CurrentEnemyData.CurEnemy_XPos;
    // ---------------- custom logic ends ---------------- 

    if ( (CurrentEnemyData.CurEnemy_usStatus & 0x800) != 0 )
    {
        CurrentEnemyData.CurEnemy_CurrentAnimationId = Q_SOKUSI;
    }
    switch ( CurrentEnemyData.CurEnemy_CurrentAnimationId )
    {
        case Q_INITIAL:
        {
            Sub_8038064_Q_INITIAL_zako_jyuutan();
            break;
        }
        case K0_WALK:
        {
            Sub_80381F4_K0_WALK_zako_jyuutan();
            break;
        }
        case K0_TURN1:
        {
            Sub_803828C_K0_TURN1_zako_jyuutan();
            break;
        }
        case K0_TURN2:
        {
            Sub_8038448_K0_TURN2_zako_jyuutan();
            break;
        }
        case K0_TURN3:
        {
            Sub_80385A4_K0_TURN3_zako_jyuutan();
            break;
        }
        case JITTO: // stay on the ground ?
        {
            Sub_8038174_JITTO_zako_jyuutan();
            break;
        }
        default:
        {
            Sub_8024554_Q_InstantlyKill_com();
            Wario_ucPlace = 0;
            break;
        }
    }

    // ---------------- custom logic starts ----------------
    // don't scroll out
    CurrentEnemyData.CurEnemy_usStatus |= 0x8000u;

    // movement control logic
    unsigned char use_controllable_carpet = 1;
    unsigned char cur_local_enemy_id = CurrentEntityLoadInfoList[CurrentEnemyData.CurEnemy_RoomEntitySlotId].EntityIdInEntityset;
    unsigned char cur_global_id = CurrentEnemyData.CurEnemy_GlobalId;
    unsigned char last_global_id = 0xf0;
    if (cur_local_enemy_id > 0x11) // if it is not the first enemy in the spriteset
    { // get the previous enemy in the spriteset before the current one
        last_global_id = EntitySetPointerTable[ucTekiGroup][cur_local_enemy_id - 0x12].global_id;
    }
    // the first one should be the controllable one
    // the second one should be controlled by Tile16 events
    // in any other cases, the carpet should be controllable
    if (cur_global_id == last_global_id)
    {
        use_controllable_carpet = 0;
        CurrentEnemyData.CurEnemy_paletteId = 1; // use the second palette
    }

    // init stuff for non-controllable carpet
    unsigned short CurrentEventId = 0;
    unsigned char stop_going_up = 0;
    unsigned char dismount_wario = 0;
    if (!use_controllable_carpet) // in this way, the carpet can do something like, go through spikes
    {
        CurrentEventId = GetEventId(1, CurrentEnemyData.CurEnemy_XPos, CurrentEnemyData.CurEnemy_YPos);
        if (CurrentEventId < event_id_one_diagonal_go_up || CurrentEventId > event_id_one_horizontal_move)
        {
            CurrentEventId = GetEventId(0, CurrentEnemyData.CurEnemy_XPos, CurrentEnemyData.CurEnemy_YPos);
        }
        if (CurrentEventId < event_id_one_diagonal_go_up || CurrentEventId > event_id_one_horizontal_move)
        {
            CurrentEventId = GetEventId(2, CurrentEnemyData.CurEnemy_XPos, CurrentEnemyData.CurEnemy_YPos);
        }
    }
    // stop going up if there is some solid block above the carpet
    // use Sub_8023BFC_T_NoCorrectionBgAttack here for Tile16 colliison check, 
    // also need to patch Sub_806DAC0_PanelYakuAllNum_TileEventId for layer asyn stuff
    if ( (Sub_8023BFC_T_NoCorrectionBgAttack(CurrentEnemyData.CurEnemy_YPos, CurrentEnemyData.CurEnemy_XPos), (ucThit2 & 0xF) != 0) ||
        (Sub_8023BFC_T_NoCorrectionBgAttack(CurrentEnemyData.CurEnemy_YPos, CurrentEnemyData.CurEnemy_XPos - 64), (ucThit2 & 0xF) != 0) ||
        (Sub_8023BFC_T_NoCorrectionBgAttack(CurrentEnemyData.CurEnemy_YPos, CurrentEnemyData.CurEnemy_XPos + 64), (ucThit2 & 0xF) != 0) )
    {
        stop_going_up = 1;
    }

    // if wario if is on the carpet and his head is going to bonk on some Tile16 while standing
    // this part is not accurate enough but can work
    // logic from Sub_8014090_WarHeadCheck() and its caller Sub_8014C4C_WarHitUp()
    // the line below is how i did that at first, but the logic is so hard to write
    // (Sub_806D4C0_SetWarioAnimation_MapFieldAtari((Wario_usPosY - 128), Wario_usPosX) & 0x1000000) != 0
    if ( (Sub_806D4C0_SetWarioAnimation_MapFieldAtari(Wario_usPosY + word_82DEB64[3 * WHit.ucSide], Wario_usPosX) & 0x1000000) != 0 )
    {
        dismount_wario = 1;
    }

    // stop going left or right if wario is going to horizontally collide into some solid blocks
    // this is some bug in vanilla AI code, we gonna fix it here
    // also sometimes the carpet just horizontally collide into some Tile16 at their upper surface, we need to deal with it too
    int enemy_xpos_delta = CurrentEnemyData.CurEnemy_XPos - enemy_xpos_bk;
    // if carpet goes right in this frame
    if (enemy_xpos_delta > 0 && ((((Sub_806D4C0_SetWarioAnimation_MapFieldAtari(Wario_usPosY - 0x1E, Wario_usPosX + 0x20) & 0x1000000) != 0) ||
                                (Sub_806D4C0_SetWarioAnimation_MapFieldAtari(Wario_usPosY - 0x1E - 0x40, Wario_usPosX + 0x20) & 0x1000000) != 0)
            || (Sub_8023BFC_T_NoCorrectionBgAttack(CurrentEnemyData.CurEnemy_YPos - 16, CurrentEnemyData.CurEnemy_XPos + 64), (ucThit2 & 0xF) != 0)))
    {
        CurrentEnemyData.CurEnemy_XPos = enemy_xpos_bk;
        Wario_usPosX = wario_xpos_bk;
    } // if carpet goes left in this frame
    else if (enemy_xpos_delta < 0 && ((((Sub_806D4C0_SetWarioAnimation_MapFieldAtari(Wario_usPosY - 0x1E, Wario_usPosX - 0x20) & 0x1000000) != 0) ||
                                    (Sub_806D4C0_SetWarioAnimation_MapFieldAtari(Wario_usPosY - 0x1E - 0x40, Wario_usPosX - 0x20) & 0x1000000) != 0)
            || (Sub_8023BFC_T_NoCorrectionBgAttack(CurrentEnemyData.CurEnemy_YPos - 16, CurrentEnemyData.CurEnemy_XPos - 64), (ucThit2 & 0xF) != 0)))
    {
        CurrentEnemyData.CurEnemy_XPos = enemy_xpos_bk;
        Wario_usPosX = wario_xpos_bk;
    }
    
    // customize Y pos changes
    int enemy_ypos_delta = CurrentEnemyData.CurEnemy_YPos - enemy_ypos_bk;
    if (CurrentEnemyData.CurEnemy_CurrentAnimationId != Q_INITIAL) // don't reset y pos when init
    {
        // when wario stand on controllable carpet
        if(use_controllable_carpet && CurrentEnemyData.CurEnemy_TWork1_WarioOnTop)
        {
            if (enemy_ypos_delta > 0 && (KeyPressContinuous & 0x40) && (stop_going_up == 0) && (dismount_wario == 0)) // when press up
            { // press up then the carpet will go up
                CurrentEnemyData.CurEnemy_YPos -= 2 * enemy_ypos_delta;
            }
        }
        // when wario stand on non-controllable carpet
        else if (!use_controllable_carpet)
        {
            if (CurrentEventId == event_id_one_diagonal_go_up && (enemy_ypos_delta > 0) && (stop_going_up == 0))
            { // disable the jump up cases in the if statement
                CurrentEnemyData.CurEnemy_YPos -= 2 * enemy_ypos_delta;
                // accelerate the vertical speed
                if (CurrentEnemyData.CurEnemy_TWork1_WarioOnTop)
                {
                    CurrentEnemyData.CurEnemy_YPos -= 2 * enemy_ypos_delta;
                }

                // force dismount wario if the carpet has to go up but there is no enough room for wario to stand on it
                if ((dismount_wario > 0) && CurrentEnemyData.CurEnemy_TWork1_WarioOnTop)
                {
                    if (Wario_ucStat <= 4) // walk, turn, stop, jump
                    {
                        Sub_8012BAC_GmWarioChng(8); // set sjump
                    }
                    if (Wario_ucStat > 12 && Wario_ucStat <= 16) // rollB, roll, rjump, rflip
                    {
                        Sub_8012BAC_GmWarioChng(15);
                    }

                    // dismount carpet
                    if (Wario_ucStat > 4 && Wario_ucStat <= 16)
                    {
                        CurrentEnemyData.CurEnemy_TWork1_WarioOnTop = 0;
                        Wario_usPosY += 32;
                    }
                }
            }
            else if (CurrentEventId == event_id_one_diagonal_go_down)
            {
                // disable the jump up cases
                if (enemy_ypos_delta < 0)
                {
                    CurrentEnemyData.CurEnemy_YPos = enemy_ypos_bk;
                    enemy_ypos_delta = 0 - enemy_ypos_delta;
                }
                // accelerate the vertical speed
                if (CurrentEnemyData.CurEnemy_TWork1_WarioOnTop)
                {
                    CurrentEnemyData.CurEnemy_YPos += 2 * enemy_ypos_delta;
                }
            }
            else // default: (CurrentEventId == event_id_one_horizontal_move)
            {
                CurrentEnemyData.CurEnemy_YPos = enemy_ypos_bk;
            }
        }
    }
    // ---------------- custom logic ends ---------------- 

    // keep wario on top of enemy, only control vertical coordinate
    Sub_8026838_EnemyWanderingCom();

    // disable the current jyuutan if wario lands on another jyuutan at the same time.
    Sub_8038014_JyuutanDaburiCheck();

    // set BG-like enemy flag (what's its usage?)
    unsigned short v0;
    if ( CurrentEnemyData.CurEnemy_TWork1_WarioOnTop )
    {
        v0 = CurrentEnemyData.CurEnemy_usStatus & 0xFFF7;
    }
    else
    {
        v0 = CurrentEnemyData.CurEnemy_usStatus | 8;
    }
    CurrentEnemyData.CurEnemy_usStatus = v0;
}
