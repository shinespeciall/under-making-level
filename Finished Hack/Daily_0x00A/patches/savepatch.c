// @Description SeisanSavePatch to trigger credit
// @HookAddress 0x81262
// @HookString 02 48 86 46 02 48 00 47 00 00 85 12 08 08 P C0 46 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46 C0 46
// Mode: Thumb
// patch logic by beco. source: https://github.com/becored/WL4_TA/blob/main/patches/TimeAttack_SeisanSavePatch.c
// custom code by ssp (shinespeciall) 2022/04/05

#define PassageID (*(volatile unsigned char*) 0x3000002)
#define InPassageLevelID (*(volatile unsigned char*) 0x3000003)
#define ucKagiGetFlg (*(volatile unsigned char*) 0x3000C0C) // 00(no) 01(yes)
#define GlobalGameMode (*(volatile unsigned short*) 0x3000C3A)
#define W4ItemStatus ((volatile unsigned char*) 0x3000A68)

void SeisanSavePatch() {
    // Vanilla code
    if (ucKagiGetFlg) {
        W4ItemStatus[24 * PassageID + 4 * InPassageLevelID] |= 0x20;
    }

    // Custom code
    GlobalGameMode = 12;
}