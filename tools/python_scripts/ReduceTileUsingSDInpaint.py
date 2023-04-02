'''
Reduce Tile using inpaint feature of Stable Diffusion

modified from horizontal_scroll.py written by xanthius from itch.io
source: https://xanthius.itch.io/horizontal-tiling-script-for-stablediffusion
also the reddit post ref by Sixhaunt
source: https://www.reddit.com/r/gamedev/comments/ynjyis/i_made_a_free_script_for_stablediffusion_to_make/

changelog:
created by ssp (shinespeciall) at 2023/4/1
'''

import math
import os

import modules.scripts as scripts
import gradio as gr
from PIL import Image, ImageDraw

from modules import images, processing, devices
from modules.processing import Processed, process_images
from modules.shared import opts, cmd_opts, state

class Script(scripts.Script):

    # Override from modules.scripts.Script
    def title(self):
        return "Reduce Tile8x8 inpaint"

    # Override from modules.scripts.Script
    def show(self, is_img2img):
        return is_img2img

    # Override from modules.scripts.Script
    def ui(self, is_img2img):
        if not is_img2img:
            return None

        mask_blur = gr.Slider(label='Mask blur amount', minimum=0, maximum=64, step=1, value=8)
        denoising_strength = gr.Slider(label='Denoising strength (Overrides default)', minimum=0.0, maximum=1.0, step=0.01, value=1.0)
        inpainting_fill = gr.Radio(label='Masked content', choices=['fill', 'original', 'latent noise', 'latent nothing'], value='fill', type="index")
        tilesize = gr.Slider(label="the pixel number on one axis in one Tile", minimum=16, maximum=128, step=16, value=16)
        tolerantTileDiff = gr.Slider(label="the tolerant difference between pixels when compare Tiles", minimum=0, maximum=255*3, step=1, value=50)
        diffPixelCount = gr.Slider(label="the pixel number threshold to judge tile difference", minimum=0, maximum=128 ** 2, step=1, value=20)

        return [mask_blur, denoising_strength, inpainting_fill, tilesize, tolerantTileDiff, diffPixelCount]

    # Override from modules.scripts.Script
    def run(self, p, mask_blur, denoising_strength, inpainting_fill, tilesize, tolerantTileDiff, diffPixelCount):
        # p.mask_blur = mask_blur * 2
        # p.inpainting_fill = inpainting_fill
        # p.inpaint_full_res = False
        # p.denoising_strength = denoising_strength

        # use the width and height value from the init_img
        init_img = p.init_images[0]
        p.width = init_img.width
        p.height = init_img.height
        self.img_width = init_img.width
        self.img_height = init_img.height

        # manage mask
        x_tile_count = self.img_width // tilesize
        y_tile_count = self.img_height // tilesize
        img = Image.new("RGB", (p.width, p.height))
        img.paste(init_img, (0, 0))
        mask = Image.new("RGB", (p.width, p.height), "black")
        draw = ImageDraw.Draw(mask)
        latent_mask = Image.new("RGB", (p.width, p.height), "black")
        latent_draw = ImageDraw.Draw(latent_mask)

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

        # Tile_1 loop
        for t1 in range(y_tile_count * x_tile_count):
            x1 = t1 % x_tile_count
            y1 = t1 // x_tile_count

            # test stuff to make sure the pre-process is going on correctly
            print("find similar tiles for the tile at: " + str(x1) + ", " + str(y1))

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
        
        # prepare mask and operate img
        count_paste_record_array = []
        for t1 in range(y_tile_count * x_tile_count):
            count_paste_record_array.append(0)
        for t1 in range(y_tile_count * x_tile_count):
            id = paste_record_array[t1]
            count_paste_record_array[id] = count_paste_record_array[id] + 1

        for t1 in range(y_tile_count * x_tile_count):
            x1 = t1 % x_tile_count
            y1 = t1 // x_tile_count
            if (paste_record_array[t1] != t1):
                # use the same graphic a tile be used multiple times
                id = paste_record_array[t1]
                img.paste(tiles_cache_src[id], (x1 * tilesize, y1 * tilesize))
            
            # mask out the non-duplicated tile parts to let stable diffusion redraw them
            if (count_paste_record_array[t1] == 1):
                draw.rectangle((x1 * tilesize,
                                    y1 * tilesize,
                                    (x1 + 1) * tilesize,
                                    (y1 + 1) * tilesize), 
                                    fill="white")
                latent_draw.rectangle((x1 * tilesize,
                                        y1 * tilesize,
                                        (x1 + 1) * tilesize,
                                        (y1 + 1) * tilesize), 
                                        fill="white")

        # devices.torch_gc()

        p.n_iter = 1
        p.batch_size = 1
        p.do_not_save_grid = True
        p.do_not_save_samples = True

        p.init_images = [img]
        p.image_mask = mask
        p.latent_mask = latent_mask

        img.save(os.getcwd() + "\\test\\img.png")
        mask.save(os.getcwd() + "\\test\\mask.png")

        work_results = []

        processed = process_images(p)

        '''
        the things below i copied from other's script cannot work
        '''
        # p.seed = processed.seed
        # uc = img.copy()
        # uc.paste(processed.images[0], (0, 0))
        # work_results.append(uc)
        
        # processed = Processed(p, work_results, p.seed, processed.info)

        return processed
