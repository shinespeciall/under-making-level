// @Description add custom logic to trigger warp door
// @HookAddress 0x6FE68
// @HookString 0fb42288 391c090c 01a30333 9e46044b 1847000c 00280fbc 07d80249 08470000 P 53ff0608 c046
// Mode: Thumb
// patch logic by ssp (shinespeciall) 2022/04/09
// fix a bug caused by setting incorrect return value by ssp (shinespeciall) 2022/04/17

/**
.thumb
    @ .dcb 1
    push {r0-r3} @ start at 0x6FE68, keep r0 be the tile event id and pass it into the patch function
    ldrh r2, [r4] @ param 2 of Sub_806DDE4_PanelPartWork_Warp_DoorType2
    mov r1, r7
    lsr r1, #16 @ param 1 of Sub_806DDE4_PanelPartWork_Warp_DoorType2
    add r3, pc, #4
    add r3, #3
    mov lr, r3
    ldr r3, .DATA
    bx r3
    lsr r0, #16 @ deal with the return value from the patch function call
    cmp r0, #0 @ if (the return value & 0xFF0000) > 0
    pop {r0-r3}
    bhi .DATA + 10
    ldr r1, .DATA + 4 @ jump to the ret routine of the current function
    bx r1
    .dcb 1
.DATA:
    @ .word 0x0806FE93 @ following logic in the vanilla function
    .word 0xAAAAAAAA
    .word 0x0806FF53 @ ret

@ Contents of section .text:
@  0000 0fb42288 391c090c 01a30333 9e46044b  ..".9......3.F.K
@  0010 1847000c 00280fbc 07d80249 08470000  .G...(.....I.G..
@  0020 aaaaaaaa 53ff0608                    ....S...
 */

struct ENEMY_DATA {
    unsigned short CurEnemy_usStatus;
    unsigned char pAnmData1;
    unsigned char pAnmData2;
    unsigned long OAMDataPackPointerForCurrentAnimation;
    unsigned short CurEnemy_YPos;
    unsigned short CurEnemy_XPos;
    unsigned short CurEnemy_AffinePA;
    unsigned short CurEnemy_AffinePB;
    unsigned short CurEnemy_AffinePC;
    unsigned short CurEnemy_AffinePD;
    unsigned short CurEnemy_CurrentAnimationFrameId;
    unsigned char CurEnemy_RealFrameCountForCurrentAnimationFrame;
    unsigned char CurEnemy_GlobalId;
    unsigned char CurEnemy_RoomEntitySlotId;
    unsigned char CurEnemy_ucChrOfs;
    unsigned char CurEnemy_Prio;
    unsigned char CurEnemy_paletteId;
    unsigned char CurEnemy_CurrentAnimationId;
    unsigned char CurEnemy_Life;
    unsigned char CurEnemy_GuardAndDamageParam;
    unsigned char CurEnemy_DisableInteractionWithWarioCountdown;
    unsigned char CurEnemy_SizeY0_Bottom;
    unsigned char CurEnemy_SizeY1_Top;
    unsigned char CurEnemy_SizeX_LeftRight;
    unsigned char CurEnemy_HitboxY0;
    unsigned char CurEnemy_HitboxY1;
    unsigned char CurEnemy_HitboxX0;
    unsigned char CurEnemy_HitboxX1;
    unsigned char CurEnemy_TWork0;
    unsigned char CurEnemy_TWork1;
    unsigned char CurEnemy_TWork2;
    unsigned char CurEnemy_TWork3;
    unsigned char CurEnemy_padding;
};

#define ucDisConFlg (*(volatile unsigned char*) 0x3000012)
#define ucTotalTaikaiNum (*(volatile unsigned char*) 0x3000023)
#define CurrentRoom (*(volatile unsigned char*) 0x03000024)
#define ucTekiGroup (*(volatile unsigned char*) 0x03000027)
#define CurrentEntityInfoList_TEbuf ((volatile struct ENEMY_DATA*) 0x3000104)
#define cPauseFlag (*(volatile unsigned char*) 0x3000C35)
#define sGameSeq (*(volatile unsigned short*) 0x3000C3C)
#define DoorInfoPointerTable ((volatile unsigned char**) 0x878F21C)
#define EntitySetPointerTable ((volatile unsigned char**) 0x878EF78)

#define Sub_806DDE4_PanelPartWork_Warp_DoorType2 ((int (*)(int, int)) 0x806DDE5)
#define Sub_8001DA4_m4aSongNumStart ((void (*)(int)) 0x8001DA5)
#define Sub_801DE7C_EnemyInit ((void (*)()) 0x801DE7D)

#define Sub_801DEC0_LoadEntitySet ((void (*)()) 0x801DEC1)


int Sub_806FD74_WarpDoorTriggerLogicPatch(unsigned short eventId, int param1, int param2)
{
    // since __attribute__((no_caller_saved_registers)) cannot work
    __asm__ volatile("push {r4-r7}");
    __asm__ volatile("mov r7, r10");
    __asm__ volatile("mov r6, r9");
    __asm__ volatile("mov r5, r8");
    __asm__ volatile("push {r5-r7}");

    int return_value = eventId;

    // Vanilla code
    if ( eventId == 3 ) // current event id == 3, room edge warp door trigger
    {
        if ( Sub_806DDE4_PanelPartWork_Warp_DoorType2(param1, param2) )
            return_value = 0;
    }
    else if ( eventId == 9 ) // current event id == 9
    {
        if ( Sub_806DDE4_PanelPartWork_Warp_DoorType2(param1, param2) )
        {
            Sub_8001DA4_m4aSongNumStart(25);
            return_value = 0;
        }
    }
    else if ( eventId == 8 ) // current event id == 8
    {
        // set return_value to do more check in the vanilla function
        return_value = 0x10000;
    }
    else if ( eventId == 0x37 ) // unused event id 0x37
    {
        // Custom code
        if ( sGameSeq == 2 )
        {
            unsigned char *doorHeader = DoorInfoPointerTable[ucTotalTaikaiNum];
            while (doorHeader[0] != 2 || doorHeader[1] != CurrentRoom || \
            doorHeader[2] > param2 || param2 > doorHeader[3] || \
            doorHeader[4] > param1 || param1 > doorHeader[5])
            {
                doorHeader += 12;
                if (!doorHeader[0])
                {
                    goto not_find;
                }
            }

            // if door and event tile both appear
            if (ucTekiGroup != doorHeader[9])
            {
                unsigned char lastTekiGroup = ucTekiGroup;
                ucTekiGroup = doorHeader[9];

                // Sub_801DE7C_EnemyInit();
                Sub_801DEC0_LoadEntitySet();

                // now we reset the enemy status to 0 if needed and change its AI
                unsigned char last_entityset_globalId_list[20];
                unsigned char new_entityset_globalId_list[20];
                int i = 0;
                do
                {
                    last_entityset_globalId_list[i] = EntitySetPointerTable[lastTekiGroup][2 * i];
                    new_entityset_globalId_list[i] = EntitySetPointerTable[ucTekiGroup][2 * i];
                    i++;
                } while (last_entityset_globalId_list[i] && new_entityset_globalId_list[i]);
                
                i = 0;
                do
                {
                    int new_globalId = -1;
                    unsigned char old_globalId = CurrentEntityInfoList_TEbuf[i].CurEnemy_GlobalId;
                    for (int local_id = 0; \
                    last_entityset_globalId_list[local_id] || \
                    new_entityset_globalId_list[local_id]; \
                    local_id++)
                    {
                        if (old_globalId == last_entityset_globalId_list[local_id])
                        {
                            new_globalId = new_entityset_globalId_list[local_id];
                            break;
                        }
                    }

                    // reset the enemy if it the new global id is different
                    if ((old_globalId != new_globalId) && (old_globalId <= 0x80) && (old_globalId > 0xF) && \
                    (new_globalId <= 0x80) && (new_globalId > 0xF))
                    {
                        CurrentEntityInfoList_TEbuf[i].CurEnemy_GlobalId = new_globalId;
                        CurrentEntityInfoList_TEbuf[i].CurEnemy_usStatus = 1;
                        CurrentEntityInfoList_TEbuf[i].CurEnemy_CurrentAnimationFrameId = 0;
                        CurrentEntityInfoList_TEbuf[i].CurEnemy_RealFrameCountForCurrentAnimationFrame = 0;
                        CurrentEntityInfoList_TEbuf[i].CurEnemy_CurrentAnimationId = 0;
                    }

                    i++;
                } while (i < 23);
            }
        }
not_find:
        return_value = 0;
    }

    __asm__ volatile("pop {r5-r7}");
    __asm__ volatile("mov r10, r7");
    __asm__ volatile("mov r9, r6");
    __asm__ volatile("mov r8, r5");
    __asm__ volatile("pop {r4-r7}");
    return return_value;
}