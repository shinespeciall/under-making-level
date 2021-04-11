// @Description Wario can now throw enemies without losing his speed
// @HookAddress 0x12BB2
// Mode: Thumb
// Made by ssp(shinespeciall)
// Verison 1.1

/** Changelog:
 * v1.1
 * rewrite the hookstring and the way the function recepting variable
 * the patch is now compatible with every version of arm7 gcc compiler
 *  
 * v1.0
 * Implement the feture and wario can throw enemies without losing his speed
 */

/* Hook details
------------------------- this only works when the new function push lr at first and bx lr at last.
0x8012BB2: PUSH R4              | B410
0x8012BB4: MOV R0, R4           | 1C20
0x8012BB6: LDR R1, 0x8012BBB    | 4903
0x8012BB8: MOV LR, R1           | 468E
0x8012BBA: LDR R1, pointer      | 4901
0x8012BBC: BX R1                | 4708
0x8012BBE: B 0x8012BC8          | E002
0x8012BC0: .fill a pointer      | 0XXXXXXX ; end with 1 (in binary) to make it run in thumb mode
0x8012BC4: .fill C92B0108       | 08012BC9 ; end with 1 (in binary) to make it run in thumb mode
0x8012BC8: POP R4               | BC10
0x8012BCA: NOP                  | 46C0
0x8012BCC: NOP                  | 46C0
0x8012BCE: NOP                  | 46C0
0x8012BD0: NOP                  | 46C0
0x8012BD2: NOP                  | 46C0
-------------------------
Hook String:
@HookString 10 B4 20 1C 03 49 8E 46 01 49 08 47 02 E0 P C9 2B 01 08 10 BC C0 46 C0 46 C0 46 C0 46 C0 46
count:                                                                                                 ^34
Hook length: 34 Bytes
*/

#define WarioState (*(volatile unsigned char*) 0x3001898)
#define WarioAnimation (*(volatile unsigned char*) 0x3001899)

#define u32_3001930 (*(volatile unsigned int*) 0x3001930)
#define u32_3001934 (*(volatile unsigned int*) 0x3001934)
#define u32_3001940 (*(volatile unsigned int*) 0x3001940)
#define u32_3001944 (*(volatile unsigned int*) 0x3001944)
#define u8_WarioHoldItem (*(volatile unsigned char*) 0x3001948)

#define Sub_800FD28_WarioSpeedReset ((void (*)()) 0x800FD29)

__attribute__((no_caller_saved_registers))
void WarioSpeedResetWithCondCheck(unsigned char data)
{
    /**WarioState should be in normal state 
     * WarioAnimation is always 4 before Wario throwing the item, it always reset speed first then set WarioAnimation to 38 (midair throw)
     * u8_WarioHoldItem == 4 escape the cases which Wario is not holding something
     * R4 Get the next frame WarioAnimation flag in the vanilla code.
     * we fetch it using the patch function's parameter passing, which triggers the skip finally
     */

    if (!((WarioState == 0 && WarioAnimation == 4 && u8_WarioHoldItem == 4 && data == 0x26))) {
        Sub_800FD28_WarioSpeedReset();
    }

    // vanilla code
    u32_3001930 = 0;
    u32_3001934 = 0;
    if ( (unsigned short)u32_3001940 != 4 )
    {
        u32_3001940 = 0;
        u32_3001944 = 0;
    }
}
