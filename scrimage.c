#define HEIGHT 1080
#define WIDTH 1920
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void fill(uint32_t *pixels, size_t height, size_t width, uint32_t color)
{
		for (int i = 0; (unsigned) i < height*width; i++)
				pixels[i] = color;
}
int save(uint32_t *pixels, size_t height, size_t width, char *filename)
{
		FILE *fp = fopen(filename, "wb");
		if (fp == NULL)
				return -1;
		fprintf(fp, "P6\n%zu %zu 255\n", width, height);
		for (int i = 0; (unsigned) i < height*width; i++) {
				uint32_t pixel = pixels[i];
				uint8_t bytes[3] = {
						// bitmasking: https://en.wikipedia.org/wiki/Mask_(computing)
						(pixel>>(8*3))&0xFF,
						(pixel>>(8*2))&0xFF,
						(pixel>>(8*1))&0xFF,
				}; // color is 0xRRGGBBAA
				fwrite(bytes, sizeof(bytes), 1, fp);
		}
		fclose(fp);
		return 0;
}
