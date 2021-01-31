// @Description test code to replace Rock AI
// @HookAddress 0x78E854
// Mode: Thumb
// Made by ssp(shinespeciall) based on the leak
// Verison 1.0

/**Changelog:
 * 1.0
 * Add basic logic and test the patch
 * /

/* Hook String:
@HookString P
*/

#define Tbuf (*(volatile unsigned char*) 0x03000A24)
#define iGmTimeFrame (*(volatile unsigned int*) 0x03000BEC)
#define Terrain_usKoka_SolidOrWater (*(volatile unsigned short*) 0x030000A2)

// rock functions
#define Q_INITIAL_zako_iwa ((int (*)()) 0x803E55F)
#define Q_K0_WALK_zako_iwa ((int (*)()) 0x803E591)
#define K0_WALK_zako_iwa ((void (*)()) 0x803E5C1)
#define Q_H_RAKKA_V_zako_iwa ((void (*)()) 0x803E62D)
#define Q_HIKKURI_L_zako_iwa ((void (*)()) 0x803E641)
#define Q_HIKKURI_R_zako_iwa ((void (*)()) 0x803E655)
#define Q_H_RAKKA_L_zako_iwa ((int (*)()) 0x803E669)
#define Q_H_RAKKA_R_zako_iwa ((int (*)()) 0x803E685)
#define Q_K4_LEFT_zako_iwa ((int (*)()) 0x803E6A1)
#define Q_K4_RIGHT_zako_iwa ((int (*)()) 0x803E6C5)
#define Q_K5_HIP_zako_iwa ((void (*)()) 0x803E6E9)
#define Q_K3_LEFT_zako_iwa ((int (*)()) 0x803E70D)
#define Q_K3_RIGHT_zako_iwa ((int (*)()) 0x803E719)
#define Q_LF_MOVE_L_zako_iwa ((int (*)()) 0x803E725)
#define Q_LF_MOVE_R_zako_iwa ((int (*)()) 0x803E74D)

// common function
#define H_RAKKA_V_com ((void (*)()) 0x8023EE1) // drop
#define HIKKURI_L_com ((void (*)()) 0x8024479) // flip
#define HIKKURI_R_com ((void (*)()) 0x802449D)

#define Q_BOUND1_L_com ((int (*)()) 0x8024689)
#define BOUND1_L_com ((void (*)(int)) 0x80246B9)
#define Q_BOUND2_L_com ((int (*)()) 0x802473D)
#define BOUND2_L_com ((void (*)(int)) 0x802476D)
#define Q_BOUND3_L_com ((int (*)()) 0x80247F1)
#define BOUND3_L_com ((void (*)(int)) 0x8024821)
#define Q_BOUND1_R_com	((int (*)()) 0x80248A5)
#define BOUND1_R_com ((void (*)(int)) 0x80248D5)
#define Q_BOUND2_R_com ((int (*)()) 0x8024959)
#define BOUND2_R_com ((void (*)(int)) 0x8024989)
#define Q_BOUND3_R_com ((int (*)()) 0x8024A0D)
#define BOUND3_R_com ((void (*)(int)) 0x8024A3D)

#define Q_NH_RAKKA_L_com ((void (*)()) 0x8024AC1)
#define Q_NH_RAKKA_R_com ((void (*)()) 0x8024BED)
#define H_RAKKA_L_com ((void (*)()) 0x8024AD5)
#define H_RAKKA_R_com ((void (*)()) 0x8024C01)

#define K3_LEFT_com ((void (*)()) 0x8024D19)
#define K3_RIGHT_com ((void (*)()) 0x8024E59)
#define LF_MOVE_L_com ((void (*)()) 0x8024F99)
#define LF_MOVE_R_com ((void (*)()) 0x8025241)

#define NAGE_L_com ((void (*)()) 0x8025635) // throw
#define TNAGE_L_com ((void (*)()) 0x80256D5)
#define UNAGE_L_com ((void (*)()) 0x8025775)
#define UTNAGE_L_com ((void (*)()) 0x8025815)
#define NAGE_R_com ((void (*)()) 0x8025A01)
#define TNAGE_R_com ((void (*)()) 0x8025AA1)
#define UNAGE_R_com ((void (*)()) 0x8025B41)
#define UTNAGE_R_com ((void (*)()) 0x8025BE1)

#define Q_SOKUSI_com ((void (*)()) 0x8024555) // instant kill
#define TOptObjSet ((void (*)(unsigned short, unsigned short, char)) 0x80766E9)
#define m4aSongNumStart ((void (*)(int)) 0x8001DA5)
#define T_NoHoseiBgAtari ((void (*)(unsigned short, unsigned short)) 0x8023BFD)

void CustomRockAI()
{
    int v0;
    char v1;
    char *v2;
    int v3;
    char *v4;
    int v5;
    unsigned char v6;

    if ( Tbuf & 0x800 && iGmTimeFrame & 3 )
        return;
    v0 = *((unsigned char *)&Tbuf + 28);
    switch ( v0 )
    {
    case 0:
        Q_INITIAL_zako_iwa();
        goto LABEL_5;
    case 15:
    case 23:
    case 47:
    LABEL_5:
        Q_K0_WALK_zako_iwa();
        goto LABEL_6;
    case 16:
    LABEL_6:
        K0_WALK_zako_iwa();
        goto LABEL_70;
    case 27:
    case 29:
        Q_H_RAKKA_V_zako_iwa();
        goto LABEL_8;
    case 30:
    LABEL_8:
        Tbuf &= 0xF7FFu;
        H_RAKKA_V_com();
        goto LABEL_70;
    case 31:
    case 35:
    case 51:
    case 79:
    case 106:
        Q_K4_LEFT_zako_iwa();
        goto LABEL_25;
    case 33:
    case 37:
    case 53:
    case 80:
    case 105:
        Q_K4_RIGHT_zako_iwa();
        goto LABEL_19;
    case 43:
        Q_HIKKURI_L_zako_iwa();
        goto LABEL_10;
    case 44:
    LABEL_10:
        HIKKURI_L_com();
        goto LABEL_70;
    case 45:
        Q_HIKKURI_R_zako_iwa();
        goto LABEL_12;
    case 46:
    LABEL_12:
        HIKKURI_R_com();
        goto LABEL_70;
    case 49:
        Q_K5_HIP_zako_iwa();
        goto LABEL_70;
    case 52:
    case 64:
        goto LABEL_25;
    case 54:
    case 58:
        goto LABEL_19;
    case 55:
        v0 = Q_BOUND1_L_com();
        goto LABEL_17;
    case 56:
    LABEL_17:
        BOUND1_L_com(v0);
        goto LABEL_70;
    case 57:
        v0 = Q_BOUND2_L_com();
    LABEL_19:
        BOUND2_L_com(v0);
        goto LABEL_70;
    case 59:
        v0 = Q_BOUND3_L_com();
        goto LABEL_21;
    case 60:
    LABEL_21:
        BOUND3_L_com(v0);
        goto LABEL_70;
    case 61:
        v0 = Q_BOUND1_R_com();
        goto LABEL_23;
    case 62:
    LABEL_23:
        BOUND1_R_com(v0);
        goto LABEL_70;
    case 63:
        v0 = Q_BOUND2_R_com();
    LABEL_25:
        BOUND2_R_com(v0);
        goto LABEL_70;
    case 65:
        v0 = Q_BOUND3_R_com();
        goto LABEL_27;
    case 66:
    LABEL_27:
        BOUND3_R_com(v0);
        goto LABEL_70;
    case 67:
        Q_NH_RAKKA_L_com();
        goto LABEL_31;
    case 68:
    case 72:
        goto LABEL_31;
    case 69:
        Q_NH_RAKKA_R_com();
        goto LABEL_33;
    case 70:
    case 74:
        goto LABEL_33;
    case 71:
        Q_H_RAKKA_L_zako_iwa();
    LABEL_31:
        Tbuf &= 0xF7FFu;
        H_RAKKA_L_com();
        goto LABEL_70;
    case 73:
        Q_H_RAKKA_R_zako_iwa();
    LABEL_33:
        Tbuf &= 0xF7FFu;
        H_RAKKA_R_com();
        goto LABEL_70;
    case 81:
        Q_K3_LEFT_zako_iwa();
        goto LABEL_70;
    case 82:
        K3_LEFT_com();
        goto LABEL_70;
    case 83:
        Q_K3_RIGHT_zako_iwa();
        goto LABEL_70;
    case 84:
        K3_RIGHT_com();
        goto LABEL_70;
    case 85:
        Q_LF_MOVE_R_zako_iwa();
        goto LABEL_70;
    case 86:
        Tbuf &= 0xF7FFu;
        LF_MOVE_R_com();
        goto LABEL_70;
    case 87:
        Q_LF_MOVE_L_zako_iwa();
        goto LABEL_70;
    case 88:
        Tbuf &= 0xF7FFu;
        LF_MOVE_L_com();
        goto LABEL_70;
    case 89:
        *((unsigned char *)&Tbuf + 28) = 90;
        goto LABEL_43;
    case 90:
    LABEL_43:
        Tbuf &= 0xF7FFu;
        NAGE_L_com();
        goto LABEL_70;
    case 91:
        *((unsigned char *)&Tbuf + 28) = 92;
        goto LABEL_51;
    case 92:
    LABEL_51:
        Tbuf &= 0xF7FFu;
        NAGE_R_com();
        goto LABEL_70;
    case 93:
        *((unsigned char *)&Tbuf + 28) = 94;
        *((unsigned char *)&Tbuf + 29) = *((unsigned char *)&Tbuf + 29) & 0xF | 0x10;
        goto LABEL_45;
    case 94:
    LABEL_45:
        Tbuf &= 0xF7FFu;
        TNAGE_L_com();
        goto LABEL_70;
    case 95:
        *((unsigned char *)&Tbuf + 28) = 96;
        *((unsigned char *)&Tbuf + 29) = *((unsigned char *)&Tbuf + 29) & 0xF | 0x40;
        goto LABEL_53;
    case 96:
    LABEL_53:
        Tbuf &= 0xF7FFu;
        TNAGE_R_com();
        goto LABEL_70;
    case 97:
        *((unsigned char *)&Tbuf + 28) = 98;
        goto LABEL_47;
    case 98:
    LABEL_47:
        Tbuf &= 0xF7FFu;
        UNAGE_L_com();
        goto LABEL_70;
    case 99:
        *((unsigned char *)&Tbuf + 28) = 100;
        goto LABEL_55;
    case 100:
    LABEL_55:
        Tbuf &= 0xF7FFu;
        UNAGE_R_com();
        goto LABEL_70;
    case 101:
        *((unsigned char *)&Tbuf + 28) = 102;
        *((unsigned char *)&Tbuf + 29) = *((unsigned char *)&Tbuf + 29) & 0xF | 0x20;
        goto LABEL_49;
    case 102:
    LABEL_49:
        Tbuf &= 0xF7FFu;
        UTNAGE_L_com();
        goto LABEL_70;
    case 103:
        *((unsigned char *)&Tbuf + 28) = 104;
        *((unsigned char *)&Tbuf + 29) = *((unsigned char *)&Tbuf + 29) & 0xF | 0x80;
        goto LABEL_57;
    case 104:
    LABEL_57:
        Tbuf &= 0xF7FFu;
        UTNAGE_R_com();
        goto LABEL_70;
    case 107:
        v1 = *((unsigned char *)&Tbuf + 29);
        if ( *((unsigned char *)&Tbuf + 29) & 0x10 )
        {
            *((unsigned char *)&Tbuf + 29) = v1 & 0xF;
            v2 = (char *)&Tbuf + 41;
            v3 = 8;
    LABEL_67:
            *v2 = v3;
            Q_NH_RAKKA_R_com();
            goto LABEL_70;
        }
        if ( *((unsigned char *)&Tbuf + 29) & 0x20 )
        {
            *((unsigned char *)&Tbuf + 29) = v1 & 0xF;
            v4 = (char *)&Tbuf + 41;
            v5 = 4;
    LABEL_64:
            *v4 = v5;
            Q_NH_RAKKA_L_com();
            goto LABEL_70;
        }
        if ( *((unsigned char *)&Tbuf + 29) & 0x40 )
        {
            *((unsigned char *)&Tbuf + 29) = v1 & 0xF;
            v4 = (char *)&Tbuf + 41;
            v5 = 8;
            goto LABEL_64;
        }
        if ( *((unsigned char *)&Tbuf + 29) & 0x80 )
        {
            *((unsigned char *)&Tbuf + 29) = v1 & 0xF;
            v2 = (char *)&Tbuf + 41;
            v3 = 4;
            goto LABEL_67;
        }
        Q_SOKUSI_com();
    LABEL_70:
        v6 = *((unsigned char *)&Tbuf + 29);
        if ( (v6 & 0xF) == 1 )
        {
            if ( Tbuf & 0x800 )
            {
                *((unsigned char *)&Tbuf + 29) = v6 + 1;
                TOptObjSet(*((unsigned short *)&Tbuf + 4), *((unsigned short *)&Tbuf + 5), 7);
                m4aSongNumStart(61);
            }
        }
        else if ( (v6 & 0xF) == 2 )
        {
            T_NoHoseiBgAtari(*((unsigned short *)&Tbuf + 4), *((unsigned short *)&Tbuf + 5));
            if ( Terrain_usKoka_SolidOrWater == 1 )
                Tbuf |= 0x800u;
            if ( !(Tbuf & 0x800) )
                --*((unsigned char *)&Tbuf + 29);
        }
        return;
    default:
        Q_SOKUSI_com();
        goto LABEL_70;
    }
}
