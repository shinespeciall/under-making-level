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

const unsigned char logoMap[1024] __attribute__((aligned(4)))=
{
	0x00,0x02,0x01,0x02,0x02,0x02,0x03,0x02,0x04,0x02,0x05,0x02,0x06,0x02,0x07,0x02,
	0x08,0x02,0x09,0x02,0x0A,0x02,0x0B,0x02,0x0C,0x02,0x0D,0x02,0x0E,0x02,0x0F,0x02,
	0x10,0x02,0x11,0x02,0x12,0x02,0x13,0x02,0x14,0x02,0x15,0x02,0x16,0x02,0x17,0x02,
	0x18,0x02,0x19,0x02,0x1A,0x02,0x1B,0x02,0x1C,0x02,0x1D,0x02,0x1E,0x02,0x1F,0x02,
	0x20,0x02,0x21,0x02,0x22,0x02,0x23,0x02,0x24,0x02,0x25,0x02,0x26,0x72,0x27,0x72,
	0x28,0x72,0x29,0x72,0x2A,0x02,0x2B,0x02,0x2C,0x02,0x2D,0x72,0x2E,0x02,0x2F,0x72,
	0x30,0x02,0x31,0x02,0x32,0x02,0x33,0x02,0x34,0x02,0x35,0x02,0x36,0x02,0x37,0x02,
	0x38,0x02,0x39,0x02,0x3A,0x02,0x3B,0x02,0x3C,0x02,0x3D,0x02,0x3E,0x02,0x3F,0x02,

	0x40,0x02,0x41,0x02,0x42,0x02,0x43,0x02,0x44,0x02,0x45,0x72,0x46,0x72,0x47,0x72,
	0x48,0x72,0x49,0x72,0x4A,0x72,0x4B,0x72,0x4C,0x72,0x4D,0x72,0x4E,0x72,0x4F,0x72,
	0x50,0x72,0x51,0x72,0x52,0x02,0x53,0x02,0x54,0x02,0x55,0x02,0x56,0x02,0x57,0x02,
	0x58,0x02,0x59,0x02,0x5A,0x02,0x5B,0x02,0x5C,0x02,0x5D,0x02,0x5E,0x02,0x5F,0x02,
	0x60,0x02,0x61,0x02,0x62,0x02,0x63,0x02,0x64,0x02,0x65,0x72,0x66,0x72,0x67,0x72,
	0x68,0x72,0x69,0x72,0x6A,0x72,0x6B,0x72,0x6C,0x72,0x6D,0x72,0x6E,0x72,0x6F,0x72,
	0x70,0x72,0x71,0x72,0x72,0x72,0x73,0x72,0x74,0x72,0x75,0x72,0x76,0x72,0x77,0x02,
	0x78,0x02,0x79,0x02,0x7A,0x02,0x7B,0x02,0x7C,0x02,0x7D,0x02,0x7E,0x02,0x7F,0x02,

	0x80,0x02,0x81,0x02,0x82,0x02,0x83,0x02,0x84,0x02,0x85,0x72,0x86,0x02,0x87,0x72,
	0x88,0x02,0x89,0x72,0x8A,0x72,0x8B,0x72,0x8C,0x72,0x8D,0x02,0x8E,0x72,0x8F,0x72,
	0x90,0x72,0x91,0x72,0x92,0x72,0x93,0x72,0x94,0x72,0x95,0x72,0x96,0x72,0x97,0x02,
	0x98,0x02,0x99,0x02,0x9A,0x02,0x9B,0x02,0x9C,0x02,0x9D,0x02,0x9E,0x02,0x9F,0x02,
	0xA0,0x02,0xA1,0x02,0xA2,0x02,0xA3,0x02,0xA4,0x02,0xA5,0x02,0xA6,0x72,0xA7,0x72,
	0xA8,0x72,0xA9,0x72,0xAA,0x72,0xAB,0x72,0xAC,0x72,0xAD,0x72,0xAE,0x72,0xAF,0x72,
	0xB0,0x72,0xB1,0x02,0xB2,0x02,0xB3,0x72,0xB4,0x72,0xB5,0x72,0xB6,0x72,0xB7,0x02,
	0xB8,0x02,0xB9,0x02,0xBA,0x02,0xBB,0x02,0xBC,0x02,0xBD,0x02,0xBE,0x02,0xBF,0x02,

	0xC0,0x02,0xC1,0x02,0xC2,0x02,0xC3,0x02,0xC4,0x02,0xC5,0x02,0xC6,0x72,0xC7,0x72,
	0xC8,0x72,0xC9,0x72,0xCA,0x72,0xCB,0x72,0xCC,0x72,0xCD,0x72,0xCE,0x72,0xCF,0x72,
	0xD0,0x72,0xD1,0x02,0xD2,0x02,0xD3,0x02,0xD4,0x72,0xD5,0x72,0xD6,0x72,0xD7,0x02,
	0xD8,0x02,0xD9,0x02,0xDA,0x02,0xDB,0x02,0xDC,0x02,0xDD,0x02,0xDE,0x02,0xDF,0x02,
	0xE0,0x02,0xE1,0x02,0xE2,0x02,0xE3,0x02,0xE4,0x02,0xE5,0x02,0xE6,0x02,0xE7,0x02,
	0xE8,0x02,0xE9,0x72,0xEA,0x72,0xEB,0x72,0xEC,0x72,0xED,0x72,0xEE,0x72,0xEF,0x72,
	0xF0,0x72,0xF1,0x72,0xF2,0x72,0xF3,0x72,0xF4,0x72,0xF5,0x72,0xF6,0x72,0xF7,0x02,
	0xF8,0x72,0xF9,0x02,0xFA,0x02,0xFB,0x02,0xFC,0x02,0xFD,0x02,0xFE,0x02,0xFF,0x02,

	0x00,0x03,0x01,0x03,0x02,0x03,0x03,0x03,0x04,0x03,0x05,0x03,0x06,0x03,0x07,0x03,
	0x08,0x03,0x09,0x73,0x0A,0x73,0x0B,0x73,0x0C,0x73,0x0D,0x73,0x0E,0x73,0x0F,0x73,
	0x10,0x73,0x11,0x73,0x12,0x73,0x13,0x73,0x14,0x73,0x15,0x73,0x16,0x73,0x17,0x73,
	0x18,0x73,0x19,0x03,0x1A,0x03,0x1B,0x03,0x1C,0x03,0x1D,0x03,0x1E,0x03,0x1F,0x03,
	0x20,0x03,0x21,0x03,0x22,0x03,0x23,0x03,0x24,0x03,0x25,0x03,0x26,0x03,0x27,0x03,
	0x28,0x03,0x29,0x03,0x2A,0x03,0x2B,0x73,0x2C,0x73,0x2D,0x73,0x2E,0x73,0x2F,0x73,
	0x30,0x73,0x31,0x73,0x32,0x73,0x33,0x73,0x34,0x73,0x35,0x73,0x36,0x73,0x37,0x73,
	0x38,0x73,0x39,0x03,0x3A,0x03,0x3B,0x03,0x3C,0x03,0x3D,0x03,0x3E,0x03,0x3F,0x03,

	0x40,0x03,0x41,0x03,0x42,0x03,0x43,0x03,0x44,0x03,0x45,0x03,0x46,0x03,0x47,0x03,
	0x48,0x03,0x49,0x03,0x4A,0x03,0x4B,0x03,0x4C,0x03,0x4D,0x73,0x4E,0x73,0x4F,0x73,
	0x50,0x73,0x51,0x73,0x52,0x73,0x53,0x73,0x54,0x03,0x55,0x03,0x56,0x03,0x57,0x03,
	0x58,0x03,0x59,0x03,0x5A,0x03,0x5B,0x03,0x5C,0x03,0x5D,0x03,0x5E,0x03,0x5F,0x03,
	0x60,0x03,0x61,0x03,0x62,0x03,0x63,0x03,0x64,0x03,0x65,0x03,0x66,0x03,0x67,0x03,
	0x68,0x03,0x69,0x03,0x6A,0x03,0x6B,0x03,0x6C,0x03,0x6D,0x73,0x6E,0x73,0x6F,0x73,
	0x70,0x73,0x71,0x73,0x72,0x73,0x73,0x73,0x74,0x73,0x75,0x73,0x76,0x73,0x77,0x73,
	0x78,0x73,0x79,0x03,0x7A,0x03,0x7B,0x03,0x7C,0x03,0x7D,0x03,0x7E,0x03,0x7F,0x03,

	0x80,0x03,0x81,0x03,0x82,0x03,0x83,0x03,0x84,0x03,0x85,0x03,0x86,0x03,0x87,0x03,
	0x88,0x03,0x89,0x03,0x8A,0x03,0x8B,0x03,0x8C,0x03,0x8D,0x03,0x8E,0x03,0x8F,0x03,
	0x90,0x03,0x91,0x03,0x92,0x03,0x93,0x03,0x94,0x03,0x95,0x03,0x96,0x03,0x97,0x03,
	0x98,0x03,0x99,0x03,0x9A,0x03,0x9B,0x03,0x9C,0x03,0x9D,0x03,0x9E,0x03,0x9F,0x03,
	0xA0,0x03,0xA1,0x03,0xA2,0x03,0xA3,0x03,0xA4,0x03,0xA5,0x03,0xA6,0x03,0xA7,0x03,
	0xA8,0x03,0xA9,0x03,0xAA,0x03,0xAB,0x03,0xAC,0x03,0xAD,0x03,0xAE,0x03,0xAF,0x03,
	0xB0,0x03,0xB1,0x03,0xB2,0x03,0xB3,0x03,0xB4,0x03,0xB5,0x03,0xB6,0x03,0xB7,0x03,
	0xB8,0x03,0xB9,0x03,0xBA,0x03,0xBB,0x03,0xBC,0x03,0xBD,0x03,0xBE,0x03,0xBF,0x03,

	0xC0,0x03,0xC1,0x03,0xC2,0x03,0xC3,0x03,0xC4,0x03,0xC5,0x03,0xC6,0x03,0xC7,0x03,
	0xC8,0x03,0xC9,0x03,0xCA,0x03,0xCB,0x03,0xCC,0x03,0xCD,0x03,0xCE,0x03,0xCF,0x03,
	0xD0,0x03,0xD1,0x03,0xD2,0x03,0xD3,0x03,0xD4,0x03,0xD5,0x03,0xD6,0x03,0xD7,0x03,
	0xD8,0x03,0xD9,0x03,0xDA,0x03,0xDB,0x03,0xDC,0x03,0xDD,0x03,0xDE,0x03,0xDF,0x03,
	0xE0,0x03,0xE1,0x03,0xE2,0x03,0xE3,0x03,0xE4,0x03,0xE5,0x03,0xE6,0x03,0xE7,0x03,
	0xE8,0x03,0xE9,0x03,0xEA,0x03,0xEB,0x03,0xEC,0x03,0xED,0x03,0xEE,0x03,0xEF,0x03,
	0xF0,0x03,0xF1,0x03,0xF2,0x03,0xF3,0x03,0xF4,0x03,0xF5,0x03,0xF6,0x03,0xF7,0x03,
	0xF8,0x03,0xF9,0x03,0xFA,0x03,0xFB,0x03,0xFC,0x03,0xFD,0x03,0xFE,0x03,0xFF,0x03,
};

const unsigned char logoPal[32] __attribute__((aligned(4)))=
{
	0xE0,0x03,0x1F,0x00,0x00,0x00,0xFE,0x7F,0xFF,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

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