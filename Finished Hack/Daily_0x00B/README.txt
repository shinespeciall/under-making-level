Credit of the hack: Daily 0x00B
level designer:
ssp

description: you will learn more about damage boost. A new level used to test the new WL4Editor graphic manager features. with attempt on using customized enemy oam data structures in the patches, and generating background and bgm using AI models. I learned a lot of things when making this hack.
you need to know how to perform a midair enemy jump to play this level. potential softlock on the first Room first puzzle, you can just reboot the game when softlock happens. i don't want to fix it atm.

patches:
vertical room warp feature, by me, inspired from a hack by beco
disable auto demo playing, by beco
disable wario life decrease, by ssp
fix wario stuck in some animation in the air, by ssp
two new Enemy AI functions for throw ball stuff by ssp
revive enemy when refresh room, by ssp
run credit after save level, by ssp
disable difficulty selecting, by ssp

tools:
arm none eabi gcc (build patches, called by WL4Editor automatically)
gba mus ripper v24 (ripping soundfonts for reference)
mid2agb (convert mid file to s file)
musescore 3 (midi editor)
sappy (compile s file of some midi and insert the data into the ROM)
usenti (tile editor, and tile data exporter)
WL4Editor

script to help with level design used in WL4Editor:
BonusRoomify by Spleen

AI generation stuff (everything runs on Google collab):
Pixel Art Diffusion to generate background pic:
https://github.com/KaliYuga-ai/Pixel-Art-Diffusion/blob/main/Pixel_Art_Diffusion_v2_01.ipynb
music composer to generate bgm tracks:
https://github.com/ai-forever/music-composer/blob/main/src/Music_Composer_Demo_Colab_en.ipynb
