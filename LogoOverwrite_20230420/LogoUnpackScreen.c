// @Description Overwrite the text data transfer to vram for WL4 logo in scene 5
// @HookAddress 0x5D3E
// from 0x5D3E to 0x5D58
// @HookString 0248 86460248 00470000 bf5d0008 P

/* Patch & Hook details
 
 .thumb
    .dcb 1
    ldr r0, .DATA
    mov lr, r0
    ldr r0, .DATA + 4
    bx r0
    .dcb 1
  .DATA:
    .word 0x08005DBF
    .word 0xAAAAAAAA
 */

/**
 * changelog: 
 * directly made from the IDA pro's generated C code.
 *            ---- by ssp (shinespeciall), 2022/09/27
 */

extern const unsigned char logoTiles[16384];
extern const unsigned char logoMap[1024];
extern const unsigned char logoPal[32];

#define bMsgJapanese (*(volatile unsigned char*) 0x3002C78) // u8 or u32 ?

#define Sub_800B734_UnPackScreen ((void (*)(unsigned int, unsigned int)) 0x800B735)
#define Sub_800C224_scene5_car_palette_change ((void (*)(unsigned int)) 0x800C225)

void LogoUnpackScreen()
{
    // overwrite this part if you want to modify the logo layer
    // unsigned int v0 = 0x829892E;
    // if ( bMsgJapanese )
    // {
    //     v0 = 0x8298908;
    // }
    // Sub_800B734_UnPackScreen(v0, 0x6008000);    // Wario Land 4 logo
    memcpy(0x6008000, logoMap, 1024);
    memcpy(0x5000000 + 7 * 16 * 2, logoPal, 32);

    // keep the vanilla code below
    Sub_800C224_scene5_car_palette_change(0xFu);// Wario's car (OBJ) pallet
}