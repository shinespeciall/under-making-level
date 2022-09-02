// @Description Rewrite Sub_806DAC0_PanelYakuAllNum_TileEventWork by ssp
// @HookAddress 0x6daca
// @HookString 024a 9646024a 10470000 37dd0608 P

/* Patch & Hook details
 
 .thumb
    .dcb 1
    ldr r2, .DATA
    mov lr, r2
    ldr r2, .DATA + 4
    bx r2
    .dcb 1
  .DATA:
    .word 0x0806DD37
    .word 0xAAAAAAAA
 */

/**
 * changelog:
 * directly modified from the IDA pro's generated C code
 * and made some adjustment to make the code more readable.
 *            ---- by ssp (shinespeciall), 2021/11/17
 * add logic to asynchronize Layer 0 and Layer 3.
 *            ---- by ssp (shinespeciall), 2022/09/01
 */

#define CurrentTileset_EventIdTablePointer (*(volatile unsigned short**) 0x30031FC)
// #define CurrentRoomHeader_TilesetId (*(volatile unsigned char*) 0x3000074)

#define CurrentRoomHeader_Layer0MappingType (*(volatile unsigned char*) 0x3000075)
// #define CurrentRoomHeader_Layer1MappingType (*(volatile unsigned char*) 0x3000076)
#define CurrentRoomHeader_Layer2MappingType (*(volatile unsigned char*) 0x3000077)
// #define CurrentRoomHeader_Layer3MappingType (*(volatile unsigned char*) 0x3000078)

#define CurrentRoomHeader_LayerPriorityALphaParam (*(volatile unsigned char*) 0x300008e)

#define Layer0_DecompressedDataPointer (*(volatile unsigned short**) 0x3000054)
#define Layer0_Width (*(volatile unsigned short*) 0x3000058)
#define Layer0_Height (*(volatile unsigned short*) 0x300005a)

#define Layer1_DecompressedDataPointer (*(volatile unsigned short**) 0x300005c)
#define Layer1_Width (*(volatile unsigned short*) 0x3000060)
#define Layer1_Height (*(volatile unsigned short*) 0x3000062)

#define Layer2_DecompressedDataPointer (*(volatile unsigned short**) 0x3000064)
#define Layer2_Width (*(volatile unsigned short*) 0x3000068)
#define Layer2_Height (*(volatile unsigned short*) 0x300006a)

// 5 map switches in total: 0:unknown 1:switch block flag 2:switch block flag 3:unknown 4:frog blocks flag
#define  MapSw ((volatile unsigned char*) 0x300002E)
#define  MAPSW_OFF  0x00 //MAPSW[*] state: off
#define  MAPSW_ON  0x01 //MAPSW[*] state: on
#define  MAPSW_SET_ON 0x02 //MAPSW[*] turn on
#define  MAPSW_SET_OFF 0x03 //MAPSW[*] turn off
#define  MAPSW_SET_HIT 0x02 //MAPSW[*] XOR

#define Terrain_usField (*(volatile unsigned short*) 0x30000a0)
enum usField_enum{
    YF_Nothing,   //00:nothing in layer 1 and 2
    YF_Door,  //01:door
    YF_Ladder_M, //02:ladder
    YF_Ladder_U, //03:top of ladder
    YF_climbable_net, //04:climbable net
    YF_BELT_L,  //05:belt to left, only works on layer 1
    YF_BELT_R,  //06:belt to right
    YF_TUBE_UL,  //07:left part of go-up pipe
    YF_TUBE_UR,  //08:right part of go-up pipe
    YF_TUBE_DL,  //09:left part of go-down pipe
    YF_TUBE_DR,  //0A:right part of go-down pipe
    YF_SLIP,  //0B:slippery platforms
    YF_Water_SR,  //0C:slow current rightwards
    YF_Water_SL,  //0D:slow current leftwards
    YF_Water_SU,  //0E:slow current upwards
    YF_Water_SD,  //0F:slow current downwards
    YF_Water_FR,  //00:fact current rightwards
    YF_Water_FL,  //11:fast current leftwards
    YF_Water_FU,  //12:fast current upwards
    YF_Water_FD,  //13:fast current downwards
};
// 030000a2 : u16 Pyaku[1] - usKoka - 01(in water) 00(else) (from WL4 RAM record)
#define Terrain_usKoka_SolidOrWater (*(volatile unsigned short*) 0x30000a2)
enum uskoka_enum
{
    YK_Nothing,
    YK_Water,
};

#define usBg0Hofs (*(volatile unsigned short*) 0x3001876)
#define usBg0Vofs (*(volatile unsigned short*) 0x3001878)
#define usBg1Hofs_CameraXPos (*(volatile unsigned short*) 0x300187A)
#define usBg1Vofs_CameraYPos (*(volatile unsigned short*) 0x300187C)
#define usBg2Hofs (*(volatile unsigned short*) 0x300187E)
#define usBg2Vofs (*(volatile unsigned short*) 0x3001880)
#define usBg3Hofs (*(volatile unsigned short*) 0x3001882)
#define usBg3Vofs (*(volatile unsigned short*) 0x3001884)

/**
 * the vanilla function is used to get the Terrain_usField and Terrain_usKoka according to your offset
 * so i suggest you to only let it sets and returns new Terrain_usField and Terrain_usKoka flags
 * and patch (or let) the caller to do the work to modify Wario, enemies, map stuff.
 * to keep this function clean and readable.
 */
int Rewrite_Sub_806DAC0_PanelYakuAllNum_by_ssp(unsigned short Y_value, unsigned short X_value)
{
    int Cur_eventId_offset;
    int solidOrwater_tmp;
    unsigned short usField_tmp;
    int Layer0CurrentEventId;
    int Layer1CurrentEventId;
    int Layer2CurrentEventId;
    int Y_value_R6;
    int X_value_R6;

    // the switches are in ram [0x30002e, 0x3000032]
    // the event id of those tiles relative to switches are [0x38, 0x43] U [0x48, 0x4f]
    // the compiler did some optimization and calculate out the addresses of switches directly in the code using these 2 values
    unsigned char *p_2FFFFF3 = 0x2FFFFF3;
    unsigned char *p_2FFFFF7 = 0x2FFFFF7;

    // deal with event id on layer 1, 2
    Y_value_R6 = (Y_value << 16) >> 22;                                     // Y
    X_value_R6 = (X_value << 16) >> 22;                                     // X
    Terrain_usField = 0;
    Terrain_usKoka_SolidOrWater = YK_Nothing;
    if ( Y_value_R6 >= Layer1_Height || X_value_R6 >= Layer1_Width )
        return 0;
    Layer1CurrentEventId = CurrentTileset_EventIdTablePointer[ \
              Layer1_DecompressedDataPointer[Y_value_R6 * Layer1_Width + X_value_R6]];
    
    int delta_L1_to_L2_X = (int)usBg2Hofs - (int)usBg1Hofs_CameraXPos;
    int delta_L1_to_L2_Y = (int)usBg2Vofs - (int)usBg1Vofs_CameraYPos;
    int X_value_R6_L2 = ((X_value + delta_L1_to_L2_X) << 16) >> 22;
    int Y_value_R6_L2 = ((Y_value + delta_L1_to_L2_Y) << 16) >> 22;

    Layer2CurrentEventId = CurrentTileset_EventIdTablePointer[ \
              Layer2_DecompressedDataPointer[Y_value_R6_L2 * Layer2_Width + X_value_R6_L2]];
    usField_tmp = 0;
    switch ( Layer1CurrentEventId )
      {
        case 106: // belt left
          usField_tmp = 5;
          goto ProcessLayer0EventId;
        case 107: // belt right
          usField_tmp = 6;
          goto ProcessLayer0EventId;
        case 104:// 0x68 Slippery ice platforms
          goto set_usField_11;
        case 4:// left part of downpipe
          usField_tmp = 7;
          goto ProcessLayer0EventId;
        case 5:// right part of downpipe
          usField_tmp = 8;
          goto ProcessLayer0EventId;
        case 6:// left part of upperpipe
          usField_tmp = 9;
          goto ProcessLayer0EventId;
        case 7:// right part of upperpipe
          usField_tmp = 10;
          goto ProcessLayer0EventId;
        case 121:// ladders
set_usField_2:
          usField_tmp = 2;
          goto ProcessLayer0EventId;
        case 123:
set_usField_4:
          usField_tmp = 4;// climbable net
          goto ProcessLayer0EventId;
        case 2:
          goto set_usField_1;
        case 122:// top of ladders (can walk on)
          goto set_usField_3;
    }
    Cur_eventId_offset = Layer1CurrentEventId - 0x59;
    if ( Cur_eventId_offset <= 4 && Cur_eventId_offset >= 0)// EventID 0x59-5D, breakable slippery blocks
        usField_tmp = 11;// slippery ice effect
    if ( usField_tmp || CurrentRoomHeader_Layer2MappingType != 16 )
        goto ProcessLayer0EventId;
    switch ( Layer2CurrentEventId )
    {
        case 2:
set_usField_1:
            usField_tmp = 1;
            goto ProcessLayer0EventId;
        case 121:
            goto set_usField_2;
        case 123:
            goto set_usField_4;
        case 104:
set_usField_11:
            usField_tmp = 11; // slippery ice effect
            goto ProcessLayer0EventId;
        case 122:
set_usField_3:
            usField_tmp = 3;
            goto ProcessLayer0EventId;
    }
    // Only do things relative to switches
    Cur_eventId_offset = Layer2CurrentEventId - 0x38;
    if ( (Cur_eventId_offset > 7) || (Cur_eventId_offset < 0)) // ID > 0x3f or ID < 0x38
    {
        Cur_eventId_offset = Layer2CurrentEventId - 0x98;
        if ( Cur_eventId_offset <= 3 && Cur_eventId_offset >= 0) // EventID from 0x98 to 0x9b
        {
            if (MapSw[1] & MAPSW_ON)
            {
                if ( Cur_eventId_offset > 1 )
                    usField_tmp = ((Layer2CurrentEventId + 0x68) & 1) + 2;
            }
            else if ( Cur_eventId_offset <= 1 )
            {
                usField_tmp = Layer2CurrentEventId - 0x96;
            }
        }
        goto ProcessLayer0EventId; // 0x3f < ID < 0x98 or ID < 0x38 or ID > 0x9B
    }
    if ( ((Layer2CurrentEventId - 0x37) > 3)) // if ID > 0x3a
    {
        if ( (*(Layer2CurrentEventId + p_2FFFFF3) - 1) > 1u ) // get the state of the switches
            goto ProcessLayer0EventId;
        goto set_usField_1; // switch door things
    }
    if ( !*(Layer2CurrentEventId + p_2FFFFF7) || *(Layer2CurrentEventId + p_2FFFFF7) == 3 ) // get the state of the switches
        goto set_usField_1; // switch door things

    // deal with event ids on water current things
ProcessLayer0EventId:
    Terrain_usField = usField_tmp;
    solidOrwater_tmp = 0;
    usField_tmp = 0;
    if ( CurrentRoomHeader_LayerPriorityALphaParam > 7u && CurrentRoomHeader_Layer0MappingType <= 0x10u )
    {
        if ( CurrentRoomHeader_Layer0MappingType )
        {
            if ( Y_value_R6 >= Layer0_Height || X_value_R6 >= Layer0_Width )
            {
                return Terrain_usField << 16;
            }

            int delta_L1_to_L0_X = (int)usBg0Hofs - (int)usBg1Hofs_CameraXPos;
            int delta_L1_to_L0_Y = (int)usBg0Vofs - (int)usBg1Vofs_CameraYPos;
            int X_value_R6_L0 = ((X_value + delta_L1_to_L0_X) << 16) >> 22;
            int Y_value_R6_L0 = ((Y_value + delta_L1_to_L0_Y) << 16) >> 22;
            Layer0CurrentEventId = CurrentTileset_EventIdTablePointer[ \
                  Layer0_DecompressedDataPointer[(Y_value_R6 + Y_value_R6_L0) * Layer0_Width + (X_value_R6 + X_value_R6_L0)]];
            // if tile in layer 0 is water or currents
            if ( (Layer0CurrentEventId - 0x4C) <= 0xC && (Layer0CurrentEventId - 0x4C) >= 0)
            {
                solidOrwater_tmp = 1;
                switch ( Layer0CurrentEventId ) // cases for Layer 0 water current tiles
                {
                    case 81:
                        usField_tmp = 12;
                        break;
                    case 82:
                        usField_tmp = 13;
                        break;
                    case 83:
                        usField_tmp = 14;
                        break;
                    case 84:
                        usField_tmp = 15;
                        break;
                    case 85:
                        usField_tmp = 16;
                        break;
                    case 86:
                        usField_tmp = 17;
                        break;
                    case 87:
                        usField_tmp = 18;
                        break;
                    case 88:
                        usField_tmp = 19;
                        break;
                }
                if (!(MapSw[4] & MAPSW_ON))// if frog switch isn't pressed yet
                {
                    switch ( Layer0CurrentEventId )
                    {
                      case 76:
                          usField_tmp = 12;
                          break;
                      case 77:
                          usField_tmp = 17;
                          break;
                      case 78:
                          usField_tmp = 18;
                          break;
                      case 79:
                          usField_tmp = 19;
                          break;
                    }
                }
            }
        }
    }
    // water current tiles work on layer 1
    else if ( (Layer1CurrentEventId - 0x4C) <= 0xC && (Layer1CurrentEventId - 0x4C) >= 0)
    {
        solidOrwater_tmp = YK_Water;
    }
    // when water current and normal water tiles appear in one place, make the current work
    // P.S. this will perhaps cause weird behaviors underwater
    if ( solidOrwater_tmp == YK_Water && (usField_tmp || Terrain_usField != 1) )
        Terrain_usField = usField_tmp;
    Terrain_usKoka_SolidOrWater = solidOrwater_tmp;
    return (Terrain_usField << 16) | solidOrwater_tmp;
}
