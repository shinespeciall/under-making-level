// @Description Add Sub_806D7F8_Atari_WaOnly_ALL into the Atari function pointer table
// @HookAddress 0x78F310
// directly hook inside the Atari function pointer table
// @HookString P

/**
 * changelog: 
 * since terrain slot 0x0B never be used,
 * why not add a terrain type which will always block wario but pass enemy?
 *            ---- by ssp (shinespeciall), 2022/11/11
 */

struct Mhitdef // found in /src/gmap/atari.o
{
    int anum;
    unsigned int x_0x3F;
    unsigned int y_0x3F;
    int swnum;
    int swtype;
    int who; // Wario: 0, Enemy: 1
};

#define Sub_806D730_Atari_NASHI ((unsigned int (*)(struct Mhitdef *)) 0x806D731)
#define Sub_806D734_Atari_ALL ((unsigned int (*)(struct Mhitdef *)) 0x806D735)

unsigned int Sub_806D7F8_Atari_WaOnly_ALL(struct Mhitdef *pMhit)
{
    // customized logic
    if ( pMhit->who ) // if it is an enemy
    {
        pMhit->anum = 0;
        return Sub_806D730_Atari_NASHI(pMhit);
    }
    if ( !(pMhit->who) )
    {
        pMhit->anum = 1;
        return Sub_806D734_Atari_ALL(pMhit);
    }
}
