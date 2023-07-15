'''
Reduce Tile for pic for GBA romhack

P.S.
i cannot make the PIL.Image.quantize() work,
so you need to quantize the palette manually using Usenti.

changelog:
created by ssp (shinespeciall) at 2023/4/1

i asked AI in you.com (based on GPT-4) about "how to make the compare logic faster using pytorch",
it gave me the follow idea, the logic looks correct, i just fit the new logic into the file.
then i found those noice pixel cannot be dealt in this way,
so i found some color reduce method online to try make the whole thing work.
by adjusting "tolerantTileDiff" value, the new method does work, lol.
changes made by ssp (shinespeciall) at 2023/7/15
'''

from PIL import Image, ImageDraw
import torch
import cv2
from torch.nn.functional import unfold
import torchvision.transforms as transforms
import numpy as np

def kmeans_color_quantization(image, clusters=8, rounds=1):
    h, w = image.shape[:2]
    samples = np.zeros([h*w,3], dtype=np.float32)
    count = 0

    for x in range(h):
        for y in range(w):
            samples[count] = image[x][y]
            count += 1

    compactness, labels, centers = cv2.kmeans(samples,
            clusters, 
            None,
            (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 10000, 0.0001), 
            rounds, 
            cv2.KMEANS_RANDOM_CENTERS)

    centers = np.uint8(centers)
    res = centers[labels.flatten()]
    return res.reshape((image.shape))

pic_src_path = "E:\\Github Repo\\under-making-level\\tools\\python_scripts\\test\\test_pic_2.png"
# the Tile's pixel number on width and height
tilesize = 16

# the tolerant difference between pixels when compare Tiles, better below 30
tolerantTileDiff = 1.15

init_img = Image.open(pic_src_path)
width, height = init_img.size

# Read the image
image = cv2.imread(pic_src_path)
result = kmeans_color_quantization(image, clusters = 16)
  
# Convert BGR image to RGB image
image = cv2.cvtColor(result, cv2.COLOR_BGR2RGB)

# manage mask
x_tile_count = width // tilesize
y_tile_count = height // tilesize
img = Image.new("RGB", (width, height))
img.paste(init_img, (0, 0))
mask = Image.new("RGB", (width, height), "black")
draw = ImageDraw.Draw(mask)

# we don't use the init_img, we paste duplicatable tiles onto img then process it
# img.paste(init_img, (0, 0))

# Define a transform to convert PIL 
# image to a Torch tensor
transform = transforms.Compose([
    transforms.ToTensor()
])
  
# transform = transforms.PILToTensor()
# Convert the PIL image to Torch tensor
img_tensor = transform(image)

tiles_cache_src = []

for y in range(y_tile_count):
    for x in range(x_tile_count):
        tiles_cache_src.append(img.crop((x * tilesize, y * tilesize, (x + 1) * tilesize, (y + 1) * tilesize)))

patch_size = (width // tilesize, height // tilesize)  # The size of the patches to extract
stride = (width // tilesize, height // tilesize)  # The stride between adjacent patches

patches = unfold(img_tensor.unsqueeze(0), kernel_size=patch_size, stride=stride)
num_patches = patches.size(1)

# Flatten the patches tensor along the spatial dimensions
patches = patches.view(1, num_patches, -1)

# Compute all pairwise differences between patches
diffs = patches - patches.transpose(1, 0)

# Compute the L2 norm (Euclidean distance) for each pairwise difference
l2_norms = diffs.norm(dim=2)

# `l2_norms[i, j]` now contains the L2 norm between the i-th and j-th patches

num_of_tiles = y_tile_count * x_tile_count

for t1 in range(num_of_tiles):
    x1 = t1 % x_tile_count
    y1 = t1 // x_tile_count
    for t2 in range(t1 + 1, num_of_tiles):
        x2 = t2 % x_tile_count
        y2 = t2 // x_tile_count

        value = l2_norms[t1, t2] + l2_norms[t1 + num_of_tiles, t2 + num_of_tiles] + l2_norms[t1 + 2 * num_of_tiles, t2 + 2 * num_of_tiles]
        if (value < tolerantTileDiff):
            img.paste(tiles_cache_src[t1], (x2 * tilesize, y2 * tilesize))

            draw.rectangle((x2 * tilesize,
                            y2 * tilesize,
                            (x2 + 1) * tilesize,
                            (y2 + 1) * tilesize),
                            fill="white")

# save
img.save("E:\\Github Repo\\under-making-level\\tools\\python_scripts\\test\\test_pic_result.png")
mask.save("E:\\Github Repo\\under-making-level\\tools\\python_scripts\\test\\test_pic_result_mask.png")