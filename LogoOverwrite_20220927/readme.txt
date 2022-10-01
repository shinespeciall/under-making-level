according to the reverse engineering record. the logo can use 512 tiles at most, and using UnpackScreen() to transfer text mapping data into a whole layer. the text mode data can use palette 6, 7 and 8. that's all the things you need, then you can make your custom logo layer with usenti and the 3 patches i made.

in the 3 patches, one is for tile data transfer, the other 2 is for mapping data transfer. since the mapping data transfer logic appear in 2 places in the whole ROM, so i have to make 2 patches for them. 

the usenti export option pic file can be found in the same folder. make sure your pic's width and height are 32 by 16. i mean, it can be 32 by 32 at most but since usenti has a lot of bugs in the export feature when doing tile reduce and it seems we cannot find its source code to fix the bug then rebuild it? so we just use 512 tiles, so the width and height are 32 by 16.

the export c file still has something wrong in the mapping data, you need to manually fix it. see the other png file in the folder.
