// @Description Sub_806EDFC_WarUpPanel_Attack
// @HookAddress 0x6EE00
// @HookString  024a 9646024a 10470000 0000 8fee0608 P
// @EntryFunctionSymbol Sub_806EDFC_WarUpPanel_Attack

/**
 * changelog: 
 * Patch of this function created by Blanchon,
 * enum and other stuff from beco's code,
 * format the code and replace the custom part by any shape breakable block logic by shinespeciall
 * put all the shared functions into C_dependency type patch file,
 * put all the declarations into ASBB.h
 *            ---- by ssp (shinespeciall), 2023/4/22
 */

#include "ASBB.h"

extern void BreakAnyShapeBlock(unsigned char start_y_pos, unsigned char start_x_pos);

int Sub_806EDFC_WarUpPanel_Attack(unsigned short Ypos,unsigned short Xpos)
{
    char v2; // r0
    struct BgBDdef pDestroy;
    int blk_width;

    pDestroy.xp = (Xpos << 16) >> 22;
    pDestroy.yp = (Ypos << 16) >> 22;
    pDestroy.part = CurrentTileset_EventIdTablePointer[Layer1_DecompressedDataPointer[pDestroy.yp * Layer1_Width + pDestroy.xp]];
    pDestroy.coin = 0;
    pDestroy.obop = 0;
    pDestroy.SE = 0;
    pDestroy.hit = WHit.ucHPow;
    pDestroy.dir = 3;
    if ( Wario_ucReact == SWALK ) pDestroy.dir = 4;
    // -------------- Custom code ------------------
    if (pDestroy.part > (event_id_TopLeft - 1) && pDestroy.part < (event_id_one_col_bottom_end + 1))
    {
        BreakAnyShapeBlock(pDestroy.yp, pDestroy.xp);
        return 1;
    }
    // -------------- Custom code end---------------
    v2 = PanelPartWork_Broken_Main(&pDestroy);
    if ( v2 == 1 ) goto LABEL_11;
    if ( v2 == 2 ) return 128;
    if ( PanelPartWork_Switch_Main(&pDestroy, 1u) ) {
LABEL_11:
        v2 = 1;
    } else {
        v2 = 0;
    }
    return v2;
}
