#include <stdio.h>
#include <stdint.h>
#include "scrimage.h"
int main(void)
{
		uint32_t pixels[HEIGHT*WIDTH];
		uint32_t color;
		printf("enter RRGGBBAA color in hex ");
		scanf("%x", &color);
		fill(pixels, HEIGHT, WIDTH, color);
		save(pixels, HEIGHT, WIDTH, "sample.ppm");
		return 0;
}
