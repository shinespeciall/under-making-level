// @Description Sub_806EC50_WarSidePanel_Attack
// @HookAddress 0x6EC54
// @HookString  024a 9646024a 10470000 0000 6bed0608 P
// @EntryFunctionSymbol Sub_806EC50_WarSidePanel_Attack

/**
 * changelog: 
 * Patch of this function created by Blanchon,
 * enum and other stuff from beco's code,
 * format the code and replace the custom part by any shape breakable block logic by shinespeciall
 *            ---- by ssp (shinespeciall), 2022/10/18
 * put all the shared functions into C_dependency type patch file,
 * put all the declarations into ASBB.h
 *            ---- by ssp (shinespeciall), 2023/4/22
 */

#include "ASBB.h"

extern void BreakAnyShapeBlock(unsigned char start_y_pos, unsigned char start_x_pos);

int Sub_806EC50_WarSidePanel_Attack(unsigned short Ypos,unsigned short Xpos)
{
    char v4;
    unsigned int v5;
    signed int v6;
    struct BgBDdef pDestroy;

    pDestroy.xp = (Xpos << 16) >> 22;
    pDestroy.yp = (Ypos << 16) >> 22;
    pDestroy.part = CurrentTileset_EventIdTablePointer[Layer1_DecompressedDataPointer[pDestroy.yp * Layer1_Width + pDestroy.xp]];
    pDestroy.coin = 0;
    pDestroy.obop = 0;
    pDestroy.SE = 0;
    pDestroy.hit = WHit.ucSPow;
    pDestroy.dir = 1;
    v4 = 0;
    if (!Wario_ucReact)
    {
        if (Wario_usPosX > pDestroy.xp)
        {
            pDestroy.dir = 2;
        }

        switch (Wario_ucStat)
        {
            case 0xE:
            case 0xF:
                goto LABEL_12;
            case 0x16:
            case 0x18:
            {
                pDestroy.dir ^= 3u;
                v4 = 1;
                goto LABEL_11;
            }
            case 0x17:
            case 0x19:
            {
                pDestroy.dir += 4;
                goto LABEL_12;
            }
            default:
            {
LABEL_11:
                if ( !v4 )
                {
                    return v4;
                }
LABEL_12:
                // -------------- Custom code ------------------
                if (pDestroy.part > (event_id_TopLeft - 1) && pDestroy.part < (event_id_one_col_bottom_end + 1))
                {
                    BreakAnyShapeBlock(pDestroy.yp, pDestroy.xp);
                    return 1;
                }
                // -------------- Custom code end---------------

                v6 = PanelPartWork_Broken_Main(&pDestroy);
                v4 = v6;
                if ( v6 == 1 )
                {
                    return v4;
                }
                if ( v6 == 2 )
                {
                    return 0;
                }
                v5 = PanelPartWork_Switch_Main(&pDestroy, 0);
                break;
            }
        }
        goto LABEL_16;
    }
    if ( Wario_ucReact == 6 )
    {
        pDestroy.dir = 5;
        if ( Wario_usPosX > pDestroy.xp )
        pDestroy.dir = 6;
        v5 = PanelPartWork_Broken_Snow(&pDestroy);
LABEL_16:
        v4 = v5;
    }
    return v4;
}
