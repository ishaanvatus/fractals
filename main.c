#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "scrimage.h"

int main(int argc, char *argv[])
{
    srand ( time(NULL) );
	static Image image;
	char filename[] = "sierpinski.ppm";
    int padding = atoi(argv[2]);
	pixel bg = {255, 255, 255};
	pixel fg = {0, 0, 0};
	point p0 = {padding, HEIGHT - padding - 1};
	point p1 = {WIDTH/2 - padding, padding};
	point p2 = {WIDTH - padding - 1, HEIGHT - padding - 1};
	//point p0 = {rand()%(WIDTH - padding), rand()%(HEIGHT - padding)};
	//point p1 = {rand()%(WIDTH - padding), rand()%(HEIGHT - padding)};
	//point p2 = {rand()%(WIDTH - padding), rand()%(HEIGHT - padding)};
	fill_image(image, bg);
	int order = atoi(argv[1]);
	sierpinski_triangle(image, order, p0, p1, p2, fg);
	save_image(image, filename);
	return 0;
}
