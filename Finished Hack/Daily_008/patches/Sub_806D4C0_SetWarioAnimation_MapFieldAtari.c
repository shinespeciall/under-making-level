// @Description modify Sub_806D4C0_SetWarioAnimation_MapFieldAtari
// @HookAddress 0x6D4C2
// from 0x6D4C2 to 0x6D5B4, 2 passed-in params for the vanilla function
// @HookString 024a 9646024a 10470000 b5d50608 P

/* Patch & Hook details
 
 .thumb
    .dcb 1
    ldr r2, .DATA
    mov lr, r2
    ldr r2, .DATA + 4
    bx r2
    .dcb 1
  .DATA:
    .word 0x0806D5B5
    .word 0xAAAAAAAA
 */

/**
 * changelog: 
 * directly modified from the IDA pro's generated C code.
 *            ---- by ssp (shinespeciall), 2021/12/12
 * add more infos of strust and functions ref from the leaks.
 *            ---- by ssp (shinespeciall), 2022/01/24
 * bugfix in the macro.
 *            ---- by ssp (shinespeciall), 2022/01/27
 */

#define Layer0_DecompressedDataPointer (*(volatile unsigned short**) 0x3000054)
#define Layer0_Width (*(volatile unsigned short*) 0x3000058)
#define Layer0_Height (*(volatile unsigned short*) 0x300005a)
#define Layer1_DecompressedDataPointer (*(volatile unsigned short**) 0x300005c)
#define Layer1_Width (*(volatile unsigned short*) 0x3000060)
#define Layer1_Height (*(volatile unsigned short*) 0x3000062)
#define Layer2_DecompressedDataPointer (*(volatile unsigned short**) 0x3000064)

#define CurrentRoomHeader_Layer2MappingType (*(volatile unsigned char*) 0x3000077)

#define WarioState (*(volatile char*) 0x3001898)
#define Wario_speed_X (*(volatile short*) 0x30018AE)

#define CurrentTileset_TerrainTypeTablePointer (*(volatile unsigned char**) 0x30031F8)
#define CurrentTileset_EventIdTablePointer (*(volatile unsigned short**) 0x30031FC)

#define Tile_collision_fucntionTable ((volatile unsigned int*) 0x878F2E4)
/** pPanel_Atari_Main_tbl[13] =  // found in /src/gmap/atari.o
   Atari_NASHI, Atari_ALL, Atari_45LU, Atari_45RU, Atari_30LU2
   Atari_30LU1, Atari_30RU1, Atari_30RU2, Atari_WaDamege_ALL
   Atari_TekiOnly_ALL, Atari_WaDTe_ALL, Atari_DUMMY, Atari_NASHI
 */

#define Sub_806D89C_Panel_Atari_SW_tbl ((int (*)(int*)) 0x806D89D) // can be found in /src/gmap/atari.o, if you want to change the switches mechanism
#define Sub_8094E00_call_via_r1 ((int (*)(int*, int)) 0x8094E01)

struct Mhitdef // found in /src/gmap/atari.o
{
    int anum;
    unsigned int x_0x3F;
    unsigned int y_0x3F;
    int swnum;
    int swtype;
    int who;
};

int Sub_806D4C0_SetWarioAnimation_MapFieldAtari(unsigned short Wario_y, unsigned short Wario_x)
{
    unsigned int x_grid_pos;
    unsigned int y_grid_pos;
    int tile_id;
    int result = 0;
    int tmp_result = 0;
    unsigned char L1_tile_terrain_type;
    unsigned char L2_tile_terrain_type;
    unsigned short L0_tile_event_id;
    struct Mhitdef v11;

    if ( Wario_x >= (Layer1_Width << 6) )
        return /* (Mhitdef *) */0x1000001;
    if ( Wario_y >= (Layer1_Height << 6) )
        return 0;
    y_grid_pos = ((unsigned int)Wario_y << 16) >> 22;
    x_grid_pos = ((unsigned int)Wario_x << 16) >> 22;
    tile_id = y_grid_pos * Layer1_Width + x_grid_pos;
    L1_tile_terrain_type = CurrentTileset_TerrainTypeTablePointer[Layer1_DecompressedDataPointer[tile_id]];
    L2_tile_terrain_type = CurrentTileset_TerrainTypeTablePointer[Layer2_DecompressedDataPointer[tile_id]];
    v11.anum = L1_tile_terrain_type;
    v11.x_0x3F = Wario_x & 0x3F;
    v11.y_0x3F = Wario_y & 0x3F;
    v11.swnum = 0;
    v11.swtype = 0;
    v11.who = 0;
    if ( (int)L1_tile_terrain_type > 12 )
    {
        if ( ((int)L1_tile_terrain_type - 0x14) > 0x2B )
        {
            v11.anum = 0;
        }
        else
        {
            result = Sub_806D89C_Panel_Atari_SW_tbl(&v11);
        }
    }
    else
    {
        // L1_tile_terrain_type <= 12
        result = Sub_8094E00_call_via_r1(&v11, Tile_collision_fucntionTable[L1_tile_terrain_type]);
    }
    if ( !v11.anum ) // if nothing in Layer 1
    {
        // ------------------custom code----------------------------
        tile_id = y_grid_pos * Layer0_Width + x_grid_pos;
        L0_tile_event_id = CurrentTileset_EventIdTablePointer[Layer0_DecompressedDataPointer[tile_id]];
        if (L0_tile_event_id == 0x50) // water
        {
            if ((Wario_speed_X >= 96 || Wario_speed_X <= -96) && WarioState == 0)
            {
                v11.anum = 12; // platform
                result = Sub_8094E00_call_via_r1(&v11, Tile_collision_fucntionTable[12]);
                return result;
            }
        }
        // ----------------custom code end--------------------------

        v11.anum = L2_tile_terrain_type;
        if ( L2_tile_terrain_type == 12 && CurrentRoomHeader_Layer2MappingType == 16 )
        {
            tmp_result = Sub_8094E00_call_via_r1(&v11, 0x806D731 /*Tile_collision_fucntionTable[12]*/);
        }
        else
        {
            if ( (v11.anum - 38) > 7 || CurrentRoomHeader_Layer2MappingType != 16 )
            {
                return result;
            }
            tmp_result = Sub_806D89C_Panel_Atari_SW_tbl(&v11);
        }
        result = tmp_result;
    }
    return result;
}
