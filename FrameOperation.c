// @Description code will be excute once every frame, modified from UnlimitedRockBouncing
// @HookAddress 0x6C75E
// Mode: Thumb
// Made by Goldensunboy, ssp(shinespeciall)

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

enum enemykind
{
 TAKARABAKO1,    // 00:
 TAKARABAKO2,    // 01:
 TAKARABAKO3,    // 02:
 TAKARABAKO4,    // 03:

 TAKARABAKO_CARD,   // 04:
 TAKARABAKO_BAINOMI,   // 05:
 DAICOIN,     // 06:
 J_SWITCH,     // 07:

 TITEM_KAGI,     // 08:
 TENCHO_SAN,     // 09:
 ITEM_KEMURI_L,    // 10:
 ITEM_KEMURI_M,    // 11:

 ITEM_KEMURI_S,    // 12:
 W_HEART_QUARTER,   // 13:
 BOSS_TAKARABAKO,   // 14:
 KUTIBIRU_NEKO,    // 15:
//------------------------------------set enemy

 ZAKO_TAKARA_BOX_DUMMY,  // 16: zako_takara_box (END code, not used to set enemy)
 ZAKO_MEN_YARI,    // 17: zako_men_yari
 ZAKO_MEN_YARI_BLUE,   // 18: zako_men_yari_blue
 ZAKO_MEN_YARI_RED,   // 19: zako_men_yari_red

 ASIBA_MOKUME,    // 20: asiba_mokume
 ZAKO_IWA,     // 21: zako_iwa
 ZAKO_S_BIRD,    // 22: zako_s_bird
 ZAKO_HITUBO,    // 23: zako_hitubo

 KONTOGE,     // 24: kontoge
 ZAKO_TOTUMEN,    // 25: zako_totumen
 ZAKO_TAKI_FIRE,    // 26: zako_taki_fire
 ZAKO_MOGURAMEN,    // 27: zako_moguramen

 ZAKO_HARIMEN,    // 28: zako_harimen
 ZAKO_HARIMEN_Z,    // 29: zako_harimen_z
 AWAT,      // 30: awat     (spawner)
 ZAKO_TOGEROBO,    // 31: zako_togerobo

 YUKI,      // 32: yuki
 ZAKO_TOGEMASUKU,   // 33: zako_togemasuku
 ZAKO_SPK,     // 34: zako_spk    (spawner)
 ZAKO_YUKA_KIKAI,   // 35: zako_yukakikai

 ZAKO_YUKA_KIKAIPRO_Y,  // 36: zako_yukakikaipro
 ZAKO_YUKA_KIKAIPRO_X,  // 37: zako_yukakikaipro
 ZAKO_JYUUTAN,    // 38: zako_jyuutan
 ZAKO_BOUBA,     // 39: zako_bouba

 ZAKO_ROULETTE,    // 40: zako_roulette
 DOCODOOR,     // 41: docodoor
 ZAKO_MARUMEN,    // 42: zako_marumen
 ZAKO_MARUMEN_Z,    // 43: zako_marumen

 ZAKO_BIG_MARUMEN,   // 44: zako_big_marumen
 ZAKO_DOMINO_DUMMY,   // 45: zako_domino
 ZAKO_DOMINO_RST,   // 46: zako_domino
 ZAKO_DOMINO_LST,   // 47: zako_domino

 ZAKO_DOMINO_R4,    // 48: zako_domino
 ZAKO_DOMINO_L4,    // 49: zako_domino
 ZAKO_DOMINO_R5D1,   // 50: zako_domino
 ZAKO_DOMINO_L5D1,   // 51: zako_domino

 ZAKO_DOMINO_R5U1,   // 52: zako_domino
 ZAKO_DOMINO_L5U1,   // 53: zako_domino
 ZAKO_DOMINO_R3D3,   // 54: zako_domino
 ZAKO_DOMINO_L3D3,   // 55: zako_domino

 ZAKO_DOMINO_R3U3,   // 56: zako_domino
 ZAKO_DOMINO_L3U3,   // 57: zako_domino
 ZAKO_DOMINO_RGL,   // 58: zako_domino
 ZAKO_DOMINO_BLOCK,   // 59: zako_domino_block

 ZAKO_MAYUBIRD,    // 60: zako_mayubird
 ZAKO_KOUMORI,    // 61: zako_koumori
 ZAKO_TOGETOGE,    // 62: zako_togetoge
 ZAKO_GHOST,     // 63: zako_ghost

 ZAKO_HATI,     // 64: zako_hati
 ZAKO_FLOWER,    // 65: zako_flower
 ZAKO_IMOMUSI,    // 66: zako_imomusi
 ZAKO_TUMIKI_3,    // 67: zako_tumiki (triangle)

 ZAKO_TUMIKI_3K,    // 68: zako_tumiki (triangle receptor)
 ZAKO_TUMIKI_4,    // 69: zako_tumiki (rectangle)
 ZAKO_TUMIKI_0,    // 70: zako_tumiki (cylinder)
 ZAKO_TUMIKI_3A,    // 71: zako_tumiki (toy door)

 ZAKO_MENHAMMER,    // 72: zako_menhammer
 ZAKO_MENONO,    // 73: zako_menono
 ZAKO_GUGYO,     // 74: zako_gugyo (horizontal)
 ZAKO_GUGYO_T,    // 75: zako_gugyo (vertical)

 ZAKO_TOBAWANI,    // 76: zako_tobawani
 ZAKO_SHELL,     // 77: zako_shell
 ZAKO_RINGOSUKEY,   // 78: zako_ringosukey
 ZAKO_PISTON_S,    // 79: zako_piston(slow)

 ZAKO_PISTON_F,    // 80: zako_piston(fast)
 DORAMORI,     // 81: doramori
 DOCODOOR_31,    // 82: docodoor_31
 ZAKO_BURANKO_L,    // 83: zako_buranko(long)

 ZAKO_BURANKO_S,    // 84: zako_buranko(short)
 ASIBA_MOKUME2R,    // 85: asiba_mokume2R (CW)
 ASIBA_MOKUME2L,    // 86: asiba_mokume2L (CCW)
 ZAKO_PINBALL_BALL,   // 87: zako_pinball

 ZAKO_PINBALL_ENT,   // 88: zako_pinball (receptor)top
 ZAKO_PINBALL_ENTD,   // 89: zako_pinball (receptor)down
 ZAKO_PINBALL_ENTL,   // 90: zako_pinball (receptor)left
 ZAKO_PINBALL_ENTR,   // 91: zako_pinball (receptor)right

 ZAKO_PINBALL_BLOCK,   // 92: zako_pinball stuck
 ZAKO_ROULETTE_X,   // 93: zako_roulette (hit multiple times)
 ZAKO_PINBALL_TOGE,   // 94: zako_pinball_toge (spawner)
 ZAKO_HIMAWARI,    // 95: zako_himawari

 ZAKO_SNOWMAN,    // 96: zako_snowman
 ZAKO_ROCKMAN,    // 97: zako_rockman
 ZAKO_MAGMA,     // 98: zako_magma
 BOSSTOBIRA0,    // 99: bosstobira

 BOSSTOBIRA1,    // 100: bosstobira
 BOSSTOBIRA2,    // 101: bosstobira
 BOSSTOBIRA3,    // 102: bosstobira
 BOSSTOBIRA4,    // 103: bosstobira

 BOSSTOBIRA5,    // 104: bosstobira
 BOSS_SHITTUKI_PUUTIN,  // 105: sick
 ZAKO_KIYOBU,    // 106: zako_kiyobu
 ZAKO_DENDEN,    // 107: zako_denden

 ZAKO_BUTATABI,    // 108: zako_butatabi
 ZAKO_DEBURINA,    // 109: zako_deburina
 ZAKO_JYABARA,    // 110: zako_jyabara
 ZAKO_PENCIL_P,    // 111: zako_pencil

 ZAKO_PENCIL_B,    // 112: zako_pencil
 ZAKO_PENCIL_R,    // 113: zako_pencil
 ZAKO_ROBOBIRD,    // 114: zako_robobird
 ZAKO_UTUBO,     // 115: zako_utubo

 ZAKO_TOGENOBI,    // 116: zako_togenobi
 ZAKO_TURARA,    // 117: zako_togenobi
 FURAWANA_UEKIBACHI,   // 118: furawana
 ZAKO_DICE,     // 119: zako_dice

 ZAKO_TOY_CAR,    // 120: zako_toy_car
 ZAKO_ONOMY,     // 121: zako_onomy
 ZAKO_NEKO,     // 122: zako_neko
 ZAKO_PETBOTTOM,    // 123: zako_petbottom

 ZAKO_GLASS_BI,    // 124: zako_glass_bi
 MOUJA,      // 125: mouja
 ZAKO_CHANDELIER,   // 126: zako_chandelier
 ZAKO_YUKA_IWA,    // 127: zako_yuka_iwa

 ZAKO_SHITAIN,    // 128: zako_shitain

//-----------------------------child

 OBJCOIN10,     // 00: smallcoin   (child)
 OBJCOIN50,     // --: smallcoin   (child)
 OBJCOIN100,     // --: smallcoin  (child)
 OBJCOIN500,     // --: smallcoin  (child)

 OBJCOIN1000,    // 04: j_diamond (child)
 TAKARA_KAKERA1,    // --:
 TAKARA_KAKERA2,    // --:
 TAKARA_KAKERA3,    // --:

 TAKARA_KAKERA4,    // 08:
 TAKARA_CARD,    // --:
 TAKARA_BAINOMI,    // --:
 HIKARI_KAKERA1,    // --:

 HIKARI_KAKERA2,    // 12:
 HIKARI_KAKERA3,    // --:
 HIKARI_KAKERA4,    // --:
 HIKARI_CARD,    // --:

 HIKARI_BAINOMI,    // 16:
 ZAKO_HITUBO_FIRE,   // --: zako_hitubo_fire1 (child)
 ZAKO_HITUBO_FIRE2,   // --: zako_hitubo_fire2 (child)
 ASIBA_MOKUME_YUKA3J,  // --: asiba_mokume   (child)

 ASIBA_MOKUME_YUKA6J,  // 20: asiba_mokume   (child)
 ASIBA_MOKUME_YUKA9J,  // --: asiba_mokume   (child)
 ASIBA_MOKUME_YUKA12J,  // --: asiba_mokume   (child)
 ZAKO_S_BIRD_TAMA,   // --: zako_s_bird   (child)

 ZAKO_S_BIRD_HONE,   // 24: zako_s_bird   (child)
 ZAKO_MOGURAMEN_IWA,   // --: zako_moguramen  (child)
 AWAT_CHILD,     // --: awat     (child)
 ZAKO_TOGEROBO_HEAD,   // --: zako_togerobo  (child)

 YUKI_CHILD_KAKERA,   // 28: yuki     (child)
 YUKI_CHILD_HARF,   // --: yuki     (child)
 ZAKO_SPK_CHILD,    // --: zako_spk    (child)
 ZAKO_SPK_CHILD2,   // --: zako_spk    (child)

 ZAKO_BOUBA_ARROW,   // 32: zako_bouba   (child)
 ZAKO_ROULETTE_STAR,   // --: zako_roulette  (child)
 DOCODOOR_UZU_BIG_A,   // --: docodoor    (child)
 DOCODOOR_UZU_BIG_B,   // --: docodoor    (child)

 DOCODOOR_UZU_MID_A,   // 36: docodoor    (child)
 DOCODOOR_UZU_MID_B,   // --: docodoor    (child)
 ZAKO_GHOST_UDE,    // --: zako_ghost   (child)
 ZAKO_GHOST_KAGI,   // --: zako_ghost   (child)

 ZAKO_TOTUMEN_PINKIE,  // 40: zako_totumen_pinkieピンキー用 (child)
 J_SWITCH_STAR,    // --: j_switch    (child)
 MOUJA_RING,     // --: mouja    (child)
 ZAKO_BURANKO_L_ASHIBA,  // --: zako_buranko   (child)

 ZAKO_BURANKO_S_ASHIBA,  // 44: zako_buranko   (child)
 ASIBA_MOKUME2R_YUKA3J,  // --: asiba_mokume2  (child)
 ASIBA_MOKUME2R_YUKA9J,  // --: asiba_mokume2  (child)
 ASIBA_MOKUME2L_YUKA3J,  // --: asiba_mokume2  (child)

 ASIBA_MOKUME2L_YUKA9J,  // 48: asiba_mokume2  (child)
 ZAKO_RINGOSUKEY_APPLE,  // --: zako_ringosukey  (child)
 DOCODOOR_WARIO_IN,   // --: docodoor    (child)
 DOCODOOR_WARIO_OUT,   // --: docodoor    (child)

 ZAKO_PINBALL_STAR,   // 52: zako_pinball   (child)
 ZAKO_TAKI_FIRE_CHILD,  // --: zako_taki_fire  (child)
 OBJCOIN1000RT,    // --: dcoin    (child)ルーレット用
 ZAKO_PINBALL_TOGE_CHILD, // --: zako_pinball_toge (child)

 ZAKO_PISTON_CHILD,   // 56: zako_piston   (child)
 ZAKO_ROCKMAN_IWA,   // --: zako_rockman   (child)
 ZAKO_SNOWMAN_REIKI,   // --: zako_snowman   (child)
 ITEM_BOMB,     // --: item_bomb   (child)

 KONTOGE_DENKI,    // 60: kontoge    (child)
 ITEM_CANON,     // --: item_canon   (child)
 ITEM_WHITEMAN,    // --: item_whiteman  (child)
 ITEM_MUSIC,     // --: item_music   (child)

 ITEM_DOG,     // 64: item_dog    (child)
 ITEM_KISS,     // --: item_kiss   (child)
 ITEM_GENKOTU,    // --: item_genkotu   (child)
 ITEM_DRAGON,    // --: item_dragon   (child)

 ITEM_CANON_TAMA,   // 68: item_canon   (child)
 ITEM_WHITEMAN_BEAM_A,  // --: item_whiteman  (child)
 ITEM_WHITEMAN_BEAM_B,  // --: item_whiteman  (child)
 KONTOGE_NOKOGIRI,   // ---: kontoge    (child)

 ITEM_KISS_HEART,   // 72: item_kiss   (child)
 ITEM_DRAGON_FIRE,   // --: item_dragon   (child)
 BOSS_SHITTUKI,    // --: シッキー    (child)
 BOSS_PUUTIN_ATARI,   // --: シッキー    (child)

 SHITTUKI_TOGEDON,   // 76: シッキー    (child)
 SHITTUKI_FIRE,    // --: シッキー    (child)
 BOSS_JEWEL,     // --: シッキー(全ボス共通) (child)
 ZAKO_KIYOBU_KEMURI,   // --: zako_kiyobu   (child)

 ZAKO_DENDEN_TAMA,   // 80: zako_denden   (child)
 ZAKO_DEBURINA_TOGE,   // --: zako_deburina  (child)
 DOCODOOR_KAGI_OUT,   // --: docodoor    (child)
 ZAKO_TOGENOBI_ARM,   // --: zako_togenobi  (child)

 ZAKO_TOGENOBI_TOGE,   // 84: zako_togenobi  (child)
 ZAKO_TOGENOBI_TAKO,   // --: zako_togenobi  (child)
 ZAKO_TURARA_KAKERA,   // --: zako_turara   (child)
 FURAWANA_HEAD,    // --: furawana_head  (child)

 FURAWANA_BODY,    // 88: furawana    (child)
 FURAWANA_OUKAN,    // --: furawana    (child)
 FURAWANA_UDE_R,    // --: furawana    (child)
 FURAWANA_UDE_L,    // --: furawana    (child)

 FURAWANA_BUBUBAE,   // 92: furawana    (child)
 FURAWANA_BUBUBAE_HIKARI, // --: furawana    (child)
 FURAWANA_YODARE,   // --: furawana    (child)
 DORAMORI_DORIZAME,   // --: doramori    (child)

 DORAMORI_TUNAMI,   // 96: doramori    (child)
 DORAMORI_TUNAMI_SHIBUKI, // --: doramori    (child)
 DORAMORI_ICE_KEMURI,  // --: doramori    (child)
 DORAMORI_ICE,    // --: doramori    (child)

 KONTOGE_KAZAMIDORI,   // 100: kontoge    (child)
 KONTOGE_ENTOTU,    // ---: kontoge    (child)
 KONTOGE_ARM,    // ---: kontoge    (child)
 KONTOGE_FURIKO,    // ---: kontoge    (child)

 KONTOGE_EGG,    // 104: kontoge    (child)
 KONTOGE_PIYO,    // ---: kontoge    (child)
 ZAKO_GLASS_BI_TAMA,   // ---: zako_glass_bi  (child)
 MOUJA_FACE,     // ---: mouja

 MOUJA_BODY,     // 108: mouja    (child)
 MOUJA_ARM,     // ---: mouja    (child)
 MOUJA_OMEN,     // ---: mouja    (child)
 MOUJA_OMEN_TAMA,   // ---: mouja    (child)

 MOUJA_SENSU,    // 112: mouja    (child)
 MOUJA_ZAKO_HAMMER,   // ---: mouja    (child)
 MOUJA_ZAKO_KURAGE,   // ---: mouja    (child)
 MOUJA_ZAKO_EGG,    // ---: mouja    (child)

 MOUJA_ZAKO_PIYO,   // 116: mouja    (child)
 MOUJA_ZAKO_BALL,   // ---: mouja    (child)
 MOUJA_KUTIBIRU,    // ---: mouja    (child)
 MOUJA_STAR,     // ---: mouja    (child)

 FURAWANA_KUSAIIKI,   // 120: mouja    (child)
 ZAKO_SHITAIN_AWA,   // ---: zako_shitain  (child)
 DORAMORI_HEAD_ATARI,  // ---: doramori   (child)
};

struct OAM_REC {
    char PAD[2];
    unsigned char EntityID;
};

#define OAM ((volatile struct OAM_REC*) 0x3000964)

struct ENTITY_REC {
    unsigned short usStatus;
    char PAD[6];
    short YPos;
    short XPos;
    char PAD1[0xB];
    unsigned char EntityID;
    char PAD2[0xD];
    unsigned char HitboxX0;
    char PAD3[6];
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
#define Layer0_Width (*(volatile unsigned short*) 0x3000058)
#define Layer0_Height (*(volatile unsigned short*) 0x300005A)
#define Layer1_DecompressedDataPointer (*(volatile unsigned int*) 0x300005C)
#define Layer1_Width (*(volatile unsigned short*) 0x3000060)
#define Layer1_Height (*(volatile unsigned short*) 0x3000062)
#define Layer2_DecompressedDataPointer (*(volatile unsigned int*) 0x3000064)
#define Layer2_Width (*(volatile unsigned short*) 0x3000068)
#define Layer2_Height (*(volatile unsigned short*) 0x300006A)
#define CurrentTileset_EventIdTablePointer (*(volatile unsigned int*) 0x30031FC)
#define CurrentRoomHeader_Layer0MappingType (*(volatile unsigned char*) 0x3000075)

#define myflag_Iscounting (*(volatile unsigned char*) 0x30000E6)

#define cGmStartFlg (*(volatile unsigned char*) 0x3000C3F)
#define cPauseFlag (*(volatile unsigned char*) 0x3000C35)
#define soft_reset (*(volatile unsigned char*) 0x300001E)
#define ADDR_KEY_4 (*(volatile unsigned short*) 0x3001848)


void FrameOperations()
{
    // vanilla code for animated tiles loading
    if ( (GameState == 2 || GameState == 6 || GameState == 4 && unk_300001B == 1) && !unk_3000046 )
    {
        sub_806E08C();
    }

    // Customized code (including everything below)

    // Process all active entities
    for(int i = 0; i < 24; ++i)
    {
        // looser condition check (from Sub_801D684_EnemyMain)
        // now all the runtime enemies should be able to work with this loop
        // but not limited by current Entitylist's enemy number
        // this makes the patch more compatible with some patches spawning random enemies in the current room
        if ((ENTITIES[i].usStatus & 1) == 0)
        {
            continue;
        }

        // If it is a Rock or an Arewo Shitain-Hakase, reset its bounce state
        if (ENTITIES[i].EntityID == 0x15 ||ENTITIES[i].EntityID == 0x80)
        {
            ENTITIES[i].usStatus = 0x100 | (ENTITIES[i].usStatus & 0xFF);
        }

        // TODO -----------------------------
        int enemy_bottom_X = (ENTITIES[i].XPos << 16) >> 22;
        int enemy_bottom_XL = ((ENTITIES[i].XPos - ENTITIES[i].HitboxX0) << 16) >> 22;
        int enemy_bottom_XR = ((ENTITIES[i].XPos + ENTITIES[i].HitboxX0) << 16) >> 22;
        int enemy_bottom_Y = (ENTITIES[i].YPos << 16) >> 22;
        int eventtileId = *(unsigned short*)(2 * \
                                *(unsigned short*)(2 * (enemy_bottom_Y * Layer1_Width + (enemy_bottom_X - 1)) + \
                                Layer1_DecompressedDataPointer) + \
                                CurrentTileset_EventIdTablePointer);
        int eventtileId2 = *(unsigned short*)(2 * \
                                *(unsigned short*)(2 * (enemy_bottom_Y * Layer1_Width + (enemy_bottom_X + 1)) + \
                                Layer1_DecompressedDataPointer) + \
                                CurrentTileset_EventIdTablePointer);
        int eventtileId_itemL = *(unsigned short*)(2 * \
                                *(unsigned short*)(2 * (enemy_bottom_Y * Layer1_Width + (enemy_bottom_XR)) + \
                                Layer1_DecompressedDataPointer) + \
                                CurrentTileset_EventIdTablePointer);
        int eventtileId_itemR = *(unsigned short*)(2 * \
                                *(unsigned short*)(2 * (enemy_bottom_Y * Layer1_Width + (enemy_bottom_XL)) + \
                                Layer1_DecompressedDataPointer) + \
                                CurrentTileset_EventIdTablePointer);
        switch (ENTITIES[i].EntityID)
        {
        case ZAKO_MEN_YARI: // won't fall down from the edge of the conveyer belt
        case ZAKO_MEN_YARI_BLUE:
        case ZAKO_MEN_YARI_RED:
        case ZAKO_HITUBO:
        case ZAKO_TOTUMEN:
        case ZAKO_MOGURAMEN:
        case ZAKO_HARIMEN:
        case ZAKO_HARIMEN_Z:
        case ZAKO_TOGEROBO:
        case ZAKO_JYUUTAN:
        case ZAKO_MARUMEN:
        case ZAKO_MARUMEN_Z:
        case ZAKO_BIG_MARUMEN:
        case ZAKO_IMOMUSI:
        case ZAKO_MENHAMMER:
        case ZAKO_MENONO:
        case ZAKO_RINGOSUKEY:
        case ZAKO_SNOWMAN:
        case ZAKO_ROCKMAN:
        case ZAKO_DENDEN:
        case ZAKO_DICE:
        case ZAKO_TOY_CAR:
        case ZAKO_ONOMY:
        case ZAKO_NEKO:
        case ZAKO_PETBOTTOM:
        case ZAKO_SHITAIN:
        {
            if (eventtileId == 0x6A) // conveyer push things to the left side
            {
                ENTITIES[i].XPos -= 2;
            }
            else if (eventtileId2 == 0x6B)// conveyer push things to the right side
            {
                ENTITIES[i].XPos += 2;
            }
            break;
        }
        case J_SWITCH: // will fall down from the edge of the conveyer belt
        case ZAKO_IWA:
        case ZAKO_TUMIKI_3:
        // case ZAKO_TUMIKI_4: // this cannot work correctly without extra patch on Sub_8043138_EntityAI_0x45_Tmain_zako_tumiki_4
        case ZAKO_TUMIKI_0:
        case ZAKO_PINBALL_BALL:
        {
            if (eventtileId_itemL == 0x6A) // conveyer push things to the left side
            {
                ENTITIES[i].XPos -= 2;
            }
            else if (eventtileId_itemR == 0x6B) // conveyer push things to the right side
            {
                ENTITIES[i].XPos += 2;
            }
            break;
        }
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
