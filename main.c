#include <stdio.h>
#include <stdint.h>
#include "scrimage.h"
int main(void)
{
		Canvas img;
		uint32_t bg = 0x00000000;
		uint32_t fg = 0xffff4400;
		Pixel p0;
		Pixel p1;
		printf("size of image is %dx%d\n", WIDTH, HEIGHT);
		printf("coordinate 1 of line ");
		scanf("%d %d", &p0.x, &p0.y);
		printf("coordinate 2 of line ");
		scanf("%d %d", &p1.x, &p1.y);
		fill(img, bg);
		bresenham(img, fg, p0, p1);
		save(img, "sample.ppm");
		return 0;
}
