// @Description modify Sub_804C89C_EntityAI_0x5E_Tmain_zako_pinball_toge
// @HookAddress 0x78E978
// called by refering to AI pointer table
// @HookString P

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

enum Event_ID
{
    // custom part
    YT_spikeball_goes_up_left = 0xA1,
    YT_spikeball_goes_up,
    YT_spikeball_goes_up_right,
    YT_spikeball_goes_left,
    YT_spikeball_goes_right,
    YT_spikeball_goes_down_left,
    YT_spikeball_goes_down,
    YT_spikeball_goes_down_right,
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

#define CurrentTileset_EventIdTablePointer (*(volatile unsigned short**) 0x30031FC)
#define Layer1_Width (*(volatile unsigned short*) 0x3000060)
#define Layer1_Height (*(volatile unsigned short*) 0x3000062)
#define Layer2_DecompressedDataPointer (*(volatile unsigned short**) 0x3000064)
#define Layer2_Width (*(volatile unsigned short*) 0x3000068)

#define ENTITIES ((volatile struct EnemyDataStructure*) 0x3000104)
#define CurrentEnemyData (*(volatile struct EnemyDataStructure*) 0x3000A24)

#define GO_DOWN 0
#define GO_UP 1
#define DISABLE_LR 2
#define DISABLE_UD 4

#define offset_y_to_spawn_spikeball 0x20

// #define Sub_80262BC_EnemyWarioSerch2_V ((unsigned int (*)(int, int)) 0x80262BD)
#define Rewrite_Sub_806DD44_PanelYakuNum_Teki ((unsigned int (*)(unsigned short, unsigned short)) 0x806DD45)
#define Terrain_usEnemySpecified (*(volatile unsigned short*) 0x30000a4)
#define Sub_8001DA4_m4aSongNumStart ((void (*)(unsigned short)) 0x8001DA5)

 // {2 oam are used in this frame, oam0_0, oam0_1, oam0_2, oam1_0, oam1_1, oam1_2}, then end by 0
 // all character ids need to be added by 0x200, and all palette ids need to be added by 8. this rule works for all regular enemy AI (except bosses)
const unsigned short No_Animation[] = {0x2, 0xF0, 0x41F6, 0x8200, 0x80F0, 0x6, 0x8202, 0 } ;
const unsigned int oam_data_table[] = {No_Animation, 1, 0, 0}; // {oam data pointer, frame num}

void Sub_804C89C_EntityAI_0x5E_Tmain_zako_pinball_toge()
{
    if ( CurrentEnemyData.CurEnemy_CurrentAnimationId > 0xFu )
    {
        if ( CurrentEnemyData.CurEnemy_CurrentAnimationId == K0_WALK )
        {
            --CurrentEnemyData.CurEnemy_TWork0;
            
            if ( !CurrentEnemyData.CurEnemy_TWork0 )
            {
                CurrentEnemyData.CurEnemy_usStatus |= 4u;
                
                unsigned int v8; // r3
                struct EnemyDataStructure *v9; // r2

                unsigned short y_pos = CurrentEnemyData.CurEnemy_YPos >> 6;
                unsigned short x_pos = CurrentEnemyData.CurEnemy_XPos >> 6;
                y_pos -= 1;
                
                // goes up left
                int event_id = CurrentTileset_EventIdTablePointer[ \
                                Layer2_DecompressedDataPointer[Layer2_Width * (y_pos - 1) + x_pos - 1]];
                if (event_id == YT_spikeball_goes_up_left)
                {
                    v8 = 0;
                    while ( 1 )
                    {
                        v9 = &ENTITIES[v8];
                        if ( (v9->CurEnemy_usStatus & 1) == 0 )
                            break;
                        v8++;
                        if ( v8 > 0x17 )
                            goto DontCreateSpikeBall;
                    }
                    v9->CurEnemy_usStatus = 0 | 0x17;
                    v9->CurEnemy_ucChrOfs = CurrentEnemyData.CurEnemy_ucChrOfs;
                    v9->CurEnemy_GlobalId = 0xB8;
                    v9->CurEnemy_YPos = CurrentEnemyData.CurEnemy_YPos - offset_y_to_spawn_spikeball;
                    v9->CurEnemy_XPos = CurrentEnemyData.CurEnemy_XPos;
                    v9->CurEnemy_RoomEntitySlotId = CurrentEnemyData.CurEnemy_RoomEntitySlotId;
                    v9->CurEnemy_Prio = 2;
                    v9->CurEnemy_CurrentAnimationId = 0;
                    v9->CurEnemy_Life = 0;
                    v9->CurEnemy_paletteId = 0;
                    v9->CurEnemy_DisableInteractionWithWarioCountdown = 1;
                    v9->CurEnemy_padding = GO_UP;
                }

                // goes up
                event_id = CurrentTileset_EventIdTablePointer[ \
                            Layer2_DecompressedDataPointer[Layer2_Width * (y_pos - 1) + x_pos]];
                if (event_id == YT_spikeball_goes_up)
                {
                    v8 = 0;
                    while ( 1 )
                    {
                        v9 = &ENTITIES[v8];
                        if ( (v9->CurEnemy_usStatus & 1) == 0 )
                            break;
                        v8++;
                        if ( v8 > 0x17 )
                            goto DontCreateSpikeBall;
                    }
                    v9->CurEnemy_usStatus = 0 | 0x17;
                    v9->CurEnemy_ucChrOfs = CurrentEnemyData.CurEnemy_ucChrOfs;
                    v9->CurEnemy_GlobalId = 0xB8;
                    v9->CurEnemy_YPos = CurrentEnemyData.CurEnemy_YPos - offset_y_to_spawn_spikeball;
                    v9->CurEnemy_XPos = CurrentEnemyData.CurEnemy_XPos;
                    v9->CurEnemy_RoomEntitySlotId = CurrentEnemyData.CurEnemy_RoomEntitySlotId;
                    v9->CurEnemy_Prio = 2;
                    v9->CurEnemy_CurrentAnimationId = 0;
                    v9->CurEnemy_Life = 0;
                    v9->CurEnemy_paletteId = 0;
                    v9->CurEnemy_DisableInteractionWithWarioCountdown = 1;
                    v9->CurEnemy_padding = GO_UP | DISABLE_LR;
                }

                // goes up right
                event_id = CurrentTileset_EventIdTablePointer[ \
                            Layer2_DecompressedDataPointer[Layer2_Width * (y_pos - 1) + x_pos + 1]];
                if (event_id == YT_spikeball_goes_up_right)
                {
                    v8 = 0;
                    while ( 1 )
                    {
                        v9 = &ENTITIES[v8];
                        if ( (v9->CurEnemy_usStatus & 1) == 0 )
                            break;
                        v8++;
                        if ( v8 > 0x17 )
                            goto DontCreateSpikeBall;
                    }
                    v9->CurEnemy_usStatus = 0x40 | 0x17;
                    v9->CurEnemy_ucChrOfs = CurrentEnemyData.CurEnemy_ucChrOfs;
                    v9->CurEnemy_GlobalId = 0xB8;
                    v9->CurEnemy_YPos = CurrentEnemyData.CurEnemy_YPos - offset_y_to_spawn_spikeball;
                    v9->CurEnemy_XPos = CurrentEnemyData.CurEnemy_XPos;
                    v9->CurEnemy_RoomEntitySlotId = CurrentEnemyData.CurEnemy_RoomEntitySlotId;
                    v9->CurEnemy_Prio = 2;
                    v9->CurEnemy_CurrentAnimationId = 0;
                    v9->CurEnemy_Life = 0;
                    v9->CurEnemy_paletteId = 0;
                    v9->CurEnemy_DisableInteractionWithWarioCountdown = 1;
                    v9->CurEnemy_padding = GO_UP;
                }

                // goes left
                Rewrite_Sub_806DD44_PanelYakuNum_Teki(y_pos, x_pos - 1);
                event_id = CurrentTileset_EventIdTablePointer[ \
                            Layer2_DecompressedDataPointer[Layer2_Width * y_pos + x_pos - 1]];
                if (event_id == YT_spikeball_goes_left)
                {
                    v8 = 0;
                    while ( 1 )
                    {
                        v9 = &ENTITIES[v8];
                        if ( (v9->CurEnemy_usStatus & 1) == 0 )
                            break;
                        v8++;
                        if ( v8 > 0x17 )
                            goto DontCreateSpikeBall;
                    }
                    v9->CurEnemy_usStatus = 0 | 0x17;
                    v9->CurEnemy_ucChrOfs = CurrentEnemyData.CurEnemy_ucChrOfs;
                    v9->CurEnemy_GlobalId = 0xB8;
                    v9->CurEnemy_YPos = CurrentEnemyData.CurEnemy_YPos - offset_y_to_spawn_spikeball;
                    v9->CurEnemy_XPos = CurrentEnemyData.CurEnemy_XPos;
                    v9->CurEnemy_RoomEntitySlotId = CurrentEnemyData.CurEnemy_RoomEntitySlotId;
                    v9->CurEnemy_Prio = 2;
                    v9->CurEnemy_CurrentAnimationId = 0;
                    v9->CurEnemy_Life = 0;
                    v9->CurEnemy_paletteId = 0;
                    v9->CurEnemy_DisableInteractionWithWarioCountdown = 1;
                    v9->CurEnemy_padding = DISABLE_UD;
                }

                // goes right
                Rewrite_Sub_806DD44_PanelYakuNum_Teki(y_pos, x_pos + 1);
                event_id = CurrentTileset_EventIdTablePointer[ \
                            Layer2_DecompressedDataPointer[Layer2_Width * y_pos + x_pos + 1]];
                if (event_id == YT_spikeball_goes_right)
                {
                    v8 = 0;
                    while ( 1 )
                    {
                        v9 = &ENTITIES[v8];
                        if ( (v9->CurEnemy_usStatus & 1) == 0 )
                            break;
                        v8++;
                        if ( v8 > 0x17 )
                            goto DontCreateSpikeBall;
                    }
                    v9->CurEnemy_usStatus = 0x40 | 0x17;
                    v9->CurEnemy_ucChrOfs = CurrentEnemyData.CurEnemy_ucChrOfs;
                    v9->CurEnemy_GlobalId = 0xB8;
                    v9->CurEnemy_YPos = CurrentEnemyData.CurEnemy_YPos - offset_y_to_spawn_spikeball;
                    v9->CurEnemy_XPos = CurrentEnemyData.CurEnemy_XPos;
                    v9->CurEnemy_RoomEntitySlotId = CurrentEnemyData.CurEnemy_RoomEntitySlotId;
                    v9->CurEnemy_Prio = 2;
                    v9->CurEnemy_CurrentAnimationId = 0;
                    v9->CurEnemy_Life = 0;
                    v9->CurEnemy_paletteId = 0;
                    v9->CurEnemy_DisableInteractionWithWarioCountdown = 1;
                    v9->CurEnemy_padding = DISABLE_UD;
                }

                // goes down left
                Rewrite_Sub_806DD44_PanelYakuNum_Teki(y_pos + 1, x_pos - 1);
                event_id = CurrentTileset_EventIdTablePointer[ \
                            Layer2_DecompressedDataPointer[Layer2_Width * (y_pos + 1) + x_pos - 1]];
                if (event_id == YT_spikeball_goes_down_left)
                {
                    v8 = 0;
                    while ( 1 )
                    {
                        v9 = &ENTITIES[v8];
                        if ( (v9->CurEnemy_usStatus & 1) == 0 )
                            break;
                        v8++;
                        if ( v8 > 0x17 )
                            goto DontCreateSpikeBall;
                    }
                    v9->CurEnemy_usStatus = 0 | 0x17;
                    v9->CurEnemy_ucChrOfs = CurrentEnemyData.CurEnemy_ucChrOfs;
                    v9->CurEnemy_GlobalId = 0xB8;
                    v9->CurEnemy_YPos = CurrentEnemyData.CurEnemy_YPos - offset_y_to_spawn_spikeball;
                    v9->CurEnemy_XPos = CurrentEnemyData.CurEnemy_XPos;
                    v9->CurEnemy_RoomEntitySlotId = CurrentEnemyData.CurEnemy_RoomEntitySlotId;
                    v9->CurEnemy_Prio = 2;
                    v9->CurEnemy_CurrentAnimationId = 0;
                    v9->CurEnemy_Life = 0;
                    v9->CurEnemy_paletteId = 0;
                    v9->CurEnemy_DisableInteractionWithWarioCountdown = 1;
                    v9->CurEnemy_padding = GO_DOWN;
                }

                // goes down
                Rewrite_Sub_806DD44_PanelYakuNum_Teki(y_pos + 1, x_pos);
                event_id = CurrentTileset_EventIdTablePointer[ \
                            Layer2_DecompressedDataPointer[Layer2_Width * (y_pos + 1) + x_pos]];
                if (event_id == YT_spikeball_goes_down)
                {
                    v8 = 0;
                    while ( 1 )
                    {
                        v9 = &ENTITIES[v8];
                        if ( (v9->CurEnemy_usStatus & 1) == 0 )
                            break;
                        v8++;
                        if ( v8 > 0x17 )
                            goto DontCreateSpikeBall;
                    }
                    v9->CurEnemy_usStatus = 0 | 0x17;
                    v9->CurEnemy_ucChrOfs = CurrentEnemyData.CurEnemy_ucChrOfs;
                    v9->CurEnemy_GlobalId = 0xB8;
                    v9->CurEnemy_YPos = CurrentEnemyData.CurEnemy_YPos - offset_y_to_spawn_spikeball;
                    v9->CurEnemy_XPos = CurrentEnemyData.CurEnemy_XPos;
                    v9->CurEnemy_RoomEntitySlotId = CurrentEnemyData.CurEnemy_RoomEntitySlotId;
                    v9->CurEnemy_Prio = 2;
                    v9->CurEnemy_CurrentAnimationId = 0;
                    v9->CurEnemy_Life = 0;
                    v9->CurEnemy_paletteId = 0;
                    v9->CurEnemy_DisableInteractionWithWarioCountdown = 1;
                    v9->CurEnemy_padding = GO_DOWN | DISABLE_LR;
                }

                // goes down right
                event_id = CurrentTileset_EventIdTablePointer[ \
                            Layer2_DecompressedDataPointer[Layer2_Width * (y_pos + 1) + x_pos + 1]];
                if (event_id == YT_spikeball_goes_down_right)
                {
                    v8 = 0;
                    while ( 1 )
                    {
                        v9 = &ENTITIES[v8];
                        if ( (v9->CurEnemy_usStatus & 1) == 0 )
                            break;
                        v8++;
                        if ( v8 > 0x17 )
                            goto DontCreateSpikeBall;
                    }
                    v9->CurEnemy_usStatus = 0x40 | 0x17;
                    v9->CurEnemy_ucChrOfs = CurrentEnemyData.CurEnemy_ucChrOfs;
                    v9->CurEnemy_GlobalId = 0xB8;
                    v9->CurEnemy_YPos = CurrentEnemyData.CurEnemy_YPos - offset_y_to_spawn_spikeball;
                    v9->CurEnemy_XPos = CurrentEnemyData.CurEnemy_XPos;
                    v9->CurEnemy_RoomEntitySlotId = CurrentEnemyData.CurEnemy_RoomEntitySlotId;
                    v9->CurEnemy_Prio = 2;
                    v9->CurEnemy_CurrentAnimationId = 0;
                    v9->CurEnemy_Life = 0;
                    v9->CurEnemy_paletteId = 0;
                    v9->CurEnemy_DisableInteractionWithWarioCountdown = 1;
                    v9->CurEnemy_padding = GO_DOWN;
                }

DontCreateSpikeBall:
                CurrentEnemyData.CurEnemy_TWork0 = 60;
                CurrentEnemyData.CurEnemy_CurrentAnimationId = 0;
            }
        }
    }
    else
    {
        // init
        // CurrentEnemyData.CurEnemy_usStatus |= 0x404u;
        CurrentEnemyData.CurEnemy_usStatus = 0x3;
        CurrentEnemyData.CurEnemy_SizeY0_Bottom = 1;
        CurrentEnemyData.CurEnemy_SizeY1_Top = 1;
        CurrentEnemyData.CurEnemy_SizeX_LeftRight = 1;
        CurrentEnemyData.CurEnemy_HitboxY0 = 1;
        CurrentEnemyData.CurEnemy_HitboxY1 = 1;
        CurrentEnemyData.CurEnemy_HitboxX0 = 1;
        CurrentEnemyData.CurEnemy_HitboxX1 = 1;
        CurrentEnemyData.OAMDataPackPointerForCurrentAnimation = oam_data_table;
        CurrentEnemyData.CurEnemy_RealFrameCountForCurrentAnimationFrame = 0;
        CurrentEnemyData.CurEnemy_CurrentAnimationFrameId = 0;
        CurrentEnemyData.CurEnemy_CurrentAnimationId = K0_WALK;
        CurrentEnemyData.CurEnemy_GuardAndDamageParam = 0;
        CurrentEnemyData.CurEnemy_TWork0 = 60;
        CurrentEnemyData.CurEnemy_Prio = 1;
    }
}