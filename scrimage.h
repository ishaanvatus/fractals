#ifndef _scrimage_h
#define _scrimage_h

#include "scrimage.h"
#include <stdio.h>

#define WIDTH 1920
#define HEIGHT 1080

typedef struct
{
	int r;
	int g;
	int b;
} pixel;

typedef struct
{
	int x;
	int y;
} point;

typedef pixel Image[WIDTH][HEIGHT];

int absol(int x);
void fill_image(Image image, pixel color);
void line(Image image, point p0, point p1, pixel color);
void triangle(Image image, point p0, point p1, point p2, pixel color);
int save_image(Image image, char *filename);
void sierpinski_triangle(Image image, int order, point p0, point p1, point p2, pixel color);
#endif
