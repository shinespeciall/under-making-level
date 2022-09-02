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
 * add the example logic to update vram for moved layer.
 *            ---- by ssp (shinespeciall), 2022/09/02
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

// debug rams
#define unk_3000039 (*(volatile unsigned char*) 0x3000039)

#define cGmStartFlg (*(volatile unsigned char*) 0x3000C3F)
#define cPauseFlag (*(volatile unsigned char*) 0x3000C35)
#define soft_reset (*(volatile unsigned char*) 0x300001E)
#define ADDR_KEY_4 (*(volatile unsigned short*) 0x3001848)
#define usWarStopFlg (*(volatile unsigned short*) 0x30019F6)

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
        }
        if ( Bg0As_ScrollLayer0ControlFlag[0] )
        {
            Sub_806EB78_GmScr_Bg0_AutoScroll();
        }
        usBg2Hofs = usBg1Hofs_CameraXPos;
        if (!unk_3000039)
        {
            usBg2Vofs = usBg1Vofs_CameraYPos;
        }
        else
        {
            usBg2Vofs = usBg1Vofs_CameraYPos + 0x40;
        }
        Sub_806BB4C_GmapBgVramInitSet(2); // call this function to update the layer 2 VRAM

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
