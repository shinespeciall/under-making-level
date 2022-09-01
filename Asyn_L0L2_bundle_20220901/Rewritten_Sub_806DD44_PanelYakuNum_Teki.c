// @Description Rewrite Sub_806DD44_PanelYakuNum_Teki
// @HookAddress 0x6dd46
// @HookString 024a 9646024a 10470000 dddd0608 P

/* Patch & Hook details
 
 .thumb
    .dcb 1
    ldr r2, .DATA
    mov lr, r2
    ldr r2, .DATA + 4
    bx r2
    .dcb 1
  .DATA:
    .word 0x0806DDDD
    .word 0xAAAAAAAA
 */

/**
 * changelog: 
 * directly modified from the IDA pro's generated C code
 * and made some adjustment to make the code executes faster.
 *            ---- by ssp (shinespeciall), 2021/11/19
 * add logic to asynchronize Layer 0 and Layer 3.
 *            ---- by ssp (shinespeciall), 2022/09/01
 */

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

#define Terrain_usEnemySpecified (*(volatile unsigned short*) 0x30000a4)
enum usEnemySpecified_enum
{
    YT_Nothing,
    YT_WASHIBA_RST,  //01:pulley, R stop
    YT_WASHIBA_LST,  //02:pulley, L stop
    YT_WASHIBA_RUP,  //03:pulley, L(horizontal) R(right up)
    YT_WASHIBA_RDW,  //04:pulley, L(horizontal) R(right down)
    YT_WASHIBA_LUP,  //05:pulley, L(left up) R(horizontal)
    YT_WASHIBA_LDW,  //06:pulley, L(left down) R(horizontal)
    YT_WASHIBA_RST2, //07:pulley, R stop (high)
    YT_WASHIBA_LST2, //08:pulley, L stop (high)
    YT_DOMINO_R4,  //09:Domino Right 4 panel(40F | 0x84:Domino Right 4 panel (new)
    YT_DOMINO_L4,  //0A:Domino Left 4 panel(40F    ｜ 0x85:Domino Left 4 panel
    YT_DOMINO_R5D1,  //0B:Domino Right 5, down 1(50F    ｜ 0x86:Domino Right 5, down 1
    YT_DOMINO_L5D1,  //0C:Domino Left 5, down 1(50F    ｜ 0x87:Domino Left 5, down 1
    YT_DOMINO_R5U1,  //0D:Domino Right 5, up 1(50F    ｜ 0x88:Domino Right 5, up 1
    YT_DOMINO_L5U1,  //0E:Domino Left 5, up 1(50F    ｜ 0x89:Domino Left 5, up 1
    YT_DOMINO_R3D3,  //0F:Domino Right 3, down 3(60F    ｜ 0x8A:Domino Left 1, down 3
    YT_DOMINO_L3D3,  //10:Domino Left 3, down 3(60F    ｜ 0x8B:Domino Right 1, down 3
    YT_DOMINO_R3U3,  //11:Domino Right 3, up 3(60F    ｜ 0x8C:Domino Left 1, up 3
    YT_DOMINO_L3U3,  //12:Domino Left 3, up 3(60F    ｜ 0x8D:Domino Right 1, up 3
    YT_DOMINO_STP,  //13:Domino stop       | 0x8E:Domino stop 
};

#define usBg0Hofs (*(volatile unsigned short*) 0x3001876)
#define usBg0Vofs (*(volatile unsigned short*) 0x3001878)
#define usBg1Hofs_CameraXPos (*(volatile unsigned short*) 0x300187A)
#define usBg1Vofs_CameraYPos (*(volatile unsigned short*) 0x300187C)
#define usBg2Hofs (*(volatile unsigned short*) 0x300187E)
#define usBg2Vofs (*(volatile unsigned short*) 0x3001880)
#define usBg3Hofs (*(volatile unsigned short*) 0x3001882)
#define usBg3Vofs (*(volatile unsigned short*) 0x3001884)

/**
 * the vanilla function of Sub_806DD44_PanelYakuNum_Teki works like Sub_806DAC0_PanelYakuAllNum
 * so, better patch (or let) the caller to do the work to modify Wario, enemies, map stuff.
 */
int Rewrite_Sub_806DD44_PanelYakuNum_Teki(unsigned short Y_value, unsigned short X_value)
{
    int result_Terrain_usEnemySpecified/* = 0 */;
    int Layer2CurrentEventId;
    int eventid_tmp;

    Terrain_usEnemySpecified = 0;
    if ( Y_value >= Layer1_Height || X_value >= Layer1_Width )
        return 0;

    int delta_L1_to_L2_X = (int)usBg2Hofs - (int)usBg1Hofs_CameraXPos;
    int delta_L1_to_L2_Y = (int)usBg2Vofs - (int)usBg1Vofs_CameraYPos;
    int X_value_R6_L2 = ((X_value + delta_L1_to_L2_X) << 16) >> 22;
    int Y_value_R6_L2 = ((Y_value + delta_L1_to_L2_Y) << 16) >> 22;

    Layer2CurrentEventId = CurrentTileset_EventIdTablePointer[ \
                                Layer2_DecompressedDataPointer[Y_value_R6_L2 * Layer2_Width + X_value_R6_L2]];
    eventid_tmp = Layer2CurrentEventId - 0x60;
    if ( eventid_tmp > 7 || eventid_tmp < 0)
    {
        // Domino things
        eventid_tmp = Layer2CurrentEventId - 0x84;
        result_Terrain_usEnemySpecified = 0;
        if ( eventid_tmp <= 0xA && eventid_tmp >= 0)
            result_Terrain_usEnemySpecified = eventid_tmp + 9;
    }
    else // 0 <= (Layer2CurrentEventId - 0x60) <= 7
    {
        // pulley things
        result_Terrain_usEnemySpecified = Layer2CurrentEventId - 0x60 + 1;
    }
    Terrain_usEnemySpecified = result_Terrain_usEnemySpecified;
    return result_Terrain_usEnemySpecified;
}
