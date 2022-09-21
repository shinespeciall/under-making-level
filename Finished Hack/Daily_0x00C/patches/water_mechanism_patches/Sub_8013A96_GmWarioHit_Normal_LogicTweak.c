// @Description tweak a part of code logic in Sub_8013A96_GmWarioHit_Normal
// @HookAddress 0x13CF0
// from 0x13CF0 to 0x13D5C (not include 0x13D5C)
// @HookString 201c0249 8e460249 08470000 5d3d0108 P

/* Patch & Hook details
.thumb
    mov r0, r4 // passing param
    ldr r1, .DATA
    mov lr, r1
    ldr r1, .DATA + 4
    bx r1
    .dcb 1
.DATA:
    .word 0x08013D5D
    .word 0xAAAAAAAA
 */

/**
 * changelog: 
 * directly parsed from the IDA pro's generated C code.
 * add logic to set wario swimming status when he is in water area.
 *            ---- by ssp (shinespeciall), 2022/01/28
 */

#define Wario_ucReact (*(volatile unsigned char*) 0x3001898)
#define Wario_ucStat (*(volatile unsigned char*) 0x3001899)
#define Wario_ucMiss (*(volatile unsigned char*) 0x300189C)
#define Wario_usPosX (*(volatile unsigned short*) 0x30018AA)
#define Wario_usPosY (*(volatile unsigned short*) 0x30018AC)

#define Sub_8012BAC_GmWarioChng ((void (*)(unsigned char)) 0x8012BAD)
#define Sub_8016614_GmWarioChng_Swim ((void (*)(unsigned char)) 0x8016615)
#define Sub_806DAC0_PanelYakuAllNum_TileEventId ((int (*)(unsigned short, unsigned short)) 0x806DAC1)

typedef struct WHitDef
{
    unsigned short usMukiX;   //Ｘ移動方向
    unsigned short usMukiY;   //Ｙ移動方向
    unsigned char ucFront;   //前方当りポジション
    unsigned char ucBack;    //後方当りポジション
    signed short sDX;    //当りによる補正Ｘ

    unsigned char ucSide;    //横壊れ有り
    unsigned char ucHead;    //頭壊れ有り
    unsigned char ucYuka;    //床壊れ有り
    unsigned char ucSPow;    //横壊しのパワー
    unsigned char ucHPow;    //頭
    unsigned char ucYPow;    //床
    unsigned char ucWSide;   //横当りで壊れたとき立てる
    unsigned char ucWHead;   //頭
    unsigned char ucWYuka;   //床
    unsigned char ucPlace;

    unsigned char ucSStop;   //横かべのとき立てる
    unsigned char ucHStop;   //上
    unsigned char ucYStop;   //床
};
#define WHit (*(volatile struct WHitDef*) 0x3001918)

enum WAR_STAT_NORMAL
{
    PHIP = 28,   //パワーヒップアタック (from src\global.h line: 346)
};

void Sub_8013A96_GmWarioHit_Normal_LogicTweak(unsigned char v0)
{
    // exclude some case here to let wario jump out of water on the top surface of some water
    // and in other cases, when wario knock into some water area, set swimming status
    if ( ((Wario_ucReact != 1 && Wario_ucStat != 4) || ((WHit.usMukiY & 0x80) != 0)) 
        && Sub_806DAC0_PanelYakuAllNum_TileEventId(Wario_usPosY, Wario_usPosX) == 1 )
    {
        Wario_ucReact = 1;                      // set swimming wario
        if ( Wario_ucStat == PHIP )
        {
            Sub_8016614_GmWarioChng_Swim(7u);
        }
        else
        {
            if ( (Wario_ucStat - 19) <= 1u )
            {
                Wario_ucMiss = 96;
            }
            Sub_8016614_GmWarioChng_Swim(0);
        }
    }
    else if ( WHit.ucPlace != 0xFF )          // not cannot-move wario, i.e. wario can move
    {
        if ( v0 != 0xFF )
            Sub_8012BAC_GmWarioChng(v0);
        if ( v0 == 0xFE )
            ++Wario_usPosY;
    }
}
