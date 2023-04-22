// @Description Sub_806F524_EnemyPanel_Attack
// @HookAddress 0x6F526
// @HookString  024d ae46024d 28470000 49f60608 P
// @EntryFunctionSymbol Sub_806F524_EnemyPanel_Attack

/**
 * changelog: 
 * Patch of this function created by beco.
 * replace the custom part by any shape breakable block logic by shinespeciall
 * put all the shared functions into C_dependency type patch file,
 * put all the declarations into ASBB.h
 *            ---- by ssp (shinespeciall), 2023/4/22
 */

#include "ASBB.h"

extern void BreakAnyShapeBlock(unsigned char start_y_pos, unsigned char start_x_pos);

#define MEMORY_2039F00 (*(volatile unsigned short*) 0x2039F00)

int Sub_806F524_EnemyPanel_Attack(unsigned short y_grid_pos, unsigned short x_grid_pos, unsigned char L1_tile_ID)
{
    signed int v3;
    signed int v6 = 0;
    signed int v7;
    int v8;
    int v9;
    int v10;
    int v11;
    int v12;
    int v13;
    struct BgBDdef pDestroy;

    unsigned short Xpos = (x_grid_pos << 22) >> 16;
    unsigned short Ypos = (y_grid_pos << 22) >> 16;

    pDestroy.xp = x_grid_pos;
    pDestroy.yp = y_grid_pos;
    pDestroy.part = *(unsigned short*)((2 * L1_tile_ID & 0x1FFFF) + CurrentTileset_EventIdTablePointer);
    pDestroy.dir = 4;
    pDestroy.coin = 0;
    pDestroy.obop = 0;
    pDestroy.hit = 1;
    v3 = 0;
    if ( ucEnemyBrokenFlag == 2 )
    {
        v8 = 0x2039F00;
        v9 = 0;
        if ( MEMORY_2039F00 == ((x_grid_pos << 8) | y_grid_pos) )
        {
            MEMORY_2039F00 = 0;
        }
        else
        {
            while ( 1 )
            {
                ++v8;
                if ( ++v9 > 63 )
                    break;
                if ( *(int*)v8 == ((x_grid_pos << 8) | y_grid_pos) )
                {
                    *(int*)v8 = 0;
                    v6 = 1;
                    break;
                }
            }
            if ( !v6 )
            return 1;
        }
        Sub_8070098_Panel_PutBG_Only(0, pDestroy.yp, pDestroy.xp);
        return 1;
    }
    if ( ucEnemyBrokenFlag <= 2 )
    {
        if ( ucEnemyBrokenFlag == 1 )
        {
            // Custom Code
            // -------------- Custom code ------------------
            if (pDestroy.part > (event_id_TopLeft - 1) && pDestroy.part < (event_id_one_col_bottom_end + 1))
            {
                BreakAnyShapeBlock(pDestroy.yp, pDestroy.xp);
                return 1;
            }
            // -------------- Custom code end---------------

            v7 = Sub_806EE98_PanelPartWork_Broken_Main(&pDestroy);
            v6 = v7;
            if ( v7 != 1 )
            {
                if ( v7 == 2 )
                    v6 = 0;
                else
                    Sub_806F424_PanelPartWork_Switch_Main(&pDestroy, 0);
            }
        }
        return v6;
    }
    if ( ucEnemyBrokenFlag != 3 )
    {
        if ( ucEnemyBrokenFlag == 4 )
            Sub_806F4BC_PanelPartWork_YokiDiva_Main(&pDestroy);
        return v6;
    }
    v10 = 0x2039F00;
    v11 = 0;
    v12 = x_grid_pos << 8;
    if ( MEMORY_2039F00 == (v12 | y_grid_pos) )
        return 1;
    while ( 1 )
    {
        v10 += 2;
        if ( ++v11 > 63 )
            break;
        if ( *(unsigned short*)v10 == (v12 | y_grid_pos) )
        {
            v6 = 1;
            break;
        }
    }
    if ( !v6 )
    {
        v13 = 0x2039F00;
        for ( int i = 0; i <= 63; ++i )
        {
            if ( !*(int*)v13 )
            {
                *(unsigned short*)v13 = v12 | y_grid_pos;
                Sub_8070098_Panel_PutBG_Only(1, pDestroy.yp, pDestroy.xp);
                return 1;
            }
            v13 += 2;
        }
    }
    return v6;
}
