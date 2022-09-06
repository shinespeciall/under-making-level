// @Description rewrite Sub_806D5C0_MapFieldAtari_Enemy
// @HookAddress 0x6D5CA
// from 0x6D5CA to 0x6D71C, 2 passed-in params for the vanilla function
// @HookString 024a 9646024a 10470000 1dd70608 P
// @EntryFunctionSymbol Sub_806D5C0_MapFieldAttact_Enemy

/* Patch & Hook details
 
 .thumb
    .dcb 1
    ldr r2, .DATA
    mov lr, r2
    ldr r2, .DATA + 4
    bx r2
    .dcb 1
  .DATA:
    .word 0x0806D71D
    .word 0xAAAAAAAA
 */

/**
 * changelog: 
 * directly modified from the IDA pro's generated C code.
 *            ---- by ssp (shinespeciall), 2022/03/01
 * fix a wrong param type in the declaration for function Sub_806F524_EnemyPanel_Attack(...).
 *            ---- by beco (becored), 2022/08/28
 * a little bit logic tweak to make block breaking logic looks better.
 *            ---- by ssp (shinespeciall), 2022/08/28
 * add logic to asynchronize Layer 0 and Layer 3.
 *            ---- by ssp (shinespeciall), 2022/09/01
 */

#define ucEnemyBrokenFlag (*(volatile unsigned char*) 0x3000028)
#define Layer0_DecompressedDataPointer (*(volatile unsigned short**) 0x3000054)
#define Layer0_Width (*(volatile unsigned short*) 0x3000058)
#define Layer0_Height (*(volatile unsigned short*) 0x300005a)
#define Layer1_DecompressedDataPointer (*(volatile unsigned short**) 0x300005c)
#define Layer1_Width (*(volatile unsigned short*) 0x3000060)
#define Layer1_Height (*(volatile unsigned short*) 0x3000062)
#define Layer2_DecompressedDataPointer (*(volatile unsigned short**) 0x3000064)
#define Layer2_Width (*(volatile unsigned short*) 0x3000068)
#define Layer2_Height (*(volatile unsigned short*) 0x300006a)

#define CurrentRoomHeader_Layer2MappingType (*(volatile unsigned char*) 0x3000077)

#define CurrentTileset_TerrainTypeTablePointer (*(volatile unsigned char**) 0x30031F8)
// #define CurrentTileset_EventIdTablePointer (*(volatile unsigned short**) 0x30031FC)

#define Tile_collision_fucntionTable ((volatile unsigned int*) 0x878F2E4)
/** pPanel_Atari_Main_tbl[13] =  // found in /src/gmap/atari.o
   Atari_NASHI, Atari_ALL, Atari_45LU, Atari_45RU, Atari_30LU2
   Atari_30LU1, Atari_30RU1, Atari_30RU2, Atari_WaDamege_ALL
   Atari_TekiOnly_ALL, Atari_WaDTe_ALL, Atari_DUMMY, Atari_NASHI
 */

#define Sub_806D89C_Panel_Atari_SW_tbl ((int (*)(int*)) 0x806D89D) // can be found in /src/gmap/atari.o, if you want to change the switches mechanism
#define Sub_806DAC0_PanelYakuAllNum_TileEventId ((int (*)(unsigned short, unsigned short)) 0x806DAC1)
#define Sub_806F524_EnemyPanel_Attack ((int (*)(unsigned short, unsigned short, unsigned short)) 0x806F525)

#define Sub_8094E00_call_via_r1 ((int (*)(int*, int)) 0x8094E01)

struct Mhitdef // found in /src/gmap/atari.o
{
    int anum;
    unsigned int x_0x3F;
    unsigned int y_0x3F;
    int swnum;
    int swtype;
    int who; // Wario: 0, Enemy: 1
};

#define Terrain_usField (*(volatile unsigned short*) 0x30000a0)
enum usField_enum{
    YF_Nothing,   //00:nothing in layer 1 and 2
    YF_Door,  //01:door
    YF_Ladder_M, //02:ladder
    YF_Ladder_U, //03:top of ladder
    YF_climbable_net, //04:climbable net
    YF_BELT_L,  //05:belt to left, only works on layer 1
    YF_BELT_R,  //06:belt to right
    YF_TUBE_UL,  //07:left part of go-up pipe
    YF_TUBE_UR,  //08:right part of go-up pipe
    YF_TUBE_DL,  //09:left part of go-down pipe
    YF_TUBE_DR,  //0A:right part of go-down pipe
    YF_SLIP,  //0B:slippery platforms
    YF_Water_SR,  //0C:slow current rightwards
    YF_Water_SL,  //0D:slow current leftwards
    YF_Water_SU,  //0E:slow current upwards
    YF_Water_SD,  //0F:slow current downwards
    YF_Water_FR,  //00:fact current rightwards
    YF_Water_FL,  //11:fast current leftwards
    YF_Water_FU,  //12:fast current upwards
    YF_Water_FD,  //13:fast current downwards
};
// 030000a2 : u16 Pyaku[1] - usKoka - 01(in water) 00(else) (from WL4 RAM record)
#define Terrain_usKoka_SolidOrWater (*(volatile unsigned short*) 0x30000a2)
enum uskoka_enum
{
    YK_Nothing,
    YK_Water,
};

#define usBg0Hofs (*(volatile unsigned short*) 0x3001876)
#define usBg0Vofs (*(volatile unsigned short*) 0x3001878)
#define usBg1Hofs_CameraXPos (*(volatile unsigned short*) 0x300187A)
#define usBg1Vofs_CameraYPos (*(volatile unsigned short*) 0x300187C)
#define usBg2Hofs (*(volatile unsigned short*) 0x300187E)
#define usBg2Vofs (*(volatile unsigned short*) 0x3001880)
#define usBg3Hofs (*(volatile unsigned short*) 0x3001882)
#define usBg3Vofs (*(volatile unsigned short*) 0x3001884)

int Sub_806D5C0_MapFieldAttact_Enemy(unsigned short Enemy_y, unsigned short Enemy_x)
{
    unsigned int x_grid_pos;
    unsigned int y_grid_pos;
    int tile_offset;
    int result;
    int tmp_result;
    unsigned char L1_tile_terrain_type;
    unsigned char L2_tile_terrain_type;
    unsigned short TileId_to_reset_TerrainType;
    int EnemyPanelAttack_result = 0;
    struct Mhitdef l_Mhit;

    if ( Enemy_x >= (Layer1_Width << 6) || Enemy_y >= (Layer1_Height << 6) )
    {
        result = 0;
        Terrain_usField = 0;
        Terrain_usKoka_SolidOrWater = 0;
        return result;
    }
    Sub_806DAC0_PanelYakuAllNum_TileEventId(Enemy_y, Enemy_x);
    y_grid_pos = (Enemy_y << 16) >> 22;
    x_grid_pos = (Enemy_x << 16) >> 22;
    tile_offset = y_grid_pos * Layer1_Width + x_grid_pos;
    TileId_to_reset_TerrainType = Layer1_DecompressedDataPointer[tile_offset];
    if (ucEnemyBrokenFlag)
    {
        EnemyPanelAttack_result = Sub_806F524_EnemyPanel_Attack(y_grid_pos, x_grid_pos, TileId_to_reset_TerrainType);
        if (EnemyPanelAttack_result)
        {
            TileId_to_reset_TerrainType = (ucEnemyBrokenFlag == 3) ? 1 : 0;
        }
        ucEnemyBrokenFlag = 0;
    }
    L1_tile_terrain_type = CurrentTileset_TerrainTypeTablePointer[TileId_to_reset_TerrainType];
    int delta_L1_to_L2_X = (int)usBg2Hofs - (int)usBg1Hofs_CameraXPos;
    int delta_L1_to_L2_Y = (int)usBg2Vofs - (int)usBg1Vofs_CameraYPos;
    int x_grid_pos_L2 = ((Enemy_x + delta_L1_to_L2_X) << 16) >> 22;
    int y_grid_pos_L2 = ((Enemy_y + delta_L1_to_L2_Y) << 16) >> 22;
    tile_offset = y_grid_pos_L2 * Layer2_Width + x_grid_pos_L2;
    L2_tile_terrain_type = CurrentTileset_TerrainTypeTablePointer[Layer2_DecompressedDataPointer[tile_offset]];
    l_Mhit.anum = L1_tile_terrain_type;
    l_Mhit.x_0x3F = Enemy_x & 0x3F;
    l_Mhit.y_0x3F = Enemy_y & 0x3F;
    l_Mhit.swnum = 0;
    l_Mhit.swtype = 0;
    l_Mhit.who = 1;
    if ( L1_tile_terrain_type > 12 )
    {
        if ( (L1_tile_terrain_type - 0x14) > 0x2B )
        {
            l_Mhit.anum = 0;
        }
        else
        {
            result = /* (Mhitdef *) */Sub_806D89C_Panel_Atari_SW_tbl(&(l_Mhit.anum));
        }
    }
    else
    {
        // L1_tile_terrain_type <= 12
        result = /* (Mhitdef *) */Sub_8094E00_call_via_r1(&(l_Mhit.anum), Tile_collision_fucntionTable[L1_tile_terrain_type]);
    }
    if ( !l_Mhit.anum ) // if nothing in Layer 1
    {
        l_Mhit.anum = L2_tile_terrain_type;
        if ( L2_tile_terrain_type == 12 && CurrentRoomHeader_Layer2MappingType == 16 )
        {
            tmp_result = Sub_8094E00_call_via_r1(&(l_Mhit.anum), 0x806D731 /*Tile_collision_fucntionTable[12]*/);
        }
        else
        {
            if ( (l_Mhit.anum - 38) > 7 || CurrentRoomHeader_Layer2MappingType != 16 )
            {
                return result;
            }
            tmp_result = Sub_806D89C_Panel_Atari_SW_tbl(&(l_Mhit.anum));
        }
        result = tmp_result;
    }
    return result;
}
