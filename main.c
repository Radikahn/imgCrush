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

int main() {

  const char *file_name = "image.jpg";
  const char *output_name = "black_and_white.jpg";
  int image_x;
  int image_y;
  int channels_in_file;

  stbi_uc *image_file =
      stbi_load(file_name, &image_x, &image_y, &channels_in_file, STBI_rgb);

  int write_png =
      stbi_write_jpg(output_name, image_x, image_y, 3, image_file, 100);

  printf("image x: %d image y: %d\n", image_x, image_y);
  printf("image channels: %d\n", channels_in_file);

  return 0;
}
