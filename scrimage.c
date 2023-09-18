#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "scrimage.h"
void fill(Canvas image, uint32_t color)
{
		for (int i = 0; (unsigned) i < HEIGHT*WIDTH; i++)
				image[i] = color;
}
int save(Canvas image, char *filename)
{
		FILE *fp = fopen(filename, "wb");
		if (fp == NULL)
				return -1;
		fprintf(fp, "P6\n%d %d 255\n", WIDTH, HEIGHT);
		for (int i = 0; (unsigned) i < HEIGHT*WIDTH; i++) {
				uint32_t pixel = image[i];
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
void bresenham(Canvas image, uint32_t color, Pixel p0, Pixel p1)
{
		Pixel pen = p0; 
		int dx = abs(p1.x - p0.x);
		int sx = (p0.x < p1.x)? 1 : -1;
		int dy = -abs(p1.y - p0.y);
		int sy = (p0.y < p1.y)? 1 : -1;
		int err = dy + dx, e2;
		while (1) {
				image[pen.y*WIDTH + pen.x] = color;
				if (pen.x == p1.x && pen.y == p1.y) break;
				e2 = 2*err;
				if (e2 >= dy) {
						if (pen.x == p1.x) break;
						err += dy;
						pen.x += sx;
				}
				if (e2 <= dx) {
						if (pen.y == p1.y) break;
						err += dx;
						pen.y += sy;
				}
		}
}
