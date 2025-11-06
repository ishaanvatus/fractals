#include "fractals.h"

void sierpinski_triangle(Image image, int order, point p0, point p1, point p2, pixel color)
{
	if (order == 0)
	{
		triangle(image, p0, p1, p2, color);
		return;
	}

	point p3, p4, p5;
	p3.x = (p0.x + p1.x) / 2;
	p3.y = (p0.y + p1.y) / 2;

	p4.x = (p1.x + p2.x) / 2;
	p4.y = (p1.y + p2.y) / 2;

	p5.x = (p0.x + p2.x) / 2;
	p5.y = (p0.y + p2.y) / 2;
	sierpinski_triangle(image, order - 1, p0, p3, p5, color);
	sierpinski_triangle(image, order - 1, p3, p1, p4, color);
	sierpinski_triangle(image, order - 1, p5, p4, p2, color);

}
