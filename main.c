#include <stdio.h>
#include <stdint.h>
#include "scrimage.h"
int main(void)
{
		Canvas img;
		uint32_t bg = 0x00000000;
		uint32_t fg = 0xffff4400;
		int w, h;
		Pixel p0;
		printf("size of image is %dx%d\n", WIDTH, HEIGHT);
		printf("top left coord of rect ");
		scanf("%d %d", &p0.x, &p0.y);
		printf("size of rect w h ");
		scanf("%d %d", &w, &h);
		fill(img, bg);
		rectangle(img, fg, p0, w, h);
		save(img, "sample.ppm");
		return 0;
}
