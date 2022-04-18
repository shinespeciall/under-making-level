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
 * add custom code to let wario run on water surface.
 *            ---- by ssp (shinespeciall), 2022/01/27
 * add custom code for layer 2 one-way tiles, since the game has
 * already supported upwards one-way tiles, i only added the logic for the other 3.
 * they are still buggy on some edge cases but can work most of the time.
 *            ---- by ssp (shinespeciall), 2022/03/08
 */

#define Layer0_DecompressedDataPointer (*(volatile unsigned short**) 0x3000054)
#define Layer0_Width (*(volatile unsigned short*) 0x3000058)
#define Layer0_Height (*(volatile unsigned short*) 0x300005a)
#define Layer1_DecompressedDataPointer (*(volatile unsigned short**) 0x300005c)
#define Layer1_Width (*(volatile unsigned short*) 0x3000060)
#define Layer1_Height (*(volatile unsigned short*) 0x3000062)
#define Layer2_DecompressedDataPointer (*(volatile unsigned short**) 0x3000064)

#define CurrentRoomHeader_Layer2MappingType (*(volatile unsigned char*) 0x3000077)

#define Wario_ucReact (*(volatile char*) 0x3001898)
#define Wario_ucStat (*(volatile char*) 0x3001899)

#define Wario_usMukiX  (*(volatile short*) 0x30018A6) // face right: 0x10, face left: 0x20
#define Wario_usPosX  (*(volatile short*) 0x30018AA) // rightwards positive
#define Wario_usPosY  (*(volatile short*) 0x30018AC) // downwards positive
#define Wario_speed_X (*(volatile short*) 0x30018AE)
#define Wario_speed_Y (*(volatile short*) 0x30018B0)
#define Wario_sHitDX1 (*(volatile short*) 0x30018CA) // seems always negative
#define Wario_sHitDY1 (*(volatile short*) 0x30018CC) // seems always negative
#define Wario_sHitDX2 (*(volatile short*) 0x30018CE)

#define CurrentTileset_TerrainTypeTablePointer (*(volatile unsigned char**) 0x30031F8)
#define CurrentTileset_EventIdTablePointer (*(volatile unsigned short**) 0x30031FC)

// #define Tile_collision_fucntionTable ((volatile unsigned int*) 0x878F2E4)
/** pPanel_Atari_Main_tbl[13] =  // found in /src/gmap/atari.o
   Atari_NASHI, Atari_ALL, Atari_45LU, Atari_45RU, Atari_30LU2
   Atari_30LU1, Atari_30RU1, Atari_30RU2, Atari_WaDamege_ALL
   Atari_TekiOnly_ALL, Atari_WaDTe_ALL, Atari_DUMMY, Atari_NASHI
 */
const unsigned int pPanel_Atari_Main_tbl[13] = {0x806D731, 0x806D735, 0x806D741, 0x806D75D, 0x806D77D,
                                                0x806D799, 0x806D7B9, 0x806D7D9, 0x806D7F9, 0x806D82D,
                                                0x806D855, 0x806D88D};

#define Sub_806D89C_Panel_Atari_SW_tbl ((int (*)(int*)) 0x806D89D) // can be found in /src/gmap/atari.o, if you want to change the switches mechanism
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

int Sub_806D4C0_SetWarioAnimation_MapFieldAtari(unsigned short Wario_y, unsigned short Wario_x)
{
    unsigned int x_grid_pos;
    unsigned int y_grid_pos;

    int tile_id;
    int result;
    unsigned char L1_tile_terrain_type;
    unsigned char L2_tile_terrain_type;
    unsigned short L0_tile_event_id;
    struct Mhitdef v11;

    if ( Wario_x >= (Layer1_Width << 6) )
        return /* (Mhitdef *) */0x1000001;
    if ( Wario_y >= (Layer1_Height << 6) )
        return 0;
    y_grid_pos = (Wario_y << 16) >> 22;
    x_grid_pos = (Wario_x << 16) >> 22;
    int y_grid_pos_wario = ((Wario_usPosY) << 16) >> 22;
    int y_grid_pos_wario_head = ((Wario_usPosY + Wario_sHitDY1) << 16) >> 22;
    int y_grid_pos_wario_head_squad = ((Wario_usPosY + Wario_sHitDY1 - 5) << 16) >> 22;
    int x_grid_pos_wario_rightside_hitbox = ((Wario_usPosX + Wario_sHitDX2) << 16) >> 22;
    int x_grid_pos_wario_leftside_hitbox = ((Wario_usPosX + Wario_sHitDX1) << 16) >> 22;
    tile_id = y_grid_pos * Layer1_Width + x_grid_pos;
    L1_tile_terrain_type = CurrentTileset_TerrainTypeTablePointer[Layer1_DecompressedDataPointer[tile_id]];
    L2_tile_terrain_type = CurrentTileset_TerrainTypeTablePointer[Layer2_DecompressedDataPointer[tile_id]];
    v11.anum = L1_tile_terrain_type;
    v11.x_0x3F = Wario_x & 0x3F;
    v11.y_0x3F = Wario_y & 0x3F;
    v11.swnum = 0;
    v11.swtype = 0;
    v11.who = 0;
    result = 0;
    if ( L1_tile_terrain_type > 12 )
    {
        if ( (L1_tile_terrain_type - 0x14) > 0x2B )
        {
            v11.anum = 0;
        }
        else
        {
            result = /* (Mhitdef *) */Sub_806D89C_Panel_Atari_SW_tbl(&(v11.anum));
        }
    }
    else
    {
        // L1_tile_terrain_type <= 12
        result = /* (Mhitdef *) */Sub_8094E00_call_via_r1(&(v11.anum), pPanel_Atari_Main_tbl[L1_tile_terrain_type]);
    }
    if ( !v11.anum ) // if nothing in Layer 1
    {
        // ------------------custom code----------------------------
        // let Wario be able to run on water surface
        // tile_id = y_grid_pos * Layer0_Width + x_grid_pos;
        // L0_tile_event_id = CurrentTileset_EventIdTablePointer[Layer0_DecompressedDataPointer[tile_id]];
        // if (L0_tile_event_id == 0x50) // water
        // {
        //     if ((Wario_speed_X >= 96 || Wario_speed_X <= -96) && Wario_ucReact == 0)
        //     {
        //         v11.anum = 12; // platform
        //         result = Sub_8094E00_call_via_r1(&v11, pPanel_Atari_Main_tbl[12]);
        //         return result;
        //     }
        // }
        // ----------------custom code end--------------------------

        v11.anum = L2_tile_terrain_type;
        if (CurrentRoomHeader_Layer2MappingType != 16)
        {
            if ((v11.anum - 38) > 7)
            {
                return result;
            }
        }
        else
        {
            if (L2_tile_terrain_type == 0x0B || L2_tile_terrain_type == 0x0F || L2_tile_terrain_type == 0x10)
            { // custom downwards one-way, 0x0B, 0x0F, 0x10
                // when wario goes up and his head is lower than the current input position
                if (Wario_speed_Y > 0 && (y_grid_pos_wario_head_squad >= y_grid_pos))
                {
                    return 0x1000001;
                }
                else
                {
                    if (Wario_ucStat < 10 && \
                        Wario_ucStat > 4 && \
                        y_grid_pos_wario_head_squad >= y_grid_pos)
                    {
                        return 0x1000001;
                    }
                    // return 0;
                }
            }
            if (L2_tile_terrain_type == 0x0D || L2_tile_terrain_type == 0x0F)
            { // custom leftwards one-way, 0x0D, 0x0F
                if (Wario_speed_X >= 0 && \
                    Wario_usMukiX == 0x10 && \
                    (x_grid_pos_wario_rightside_hitbox <= x_grid_pos) && \
                    (y_grid_pos_wario >= y_grid_pos))
                {
                    return 0x1000001;
                }
                // else
                // {
                //     return 0;
                // }
            }
            if (L2_tile_terrain_type == 14 || L2_tile_terrain_type == 0x10)
            { // custom rightwards one-way, 0x0E, 0x10
                if (Wario_speed_X <= 0 && \
                    Wario_usMukiX == 0x20 && \
                    (x_grid_pos_wario_leftside_hitbox >= x_grid_pos) && \
                    (y_grid_pos_wario >= y_grid_pos))
                {
                    return 0x1000001;
                }
                // else
                // {
                //     return 0;
                // }
            }
            if (L2_tile_terrain_type == 12) // vanilla upwards one-way
            {
                return 12;
            }
            else
            {
                return Sub_806D89C_Panel_Atari_SW_tbl(&(v11.anum));
            }
        }
    }
    return result;
}
