// @Description rewrite Sub_806E7F8_GmScrSet
// @HookAddress 0x6E7FA
// from 0x6E7FA to 0x6E8D8, no passed-in param
// @HookString 024a 9646024a 10470000 d9e80608 P
// @EntryFunctionSymbol Sub_806E7F8_GmScrSet

/* Patch & Hook details
 
 .thumb
    .dcb 1
    ldr r2, .DATA
    mov lr, r2
    ldr r2, .DATA + 4
    bx r2
    .dcb 1
  .DATA:
    .word 0x0806E8D9
    .word 0xAAAAAAAA
 */

/**
 * changelog: 
 * directly modified from the IDA pro's generated C code.
 * add logic to asynchronize Layer 0 and Layer 3.
 *            ---- by ssp (shinespeciall), 2022/09/01
 */

#define unk_300004C (*(volatile unsigned char*) 0x300004C) // some debug mode stuff

#define CurrentRoomHeader_Layer0MappingType (*(volatile unsigned char*) 0x3000075)
#define CurrentRoomHeader_Layer1MappingType (*(volatile unsigned char*) 0x3000076)
#define CurrentRoomHeader_Layer2MappingType (*(volatile unsigned char*) 0x3000077)
#define CurrentRoomHeader_CameraControlTypeFlag (*(volatile unsigned char*) 0x300008C)

#define sGameSeq (*(volatile unsigned short*) 0x3000C3C)

#define usBg0Hofs (*(volatile unsigned short*) 0x3001876)
#define usBg0Vofs (*(volatile unsigned short*) 0x3001878)
#define usBg1Hofs_CameraXPos (*(volatile unsigned short*) 0x300187A)
#define usBg1Vofs_CameraYPos (*(volatile unsigned short*) 0x300187C)
#define usBg2Hofs (*(volatile unsigned short*) 0x300187E)
#define usBg2Vofs (*(volatile unsigned short*) 0x3001880)
#define usBg3Hofs (*(volatile unsigned short*) 0x3001882)
#define usBg3Vofs (*(volatile unsigned short*) 0x3001884)

#define Wario_ucDokan (*(volatile unsigned char*) 0x300189A)
#define Wario_usPosX (*(volatile short*) 0x30018AA) // rightwards positive
#define Wario_usPosY (*(volatile short*) 0x30018AC) // downwards positive

#define Bg0As_ScrollLayer0ControlFlag (*(volatile unsigned char**) 0x3003218)

// functions
#define Sub_806EBA8_Debug_LBUTTON_ScrSet ((void (*)(int*)) 0x806EBA9)
#define Sub_806E3BC_BlockScrSet ((void (*)(int*)) 0x806E3BD)
#define Sub_806E72C_GroundScrSet ((void (*)(int*)) 0x806E72D)
#define Sub_806E904_DirectScrSet ((void (*)(int*)) 0x806E905)
#define Sub_806EACC_Bg0_SP_ScrSet ((int (*)()) 0x806EACD)
#define Sub_806EB78_GmScr_Bg0_AutoScroll ((int (*)()) 0x806EB79)

// extra functions
#define Sub_806BB4C_GmapBgVramInitSet ((void (*)(unsigned char bgnum)) 0x806BB4D)

// 5 map switches in total
#define MapSw ((volatile unsigned char*) 0x300002E)

// debug rams
#define unk_3000039 (*(volatile unsigned char*) 0x3000039)

#define cGmStartFlg (*(volatile unsigned char*) 0x3000C3F)
#define cPauseFlag (*(volatile unsigned char*) 0x3000C35)
#define ucMainTimer (*(volatile unsigned char*) 0x3000C41)
#define soft_reset (*(volatile unsigned char*) 0x300001E)
#define ADDR_KEY_4 (*(volatile unsigned short*) 0x3001848)
#define usWarStopFlg (*(volatile unsigned short*) 0x30019F6)

// 00(Entry) 01(Emerald) 02(Ruby) 03(Topaz) 04(Sapphire) 05(Golden) 06(Sound Room)
#define CurrentPassage (*(volatile unsigned char*) 0x3000002)
// 00(first lvl) 01(second lvl) 02(third lvl) 03(fourth lvl) 04(Boss) 05(Mini-Game Shop)
#define CurrentLevel (*(volatile unsigned char*) 0x3000003)
#define CurrentRoom (*(volatile unsigned char*) 0x03000024)

#define Sub_8094E38__divsi3 ((int (*)(int,int)) 0x8094E39)
#define Sub_8094ED0__modsi3 ((int (*)(int,int)) 0x8094ED1)

// move layer 2 logic
void Level0Room_0_11_1_3_5_Bg2MoveLogic()
{
    if (CurrentPassage == 0 && CurrentLevel == 0 && (CurrentRoom == 0 || CurrentRoom == 11 || CurrentRoom == 1 || CurrentRoom == 3 || CurrentRoom == 5))
    {
        if (!unk_3000039)
        {
            usBg2Vofs = usBg1Vofs_CameraYPos;
        }
        else
        {
            usBg2Vofs = usBg1Vofs_CameraYPos + 64 * 10;
        }
        Sub_806BB4C_GmapBgVramInitSet(2);
    }
}

void Level0Room_4_Bg2MoveLogic()
{
    if (CurrentPassage == 0 && CurrentLevel == 0 && CurrentRoom == 4)
    {
        if (!unk_3000039)
        {
            usBg2Hofs = usBg1Hofs_CameraXPos;
        }
        else
        {
            usBg2Hofs = usBg1Hofs_CameraXPos + 8 * 0x40;
        }
        Sub_806BB4C_GmapBgVramInitSet(2);
    }
}

// move layer 0 logic
const char offset[] = {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf,
                       0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
                       0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
                       0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
                       0x3f, 0x3e, 0x3d, 0x3c, 0x3b, 0x3a, 0x39, 0x38, 0x37, 0x36, 0x35, 0x34, 0x33, 0x32, 0x31, 0x30,
                       0x2f, 0x2e, 0x2d, 0x2c, 0x2b, 0x2a, 0x29, 0x28, 0x27, 0x26, 0x25, 0x24, 0x23, 0x22, 0x21, 0x20,
                       0x1f, 0x1e, 0x1d, 0x1c, 0x1b, 0x1a, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10,
                       0xf, 0xe, 0xd, 0xc, 0xb, 0xa, 0x9, 0x8, 0x7, 0x6, 0x5, 0x4, 0x3, 0x2, 0x1, 0x0};
void Level0Room_2_4_Bg0MoveLogic()
{
    if (CurrentPassage == 0 && CurrentLevel == 0)
    {
        if (CurrentRoom == 2 || CurrentRoom == 4)
        {
            usBg0Hofs = usBg1Hofs_CameraXPos + 8 * offset[Sub_8094ED0__modsi3(ucMainTimer, 128)];
            Sub_806BB4C_GmapBgVramInitSet(0);
        }
    }
}

void Level0Room_3_Bg0MoveLogic()
{
    if (CurrentPassage == 0 && CurrentLevel == 0 && CurrentRoom == 3)
    {
        int value = Sub_8094ED0__modsi3(ucMainTimer, 128);
        if (value >= 0 && value < 63)
        {
            usBg0Vofs = usBg1Vofs_CameraYPos + 64 * 10;
            Sub_806BB4C_GmapBgVramInitSet(0);
                
        }
        else if (value >= 64 && value < 127)
        {
            usBg0Vofs = usBg1Vofs_CameraYPos;
            Sub_806BB4C_GmapBgVramInitSet(0);
        }
    }
}

void Level0Room_5_Bg0MoveLogic()
{
    if (CurrentPassage == 0 && CurrentLevel == 0 && CurrentRoom == 5)
    {
        int delta_y = 0x2BF - Wario_usPosY;
        if (delta_y >= 0)
        {
            usBg0Hofs = usBg1Hofs_CameraXPos + delta_y;
            Sub_806BB4C_GmapBgVramInitSet(0);
        }
        else
        {
            usBg0Hofs = usBg1Hofs_CameraXPos;
        }
    }
}

void Level0Room_7_Bg0MoveLogic()
{
    if (CurrentPassage == 0 && CurrentLevel == 0 && CurrentRoom == 7)
    {
        if (!unk_3000039)
        {
            usBg0Vofs = usBg1Vofs_CameraYPos;
        }
        else
        {
            usBg0Vofs = usBg1Vofs_CameraYPos + 64 * 10;
        }
        Sub_806BB4C_GmapBgVramInitSet(0);
    }
}

int Sub_806E7F8_GmScrSet()
{
    int v1[3]; // [sp+0h] [bp-Ch] BYREF

    if ( (!Wario_ucDokan || !sGameSeq) && sGameSeq != 3 )
    {
        v1[0] = Wario_usPosX | (Wario_usPosY << 16);// wario x and y position
        if ( (v1[0] & 0x80000000) != 0 )
        {
            v1[0] = Wario_usPosX;
        }
        if ( unk_300004C && sGameSeq == 8 )
        {
            Sub_806EBA8_Debug_LBUTTON_ScrSet(v1);
        }
        else if ( CurrentRoomHeader_CameraControlTypeFlag == 3 )
        {
            Sub_806E3BC_BlockScrSet(v1);
        }
        else if ( CurrentRoomHeader_CameraControlTypeFlag == 4 )// type 4
        {
            Sub_806E72C_GroundScrSet(v1);
        }
        else                                        // case: == 1 or == 2
        {
            Sub_806E904_DirectScrSet(v1);
        }

        if ( (CurrentRoomHeader_Layer0MappingType & 0xF) != 0 )
        {
            Sub_806EACC_Bg0_SP_ScrSet();
        }
        else
        {
            usBg0Hofs = usBg1Hofs_CameraXPos;
            usBg0Vofs = usBg1Vofs_CameraYPos;

            // custom layer 0 offset change control logic put here:
            if (MapSw[4] != 1)
            {
                Level0Room_2_4_Bg0MoveLogic();
                Level0Room_3_Bg0MoveLogic();
                Level0Room_5_Bg0MoveLogic();
                Level0Room_7_Bg0MoveLogic();
            }
        }
        if ( Bg0As_ScrollLayer0ControlFlag[0] )
        {
            Sub_806EB78_GmScr_Bg0_AutoScroll();
        }

        usBg2Hofs = usBg1Hofs_CameraXPos;
        usBg2Vofs = usBg1Vofs_CameraYPos;
        
        // custom layer 2 offset change control logic put here:
        if (MapSw[4] != 1)
        {
            Level0Room_0_11_1_3_5_Bg2MoveLogic();
            Level0Room_4_Bg2MoveLogic();
        }


        // Press L to Debug asyn layers
        if(cGmStartFlg == 1 && cPauseFlag == 0 && soft_reset == 0)
        {
            if((ADDR_KEY_4 & 0x200) && !usWarStopFlg) // press L, and another condition
            {
                if (!unk_3000039)
                {
                    unk_3000039 = 1;
                }
                else
                {
                    unk_3000039 = 0;
                }
            }
        }
        if ( (CurrentRoomHeader_Layer2MappingType & 0xF) != 0 )
        {
            usBg2Hofs = usBg1Hofs_CameraXPos - 32;
        }
    }
    return v1[2];
}
