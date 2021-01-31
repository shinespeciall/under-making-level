// @Description Allows Wario Speed Reset With Condition Checks
// @HookAddress 0x12BB2
// Mode: Thumb
// Made by ssp(shinespeciall)
// Verison 1.0
// supported compiler: GCC: (GNU Arm Embedded Toolchain 9-2020-q2-update) 9.3.1 20200408 (release)

/* Hook details
------------------------- this only works when the new function push lr at first and bx lr at last.
0x8012BB2: LDR R0, 0x8012BBF    | 4803
0x8012BB4: MOV LR, R0           | 4686
0x8012BB6: LDR R0, pointer      | 4801
0x8012BB8: BX R0                | 4700
0x8012BBA: B 0x8012BC6          | E002
0x8012BCC: .fill a pointer      | 0XXXXXXX ; end with 1 (in binary) to make it run in thumb mode
0x8012BC0: .fill BB2B0108       | 08012BBB ; end with 1 (in binary) to make it run in thumb mode
0x8012BC2: nop                  | 46C0‬     ; i.e. mov r8, r8
0x8012BC4: nop....              | 46C0
-------------------------
Hook String:
@HookString 03 48 86 46 01 48 00 47 02 E0 P BB 2B 01 08 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46
count:                                     ^14                                                         ^34
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
void WarioSpeedResetWithCondCheck()
{
    /**WarioState shoulb be normal state 
     * WarioAnimation is always 4 before Wario throwing the item, it always reset speed first then set WarioAnimation to 38 (midair throw)
     * u8_WarioHoldItem == 4 escape the cases which Wario is not holding something
     * R4 Get the next frame WarioAnimation flag, this trigger the skip finally
     */
    unsigned char data = 0;
    asm volatile ("mov %0, r4\n\t" : "=r" (data));

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
