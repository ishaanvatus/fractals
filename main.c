#include <stdio.h>
#include <stdlib.h>
#include "scrimage.h"

int main(int argc, char *argv[])
{
	static Image image;
	char filename[] = "sierpinski.ppm";
	pixel bg = {0, 0, 0};
	pixel fg = {255, 0, 255};
	point p0 = {0, HEIGHT - 1};
	point p1 = {WIDTH/2, 0};
	point p2 = {WIDTH - 1, HEIGHT - 1};
	fill_image(image, bg);
	int order = atoi(argv[1]);
	sierpinski_triangle(image, order, p0, p1, p2, fg);
	save_image(image, filename);
	return 0;
}
