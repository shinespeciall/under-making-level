// @Description shittest_FO
// @HookAddress 0x6C75E
// Mode: Thumb
// Made by ssp(shinespeciall)
// Note: only for test

/* Hook details
------------------------- this only works when the new function push lr at first and bx lr at last.
0x806C75E: LDR R0, 0x806C767    | 4803
0x806C760: MOV LR, R0           | 4686
0x806C762: LDR R0, pointer      | 4801
0x806C764: BX R0                | 4700
0x806C766: B 0x806C770          | E002
0x806C768: .fill a pointer      | 0XXXXXXX ; end with 1 (in binary) to make it run in thumb mode
0x806C76C: .fill 67C70608       | 0806C767 ; end with 1 (in binary) to make it run in thumb mode
0x806C770: nop                  | 46C0     ; i.e. mov r8, r8
0x806C772: nop....
-------------------------
Hook String:
@HookString 03 48 86 46 01 48 00 47 02 E0 P 67 C7 06 08 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46
count:                                     ^14                                                                     ^38
Hook length: 38 Bytes
*/

#define GameState (*(volatile unsigned char*) 0x3000C3C)
#define unk_300001B (*(volatile unsigned char*) 0x300001B)
#define unk_3000046 (*(volatile unsigned char*) 0x3000046)
#define sub_806E08C ((void (*)()) 0x806E08D)

#define usBg2Vofs (*(volatile unsigned short*) 0x3001880)
#define WarioState (*(volatile unsigned char*) 0x3001898)

#define myflag_Iscounting (*(volatile unsigned char*) 0x30000E6)



__attribute__((no_caller_saved_registers))
void FrameOperations()
{
    // vanilla code for animated tiles loading
    if ( (GameState == 2 || GameState == 6 || GameState == 4 && unk_300001B == 1) && !unk_3000046 )
    {
        sub_806E08C();
    }

    if(myflag_Iscounting >= 0 && myflag_Iscounting < 0x10)
    {
        myflag_Iscounting++;
        usBg2Vofs -= 4;
    }
    else if(myflag_Iscounting >= 0x10 && myflag_Iscounting < 0x20)
    {
        myflag_Iscounting++;
        usBg2Vofs += 4;
    }
    else
    {
        myflag_Iscounting = 0;
    }
    
}
