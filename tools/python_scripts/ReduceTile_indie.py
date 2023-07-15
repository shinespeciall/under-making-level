'''
Reduce Tile for pic for GBA romhack

P.S.
i cannot make the PIL.Image.quantize() work,
so you need to quantize the palette manually using Usenti.

changelog:
created by ssp (shinespeciall) at 2023/4/1
'''

from PIL import Image, ImageDraw

# the Tile's pixel number on width and height
tilesize = 16

# the tolerant difference between pixels when compare Tiles, better below 30
tolerantTileDiff = 20

# a number of noise pixels is allowed, but we need a threshold for it, better below 20
diffPixelCount = 10

init_img = Image.open("E:\\Github Repo\\under-making-level\\tools\\python_scripts\\test\\test_pic_2.png")
width, height = init_img.size

# manage mask
x_tile_count = width // tilesize
y_tile_count = height // tilesize
img = Image.new("RGB", (width, height))
img.paste(init_img, (0, 0))
mask = Image.new("RGB", (width, height), "black")
draw = ImageDraw.Draw(mask)

# we don't use the init_img, we paste duplicatable tiles onto img then process it
# img.paste(init_img, (0, 0))

if (diffPixelCount > (tilesize * tilesize)):
    diffPixelCount = tilesize * tilesize

tiles_cache_src = []
tiles_cache = [] # an array of tile
# if the key eqauls to the value, then we don't touch the tile
# if the key is different from the value, then we modify the tile according to the value
paste_record_array = []

for y in range(y_tile_count):
    for x in range(x_tile_count):
        tiles_cache_src.append(img.crop((x * tilesize, y * tilesize, (x + 1) * tilesize, (y + 1) * tilesize)))
        tiles_cache.append(tiles_cache_src[-1].load())
        paste_record_array.append(y * x_tile_count + x)

        # crop test
        # tiles_cache[y * x_tile_count + x].save("C:\\Users\\shinespeciall\\Desktop\\training_data\\python\\crop\\result_" + str(y * x_tile_count + x) + ".png")

# Tile_1 loop
for t1 in range(y_tile_count * x_tile_count):
    x1 = t1 % x_tile_count
    y1 = t1 // x_tile_count

    # test stuff to make sure the pre-process is going on correctly
    print(x1, y1)

    # Tile_2 loop
    for t2 in range(t1 + 1, y_tile_count * x_tile_count):
        x2 = t2 % x_tile_count
        y2 = t2 // x_tile_count

        diff_pixel_count = 0
        for j in range(tilesize):
            for i in range(tilesize):
                r1, g1, b1 = tiles_cache[y1 * x_tile_count + x1][i, j]
                r2, g2, b2 = tiles_cache[y2 * x_tile_count + x2][i, j]
                delta_r = abs(r1 - r2)
                delta_g = abs(g1 - g2)
                delta_b = abs(b1 - b2)

                if ((delta_r + delta_g + delta_b) > tolerantTileDiff):
                    diff_pixel_count += 1
        
        # count how many pixels are quasi-different
        # if the Tile_2 looks close enough to the Tile_1
        # then we let Tile_1 overwrite Tile_2
        if (diff_pixel_count < diffPixelCount):
            paste_record_array[t2] = paste_record_array[t1]

#test
print(paste_record_array)

# prepare mask and operate img
count_paste_record_array = []
for t1 in range(y_tile_count * x_tile_count):
    count_paste_record_array.append(0)
for t1 in range(y_tile_count * x_tile_count):
    id = paste_record_array[t1]
    count_paste_record_array[id] = count_paste_record_array[id] + 1

#test
print(count_paste_record_array)

for t1 in range(y_tile_count * x_tile_count):
    x1 = t1 % x_tile_count
    y1 = t1 // x_tile_count
    if (paste_record_array[t1] != t1):
        # use the same graphic a tile be used multiple times
        id = paste_record_array[t1]
        img.paste(tiles_cache_src[id], (x1 * tilesize, y1 * tilesize))
    
        # show the parts which use other tiles' graphic
        if (count_paste_record_array[t1] != 1):
            draw.rectangle((x1 * tilesize,
                            y1 * tilesize,
                            (x1 + 1) * tilesize,
                            (y1 + 1) * tilesize), 
                            fill="white")

# save
img.save("E:\\Github Repo\\under-making-level\\tools\\python_scripts\\test\\test_pic_result.png")
mask.save("E:\\Github Repo\\under-making-level\\tools\\python_scripts\\test\\test_pic_result_mask.png")