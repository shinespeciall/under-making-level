Pizza Tower Lap Room patch bundle v1.1

features:
1. By pressing frog switch, all the enemies on the frog switch Room will insta respawn. (it looks ugly, you can disable this feature by not applying this file: `Sub_802B694_Q_K0_TURN1_j_switch.c`)
2. Use an event Tile16 in the LAP Room to trigger the enemies respawn in all the other Rooms again.
3. only the diamonds in the respawn Room will re-appear, the other diamonds won't re-appear after using the LAP Room.

NOTICE:
You need to manually edit these define lines in the files to make the feature work and also take care not to cause conflict if some other patch bundles use patches hook on the same function, or have the same number on the user defined Tile16 event id, or have user defined global variables on the same ram address:
```
#define RespawnEnemiesEventID 0xA1
#define LAPROOMID 1 // we only revive diamonds in this Room
// unsigned char EnemiesHaveBeenRevivedRoomList[0x10], custom variables
#define EnemiesHaveBeenRevivedRoomList ((volatile unsigned char*) 0x3006280)
```

The Sub_806FD74_WarioBgAttackCheck_Center.c file is directly modified on the one in Asyn_L0L2_bundle_20220906 bundle. just ignore those layer asyn logic above and leave them there forever...