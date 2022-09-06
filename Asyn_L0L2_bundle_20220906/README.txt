Asyn L0L2 bundle can make your Rooms Layer 0 and Layer 2 asyn with Layer 1.

it uses the unchanged Layer 1 as the coordinates and move Layer 0 and Layer 2 using those layer offset variables.
in vanilla game engine, you can move layers around but wario and enemy mechanism does not work with asyn Layer 0 and Layer 2, so all the patches in this bundle solve this problem. by applying all the c file patches into your romhack, you can make terrains and events from Tile16 on Layer 0 and Layer 2 works with wario and enemy.

when you move layer 0 or layer 2 around, the vanilla game engine won't update the vram correctly, it will just update tiles on the edges of the screen dynamically. So one of the solutions is calling Sub_806BB4C_GmapBgVramInitSet(unsigned char layerId) every time after you reset a layer's s or y offset.

i make a small example in Sub_806E7F8_GmScrSet.c patch since you always need to disable the Layer 0 and Layer 2 auto-sync with Layer 1 in that function if you want everything in this bundle works. That's not the only place you can move layer 0 or layer 2. it depends on how you want to design your hacks.
