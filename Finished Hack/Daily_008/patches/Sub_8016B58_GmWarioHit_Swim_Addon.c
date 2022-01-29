// @Description Add some extra code to Sub_8016B58_GmWarioHit_Swim
// @HookAddress 0x16D62
// from 0x16D62 to 0x16DF4
// @HookString 0248 86460248 00470000 f56d0108 P

/* Patch & Hook details
 
 .thumb
    .dcb 1
    ldr r0, .DATA
    mov lr, r0
    ldr r0, .DATA + 4
    bx r0
    .dcb 1
  .DATA:
    .word 0x08016DF5
    .word 0xAAAAAAAA
 */

/**
 * changelog: 
 * directly parsed from the IDA pro's generated C code.
 * add logic to let wario get rid of water status on the side.
 *            ---- by ssp (shinespeciall), 2022/01/25
 * Fix wario cannot get rid of water status 
 * from the bottom of water area.
 *            ---- by ssp (shinespeciall), 2022/01/26
 */

#define Wario_ucReact (*(volatile unsigned char*) 0x3001898)
#define Wario_ucStat (*(volatile unsigned char*) 0x3001899)
#define Wario_ucMiss (*(volatile unsigned char*) 0x300189C)
#define Wario_usPosX (*(volatile unsigned short*) 0x30018AA)
#define Wario_usPosY (*(volatile unsigned short*) 0x30018AC)
#define Wario_sMvSpeedY (*(volatile signed short*) 0x30018B0)
#define WarBk_ucStat (*(volatile unsigned char*) 0x30018D5)

#define Sub_8001DA4_m4aSongNumStart ((void (*)(unsigned int)) 0x8001DA5)

// didn't double-check the ret and input variable types, directly parsed from IDA pro
#define Sub_8015BA8_WarChngCheck ((signed int (*)(signed int)) 0x8015BA9)
#define Sub_8016614_GmWarioChng_Swim ((void (*)(unsigned char)) 0x8016615)

// globalId, RoomEnemySlotId, ChrOfs, us_YPos, us_XPos, usStatus
#define Sub_801E3A8_EnemyChildSet_LR ((void (*)(unsigned char, unsigned char, unsigned char, unsigned short, unsigned short, int)) 0x801E3A9)
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

enum uskoka_enum
{
    YK_Nothing,
    YK_Water,
};

#define WarioChng_React ((volatile unsigned int*) 0x82DECA0)
#define Sub_8094E00_call_via_r1 ((int (*)(int*, int)) 0x8094E01)

void Sub_8016B58_GmWarioHit_Swim_Addon()
{
    // vanilla part
    if ( Wario_ucStat != 4 )
    {
        if ( Wario_ucStat > 4u )
        {
            if ( Wario_ucStat == 7 || Wario_ucStat == 12 )
                return;
        }
        else if ( !Wario_ucStat )
        {
            return;
        }
        if ( !Sub_806DAC0_PanelYakuAllNum_TileEventId((Wario_usPosY - 0x30), Wario_usPosX) )// if hollow tile above wario's head
        {
            if ( Wario_ucStat == 6 )
            {
                Wario_sMvSpeedY = 0;
            }
            else if ( Wario_ucStat == 14 ) // balloon wario
            {
                Sub_8016614_GmWarioChng_Swim(0);
                Wario_ucMiss = 96;
                Sub_8001DA4_m4aSongNumStart(364);
                Sub_801E3A8_EnemyChildSet_LR(155, 0, 0, Wario_usPosY, Wario_usPosX, 64);
            }
            else
            {
                Sub_8016614_GmWarioChng_Swim(4u);       // wario has floated up to the water surface
            }
            Wario_usPosY = ((Wario_usPosY - 48) & 0xFFC0) + 96;
        }
    }

    // custom code to let wario get rid of swimming status
    if ( (!(WHit.usMukiY & 0x80) || !(WHit.usMukiX & 0x80)) && Sub_806DAC0_PanelYakuAllNum_TileEventId(Wario_usPosY, Wario_usPosX) == YK_Nothing )
    {
        Wario_ucReact = 0;
        Sub_8094E00_call_via_r1(0, 0x8012BAD);      // WarioChng_React[0]
        Wario_ucStat = 4;
        WarBk_ucStat = 4;
    }
}
