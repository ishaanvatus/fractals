#include "scrimage.h"

int save_image(Image image, char *filename)
{
	FILE *fp = fopen(filename, "w");
	if (fp == NULL)
	{
		return -1;
	}
	fprintf(fp, "P3\n");
	fprintf(fp, "%d %d\n", WIDTH, HEIGHT);
	fprintf(fp, "255\n");
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			fprintf(fp, "%d %d %d\n", 
					image[x][y].r, image[x][y].g, image[x][y].b);
		}
	}
	fclose(fp);
	return 0;
}

void fill_image(Image image, pixel color)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			image[x][y] = color;
		}
	}
}

int absol(int x)
{
	return x >= 0 ? x:-x;
}

// Bresenham function stolen off wikipedia
// https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm#All_cases
void line(Image image, point p0, point p1, pixel color)
{
	int dx = absol(p0.x - p1.x);
	int sx = p0.x < p1.x ? 1:-1;
	int dy = -absol(p0.y - p1.y);
	int sy = p0.y < p1.y ? 1:-1;
	int error = dx + dy;
	int x = p0.x;
	int y = p0.y;
	int err2;

	while (1)
	{
		image[x][y] = color;
		if ((x == p1.x) && (y == p1.y)) break;
		err2 = 2*error;

		if (err2 >= dy)
		{
			if (x == p1.x) break;
			error += dy;
			x += sx;
		}

		if (err2 <= dx)
		{
			if (y == p1.y) break;
			error += dx;
			y += sy;
		}
	}
}

void triangle(Image image, point p0, point p1, point p2, pixel color)
{
	line(image, p0, p1, color);
	line(image, p1, p2, color);
	line(image, p2, p0, color);
}
