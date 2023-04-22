// @Description ASBB shared fucntions and stuff

/**
 * changelog:
 * enum and other stuff from beco's code,
 * put all the shared functions into C_dependency type patch file,
 * put all the declarations into ASBB.h
 *            ---- by ssp (shinespeciall), 2023/4/22
 */

#include "ASBB.h"

int find_next_valid_slot(struct AnyShapeBlockBreakdef *currentTile16_pos_array_ptr)
{
    for(int i = 0; i < MAX_Tile16_deal_at_the_same_time; i++)
    {
        if(currentTile16_pos_array_ptr[i].x_pos == -1) return i;
    }
    return -1;
}

int find_a_used_slot(struct AnyShapeBlockBreakdef *currentTile16_pos_array_ptr)
{
    for(int i = 0; i < MAX_Tile16_deal_at_the_same_time; i++)
    {
        if(currentTile16_pos_array_ptr[i].x_pos != -1) return i;
    }
    return -1;
}

int check_existance(struct AnyShapeBlockBreakdef *currentTile16_pos_array_ptr,
                    unsigned char y_pos, unsigned char x_pos)
{
    for(int i = 0; i < MAX_Tile16_deal_at_the_same_time; i++)
    {
        if(currentTile16_pos_array_ptr[i].x_pos == x_pos &&
           currentTile16_pos_array_ptr[i].y_pos == y_pos) return i;
    }
    return -1;
}

void Search_And_Break_logic_For_Any_shape_Block(struct AnyShapeBlockBreakdef *currentTile16_pos_array_ptr)
{
    if (find_next_valid_slot(currentTile16_pos_array_ptr) == -1) return;

    struct BgBDdef tmp_pDestroy;
    tmp_pDestroy.xp = (currentTile16_pos_array_ptr[0].x_pos << 16) >> 22;
    tmp_pDestroy.yp = (currentTile16_pos_array_ptr[0].y_pos << 16) >> 22;
    tmp_pDestroy.part = CurrentTileset_EventIdTablePointer[Layer1_DecompressedDataPointer[tmp_pDestroy.yp * Layer1_Width + tmp_pDestroy.xp]];
    tmp_pDestroy.coin = 0;
    tmp_pDestroy.obop = 0;
    tmp_pDestroy.SE = 0;
    tmp_pDestroy.hit = WHit.ucSPow;
    tmp_pDestroy.dir = 1;

    int cur_Tile16_slot_id = find_a_used_slot(currentTile16_pos_array_ptr);
    while(cur_Tile16_slot_id >= 0)
    {
        // clean a Tile16 from vram and layer data in the ram
        tmp_pDestroy.yp = currentTile16_pos_array_ptr[cur_Tile16_slot_id].y_pos;
        tmp_pDestroy.xp = currentTile16_pos_array_ptr[cur_Tile16_slot_id].x_pos;

        unsigned short *L1_Tile_ptr = &(Layer1_DecompressedDataPointer[tmp_pDestroy.yp * Layer1_Width + tmp_pDestroy.xp]);
        tmp_pDestroy.part = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
        Sub_806F2AC_BgBrokenBlock_ObjSet(&tmp_pDestroy);
        Sub_806FFB0_Panel_PutBG_Save(0, tmp_pDestroy.yp, tmp_pDestroy.xp);

        // find the current Tile16's breakable neighbor Tile16s and add them into the list if theyir event ids are correct
        char U = 0, D = 0, L = 0, R = 0;
        unsigned short tmp_eventId;
        if (tmp_pDestroy.part == event_id_TopLeft) {
            L1_Tile_ptr += 1;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) R = 1;
            L1_Tile_ptr += Layer1_Width - 1;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) D = 1;
        } else if (tmp_pDestroy.part == event_id_Top_border) {
            L1_Tile_ptr -= 1;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) L = 1;
            L1_Tile_ptr += 2;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) R = 1;
            L1_Tile_ptr += Layer1_Width - 1;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) D = 1;
        } else if (tmp_pDestroy.part == event_id_TopRight) {
            L1_Tile_ptr -= 1;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) L = 1;
            L1_Tile_ptr += Layer1_Width + 1;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) D = 1;
        } else if (tmp_pDestroy.part == event_id_Left_border) {
            L1_Tile_ptr -= Layer1_Width;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) U = 1;
            L1_Tile_ptr += Layer1_Width + 1;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) R = 1;
            L1_Tile_ptr += Layer1_Width - 1;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) D = 1;
        } else if (tmp_pDestroy.part == event_id_internal) {
            L1_Tile_ptr -= Layer1_Width;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) U = 1;
            L1_Tile_ptr += Layer1_Width - 1;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) L = 1;
            L1_Tile_ptr += 2;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) R = 1;
            L1_Tile_ptr += Layer1_Width - 1;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) D = 1;
        } else if (tmp_pDestroy.part == event_id_Right_border) {
            L1_Tile_ptr -= Layer1_Width;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) U = 1;
            L1_Tile_ptr += Layer1_Width - 1;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) L = 1;
            L1_Tile_ptr += Layer1_Width + 1;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) D = 1;
        } else if (tmp_pDestroy.part == event_id_BottomLeft) {
            L1_Tile_ptr -= Layer1_Width;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) U = 1;
            L1_Tile_ptr += Layer1_Width + 1;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) R = 1;
        } else if (tmp_pDestroy.part == event_id_Bottom_border) {
            L1_Tile_ptr -= Layer1_Width;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) U = 1;
            L1_Tile_ptr += Layer1_Width - 1;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) L = 1;
            L1_Tile_ptr += 2;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) R = 1;
        } else if (tmp_pDestroy.part == event_id_BottomRight) {
            L1_Tile_ptr -= Layer1_Width;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) U = 1;
            L1_Tile_ptr += Layer1_Width - 1;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) L = 1;
        } else if (tmp_pDestroy.part == event_id_one_row_left_end) {
            L1_Tile_ptr += 1;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) R = 1;
        } else if (tmp_pDestroy.part == event_id_one_row_middle) {
            L1_Tile_ptr -= 1;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) L = 1;
            L1_Tile_ptr += 2;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) R = 1;
        } else if (tmp_pDestroy.part == event_id_one_row_right_end) {
            L1_Tile_ptr -= 1;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) L = 1;
        } else if (tmp_pDestroy.part == event_id_one_col_top_end) {
            L1_Tile_ptr += Layer1_Width;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) D = 1;
        } else if (tmp_pDestroy.part == event_id_one_col_middle) {
            L1_Tile_ptr -= Layer1_Width;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) U = 1;
            L1_Tile_ptr += 2 * Layer1_Width;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) D = 1;
        } else if (tmp_pDestroy.part == event_id_one_col_bottom_end) {
            L1_Tile_ptr -= Layer1_Width;
            tmp_eventId = CurrentTileset_EventIdTablePointer[*L1_Tile_ptr];
            if (tmp_eventId > (event_id_TopLeft - 1) && tmp_eventId < (event_id_one_col_bottom_end + 1)) U = 1;
        }

        char y, x;
        if (U)
        {
            int index = find_next_valid_slot(currentTile16_pos_array_ptr);
            if (index == -1) return;
            y = currentTile16_pos_array_ptr[cur_Tile16_slot_id].y_pos - 1;
            x = currentTile16_pos_array_ptr[cur_Tile16_slot_id].x_pos;
            if (check_existance(currentTile16_pos_array_ptr, y, x) == -1)
            {
                currentTile16_pos_array_ptr[index].y_pos = y;
                currentTile16_pos_array_ptr[index].x_pos = x;
            }
        }
        if (L)
        {
            int index = find_next_valid_slot(currentTile16_pos_array_ptr);
            if (index == -1) return;
            y = currentTile16_pos_array_ptr[cur_Tile16_slot_id].y_pos;
            x = currentTile16_pos_array_ptr[cur_Tile16_slot_id].x_pos - 1;
            if (check_existance(currentTile16_pos_array_ptr, y, x) == -1)
            {
                currentTile16_pos_array_ptr[index].y_pos = y;
                currentTile16_pos_array_ptr[index].x_pos = x;
            }
        }
        if (R)
        {
            int index = find_next_valid_slot(currentTile16_pos_array_ptr);
            if (index == -1) return;
            y = currentTile16_pos_array_ptr[cur_Tile16_slot_id].y_pos;
            x = currentTile16_pos_array_ptr[cur_Tile16_slot_id].x_pos + 1;
            if (check_existance(currentTile16_pos_array_ptr, y, x) == -1)
            {
                currentTile16_pos_array_ptr[index].y_pos = y;
                currentTile16_pos_array_ptr[index].x_pos = x;
            }
        }
        if (D)
        {
            int index = find_next_valid_slot(currentTile16_pos_array_ptr);
            if (index == -1) return;
            y = currentTile16_pos_array_ptr[cur_Tile16_slot_id].y_pos + 1;
            x = currentTile16_pos_array_ptr[cur_Tile16_slot_id].x_pos;
            if (check_existance(currentTile16_pos_array_ptr, y, x) == -1)
            {
                currentTile16_pos_array_ptr[index].y_pos = y;
                currentTile16_pos_array_ptr[index].x_pos = x;
            }
        }

        // clear the current Tile16 from the list
        currentTile16_pos_array_ptr[cur_Tile16_slot_id].y_pos = -1;
        currentTile16_pos_array_ptr[cur_Tile16_slot_id].x_pos = -1;

        // reset U, L, R, D
        // U = L = R = D = 0;

        // search if there is still some Tile16 in the list
        cur_Tile16_slot_id = find_a_used_slot(currentTile16_pos_array_ptr);
    }
}

void BreakAnyShapeBlock(unsigned char start_y_pos, unsigned char start_x_pos)
{
    // use a list to save the Tile16s position which will be wiped out in the whole run
    // the Tile16 be added into the list will be cleared in the future
    // the Tile16 be deleted ftom the list has been cleared, or just be cleared in the current step
    struct AnyShapeBlockBreakdef currentTile16_pos_array[MAX_Tile16_deal_at_the_same_time];
    for (int i = 1; i < MAX_Tile16_deal_at_the_same_time; i++)
    {
        currentTile16_pos_array[i].x_pos = -1;
        currentTile16_pos_array[i].y_pos = -1;
    }

    // initialize the list with the first root Tile16 to be cleared
    currentTile16_pos_array[0].x_pos = start_x_pos;
    currentTile16_pos_array[0].y_pos = start_y_pos;

    // run a quasi-BFS algorithm to delete breakable Tile16s one by one
    Search_And_Break_logic_For_Any_shape_Block(currentTile16_pos_array);

    // end
    Sub_8001DA4_m4aSongNumStart(253);
}