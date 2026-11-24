#include <stdint.h>
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

//  JPEG files are made up of markers (segments starting with 0xFF followed
//  by a marker byte). For example, 0xFFD8 is Start of Image, 0xFFC0
//  contains dimensions/color info, 0xFFDA is the start of the compressed
//  image data.
//  source:
//  https://en.wikipedia.org/wiki/JPEG#Syntax_and_structure

int main() {
    const char *file_name = "image.jpg";
    const char *output_name = "output.png";
    int image_x;
    int image_y;
    int image_w = 640;
    int image_h = 485;
    int channels_in_file;

    stbi_uc *image_file = stbi_load(file_name, &image_x, &image_y, &channels_in_file, STBI_rgb);

    if (image_x == image_w && image_y == image_h) {
        int write_png = stbi_write_png(output_name, image_w, image_h, 4, image_file, image_w * sizeof(uint32_t));
    }
    else {
        printf("fucking shit dude");
    }

    stbi_image_free(image_file);


//     int write_png =
//         stbi_write_jpg(output_name, image_x, image_y, 2, image_file, 100);
//
//     printf("image x: %d image y: %d\n", image_x, image_y);
//     printf("image channels: %d\n", channels_in_file);
//
    return 0;
}
